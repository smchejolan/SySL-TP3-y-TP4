%{

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "TP4.tab.h"


int octToDec(char oct[]);
int hexToDec(char *hex);
double stringToReal(char realC[]);


%}
PRESERVADA	auto|break|register|typedef|extern|union|const|unsigned|continue|signed|void|default|goto|sizeof|volatile|static
ID       	[a-zA-Z_][a-zA-Z0-9_]*
CEDECIMAL 	[1-9][0-9]*
CEOCTAL		0[0-7]*
CEHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLlDd]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLlDd]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLlDd]?
CCHAR		"'"."'"
LITERALCADENA \"(\\.|[^\\"])*\"
COMENTARIO  "//".*\n|"/*"(.|\n)*"*/"
CHAR        char
FLOAT       float
LONG        long
DOUBLE      double
SHORT       short
WHILE       while
IF          if
ELSE        else
FOR         for
DO          do
TYPEDEF     typedef
SWITCH      switch
CASE        case
STRUCT      struct
SIZEOF      sizeof
TIPODATO    int|float|double|char|long|short
RETURN      return
CONTINUE    continue
BREAK       break




%%
{PRESERVADA}    {strcpy(yylval.cadena,yytext); return PRESERVADA;}
{TIPODATO}      {strcpy(yylval.cadena,yytext); return TIPODATO;}
{RETURN}        {strcpy(yylval.cadena,yytext); return RETURN;}
{ID}            {strcpy(yylval.cadena,yytext);   return ID;}
{WHILE}         {strcpy(yylval.cadena,yytext);   return WHILE;}
{DO}            {strcpy(yylval.cadena,yytext);   return DO;}
{IF}            {strcpy(yylval.cadena,yytext);   return IF;}
{ELSE}          {strcpy(yylval.cadena,yytext);   return ELSE;}
{FOR}           {strcpy(yylval.cadena,yytext);   return FOR;}
{TYPEDEF}       {strcpy(yylval.cadena,yytext);   return TYPEDEF;}
{STRUCT}        {strcpy(yylval.cadena,yytext);   return STRUCT;}
{SWITCH}        {strcpy(yylval.cadena,yytext);   return SWITCH;}
{CASE}          {strcpy(yylval.cadena,yytext);   return CASE;}
{SIZEOF}        {strcpy(yylval.cadena,yytext);   return SIZEOF;}
{BREAK}         {strcpy(yylval.cadena,yytext);   return BREAK;}
{CONTINUE}      {strcpy(yylval.cadena,yytext);   return CONTINUE;}
{CEDECIMAL}     {yylval.entero = atoi(yytext);   return NUMI;}
{CEOCTAL}     { char *matchOctal;
                matchOctal=(char *)malloc(sizeof(char *));
                strcpy(matchOctal,yytext);
                yylval.entero = octToDec(matchOctal);
                return NUMI;}
{CEHEXA}      { char *matchHexa;
                matchHexa=(char *)malloc(sizeof(char *));
                strcpy(matchHexa,yytext);
                yylval.entero = hexToDec(matchHexa);
                return NUMI;}
{CREAL}       { yylval.real = atof(yytext); return NUMR;}
{CCHAR}         {printf("La cadena %s representa una constante caracter\n", yytext);return CCHAR;}
{LITERALCADENA} {   char *matchLT;
                    matchLT=(char *)malloc(sizeof(char *));
                    strcpy(matchLT,yytext);
                    punteroLitCad=agregarAListaA(punteroLitCad,matchLT,strlen(matchLT)-2);return LCADENA;}
"++"            {strcpy(yylval.cadena,yytext); return INCREMENTO;}
"--"            {strcpy(yylval.cadena,yytext); return DECREMENTO;}
"&&"            {strcpy(yylval.cadena,yytext); return AND;}
"||"            {strcpy(yylval.cadena,yytext); return OR;}
"+="            {strcpy(yylval.cadena,yytext); return SUMADIRECTA;}
"-="            {strcpy(yylval.cadena,yytext); return RESTADIRECTA;}
"!"             {strcpy(yylval.cadena,yytext); return '!';}
"<"             {strcpy(yylval.cadena,yytext); return '<';}
">"             {strcpy(yylval.cadena,yytext); return '>';}
">="            {strcpy(yylval.cadena,yytext); return MAYORIGUAL;}
"=<"            {strcpy(yylval.cadena,yytext); return MENORIGUAL};
"!="            {strcpy(yylval.cadena,yytext); return DESIGUALDAD;}
"=="            {strcpy(yylval.cadena,yytext); return IGUALDAD;}
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


int octToDec(char oct[]){
	int longitud=0,dec=0,potencia=0;
    for(longitud=0;oct[longitud]!='\0';longitud++);
    for(int j=longitud-1;j>=0;j--){
        dec += (oct[j]-48) * pow(8,potencia);
        potencia++;
    };
    return dec;
}

int hexToDec(char *hex){
    return (int)strtol(hex, NULL, 0);
}

int yywrap(){}

int main(){
    yyout = fopen("salida.txt","w");
    yyin = fopen("entrada.txt","r");
    yylex();
    return 0;
}
