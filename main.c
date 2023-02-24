#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 

#include "admin.c"
#include "utils.h"

int main() {
	struct stat file_stat; 
  	
  	// Checar si existen los archivos de administrador (primera vez)
    if (stat("./data/superuser/admin", &file_stat) != 0 || file_stat.st_size <= 0 ) {
    	crearAdmin();
    	printf("Cuenta de administrador creada con exito\n");
		system("pause");
    }
	
	char opc = '0';
	do {
		fflush(stdin);
		system("cls");
		
		printf("Iniciar menu de:\n");
		printf("1-Adminastrador\n");
		printf("2-Cliente\n");
		printf(">>> ");
		scanf("%c", &opc);

		switch (opc) {
			
			case '1': 
				adminMain();
				break;
			
			case '2': 
				printf("2");
				system("pause");
				break;
			
			default: 
				printf("incorrecto");
				system("pause");
							
		}
		
	} while (1);


	return 0;
}

