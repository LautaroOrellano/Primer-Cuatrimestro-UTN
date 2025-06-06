#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDAD 7

typedef struct
{
    int idViaje;
    char origen[50];
    char destino[50];
    int cantidadPasajeros;
}stViaje;

typedef struct
{
    int idPasajero;
    int idViaje;
    char nombre[50];
    char dni[10];
    int despacheEquipaje;
}stPasajero;

//------------------------Prototipado----------------------------------------
int contarRegistroArchivo(char archivo[], size_t(tamRegistro));
stPasajero* cargarArregloPasajeros(char archivoPasajero[], int cantidadRegistroPasajeros);
void mostrarPasajero(stPasajero aux);
void contarPasajerosPorViaje(stPasajero *arregloPasajerosMain, int cantidadRegistroPasajeros, int idViajeDeterminado);
void mostrarViaje(stViaje aux);
stViaje* cargarArregloViajes(char archivoViajes[], int cantidadRegistroViajes, stPasajero *arrgloPasajeroMain, int cantidadRegistroPasajeros);
int listarViajesDisponibles(stViaje *arregloViajesMain, int cantidadRegistroViajes, int i);
void escribirArchivoViajes(char archivoViajes[], stViaje *arregloViajesMain, int cantidadRegistroViajes);
void mostrarArchivoViajeActualizado(char archivoViajes[]);
//--------------------------------------------------------------------------
int main()
{
    char archivoPasajero[] = "pasajeros.bin";
    char archivoViajes[] = "viajes.bin";
    int cantidadRegistroPasajeros = 0;
    int cantidadRegistroViajes = 0;
    stPasajero *arregloPasajerosMain = NULL;
    int idViajeDeterminado = 0;
    stViaje *arregloViajesMain = NULL;


    ///Ejercicio1

    cantidadRegistroPasajeros = contarRegistroArchivo(archivoPasajero, sizeof(stPasajero));
    printf("La cantidad de registros que contiene el archivo pasajeros es de: %d \n\n", cantidadRegistroPasajeros);

    cantidadRegistroViajes = contarRegistroArchivo(archivoViajes, sizeof(stViaje));
    printf("La cantidad de registros que contiene el archivo viajes es de: %d \n\n", cantidadRegistroViajes);

    system("pause");
    system("cls");

    ///Ejercicio2

    printf("--------------Arreglo pasajeros: --------------\n\n");

    arregloPasajerosMain = cargarArregloPasajeros(archivoPasajero, cantidadRegistroPasajeros);

    system("pause");
    system("cls");

    ///Ejercicio3

    printf("Que id de viaje desesa buscar para saber la cantidad de pasajeros: ");
    scanf("%d", &idViajeDeterminado);
    while(getchar() != '\n');

    contarPasajerosPorViaje(arregloPasajerosMain, cantidadRegistroPasajeros, idViajeDeterminado);

    system("pause");
    system("cls");

    ///Ejercicio4

    printf("-----------------Arreglo viajes: -----------------\n\n");

    arregloViajesMain = cargarArregloViajes(archivoViajes, cantidadRegistroViajes, arregloPasajerosMain, cantidadRegistroPasajeros);

    system("pause");
    system("cls");

    ///Ejercicio5

    int i = 0;
    listarViajesDisponibles(arregloViajesMain, cantidadRegistroViajes, i);

    system("pause");
    system("cls");

    ///Ejercicio6

     printf("-----------------Archivo viaje modificado: -----------------\n\n");
    escribirArchivoViajes(archivoViajes, arregloViajesMain, cantidadRegistroViajes);
    mostrarArchivoViajeActualizado(archivoViajes);

    system("pause");
    system("cls");

    ///Ejercicio7




    free(arregloPasajerosMain);
    return 0;
}

///Ejercicio1

int contarRegistroArchivo(char archivo[], size_t(tamRegistro)){

    FILE* arch = fopen(archivo, "rb");
    int cantidadReg = 0;

    if(arch != NULL){

        fseek(arch, 0,SEEK_END);
        int validos = ftell(arch);

        cantidadReg = validos / tamRegistro;

        fclose(arch);

    } else {
        printf("El archivo no se pudo abrir correctamente. \n");
    }

    return cantidadReg;
}

///Ejercicio2

void mostrarPasajero(stPasajero aux){

    printf("ID pasajero: %d \n", aux.idPasajero);
    printf("ID viaje: %d \n", aux.idViaje);
    printf("Nombre: %s \n", aux.nombre);
    printf("DNI: %s \n", aux.dni);
    printf("Despache de equipaje: %d \n\n", aux.despacheEquipaje);

}

stPasajero* cargarArregloPasajeros(char archivoPasajero[], int cantidadRegistroPasajeros){

    FILE *arch = fopen(archivoPasajero, "rb");
    stPasajero aux;
    stPasajero *arregloPasajero = NULL;
    int i = 0;

    if(arch != NULL){

        arregloPasajero = (stPasajero*) malloc(sizeof(stPasajero) * cantidadRegistroPasajeros);

        while(fread(&aux, sizeof(stPasajero), 1, arch) > 0 && i < cantidadRegistroPasajeros){

            arregloPasajero[i] = aux;
            i++;

        }

        for(i=0; i<cantidadRegistroPasajeros; i++){

            mostrarPasajero(arregloPasajero[i]);
        }

        fclose(arch);
    } else {
        printf("El arhivo no se pudo abrir. \n");
    }

    return arregloPasajero;
}

///Ejercicio3

void contarPasajerosPorViaje(stPasajero *arregloPasajerosMain, int cantidadRegistroPasajeros, int idViajeDeterminado){

    int cont = 0;

    for(int i=0; i<cantidadRegistroPasajeros; i++){

        if(arregloPasajerosMain[i].idViaje == idViajeDeterminado){

            cont ++;
        }
    }

    printf("La cantidad de pasajeros de ese viaje es: %d \n", cont);
}

///Ejercicio4

void mostrarViaje(stViaje aux){

    printf("ID viaje: %d \n", aux.idViaje);
    printf("Origen: %s \n", aux.origen);
    printf("Destino: %s \n", aux.destino);
    printf("Cantidad de pasajeros: %d \n\n", aux.cantidadPasajeros);

}

stViaje* cargarArregloViajes(char archivoViajes[], int cantidadRegistroViajes, stPasajero *arregloPasajerosMain, int cantidadRegistroPasajeros){

    FILE *arch = fopen(archivoViajes, "rb");
    stViaje *arregloViajes = NULL;
    stViaje aux;
    int i = 0;

    if(arch != NULL){

        arregloViajes = (stViaje*) malloc(sizeof(stViaje) * cantidadRegistroViajes);

        while(fread(&aux, sizeof(stViaje), 1, arch) > 0 && i < cantidadRegistroViajes){

            arregloViajes[i] = aux;
            arregloViajes[i].cantidadPasajeros = 0;
            i++;

        }

        for(i=0; i<cantidadRegistroViajes; i++){

            for(int j=0; j<cantidadRegistroPasajeros; j++){

                if(arregloViajes[i].idViaje == arregloPasajerosMain[j].idViaje){

                    arregloViajes[i].cantidadPasajeros++;
                }
            }
        }

        for(i=0; i<cantidadRegistroViajes; i++){

            mostrarViaje(arregloViajes[i]);
        }


        fclose(arch);

    } else {
        printf("No se pudo leer el archivo. \n");
    }

    return arregloViajes;
}

///Ejercicio5

int listarViajesDisponibles(stViaje *arregloViajesMain, int cantidadRegistroViajes, int i){

    if( i == cantidadRegistroViajes){
        return -1;
    }

    if(arregloViajesMain[i].cantidadPasajeros < CAPACIDAD){

        printf("---------------Viaje con disponibilidad: --------------\n\n");
        mostrarViaje(arregloViajesMain[i]);
    }

    return listarViajesDisponibles(arregloViajesMain, cantidadRegistroViajes, i + 1);
}

///Ejercicio6

void escribirArchivoViajes(char archivoViajes[], stViaje *arregloViajesMain, int cantidadRegistroViajes){

    FILE *arch = fopen(archivoViajes, "wb");
    stViaje aux;

    if(arch != NULL){

        for(int i=0; i<cantidadRegistroViajes; i++){

            fwrite(&arregloViajesMain[i], sizeof(stViaje), 1, arch);
        }

        fclose(arch);
    } else {
        printf("El archivo no se pudo leer correctamente. \n");
    }
}

void mostrarArchivoViajeActualizado(char archivoViajes[]){

    FILE *arch = fopen(archivoViajes, "rb");
    stViaje aux;

    while(fread(&aux, sizeof(stViaje), 1, arch) > 0){

        mostrarViaje(aux);
    }
}

///Ejercicio7

void cargarArchivosPorOrigen(stViaje *arregloViajesMain, int cantidadRegistroViajes){

     char nombreArchivo[100];

    for (int i = 0; i < cantidadRegistroViajes; i++) {
        // Armar el nombre del archivo con el origen del viaje
        sprintf(nombreArchivo, "%s.bin", arregloViajesMain[i].origen);

        // Abrir el archivo correspondiente en modo append binario
        FILE *arch = fopen(nombreArchivo, "ab");

        if (arch != NULL) {
            // Escribir el viaje en el archivo de su ciudad de origen
            fwrite(&arregloViajesMain[i], sizeof(stViaje), 1, arch);
            fclose(arch);
        } else {
            printf("No se pudo abrir el archivo: %s\n", nombreArchivo);
        }
    }
}
