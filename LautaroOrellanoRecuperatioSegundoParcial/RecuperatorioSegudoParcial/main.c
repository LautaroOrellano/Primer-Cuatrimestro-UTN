///Lautaro Orellano Comision14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {

    int id_producto;
    char nombre[20];
    double precio_venta;
    int stock;
    int stock_minimo;

} stProducto;


typedef struct {

    int id_venta;
    int id_producto;
    int cantidad;
    float sub_total;
    double descuento;
    float total;

} stVenta;

//------------------PROTOTIPADO--------------------
///Ejercicio1
int contarRegistrosProductos(char archivoProductos[]);
///Ejercicio2
void mostrarUnProducto(stProducto aux);
stProducto* cargarProductosDesdeArchivo(char archivoProductos[], int dimensionMain);
///Ejercicio3
void buscarProductoPorID(stProducto* arregloProductoMain, int dimensionMain, int idBuscado);
///Ejercicio4
void mostrarProductosDisponibles(stProducto* arregloProductoMain, int dimensionMain);
///Ejercicio5
void actualizarStockProducto(stProducto* arregloProductoMain, int dimensionMain, int idProducto, int nuevoStock);
///Ejercicio6
int calcularElsubTotalDeUnaVenta(stProducto* arregloProductoMain, int idProductoCalcular, int dimensionMain, int suma, int cantidadVenta);

///Ejercicio7
double aplicarDescuento(stProducto* arregloProductoMain, int idProductoCalcular, int dimensionMain, int suma, int cantidadVenta);
void efectuarVenta(stProducto* arregloProductoMain, int dimensionMain, int idProductoCalcular, int suma, int cantidadVenta);

//-------------------------------------------------


int main(){

    char archivoProductos[] = "productos.bin";

    ///Ejercicio1

    int dimensionMain  = contarRegistrosProductos(archivoProductos);

    printf("La cantidad de registros en el archivo es de: %d \n", dimensionMain );

    system("pause");
    system("cls");

    ///Ejercicio2

    stProducto* arregloProductoMain = cargarProductosDesdeArchivo(archivoProductos, dimensionMain);
    printf("Contenido arreglo producto: \n\n");

    for(int i=0; i<dimensionMain; i++){

        mostrarUnProducto(arregloProductoMain[i]);
    }

    system("pause");
    system("cls");

    ///Ejercicio3

    int idBuscado = 0;

    printf("ID del producto que desea buscar: ");
    fflush(stdin);
    scanf("%d", &idBuscado);
    //while(getchar() != '\n');

    buscarProductoPorID(arregloProductoMain, dimensionMain, idBuscado);

    system("pause");
    system("cls");

    ///Ejercicio4

    printf("Los productos disponibles son: \n\n");
    mostrarProductosDisponibles(arregloProductoMain, dimensionMain);

    system("pause");
    system("cls");

    ///Ejercicio5

    int idProductoAmodificar = 0;
    int nuevoStock = 0;

    printf("Ingrese el id del producto a modificar");
    fflush(stdin);
    scanf("%d", &idProductoAmodificar);
    while(getchar() != '\n');

    printf("Ingrese el stock nuevo");
    fflush(stdin);
    scanf("%d", &nuevoStock);
    while(getchar() != '\n');

    actualizarStockProducto(arregloProductoMain, dimensionMain, idProductoAmodificar, nuevoStock);

    printf("El arreglo con el producto modificado es: \n\n");


    for(int i=0; i<dimensionMain; i++){

        mostrarUnProducto(arregloProductoMain[i]);
    }

    system("pause");
    system("cls");

    ///Ejercicio6
    int cantidadVenta = 0;
    int suma = 0;
    int idProductoCalcular = 0;

    printf("Ingrese el id del producto a calcular");
    fflush(stdin);
    scanf("%d", &idProductoCalcular);

    printf("Cuantos ventas quiere calcular?");
    fflush(stdin);
    scanf("%d", &cantidadVenta);

    int subTotalDeVenta = calcularElsubTotalDeUnaVenta(arregloProductoMain,  idProductoCalcular, dimensionMain, suma, cantidadVenta);

    printf("Subtotal de venta: %d \n", subTotalDeVenta);


    system("pause");
    system("cls");

    ///Ejercicio7

    efectuarVenta(arregloProductoMain, dimensionMain, idProductoCalcular, suma, cantidadVenta);

    system("pause");
    system("cls");

    free(arregloProductoMain);

    return 0;
}

///Ejercicio1

int contarRegistrosProductos(char archivoProductos[]){

    int dimension = 0;
    long registros = 0;

    FILE* arch = fopen(archivoProductos, "rb");
    stProducto aux;

    if(arch != NULL){

        fseek(arch, 0, SEEK_END);
        registros = ftell(arch);
        dimension = registros/sizeof(stProducto);

        fclose(arch);
    } else {
        printf("Error. \n");
    }

    return dimension;
}


///Ejercicio2

void mostrarUnProducto(stProducto aux){

    printf("ID PRODUCTO: %d \n", aux.id_producto);
    printf("NOMBRE: %s \n", aux.nombre);
    printf("PRECIO VENTA: %lf \n", aux.precio_venta);
    printf("STOCK: %d \n", aux.stock);
    printf("STOCK MINIMO: %d \n", aux.stock_minimo);
    printf("---------------------------- \n\n");

}

stProducto* cargarProductosDesdeArchivo(char archivoProductos[], int dimensionMain){

    int dimension = 0;

    FILE* arch = fopen(archivoProductos, "rb");
    stProducto* arregloProducto = (stProducto*) malloc(sizeof(stProducto) * dimensionMain);
    stProducto aux;
    int i = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stProducto), 1, arch) > 0){

            arregloProducto[i] = aux;
            i++;
        }

        fclose(arch);
    } else {
        printf("Error. \n");
    }

    return arregloProducto;

}

///Ejercicio3

void buscarProductoPorID(stProducto* arregloProductoMain, int dimensionMain, int idBuscado){

    int encontrado = 0;

    for(int i=0; i<dimensionMain; i++){

        if(arregloProductoMain[i].id_producto == idBuscado && encontrado == 0){

            printf("Se encontro su id. \n");
            encontrado = 1;
            printf("El producto con ese id es: %s \n", arregloProductoMain[i].nombre);
        }
    }

}

///Ejercicio4

void mostrarProductosDisponibles(stProducto* arregloProductoMain, int dimensionMain){

    for(int i=0; i<dimensionMain; i++){

        if( 0 != arregloProductoMain[i].stock){

            mostrarUnProducto(arregloProductoMain[i]);
        }
    }
}

///Ejercicio5

void actualizarStockProducto(stProducto* arregloProductoMain, int dimensionMain, int idProductoAmodificar, int nuevoStock){

    for(int i=0; i<dimensionMain; i++){

        if(arregloProductoMain[i].id_producto == idProductoAmodificar){

            arregloProductoMain[i].stock = nuevoStock;
        }
    }
}

///Ejercicio6

int calcularElsubTotalDeUnaVenta(stProducto* arregloProductoMain, int idProductoCalcular, int dimensionMain, int suma, int cantidadVenta){

    if(cantidadVenta == 0){

        return suma;

    } else {

        return suma = arregloProductoMain[idProductoCalcular].precio_venta + calcularElsubTotalDeUnaVenta(arregloProductoMain, idProductoCalcular, dimensionMain, suma, cantidadVenta-1);
    }

}

///Ejercicio7

void efectuarVenta(stProducto* arregloProductoMain, int dimensionMain, int idProductoCalcular, int suma, int cantidadVenta){

    printf("--------------Productos Disponibles---------\n");

    for(int i=0; i<dimensionMain; i++){

        mostrarUnProducto(arregloProductoMain[i]);
    }

    printf("--------------Stock suficiente---------\n");

    mostrarProductosDisponibles(arregloProductoMain, dimensionMain);

    printf("--------------Calcular Subtotal---------\n");

    double subTotalDeVenta = aplicarDescuento(arregloProductoMain, idProductoCalcular, dimensionMain, suma, cantidadVenta);

    double descuento = 0;

    if(subTotalDeVenta > 2000){

        descuento = subTotalDeVenta * 0,5 / 100;
        printf("Se le hizo un descuento del 5% total: %lf", descuento);

    } else if (subTotalDeVenta > 5000) {

        descuento = subTotalDeVenta * 0,10 / 100;
        printf("Se le hizo un descuento del 5% total: %lf", descuento);

    } else if (subTotalDeVenta > 9000){
        descuento = subTotalDeVenta * 0,15 / 100;
        printf("Se le hizo un descuento del 5% total: %lf", descuento);
    }

}

double aplicarDescuento(stProducto* arregloProductoMain, int idProductoCalcular, int dimensionMain, int suma, int cantidadVenta){

    printf("Ingrese el id del producto a calcular");
    fflush(stdin);
    scanf("%d", &idProductoCalcular);

    printf("Cuantos ventas quiere calcular?");
    fflush(stdin);
    scanf("%d", &cantidadVenta);

    double subTotalDeVenta = calcularElsubTotalDeUnaVenta(arregloProductoMain,  idProductoCalcular, dimensionMain, suma, cantidadVenta);

    printf("Subtotal de venta: %lf \n", subTotalDeVenta);

    return subTotalDeVenta;
}

