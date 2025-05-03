#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Prototipado

void cargarMatriz(int matriz1[3][3]);
void mostrarMatriz(int matriz1[3][3]);
void cargarMatrizRandom(int matriz1[3][3]);
int sumaMatriz(int matriz[3][3]);
float promedioMatriz(int matriz1[3][3]);
void encontrarElemento(int matriz1[3][3], int dato);
int cargarPalabras(int dimF, int dimC, char palabra[dimF][dimC]);
void mostrarString(int validos, int dimC, char palabra[][dimC]);
int encuentraPalabra(int validos, int dimC, char palabra[][dimC], char buscarP[]);
int encuentraPalabraOrdenado(int validos, int dimC, char palabra[][dimC], char buscarP[]);


int main()
{
    int dimF = 10;
    int dimC = 30;
    int matriz1[3][3];
    int validos;
    int suma = 0;
    float promedio = 0;
    int dato = 0;
    char buscarP[] = "";
    char palabra[dimF][dimC];

    //cargarMatriz(matriz1);
    //mostrarMatriz(matriz1);

    //cargarMatrizRandom(matriz1);
    //mostrarMatriz(matriz1);
    //suma = sumaMatriz(matriz1);
    //printf("\nLa suma de todos los valores de la matriz es: %d\n", suma);

    //promedio = promedioMatriz(matriz1);
    //printf("El promedio de la suma de los valores es: %f\n", promedio);

    //cargarMatrizRandom(matriz1);
    //printf("Dame el numero a buscar...\n");
    //scanf("%d", &dato);
    //encontrarElemento(matriz1, dato);
    //mostrarMatriz(matriz1);

    validos = cargarPalabras(10, 30, palabra);
    printf("La cantidad de palabra que se agregaron fueron: %d\n", validos);
    mostrarString(validos, dimC, palabra);

    printf("Dame la palabra que quieres buscar\n");
    gets(buscarP);

    int pos = encuentraPalabra(validos, dimC, palabra, buscarP);
    if (pos == -1){
        printf("La palabra Buscada %s No se encuentra en el arreglo!\n", buscarP);
    } else {
        printf("La palabra buscada %s se ecuentra en la posicion n %d del arreglo\n ", buscarP, pos);
    }



    return 0;
}
//Ejercicio 1
void cargarMatriz(int matriz1[3][3]){

    for(int i=0; i < 3; i++){

        for(int j=0; j < 3; j++){

            printf("Dame un numero para ingresarlo a la matriz \n");
            scanf("%d", &matriz1[i][j]);
        }
    }
}
//Ejercicio 2
void mostrarMatriz(int matriz1[3][3]){

    for(int i=0; i < 3; i++){
            printf("\n");
        for(int j=0; j < 3; j++){
            printf("|%02d|", matriz1[i][j]);
        }
    }
}
//Ejercicio 3
void cargarMatrizRandom(int matriz1[3][3]){

    srand(time(NULL));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matriz1[i][j] = rand()%50+1;
        }
    }
}
//Ejercicio 4
int sumaMatriz(int matriz[3][3]){

        int suma=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                suma = suma + matriz[i][j];
            }
        }
        return suma;
}
//Ejercicio 5
float promedioMatriz(int matriz1[3][3]){

    int suma = sumaMatriz(matriz1);
    float promedio = (float) suma / 9.0;
    return promedio;
}
//Ejercicio 6
void encontrarElemento(int matriz1[3][3], int dato){

    int flag = 0;
    int aux;

    for(int i=0; i<3 && flag == 0; i++){
        for(int j=0; j<3 && flag == 0; j++){
            aux = matriz1[i][j];
            if(dato == aux){
                    printf("Se econtro su numero en la posicion [%d][%d]\n", i, j);
                flag = 1;
            }
        }
    }
    if(flag == 0){
        printf("No se econtro su numero\n");
    }
}
//Ejercicio 7
int cargarPalabras(int dimF, int dimC, char palabra[dimF][dimC]){

    int f = 0;
    char opcion = 's';

    while(f < dimF && opcion == 's' ){

        printf("Ingrese una palabra para cargar a la matriz? \n");
        gets(palabra[f]);
        fflush(stdin);

        printf("\nDesea seguir cargandos palabras ? presione s o n \n");
        scanf(" %c", &opcion);
        while (getchar() != '\n');

        f++;
    }

    return f;
}
//Ejercicio 8
void mostrarString(int validos, int dimC, char palabra[][dimC]){


    for(int i=0; i < validos; i++){
        printf("palabra %d: %s\n", i+1, palabra[i]);
    }
}
//Ejercicio 9
int encuentraPalabra(int validos, int dimC, char palabra[][dimC], char buscarP[]){

    int pos = -1;
    int indFilas = 0;

    while ((indFilas < validos) && (pos == -1)){
        if(strcmpi (buscarP, palabra[indFilas]) == 0){

                pos = indFilas;
           }
           indFilas ++;
    }
    return pos;
}
//Ejercicio 10
int encuentraPalabraOrdenado(int validos, int dimC, char palabra[][dimC], char buscarP[]){

    int pos = -1;
    int indFilas = 0;

    while ((indFilas < validos) && (pos == -1) && strcmpi (buscarP, palabra[indFilas]) == 0){
        if(strcmpi (buscarP, palabra[indFilas]) == 0){

                pos = indFilas;
           }
           indFilas ++;
    }
    return pos;
}
//Ejercicio 11
void ordenarAlfabet()


