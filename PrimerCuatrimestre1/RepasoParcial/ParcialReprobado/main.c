#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Pila.h"

#define DIM 20
#define FIL 20
#define COL 20
#define FIL1 10
#define COL1 10
#define FIL2 10
#define COL2 30

//Prototipado
///Ejercicio1
void cargarDatos(int codigoISBN[DIM], char generoLibros[FIL][COL], int cantLibros);
///Ejercicio2
void clasificarPorGenero(int codigoISBN[DIM], char generoLibros[FIL][COL], int cantLibros, Pila *policial, Pila *romance, Pila *terror, int *cantPolicial, int *cantRomance, int *cantTerror);
///Ejercicio3
void ordenarISBN(int codigoISBN[DIM], char generoLibros[FIL][COL], int cantLibros);
void muestraInversa(int codigoISBN[DIM], char generoLibros[FIL][DIM], int cantLibros, int nLimite);
///Ejercicio4
void generaMatrizRandom(int matrizRandom[FIL1][COL1]);
void mostrarMatrizRandom(int matrizRandom[FIL1][COL1]);
///Ejercicio5
int cantidadApariciones(int aux, int matrizRandom[FIL1][COL1]);
void cantidadesPorCodigo(int codigoISBN[DIM], int cantLibros, int MatrizRandom[FIL1][COL1], int resultado[DIM]);
///Ejercicio6
void informaPorPalabra(char misPalabras[FIL2][COL2], char letra);


int main()
{
    int codigoISBN[DIM];
    char generoLibros[FIL][COL] = {"policial", "romance", "terror"};
    int matrizRandom[FIL1][COL1];
    int resultado[DIM];
    char misPalabras[FIL2][COL2];
    char letra;
    int cantLibros;
    int nLimite = 0;
    int cantPolicial = 0;
    int cantRomance = 0;
    int cantTerror = 0;

    Pila policial, romance, terror;
    inicpila(&policial);
    inicpila(&romance);
    inicpila(&terror);

    //printf("Cuantos libros desea cargar?: ");
    //scanf("%d", &cantLibros);
    //fflush(stdin);

    ///Ejercicio1
    //cargarDatos(codigoISBN, generoLibros,cantLibros);

    ///Ejercicio2
    //clasificarPorGenero(codigoISBN, generoLibros, cantLibros, &policial, &romance,  &terror, &cantPolicial, &cantRomance, &cantTerror);
    //mostrar(&policial);
    //mostrar(&romance);
    //mostrar(&terror);
    //printf("La cantidad de codigos ISBN de genero policial es: %d\n", cantPolicial);
    //printf("La cantidad de codigos ISBN de genero policial es: %d\n", cantRomance);
    //printf("La cantidad de codigos ISBN de genero policial es: %d\n", cantTerror);
    //printf("\n");

    ///Ejercicio3
    //printf("Dame un numero limite para encontrar \n");
    //scanf("%d", &nLimite);
    //ordenarISBN(codigoISBN, generoLibros, cantLibros);
    ///muestraInversa(codigoISBN, generoLibros, cantLibros, nLimite);

    ///Ejercicio4
    //generaMatrizRandom(matrizRandom);
    //mostrarMatrizRandom(matrizRandom);

    ///Ejercicio5
    //cantidadesPorCodigo(codigoISBN, cantLibros, matrizRandom, resultado);

    ///Ejercicio6
    //printf("Ingrese una letra: ");
    //scanf("%c", &letra);
    //while (getchar() != '\n');

    //informaPorPalabra(misPalabras, letra);

    return 0;
}
///Ejercicio 1
void cargarDatos(int codigoISBN[DIM], char generoLibros[FIL][COL], int cantLibros){

    int i=0;
    int genero;
    char policial[]= "policial";
    char romance[]= "romance";
    char terror[]= "terror";

    srand(time(NULL));
    for(i=0; i<cantLibros; i++){
        codigoISBN[i]=rand()%100+1;
    }
    for(i=0; i<cantLibros; i++){
        printf("Ingrese un genero (1-policial, 2-romace, 3-terror) para el libro %d : ", i+1);
        scanf("%d", &genero);
        fflush(stdin);
        printf("\n");

        if(genero == 1){
            strcpy(generoLibros[i], policial);
        } else if (genero == 2){
            strcpy(generoLibros[i], romance);
        } else if (genero == 3){
            strcpy(generoLibros[i], terror);
        } else {
            printf("Genero desconocido");
        }
    }


    //Muestro los vectores simultaneamente

    for(i=0; i<cantLibros; i++){

        printf("libro numero: %d codigo ISBN: %d\n", i+1, codigoISBN[i]);
        printf("El genero es: %s\n", generoLibros[i]);
        printf("\n");
    }
}
///Ejercicio2
void clasificarPorGenero(int codigoISBN[DIM], char generoLibros[FIL][COL], int cantLibros, Pila *policial, Pila *romance, Pila *terror, int *cantPolicial, int *cantRomance, int *cantTerror){

    for(int i=0; i<cantLibros; i++){

        if(strcmp(generoLibros[i], "policial")==0){
            apilar(policial, codigoISBN[i]);
            (*cantPolicial)++;
        } else if(strcmp(generoLibros[i], "romance")==0){
            apilar(romance, codigoISBN[i]);
            (*cantRomance)++;
        } else if(strcmp(generoLibros[i], "terror")==0){
            apilar(terror, codigoISBN[i]);
            (*cantTerror)++;
        }
    }
}
///Ejercicio3
void ordenarISBN(int codigoISBN[DIM], char generoLibros[FIL][COL], int cantLibros){

       char temporal2[20];

       for(int i=0; i<cantLibros - 1; i++){
        for(int j=0; j<cantLibros - i - 1; j++){
            if (codigoISBN[j] > codigoISBN[j + 1]){
                int temporal = codigoISBN[j];
                codigoISBN[j] = codigoISBN[j + 1];
                codigoISBN[j + 1] = temporal;
                strcpy(temporal2, generoLibros[j]);
                strcpy(generoLibros[j], generoLibros[j+1]);
                strcpy(generoLibros[j+1], temporal2);
            }
        }
    }
    /**for(int i=0; i<cantLibros; i++){

        printf("libro numero: %d codigo ISBN: %d\n", i+1, codigoISBN[i]);
        printf("El genero es: %s\n", generoLibros[i]);
        printf("\n");
    }*/
}
void muestraInversa(int codigoISBN[DIM], char generoLibros[FIL][DIM], int cantLibros, int nLimite){

    ordenarISBN(codigoISBN, generoLibros, cantLibros);

    for(int i=cantLibros-1; i >= 0; i--){
        if(nLimite <= codigoISBN[i]){
            printf("libro numero: %d codigo ISBN: %d\n", i+1, codigoISBN[i]);
            printf("El genero es: %s\n", generoLibros[i]);
            printf("\n");
        }
    }
}
///Ejercicio4
void generaMatrizRandom(int matrizRandom[FIL1][COL1]){

    srand(time(NULL));
    for(int i=0; i<FIL1; i++){
        for(int j=0; j<COL1; j++){
            matrizRandom[i][j] = rand()%100+1;
        }
    }
}
void mostrarMatrizRandom(int matrizRandom[FIL1][COL1]){

    for(int i=0; i<FIL1; i++){
        for(int j=0; j<COL1; j++){
            printf("|%02d|", matrizRandom[i][j]);
        }
        printf("\n");
    }
}
///Ejercicio5
int cantidadApariciones(int aux, int matrizRandom[FIL1][COL1]){

    int cont = 0;

    for(int i=0; i<FIL1; i++){
        for(int j=0; j<COL1; j++){
            if(matrizRandom[i][j] == aux){
                cont++;
            }
        }
    }
    return cont;
}
void cantidadesPorCodigo(int codigoISBN[DIM], int cantLibros, int matrizRandom[FIL1][COL1], int resultado[DIM]){

    for(int i=0; i<cantLibros; i++){

        resultado[i] = cantidadApariciones(codigoISBN[i], matrizRandom);
        printf("La cantidad de veces que aparece el codigo: %d es: %d \n", codigoISBN[i], resultado[i]);
    }
}
///Ejercicio6
void informaPorPalabra(char misPalabras[FIL2][COL2], char letra){

    char palabra[30];

    for(int i=0; i<10; i++){
        printf("Ingrese la palabra numero %d: ", i+1);
        gets(palabra);

        strcpy(misPalabras[i],palabra);
    }

    printf("\n");
    //for(int i=0; i<10; i++){
    //    printf("Las palabras son: %s \n", misPalabras[i]);
    //}

    for(int i=0; i<10; i++){
        int largo = strlen(misPalabras[i]);
        //char ult = misPalabras[i][largo-1];

        if(misPalabras[i][0] == letra || misPalabras[i][largo-1] == letra){
            printf("La palabra: %s comienza o finaliza con %c \n", misPalabras[i], letra);
        }
    }

}



