#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h> 

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE_PRODUCTO 50

typedef struct Producto{
    int id;
    char nombre[MAX_NOMBRE_PRODUCTO];
    int cantidad;
    float precio;
    
} Producto;


int num_productos = 0;
Producto productos[MAX_PRODUCTOS];

void cargar_productos_desde_archivo();
int buscar_producto_por_nombre(char *nombre);
int buscar_producto_por_id(int id);
void eliminar_producto_por_id(int id);
void modificar_producto_por_id(int id);
void guardar_productos_en_archivo();
int obtener_nuevo_id();



int adminProducts() {
	
    cargar_productos_desde_archivo();

    char opcion;
    do {
        printf("\nSeleccione una opcion:\n");
        printf("1. Agregar producto al stock\n");
        printf("2. Modificar producto por ID\n");
        printf("3. Eliminar producto por ID\n");
        printf("4. Mostrar productos en stock\n");
        printf("0. Salir\n");
        fflush(stdin);
        scanf("%c", &opcion);

        switch (opcion) {
        	
        case '1':
        	
            if (num_productos < MAX_PRODUCTOS) {
                Producto producto;
                producto.id = obtener_nuevo_id();
				
				fflush(stdin);
                printf("Ingrese el nombre del producto: ");
                gets(producto.nombre);

                printf("Ingrese la cantidad del producto: ");
                scanf("%d", &producto.cantidad);

                printf("Ingrese el precio del producto: ");
                scanf("%f", &producto.precio);

                // Buscar si el producto ya existe y sumarle la cantidad
                int index = buscar_producto_por_nombre(producto.nombre);
                
                if (index != -1) {
                    productos[index].cantidad += producto.cantidad;
                    printf("El producto ya existe, se ha sumado la cantidad.\n");
                
				} else {
                    productos[num_productos] = producto;
                    num_productos++;
                }
                
            } else {
                printf("No se pueden agregar mas productos, se ha alcanzado el maximo de %d.\n", MAX_PRODUCTOS);
            }
            break;
            
        case '2':
        	
            if (num_productos > 0) {
            	int id;
                printf("Ingrese el ID del producto a modificar: ");
                scanf("%d", &id);
                
                modificar_producto_por_id(id);
                
            } else {
                printf("No hay productos para modificar.\n");
            }
            break;
            
        case '3':
        	
            if (num_productos > 0) {
                int id;
                
                printf("Ingrese el ID del producto a eliminar: ");
                scanf("%d", &id);
                               
                eliminar_producto_por_id(id);
                
            } else {
                printf("No hay productos para eliminar.\n");
            }
            break;
            
        case '4':
        	
            if (num_productos > 0) {
                printf("ID\tNombre\tCantidad\tPrecio\n");
                
                for (int i = 0; i < num_productos; i++) {
                    printf("%d\t%s\t%d\t\t%.2f\n", productos[i].id, productos[i].nombre, productos[i].cantidad, productos[i].precio);
                }
                
            } else {
                printf("No hay productos para mostrar.\n");
            }
            break;
            
        case '0':
            break;
        default:
            printf("Opcion invalida, intente de nuevo.\n");
            break;
        }

        guardar_productos_en_archivo();
        
    } while (opcion != '0');

    return 0;

}



void cargar_productos_desde_archivo() {	
    FILE * archivo_productos = fopen("./data/products/products.txt", "r");
    struct stat file_stat;
    stat("./data/products/products.txt", &file_stat);
    
    
    if (archivo_productos != NULL) {
    	
    	if(file_stat.st_size <= 0) {
    		fclose(archivo_productos);
    		
		} else {
			
	        while (!feof(archivo_productos) && num_productos < MAX_PRODUCTOS) {      	
	            Producto producto;
	            // cargar
	            fscanf(archivo_productos, "%d %s %d %f\n", & producto.id, producto.nombre, & producto.cantidad, & producto.precio);  
	            productos[num_productos] = producto; // rellenar
	            num_productos++;
	
			}
		}
        fclose(archivo_productos);
    
}
}


int buscar_producto_por_nombre(char *nombre) {

    for (int i = 0; i < num_productos; i++) {
        if (strcasecmp(productos[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}


int buscar_producto_por_id(int id) {

    for (int i = 0; i < num_productos; i++) {
        if (productos[i].id == id) {
            return i;
        }
    }
    return -1;
}


void eliminar_producto_por_id(int id) {
	
    int index = buscar_producto_por_id(id);
    int cantidad;
    
    if (index != -1) {
    	
    	fflush(stdin);
    	printf("Indique la cantidad a eliminar del producto: ");
    	scanf("%d", &cantidad);
    	
    	// Se ha eliminado todo en stock del producto
    	if (productos[index].cantidad - cantidad <= 0) {
    		// Mover todos los productos a la izquierda para reemplazar el producto eliminado
       	 	for (int i = index; i < num_productos - 1; i++) {
        	    productos[i] = productos[i + 1];
        	}
        
       		 num_productos--;	
       		 
		} else {
			productos[index].cantidad = productos[index].cantidad - cantidad;
			
		}
        
        printf("Producto eliminado.\n");
        
    } else {
        printf("El producto con ID %d no existe.\n", id);
    }
}


void modificar_producto_por_id(int id) {
	
    int index = buscar_producto_por_id(id);
    
    if (index != -1) {
    	
    	fflush(stdin);
        Producto *producto = &productos[index];
        printf("Producto encontrado: %d %s %d %f\n", producto -> id, producto -> nombre, producto -> cantidad, producto -> precio);
		
		char nombre_nuevo[MAX_NOMBRE_PRODUCTO];
        printf("Ingrese el nuevo nombre del producto (Enter para dejarlo como estaba)");
        gets(nombre_nuevo);
        
        if (nombre_nuevo[0] != '\0') {
			strcpy(producto -> nombre, nombre_nuevo);      
        }

        printf("Ingrese la nueva cantidad del producto (o -1 para dejarla igual): ");
        int cantidad_nueva;
        scanf("%d", &cantidad_nueva);
        
        if (cantidad_nueva != -1) {
            producto->cantidad = cantidad_nueva;
        }
        
        printf("Ingrese el nuevo precio del producto (o -1 para dejarlo igual): ");
        float precio_nuevo;
        scanf("%f", &precio_nuevo);
        
        if (precio_nuevo != -1) {
            producto -> precio = precio_nuevo;
        }

        printf("Producto modificado: %d %s %d %f\n", producto -> id, producto -> nombre, producto -> cantidad, producto -> precio);
        
    } else {
        printf("El producto con ID %d no existe.\n", id);
    }

}


void guardar_productos_en_archivo() {
    FILE * archivo_productos = fopen("./data/products/products.txt", "w");
    
    for (int i = 0; i < num_productos; i++) {
        fprintf(archivo_productos, "%d %s %d %.2f\n", productos[i].id, productos[i].nombre, productos[i].cantidad, productos[i].precio);
    }
    
    fclose(archivo_productos);
}


int obtener_nuevo_id() {
    int max_id = 0;
    
    for (int i = 0; i < num_productos; i++) {
        if (productos[i].id > max_id) {
            max_id = productos[i].id;
        }
    }
    
    return max_id + 1;
}