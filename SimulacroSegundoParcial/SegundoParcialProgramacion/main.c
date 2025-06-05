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

//----------------------------Prototipado----------------------------------------
int contarRegistrosArchivo(char nombreArchivo[], size_t(registro));
stPasajero* cargarArregloPasajeros(char archivoPasajeros[], int cantRegistroPasajeros);
stPasajero mostrarPasajero(stPasajero aux);
void pasajerosPorViaje(stPasajero* arregloPasajeros, int cantRegistroPasajeros, int nViaje);
stViaje* cargarArregloViajes(char archivoViajes[], int cantRegistroViajes, stPasajero *pasajeros, int cantRegistroPasajeros);
void listarViajesDisponibles(stViaje *viajes, int cantRegistroViajes, int i);
void escribirArchivosViajes(char archivoViajes[], stViaje *viajes, int cantRegistroViajes);
void leerArchivoViajesActualizado(char archivoViajes[]);


//--------------------------------------------------------------------------------

int main()
{
    char archivoPasajeros[] = "Pasajeros.bin";
    char archivoViajes[] = "Viajes.bin";
    int cantRegistroPasajeros = 0;
    int cantRegistroViajes = 0;
    stPasajero *pasajeros = NULL;
    stViaje *viajes = NULL;
    int i = 0;
    int nViaje = 0;

    ///Ejercicio1
    cantRegistroPasajeros = contarRegistrosArchivo(archivoPasajeros, sizeof(stPasajero));
    printf("Cantidad de registro Pasajeros: %d \n", cantRegistroPasajeros);

    cantRegistroViajes = contarRegistrosArchivo(archivoViajes, sizeof(stViaje));
    printf("Cantidad de registro Viajes: %d \n", cantRegistroViajes);

    system("pause");
    system("cls");

    ///Ejercicio2
    pasajeros = cargarArregloPasajeros(archivoPasajeros, cantRegistroPasajeros);

    system("pause");
    system("cls");

    ///Ejercicio3
    printf("Que id de viaje desea buscar?: ");
    fflush(stdin);
    scanf("%d", &nViaje);
    while(getchar() != '\n');

    pasajerosPorViaje(pasajeros, cantRegistroPasajeros, nViaje);

    system("pause");
    system("cls");

    ///Ejercicio4

    printf("Cantidad de viajes totales: \n\n");
    viajes = cargarArregloViajes(archivoViajes, cantRegistroViajes, pasajeros, cantRegistroPasajeros);

    system("pause");
    system("cls");

    ///Ejercicio5

    listarViajesDisponibles(viajes, cantRegistroViajes, i);

    system("pause");
    system("cls");

    ///Ejercicio6

    printf("Archivo de Viajes actualizado correctamente!! \n\n");
    escribirArchivosViajes(archivoViajes, viajes, cantRegistroViajes);
    leerArchivoViajesActualizado(archivoViajes);


    free(pasajeros);


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
        printf("No se pudo leer el archivo \n");
    }
    return cantidadRegistros;
}

///Ejercicio2
stPasajero* cargarArregloPasajeros(char archivoPasajeros[], int cantRegistroPasajeros){

    FILE *arch = fopen(archivoPasajeros, "rb");
    stPasajero* arregloPasajeros = NULL;
    stPasajero aux;
    int i = 0;

    if(arch != NULL){

        arregloPasajeros = (stPasajero*) malloc(sizeof(stPasajero)*cantRegistroPasajeros);
        while(fread(&aux, sizeof(stPasajero), 1, arch) > 0 && i<cantRegistroPasajeros){

            arregloPasajeros[i] = aux;
            i++;
        }

        fclose(arch);

        for(int i = 0; i < cantRegistroPasajeros; i++){

            mostrarPasajero(arregloPasajeros[i]);
        }


    } else {
        printf("El archivo no se pudo abrir. \n");
    }

    return arregloPasajeros;
}

stPasajero mostrarPasajero(stPasajero aux){

    printf("Id: %d \n", aux.idPasajero);
    printf("Id viaje %d \n", aux.idViaje);
    printf("Nombre: %s \n", aux.nombre);
    printf("Dni: %s \n", aux.dni);
    printf("DespacheEquipaje: %d \n\n", aux.despacheEquipaje);

    return aux;
}

stViaje mostrarViaje(stViaje aux){

    printf("Id: %d \n", aux.idViaje);
    printf("Origen: %s \n", aux.origen);
    printf("Destino: %s \n", aux.destino);
    printf("Cantidad de pasajeros: %d \n", aux.cantidadPasajeros);

    return aux;
}

///Ejercicio3
void pasajerosPorViaje(stPasajero* arregloPasajeros, int cantRegistroPasajeros, int nViaje){

    int cont = 0;

    for(int i=0; i<cantRegistroPasajeros; i++){

        if(arregloPasajeros[i].idViaje == nViaje){
            cont++;
        }
    }

    printf("La cantidad de pasajeros para el viaje %d es de %d \n\n", nViaje, cont);
}

///Ejercicio4
stViaje* cargarArregloViajes(char archivoViajes[], int cantRegistroViajes, stPasajero *pasajeros, int cantRegistroPasajeros){

    FILE *arch = fopen(archivoViajes, "rb");
    stViaje aux;
    int i = 0;
    stViaje* arregloViajes = NULL;

    if(arch != NULL){

        arregloViajes = (stViaje*) malloc(sizeof(stViaje)* cantRegistroViajes);
        while(fread(&aux, sizeof(stViaje), 1, arch) > 0 && i < cantRegistroViajes){

            arregloViajes[i] = aux;
            arregloViajes[i].cantidadPasajeros = 0;
            i++;
        }

        for(i=0; i<cantRegistroPasajeros; i++){
            for(int j = 0; j <cantRegistroViajes; j++){

                if(pasajeros[i].idViaje == arregloViajes[j].idViaje){
                    arregloViajes[j].cantidadPasajeros++;
                }
            }
        }
        fclose(arch);

        for(i = 0; i < cantRegistroViajes; i++){

            mostrarViaje(arregloViajes[i]);
        }

    } else {
        printf("El archivo no se pudo abrir. \n");
    }

    return arregloViajes;

}

///Ejercicio5
void listarViajesDisponibles(stViaje *viajes, int cantRegistroViajes, int i){


    if( i == cantRegistroViajes){

        return;
    }

    if(viajes[i].cantidadPasajeros < CAPACIDAD){

        printf("Viajes con lugar disponibles: \n\n ");
        mostrarViaje(viajes[i]);
    }

    listarViajesDisponibles(viajes, cantRegistroViajes, i + 1);

}

///Ejercicio6
void escribirArchivosViajes(char archivoViajes[], stViaje *viajes, int cantRegistroViajes){

    FILE* arch = fopen(archivoViajes, "wb");


    if(arch != NULL){

        for(int i=0; i < cantRegistroViajes; i++){

            fwrite(&viajes[i], sizeof(stViaje), 1, arch);
        }

        fclose(arch);

    } else {
        printf("El archivo no se pudo leer correctamente. \n");
    }
}

void leerArchivoViajesActualizado(char archivoViajes[]){

    FILE* arch = fopen(archivoViajes, "rb");
    stViaje aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stViaje), 1, arch) > 0){

           mostrarViaje(aux);
        }

        fclose(arch);

    } else {
        printf("El archivo no se pudo leer correctamente. \n");
    }
}

///Ejercicio7
void cargarArchivoPorOrigen(stViaje *viajes, int cantRegistroViajes){

    for(int i=0; i<cantRegistroViajes; i++){
        char nombreArchivo[30];

        strcpy(nombreArchivo, viajes[i].origen);
        strcat(nombreArchivo, ".bin");
        cargarViajeEnArchivo(nombreArchivo, viajes[i]);

    }

}

void cargarViajeEnArchivo(char archivo[], stViaje viaje){

    FILE* arch = fopen(archivo, "ab");

    if(arch != NULL){

        fwrite(&viaje[i], sizeof(stViaje), 1, arch);

        fclose(arch);

    } else {
        printf("El archivo no se pudo leer correctamente. \n");
    }
}
