#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipado
int valorRandom();
int obtenerValores(int, int, int);
int sumaMenores(int);
int tablaMultiplicar(int);
float calcuSuma(float, float);
float calcuResta(float, float);
float calcuMultipli(float, float);
float calcuDivicion(float, float);
void cambioSigno(int *num1);
void dentroFuncion(int *num1, int *num2);

int main()
{
   //Ejercicio1

   int numeroAzar = valorRandom();
   printf("Numero random: %d\n", numeroAzar);


   //Ejercicio2

    int num1;
    int num2;
    int num3;
    float num1_float;
    float num2_float;
    int opcion;

    printf("Dame el primer valor a comparar: \n");
    fflush(stdin);
    scanf("%d", &num1);

    printf("Dame el segundo valor a comparar: \n");
    fflush(stdin);
    scanf("%d", &num2);

    printf("Dame el tercer valor a comparar: \n");
    fflush(stdin);
    scanf("%d", &num3);

    int valorAlto = obtenerValores(num1, num2, num3);

    printf("El valor mas alto es: %d\n", valorAlto);


    //Ejercicio3

    printf("Dame un valor para calcular la suma de sus menores: \n");
    fflush(stdin);
    scanf("%d", &num1);

    int sumaMrs = sumaMenores(num1);

    printf("La suma de los menoes positvos de ese numero es: %d\n", sumaMrs);


    //Ejercicio4

    printf("Dame un numero para mostrarte la tabla de multiplicacion del mismo: \n");
    fflush(stdin);
    scanf("%d", &num1);

    int tablaMul = tablaMultiplicar(num1);

    printf("%d\n", tablaMul);


    //Ejercicio5

    printf("Selecciona una opcion: \n");
    printf("1 para calcular una suma \n");
    printf("2 para calcular una resta \n");
    printf("3 para calcular una multiplicacion \n");
    printf("4 para calcular una division \n");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion){

        case 1:
            printf("Dame el primer numero para sumar: \n");
            fflush(stdin);
            scanf("%f", &num1_float);

            printf("Dame el segundo numero para sumar: \n");
            fflush(stdin);
            scanf("%f", &num2_float);

            float suma = calcuSuma(num1_float, num2_float);

            printf("La suma es: %.2f\n", suma);
            break;

        case 2:
            printf("Dame el primer numero para restar: \n");
            fflush(stdin);
            scanf("%f", &num1_float);

            printf("Dame el segundo numero para restar: \n");
            fflush(stdin);
            scanf("%f", &num2_float);

            float resta = calcuResta(num1_float, num2_float);

            printf("La suma es: %.2f\n", resta);
            break;

        case 3:
            printf("Dame el primer numero para multiplicar: \n");
            fflush(stdin);
            scanf("%f", &num1_float);

            printf("Dame el segundo numero para multiplicar: \n");
            fflush(stdin);
            scanf("%f", &num2_float);

            float multiplicacion = calcuMultipli(num1_float, num2_float);

            printf("La suma es: %.2f\n", multiplicacion);
            break;


        case 4:
            printf("Dame el primer numero para dividir: \n");
            fflush(stdin);
            scanf("%f", &num1_float);

            printf("Dame el segundo numero para dividir: \n");
            fflush(stdin);
            scanf("%f", &num2_float);

            float divicion = calcuDivicion(num1_float, num2_float);

            printf("La suma es: %.2f\n", divicion);
            break;


        default:
            printf("Opcion no valida. \n");
    }


    //Ejercicio6

    printf("Dame un numero entero para cambiarle el signo: \n");
    fflush(stdin);
    scanf("%d", &num1);

    cambioSigno(&num1);

    printf("Cambiando signo....%d\n", num1);


    //Ejercicio7

    printf("Cargue el primer numero dentro de la funcion: \n");
    fflush(stdin);
    scanf("%d", &num1);

    printf("Cargue el segundo numero dentro de la funcion: \n");
    fflush(stdin);
    scanf("%d", &num2);

    dentroFuncion(&num1, &num2);

}

int valorRandom(){

    srand(time(NULL));
    int random = rand()%100;

    return random;

}

int obtenerValores(int num1, int num2, int num3){

    if(num1 >= num2 && num1 >= num3){
        return num1;
    } else if(num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }
}

int sumaMenores(int num1){

    int sum;
    int acum;
    for(int i = 0; i<num1; i++){
            acum = acum + 1;
            sum = sum + acum;
    }
    num1 = sum;

    return num1;
}

int tablaMultiplicar(int num1){
    int resultado;
    for(int i = 0; i<=10; i++){
        resultado = num1 * i;
        printf("%d\n", resultado);
    }


    num1 = resultado;
    return num1;
}

float calcuSuma(float num1, float num2){

    return num1 + num2;
}

float calcuResta(float num1, float num2){

    return num1 - num2;
}

float calcuMultipli(float num1, float num2){

    return num1 * num2;
}

float calcuDivicion(float num1, float num2){

    if(num2 == 0){
        printf("NO SE PUEDE DIVIDIR POR CERO \n");
    } else {
        return num1 / num2;
    }

}

void cambioSigno(int *num1){
    *num1 = -(*num1);
}

void dentroFuncion(int *num1, int *num2){
    printf("Primer numero cargado: %d\n", *num1);
    printf("Segundo numero cargado: %d\n", *num2);
}
