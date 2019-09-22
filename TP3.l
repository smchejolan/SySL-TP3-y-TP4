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
struct nodoCTEReal{
    char *string;
    int mantiza;
    int parteEntera;
    struct nodoCTEReal* next;
};

int acum = 0;
struct nodoTIPOA *punteroID = NULL;	
struct nodoTIPOA *punteroLitCad = NULL;
struct nodoTIPOB *punteroPRes = NULL;
struct nodoTIPOA *punteroCTEO = NULL;
struct nodoTIPOA *punteroPunt = NULL;
struct nodoTIPOA * agregarAListaA(struct nodoTIPOA *puntero, char nuevaEntrada[], int entero);
struct nodoTIPOB *agregarAListaB(struct nodoTIPOB *puntero, char nuevaEntrada[]);
struct nodoTIPOA *buscarA(struct nodoTIPOA *puntero, char clave[]);
struct nodoTIPOB *buscarB(struct nodoTIPOB *puntero, char clave[]);
void mostrarListaA(struct nodoTIPOA* puntero);
void mostrarListaB(struct nodoTIPOB* puntero);
int octToDec(char oct[]);
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
PUNTUACION  ";"|","|"("|")"|"{"|"}"

%%
{PRESERVADA}  { char *matchPR;
                matchPR=(char *)malloc(sizeof(char *));
                strcpy(matchPR,yytext);
                punteroPRes=agregarAListaB(punteroPRes,matchPR);
                printf("-----------Listado de Palabras reservadas-----------\n");
	            printf("Palabra reservada\n");
	            mostrarListaB(punteroPRes);}
{ID}          { char *matchID;
                matchID=(char *)malloc(sizeof(char *));
                strcpy(matchID,yytext);
                struct nodoTIPOA * ID=buscarA(punteroID,matchID);
                if(ID==NULL){
                    punteroID=agregarAListaA(punteroID,matchID,1);
                }else{
                    ID->numero++;
                }	
                printf("-----------Listado de identificadores-----------\n");
	            printf("Identificador\t\t cantidad de veces que aparece\n");
	            mostrarListaA(punteroID);}
{CEDECIMAL}   {acum = acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);}
{CEOCTAL}     { char *matchOctal;
                matchOctal=(char *)malloc(sizeof(char *));
                strcpy(matchOctal,yytext);
                punteroCTEO = agregarAListaA(punteroCTEO,matchOctal,octToDec(matchOctal));
                printf("-----------Listado de Constantes octales-----------\n");
                printf("cte octal\t\t valor decimal\n");
                mostrarListaA(punteroCTEO);}
{CEHEXA}      {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);}
{CREAL}       {printf("La cadena %s representa una constante real\n", yytext);}
{CCHAR}       {printf("La cadena %s representa una constante caracter\n", yytext);}  
{LITERALCADENA} {   char *matchLT;
                    matchLT=(char *)malloc(sizeof(char *));
                    strcpy(matchLT,yytext);
                    punteroLitCad=agregarAListaA(punteroLitCad,matchLT,strlen(matchLT)-2);
                    printf("-----------Listado de Literal cadena-----------\n");
                    printf("LITERALCADENA\t\t longitud\n");
                    mostrarListaA(punteroLitCad);} 
{COMENTARIO} 	{printf("La cadena %s representa un comentario\n", yytext);} 
{PUNTUACION}    {   char *matchP;
                    matchP=(char *)malloc(sizeof(char *));
                    strcpy(matchP,yytext);
                    struct nodoTIPOA * ID=buscarA(punteroPunt,matchP);
                    if(ID==NULL){
                        punteroPunt=agregarAListaA(punteroPunt,matchP,1);
                    }else{
                        ID->numero++;
                    }	
                    printf("-----------Listado de car de PUNTUACION-----------\n");
                    printf("car de PUNTUACION\t\t cantidad de veces que aparece\n");
                    mostrarListaA(punteroPunt);}
[ \t\n]+          

%%

//OPERADOR	"++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"%"|"<"|"<="|">"|">="|"=="|"!="|"&&"|"||"|"?"|:|=|+=
//{OPERADOR}      {printf("La cadena %s representa un OPERADOR\n", yytext);}

struct nodoTIPOA *agregarAListaA(struct nodoTIPOA *puntero, char nuevaEntrada[], int entero){
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

struct nodoTIPOB *agregarAListaB(struct nodoTIPOB *puntero, char nuevaEntrada[]){
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

struct nodoTIPOA *buscarA(struct nodoTIPOA *puntero, char clave[]){
    struct nodoTIPOA *punteroEncontrado;
    struct nodoTIPOA *aux;
    int encontrado=0;
    if(puntero!=NULL){
        aux=puntero;
        while(aux->next!=NULL && encontrado==0){
            if(strcmp(aux->string,clave)==0){encontrado=1;}
            punteroEncontrado=aux;
            aux=aux->next;
        }
        if(encontrado==0){punteroEncontrado=NULL;}
    }else{
    	punteroEncontrado = NULL;
    }
    return punteroEncontrado;
}

/*struct nodoTIPOB *buscarB(struct nodoTIPOB *puntero, char clave[]){
    struct nodoTIPOB *punteroEncontrado;
    struct nodoTIPOB *aux;
    int encontrado=0;
    if(puntero!=NULL){
        aux=puntero;
        while(aux->next!=NULL && encontrado==0){
            if(strcmp(aux->string,clave)==0){encontrado=1;}
            punteroEncontrado=aux;
            aux=aux->next;
        }
        if(encontrado==0){punteroEncontrado=NULL;}
    }else{
    	punteroEncontrado = NULL;
    }
    return punteroEncontrado;
}*/

void mostrarListaA(struct nodoTIPOA *puntero){
    struct nodoTIPOA *aux=puntero;
    if(puntero!=NULL){
        while(aux!=NULL){
            printf("%s\t\t%d\n",aux->string,aux->numero);
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

int octToDec(char oct[]){
	int longitud=0,dec=0,potencia=0;
    for(longitud=0;oct[longitud]!='\0';longitud++);
    for(int j=longitud-1;j>=0;j--){
        dec += (oct[j]-48) * pow(8,potencia);
        potencia++;
    };
    return dec;
}



int yywrap(){} 

int main(int argc, char** argv){
    yylex();
    return 0;
    }
