%{

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>

int octToDec(char oct[]);
int hexToDec(char *hex);
double stringToReal(char realC[]);
int yylineno;

%}
PRESERVADA	while|do|if|else|for|int|char|return|case|switch|auto|double|struct|break|long|enum|register|typedef|extern|union|const|float|short|unsigned|continue|signed|void|default|goto|sizeof|volatile|static
ID       	[a-zA-Z_][a-zA-Z0-9_]*
CEDECIMAL 	[1-9][0-9]*
CEOCTAL		0[0-7]*
CEHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLlDd]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLlDd]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLlDd]?
CCHAR		"'"."'"
LITERALCADENA \"(\\.|[^\\"])*\"
COMENTARIO  "//".*\n|"/*"(.|\n)*"*/"
OPERADOR	"++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"%"|"<"|"<="|">"|">="|"=="|"!="|"&&"|"||"|"?"|":"|"="|"+="
PUNTUACION  ";"|","|"("|")"|"{"|"}"

%%
{PRESERVADA}  { strcpy(yylval.cadena,yytext);
                return PR;}                
{ID}          { strcpy(yylval.cadena,yytext);
                return ID;}
{CEDECIMAL}   { yylval.entero = atoi(yytext);
                return NUMI;}
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
{CREAL}       { yylval.real = atof(yytext);
                return NUMR;}                
{CCHAR}         {printf("La cadena %s representa una constante caracter\n", yytext);}  
{LITERALCADENA} {   char *matchLT;
                    matchLT=(char *)malloc(sizeof(char *));
                    strcpy(matchLT,yytext);
                    punteroLitCad=agregarAListaA(punteroLitCad,matchLT,strlen(matchLT)-2);} 
{COMENTARIO} 	{char *matchCOM;
                 matchCOM=(char *)malloc(sizeof(char *));
                 strcpy(matchCOM,yytext);
                 punteroCOM=agregarAListaB(punteroCOM,matchCOM);}
{OPERADOR}      {char *matchOP;
                 matchOP=(char *)malloc(sizeof(char *));
                 strcpy(matchOP,yytext);
                 struct nodoTIPOA *ID=buscar(punteroOP,matchOP);
                 if(ID==NULL){
                    punteroOP=agregarAListaA(punteroOP,matchOP,1);
                 }else{
                    ID->numero++;}}
{PUNTUACION}    {   char *matchP;
                    matchP=(char *)malloc(sizeof(char *));
                    strcpy(matchP,yytext);
                    struct nodoTIPOA * ID=buscar(punteroPunt,matchP);
                    if(ID==NULL){
                        punteroPunt=agregarAListaA(punteroPunt,matchP,1);
                    }else{
                        ID->numero++;
                    }}
"&&"            {return AND} 
"=="            {return COMPARACION}
">="            {return COMPARACION}
"++"            {return INCREMENTO}

[ \t\n]+          

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