#include <stdio.h>
#include <stdlib.h>

///Prototipado
int contarPares(char arreglo[], int validos);

int main()
{
    ///Ejercicio1

    int valor = 5;
    int* pint = &valor;
    int** ppint = &pint;

    printf("Direccion de memoria de int valor: %p\n", &valor);
    printf("Direccion de memoria de int *pint: %p\n", &pint);
    printf("Direccion de memoria de int **ppint: %p\n", &ppint);

    getchar();

    printf("Contenido de int valor: %d\n", valor);
    printf("Contenido de int *pint: %d\n", *pint);
    printf("Contenido de int **ppint: %d\n", **ppint);

    getchar();

    printf("Ingrese un entero: ");
    scanf("%d", pint);
    printf("Contenido de variable valor modificado a travez de un puntero: %d\n\n", valor);

    getchar();

    printf("Ingrese un Entero nuevamente: ");
    scanf("%d", *ppint);
    printf("Contenido de variable valor modificado a travez de un puntero doble: %d\n\n", valor);

    ///Ejercicio2

    char arreglo[] = {1,2,3,4,5,6,7,8,9,10};
    int validos = 10;
    int pares;
    int* arreglo2;
    while(getchar() != '\n');

    pares = contarPares(arreglo,validos);
    printf("Cantidad de pares: %d", pares);

    arreglos2 = malloc(pares * sizeof(int));


    return 0;
}

int contarPares(char arreglo[], int validos){
    int contPares = 0;

    for(int i=0; i<validos; i++){
        if(arreglo[i]%2 == 0){
            contPares ++;
        }
    }
    return contPares;
}

void pasoPares(int arreglo[], int validos,int arreglo2){

    int i = 0;
    int j = 0;

    while(i<validos){

        if(arreglo[i]%2==0)){
            arreglo2[j] = arreglo[i];
            j++;
        }
        i++;
    }
}

