#include <string.h>
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
	char *neuvoID,*nuevoTIPO;
	neuvoID =(char *)malloc(sizeof(char *));
	nuevoTIPO =(char *)malloc(sizeof(char *));
	strcpy(neuvoID,nuevoId);
	strcpy(nuevoTIPO,nuevoTipo);
	nuevo->id=neuvoID;
	nuevo->tipo= nuevoTIPO;
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
	char *neuvoID,*nuevoTIPO;
	neuvoID =(char *)malloc(sizeof(char *));
	nuevoTIPO =(char *)malloc(sizeof(char *));
	strcpy(neuvoID,nuevoId);
	strcpy(nuevoTIPO,nuevoTipo);
	nuevo->id=neuvoID;
	nuevo->tipo= nuevoTIPO;
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
struct nodoFuncion* ultimoDeLaLista(struct nodoFuncion* funcion){
    struct nodoFuncion *aux=funcion;
	if(funcion!=NULL){
        while(aux->next!=NULL){
         	aux=aux->next; 
        }
    }
    return aux; 
}
struct nodoVariable* asignar(struct nodoVariable* puntero){
	struct nodoVariable* aux ;
	aux = (struct nodoVariable*)malloc(sizeof(struct nodoVariable));
	aux	= puntero;
	return aux;
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
    	printf("ID     TIPO\n");
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
   	    	printf("ID     TIPO\n");
            printf("%s %s\n",aux->id,aux->tipo);
            printf("Parametros de %s:\n",aux->id);
            mostrarListaVariables((*aux).parametros);
            printf("---------------------------\n");
            aux=aux->next;
        }
    }
}

int controlId(struct nodoId *puntero, char *id){	
	return buscarId(puntero,id)==NULL;
}

int lvalueError(char* cadena){
	if(!strcmp(cadena,"0") || cadena[0]=='\"'){
		return 1;
	}else{
		return 0;
	}
}

int tipoId(struct nodoId *punteroId,char* cadena,int tipo){
	if(tipo==5){
		struct nodoId *a = buscarId(punteroId,cadena);{
			if(a==NULL){
				return -1;
			}else{				
				return a->tipo;
			}			
		}
	}else{
		return tipo;
	}
}

int controlDeTiposOperacion(int tipo1,int tipo2){
	if((tipo1==1 || tipo1==2 || tipo1==3)&&(tipo2==1 || tipo2==2 || tipo2==3)){
		return 1;
	}
	if((tipo1==4 || tipo2 == 4)){
		return 0;
	} 
}
int controlOperacion(struct nodoId *punteroId,char *cadena1,char *cadena2,int tipo1, int tipo2){
	tipo1 = tipoId(punteroId,cadena1,tipo1);
	tipo2 = tipoId(punteroId,cadena2,tipo2);
	if(tipo1==-1 || tipo2==-1){
		printf("No existe el identificador\n");
		return 0;
	}else if(!controlDeTiposOperacion(tipo1,tipo2)){
			printf("Error de tipos");
			return 0;
	}else{
		return 1;	
	}	
}
int tipoDeDato(char* tipo){
	if(!strcmp(tipo,"int")){
		return 1;
	}else {
		if(!strcmp(tipo,"float")){
			return 2;
		}else{
			if(!strcmp(tipo,"char")){
				return 3;	
			}else{
				 if(!strcmp(tipo,"char*")){
					return 4;	
				}else{
					if(!strcmp(tipo,"void")){
						return 0;
					}}}}}
}
