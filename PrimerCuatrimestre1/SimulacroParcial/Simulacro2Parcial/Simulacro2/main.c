//Lautaro Orellano Lorenzo
#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include <string.h>
#include <time.h>

const int DIMENSION = 50;
const int FIL = 10;
const int COL = 10;
#define FIL1 3
#define COL2 30

//Prototipado
int cargarArreglo(int vectorEdades[DIMENSION], int edades);
void mostrarArreglo(int vectorEdades[DIMENSION], int validos);
int muestraInversa(int vector[], int validos2, int edadLimite);
void generaPila(int validos, int vectorEdades[DIMENSION], Pila *menores, Pila *mayores,int *cantMayores, int *cantMenores);
void generaMatrizRandom(int matrizRandom[FIL][COL]);
void imprimirMatrizRandom(int matrizRamdom[FIL][COL]);
void cantidadPorEdad(int vectorEdades[DIMENSION], int matrizRandom[FIL][COL], int validos, int arreglo[20]);
void informaPorPal(char misPalabras[FIL1][COL2], char letra);

int main()
{
    int arreglo[20];
    int vectorEdades[DIMENSION];
    int vector[]={16, 18, 25, 28, 29};
    int matrizRandom[FIL][COL];
    int edades, validos;
    int edadLimite = 20;
    int edadesRecorridas;
    int validos2 = 5;
    int cantMenores;
    int cantMayores;
    char letra;
    char misPalabras[FIL1][COL2] = {"Lautaro", "Manda", "Obvio"};
    Pila menores, mayores;
    inicpila(&menores);
    inicpila(&mayores);


    //Ejercicio1
    //validos = cargarArreglo(vectorEdades, edades);
    //mostrarArreglo(vectorEdades, validos);

    //Ejercicio2
    //edadesRecorridas = muestraInversa(vector, validos2, edadLimite);
    //printf("Las cantidad de edades hasta encontrar la edad correcta fue de: %d\n", edadesRecorridas);

    //Ejercicio3
    //generaPila(validos, vectorEdades, &menores, &mayores, &cantMayores, &cantMenores);
    //mostrar(&menores);
    //mostrar(&mayores);
    //printf("Los menores son: %d y los mayores son: %d", cantMenores, cantMayores);

    //Ejercicio4
    //generaMatrizRandom(matrizRandom);
    //imprimirMatrizRandom(matrizRandom);

    //Ejercicio5
    //cantidadPorEdad(vectorEdades, matrizRandom, validos, arreglo);

    //Ejercicio6
    printf("Dame la letra con la que quieres probar\n");
    fflush(stdin);
    scanf("%c", &letra);

    informaPorPal(misPalabras, letra);

    return 0;
}

//Inciso1
 int cargarArreglo(int vectorEdades[DIMENSION], int edades){

        int i = 0;
        int validos;
        char opcion = 's';


        while((opcion == 's') && (i < DIMENSION)){

                printf("Por favor dame una edad para cargar al vector \n");
                scanf("%d", &edades);
                fflush(stdin);

                if (edades <= 30 && edades >= 15){
                    vectorEdades[i] = edades;
                } else {
                    printf("La edad debe ser entre 15 y 30 años. \n");
                }

                printf("Desea seguir cargando el vector ? (s para continuar, n para cancelar): \n");
                scanf(" %c", &opcion);
                fflush(stdin);
                i++;
        }
        validos = i;
        return validos;
 }
 void mostrarArreglo(int vectorEdades[DIMENSION], int validos){

        for(int i=0; i<validos; i++){
            printf("lugar: %d, edad: %d \n", i+1, vectorEdades[i]);
        }
 }
//Inciso2
int muestraInversa(int vector[], int validos2, int edadLimite){

    int flag = 0;
    int i = 0;
    int acum = 0;

    for(i = validos2 -1; i >= 0; i--){

        if(flag == 0){

            printf("Edad: %d\n", vector[i]);
            acum = acum + 1;

            if(edadLimite < vector[i] && edadLimite > vector[i-1]){
            flag = 1;
            }
        }
    }

    return acum;
}
//Inciso3
void generaPila(int validos, int vectorEdades[DIMENSION], Pila *menores, Pila *mayores,int *cantMayores, int *cantMenores){

    int acum = 0;
    int acum2 = 0;

    for(int i=0; i<validos; i++){
        if (vectorEdades[i] >= 18){
            apilar(mayores, vectorEdades[i]);
            acum = acum + 1;
        } else {
            apilar(menores, vectorEdades[i]);
            acum2 = acum2 + 1;
        }

    }
    *cantMayores = acum;
    *cantMenores = acum2;
}
//Inciso4
void generaMatrizRandom(int matrizRandom[FIL][COL]){

    srand(time(NULL));
    for(int i=0; i<FIL; i++){
        for(int j=0; j<COL; j++){
                matrizRandom[i][j] = rand()%30;
            }
        }
}
void imprimirMatrizRandom(int matrizRandom[FIL][COL]){

    for(int i=0; i<FIL; i++){
        for(int j=0; j<COL; j++){
                printf("|%02d|", matrizRandom[i][j]);
            }
            printf("\n");
        }
}
//Ejercicio5
void cantidadPorEdad(int vectorEdades[DIMENSION], int matrizRandom[FIL][COL], int validos, int arreglo[20]){

    int acum;

    for(int k=0; k<validos; k++){
        acum = 0;
        for(int i=0; i<FIL; i++){
                for(int j=0; j<COL; j++){
                    if(matrizRandom[i][j] == vectorEdades[k]){
                        acum++;
                    }
                }
        }
        arreglo[k]= acum;
    }

    for(int i=0; i<validos; i++){
        printf("La edad buscada es: %d y aparecio %d\n", vectorEdades[i], arreglo[i]);
    }
}
//Ejercicio6
void informaPorPal(char misPalabras[FIL1][COL2], char letra){

    for(int i=0; i<FIL1; i++){
        if( misPalabras[i][0] == letra || misPalabras[i][strlen(misPalabras[i])-1] == letra){
                        printf("La palabra: %s empieza o termina con %c\n", misPalabras[i], letra);

        }
    }
}
