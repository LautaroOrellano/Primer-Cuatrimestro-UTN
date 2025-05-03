#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//prototipado
int cargarArreglo(int arreglo[], int valido, int dimencion);
void mostrarArreglo(int arreglo[], int valido);
void sumaElementos(int arreglo[], int valido);
void arregloCopiaPila(int arreglo[], int valido, Pila copiaArreglo);
float cargarArregloFloat(float arregloF[], int valido, int dimensionF);
void mostrarArregloFloat(float arregloF[], int valido);
void sumaElementosFloat(float arregloF[], int valido);
int cargarArregloChar(char arregloC[], int valido, int dimension);
void mostrarArregloChar(char arregloC[], int valido);
void encontrarCaracter(char arregloC[], int valido);
void ordenadoAlfabeticamente(char arregloC[10], int valido);
void insertarNuevoCaracter(char arregloC[], int *u);
char maximoCaracter(char arregloC[10]);
void arregloCapicua(char arregloC[10], char arregloC2[10], int valido);


int main()
{
   int u;
   int dato = 0;
   int mayor = 0;
   int dimension = 10;
   int dimensionF = 100;
   int arreglo[10];
   char arregloC[10];
   char arregloC2[10];
   float arregloF[100];
   int valido = 0;

   Pila copiaArreglo;
   inicpila(&copiaArreglo);

   /**
   valido = cargarArreglo(arreglo, valido, dimension);
   printf("Cantidad de elementos cargados: %d\n", valido);

   mostrarArreglo(arreglo, valido);

   sumaElementos(arreglo, valido);

   arregloCopiaPila(arreglo, valido, copiaArreglo);
   */

    /**
   valido = cargarArregloFloat(arregloF, valido, dimensionF);
   printf("Cantidad de elementos cargados: %d\n", valido);

    printf("los validos son: %d\n", valido);

   mostrarArregloFloat(arregloF, valido);

   sumaElementosFloat(arregloF, valido);
    */

    valido = cargarArregloChar(arregloC, valido, dimension);
    printf("Cantidad de elementos cargados: %d\n", valido);

    mostrarArregloChar(arregloC, valido);
    printf("\n");

    //encontrarCaracter(arregloC, valido);
    //ordenadoAlfabeticamente(arregloC, valido);
    //insertarNuevoCaracter(arregloC, &valido);
    //mayor = maximoCaracter(arregloC);
    //printf("El mayor de los caracteres es: %c\n", mayor);

    arregloCapicua(arregloC, arregloC2,valido);
    printf("\n");

    mostrarArregloChar(arregloC, valido);

   return 0;
}

int cargarArreglo(int arreglo[10], int valido, int dimension){

    char opcion = 's';
    printf("Ingrese el valor que desea cargar al arreglo \n");

    while(opcion == 's' && valido < dimension){
            printf("Elemento %d: ", valido + 1);
            scanf("%i",&arreglo[valido]);
            printf("Queres seguir cargando el arreglo? (s para continuar, cualquier tecla para abortar) \n");
            scanf(" %c",&opcion);
            valido++;
    }
    return valido;
}

void mostrarArreglo(int arreglo[10], int valido){

    for(int i=0; i<valido; i++){
            printf("Lugar: %d contenido: %d\n", i, arreglo[i]);
    }
}

void sumaElementos(int arreglo[10], int valido){

        int suma = 0;

        for(int i=0; i<valido; i++){
            suma = suma + arreglo[i];
        }

    printf("La suma de los elementos del arreglo es: %d\n", suma);
}

void arregloCopiaPila(int arreglo[10], int valido, Pila copiaArreglo){

        int contenido;

        for(int i = 0; i < valido; i++){
                contenido = arreglo[i];
                apilar(&copiaArreglo, contenido);
        }

        printf("La pila copia del arreglo se creo con exito!! \n ");
        mostrar(&copiaArreglo);
}

float cargarArregloFloat(float arregloF[100], int valido, int dimensionF){

    char opcion = 's';
    printf("Ingrese el valor que desea cargar al arreglo \n");

    while(opcion == 's' && valido < dimensionF){
            printf("Elemento %d: ", valido + 1);
            scanf(" %f",&arregloF[valido]);
            printf("Queres seguir cargando el arreglo? (s para continuar, cualquier tecla para abortar) \n");
            scanf(" %c",&opcion);
            valido++;
    }
    return valido;
}

void mostrarArregloFloat(float arregloF[100], int valido){

    for(int i=0; i<valido; i++){
            printf("Lugar: %d contenido: %f\n", i, arregloF[i]);
    }
}

void sumaElementosFloat(float arregloF[100], int valido){

        float suma = 0;

        for(int i=0; i<valido; i++){
            suma = suma + arregloF[i];
        }

    printf("La suma de los elementos del arreglo float es: %f\n", suma);
}

int cargarArregloChar(char arregloC[10], int valido, int dimension){

    int opcion = 3;
    printf("Ingrese el caracter que desea cargar al arreglo \n");

    while(opcion == 3 && valido < dimension){
            printf("Elemento %d: ", valido + 1);
            scanf(" %c",&arregloC[valido]);
            printf("Queres seguir cargando el arreglo? (3 para continuar, cualquier tecla para abortar) \n");
            scanf(" %d",&opcion);
            valido++;
    }
    return valido;
}

void mostrarArregloChar(char arregloC[10], int valido){

    for(int i=0; i<valido; i++){
            printf("Lugar: %d contenido: %c \n", i, arregloC[i]);
    }
}

void encontrarCaracter(char arregloC[10], int valido){

        char caracter;
        char contenido;
        int flag = 0;

        printf("Que caracter estas buscando dentro del arrelgo? \n");
        scanf(" %c", &caracter);

        for(int i=0; i<valido; i++){

                contenido = arregloC[i];

                if(caracter == contenido && flag == 0){
                        printf("Se econtro su caracter en el lugar n: %d", i);
                        flag = 1;
                }
        }

        if(flag == 0){
            printf("No se econtro su caracter! \n");
        }
}

void ordenadoAlfabeticamente(char arregloC[10], int valido){

        char aux;

        for(int i=0; i<valido - 1; i++){
            for(int j=0; j<valido -1; j++){
                if(arregloC[j] > arregloC[j + 1]){
                        aux = arregloC[j];
                        arregloC[j] = arregloC[j+1];
                        arregloC[j+1] = aux;
                }
            }
        }
}

void insertarNuevoCaracter(char arregloC[10], int *u){


    char dato;
    printf("Ingrese el nuevo caracter por favor\n");
    scanf(" %c", &dato);

    int i = *u - 1;
    while(i >= 0 && dato < arregloC[i]){

            arregloC[i+1] = arregloC[i];
            i--;
    }

    arregloC[i+1] = dato;
    (*u)++;
}

char maximoCaracter(char arregloC[10]){

    char mayor = arregloC[0];

    for(int i=0; i<10; i++){
        if(arregloC[i] > mayor){
            mayor = arregloC[i];
        }
    }
    return mayor;
}

void arregloCapicua(char arregloC[10], char arregloC2[10],int valido){

    /**for(int i=0; i<valido; i++){
        arregloC2[i] = arregloC[i];
        printf("Arreglo n2: %c\n", arregloC2[i]);
    }*/

    for(int i=0; i<valido; i++){
        if(arregloC[i]!= arregloC[valido]){
            printf("El arreglo no es capicua!");
        }
    }

}
