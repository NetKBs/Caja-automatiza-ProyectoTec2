#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 

#define true 0
#define false 1

int main() {
	struct stat result; 
  
    if (stat("./data/superuser/admin", &result) == true) {
    	// No existe los datos de admin
    }

	return 0;
}