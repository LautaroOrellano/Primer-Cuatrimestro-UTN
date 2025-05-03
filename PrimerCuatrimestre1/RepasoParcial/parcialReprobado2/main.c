//Lautaro Orellano Lorenzo -comision14
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pila.h"

#define DIMENSION 20
#define FIL 10
#define COL 20
#define FIL1 10
#define COL1 10
#define FIL2 10
#define COL2 30


//Prototipado
void cargarDatos(int codigosISBN[DIMENSION], char generosLibros[FIL][COL], int cantLibros);
///Ejercicio2
int clasificarPorGenero(int codigosISBN[DIMENSION], char generosLibros[FIL][COL], int cantLibros, Pila *policial, Pila *romance, Pila *terror, int *cantPolicial, int *cantRomance, int *cantTerror);
///Ejercicio3
void ordenarISBN(int codigosISBN[DIMENSION],char generosLibros[FIL][COL], int cantLibros);
void muestraInversa(int codigosISBN[DIMENSION], char generosLibros[FIL][COL], int cantLibros, int nLimite);
///Ejercicio4
void generaMatrizRandom(int matrizRandom[FIL1][COL1]);
void imprimirMatrizRandom(int matrizRandom[FIL1][COL1]);
///Ejercicio5
int cantidadDeApariciones(int codigo, int matrizRandom[FIL1][COL1]);
void cantidadPorCodigo(int codigosISBN[DIMENSION], int matrizRandom[FIL1][COL1], int cantLibros, int resultado[DIMENSION]);
///Ejercicio6
void informaPorPal(char misPalabras[FIL2][COL2], char letra);


int main()
{
    ///Ejercicio1
    int codigosISBN[DIMENSION];
    char generosLibros[FIL][COL];
    int cantLibros;

    printf("Ingrese que cantidad de libros desea cargar.... \n");
    scanf("%d", &cantLibros);
    fflush(stdin);
    cargarDatos(codigosISBN, generosLibros, cantLibros);

    ///Ejercicio2
    int cantPolicial = 0;
    int cantRomance = 0;
    int cantTerror = 0;
    Pila policial, romance, terror;
    inicpila(&policial);
    inicpila(&romance);
    inicpila(&terror);

    clasificarPorGenero(codigosISBN, generosLibros, cantLibros, &policial, &romance, &terror, &cantPolicial, &cantRomance, &cantTerror);
    printf("La pila policial tiene %d elementos.\n", cantPolicial);
    mostrar(&policial);
    printf("La pila romance tiene %d elementos.\n", cantRomance);
    mostrar(&romance);
    printf("La pila terror tiene %d elementos.\n", cantTerror);
    mostrar(&terror);

    ///Ejercicio3
    int nLimite = 0;

    printf("Por favor ingrese el numero limite para buscar en el vector:  ");
    scanf("%d", &nLimite);
    while (getchar() != '\n');
    ordenarISBN(codigosISBN,generosLibros, cantLibros);
    muestraInversa(codigosISBN, generosLibros, cantLibros, nLimite);

    ///Ejercicio4
    int matrizRandom[FIL1][COL1];
    generaMatrizRandom(matrizRandom);
    imprimirMatrizRandom(matrizRandom);

    ///Ejercicio5
    int resultado[DIMENSION];
    cantidadPorCodigo(codigosISBN, matrizRandom, cantLibros, resultado);

    ///Ejercicio6
    char misPalabras[FIL2][COL2];
    char letra;
    printf("Letra que desea comparar: ");
    scanf("%c", &letra);
    while (getchar() != '\n');
    printf("\n");
    informaPorPal(misPalabras, letra);

    return 0;
}
///Ejercicio1
void cargarDatos(int codigosISBN[DIMENSION], char generosLibros[FIL][COL], int cantLibros){

        int genero;
        char policial[10]= "policial";
        char romance[10]= "romance";
        char terror[10]= "terror";

        srand(time(NULL));
        for(int i=0; i<cantLibros; i++){

            //Cargo codigoISBN
            codigosISBN[i] = rand()%100+1;

            //Cargo generoLibros
            printf("Elija un genero (1.policial 2.romance 3.terror): ", i+1);
            scanf("%d", &genero);
            fflush(stdin);

            if(genero == 1){
                strcpy(generosLibros[i], policial);
            } else if (genero == 2){
                strcpy(generosLibros[i], romance);
            } else if (genero == 3){
                strcpy(generosLibros[i], terror);
            } else {
                printf("La opcion no corresponde a ningun genero.\n");
            }

            //Muestro el codigo con el genero cargado

            printf("------------------------\n");
            printf("Codigo ISBN, libro %d: %d\n", i+1, codigosISBN[i]);
            printf("Genero: %s\n", generosLibros[i]);
            printf("------------------------\n");
            printf("\n");

        }
}
///Ejercicio2
int clasificarPorGenero(int codigosISBN[DIMENSION], char generosLibros[FIL][COL], int cantLibros, Pila *policial, Pila *romance, Pila *terror, int *cantPolicial, int *cantRomance, int *cantTerror){

            for(int i=0; i<cantLibros; i++){

                if(strcmp(generosLibros[i], "policial")==0){
                    apilar(policial, codigosISBN[i]);
                    (*cantPolicial)++;
                } else if(strcmp(generosLibros[i], "romance")==0){
                    apilar(romance, codigosISBN[i]);
                    (*cantRomance)++;
                } else if(strcmp(generosLibros[i], "terror")==0){
                    apilar(terror, codigosISBN[i]);
                    (*cantTerror)++;
                }
            }
}
///Ejercicio3
void ordenarISBN(int codigosISBN[DIMENSION],char generosLibros[FIL][COL], int cantLibros){

    char temp2[10];

    for(int i = 0; i < cantLibros - 1; i++){
        for(int j = 0; j < cantLibros - i - 1; j++){
            if(codigosISBN[j] > codigosISBN[j + 1]){
                int temp = codigosISBN[j];
                codigosISBN[j] = codigosISBN[j + 1];
                codigosISBN[j + 1] = temp;
                strcpy(temp2, generosLibros[j]);
                strcpy(generosLibros[j], generosLibros[j+1]);
                strcpy(generosLibros[j+1], temp2);
            }
        }
    }

    //for(int i=0; i<cantLibros; i++){
    //    printf("Codigo ISBN, libro %d: %d\n", i+1, codigosISBN[i]);
    //    printf("Genero: %s\n", generosLibros[i]);
    //}

}
void muestraInversa(int codigosISBN[DIMENSION], char generosLibros[FIL][COL], int cantLibros, int nLimite){

    ordenarISBN(codigosISBN, generosLibros, cantLibros);

    for(int i=cantLibros-1; i>=0; i--){
        if(codigosISBN[i] >= nLimite){
            printf("Codigo ISBN, libro %d: %d\n", i+1, codigosISBN[i]);
            printf("Genero: %s\n", generosLibros[i]);
            printf("\n");
        }
    }
}
///Ejercicio4
void generaMatrizRandom(int matrizRandom[FIL1][COL1]){

    srand(time(NULL));
    for(int i=0; i<FIL1; i++){
        for(int j=0; j<COL1; j++){
            matrizRandom[i][j]=rand()%100+1;
        }
    }
}
void imprimirMatrizRandom(int matrizRandom[FIL1][COL1]){

    for(int i=0; i<FIL1; i++){
        for(int j=0; j<COL1; j++){
            printf("|%02d|", matrizRandom[i][j]);
        }
        printf("\n");
    }
}
///Ejercicio5
int cantidadDeApariciones(int codigo, int matrizRandom[FIL1][COL1]){

    int cont = 0;

    for(int i=0; i<FIL1; i++){
        for(int j=0; j<COL1; j++){
            if(matrizRandom[i][j] == codigo){
                cont++;
            }
        }
    }
    return cont;
}
void cantidadPorCodigo(int codigosISBN[DIMENSION], int matrizRandom[FIL1][COL1], int cantLibros, int resultado[DIMENSION]){


    for(int i=0; i<cantLibros; i++){
        resultado[i] = cantidadDeApariciones(codigosISBN[i], matrizRandom);
        printf("El codigo: %d aparecio: %d \n", codigosISBN[i], resultado[i]);
    }
}

void informaPorPal(char misPalabras[FIL2][COL2], char letra){

    char palabra[30];

    for(int i=0; i<FIL2; i++){

        printf("Ingrese la palabra numero %d a cargar\n", i+1);
        gets(palabra);

        strcpy(misPalabras[i], palabra);
    }

    printf("\n");

    for(int i=0; i<FIL2; i++){

        int ult = strlen(misPalabras[i]);

        if(misPalabras[i][0] == letra || misPalabras[i][ult-1] == letra){
            printf("La palabra %s comienza o finaliza con %c \n", misPalabras[i], letra);
        }
    }

}
