%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern FILE *yyout;
%}

%union
{
  struct{
    char* cadena;
    double valor;
    int tipo;
  }token;
  char caracter;
  char* cadena;
}

%start input


%token <token> NUM 
%token <cadena> TIPODATO
%token <token> LCADENA
%token <token> ID
%token <cadena> PRESERVADA MODALIDAD AND PUNTUACION INCREMENTO DECREMENTO SUMADIRECTA RESTADIRECTA OR VOID MAYORIGUAL MENORIGUAL DESIGUALDAD IGUALDAD RETURN IF DO WHILE ELSE FOR TYPEDEF STRUCT SIZEOF SWITCH CASE BREAK CONTINUE CONTROLOTRA OPERADOR CONDICION DEFAULT
%type <token> expresion expresionAditiva expresionAnd expresionAsignacion expresionCondicional expresionIgualdad expresionMultiplicativa expresionOr expresionPostfijo expresionPrimaria expresionRelacional expresionUnaria

%left '+' '-' '*' '/' IGUALDAD DESIGUALDAD AND OR
%right  '&' '!' INCREMENTO DECREMENTO SIZEOF ':' '?'
%nonassoc '^'


%% /* A continuacion las reglas gramaticales y las acciones */

input: programa 
;
programa: global
          |programa global
;
global: declaracion
        |definicionFuncion
;
declaracion:  modalidadOP TIPODATO listaIdentificadores  ';' 
              modalidadOP declarancionDeStruct';'
              modalidadOP declaracionFuncion';'
;
modalidadOP: 
            |MODALIDAD
;
tipoDeDato: TIPODATO
            |STRUCT ID
;
type: tipoDeDato
      |VOID
;
listaDeDeclaracionesStructOP: 
                              |listaDeDeclaracionesStruct
;
listaDeDeclaracionesStruct: declaracionParametrosStruct
                            |listaDeDeclaracionesStruct declaracionParametrosStruct
;
declaracionParametrosStruct: modalidadOP tipoDeDato ID';'
                            |modalidadOP tipoDeDato '*'ID';'
                            |modalidadOP tipoDeDato ID'['expresion']'';'
                            |modalidadOP tipoDeDato ID'['']'';'
;
listaIdentificadores: identificadorA
                    | listaIdentificadores ',' identificadorA
;
identificadorA: declaracionNormal
                |declaracionArray
                |declaracionPuntero
;
declaracionNormal: ID
                   |ID '=' expresion
;
declaracionPuntero: '*'ID asignarPunteroOP
;
asignarPunteroOP: 
                  |asignarPuntero
;
asignarPuntero: '=' expresion
                |'=' ID
                |'=' '&'ID
;            
declaracionArray: ID'['expresion']' asignarArrayOp
                  |ID'['']' asignarArray
;
asignarArrayOp: 
                  |asignarArray
;
asignarArray: '=' '{'listaDeExpresiones'}'
;
declaracionFuncion: type ID '('listaDeParametrosOP')'
;
declarancionDeStruct: STRUCT ID
                      STRUCT ID '{'listaDeDeclaracionesStructOP'}'
                      STRUCT ID '{'listaDeDeclaracionesStructOP'}'
                      STRUCT ID '{'listaDeDeclaracionesStructOP'}'ID
                      STRUCT '{'listaDeDeclaracionesStructOP'}'ID
;
definicionFuncion: type ID '('listaDeParametros')' sentenciaCompuesta
;
listaDeParametrosOP: 
                      |listaDeParametros
;
listaDeParametros: parametro
                  |listaDeParametros ',' parametro
;
parametro: TIPODATO ID
          |TIPODATO'*' ID
          |TIPODATO'['']'ID
;
sentencia: sentenciaCompuesta sentenciaExpresion sentenciaSeleccion sentenciaIteracion sentenciaSalto 
;
sentenciaCompuesta: '{' '}' 
                    '{'listaCompuesta'}'
;
listaCompuesta: elementoDeSentencia
                |listaCompuesta elementoDeSentencia
;
elementoDeSentencia: listaDeFunciones|listaDeDeclaraciones|listaDeSentencias
;
listaDeFunciones: definicionFuncion
                  listaDeFunciones definicionFuncion
;
listaDeDeclaraciones:  declaracion
                    | listaDeDeclaraciones declaracion 
;             
listaDeSentencias:  sentencia
                    |listaDeSentencias sentencia
;
sentenciaExpresion: ';'       
                    |expresion';'
;
sentenciaSeleccion: IF'('expresion')' sentencia
                    |IF'('expresion')' sentencia ELSE sentencia
                    |SWITCH'('expresion')' sentencia
;
sentenciaIteracion: WHILE '(' expresion ')' sentencia
                    |DO sentencia WHILE'(' expresion ')' ';'
                    |FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia 
;
sentenciaSalto:  ';'
                |CONTINUE';'
                |BREAK ';'
                |RETURN expresion ';'
;
listaDeExpresiones: expresion
                    |listaDeExpresiones ',' expresion
;
expresionOP: 
              |expresion
;
expresion: expresionAsignacion {$<token.tipo>$ = $<token.tipo>1;}
;
expresionAsignacion: expresionCondicional {$<token.tipo>$ = $<token.tipo>1;}
                     |expresionUnaria operacionAsignacion expresionAsignacion  {if(){$<token.tipo>$ = $<token.tipo>1;} } //hacer lvalue y control de tipos 
;
operacionAsignacion: '='|SUMADIRECTA|RESTADIRECTA
;
expresionCondicional: expresionOr {$<token.tipo>$ = $<token.tipo>1;}
                      |expresionOr '?' expresion ':' expresion  {$<token.tipo>$ = 1;}
;
expresionOr: expresionAnd {$<token.tipo>$ = $<token.tipo>1;}
            |expresionOr OR expresionAnd  {$<token.tipo>$ = 1;}
;
expresionAnd: expresionIgualdad  {$<token.tipo>$ = $<token.tipo>1;}
             |expresionAnd AND expresionIgualdad  {$<token.tipo>$ = 1;}
;
expresionIgualdad: expresionRelacional {$<token.tipo>$ = $<token.tipo>1;}
                  | expresionIgualdad operadorComparacion expresionRelacional  {$<token.tipo>$ = 1;}
;
operadorComparacion: IGUALDAD DESIGUALDAD
;
expresionRelacional: expresionAditiva {$<token.tipo>$ = $<token.tipo>1;}
                     |expresionRelacional operadorRelacional expresionAditiva  {$<token.tipo>$ = 1;}
;
operadorRelacional: '>' | '<' | MENORIGUAL | MAYORIGUAL
;
expresionAditiva: expresionMultiplicativa  {$<token.tipo>$ = $<token.tipo>1;}
                  |expresionAditiva '+' expresionMultiplicativa  {$<token.tipo>$ = $<token.tipo>1;}
                  |expresionAditiva '-' expresionMultiplicativa  {$<token.tipo>$ = $<token.tipo>1;}
;
expresionMultiplicativa:  expresionUnaria {$<token.tipo>$ = $<token.tipo>1;}
                          | expresionMultiplicativa '*' expresionUnaria
                          | expresionMultiplicativa '/' expresionUnaria
;
expresionUnaria: expresionPostfijo  {$<token.tipo>$ = $<token.tipo>1;}
                 | INCREMENTO expresionUnaria  {$<token.tipo>$ = $<token.tipo>1;}
                 | DECREMENTO expresionUnaria {$<token.tipo>$ = $<token.tipo>1;}
                 | operadorUnario expresionUnaria {$<token.tipo>$ = $<token.tipo>1;}
                 | '-' expresionUnaria %prec NEG {$<token.tipo>$ = $<token.tipo>1;}
                 | '+' expresionUnaria %prec POS {$<token.tipo>$ = $<token.tipo>1;}
                 | '*' expresionUnaria %prec PUNT {$<token.tipo>$ = $<token.tipo>1;}
;
operadorUnario: '&'|'!'
;
expresionPostfijo: expresionPrimaria  {$<token.tipo>$ = $<token.tipo>1;}
                  |expresionPostfijo'['expresion']'
                  |expresionPostfijo'('listaDeArgumentos')'
;
listaDeArgumentos: expresionAsignacion
                   |listaDeArgumentos ',' expresionAsignacion
;
expresionPrimaria: NUM    {$<token.tipo>$ = $<token.tipo>1;}
                  |ID      {$<token.tipo>$ = $<token.tipo>1;}
                  |LCADENA  {$<token.tipo>$ = $<token.tipo>1;}
;




%%

yyerror (s)  
      char *s;
{
   printf ("%s\n", s);
}

int main ()
{
  yyin = fopen("entrada.txt","r+");
  yyout = fopen("salida.txt","w");
  yyparse ();
}
