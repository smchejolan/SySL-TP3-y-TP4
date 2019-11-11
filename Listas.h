#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nodoId{
	char* id;
	int tipo;
	struct nodoId *next;
};

struct nodoVariable{
	char* id;
	char* tipo;
	struct nodoVariable *next;
};
struct nodoFuncion{
	char* id;
	char* tipo;
	struct nodoVariable *parametros;
	struct nodoFuncion *next;
};

struct nodoVariable *agregarVariable(struct nodoVariable *puntero, char *nuevoId,char *nuevoTipo){
	struct nodoVariable *nuevo;
	nuevo = (struct nodoVariable*)malloc(sizeof(struct nodoVariable));
	nuevo->id=nuevoId;
	nuevo->tipo= nuevoTipo;
	nuevo->next=NULL;
	if(puntero!=NULL){
        struct nodoVariable *aux = puntero;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next = nuevo;
    }else{
        puntero = nuevo;
    }
    return puntero;
}
struct nodoFuncion *agregarFuncion(struct nodoFuncion *puntero, char *nuevoId,char *nuevoTipo){
	struct nodoFuncion *nuevo;
	nuevo = (struct nodoFuncion*)malloc(sizeof(struct nodoFuncion));
	nuevo->id=nuevoId;
	nuevo->tipo= nuevoTipo;
	nuevo->parametros=NULL;
	nuevo->next=NULL;
	if(puntero!=NULL){
        struct nodoFuncion *aux = puntero;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next = nuevo;
    }else{
        puntero = nuevo;
    }
    return puntero;
}
struct nodoId *agregarId(struct nodoId *puntero, char *nuevoId, int tipo){
	struct nodoId *nuevo;
	nuevo = (struct nodoId*)malloc(sizeof(struct nodoId));
	nuevo->id=nuevoId;
	nuevo->tipo=tipo;
	nuevo->next=NULL;
	if(puntero!=NULL){
        struct nodoId *aux = puntero;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next = nuevo;
    }else{
        puntero = nuevo;
    }
    return puntero;
}

struct nodoId *buscarId(struct nodoId *puntero, char *idMatch){
    struct nodoId *punteroEncontrado = NULL;
    int encontrado=0;
    if(puntero!=NULL){
        struct nodoId *aux=puntero;
        while(aux!=NULL && encontrado==0){
            if(strcmp(aux->id,idMatch)==0){
                punteroEncontrado=aux;
                encontrado=1;
            }else{
                aux=aux->next;
            }
        }
    }
    return punteroEncontrado;
}


void mostrarListaVariables(struct nodoVariable *puntero){
    struct nodoVariable *aux=puntero;
    if(puntero!=NULL){
        while(aux!=NULL){
            printf("%s %s\n",aux->id,aux->tipo);
            aux=aux->next;
        }
    }
}
void mostrarListaFuncion(struct nodoFuncion *puntero){
    struct nodoFuncion *aux=puntero;
    if(puntero!=NULL){
        while(aux!=NULL){
            printf("%s %s\n",aux->id,aux->tipo);
            printf("Parametros de %s:\n",aux->id);
            mostrarListaVariables((*aux).parametros);
            aux=aux->next;
        }
    }
}
