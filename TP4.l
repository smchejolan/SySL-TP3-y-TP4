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
PRESERVADA	auto|break|register|extern|union|const|continue|default|goto|volatile|static
CHAR        char
FLOAT       float
LONG        long
DOUBLE      double
SHORT       short
VOID        void
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
TIPODATO    int|float|double|char|long|short|signed|unsigned|
RETURN      return
ID       	[a-zA-Z_][a-zA-Z0-9_]*
CEDECIMAL 	[1-9][0-9]*
CEOCTAL		0[0-7]*
CEHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLlDd]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLlDd]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLlDd]?
CCHAR		"'"."'"
LITERALCADENA \"(\\.|[^\\"])*\"
COMENTARIO  "//".*\n|"/*"(.|\n)*"*/"

%%
{PRESERVADA}    {strcpy(yylval.cadena,yytext); return PRESERVADA;}
{TIPODATO}      {strcpy(yylval.cadena,yytext);printf("%s",yytext); return TIPODATO;}
{RETURN}        {strcpy(yylval.cadena,yytext); return RETURN;}
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
{CEDECIMAL}   { yylval.entero = atoi(yytext);   return NUMI;}
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
{CCHAR}         { char *matchCH;
                    matchCH=(char *)malloc(sizeof(char *));
                    strcpy(matchLT,yytext);
                    yylval.char = matchLT[0];
                    return CCHAR;}
{LITERALCADENA} {   strcpy(yylval.cadena,yytext);return LCADENA;}
"++"            {strcpy(yylval.cadena,yytext); return INCREMENTO;}
"--"            {strcpy(yylval.cadena,yytext); return DECREMENTO;}
"&&"            {strcpy(yylval.cadena,yytext); return AND;}
"||"            {strcpy(yylval.cadena,yytext); return OR;}
"+="            {strcpy(yylval.cadena,yytext); return SUMADIRECTA;}
"-="            {strcpy(yylval.cadena,yytext); return RESTADIRECTA;}
">="            {strcpy(yylval.cadena,yytext); return MAYORIGUAL;}
"=<"            {strcpy(yylval.cadena,yytext); return MENORIGUAL};
"!="            {strcpy(yylval.cadena,yytext); return DESIGUALDAD;}
"=="            {strcpy(yylval.cadena,yytext); return IGUALDAD;}
"->"            {strcpy(yylval.cadena,yytext); return PERTENCECE;}
"."             {strcpy(return '.';)}   
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
