#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int adminMain() {
	system("cls");
	fflush(stdin);
	
	char clave[30];
	printf("Escriba la clave de administrador: ");
	gets(clave);
	
	if (verificarAdmin(clave) != 0) {
		printf("La clave no coincide con la del administrador");
		system("pause");
	}
	
	char opc = '0'
	
	do {
		fflush(stdin);
		
		printf("Panel De Administrador\n");
		printf("1-Reportes\n2-Productos\n3-Cambiar Clave\n4-Restaurar Sistema\n5-Salir");
		scanf("%c", &opc);
		
		switch (opc) {
			
			case 1: {
				break;
			}
			
			case 2: {
				break;
			}
			
			case 3: {
		
				break;
			}
			
			case 4: {
				
				break;
			}
			
			case 5: {
				
				break;
			}
		}
		
	} while (opc != '5');
	
	
	
	return 0;
}