#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DIMPAL 20
#define DIM 100
#define DIMPROD 50
#define DIMCAT 30

typedef struct{

    int idProducto;
    int stock;
    float precio;
    char nombre[DIMPAL];
    char categoriaProducto[DIMPAL]

}stProducto;

typedef struct{

    char categoria[DIMPAL];
    stProducto producto[DIM];
    int productosDisponibles;

}stCategorias;

//Prototipado
///Ejercicio1
int cargaProducto(stProducto productosSinCategorizar[DIMPROD]);
void mostrarProductos(stProducto productosSinCategorizar[DIMPROD], int validos);
///Ejercicio2
int categoriasDisponibles(stProducto productosSinCategorizar[DIMPROD], int validos, stCategorias productosCategorizados[DIMCAT]);
void mostrarCategorias(stCategorias productosCategorizados[DIMCAT], int contCategorias);



int main()
{
    ///Ejercicio1
    int validos = 0;
    stProducto productosSinCategorizar[DIMPROD];
    validos = cargaProducto(productosSinCategorizar);
    mostrarProductos(productosSinCategorizar, validos);

    ///Ejercicio2
    int contCategorias = 0;
    stCategorias productosCategorizados[DIMCAT];
    contCategorias = categoriasDisponibles(productosSinCategorizar, validos, productosCategorizados);
    mostrarCategorias(productosCategorizados, contCategorias);

    ///Ejercicio3




    return 0;
}


///Ejercicio1
int cargaProducto(stProducto productosSinCategorizar[DIMPROD]){

    int i = 0;
    char opcion = 's';

    while( opcion == 's' && i<DIMPROD){

        productosSinCategorizar[i].idProducto = i+1;

        printf("Stock del producto %d: ", i+1);
        fflush(stdin);
        scanf("%d", &productosSinCategorizar[i].stock);
        printf("\n");

        printf("Precio del producto %d: ", i+1);
        fflush(stdin);
        scanf("%f", &productosSinCategorizar[i].precio);
        printf("\n");

        printf("Nombre del producto %d: ", i+1);
        getchar();
        fgets(productosSinCategorizar[i].nombre, 20, stdin);
        printf("\n");

        printf("Nombre de la categoria %d: ", i+1);
        fgets(productosSinCategorizar[i].categoriaProducto, 20, stdin);
        printf("\n");

        printf("Desea cargar otro producto? (s o n): ");
        scanf("%c", &opcion);
        printf("\n");

        i++;
    }
    return i;
}
void mostrarProductos(stProducto productosSinCategorizar[DIMPROD], int validos){

    for(int i=0; i<validos; i++){

        printf("____________________\n");
        printf("Id producto: %d\n", productosSinCategorizar[i].idProducto);
        printf("Stock: %d\n", productosSinCategorizar[i].stock);
        printf("Precio: %.02f SD \n", productosSinCategorizar[i].precio);
        printf("Nombre: %s", productosSinCategorizar[i].nombre);
        printf("Categoria: %s", productosSinCategorizar[i].categoriaProducto);
        printf("____________________\n");
    }
}

int categoriasDisponibles(stProducto productosSinCategorizar[DIMPROD], int validos, stCategorias productosCategorizados[DIMCAT]){

    char categoria[20];
    int cont=0;
    int flag;

    for(int i=0; i<validos; i++){
        strcpy(categoria, productosSinCategorizar[i].categoriaProducto);
        flag = 0;

        for(int j=0; j<cont; j++){
            if(strcmp(productosCategorizados[j].categoria, categoria)==0){
            flag = 1;
            break;
            }
        }

        if(!flag){
            strcpy(productosCategorizados[i].categoria, categoria);
            cont++;
        }
    }
    return cont;
}

void mostrarCategorias(stCategorias productosCategorizados[DIMCAT], int contCategorias){

    for(int i=0; i<contCategorias; i++){
        printf("\n");
        printf("Categoria %d %s ", i+1, productosCategorizados[i].categoria);
    }
}


