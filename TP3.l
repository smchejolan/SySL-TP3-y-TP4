%{

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nodoTIPOA{
    char *string;
    int numero;
    struct nodoTIPOA* next;
};
struct nodoTIPOB{
    char *string;
    struct nodoTIPOB* next;
};
struct nodoTIPOC{
    char *string;
    double mantisa;
    int parteEntera;
    struct nodoTIPOC* next;
};

int acum = 0;
struct nodoTIPOA *punteroID = NULL;	
struct nodoTIPOA *punteroLitCad = NULL;
struct nodoTIPOB *punteroPRes = NULL;
struct nodoTIPOA *punteroDEC = NULL;
struct nodoTIPOA *punteroCTEO = NULL;
struct nodoTIPOA *punteroPunt = NULL;
struct nodoTIPOA *punteroHex = NULL;
struct nodoTIPOA *punteroOP = NULL;
struct nodoTIPOB *punteroCOM = NULL;
struct nodoTIPOC *punteroReal = NULL;
struct nodoTIPOA * agregarAListaA(struct nodoTIPOA *puntero, char *nuevaEntrada, int entero);
struct nodoTIPOB *agregarAListaB(struct nodoTIPOB *puntero, char *nuevaEntrada);
struct nodoTIPOC *agregarAListaC(struct nodoTIPOC *puntero, char *nuevaEntrada,double flotante, int entero);
struct nodoTIPOA *buscar(struct nodoTIPOA *puntero, char *match);
void mostrarListaA(struct nodoTIPOA* puntero);
void mostrarListaB(struct nodoTIPOB* puntero);
int octToDec(char oct[]);
int hexToDec(char *hex);
double stringToReal(char realC[]);
double mantiza(double real);
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
{PRESERVADA}  { char *matchPR;
                matchPR=(char *)malloc(sizeof(char *));
                strcpy(matchPR,yytext);
                punteroPRes=agregarAListaB(punteroPRes,matchPR);}                
{ID}          { char *matchID;
                matchID=(char *)malloc(sizeof(char *));
                strcpy(matchID,yytext);
                struct nodoTIPOA *ID=buscar(punteroID,matchID);
                if(ID==NULL){
                    punteroID=agregarAListaA(punteroID,matchID,1);
                }else{
                    ID->numero++;}}
{CEDECIMAL}   { char *matchDEC;
                matchDEC=(char *)malloc(sizeof(char *));
                strcpy(matchDEC,yytext);
                acum = acum + atoi(matchDEC); 
                punteroDEC = agregarAListaA(punteroDEC,matchDEC,acum);
                }
{CEOCTAL}     { char *matchOctal;
                matchOctal=(char *)malloc(sizeof(char *));
                strcpy(matchOctal,yytext);
                punteroCTEO = agregarAListaA(punteroCTEO,matchOctal,octToDec(matchOctal));}
{CEHEXA}        {char *matchHexa;
                matchHexa=(char *)malloc(sizeof(char *));
                strcpy(matchHexa,yytext);
                punteroHex = agregarAListaA(punteroHex,matchHexa,hexToDec(matchHexa));}
{CREAL}       { char *matchReal;
                matchReal = (char*)malloc(sizeof(char *));
                strcpy(matchReal,yytext);
                double real = atof(matchReal), mant = mantiza(real);
                int realInt = (int)real;
                punteroReal = agregarAListaC(punteroReal,matchReal,mant,realInt);}                
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
[ \t\n]+          

%%

//

struct nodoTIPOA *agregarAListaA(struct nodoTIPOA *puntero, char *nuevaEntrada, int entero){
    struct nodoTIPOA *nuevo;
    nuevo = (struct nodoTIPOA*)malloc(sizeof(struct nodoTIPOA));
    nuevo->string=nuevaEntrada;
    nuevo->numero=entero;
    nuevo->next=NULL;
    if(puntero!=NULL){
        struct nodoTIPOA *aux = puntero;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next = nuevo;
    }else{
        puntero = nuevo;
    }
    return puntero;
}

struct nodoTIPOB *agregarAListaB(struct nodoTIPOB *puntero, char *nuevaEntrada){
    struct nodoTIPOB *nuevo;
    nuevo = (struct nodoTIPOB*)malloc(sizeof(struct nodoTIPOB));
    nuevo->string=nuevaEntrada;
    nuevo->next=NULL;
    if(puntero!=NULL){
        struct nodoTIPOB *aux = puntero;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next = nuevo;
    }else{
        puntero = nuevo;
    }
    return puntero;
}

struct nodoTIPOC *agregarAListaC(struct nodoTIPOC *puntero, char *nuevaEntrada,double flotante, int entero){
    struct nodoTIPOC *nuevo;
    nuevo = (struct nodoTIPOC*)malloc(sizeof(struct nodoTIPOC));
    nuevo->string=nuevaEntrada;
    nuevo->mantisa=flotante;
    nuevo->parteEntera=entero;
    nuevo->next=NULL;
    if(puntero!=NULL){
        struct nodoTIPOC *aux = puntero;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next = nuevo;
    }else{
        puntero = nuevo;
    }
    return puntero;
}

struct nodoTIPOA *buscar(struct nodoTIPOA *puntero, char *match){
    struct nodoTIPOA *punteroEncontrado = NULL;
    int encontrado=0;
    if(puntero!=NULL){
        struct nodoTIPOA *aux=puntero;
        while(aux!=NULL && encontrado==0){
            if(strcmp(aux->string,match)==0){
                punteroEncontrado=aux;
                encontrado=1;
            }else{
                aux=aux->next;
            }   
        }
    }
    return punteroEncontrado;
}

void mostrarListaA(struct nodoTIPOA *puntero){
    struct nodoTIPOA *aux=puntero;
    if(puntero!=NULL){
        while(aux!=NULL){
            printf("%s\t%d\n",aux->string,aux->numero);
            aux=aux->next;
        }
    }
}

void mostrarListaB(struct nodoTIPOB *puntero){
    struct nodoTIPOB *aux=puntero;
    if(puntero!=NULL){
        while(aux!=NULL){
            printf("%s\n",aux->string);
            aux=aux->next;
        }
    }
}

void mostrarListaC(struct nodoTIPOC *puntero){
    struct nodoTIPOC *aux=puntero;
    if(puntero!=NULL){
        while(aux!=NULL){
            printf("%s\t%.10f\t%d\n",aux->string,aux->mantisa,aux->parteEntera);
            aux=aux->next;
        }
    }
}
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

double mantiza(double real){
	return (real - (double)((int)real));
}

int yywrap(){} 

int main(){
    yyout = fopen("salida.txt","w");
    yyin = fopen("entrada.txt","r");
    yylex();
    printf("-----------Listado de Palabras reservadas-----------\n");
    printf("Palabra reservada\n");
    mostrarListaB(punteroPRes);
    printf("-----------Listado de identificadores-----------\n");
    printf("Identificador\tCantidad de veces que aparece\n");
    mostrarListaA(punteroID);   
    printf("-----------Listado de Constantes Decimales-----------\n");
    printf("Cte decimal\tValor acumulado\n");
    mostrarListaA(punteroDEC);
    printf("-----------Listado de Constantes octales-----------\n");
    printf("Cte octal\tValor decimal\n");
    mostrarListaA(punteroCTEO);
    printf("-----------Listado de Constantes Hexadecimales-----------\n");
    printf("Cte hexadecimal\tValor decimal\n");
    mostrarListaA(punteroHex);
    printf("-----------Listado de Constantes Reales-----------\n");
    printf("Cte real\tMantiza\tValor entero\n");
    mostrarListaC(punteroReal);
    printf("-----------Listado de Literales cadena-----------\n");
    printf("Literal Cadena\tLongitud\n");
    mostrarListaA(punteroLitCad);
    printf("-----------Listado de Caracteres de puntuacion-----------\n");
    printf("Caracter de puntuacion\tCantidad de veces que aparece\n");
    mostrarListaA(punteroPunt);
    printf("-----------Listado de Comentarios-----------\n");
    printf("Comentario\n");
    mostrarListaB(punteroCOM);
    printf("-----------Listado de operadores-----------\n");
    printf("Operador\tCantidad de veces que aparece\n");
    mostrarListaA(punteroOP);
    return 0;
}