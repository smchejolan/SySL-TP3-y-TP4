#include <string.h>

int lvalueError(int tipo){
	return tipo<5;
}

int tipoId(char* tipo){
	if(!strcmp("int",tipo)){
		return 1;
	}else if(!strcmp("float",tipo)){
		return 2;
	}else if(!strcmp("char",tipo)){
		return 3;
	}
}

int controlDeTiposOperacion(int tipo1, int tipo2){
	if((tipo1==1 || tipo1 == 2 || tipo1==3)&&(tipo2==1 || tipo2 == 2 || tipo2==3)){
		return 1; 
	}else if()
	 
}
