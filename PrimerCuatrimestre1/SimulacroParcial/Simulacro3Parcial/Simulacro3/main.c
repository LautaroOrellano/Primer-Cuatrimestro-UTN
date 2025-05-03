//Lautaro Orellano Lorenzo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"
#include <string.h>
const int DIM = 10;
const char FIL = 30;
const char COL = 40;
const int PREF = 20;

//Prototipado
void cargaArreglos(int tiposMuestras[DIM], int concMuestras[DIM], int cantMuestras, int cargaDatos);
void mostrarArreglos(int tiposMuestras[DIM], int concMuestras[DIM], int cantMuestras);
void clasificaConcentraciones(int tiposMuestras[DIM], int concMuestras[DIM], Pila *A, Pila *B, Pila *C, int cantMuestras);
float promedioConcent(int concMuestras[DIM], int cantMuestras);
float porcBajoUmbral(Pila A, int umbral, int cantMuestras);
void informaPromPorc(Pila A, int umbral, int cantMuestras, int concMuestras[DIM]);
void cargaApeyNom(char matPersonas[FIL][COL], int n);
int buscaApe(char prefijo[20], int n, char matPersonas[FIL][COL], int posiciones[PREF]);

void cargaBuscados(int posiciones[PREF], int n);

int main()
{
    int tiposMuestras[DIM];
    int concMuestras[DIM];
    char matPersonas[FIL][COL];
    int cantMuestras, cargaDatos,n;
    int posiciones[PREF];
    int umbral = 50;
    float resultados;
    char prefijo[20];
    int cantidad;
    Pila A, B, C;
    inicpila(&A);
    inicpila(&B);
    inicpila(&C);

    //Ejercicio1
    /**printf("Que cantidad de muestras desea cargar ? Recuerda que solo puedes cargar hasta %d\n", DIM);
    fflush(stdin);
    scanf("%d",&cantMuestras);
    printf("Como desea cargar el los valores ? (0 para manual, 1 para automatica) \n");
    scanf("%d", &cargaDatos);
    cargaArreglos(tiposMuestras, concMuestras, cantMuestras, cargaDatos);
    mostrarArreglos(tiposMuestras, concMuestras, cantMuestras);

    //Ejercicio2
    clasificaConcentraciones(tiposMuestras, concMuestras, &A, &B, &C, cantMuestras);
    mostrar(&A);
    mostrar(&B);
    mostrar(&C);

    //Ejercicio3
    informaPromPorc(A, umbral, cantMuestras, concMuestras);*/


    //Ejercicio4
    do{
        printf("Dame la cantidad de nombres que deseas ingresar:\n");
        scanf("%d", &n);
        getchar();

        if(n > 30){
            printf("Los nombres no pueden ser mas de 30\n");
        }
    }while(n > 30 || n <= 0);
    cargaApeyNom(matPersonas, n);

    printf("Ingrese el prefijo que desea buscar dentro de los nombres:\n");
    fflush(stdin);
    scanf(" %s", &prefijo);

    cantidad = buscaApe(prefijo, n, matPersonas, posiciones);
    printf("%d", cantidad);
    if(cantidad == 0 ){
        printf("No se encontro el prefijo solicitado");
    } else {
        printf("Se encontro el prefijo en las siguientes pocisiones: \n");
        for(int i=0; i<cantidad; i++){
            printf("Fila %d: %s\n", posiciones[i], matPersonas[posiciones[i]]);
        }
    }

    cargaBuscados(posiciones, cantidad);

    return 0;
}


//Ejercicio1
void cargaArreglos(int tiposMuestras[DIM], int concMuestras[DIM], int cantMuestras, int cargaDatos){

    int muestra, concent;
    int i = 0;

    if(cargaDatos == 0){

        for(i=0; i<cantMuestras; i++){

            printf("Ingrese el tipo de muestra que desea agregar\n");
            scanf("%d", &muestra);

            printf("Ingrese el numero de concentracion que desea agregar\n");
            scanf("%d", &concent);

            tiposMuestras[i] = muestra;
            concMuestras[i] = concent;
        }

    } else {
        srand(time(NULL));
        for(i=0; i<cantMuestras; i++){
                tiposMuestras[i] = rand()%3;
                concMuestras[i] = rand()%100+1;
        }
    }
}
void mostrarArreglos(int tiposMuestras[DIM], int concMuestras[DIM], int cantMuestras){

    for(int i=0; i<cantMuestras; i++){
        printf("Tipo de Muestra: %d\n", tiposMuestras[i]);
        printf("Numero de concentracion: %d\n", concMuestras[i]);
    }
}
//Ejercicio2
void clasificaConcentraciones(int tiposMuestras[DIM], int concMuestras[DIM], Pila *A, Pila *B, Pila *C, int cantMuestras){

    for(int i=0; i<cantMuestras; i++){

        if(concMuestras[i] > 30 && concMuestras[i] <= 60){
            apilar(A, concMuestras[i]);
        } else {
            apilar(B, concMuestras[i]);
        }

        if(tiposMuestras[i] == 1){
            apilar(C, tiposMuestras[i]);
        }
    }
}
//Ejercicio3
float promedioConcent(int concMuestras[DIM], int cantMuestras){

    int aux = 0;
    int suma = 0;
    float promedio = 0;

    for(int i=0; i<cantMuestras; i++){
        aux = concMuestras[i];
        suma = suma + aux;
    }
    promedio = (float)suma / cantMuestras;

    return promedio;
}
float porcBajoUmbral(Pila A, int umbral, int cantMuestras){

    int aux;
    int acum = 0;
    float porcentaje;

    while(!pilavacia(&A)){

        aux = tope(&A);
        if(aux <= umbral){
            acum = acum +1;
        }
        desapilar(&A);
    }
    porcentaje = ((float)acum/cantMuestras)*100;
    return porcentaje;
}
void informaPromPorc(Pila A, int umbral, int cantMuestras, int concMuestras[DIM]){
    float promedio, porcentaje;
    promedio = promedioConcent(concMuestras, cantMuestras);
    printf("El promedio de las concentraciones es: %f\n", promedio);
    porcentaje = porcBajoUmbral(A, umbral, cantMuestras);
    printf("El porcentaje de las concentraciones por debajo de %d es: %f\n", umbral, porcentaje);
}
//Ejercicio4
void cargaApeyNom(char matPersonas[FIL][COL], int n){

    printf("Dame los nombre y apellido a cargar\n");

    for(int i=0; i<n; i++){
            fflush(stdin);
            gets(matPersonas[i]);
    }
}
int buscaApe(char prefijo[20], int n, char matPersonas[FIL][COL], int posiciones[PREF]){

    int cont = 0;
    for(int i=0; i<n; i++){
        if(strstr(matPersonas[i],prefijo)){
            posiciones[cont] = i;
            cont++;
        }
    }

   return cont;
}
void cargaBuscados(int posiciones[PREF], int cantidad){

    //Muestro la Matriz
    for(int i=0; i<cantidad; i++){
            printf("las filas donde se encontraron fueron: %d\n", posiciones[i]);
    }
}



