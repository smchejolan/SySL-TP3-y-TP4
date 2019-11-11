#include <string.h>
#include "Listas.h"

int lvalueError(char* cadena){
	if(!strcmp(cadena,"0") || cadena[0]=='\"'){
		printf("Error de lvalue a izquierda");
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

