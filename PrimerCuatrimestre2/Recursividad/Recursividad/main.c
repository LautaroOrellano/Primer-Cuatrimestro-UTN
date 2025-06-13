#include <stdio.h>
#include <stdlib.h>

//-----------------------Prototipado----------------------
int factorialNumer(int n0);
int potenciaNum(int n, int p);
int recorrerArreglo(int arreglo[], int i, int dimension);
int recorrerArregloInvertido(int arreglo[], int i, int dimension);
int arregloCapicua(int arregloCap[], int indice, int dimension1);
int sumarElementosDeUnArreglo(int arregloParaSumar[], int dimension2, int suma, int indice1);
int menorElementoDelArreglo(int arregloParaBuscarMenor[], int dimension3, int menorElemento, int indice2);
void crearArchivo(char archivo[]);
void leerArchivo(char archivo[]);
//--------------------------------------------------------

int main()
{

    ///Ejercicio1
    int n0 = 5;
    int nro = factorialNumer(n0);

    printf("Factorial de %d: %d \n", n0, nro);

    system("pause");
    system("cls");

    ///Ejrcicio2

    int p = 2;
    int n = 5;
    int nro2 = potenciaNum(n,p);
    printf("%d a la %d: %d \n", n, p, nro2);

    system("pause");
    system("cls");

    ///Ejercicio3

    int arreglo[] = {10,20,30};
    int i = 0;
    int dimension = 3;

    printf("ARREGLO: \n");
    int retorno = recorrerArreglo(arreglo, i, dimension);

    system("pause");
    system("cls");

    ///Ejercicio4

    printf("ARREGLO INVERTIDO: \n");
    int retorno1 = recorrerArregloInvertido(arreglo, i, dimension);

    system("pause");
    system("cls");

    ///Ejercicio5

    int arregloCap[] = {1,2,3,2,1};
    int indice = 0;
    int dimension1 = 5;

    int condicionDeArreglo = arregloCapicua(arregloCap, indice, dimension1);

    if(condicionDeArreglo == 0){

        printf("El arreglo no es capicua \n");
    } else {
        printf("El arreglo si era capicua \n");
    }

    system("pause");
    system("cls");

    ///Ejercicio6

    int arregloParaSumar[] = {10, 10, 10, 30, 40};
    int dimension2 = 5;
    int indice1 = 0;
    int suma = 0;

    int sumaTotal = sumarElementosDeUnArreglo(arregloParaSumar, dimension2, suma, indice1);

    printf("La suma total del arreglo es: %d \n", sumaTotal);

    system("pause");
    system("cls");

    ///Ejercicio7

    int arregloParaBuscarMenor[] = {48,6,3,43,2,45,56};
    int dimension3 = 7;
    int indice2 = 0;
    int menorElemento = arregloParaBuscarMenor[0];
    int menorEncontrado = menorElementoDelArreglo(arregloParaBuscarMenor, dimension3, menorElemento, indice2);

    printf("El menor elemento del arreglo es: %d \n", menorEncontrado);

    system("pause");
    system("cls");

    ///Ejercicio8
    char archivo[] = "archivo.bin";

    //crearArchivo(archivo);
    printf("Contenido Archivo: \n\n");
    leerArchivo(archivo);

    system("pause");
    system("cls");

    return 0;
}

int factorialNumer(int n0){

    if(n0 == 0){

        return 1;

    } else {

        return n0 * factorialNumer(n0-1);
    }
}

int potenciaNum(int n, int p){

    if(p == 0){

        return 1;

    } else {
        return n * potenciaNum(n, p-1);
    }
}

int recorrerArreglo(int arreglo[], int i, int dimension){

    if(i >= dimension){

        return 1;

    } else {
        printf("%d ", arreglo[i]);
        return recorrerArreglo(arreglo, i+1, dimension);
    }
}

int recorrerArregloInvertido(int arreglo[], int i, int dimension){

    if(i == dimension){

        return 1;

    } else {
        printf("%d ", arreglo[dimension-1]);
        return recorrerArregloInvertido(arreglo, i, dimension-1);
    }
}

int arregloCapicua(int arregloCap[], int indice, int dimension1){

    if(indice >= dimension1){

        return 1;

    }

    if(arregloCap[indice] != arregloCap[dimension1-1]) {

        return 0;

    } else

    return arregloCapicua(arregloCap, indice+1, dimension1-1);
}

int sumarElementosDeUnArreglo(int arregloParaSumar[], int dimension2, int suma, int indice1){

    if(indice1 >= dimension2){

        return 0;
    } else {

        suma = arregloParaSumar[indice1] + sumarElementosDeUnArreglo(arregloParaSumar, dimension2, suma, indice1+1);
        return suma;
    }
}

int menorElementoDelArreglo(int arregloParaBuscarMenor[], int dimension3, int menorElemento, int indice2){

    if(indice2 >= dimension3){

        return menorElemento;
    }

    if(menorElemento > arregloParaBuscarMenor[indice2+1]){

        menorElemento = arregloParaBuscarMenor[indice2+1];

        return menorElementoDelArreglo(arregloParaBuscarMenor, dimension3, menorElemento, indice2 + 1);

    } else {

        return menorElementoDelArreglo(arregloParaBuscarMenor, dimension3, menorElemento, indice2 + 1);
    }

}

void crearArchivo(char archivo[]){

    FILE* arch = fopen(archivo, "wb");

    if(arch != NULL){

        for(int i=0; i<10; i++){

            fwrite(&i, sizeof(int), 1, arch);
        }

        fclose(arch);
    } else {
        printf("Error al abrir el archivo. \n");
    }
}

void leerArchivo(char archivo[]){

    FILE* arch = fopen(archivo, "rb");
    int aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(int), 1, arch) > 0){

            printf("%d ", aux);
        }

        fclose(arch);
    } else {
        printf("Error al abrir el archivo. \n");
    }
}
