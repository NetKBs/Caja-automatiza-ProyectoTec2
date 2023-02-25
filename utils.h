#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _UTILSH_
#define _UTILSH_


// Compara una clave con la clave del administrador
int verificarAdmin(char clave[30]) {

	char file_text[30]; 
	
	FILE *fp = fopen("data/superuser/admin", "r");
	fscanf(fp, "%s", file_text);
	
	if (strcmp(clave, file_text) != 0) {
		return 1;
	}
	
	return 0; // coninciden
}



// Crear administrador nuevo
int crearAdmin() {
	FILE *fp;
	char clave[30];

	fp = fopen("./data/superuser/admin", "w+");

	printf("Inserte clave de administrador: \n");
	printf("Minimo 8 caracteres y maximo 30\n Debe contener minusculas y mayusculas\n");
	printf("Debe contener numeros\n");
	gets(clave);

	// Verificar validez
	int len_clave = strlen(clave);

	if (len_clave < 8) {
		printf("Minimo 8 caracteres de longitud");
		system("pause");
		return crearAdmin();
		
	} else if (len_clave > 30) {
		printf("Maximo 30 caracteres de longitud");
		system("pause");
		return crearAdmin();
	}
	
	short mayus = 0, minus = 0;
	short nums = 0;
	
	for (int i = 0; i < strlen(clave); i++) {
		
		// Existen mayúsculas y minúsculas
		if (clave[i] >= 'A' && clave[i] <= 'Z' && mayus == 0) {
			mayus ++;
		
		} else if (clave[i] >= 'a' && clave[i] <= 'z' && minus == 0) {
			minus ++;			
		} 
		// Existen números
		if (clave[i] >= '0' && clave[i] <= '9' && nums == 0) {
			nums ++;
		}
		
		if (mayus != 0 && minus != 0 && nums != 0) { // se ha cumplido las condiciones
			fprintf(fp, clave);
			fclose(fp);
			return 0;
		}
	}

	printf("Debe contener mayusculas, minusculas y numeros");
	system("pause");
	return crearAdmin();
}


#endif