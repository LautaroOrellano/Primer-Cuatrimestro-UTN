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
    char categoria[DIMPAL]

}stProductos;

typedef struct{

    char categoria[DIMPAL];
    stProductos productos[DIM];
    int productosDisponibles;

}stCategorias;

//Prototipado
///Ejercicio1
stProductos cargarProducto();
int cargarProductos(stProductos productosSinCategorizar[DIMPROD]);
void mostrarProductos(stProductos productosSinCategorizar[DIMPROD], int validos);
///Ejercicio2
int categoriasDisponibles(stCategorias categorias[DIMCAT], int validos, char nombreCategoria[DIMPAL]);
void mostrarCategorias(stCategorias categorias[DIMCAT], int cantCategorias);
int cargaCategoria(stCategorias categorias[DIMCAT], int validos, stProductos productosSinCategorizar[DIMPROD]);
///Ejercicio3
int buscarCategoriaPorNomrbe(stCategorias productosCategorizados[DIMCAT], int contCategorias, char nombreCategoria[DIM]);
void guardarProductoConCategoria(stProductos productosSinCategorizar[DIMPROD], int validos, int contCategorias, stCategorias productosCategorizados[DIMCAT], char nombreCategoria[DIM]);

int main()
{
    ///Ejercicio1
    int validos = 0;
    stProductos productosSinCategorizar[DIMPROD];
    validos = cargarProductos(productosSinCategorizar);
    mostrarProductos(productosSinCategorizar, validos);

    ///Ejercicio2
    stCategorias categorias[DIMCAT];
    char nombreCategoria[DIMPAL];
    int cantCategorias = 0;
    cantCategorias = cargaCategoria(categorias, validos, productosSinCategorizar);
    mostrarCategorias(categorias, cantCategorias);

    ///Ejercicio3



    return 0;
}


///Ejercicio1
stProductos cargarProducto(){

    stProductos nuevoProducto;
    static int idAutoIncremental = 1;

    nuevoProducto.idProducto = idAutoIncremental;
    idAutoIncremental++;

    printf("Ingrese el stock del producto: ");
    fflush(stdin);
    scanf("%d", &nuevoProducto.stock);
    printf("\n");

    printf("Ingrese el precio del producto: ");
    fflush(stdin);
    scanf("%f", &nuevoProducto.precio);
    printf("\n");

    printf("Ingrese el nombre del producto: ");
    getchar();
    fgets(nuevoProducto.nombre, 20, stdin);
    printf("\n");

    printf("Ingrese el nombre de la categoria: ");
    fgets(nuevoProducto.categoria, 20, stdin);
    printf("\n");

    return nuevoProducto;
}
int cargarProductos(stProductos productosSinCategorizar[DIMPROD]){

    int i = 0;
    char opcion = 's';

    while(opcion == 's' && i < DIMPROD){
        productosSinCategorizar[i] = cargarProducto();
        i++;

        printf("Ingrese s para continuear o cualquier tecla para salir: ");
        scanf(" %c", &opcion);
        printf("\n");
    }

    return i;
}
void mostrarProductos(stProductos productosSinCategorizar[DIMPROD], int validos){

    for(int i=0; i<validos; i++){

        printf("____________________\n");
        printf("Id producto: %d\n", productosSinCategorizar[i].idProducto);
        printf("Stock: %d\n", productosSinCategorizar[i].stock);
        printf("Precio: %.02f USD \n", productosSinCategorizar[i].precio);
        printf("Nombre: %s", productosSinCategorizar[i].nombre);
        printf("Categoria: %s", productosSinCategorizar[i].categoria);
        printf("____________________\n");
    }
}
///Ejercicio2
int categoriasDisponibles(stCategorias categorias[DIMCAT], int validos, char nombreCategoria[DIMPAL]){

    int encontrado = -1;
    int i = 0;
    while(i<validos && encontrado == -1){
        if(strcmpi(categorias[i].categoria, nombreCategoria) == 0){
            encontrado = i;
        }
        i++;

    }
    return encontrado;
}
int cargaCategoria(stCategorias categorias[DIMCAT], int validos, stProductos productosSinCategorizar[DIMPROD]){
    int cantCategorias = 0;
    for(int i=0; i<validos; i++){

        if(categoriasDisponibles(categorias,cantCategorias,productosSinCategorizar[i].categoria) == -1){
            strcpy(categorias[cantCategorias].categoria, productosSinCategorizar[i].categoria);
            categorias[cantCategorias].productosDisponibles = 0;
            cantCategorias ++;
        }
    }
    return cantCategorias;
}
void mostrarCategorias(stCategorias categorias[DIMCAT], int cantCategorias){

    for(int i=0; i<cantCategorias; i++){
        printf("\n");
        printf("Categorias dispobibles: \n");
        printf("Categoria %d %s ", i+1, categorias[i].categoria);
    }
}
///Ejercicio3
void cargarProductosEnCategorias(stCategorias categorias[DIMCAT], int cantCategorias, stProductos productosSinCategorizar[DIMPROD], int validos){

    int indiceCategoria = -1;
    for(int i=0; i<validos; i++){
        indiceCategoria = categoriasDisponibles(categorias,validos,productosSinCategorizar[i].categoria);
        int validosProdxCat = categorias[indiceCategoria].productosDisponibles;
        categorias[indiceCategoria].productos[validosProdxCat] = productosSinCategorizar[i];
        categorias[indiceCategoria].productosDisponibles++;
    }
}



