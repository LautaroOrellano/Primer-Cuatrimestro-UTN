#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMPALABRA 50

typedef struct{
    int idLibro;
    char titulo[DIMPALABRA];
    char autor[DIMPALABRA];
    int stock;
} stLibro;

typedef struct{
    int idUsuario;
    char nombre[DIMPALABRA];
    int prestamosActivos;
} stUsuario;

typedef struct{
    int idPrestamo;
    int idUsuario;
    int idLibro;
    char fechaPrestamo[11];
    char fechaDevolucion[11];
} stPrestamo;

//Prototipado
void limpiarString(char string[]);

int main()
{



    return 0;
}

void limpiarString(char string[]){
    int posicion = strcspn(string, "\n");
    string[posicion] = '\0';
}

/**1. Generar las funciones necesarias para cargar cada estructura en su correspondiente
archivo. Modularizar de manera que exista una función que genere la estructura con
id autoincremental y otra que se encargue de abrir/cerrar el archivo y escribir el
nuevo dato. */

stLibro cargarUnLibro(){

    stLibro newLibro;

    static int idAutoIncremental = 1;
    newLibro.idLibro = idAutoIncremental;
    idAutoIncremental ++;


    printf("Titulo del libro a cargar");
    fgets(newLibro.titulo, DIMPALABRA, stdin);
    limpiarString(newLibro.titulo);

    printf("Autor del libro a cargar");
    fgets(newLibro.autor, DIMPALABRA, stdin);
    limpiarString(newLibro.autor);



}






