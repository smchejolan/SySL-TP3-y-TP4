/* Calculadora de notacion infija (usual) */

%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define YYDEBUG 1
extern FILE *yyin;
extern FILE *yyout;

%}



%union
{
  double real;
  int entero
  char * cadena
  char caracter
}

%token <real> NUMR
%token <entero> NUMI
%token <cadena> ID
%token <cadena> OP
%token <caracter> CHAR
%token <cadena> PR 
%type <real> exp

%left '+' '-'
%right '*' '/'
%nonassoc '^'


%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\t %f\n", $1); }
;

expresion:    NUM               { $$ = $1             }
        |'(' '-' NUM ')'  { $$ = - $3           }
        | exp '+' exp     { $$ = $1 + $3;       }
        | exp '-' exp     { $$ = $1 - $3;       }
        | exp '*'  exp     { $$ = $1 * $3;       }
        | exp '/' exp     { $$ = $1 / $3;       }
        | exp '^' exp     { $$ = pow($1,$3);    }
;
declaracion: ID           {     }
          |ID '=' NUM {$$ = $3}


%%

yyerror (s)  /* Llamada por yyparse ante un error */
     char *s;
{
  printf ("%s\n", s);
}

main ()
{
  yyin = fopen("Hola.txt","r+");
  yyout = fopen("Chau.txt","w");
  yyparse ();
}
