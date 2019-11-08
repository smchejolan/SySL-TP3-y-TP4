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
%token identificador
%token constante
%token literalCadena
%token AND
%token COMPARACION
%token INCREMENTO

%type <real> exp
%type expAsignación
%type expCondicional
%type expOr
%type expAnd
%type expIgualdad
%type expRelacional
%type expAditiva
%type expMultiplicativa
%type expUnaria
%type operUnario
%type expPostfijo
%type listaArgumentos
%type expPrimaria

%start 

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
declaracion: ID           
        |ID '=' NUM {$$ = $3};

expAsignación:	expCondicional
		|expUnaria operAsignación expAsignación ;
operAsignación:	uno de = +=;

expCondicional:	expOr
		|expOr ? expresión : expCondicional;
expOr:		expAnd;
		|expOr 
		|expAnd;

expAnd: 	expIgualdad
		|expAnd AND expIgualdad;
expIgualdad:	expRelacional
		|expIgualdad COMPARACION expRelacional;
expRelacional:	expAditiva
		|expRelacional >= expAditiva;
expAditiva:	expMultiplicativa
		|expAditiva '+' expMultiplicativa;
expMultiplicativa: expUnaria
		|expMultiplicativa '*' expUnaria;
expUnaria:	expPostfijo
		|INCREMENTO expUnaria
		|operUnario expUnaria;
sizeof: (nombreTipo) ;
operUnario:	uno de '&' (dirección) '*' (puntero) '–' (signo) '!' (“not”);
expPostfijo:	expPrimaria
		|expPostfijo '[' expresión ']'
		|expPostijo ( listaArgumentosop );
listaArgumentos: expAsignación
		|listaArgumentos ',' expAsignación;
expPrimaria:	identificador
		|constante
		|literalCadena
		|'(' expresión ')';
nombreTipo: uno de char int double


%%

yyerror (s)  /* Llamada por yyparse ante un error */
     char *s;
{
  printf ("%s\n", s);
}

main ()
{
  yyin = fopen("entrada.txt","r+");
  yyout = fopen("salida.txt","w");
  yyparse ();
}
