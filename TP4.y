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
%token <cadena> OP
%token <caracter> CCHAR
%token <cadena> PRESERVADA 
%token <cadena> LCADENA
%token <cadena> AND
%token <cadena> COMPARACION
%token <cadena> INCREMENTO
%token <caracter> PUNTUACION


%type <cadena> expresion
%type <cadena> listaIdentificadores
%type <cadena> identificadorA


%left '+' '-'
%right '*' '/'
%nonassoc '^'


%% /* A continuacion las reglas gramaticales y las acciones */
expresion:  TIPODATO listaIdentificadores  PUNTUACION 
          | NUMI {printf("funciono DOU!")}
;
listaIdentificadores: identificadorA
                    | identificadorA ',' listaIdentificadores
;
identificadorA: ID
              | ID '=' expresion
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
