#include <stdio.h>
#include <stdlib.h>

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


//--------------------------------------------------------------------------------

int main()
{
    int opcion = 1;
    int opcionMenu = 0;
    char archivoPasajeros[] = "Pasajeros.bin";
    char archivoViajes[] = "Viajes.bin";
    int cantRegistroPasajeros = 0;
    int cantRegistroViajes = 0;
    stPasajero *pasajeros = NULL;
    int nViaje = 0;



    while(opcion == 1){

            printf("------------Menu--------------------------\n");
            printf("1-Cantidad Registros Pasajeros\n");
            printf("2-Cantidad Registros Viajes\n");
            printf("3-Mostrar Arreglo Pasajeros\n");
            printf("4-Buscar total de pasajeros por idViaje\n");
            printf("------------Menu--------------------------\n\n");
            printf("Elija una opcion para ingresar al menu: ");
            scanf("%d", &opcionMenu);
            while(getchar() != '\n');

        switch(opcionMenu){

            case 1:
                    cantRegistroPasajeros = contarRegistrosArchivo(archivoPasajeros, sizeof(stPasajero));
                    printf("Cantidad de registro Pasajeros: %d \n", cantRegistroPasajeros);
                    break;

            case 2:
                    cantRegistroViajes = contarRegistrosArchivo(archivoViajes, sizeof(stViaje));
                    printf("Cantidad de registro Viajes: %d \n", cantRegistroViajes);
                    break;

            case 3:
                    cantRegistroPasajeros = contarRegistrosArchivo(archivoPasajeros, sizeof(stPasajero));
                    pasajeros = cargarArregloPasajeros(archivoPasajeros, cantRegistroPasajeros);

                    for(int i = 0; i < cantRegistroPasajeros; i++){

                        mostrarPasajero(pasajeros[i]);
                    }
                    break;

            case 4:
                    printf("Que id de viaje desea buscar?: ");
                    fflush(stdin);
                    scanf("%d", &nViaje);
                    while(getchar() != '\n');

                    pasajerosPorViaje(pasajeros, cantRegistroPasajeros, nViaje);
                    break;

            case 5:

            default:
                    printf("Opcion incorrecta ingrese nuevamente una opcion.\n");


        }
        printf("Desea continuar en el menu (1-si | 0-no)\n");
        scanf("%d", &opcion);
        while(getchar() != '\n');
    }

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


    } else {
        printf("El archivo no se pudo abrir. \n");
    }

    return arregloPasajeros;
}

///Ejercicio3
stPasajero mostrarPasajero(stPasajero aux){

    printf("Id: %d \n", aux.idPasajero);
    printf("Id viaje %d \n", aux.idViaje);
    printf("Nombre: %s \n", aux.nombre);
    printf("Dni: %s \n", aux.dni);
    printf("DespacheEquipaje: %d \n\n", aux.despacheEquipaje);

    return aux;
}

///Ejercicio4
void pasajerosPorViaje(stPasajero* arregloPasajeros, int cantRegistroPasajeros, int nViaje){

    int cont = 0;

    for(int i=0; i<cantRegistroPasajeros; i++){

        if(arregloPasajeros[i].idViaje == nViaje){
            cont++;
        }
    }

    printf("La cantidad de pasajeros para el viaje %d es de %d", nViaje, cont);

}
