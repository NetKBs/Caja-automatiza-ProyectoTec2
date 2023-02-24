#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 

#define true 0
#define false 1

void crearAdmin();

int main() {
	struct stat file_stat; 
  	
  	// Checar si existen los archivos de administrador (primera vez)
    if (stat("./data/superuser/admin", &file_stat) != true || file_stat.st_size <= 0 ) {
    	crearAdmin();
    }
	


	return 0;
}

void crearAdmin() {
	FILE *fp;
	char clave[30];

	fp = fopen("./data/superuser/admin", "w+");

	printf("Inserte clave de administrador: \n");
	printf("Minimo 8 caracteres y maximo 20\n Debe contener minusculas y mayusculas\n");
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
	}
	
	if (mayus == 0 || minus == 0 || nums == 0) {
		printf("Debe contener mayusculas, minusculas y numeros");
		system("pause");
		return crearAdmin();
	}
	
	fprintf(fp, clave);
	fclose(fp);
	printf("Cuenta de administrador creada con exito\n");
	printf("Clave asignada: %s\n-No Perderla Bajo Ninguna Circunstancia-\n", clave);
	system("pause");
}