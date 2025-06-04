#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD 7

typedef struct
{
    int idVieajes;
    char origen[50];
    char destino[50];
    int cantidadPasajeross;
}stVieajes;

typedef struct
{
    int idPasajeros;
    int idVieajes;
    char nombre[50];
    char dni[10];
    int despacheEquipaje;
}stPasajeros;

//Prototipado
int contarRegistrosArchivo(char nombreArchivo[], size_t(registro));
void cargarArregloPasajeros(char archivoPasajeros[], int cantRegistroPasajeros);
stPasajeros mostrarPasajero(stPasajeros aux);

int main()
{

    char archivoPasajeros[] = "Pasajeros.bin";
    char archivoVieajes[] = "Pasajeros.bin";


    int cantRegistroPasajeros = contarRegistrosArchivo(archivoPasajeros, sizeof(stPasajeros));
    printf("Cantidad de registro Pasajeros: %d \n", cantRegistroPasajeros);

    int cantRegistroVieajes = contarRegistrosArchivo(archivoVieajes, sizeof(stVieajes));
    printf("Cantidad de registro stVieajes: %d \n", cantRegistroVieajes);

    cargarArregloPasajeros(archivoPasajeros, cantRegistroPasajeros);

    return 0;
}

///Ejercicio1
int contarRegistrosArchivo(char nombreArchivo[], size_t(registro)){

    FILE *arch = fopen(nombreArchivo, "rb");
    int cantidadRegistros = 0;

    if(arch != NULL){

            fseek(arch, 0, SEEK_END);
            int validos = ftell(arch);
            cantidadRegistros = validos / registro;
            fclose(arch);

    } else {
        printf("No se pudo leer el archivo");
    }
    return cantidadRegistros;
}

///Ejercicio2
void cargarArregloPasajeros(char archivoPasajeros[], int cantRegistroPasajeros){

    FILE *arch = fopen(archivoPasajeros, "rb");
    stPasajeros* arregloPasajeros = NULL;
    stPasajeros aux;
    int i = 0;

    if(arch != NULL){

        arregloPasajeros = (stPasajeros*) malloc(sizeof(stPasajeros)*cantRegistroPasajeros);
        while(fread(&aux, sizeof(stPasajeros), 1, arch) > 0 && i<0){

            arregloPasajeros[i] = aux;
            i++;
        }

        for(i = 0; i < cantRegistroPasajeros; i++){

            mostrarPasajero(aux);
        }

        fclose(arch);


    } else {
        printf("El archivo no se pudo abrir. \n");
    }
}

stPasajeros mostrarPasajero(stPasajeros aux){

    printf("Id: %d \n", aux.idPasajeros);
    printf("Id viaje %d \n", aux.idVieajes);
    printf("Nombre: %s \n", aux.nombre);
    printf("Dni: %s \n", aux.dni);
    printf("DespacheEquipaje: %d \n\n", aux.despacheEquipaje);

    return aux;
}
