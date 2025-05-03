//Lautaro Orellano Lorenzo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"
#include <string.h>

#define DIMENCION 100
#define CANT_PAL 10
#define LONG_PAL 30

//PrototipadoINT
///EjercicioA
void cargarPilaUsuario(Pila *calificaciones);
///EjercicioB
void cargarPilaRandom(Pila *calificaciones);
///EjercicioC
void opcionDeCarga(Pila *calificaciones);
///EjercicioD
int pilaToArray(Pila calificaciones, int vectorNotas[DIMENCION]);
///EjercicioE
void mostrarArreglo(int vectorNotas[DIMENCION], int validos);
///EjercicioF
void informeGeneralPromedio(int vectorNotas[DIMENCION], int validos);
///EjercicioG
void informaMayoMenor(int vectorNotas[DIMENCION], int validos, char nota[]);

//PrototipadoString
void informaString(char palabras[CANT_PAL][LONG_PAL], int i);
int contarVocalesPalabras(char palabras[CANT_PAL][LONG_PAL], int i);


int main()
{
    ///EjercicioA
    //int calificacion, validos;
    //Pila calificaciones;
    //inicpila(&calificaciones);
    //opcionDeCarga(&calificaciones);
    //mostrar(&calificaciones);

    ///EjercicioC
    //int vectorNotas[DIMENCION];
    //validos = pilaToArray(calificaciones, vectorNotas);

    ///EjercicioE

    //mostrarArreglo(vectorNotas, validos);

    ///EjercicioF
    //informeGeneralPromedio(vectorNotas, validos);

    ///EjercicioG
    //char nota[10];
    //while(getchar() != '\n');
    //printf("Que nota desea buscar (escriba mayor o menor): ");
    //gets(nota);
    //informaMayoMenor(vectorNotas, validos, nota);


    ///PARTE 2 STRING
    char palabras[CANT_PAL][LONG_PAL];
    int i=0;
    informaString(palabras, i);

    return 0;
}

///Ejercicio1A
void cargarPilaUsuario(Pila *calificaciones){

    char opcion = 's';
    int calificacion;
    int i = 0;

    while(opcion == 's' && i < 50){
        printf("Dame la calificacion que quiere cargar a la pila. Ignresar hasta 50 calificaciones \n");
        scanf("%d", &calificacion);
        fflush(stdin);
        if (calificacion <= 10 && calificacion > 0){
            apilar(calificaciones, calificacion);
            i++;
        } else{
            printf("La califiacion debe ser de 0 a 10 puntos. \n");
        }
        if(i<50){
        printf("Desea seguir cargando la pila ? (s para continuar, n para terminar): ");
        scanf(" %c", &opcion);
        fflush(stdin);
        }

    }
}
///Ejercicio1B
void cargarPilaRandom(Pila *calificaciones){
    int cantNotas;

    printf("Cuantas notas queres cargar aleatoriamente ? \n");
    scanf("%d", &cantNotas);
    fflush(stdin);

    srand(time(NULL));
    if(cantNotas<50){
        for(int i=0; i<cantNotas; i++){
            apilar(calificaciones, rand()%10+1);
        }
    } else {
        printf("Se exedio de la cantidad de notas");
    }
}
///Ejercicio1C
void opcionDeCarga(Pila *calificaciones){

    int carga;

    printf("Elija como quiere ingresar la carga de la pila. (opcion 0 manual, opcion 1 automatica): \n");
    scanf("%d", &carga);
    fflush(stdin);

    if(carga == 0){
        cargarPilaUsuario(calificaciones);
    } else {
        cargarPilaRandom(calificaciones);
    }
}
///Ejercicio1D
int pilaToArray(Pila calificaciones, int vectorNotas[DIMENCION]){

   int pares[DIMENCION];
   int impares[DIMENCION];
   int iPar=0;
   int iImpar=0;

    while(!pilavacia(&calificaciones)){
            int aux = desapilar(&calificaciones);
            if(aux %2 == 0){
                pares[iPar++] = aux;
            } else {
                impares[iImpar++] = aux;
            }
    }

    int posPar = 0;
    int posImpar = 1;
    int i=0;
    int j=0;
    int validos = 0;

    // Cargamos los pares primero en posiciones pares
    while (i < iPar && posPar < DIMENCION) {
        vectorNotas[posPar] = pares[i++];
        posPar += 2;
        validos++;
    }

    // Cargamos los impares en posiciones impares
    while (j < iImpar && posImpar < DIMENCION) {
        vectorNotas[posImpar] = impares[j++];
        posImpar += 2;
        validos++;
    }

    // Rellenamos con ceros el resto
    while (posPar < DIMENCION) {
        vectorNotas[posPar] = 0;
        posPar += 2;
    }

    while (posImpar < DIMENCION) {
        vectorNotas[posImpar] = 0;
        posImpar += 2;
    }

    return validos;
}
///EjercicioE
void mostrarArreglo(int vectorNotas[DIMENCION], int validos){

    for(int i=0; i<validos; i++){
        printf("El vector en la posicion: %d %d \n", i, vectorNotas[i]);
    }
}
///EjercicioF
void informeGeneralPromedio(int vectorNotas[DIMENCION], int validos){

    float promedio;
    int suma =0;
    int notaMenor =0;
    int notaMayor =0;

    for(int i=0; i<validos; i++){

        suma+=vectorNotas[i];
    }

    promedio = (float)suma / validos;

    printf("promedio: %f \n", promedio);

    for(int i=0; i<validos; i++){
        if(vectorNotas[i] < promedio){
            notaMenor++;
        } else if (vectorNotas[i] > promedio) {
            notaMayor++;
        }
    }

    printf("Las notas por encima del promedio fueron: %d\n", notaMayor);
    printf("Las notas por debajo del promedio fueron: %d\n", notaMenor);
}
///EjercicioG
void informaMayoMenor(int vectorNotas[DIMENCION], int validos, char nota[]){

    int i=0;
    int mayor = vectorNotas[i];
    int menor = vectorNotas[i];
    int myor = 0;
    int mnor = 0;

    for(i=1; i<validos; i++){

        if(vectorNotas[i] > mayor){
            mayor = vectorNotas[i];
        }

        if(vectorNotas[i]< menor){
            menor = vectorNotas[i];
        }
    }

    for(i=0; i<validos; i++){

        if(vectorNotas[i] == mayor){
            myor++;
        } else if (vectorNotas[i] == menor){
            mnor++;
        }
    }

    if(strcmp(nota, "mayor")==0){
        printf("La nota %s es: %d cantidad de apariciones %d", nota, mayor, myor);
    } else if (strcmp(nota, "menor")==0){
        printf("La nota %s es: %d cantidad de apariciones %d veces", nota, menor, mnor);
    }
}

///PARTE 2 STRING
///EjercicioA
void informaString(char palabras[CANT_PAL][LONG_PAL], int i){

    for(int i=0; i<CANT_PAL; i++){
        printf("Ingrese la palabra numero %d:", i+1);
        gets(palabras[i]);
    }

    int totalVocales = contarVocalesPalabras(palabras, i);


    printf("La cantidad de vocales de la palabra %s es: %d", palabras[i], totalVocales);
    //printf("La palabra %s: contine %d vocales y esta en la posicion %d y es la que mas vocales tiene", palabras[i], totalVocales, i);

}

int contarVocalesPalabras(char palabras[CANT_PAL][LONG_PAL]){

    int a=0;
    int e=0;
    int i1=0;
    int o=0;
    int u=0;
    int totalVocales = 0;

    for(int i=0; i<CANT_PAL; i++){
        for(int j=0; j<LONG_PAL; j++){
            if(palabras[i][j] == 'a'){
                a++;
            } else if(palabras[i][j] == 'e'){
                e++;
            } else if(palabras[i][j] == 'i'){
                i1++;
            } else if(palabras[i][j] == 'o'){
                o++;
            } else if(palabras[i][j] == 'u'){
                u++;
            }
        }
    }

     totalVocales = a + e + i1 + o + u;

    return totalVocales;
}
