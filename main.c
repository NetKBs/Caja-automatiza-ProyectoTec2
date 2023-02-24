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
	printf("Minimo 8 caracteres y maximo 20\n");
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

}