#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int admin() {
	system("cls");
	char clave[30];
	FILE *fp = fopen("data/superuser/admin", "r");
	
	fflush(stdin);
	printf("Escriba la clave de administrador: ");
	gets(clave);
	
	char file_text[30]; 
	fscanf(fp, "%s", file_text);
	
	if (strcmp(clave, file_text) != 0) {
		printf("La clave no conincide con la del administrador");
		system("pause");
		return 1;
	}
	
	
	return 0;
}