#include <stdio.h>
#include <stdlib.h>

#define DIM 10

//Prototipado
int cargarArreglo(int vectorNum[DIM], int validos);
int elementosParesVector(int vectorNum[DIM], int validos);
void traspasarElementosPares(int vectorNum[DIM], int validos, int **vectorPares);
void mostrarArreglo(int* arregloNum, int validos);

int main()
{
    ///Ejercicio1
    /**
    int valor = 3;
    int* punt = &valor;
    int** ppunt = &punt;


    printf("La direccion de memoria de valor es: %d\n", &valor);
    printf("La direccion de memoria de punt es %d\n", &punt);
    printf("La direccion de memoria de ppunt es %d\n", &ppunt);

    printf("\n");

    printf("El valor de la variable valor es de: %d \n", valor);
    printf("El valor del puntero punt es de: %d \n", *punt);
    printf("El valor del puntero ppunt es de: %d \n", **ppunt);

    printf("\n");

    printf("Agregue un entero para modificar el valor de la variable: ");
    scanf("%d", punt);
    while(getchar() != '\n');

    printf("\n");

    printf("El valor fue modificado a travez del puntero *punt y ahora vale: %d \n", *punt);

    system("pause");

    printf("Agregue un entero para modificar el valor de la variable: ");
    scanf("%d", ppunt);
    while(getchar() != '\n');

    printf("El valor fue modificado a travez del puntero **ppunt y ahora vale: %d \n", *ppunt);

    system("pause"); */

    ///Ejercicio2

    int vectorNum[DIM];
    int* vectorPares;

    int validos, validosPares;

    validos = cargarArreglo(vectorNum, validos);
    printf("Los elementos del vector statico son: %d\n", validos);

    mostrarArreglo(vectorNum, validos);

    validosPares = elementosParesVector(vectorNum, validos);

    printf("Los elementos pares del vector statico son: %d\n", validosPares);

    vectorPares = (int*) malloc (sizeof(int) * validosPares);

    traspasarElementosPares(vectorNum, validos, &vectorPares);
    mostrarArreglo(vectorPares, validosPares);

    free(vectorPares);
    return 0;
}

int cargarArreglo(int vectorNum[DIM], int validos){

    char opcion = 's';
    int i = 0;
    int num;
    int cont = 0;

    while(i< DIM && opcion == 's'){

        printf("Agregue un elemento al vector de numeros: ");
        fflush(stdin);
        scanf("%d", &num);
        while(getchar() != '\n');

        if(0 < num){

            vectorNum[i] = num;
            cont++;
        }

        printf("Desea seguir cargando el arreglo ?\n");
        scanf("%c", &opcion);
        while(getchar() != '\n');
    }

    return cont;
}

int elementosParesVector(int vectorNum[DIM], int validos){

    int contPares = 0;

    for(int i = 0; i < validos; i++){

        if( vectorNum[i] % 2 == 0){
                contPares++;
        }

    }

    return contPares;
}

void traspasarElementosPares(int vectorNum[DIM], int validos, int **vectorPares){

    int j = 0;
    for(int i = 0; i < validos; i++){

        if(vectorNum[i] %2 == 0){
            (*vectorPares)[j] = vectorNum[i];
            j++;
        }
    }
}

void mostrarArreglo(int* arregloNum, int validos){

    for(int i=0; i<validos; i++){
        fflush(stdin);
        printf("%d ", &arregloNum[i]);
    }

}
