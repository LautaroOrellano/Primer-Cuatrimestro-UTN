#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//Prototipado

void cargarPila(Pila *pila1);
void pasarPila(Pila *pilaAux1, Pila *pila1);
void pasarPilaConOrden(Pila *pila1, Pila *pilaAux1, Pila *pila2);
int menorElemntoPila(Pila *pila1, Pila *pilaDescarte, Pila *pilaAux1);
void ordenamientoSeleccion(Pila *pila1, Pila *pilaDescarte, Pila *pilaAux1);

int main()
{
    Pila pila1,pilaAux1,pila2,pilaDescarte;

    inicpila(&pila1);
    inicpila(&pilaAux1);
    inicpila(&pila2);
    inicpila(&pilaDescarte);

    //Ejercicio1
    cargarPila(&pila1);
    mostrar(&pila1);

    //Ejercicio2
    /**
    pasarPila(&pilaAux1, &pila1);
    mostrar(&pila1);
    mostrar(&pilaAux1);
    */

    //Ejercicio3
    /**
    pasarPilaConOrden(&pila1, &pilaAux1, &pila2);
    mostrar(&pila1);
    mostrar(&pilaAux1);
    mostrar(&pila2);
    */

    //Ejercicio4

    /**
    int menor1 = menorElemntoPila(&pila1, &pilaDescarte, &pilaAux1);
    printf("El menor elemento de esta pila es: %d", menor1);
    */

    //Ejercicio5

    mostrar(&pila1);
}

void cargarPila(Pila *pila1){

    int elementos;
    int opcion;

    do{
        printf("Ingrese los valores que desee a la pila: \n");
        fflush(stdin);
        scanf("%d", &elementos);
        apilar(pila1, elementos);
        printf("Precione 0 para finalizar la carga, cualquier otro numero para continuar: \n");
        fflush(stdin);
        scanf("%d", &opcion);
    }while(opcion != 0);
}

void pasarPila(Pila *pilaAux1, Pila *pila1){

    while(!pilavacia(pila1)){
        apilar(pilaAux1, desapilar(pila1));
    }
}

void pasarPilaConOrden(Pila *pila1, Pila *pilaAux1, Pila *pila2){

    while(!pilavacia(pila1)){
        apilar(pilaAux1, desapilar(pila1));
    }

    while(!pilavacia(pilaAux1)){
        apilar(pila2, desapilar(pilaAux1));
    }
}

int menorElemntoPila(Pila *pila1, Pila *pilaDescarte, Pila *pilaAux1){

    int menor = desapilar(pila1);
    apilar(pilaAux1, menor);

    while(!pilavacia(pila1)){
            int elemento = desapilar(pila1);
            if(elemento < menor){
            menor = elemento;
            }
            apilar(pilaAux1, elemento);
    }
    mostrar(pilaAux1);

    int bandera = 0;
    while(!pilavacia(pilaAux1)){
            int elemento = desapilar(pilaAux1);
            if(menor == elemento && bandera == 0){
                    apilar(pilaDescarte, elemento);
                    bandera = 1;
            } else {
                 apilar(pila1, elemento);
            }
    }

    mostrar(pila1);
    return menor;
}

void ordenamientoSeleccion(Pila *pila1, Pila *pilaDescarte, Pila *pilaAux1){

    while(!pilavacia(pila1)){
        int menor = menorElemntoPila(pila1, pilaDescarte, pilaAux1);
        apilar(pilaDescarte, menor);

        mostrar(pilaDescarte);
    }

    while()




}


