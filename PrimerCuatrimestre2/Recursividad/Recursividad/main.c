#include <stdio.h>
#include <stdlib.h>

//Prototipado
int recursividadFactorial(int num);
int recursividadPotencia(int numP, int potencia);
void mostrarArregloFormaRecursiva(int arreglo[],int i, int validos);
void mostrarArregloFormaRecursivaAlrevez(int arreglo[],int i, int validos);
int palabraCapicua(int numero[] , int i, int j);

int main()
{
    ///Ejercicio1

    //int num, rta;
    //printf("Numero para el factorial: \n");
    //fflush(stdin);
    //scanf("%d", &num);

    //rta = recursividadFactorial(num);
    //printf("factorial de %d: %d\n", num, rta);

    ///Ejercicio2

    //int numP, potencia, rta2;
    //printf("Numero para potenciar: \n");
    //fflush(stdin);
    //scanf("%d", &numP);

    //printf("\n");

    //printf("Numero de potencia: \n");
    //fflush(stdin);
    //scanf("%d", &potencia);

    //rta2 = recursividadPotencia(numP, potencia);
    //printf("potencia de %d a la %d: %d\n", numP, potencia, rta2);

    ///Ejercicio3

    int arreglo[] = {1,2,3,4};
    int validos = 4;
    int i = 0;
    mostrarArregloFormaRecursiva(arreglo, i, validos);
    printf("\n");

    ///Ejercicio4

    mostrarArregloFormaRecursivaAlrevez(arreglo, i, validos);

    ///Ejercicio5
    int numero[]= {3, 5, 9, 4, 3};
    int retorno = 0;

    retorno = palabraCapicua(numero, 0, 4);

    if(retorno == 0){
        printf("El numero no es capicua \n");
    } else {
        printf("El numero es capicua \n");
    }

    ///Ejercicio6





    return 0;
}

int recursividadFactorial(int num){

    int rta;

    if(num == 0){

        rta = 1;

    } else {
        rta = num * recursividadFactorial(num-1);
    }

    return rta;
}

int recursividadPotencia(int numP, int potencia){

    int rta = 0;

    if(potencia == 0){

        rta = 1;

    } else {
        rta = numP * recursividadPotencia(numP, potencia-1);
    }

    return rta;
}

void mostrarArregloFormaRecursiva(int arreglo[], int i, int validos){

    if(i < validos){

        printf("%d", arreglo[i]);

       mostrarArregloFormaRecursiva(arreglo, i+1, validos);
    }
}

void mostrarArregloFormaRecursivaAlrevez(int arreglo[], int i, int validos){


    if(i < validos){

        mostrarArregloFormaRecursivaAlrevez(arreglo, i+1, validos);
        printf("%d", arreglo[i]);
    }
}

int palabraCapicua(int numero[] ,int i, int j){

    if(i >= j){

        return 1;
    }
    if (numero[i] != numero[j]){

        return 0;
    }

    return palabraCapicua(numero, i+1, j-1);
}

int sumaRecursiva(int numero[], int i, int validos){

    int = rta;

    if(i < validos-1){

        rta = num[i];

    } else {
        rta = numero[i] + sumaRecursiva(numero, i+1, validos);
    }

   return rta;
}
