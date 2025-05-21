#include <stdio.h>
#include <stdlib.h>



typedef struct{
    int idLibro;
    char titulo[DIMPALABRA];
    char autor[DIMPALABRA];
    int stock;
}stLibro

type struct{
    int idUsuario;
    char nombre[DIMPALABRA];
    int prestamosActivos;
}stUsuario

type struct{
    int idPrestamo;
    int idUsuario;
    int idLibro;
    char fechaPrestamo[11];
    char fechaDevolucion[11];
}stPrestamo

int main()
{



    return 0;
}
