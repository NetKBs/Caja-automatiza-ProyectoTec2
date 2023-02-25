#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


int cambiarClave();

int adminMain() {
	
	system("cls");
	fflush(stdin);
	
	char clave[30];
	printf("Escriba la clave de administrador: ");
	gets(clave);
	
	if (verificarAdmin(clave) != 0) {
		printf("La clave no coincide con la del administrador");
		system("pause");
		return 1;
	} 
	
	
	char opc = '0';
	short temp; // Para verificar procesos de funciones
	
	do {
		fflush(stdin);
		
		printf("Panel De Administrador\n");
		printf("1-Reportes\n2-Productos\n3-Cambiar Clave\n4-Restaurar Sistema\n5-Salir");
		scanf("%c", &opc);
		
		switch (opc) {
			
			case '1': 
				break;
			
		
			case '2': 
				break;
			
			
			case '3': 
				temp = cambiarClave();
				if (!temp) { // Si se cambió, mandar al munú de inicio del programa
					opc = '5';
				}
				
				break;
			
			
			case '4': 
				
				break;
			
			
			case '5': 
				
				break;
			
			
			default: 
				printf("Incorrecto");
				system("pause");
				
			
		}
		
	} while (opc != '5');
	

	
	return 0;
}


int cambiarClave() {
	fflush(stdin);
	char clave_actual[30];
	
	printf("Escribe la clave actual: ");
	gets(clave_actual);
	
	// Verificamos contrseña
	if (verificarAdmin(clave_actual) != 0) {
		printf("No coincide\n");
		system("pause");
		return 1;
		
	}
	
	crearAdmin();
	printf("Clave cambiada con exito");
	system("pause");
	return 0;
	
}