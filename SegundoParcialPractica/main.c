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
int dimensionAutoSinPiloto(char archivoAutos[]);
stAuto* cargarArregloAutos(char archivoAutos[], int dimensionMain);
void mostrarUnPiloto(stPiloto aux);
stPiloto* cargarArregloPilotos(char archivoPilotos[], int* validos);
int menorTiempo0a100(stAuto* autoSinPilotoMain, int dimensionMain);
stAuto asignarPiloto(stPiloto* pilotoSinAutoMain, int validos, stAuto* autoSinPilotoMain, int dimensionMain, int autoMenorTiempo);
void modificarAutoEnArchivo(char archivoAutos[], stAuto autoModificado);
void leerArchivoAuto(char archivoAutos[]);
float calcularVelocidadPromedio(stAuto* autoSinPilotoMain, int dimensionMain, int sumatoria, int i);
void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char archivoDebajoPromedio[], stAuto* autoSinPilotoMain, int dimensionMain, float promedioVelocidad);
//-------------------------------------------------------------------------------


int main()
{
    char archivoAutos[] = "autos.bin";
    char archivoPilotos[] = "pilotos.bin";

    ///Ejercicio1

    int dimensionMain = dimensionAutoSinPiloto( archivoAutos);

    printf("La dimension del arreglo autos sin pilotos es: %d \n", dimensionMain);

    stAuto* autoSinPilotoMain = cargarArregloAutos(archivoAutos, dimensionMain);
    printf("Arreglo pilotos sin autos: \n");

    for(int i=0; i<dimensionMain; i++){

        mostrarUnAuto(autoSinPilotoMain[i]);
    }

    system("pause");
    system("cls");

    ///Ejercicio2
    int validos = 0;

    stPiloto* pilotoSinAutoMain = cargarArregloPilotos(archivoPilotos, &validos);

    printf("Arreglo pilotos sin autos: \n");
    for(int i=0; i<dimensionMain; i++){

        mostrarUnPiloto(pilotoSinAutoMain[i]);
    }

    system("pause");
    system("cls");

    ///Ejercicio3

    int autoMenorTiempo = menorTiempo0a100(autoSinPilotoMain, dimensionMain);

    printf("El id del auto que hace menor tiempo es: %d \n", autoMenorTiempo);

    system("pause");
    system("cls");

    ///Ejercicio4

    stAuto autoModificado = asignarPiloto(pilotoSinAutoMain, validos, autoSinPilotoMain, dimensionMain, autoMenorTiempo);

    printf("Vector modificado con el nuevo id de piloto en el auto: \n\n");
    for(int i=0; i<dimensionMain; i++){

        mostrarUnAuto(autoSinPilotoMain[i]);
    }
    printf("Vector modificado asignandole auto al piloto: \n\n");
    for(int i=0; i<dimensionMain; i++){

        mostrarUnPiloto(pilotoSinAutoMain[i]);
    }

    system("pause");
    system("cls");

    ///Ejercicio5

    printf("Archivo antes de ser modificado: \n\n");
    leerArchivoAuto(archivoAutos);

    //modificarAutoEnArchivo(archivoAutos, autoModificado);

    printf("Archivo despues de ser modificado: \n\n");
    leerArchivoAuto(archivoAutos);

    system("pause");
    system("cls");

    ///Ejercicio6

    int sumatoria = 0;
    int i = 0;

    float promedioVelocidad = calcularVelocidadPromedio(autoSinPilotoMain, dimensionMain, sumatoria, i);

    printf("La velocidad promedio de los autos sin pilotos es: %.2f \n", promedioVelocidad);

    system("pause");
    system("cls");

    ///Ejercicio7

    char archivoSobrePromedio[] = "sobrePromedio.bin";
    char archivoDebajoPromedio[] = "debajoPromedio.bin";

    escribirArchivosPorVelocidad(archivoSobrePromedio, archivoDebajoPromedio, autoSinPilotoMain, dimensionMain, promedioVelocidad);

    system("pause");
    system("cls");

    free(autoSinPilotoMain);
    free(pilotoSinAutoMain);

    return 0;
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
    printf("PESO: %.2f \n", aux.peso);
    printf("---------------------------\n\n");
}

int dimensionAutoSinPiloto(char archivoAutos[]){

    FILE* arch = fopen(archivoAutos, "rb");
    stAuto aux;
    int cont = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0 ){

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
    stAuto* autosSinPiloto = (stAuto*) malloc(sizeof(autosSinPiloto)*dimensionMain);
    stAuto aux;
    int i = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0 ){

            if(aux.idPiloto == -1){

                autosSinPiloto[i] = aux;
                i++;
            }
        }

        fclose(arch);
    } else {
        printf("Error \n");
    }

    return autosSinPiloto;
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
    printf("ESTATURA 0 A 100: %.2f \n", aux.estatura);
    printf("PESO: %.2f \n", aux.peso);
    printf("TIENE AUTO: %d \n", aux.tieneAuto);
    printf("---------------------------\n\n");
}

stPiloto* cargarArregloPilotos(char archivoPilotos[], int* validos){

    FILE* arch = fopen(archivoPilotos, "rb");
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
        printf("ERROR. \n");
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

stAuto asignarPiloto(stPiloto* pilotoSinAutoMain, int validos, stAuto* autoSinPilotoMain, int dimensionMain, int autoMenorTiempo){

    int posAuto = 0;
    int posPiloto = 0;
    int autoEncontrado = 0;
    int idDelPiloto = 0;

    while(posAuto < dimensionMain && autoSinPilotoMain[posAuto].idAuto != autoMenorTiempo){

        posAuto++;
    }

    while(posPiloto < validos && autoEncontrado == 0){

        if(strcmp(pilotoSinAutoMain[posPiloto].equipo, autoSinPilotoMain[posAuto].equipo) == 0){

            idDelPiloto = pilotoSinAutoMain[posPiloto].idPiloto;
            autoEncontrado = 1;

        } else {
            posPiloto++;
        }
    }

    autoSinPilotoMain[posAuto].idPiloto = idDelPiloto;
    pilotoSinAutoMain[posPiloto].tieneAuto = 1;

    return autoSinPilotoMain[posAuto];
}


//5. Modificar el registro del auto del punto anterior en el archivo.
//void modificarAutoEnArchivo(char nombreArchivo[], Auto autoModificado)

void modificarAutoEnArchivo(char archivoAutos[], stAuto autoModificado){

    FILE* arch = fopen(archivoAutos, "r+b");
    stAuto aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0){

            if(autoModificado.idAuto == aux.idAuto){

                fseek(arch, -1*sizeof(stAuto), SEEK_CUR);
                fwrite(&autoModificado, sizeof(stAuto), 1, arch);
                break;

            }
        }

        fclose(arch);
    } else {
        printf("Error al abrir el archivo. \n");
    }
}

void leerArchivoAuto(char archivoAutos[]){

    FILE* arch = fopen(archivoAutos, "rb");
    stAuto aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0){

            mostrarUnAuto(aux);
        }

        fclose(arch);
    } else {
        printf("Error al abrir el archivo. \n");
    }
}

//6. Hacer una función recursiva que calcule la velocidad promedio del arreglo de
//autos (campo velocidadMaxima).
//float calcularVelocidadPromedio(Auto* arreglo, int dimension, int sumatoria, int i)

float calcularVelocidadPromedio(stAuto* autoSinPilotoMain, int dimensionMain, int sumatoria, int i){

    if(i == dimensionMain){

        return (float)sumatoria/dimensionMain;
    } else {

         return calcularVelocidadPromedio(autoSinPilotoMain, dimensionMain, sumatoria + autoSinPilotoMain[i].velocidadMaxima , i+1);

    }
}

//7. Pasar los autos del arreglo a dos archivos según el resultado de la función
//anterior (velocidad mayor al promedio y menor al promedio).
//void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char
//archivoDebajoPromedio[], Auto* arreglo, int dimension, float promedio)

void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char archivoDebajoPromedio[], stAuto* autoSinPilotoMain, int dimensionMain, float promedioVelocidad){

    FILE* archSobre = fopen(archivoSobrePromedio, "ab");
    FILE* archDebajo = fopen(archivoDebajoPromedio, "ab");
    stAuto aux;

    if(archSobre != NULL && archDebajo != NULL){

        for(int i=0; i<dimensionMain; i++){

           if(autoSinPilotoMain[i].velocidadMaxima < promedioVelocidad){

                aux = autoSinPilotoMain[i];
                fwrite(&aux, sizeof(stAuto), 1, archDebajo);

           } else {

                aux = autoSinPilotoMain[i];
                fwrite(&aux, sizeof(stAuto), 1, archSobre);
           }
        }


       fclose(archSobre);
       fclose(archDebajo);
    } else {
        printf("El archivo no se pudo abrir.");
    }
}

//8. Invocar funciones en main() para demostrar el funcionamiento del programa.
//Crear las variables y constantes que se consideren necesarias
