#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

//Lautaro Orellano Lorenzo, comision 14.

//Prototipado
void cargarPilaRandom(Pila *pilaDatos, int cantDias);
void cargarPilaUsuario(Pila *pilaDatos, int cantDias);
int separarPrecipitacioens(Pila pilaDatos, Pila *pilaLluvias, int cantDias, int vectorLluvias[cantDias], int validos);
void mostrarVectorLLuvia(int validos, int vectorLluvia[validos]);
int promedioPilaLluvia(float *promedio, Pila pilaLluvia, Pila *auxiliar);
void mayorPrecipitacion(int cantDias, int vectorLluvia[cantDias], int validos);
void posicionPrecAlta(int cantDias, int vectorLluvia[cantDias], int validos);
void menorPrecipitacion(Pila pilaLluvias, Pila auxiliar);
void informaMaxMin(Pila pilaLluvias, Pila auxiliar, int cantDias, int vectorLluvia[cantDias], int validos);
void extraVocales(char palabra[], Pila *pilaVocales);
void mostrarPila(Pila *pilaVocales);
void armaFrase(char matrizLetras[5][20]);

int main()
{
    int cantDias = 5;
    int validos, dias;
    float promedio;
    Pila pilaDatos, pilaLluvias, auxiliar, pilaVocales;
    int vectorLluvia[cantDias];
    char palabra[] = "externocleidomastoideo";
    char matrizLetra[5][20]= {"pedro", "andaba", "caminando", "por", "ahi"};

    inicpila(&pilaDatos);
    inicpila(&pilaLluvias);
    inicpila(&auxiliar);
    inicpila(&pilaVocales);

    /**
    cargarPilaRandom(&pilaDatos, cantDias);
    cargarPilaUsuario(&pilaDatos, cantDias);
    mostrar(&pilaDatos);
    validos = separarPrecipitacioens(pilaDatos, &pilaLluvias, cantDias, vectorLluvia, validos);
    printf("Las precipitaciones menoras a 60 mm son: \n");
    mostrar(&pilaLluvias);
    printf("------------------------------------------ \n");
    printf("Las precipitaciones mayores a 60 mm son: \n");
    mostrarVectorLLuvia(validos, vectorLluvia);
    printf("------------------------------------------ \n");
    printf("Los validos son: %d\n", validos);
    dias = promedioPilaLluvia(&promedio, pilaLluvias, &auxiliar);
    printf("El promedio de las precipitaciones fue: %f y los dias fueron %d\n", promedio, dias);
    mayorPrecipitacion(cantDias, vectorLluvia, validos);
    informaMaxMin(pilaLluvias, auxiliar, cantDias, vectorLluvia, validos);
    */

    //extraVocales(palabra,&pilaVocales);
    //mostrarPila(&pilaVocales);

    armaFrase(matrizLetra);

    return 0;
}

void cargarPilaRandom(Pila *pilaDatos, int cantDias){

    srand(time(NULL));
    for(int i=0; i<cantDias; i++){
        apilar(pilaDatos, rand()% 180 + 1);
    }

}

void cargarPilaUsuario(Pila *pilaDatos, int cantDias){

    int i = 0;
    int precipitaciones;
    char opcion = 's';

    while((opcion == 's') && (i < cantDias)){

        printf("Dame el numero en mm de presipitaciones que quieres cargar a la pila. \n");
        scanf("%d", &precipitaciones);
        fflush(stdin);

        if(precipitaciones > 180){
            printf("Las pricipitaciones no pueden superar los 180mm por dia. \n");
        } else if( precipitaciones < 0){
            printf("Las precipitaciones no pueden ser menor a 0 mm. \n");
        } else {
            apilar(pilaDatos, precipitaciones);
        }

        printf("Quiere seguir cargando precipitaciones? (s para continuar, n para salir):");
        scanf(" %c", &opcion);
        fflush(stdin);

        i++;
    }

}

int separarPrecipitacioens(Pila pilaDatos, Pila *pilaLluvias, int cantDias, int vectorLluvias[cantDias], int validos){


        int i = 0;

        while(!pilavacia(&pilaDatos)){

            int aux = tope(&pilaDatos);

            if(aux < 60){
                    apilar(pilaLluvias, aux);
               } else {
                    vectorLluvias[i] = aux;
                    i++;
               }

            desapilar(&pilaDatos);
        }

        validos = i;

        return validos;
}

void mostrarVectorLLuvia(int validos, int vectorLluvia[validos]){

        for(int i=0; i<validos; i++){
            printf("%d ", vectorLluvia[i]);
        }
        printf("\n");
}

int promedioPilaLluvia(float *promedio, Pila pilaLluvia, Pila *auxiliar){

        int suma =0;
        int acum = 0;
        while(!pilavacia(&pilaLluvia)){

            int aux = tope(&pilaLluvia);

            suma = suma + aux;
            acum = acum + 1;

            desapilar(&pilaLluvia);
            apilar(auxiliar, aux);
        }

        *promedio = suma / acum;

        while(!pilavacia(auxiliar)){
            apilar(&pilaLluvia, desapilar(auxiliar));
        }

        return acum;
}

void mayorPrecipitacion(int cantDias, int vectorLluvia[cantDias], int validos){

    int i=0;
    int mayorPrecip = vectorLluvia[i];

    for(i=1; i<validos; i++){

        if(mayorPrecip < vectorLluvia[i]){

            mayorPrecip = vectorLluvia[i];
        }
    }

    printf("La mayor precipitacion del mes fue: %d\n", mayorPrecip);
}

void posicionPrecAlta(int cantDias, int vectorLluvia[cantDias], int validos){

    int i=0;
    int mayorPrecip = vectorLluvia[i];
    int posMayor = 0;

    for(i=1; i<validos; i++){

        if(mayorPrecip < vectorLluvia[i]){

            mayorPrecip = vectorLluvia[i];
            posMayor = i+1;
        }
    }

    printf("La mayor precipitacion esta en la posicion : %d\n", posMayor);
}

void menorPrecipitacion(Pila pilaLluvias, Pila auxiliar){

        int precMenor = tope(&pilaLluvias);
        desapilar(&pilaLluvias);

        while(!pilavacia(&pilaLluvias)){
            if(precMenor > tope(&pilaLluvias)){
                precMenor = tope(&pilaLluvias);
            }

            apilar(&auxiliar, desapilar(&pilaLluvias));
        }

        while(!pilavacia(&auxiliar)){
            apilar(&pilaLluvias, desapilar(&auxiliar));
        }

        printf("La menor precipitacion es : %d\n", precMenor);
}

void informaMaxMin(Pila pilaLluvias, Pila auxiliar, int cantDias, int vectorLluvia[cantDias], int validos){

        posicionPrecAlta(cantDias, vectorLluvia, validos);
        menorPrecipitacion(pilaLluvias, auxiliar);
}

void extraVocales(char palabra[], Pila *pilaVocales){

        int i;

        for(int i=0; palabra[i] != '\0'; i++){
                printf("Letra %d: %c\n", i, palabra[i]);

                char letra = palabra[i];
                if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra =='u'){
                    apilar(pilaVocales, palabra[i]);
                }

        }

}

void mostrarPila(Pila *pilaVocales){

    while (!pilavacia(pilaVocales)) {
        printf("Vocal en pila: %c\n", desapilar(pilaVocales));
    }

}

void armaFrase(char matrizLetras[5][20]){

    for(int i=0; i<5; i++){
        printf(" %s", matrizLetras[i]);
    }
}
