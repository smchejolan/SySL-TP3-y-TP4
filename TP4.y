/* Calculadora de notacion infija (usual) */

%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

%}

%union
{
  struct{
    char* cadena;
    double valor;
    int tipo;
  }tk;
  char caracter;
  char* cadena;
}

%start sentencia

%token <tk> NUMR
%token <tk> NUMI
%token <tk> TIPODATO
%token <tk> ID
%token <tk> CCHAR
%token <cadena> PRESERVADA 
%token <cadena> LCADENA
%token <cadena> AND
%token <cadena> PUNTUACION
%token <cadena> INCREMENTO
%token <cadena> DECREMENTO
%token <cadena> SUMADIRECTA
%token <cadena> RESTADIRECTA
%token <cadena> OR
%token <cadena> VOID
%token <cadena> MAYORIGUAL
%token <cadena> MENORIGUAL
%token <cadena> DESIGUALDAD
%token <cadena> IGUALDAD
%token <cadena> RETURN
%token <cadena> IF
%token <cadena> DO
%token <cadena> WHILE
%token <cadena> ELSE
%token <cadena> FOR
%token <cadena> TYPEDEF
%token <cadena> STRUCT
%token <cadena> SIZEOF
%token <cadena> SWITCH
%token <cadena> CASE
%token <cadena> BREAK
%token <cadena> CONTINUE

%type <tk> declaracion
%type <tk> listaIdentificadores
%type <tk> identificadorA
%type <tk> sentencia
%type <tk> sentenciaCompuesta
%type <tk> sentenciaExpresion
%type <tk> sentenciaIteracion
%type <tk> sentenciaSalto
%type <tk> listaDeSentencias
%type <tk> listaDeDeclaraciones
%type <tk> sentenciaSeleccion
%type <tk> expresion
%type <tk> expresionCondicional
%type <tk> expresionAsignacion
%type <tk> expresionOr
%type <tk> expresionAnd
%type <tk> expresionIgualdad
%type <tk> expresionRelacional
%type <tk> expresionAditiva
%type <tk> expresionMultiplicativa
%type <tk> expresionUnaria
%type <tk> operadorUnario
%type <tk> operadorComparacion
%type <tk> operadorRelacional
%type <tk> expresionPostfijo
%type <tk> listaDeArgumentos
%type <tk> listaDeParametros
%type <tk> listaDeExpresiones
%type <tk> expresionPrimaria
%type <tk> parametro 

%left '+' '-'
%right '*' '/'
%nonassoc '^'


%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vac�o */
        | input line
;

line: '\n'
    | declaracion {printf("Fin linea \n");}
		| sentenciaCompuesta {printf("Fin linea \n");}
		| sentenciaExpresion {printf("Fin linea\n");}
		| sentenciaSeleccion {printf("Fin linea \n");}
		| sentenciaIteracion {printf("Fin linea \n");}
		| sentenciaSalto {printf("Fin linea \n");}
		| error 
;

sentencia: sentenciaCompuesta sentenciaExpresion sentenciaSeleccion sentenciaIteracion sentenciaSalto 
;
sentenciaCompuesta: '{' '}'
                    |'{' listaDeDeclaraciones '}'
                    |'{' listaDeSentencias '}'
                    |'{' listaDeDeclaraciones listaDeSentencias'}' 
;
listaDeDeclaraciones:  declaracion
                    | listaDeDeclaraciones declaracion 
;             
listaDeSentencias:  sentencia
                    |listaDeSentencias sentencia
;
sentenciaExpresion: ';'       
                    |expresion
;
sentenciaSeleccion: IF'('expresion')' sentencia
                    |IF'('expresion')' sentencia ELSE sentencia
                    |SWITCH'('expresion')' sentencia
;
sentenciaIteracion: WHILE '(' expresion ')' sentencia
                    |DO sentencia WHILE'(' expresion ')' ';'
                    |FOR '('';'';'')' sentencia 
                    |FOR '(' expresion ';'';'')' sentencia 
                    |FOR '('  ';' expresion ';'  ')' sentencia 
                    |FOR '('  ';'  ';' expresion ')' sentencia 
                    |FOR '('  ';' expresion ';' expresion ')' sentencia 
                    |FOR '(' expresion ';'  ';' expresion ')' sentencia 
                    |FOR '(' expresion ';' expresion ';' ')' sentencia 
                    |FOR '(' expresion ';' expresion ';' expresion ')' sentencia 
;
sentenciaSalto:  ';'
                |CONTINUE';'
                |BREAK ';'
                |RETURN expresion ';'
;
declaracion:  TIPODATO listaIdentificadores  ';' 
            | {printf("funciono DOU!")}
;
definicionFuncion: type ID '('listaDeParametros')' sentenciaCompuesta
;
declaracionFuncion: type ID '('listaDeParametros')'';'
;
type: TIPODATO
      |VOID
;
listaDeParametros: parametro
                  |listaDeParametros ',' parametro
;
parametro: TIPODATO ID
          |TIPODATO'*' ID
          |TIPODATO'['']'ID
;
listaIdentificadores: identificadorA
                    | listaIdentificadores ',' identificadorA
;
identificadorA: ID
              | ID '=' expresion
              | '*'ID  
              | '*'ID '=' expresion
              | '*'ID '=' ID
              | '*'ID '=' '&'ID
              | ID'['expresion']' 
              | ID'['expresion']' '=' '{'listaDeExpresiones'}' 
              | ID'[' ']' '=' '{'listaDeExpresiones'}'
;
listaDeExpresiones: expresion
                    |listaDeExpresiones ',' expresion
;

expresion: expresionAsignacion
;
expresionAsignacion: expresionCondicional
                     |expresionUnaria operacionAsignacion expresionAsignacion
;
operacionAsignacion: '='|SUMADIRECTA|RESTADIRECTA
;
expresionCondicional: expresionOr
                      |expresionOr '?' expresion ':' expresion
;
expresionOr: expresionAnd
            |expresionOr OR expresionAnd
;
expresionAnd: expresionIgualdad 
             |expresionAnd AND expresionIgualdad
;
expresionIgualdad: expresionRelacional
                  | expresionIgualdad operadorComparacion expresionRelacional 
;
operadorComparacion: IGUALDAD DESIGUALDAD
;
expresionRelacional: expresionAditiva
                     |expresionRelacional operadorRelacional expresionAditiva
;
operadorRelacional: '>' | '<' | MENORIGUAL | MAYORIGUAL
;
expresionAditiva: expresionMultiplicativa
                  |expresionAditiva '+' expresionMultiplicativa
                  |expresionAditiva '-' expresionMultiplicativa
;
expresionMultiplicativa:  expresionUnaria
                          | expresionMultiplicativa '*' expresionUnaria
                          | expresionMultiplicativa '/' expresionUnaria
;
expresionUnaria: expresionPostfijo
                 | INCREMENTO expresionUnaria
                 | DECREMENTO expresionUnaria
                 | operadorUnario expresionUnaria
;
operadorUnario: '&'|'*'|'-'|'!'
;
expresionPostfijo: expresionPrimaria
                  |expresionPostfijo'['expresion']'
                  |expresionPostfijo'('listaDeArgumentos')'
;
expresionPrimaria: CCHAR|NUMI|NUMR
;
listaDeArgumentos: expresionAsignacion
                   |listaDeArgumentos ',' expresionAsignacion
;




%%

yyerror (s)  /* Llamada por yyparse ante un error */
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
