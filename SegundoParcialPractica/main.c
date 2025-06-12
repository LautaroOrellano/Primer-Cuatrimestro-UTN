///Lautaro Orellano comision 14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idPiloto;
    char apellido[30];
    char equipo[30];
    float estatura;
    float peso;
    int tieneAuto; //1 o 0
} stPiloto;

typedef struct
{
    int idAuto;
    int idPiloto;
    char equipo[30];
    int velocidadMaxima;
    double tiempo0a100;
    float peso;
} stAuto;

//---------------------------------PROTOTIPADO-----------------------------------
void mostrarUnAuto(stAuto aux);
int dimensionArregloAutos(char archivoAutos[]);
stAuto* cargarArregloAutos(char archivoAutos[], int dimensionMain);
void mostrarUnPiloto(stPiloto aux);
stPiloto* cargarArregloPilotos(char archivoPilotos[], int* validos);
int menorTiempo0a100(stAuto* autoSinPilotoMain, int dimensionMain);
stAuto asignarPiloto(stPiloto* pilotoSinAutoMain, int validosMain, stAuto* autoSinPilotoMain, int dimensionMain, int idAutoMenorTiempo);
void mostrarArregloAuto(stAuto* arreglo, int dimensionMain );
void modificarAutoEnArchivo(char archivoAutos[], stAuto autoModificado);
void mostrarArchivoAuto(char archivoAutos[]);
float calcularVelocidadPromedio(stAuto* autoSinPilotoMain, int dimensionMain, int sumatoria, int i);

//-------------------------------------------------------------------------------


int main()
{
    char archivoAutos[] = "autos.bin";
    char archivoPilotos[] = "pilotos.bin";

    printf("-------Archivo auto original----------- \n");

    mostrarArchivoAuto(archivoAutos);

    system("pause");
    system("cls");

    ///Ejercicio1

    int dimensionMain = dimensionArregloAutos(archivoAutos);

    printf("La dimension del arreglo autos es de: %d", dimensionMain);
    printf("\n");

    system("pause");
    system("cls");

    stAuto* autoSinPilotoMain = cargarArregloAutos(archivoAutos, dimensionMain);

    for(int i=0; i < dimensionMain; i++){

        mostrarUnAuto(autoSinPilotoMain[i]);
    }

    system("pause");
    system("cls");

    ///Ejercicio2

    int validosMain = 0;

    stPiloto* pilotoSinAutoMain = cargarArregloPilotos(archivoPilotos, &validosMain);

    for(int i=0; i < dimensionMain; i++){

        mostrarUnPiloto(pilotoSinAutoMain[i]);
    }

    system("pause");
    system("cls");

    ///Ejercicio3

    int idAutoMenorTiempo = menorTiempo0a100(autoSinPilotoMain, dimensionMain);

    printf("El id del auto con menor tiempo es: %d", idAutoMenorTiempo);
    printf("\n");

    system("pause");
    system("cls");

    ///Ejercicio4

    stAuto autoModificado = asignarPiloto( pilotoSinAutoMain, validosMain, autoSinPilotoMain, dimensionMain, idAutoMenorTiempo);

    printf("Autos Sin Pilotos modificados: \n\n");
    mostrarArregloAuto(autoSinPilotoMain, dimensionMain );

    system("pause");
    system("cls");

    ///Ejercicio5

    modificarAutoEnArchivo(archivoAutos, autoModificado);

    printf("-------Archivo auto modificado----------- \n");

    mostrarArchivoAuto(archivoAutos);

    system("pause");
    system("cls");

    ///Ejercicio6
    int i = 0;
    int sumatoria = 0;

    float promedioVelocidades = calcularVelocidadPromedio(autoSinPilotoMain, dimensionMain, sumatoria, i);

    printf("La velocidad promedio es: %.2f", promedioVelocidades);
    printf("\n");

    system("pause");
    system("cls");


    return 0;
}

void mostrarArregloAuto(stAuto* arreglo, int dimensionMain ){

    for(int i=0; i<dimensionMain; i++){

        mostrarUnAuto(arreglo[i]);
    }

}
//1. Pasar a un arreglo dinámico de tamaño justo todos los autos sin piloto asignado
//(idPiloto==-1) y mostrarlo por pantalla. Modularizar el cálculo de la dimensión.
//Auto* cargarArregloAutos(char nombreArchivo[], int dimension)

void mostrarUnAuto(stAuto aux){

    printf("ID AUTO: %d \n", aux.idAuto);
    printf("ID PILOTO: %d \n", aux.idPiloto);
    printf("EQUIPO: %s \n", aux.equipo);
    printf("VELOCIDAD MAXIMA: %d \n", aux.velocidadMaxima);
    printf("TIEMPO 0 A 100: %lf \n", aux.tiempo0a100);
    printf("PESO: %2.f \n", aux.peso);
    printf("--------------------------\n\n");

}

int dimensionArregloAutos(char archivoAutos[]){

    FILE* arch = fopen(archivoAutos, "rb");
    stAuto aux;
    int cont = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0){

            if(aux.idPiloto == -1){

                cont++;
            }
        }

        fclose(arch);
    } else {
        printf("Error \n");
    }

    return cont;
}

stAuto* cargarArregloAutos(char archivoAutos[], int dimensionMain){

    FILE* arch = fopen(archivoAutos, "rb");
    stAuto* autosSinPilotos = (stAuto*) malloc (sizeof(stAuto)* dimensionMain);
    stAuto aux;
    int i = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0){

            if(aux.idPiloto == -1){

                autosSinPilotos[i] = aux;
                i++;
            }
        }

        fclose(arch);
    } else {
        printf("Error \n");
    }

    return autosSinPilotos;
}
//2. Pasar a un arreglo dinámico todos los pilotos sin auto asignado y mostrarlo por
//pantalla. El arreglo debe redimensionarse cuando sea necesario. De no poder
//resolver el ejercicio usando realloc, se podrá crear un arreglo de tamaño justo, pero
//el ejercicio tendrá la mitad del puntaje.
//Piloto* cargarArregloPilotos(char archivoPiloto[], int* validos){

void mostrarUnPiloto(stPiloto aux){

    printf("ID PILOTO: %d \n", aux.idPiloto);
    printf("APELLIDO: %s \n", aux.apellido);
    printf("EQUIPO: %s \n", aux.equipo);
    printf("ESTATURA: %2.f \n", aux.estatura);
    printf("PESO: %2.f \n", aux.peso);
    printf("TIENE AUTO: %d \n", aux.tieneAuto);
    printf("--------------------------\n\n");

}

stPiloto* cargarArregloPilotos(char archivoPilotos[], int* validos){

    FILE* arch = fopen(archivoPilotos,"rb");
    stPiloto* pilotoSinAuto = (stPiloto*) malloc(sizeof(stPiloto));
    stPiloto aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stPiloto), 1, arch) > 0){

            if(aux.tieneAuto == 0){

                pilotoSinAuto[*validos] = aux;
                (*validos)++;
                pilotoSinAuto = (stPiloto*) realloc(pilotoSinAuto, sizeof(stPiloto)*((*validos)+1));
            }
        }

        fclose(arch);
    } else {
        printf("Error \n");
    }

    return pilotoSinAuto;
}
//3. Buscar el ID del auto con menor tiempo 0 a 100 en el arreglo y retornarlo.
//int menorTiempo0a100(Auto* arreglo, int dimension)

int menorTiempo0a100(stAuto* autoSinPilotoMain, int dimensionMain){

    int menorTiempo = autoSinPilotoMain[0].tiempo0a100;
    int idDelAuto = autoSinPilotoMain[0].idAuto;

    for(int i=1; i<dimensionMain; i++){

        if(menorTiempo > autoSinPilotoMain[i].tiempo0a100){

            menorTiempo = autoSinPilotoMain[i].tiempo0a100;
            idDelAuto = autoSinPilotoMain[i].idAuto;
        }
    }

    return idDelAuto;
}

//4. Asignar un piloto al auto obtenido en el ejercicio anterior. Tanto el auto como el
//piloto deben pertenecer al mismo equipo.
//Auto asignarPiloto(Piloto* arrPilotos, int dimPilotos, Auto* arrAutos, int dimAutos, int
//idAutoBuscado)

stAuto asignarPiloto(stPiloto* pilotoSinAutoMain, int validosMain, stAuto* autoSinPilotoMain, int dimensionMain, int idAutoMenorTiempo){

    int posAuto = 0;
    int posPiloto = 0;
    int pilotoTieneAuto = -1;

    while( posAuto < dimensionMain && autoSinPilotoMain[posAuto].idAuto != idAutoMenorTiempo){

        posAuto++;
    }

    while( posPiloto < validosMain && pilotoTieneAuto == -1 ){

        if(strcmp(autoSinPilotoMain[posAuto].equipo, pilotoSinAutoMain[posPiloto].equipo) == 0){

            pilotoTieneAuto = 1;

        } else {

            posPiloto ++;
        }
    }

    autoSinPilotoMain[posAuto].idPiloto = pilotoSinAutoMain[posPiloto].idPiloto;
    pilotoSinAutoMain[posPiloto].tieneAuto = pilotoTieneAuto;

    return autoSinPilotoMain[posAuto];

}
//5. Modificar el registro del auto del punto anterior en el archivo.
//void modificarAutoEnArchivo(char nombreArchivo[], Auto autoModificado)

void modificarAutoEnArchivo(char archivoAutos[], stAuto autoModificado){

    FILE* arch = fopen(archivoAutos, "r+b");
    stAuto aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0){

            if(aux.idAuto == autoModificado.idAuto){

                fseek(arch, -1 *sizeof(stAuto) , SEEK_CUR);

                fwrite(&autoModificado, sizeof(stAuto), 1, arch);
                break;
            }
        }

        fclose(arch);
    } else {
        printf("ERROR. \n");
    }

}

void mostrarArchivoAuto(char archivoAutos[]){

    FILE* arch = fopen(archivoAutos, "rb");
    stAuto aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0){

            mostrarUnAuto(aux);
        }

        fclose(arch);
    } else {
        printf("ERROR. \n");
    }
}

//6. Hacer una función recursiva que calcule la velocidad promedio del arreglo de
//autos (campo velocidadMaxima).
//float calcularVelocidadPromedio(Auto* arreglo, int dimension, int sumatoria, int i)

float calcularVelocidadPromedio(stAuto* autoSinPilotoMain, int dimensionMain, int sumatoria, int i){

    if(i == dimensionMain){

        return(float)sumatoria/dimensionMain;
    } else {
        return calcularVelocidadPromedio(autoSinPilotoMain, dimensionMain, sumatoria + autoSinPilotoMain[i].velocidadMaxima, i+1);
    }
}

//7. Pasar los autos del arreglo a dos archivos según el resultado de la función
//anterior (velocidad mayor al promedio y menor al promedio).
//void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char
//archivoDebajoPromedio[], Auto* arreglo, int dimension, float promedio)

//8. Invocar funciones en main() para demostrar el funcionamiento del programa.
//Crear las variables y constantes que se consideren necesarias
