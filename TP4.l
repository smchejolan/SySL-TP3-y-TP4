%{

/* Se necesita esto para la llamada a atof() , atoi m�s abajo */
#include"TP4.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int yylineno;
%}

%option noyywrap

PRESERVADA	auto|break|register|extern|const|continue|default|goto
TIPODATO    char|float|long|double|short|int
VOID        void
WHILE       while
IF          if
ELSE        else
FOR         for
DO          do
TYPEDEF     typedef
SWITCH      switch
CASE        case
STRUCT      struct|union
SIZEOF      sizeof
MODALIDAD   constsigned|static|unsigned|volatile
RETURN      return
ID       	[a-zA-Z_][a-zA-Z0-9_]*
CEDECIMAL 	[1-9][0-9]*
CEOCTAL		0[0-7]*
CHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLlDd]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLlDd]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLlDd]?
CCHAR		"'"."'"
LITERALCADENA \"([ -!#-~]|\\\")*\"
COMENTARIO  \/\/(.)*|\/\*(.|\n)*\*\/

%%
{PRESERVADA}    {strcpy(yylval.cadena,yytext);   return PRESERVADA;}
{TIPODATO}      {strcpy(yylval.cadena,yytext);   return TIPODATO;}
{MODALIDAD}      {strcpy(yylval.cadena,yytext);  return MODALIDAD;}
{RETURN}        {strcpy(yylval.cadena,yytext);   return RETURN;}
{WHILE}         {strcpy(yylval.cadena,yytext);   return WHILE;}
{VOID}          {strcpy(yylval.cadena,yytext);   return VOID;}
{DO}            {strcpy(yylval.cadena,yytext);   return DO;}
{IF}            {strcpy(yylval.cadena,yytext);   return IF;}
{ELSE}          {strcpy(yylval.cadena,yytext);   return ELSE;}
{FOR}           {strcpy(yylval.cadena,yytext);   return FOR;}
{TYPEDEF}       {strcpy(yylval.cadena,yytext);   return TYPEDEF;}
{STRUCT}        {strcpy(yylval.cadena,yytext);   return STRUCT;}
{SWITCH}        {strcpy(yylval.cadena,yytext);   return SWITCH;}
{CASE}          {strcpy(yylval.cadena,yytext);   return CASE;}
{SIZEOF}        {strcpy(yylval.cadena,yytext);   return SIZEOF;}
{ID}            {strcpy(yylval.cadena,yytext);   return ID;}
{CEDECIMAL}   	{yylval.token.valor = atoi(yytext);yylval.token.tipo = 1; return NUM;}
{CEOCTAL}     	{yylval.token.valor = atoi(yytext);yylval.token.tipo = 1; return NUM;}
{CHEXA}      	{yylval.token.valor = atoi(yytext);yylval.token.tipo = 2; return NUM;}
{CREAL}       	{yylval.token.valor = atof(yytext);yylval.token.tipo = 2; return NUM;}
{CCHAR}     	{yylval.token.valor = atoi(yytext);yylval.token.tipo = 3; return NUM;}
{LITERALCADENA} {strcpy(yylval.cadena,yytext);return LCADENA;}
"++"            {strcpy(yylval.cadena,yytext); return INCREMENTO;}
"--"            {strcpy(yylval.cadena,yytext); return DECREMENTO;}
"&&"            {strcpy(yylval.cadena,yytext); return AND;}
"||"            {strcpy(yylval.cadena,yytext); return OR;}
"+="            {strcpy(yylval.cadena,yytext); return SUMADIRECTA;}
"-="            {strcpy(yylval.cadena,yytext); return RESTADIRECTA;}
">="            {strcpy(yylval.cadena,yytext); return MAYORIGUAL;}
"=<"            {strcpy(yylval.cadena,yytext); return MENORIGUAL;};
"!="            {strcpy(yylval.cadena,yytext); return DESIGUALDAD;}
"=="            {strcpy(yylval.cadena,yytext); return IGUALDAD;}
"."             {return '.';}   
"!"             {return '!';}
"<"             {return '<';}
">"             {return '>';}
"+"             {return '+';}
"-"             {return '-';}
"*"             {return '*';}
"/"             {return '/';}
"%"             {return '%';}
"&"             {return '&';}
";"             {return ';';}
","             {return ',';}
"("             {return '(';}
")"             {return ')';}
"{"             {return '{';}
"}"             {return '}';}


{COMENTARIO} 
[ \t\n]+ 

.               

%%