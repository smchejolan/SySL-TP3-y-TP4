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
CEDECIMAL 	[1-9][0-9]*
CEOCTAL		0[0-7]*
CHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*\.[0-9]+([eE]([\+\-]?)[0-9]+)?|[0-9]+\.([eE]([\+\-]?)[0-9]+)?|[0-9]+[eE]([\+\-]?)[0-9]+
CCHAR		"'"."'"
LCADENA \"([ -!#-~]|\\\")*\"
PRESERVADA	auto|register|extern|const|default|goto
TIPODATO    char|float|long|double|short|int
MODALIDAD   const|signed|static|unsigned|volatile
ID       	[a-zA-Z_][a-zA-Z0-9_]*
COMENTARIO  \/\/(.)*|\/\*(.|\n)*\*\/
STRUCT      struct|union

%%
"return"        {strcpy(yylval.cadena,yytext);   return RETURN;}
"while"         {strcpy(yylval.cadena,yytext);   return WHILE;}
"void"          {strcpy(yylval.cadena,yytext);   return VOID;}
"do"            {strcpy(yylval.cadena,yytext);   return DO;}
"continue"      {strcpy(yylval.cadena,yytext);   return CONTINUE;}
"break"         {strcpy(yylval.cadena,yytext);   return BREAK;}
"if"            {strcpy(yylval.cadena,yytext);   return IF;}
"else"          {strcpy(yylval.cadena,yytext);   return ELSE;}
"for"           {strcpy(yylval.cadena,yytext);   return FOR;}
"typedef"       {strcpy(yylval.cadena,yytext);   return TYPEDEF;}
"switch"        {strcpy(yylval.cadena,yytext);   return SWITCH;}
"case"          {strcpy(yylval.cadena,yytext);   return CASE;}
"sizeof"        {strcpy(yylval.cadena,yytext);   return SIZEOF;}
{TIPODATO}      {strcpy(yylval.cadena,yytext);   return TIPODATO;}
{STRUCT}        {strcpy(yylval.cadena,yytext);   return STRUCT;}
{PRESERVADA}    {strcpy(yylval.cadena,yytext);   return PRESERVADA;}
{MODALIDAD}     {strcpy(yylval.cadena,yytext);  return MODALIDAD;}
{ID}            {yylval.s.valor = 0;strcpy(yylval.s.cadena,yytext); yylval.s.tipo = 5; return ID;}
{CEDECIMAL}   	{yylval.s.valor = atof(yytext);strcpy(yylval.s.cadena,"yytext");yylval.s.tipo = 1; return NUM;}
{CEOCTAL}     	{yylval.s.valor = atof(yytext);strcpy(yylval.s.cadena,"yytext");yylval.s.tipo = 1; return NUM;}
{CHEXA}      	{yylval.s.valor = atof(yytext);strcpy(yylval.s.cadena,"yytext");yylval.s.tipo = 1; return NUM;}
{CREAL}       	{yylval.s.valor = atof(yytext);strcpy(yylval.s.cadena,"yytext");yylval.s.tipo = 2; return NUM;}
{CCHAR}     	{yylval.s.valor = atof(yytext);strcpy(yylval.s.cadena,"yytext");yylval.s.tipo = 3; return NUM;}
{LCADENA}       {yylval.s.valor = 0;strcpy(yylval.s.cadena,yytext); yylval.s.tipo = 4; return LCADENA;}
"++"            {strcpy(yylval.cadena,yytext); return INCREMENTO;}
"--"            {strcpy(yylval.cadena,yytext); return DECREMENTO;}
"&&"            {strcpy(yylval.cadena,yytext); return AND;}
"||"            {strcpy(yylval.cadena,yytext); return OR;}
"+="            {strcpy(yylval.cadena,yytext); return SUMADIRECTA;}
"-="            {strcpy(yylval.cadena,yytext); return RESTADIRECTA;}
">="            {strcpy(yylval.cadena,yytext); return MAYORIGUAL;}
"=<"            {strcpy(yylval.cadena,yytext); return MENORIGUAL;}
"!="            {strcpy(yylval.cadena,yytext); return DESIGUALDAD;}
"=="            {strcpy(yylval.cadena,yytext); return IGUALDAD;}
"->"            {strcpy(yylval.cadena,yytext); return PERTENECE;}
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