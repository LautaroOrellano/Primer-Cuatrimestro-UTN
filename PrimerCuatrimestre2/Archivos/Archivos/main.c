#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"


#define DIM 30

typedef struct{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio; //año que cursa
} stAlumno;

//Prototipado
///Ejercicio1
void agregarElementoAlArchivo(char nombreArchivo[]);
///Ejercicio2
void mostrarContenidoArchivo(char nombreArchivo[]);
///Ejercicio3
int contarRegistrosEnArchivo(char nombreArchivo[]);
///Ejercicio4
void cargarArchivoAlumno(char nombreArchivo1[]);
///Ejercicio5
stAlumno cargarUnAlumno();
void guardarAlumnoArchivo(stAlumno newAlumno, FILE* arch);
void mostrarRegistroArchivo(char nombreArchivo1[]);
///Ejercicio6
void agregarNuevoDatos(char nombreArchivo1[]);
///Ejercicio7
void pasarApilaLegajos(char nombreArchivo1[], Pila *mayores);
///Ejercicio8
int cantidadAlumnosMayoresA(char nombreArchivo1[], int edadUsuario);
///Ejercicio9
void mostrarNombreXedades(char nombreArchivo1[], int edadRango1, int edadRango2);
///Ejericio10
void mostrarAlumnoMayorEdad(char nombreArchivo1[]);
void mostrarUnAlumno(stAlumno aux);
///Ejercicio11
int anioDeCursada(char nombreArchivo1[], int anioCursada);


int main()
{
    /**
    char nombreArchivo[] = "archivo.bin";
    ///Ejercicio1
    agregarElementoAlArchivo(nombreArchivo);

    ///Ejercicio2
    mostrarContenidoArchivo(nombreArchivo);

    ///Ejercicio3
    int contador;
    contador = contarRegistrosEnArchivo(nombreArchivo);
    printf("\n");
    printf("La cantidad de registros que tiene el archivo es de: %d\n", contador);
    */

    ///Ejercicio4
    char nombreArchivo1[] = "archivoAlumno.bin";
    stAlumno newAlumno[DIM];
    cargarArchivoAlumno(nombreArchivo1);

    ///Ejercicio5
    mostrarRegistroArchivo(nombreArchivo1);

    ///Ejercicio6
    agregarNuevoDatos(nombreArchivo1);
    mostrarRegistroArchivo(nombreArchivo1);

    ///Ejercicio7
    Pila mayores;
    inicpila(&mayores);
    pasarApilaLegajos(nombreArchivo1, &mayores);
    mostrar(&mayores);

    ///Ejercicio8
    int edadUsuario;
    int totalAlumMayores;
    getchar();
    printf("Alumnos mayores a que edad desea buscar?: ");
    scanf("%d", &edadUsuario);
    totalAlumMayores = cantidadAlumnosMayoresA(nombreArchivo1, edadUsuario);
    printf("\n");
    printf("La cantidad de alumnos mayores a %d, es de %d\n", edadUsuario, totalAlumMayores);


    ///Ejercicio9
    int edadRango1, edadRango2;
    printf("Edad del primer rango a buscar\n");
    fflush(stdin);
    scanf("%d", &edadRango1);
    printf("\n");
    printf("Edad del segundo rango a buscar\n");
    fflush(stdin);
    scanf("%d", &edadRango2);
    mostrarNombreXedades(nombreArchivo1, edadRango1, edadRango2);

    ///Ejercicio10
    mostrarAlumnoMayorEdad(nombreArchivo1);

    ///Ejercicio11
    int anioCursada;
    int totalAlumnosXanioCursada;
    printf("Alumnos con cuantos años de cursada desea buscar?");
    fflush(stdin);
    scanf("%d", &anioCursada);
    totalAlumnosXanioCursada = anioDeCursada(nombreArchivo1, anioCursada);
    printf("Los Alumnos con %d años de cursa son: %d", anioCursada, totalAlumnosXanioCursada);

    ///Ejercicio12
    stAlumno vectorAlumnos[DIM];

    return 0;
}

///Ejercicio1
void agregarElementoAlArchivo(char nombreArchivo[]){

    FILE* arch = fopen(nombreArchivo, "wb");
    char texto[ ] = "Prueba de escritura";
    int cant, longit;

    if(arch != NULL){
        longit = strlen(texto);
        cant = fwrite(texto, sizeof(char), longit, arch);

        if (cant < longit){
            printf("Error al escribir el archivo \n");
        } else {
            printf("Se escribieron %d caracteres \n", cant);
            printf("\n");
        }
        fclose(arch);
    } else {
        printf("El archivo no se pudo abrir. \n");
    }
}

///Ejercicio2
void mostrarContenidoArchivo(char nombreArchivo[]){

    FILE* arch = fopen(nombreArchivo, "rb");
    char caracter;

    if(arch != NULL){
        printf("Contenido del archivo:\n");
        printf("\n");
        while (fread(&caracter, sizeof(char), 1, arch) == 1){
            printf("%c", caracter);
        }
        fclose(arch);

    } else {
        printf("El archivo no se pudo leer");
    }
}

///Ejercicio3
int contarRegistrosEnArchivo(char nombreArchivo[]){

    FILE* arch = fopen(nombreArchivo, "rb");

    int cont = 0;
    char aux[50];

    if (arch != NULL){

        while(fread(aux, sizeof(char), 19, arch) == 19){
            cont++;
        }
    }
    fclose(arch);

    return cont;
}

///Ejercicio4
stAlumno cargarUnAlumno(){

    stAlumno newAlumno;

    printf("Ingrese el num de legajo: ");
    scanf("%d", &newAlumno.legajo);
    while ((getchar()) != '\n');

    printf("Ingrese el nombre y apellido: ");
    fgets(newAlumno.nombreYapellido, sizeof(newAlumno.nombreYapellido), stdin);

    size_t len = strlen(newAlumno.nombreYapellido);
    if (len > 0 && newAlumno.nombreYapellido[len - 1] == '\n') {
        newAlumno.nombreYapellido[len - 1] = '\0';
    }

    printf("Ingrese la edad: ");
    scanf("%d", &newAlumno.edad);
    while ((getchar()) != '\n');

    printf("Años cursados: ");
    scanf("%d", &newAlumno.anio);
    while ((getchar()) != '\n');

    return newAlumno;
}

void guardarAlumnoArchivo(stAlumno newAlumno, FILE* arch){
    fwrite(&newAlumno, sizeof(stAlumno), 1, arch);
}

void cargarArchivoAlumno(char nombreArchivo1[]){
    /**
    FILE* archi = fopen(nombreArchivo1, "rb");

    if(archi == NULL){
        archi = fopen(nombreArchivo1,"wb");
        if(archi != NULL){
            printf("Se crea por primera vez el archivo \n");
            printf("\n");
            char entrada[30];

            for(int i=0; i<2; i++){
                printf("Ingrese el num de legajo del alumno %d: ", i + 1);
                fflush(stdin);
                scanf("%d", &newAlumno[i].legajo);
                while ((getchar()) != '\n');

                printf("Ingrese el nombre y el apellido del alumno %d: ", i + 1);
                fgets(newAlumno[i].nombreYapellido, sizeof(newAlumno[i].nombreYapellido), stdin);

                size_t len = strlen(newAlumno[i].nombreYapellido);
                if (len > 0 && newAlumno[i].nombreYapellido[len - 1] == '\n') {
                newAlumno[i].nombreYapellido[len - 1] = '\0';
                }

                printf("Ingrese la edad del alumno %d: ", i + 1);
                fflush(stdin);
                scanf("%d", &newAlumno[i].edad);
                while ((getchar()) != '\n');

                printf("Ingrese el año de cursada del alumno %d: ", i + 1);
                fflush(stdin);
                scanf("%d", &newAlumno[i].anio);
                while ((getchar()) != '\n');

                printf("\n");

                fwrite(&newAlumno[i], sizeof(stAlumno), 1, archi);
            }

        } else {
            printf("No se puede crear el archivo \n");
        }
    } else {
        printf("El elemento ya existia, no se cargo.");
    }
    fclose(archi);
}*/

    FILE* archi = fopen(nombreArchivo1, "rb");

    if(archi == NULL){
        archi = fopen(nombreArchivo1,"wb");
        if(archi != NULL){
            printf("Se crea por primera vez el archivo \n");
            printf("\n");

            for(int i=0; i< 5; i++){
                stAlumno newAlumno = cargarUnAlumno();
                guardarAlumnoArchivo(newAlumno, archi);
                printf("\n");
            }
         } else {
            printf("No se puede crear el archivo.\n");
        }
    } else {
        printf("El elemento ya existe. \n");
        printf("\n");
    }
    fclose(archi);
}

///Ejercicio5
void mostrarRegistroArchivo(char nombreArchivo1[]){

    FILE* arch = fopen(nombreArchivo1, "rb");
    stAlumno aux;

    if(arch != NULL){
        printf("Contenido del archivo:\n");
        printf("\n");

        while(fread(&aux, sizeof(stAlumno), 1, arch) == 1){
            printf("Legajo: %d\n", aux.legajo);
            printf("Nombre y Apellido: %s \n", aux.nombreYapellido);
            printf("edad: %d\n", aux.edad);
            printf("Año lectivo: %d\n", aux.anio);
            printf("-----------------------\n");
        }
    } else {
        printf("Error al intentar abrir el archivo");
    }
    fclose(arch);
}

///Ejercicio6
void agregarNuevoDatos(char nombreArchivo1[]){

    FILE* arch = fopen(nombreArchivo1, "ab");
    stAlumno aux;
    char opcion = 's';

    if(arch != NULL){

        printf("Desea cargar un alumno nuevo (s-n)?: ");
        scanf("%c", &opcion);

        printf("\n");
        while(opcion == 's'){

            printf("Ingrese el num de legajo: ");
            scanf("%d", &aux.legajo);
            while ((getchar()) != '\n');

            printf("Ingrese el nombre y apellido: ");
            fgets(aux.nombreYapellido, sizeof(aux.nombreYapellido), stdin);

            size_t len = strlen(aux.nombreYapellido);
            if (len > 0 && aux.nombreYapellido[len - 1] == '\n') {
            aux.nombreYapellido[len - 1] = '\0';
            }

            printf("Ingrese la edad: ");
            scanf("%d", &aux.edad);
            while ((getchar()) != '\n');

            printf("Años cursados: ");
            scanf("%d", &aux.anio);
            while ((getchar()) != '\n');

            fwrite(&aux, sizeof(stAlumno), 1, arch);

            printf("Desea cargar otro alumno (s-n)?");
            scanf("%c", &opcion);
        }

    } else {
        printf("Error al cargar el archivo");
    }
    fclose(arch);
}

///Ejercicio7
void pasarApilaLegajos(char nombreArchivo1[], Pila *mayores){

    FILE* arch = fopen(nombreArchivo1, "rb");
    stAlumno aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAlumno),1,arch) > 0){
            if(aux.edad > 18){
                apilar(mayores, aux.edad);
            }
        }

    } else {
        printf("Error al leer el archivo...\n");
    }
}

///Ejercicio8
int cantidadAlumnosMayoresA(char nombreArchivo1[], int edadUsuario){

    FILE *arch = fopen(nombreArchivo1, "rb");
    stAlumno aux;
    int cont = 0;

    if(arch != NULL){

        while(fread(&aux,sizeof(stAlumno),1,arch) > 0){
            if(aux.edad >= edadUsuario){
                cont++;
            }
        }
    } else {
        printf("El archivo esta corrupto o no se pudo leer \n");
    }
    fclose(arch);
    return cont;
}

///Ejercicio9
void mostrarNombreXedades(char nombreArchivo1[], int edadRango1, int edadRango2){

    FILE *arch = fopen(nombreArchivo1, "rb");
    stAlumno aux;

    if(arch != NULL){

        printf("Los alumnos en ese rango son: \n");
        while(fread(&aux, sizeof(stAlumno), 1, arch) > 0){
                if((aux.edad >= edadRango1 && aux.edad <= edadRango2) || (aux.edad <= edadRango1 && aux.edad >= edadRango2)){
                    printf("%s\n", aux.nombreYapellido);
                }

        }
    } else {
        printf("El arhivo esta corrupto o no se pudo leer.");
    }
    fclose(arch);
}

///Ejercicio10
void mostrarAlumnoMayorEdad(char nombreArchivo1[]){

    FILE *arch = fopen(nombreArchivo1, "rb");
    stAlumno aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAlumno), 1, arch) > 0){
            int edadMayor = aux.edad;
            if(aux.edad > edadMayor){
                edadMayor = aux.edad;
            }
        }
        printf("\n");
        printf("El alumno con mayor edad es: \n");
        mostrarUnAlumno(aux);
    } else {
        printf("Archivo corrupto o imposible de leer.");

    }
    fclose(arch);
}

void mostrarUnAlumno(stAlumno aux){

    printf("-----------------------\n");
    printf("Legajo: %d\n", aux.legajo);
    printf("Nombre y Apellido: %s \n", aux.nombreYapellido);
    printf("edad: %d\n", aux.edad);
    printf("Año lectivo: %d\n", aux.anio);
    printf("-----------------------\n");
}

///Ejercicio11
int anioDeCursada(char nombreArchivo1[], int anioCursada){

    FILE *arch = fopen(nombreArchivo1, "rb");
    stAlumno aux;
    int cont = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stAlumno), 1, arch) > 0){

            if(aux.anio == anioCursada){
                cont++;
            }
        }
    } else {
        printf("Archivo corrupto o imposible de leer.");
    }
    fclose(arch);
    return cont;
}

///Ejercicio12
void copiaDeArchivo(char nombreArchivo1[], stAlumno vectorAlumnos[DIM]){

    FILE *arch = fopen(nombreArchivo1, "rb");

}
