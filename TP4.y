%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int lines = 1;

int flag_error=0;
extern FILE *yyout;
extern FILE *yyin;


struct nodoId *punteroId=NULL;
struct nodoFuncion *punteroFunc=NULL;
struct nodoVariable *punteroVariables=NULL;
struct nodoFuncion *funcionActual=NULL;
struct nodoVariable *parametros=NULL;
int funciones=0;
%}

%union
{
    struct{
    char cadena[50];
    double valor;
    int tipo;
  }s; 
}

%start input


%token<s> NUM LCADENA ID
%token<s> TIPODATO PRESERVADA MODALIDAD AND PUNTUACION INCREMENTO DECREMENTO SUMADIRECTA RESTADIRECTA OR VOID MAYORIGUAL MENORIGUAL PERTENECE DESIGUALDAD IGUALDAD RETURN IF DO WHILE ELSE FOR TYPEDEF STRUCT SIZEOF SWITCH CASE BREAK CONTINUE CONTROLOTRA OPERADOR CONDICION DEFAULT

%type <s> expresionPrimaria

%left '*' '/'
%left '+' '-'  AND OR
%left IGUALDAD DESIGUALDAD
%left ','
%right INCREMENTO DECREMENTO SIZEOF '&' '!'
%right ':' '?'  
%right RESTADIRECTA SUMADIRECTA '=' 
%nonassoc '{' '}' '[' ']' '(' ')'

%% /* A continuacion las reglas gramaticales y las acciones */

input: 
      |input line 
;
line: '\n' {lines++}
      | sentencia 
      | sentencia '\n' {lines ++}
;

// programa: global
//           |programa global
// ;
// global: declaracion   {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
//         |definicionFuncion  {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
//;
declaracion:  variable  ';'  {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
              |declaracionFuncion ';'              {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
;
declaracionFuncion: TIPODATO ID '('listaDeParametros')'                {if(controlId(punteroId,$<s.cadena>1)){
                                                                        punteroId=agregarId(punteroId,$<s.cadena>2,tipoDeDato($<s.cadena>1));
                                                                        punteroFunc=agregarFuncion(punteroFunc,$<s.cadena>2,$<s.cadena>1);
                                                                        funcionActual=ultimoDeLaLista(punteroFunc);
                                                                        funcionActual->parametros=asignar(parametros);
                                                                        parametros=NULL;
                                                                        }else{
                                                                          yyerror("Ya existe la variable");
                                                                        flag_error==1;}}
                    |VOID ID '('listaDeParametros')'                   {if(controlId(punteroId,$<s.cadena>1)){
                                                                        punteroId=agregarId(punteroId,$<s.cadena>2,tipoDeDato($<s.cadena>1));
                                                                        punteroFunc=agregarFuncion(punteroFunc,$<s.cadena>2,$<s.cadena>1);
                                                                        funcionActual=ultimoDeLaLista(punteroFunc);
                                                                        funcionActual->parametros=asignar(parametros);
                                                                        parametros=NULL;
                                                                        }else{
                                                                          yyerror("Ya existe la variable");
                                                                          flag_error==1;}}
;
definicionFuncion: TIPODATO ID '('listaDeParametros')' sentenciaCompuesta  {if(controlId(punteroId,$<s.cadena>1)){
                                                                            punteroId=agregarId(punteroId,$<s.cadena>2,tipoDeDato($<s.cadena>1));
                                                                            punteroFunc=agregarFuncion(punteroFunc,$<s.cadena>2,$<s.cadena>1);
                                                                            funcionActual=ultimoDeLaLista(punteroFunc);
                                                                            funcionActual->parametros=asignar(parametros);
                                                                            parametros=NULL;
                                                                            }else{
                                                                              yyerror("Ya existe la variable");
                                                                              flag_error==1;}}
                  |VOID ID '('listaDeParametros')' sentenciaCompuesta  {if(controlId(punteroId,$<s.cadena>1)){
                                                                        punteroId=agregarId(punteroId,$<s.cadena>2,tipoDeDato($<s.cadena>1));
                                                                        punteroFunc=agregarFuncion(punteroFunc,$<s.cadena>2,$<s.cadena>1);
                                                                        funcionActual=ultimoDeLaLista(punteroFunc);
                                                                        funcionActual->parametros=asignar(parametros);
                                                                        parametros=NULL;
                                                                        }else{
                                                                          yyerror("Ya existe la variable");
                                                                          flag_error==1;}}

;
listaDeParametros: 
                  |parametro 
                  |listaDeParametros ',' parametro 
;
parametro: TIPODATO ID  {parametros=agregarVariable(parametros,$<s.cadena>2,$<s.cadena>1);/*mostrarListaVariables(parametros);*/}
;

variable: TIPODATO ID {if(controlId){punteroId=agregarId(punteroId,$<s.cadena>2,tipoDeDato($<s.cadena>1));punteroVariables=agregarVariable(punteroVariables,$<s.cadena>2,$<s.cadena>1);}else{yyerror("Ya existe la variable");flag_error==1;}}
;

sentenciaCompuesta: '{'listaCompuesta'}'
;
listaCompuesta:  
                |listaCompuesta finSentencia 
                |listaCompuesta sentencia finSentencia
finSentencia: 
            | '\n' {lines ++}
  
;
sentencia: sentenciaCompuesta {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
          |sentenciaExpresion {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
          |sentenciaSeleccion {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
          |sentenciaIteracion {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
          |sentenciaSalto     {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
          |declaracion       {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
          |definicionFuncion
;
sentenciaExpresion: ';'       
                    |expresion';' {$<s.tipo>$ = $<s.tipo>1; strcpy($<s.cadena>$,$<s.cadena>1);$<s.tipo>$=$<s.tipo>1}
;
sentenciaSeleccion:  IF'('expresion')' sentencia 
                    |IF'('expresion')' sentencia ELSE sentencia
                    |SWITCH'('expresion')' sentencia
;
sentenciaIteracion: WHILE '(' expresion ')' sentencia
                    |DO sentencia WHILE'(' expresion ')' ';'
                    |FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentenciaCompuesta 
;
sentenciaSalto: CONTINUE';'       
                |BREAK ';'
                |RETURN expresion ';'
;
expresionOP: 
              |expresion
;
expresion: expresionAsignacion 
;

expresionAsignacion: expresionCondicional 
                     |expresionUnaria operacionAsignacion expresionAsignacion   { if(lvalueError($<s.cadena>1)){
                                                                                  printf("Error de lValue");
                                                                                  }else{
                                                                                  if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                                    $<s.tipo>$ = $<s.tipo>1; 
                                                                                    strcpy($<s.cadena>$,$<s.cadena>1);
                                                                                  }else{
                                                                                    printf("Error de tipos");
                                                                                    flag_error=1;YYERROR;}}}
;
operacionAsignacion: '='
                    |SUMADIRECTA
                    |RESTADIRECTA
;
expresionCondicional: expresionOr
                      |expresionOr '?' expresion ':' expresion 
;
expresionOr: expresionAnd 
            |expresionOr OR expresionAnd   {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
;
expresionAnd: expresionIgualdad 
             |expresionAnd AND expresionIgualdad    {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
;
expresionIgualdad: expresionRelacional
                  | expresionIgualdad operadorComparacion expresionRelacional  {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          $<s.tipo>$=$<s.tipo>1;
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
;
operadorComparacion: IGUALDAD DESIGUALDAD
;
expresionRelacional: expresionAditiva 
                     |expresionRelacional operadorRelacional expresionAditiva    {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          $<s.tipo>$=$<s.tipo>1;
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
;
operadorRelacional: '>' | '<' | MENORIGUAL | MAYORIGUAL
;
expresionAditiva: expresionMultiplicativa  
                  |expresionAditiva '+' expresionMultiplicativa   {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          $<s.tipo>$=$<s.tipo>1;
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
                  |expresionAditiva '-' expresionMultiplicativa  {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          $<s.tipo>$=$<s.tipo>1;
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
;
expresionMultiplicativa:  expresionUnaria 
                          | expresionMultiplicativa '*' expresionUnaria {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          $<s.tipo>$=$<s.tipo>1;
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
                          | expresionMultiplicativa '/' expresionUnaria  {if(controlOperacion(punteroId,$<s.cadena>1,$<s.cadena>3,$<s.tipo>1,$<s.tipo>3)){
                                                                          $<s.tipo>$ = $<s.tipo>1;
                                                                          strcpy($<s.cadena>$,$<s.cadena>1);
                                                                          $<s.tipo>$=$<s.tipo>1;
                                                                          }else{
                                                                          flag_error=1;YYERROR;}}
;
expresionUnaria: expresionPostfijo 
                 | expresionUnaria INCREMENTO {  if(!lvalueError($<s.cadena>1)){
                                                  $<s.tipo>$ = $<s.tipo>1;
                                                  strcpy($<s.cadena>$,$<s.cadena>1);
                                                  }else{
                                                    printf("Error de lValue");
                                                    flag_error=1;YYERROR;}}
                 | expresionUnaria DECREMENTO {  if(!lvalueError($<s.cadena>1)){
                                                  $<s.tipo>$ = $<s.tipo>1;
                                                  strcpy($<s.cadena>$,$<s.cadena>1);
                                                  }else{
                                                    printf("Error de lValue");
                                                    flag_error=1;YYERROR;}}                 
                 | operadorUnario expresionUnaria 
                 | '-' expresionUnaria %prec NEG 
                 | '+' expresionUnaria %prec POS 
                 | '*' expresionUnaria %prec PUNT 
;
operadorUnario: '&'|'!'
;
expresionPostfijo: expresionPrimaria                 
                  |expresionPostfijo'['expresion']'   
                  |expresionPostfijo'('listaDeArgumentos')' 
;
listaDeArgumentos: expresionAsignacion
                   |listaDeArgumentos ',' expresionAsignacion
;
expresionPrimaria: NUM        
                   |ID        
                   |LCADENA   
;




%%

yyerror (s)  
{
   printf ("Hubo un error en la linea %d",lines);
}

int main ()
{
  yyout = fopen("salida.txt","w");
  yyin = fopen("entrada.txt","r+");
  yyparse ();
  mostrarListaVariables(punteroVariables);
  printf("----------------------\n");
  mostrarListaFuncion(punteroFunc);
  mostrarListaVariables(parametros);
}
