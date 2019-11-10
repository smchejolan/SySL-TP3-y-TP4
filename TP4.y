%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int flag_error=0;
extern FILE *yyout;
extern FILE *yyin;

%}

%union
{
  struct{
    char cadena[50];
    double valor;
    int tipo;
  }s;
  char caracter;
  char* cadena;
}

%start expresionPrimaria


%token<s> NUM LCADENA ID
%token<cadena> TIPODATO PRESERVADA MODALIDAD AND PUNTUACION INCREMENTO DECREMENTO SUMADIRECTA RESTADIRECTA OR VOID MAYORIGUAL MENORIGUAL PERTENECE DESIGUALDAD IGUALDAD RETURN IF DO WHILE ELSE FOR TYPEDEF STRUCT SIZEOF SWITCH CASE BREAK CONTINUE CONTROLOTRA OPERADOR CONDICION DEFAULT

%left '+' '-' '*' ',' '/' IGUALDAD DESIGUALDAD AND OR
%right  '&' '!' INCREMENTO DECREMENTO SIZEOF ':' '?' '=' SUMADIRECTA RESTADIRECTA
%nonassoc '{' '}' '[' ']' '(' ')'


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
declaracionParametrosStruct: modalidadOP tipoDeDato ID';'
                            |modalidadOP tipoDeDato '*'ID';'
                            |modalidadOP tipoDeDato ID'['expresion']'';'
                            |modalidadOP tipoDeDato ID'['']'';'
;
declaracionFuncion: type ID '('listaDeParametrosOP')'
;
definicionFuncion: type ID '('listaDeParametros')' sentenciaCompuesta
;
listaDeParametros: parametro
                  |listaDeParametros ',' parametro
;
parametro: TIPODATO ID
          |TIPODATO'*' ID
          |TIPODATO'['']'ID
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

declarancionDeStruct: STRUCT ID
                      STRUCT ID '{'listaDeDeclaracionesStructOP'}'
                      STRUCT ID '{'listaDeDeclaracionesStructOP'}'ID
                      STRUCT '{'listaDeDeclaracionesStructOP'}'ID
;
listaDeParametrosOP: 
                      |listaDeParametros
;
sentenciaCompuesta: '{' '}' 
                    |'{'listaCompuesta'}'
;
listaCompuesta: elementoDeSentencia
                |listaCompuesta elementoDeSentencia
;
elementoDeSentencia: listaDeFunciones
                  |listaDeDeclaraciones
                  |listaDeSentencias
;
listaDeFunciones: definicionFuncion
                  |listaDeFunciones definicionFuncion
;

listaDeDeclaraciones:  declaracion
                    | listaDeDeclaraciones declaracion 
;             
listaDeSentencias:  sentencia
                    |listaDeSentencias sentencia
;
sentencia: sentenciaCompuesta 
          |sentenciaExpresion 
          |sentenciaSeleccion 
          |sentenciaIteracion 
          |sentenciaSalto 
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
sentenciaSalto: CONTINUE';'
                |BREAK ';'
                |RETURN expresion ';'
;
listaDeExpresiones: expresion
                    |listaDeExpresiones ',' expresion
;
expresionOP: 
              |expresion
;
expresion: expresionAsignacion {$<s.tipo>$ = $<s.tipo>1;}
;

expresionAsignacion: expresionCondicional {$<s.tipo>$ = $<s.tipo>1;}
                     |expresionUnaria operacionAsignacion expresionAsignacion  {if(1){$<s.tipo>$ = $<s.tipo>1;} } //hacer lvalue y control de tipos 
;
operacionAsignacion: '='|SUMADIRECTA|RESTADIRECTA
;
expresionCondicional: expresionOr {$<s.tipo>$ = $<s.tipo>1;}
                      |expresionOr '?' expresion ':' expresion  {$<s.tipo>$ = 1;}
;
expresionOr: expresionAnd {$<s.tipo>$ = $<s.tipo>1;}
            |expresionOr OR expresionAnd  {$<s.tipo>$ = 1;}
;
expresionAnd: expresionIgualdad  {$<s.tipo>$ = $<s.tipo>1;}
             |expresionAnd AND expresionIgualdad  {$<s.tipo>$ = 1;}
;
expresionIgualdad: expresionRelacional {$<s.tipo>$ = $<s.tipo>1;}
                  | expresionIgualdad operadorComparacion expresionRelacional  {$<s.tipo>$ = 1;}
;
operadorComparacion: IGUALDAD DESIGUALDAD
;
expresionRelacional: expresionAditiva {$<s.tipo>$ = $<s.tipo>1;}
                     |expresionRelacional operadorRelacional expresionAditiva  {$<s.tipo>$ = 1;}
;
operadorRelacional: '>' | '<' | MENORIGUAL | MAYORIGUAL
;
expresionAditiva: expresionMultiplicativa  {$<s.tipo>$ = $<s.tipo>1;}
                  |expresionAditiva '+' expresionMultiplicativa  {$<s.tipo>$ = $<s.tipo>1;}
                  |expresionAditiva '-' expresionMultiplicativa  {$<s.tipo>$ = $<s.tipo>1;}
;
expresionMultiplicativa:  expresionUnaria {$<s.tipo>$ = $<s.tipo>1;}
                          | expresionMultiplicativa '*' expresionUnaria
                          | expresionMultiplicativa '/' expresionUnaria
;
expresionUnaria: expresionPostfijo  {$<s.tipo>$ = $<s.tipo>1;}
                 | INCREMENTO expresionUnaria  {$<s.tipo>$ = $<s.tipo>1;}
                 | DECREMENTO expresionUnaria {$<s.tipo>$ = $<s.tipo>1;}
                 | operadorUnario expresionUnaria {$<s.tipo>$ = $<s.tipo>1;}
                 | '-' expresionUnaria %prec NEG {$<s.tipo>$ = $<s.tipo>1;}
                 | '+' expresionUnaria %prec POS {$<s.tipo>$ = $<s.tipo>1;}
                 | '*' expresionUnaria %prec PUNT {$<s.tipo>$ = $<s.tipo>1;}
;
operadorUnario: '&'|'!'
;
expresionPostfijo: expresionPrimaria 
                  |expresionPostfijo'['expresion']'
                  |expresionPostfijo'('listaDeArgumentos')'
;
listaDeArgumentos: expresionAsignacion
                   |listaDeArgumentos ',' expresionAsignacion
;
expresionPrimaria: NUM {printf("%f",$<s.valor>1);}
                   |ID {printf("%s",$<s.cadena>1);}
                   |LCADENA  {printf("%s",$<s.cadena>1);}





%%

yyerror (s)  
      char *s;
{
   printf ("%token\n", s);
}

int main ()
{
  yyout = fopen("salida.txt","w");
  yyin = fopen("entrada.txt","r+");
  yyparse ();
}
