/* Calculadora de notacion infija (usual) */

%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

%}

%union
{
  double real;
  int entero;
  char * cadena;
  char caracter;
}

%start expresion

%token <real> NUMR
%token <entero> NUMI
%token <cadena> TIPODATO
%token <cadena> ID
%token <caracter> CCHAR
%token <cadena> PRESERVADA 
%token <cadena> LCADENA
%token <cadena> AND
%token <caracter> PUNTUACION
%token <cadena> INCREMENTO
%token <cadena> DECREMENTO
%token <cadena> SUMADIRECTA
%token <cadena> RESTADIRECTA
%token <cadena> OR
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






%type <cadena> declaracion
%type <cadena> listaIdentificadores
%type <cadena> identificadorA
%type <cadena> sentencia
%type <cadena> sentenciaCompuesta
%type <cadena> sentenciaExpresion
%type <cadena> sentenciaIteracion
%type <cadena> sentenciaSalto
%type <cadena> listaDeSentencias
%type <cadena> listaDeDeclaraciones
%type <cadena> sentenciaSeleccion


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
declaracion:  TIPODATO listaIdentificadores  ';' 
            | {printf("funciono DOU!")}
;
listaIdentificadores: identificadorA
                    | listaIdentificadores ',' identificadorA
;
identificadorA: ID
              | ID '=' expresion
;
expresion: NUMI
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
sentenciaExpresion: {"opcional xd"}        
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
sentenciaSalto:     RETURN ';'
                    |RETURN expresion ';'
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
