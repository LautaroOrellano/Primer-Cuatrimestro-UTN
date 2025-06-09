///Lautaro Orellano comision 14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idPiloto;
    char apellido[30];
    char equipo[30];
    float estatura;
    float peso;
    int tieneAuto; //1 o 0
} stPiloto;

typedef struct
{
    int idAuto;
    int idPiloto;
    char equipo[30];
    int velocidadMaxima;
    double tiempo0a100;
    float peso;
} stAuto;

//--------------PROTOTIPADO-----------
void mostrarUnAuto(stAuto aux);
void calculoDeDimencion(FILE *arch, stAuto aux, int *dimension);
stAuto* cargarArregloAutos(char archivoAutos[], int *dimension);
void mostrarArregloAutosSinPiloto(stAuto *arregloAutosSinPilotosMain, int dimension);

//------------------------------------
int main()
{
    char archivoAutos[] = "autos.bin";
    char archivoPilotos[] = "pilotos.bin";
    int dimension = 0;
    stAuto *arregloAutosSinPilotosMain = NULL;

    ///Ejercico1
    arregloAutosSinPilotosMain = cargarArregloAutos(archivoAutos, &dimension);
    mostrarArregloAutosSinPiloto(arregloAutosSinPilotosMain, dimension);
    return 0;
}


///1. Pasar a un arreglo dinámico de tamaño justo todos los autos sin piloto asignado
///(idPiloto==-1) y mostrarlo por pantalla. Modularizar el cálculo de la dimensión.
///Auto* cargarArregloAutos(char nombreArchivo[], int dimension)

void mostrarUnAuto(stAuto aux){

    printf("ID auto: %d \n", aux.idAuto);
    printf("ID piloto: %d \n", aux.idPiloto);
    printf("Equipo: %s \n", aux.equipo);
    printf("Velocidad Maxima: %d \n", aux.velocidadMaxima);
    printf("Tiempo 0 a 100: %lf \n", aux.tiempo0a100);
    printf("Peso: %f \n\n", aux.peso);

}
void calculoDeDimencion(FILE *arch, stAuto aux, int *dimension){
    *dimension = 0;

    while(fread(&aux, sizeof(stAuto), 1, arch) > 0){

        if(aux.idPiloto == -1){
            (*dimension)++;
        }
    }
}


stAuto* cargarArregloAutos(char archivoAutos[], int *dimension){

    FILE* arch = fopen(archivoAutos, "rb");
    stAuto * arregloAutosSinPilotos = NULL;
    stAuto aux;
    int i = 0;

    if(arch!=NULL){

        calculoDeDimencion(arch, aux, dimension);

        arregloAutosSinPilotos = (stAuto*) malloc(sizeof(stAuto) * (*dimension));

        fseek(arch, 0, SEEK_SET);

        while(fread(&aux, sizeof(stAuto), 1, arch) > 0 && i < *dimension){

            if(aux.idPiloto == -1){
                arregloAutosSinPilotos[i] = aux;
                i++;
            }

        }

        fclose(arch);
    } else {
        printf("El archivo no se pudo abrir correctamente.");
    }
    return arregloAutosSinPilotos;
}

void mostrarArregloAutosSinPiloto(stAuto *arregloAutosSinPilotosMain, int dimension){

    for(int i=0; i<dimension; i++){

        mostrarUnAuto(arregloAutosSinPilotosMain[i]);
    }
}


//2. Pasar a un arreglo dinámico todos los pilotos sin auto asignado y mostrarlo por
//pantalla. El arreglo debe redimensionarse cuando sea necesario. De no poder
//resolver el ejercicio usando realloc, se podrá crear un arreglo de tamaño justo, pero
//el ejercicio tendrá la mitad del puntaje.
//Piloto* cargarArregloPilotos(char nombreArchivo[], int* validos)




//3. Buscar el ID del auto con menor tiempo 0 a 100 en el arreglo y retornarlo.
//int menorTiempo0a100(Auto* arreglo, int dimension)


//4. Asignar un piloto al auto obtenido en el ejercicio anterior. Tanto el auto como el
//piloto deben pertenecer al mismo equipo.
//Auto asignarPiloto(Piloto* arrPilotos, int dimPilotos, Auto* arrAutos, int dimAutos, int
//idAutoBuscado)


//5. Modificar el registro del auto del punto anterior en el archivo.
//void modificarAutoEnArchivo(char nombreArchivo[], Auto autoModificado)


//6. Hacer una función recursiva que calcule la velocidad promedio del arreglo de
//autos (campo velocidadMaxima).
//float calcularVelocidadPromedio(Auto* arreglo, int dimension, int sumatoria, int i)

//7. Pasar los autos del arreglo a dos archivos según el resultado de la función
//anterior (velocidad mayor al promedio y menor al promedio).
//void escribirArchivosPorVelocidad(char archivoSobrePromedio[], char
//archivoDebajoPromedio[], Auto* arreglo, int dimension, float promedio)

//8. Invocar funciones en main() para demostrar el funcionamiento del programa.
//Crear las variables y constantes que se consideren necesarias
