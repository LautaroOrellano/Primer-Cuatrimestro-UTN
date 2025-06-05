#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20

typedef struct {

    int idLibro;
    char titulo[50];
    char autor[50];
    char isbn[20];
    int anioPublicacion;
    int idCategoria;
} stLibro;

typedef struct {

    int idCategoria;
    int cantidadLibros;
    char nombreCategoria[30];
    int capacidad;
} stCategoria;


//------------Prototipado----------
void limpiarString(char string[]);
void mostrarUnLibro(stLibro newLibro);
void leerArchivoLibro(char archivoLibro[]);
stLibro* buscarLibroPorAutor(char archivoLibro[], char nombreAutor[], int *cantidadEncontrados);
void mostrarArregloLibroXAutor(stLibro *librosXAutor, int cantidadEncontrados);



//---------------------------------

int main()
{
    char archivoCateg[] = "categorias.bin";
    char archivoLibro[] = "libros.bin";
    stLibro *librosXAutor = NULL;
    char nombreAutor[DIM];
    int cantidadEncontrados = 0;

    ///Ejercicio1

    leerArchivoLibro(archivoLibro);

    printf("Ingrese el nombre del auto a buscar \n");
    fgets(nombreAutor, DIM, stdin);
    limpiarString(nombreAutor);

    printf("Autor: %s", nombreAutor);

    librosXAutor = buscarLibroPorAutor(archivoLibro, nombreAutor, &cantidadEncontrados);
    mostrarArregloLibroXAutor(librosXAutor, cantidadEncontrados);


    free(librosXAutor);
    return 0;
}

void limpiarString(char string[]){
    int posicion = strcspn(string, "\n");
    string[posicion] = '\0';
}

void mostrarUnLibro(stLibro newLibro){

    printf("ID: %d \n", newLibro.idLibro);
    printf("Titulo: %s \n", newLibro.titulo);
    printf("Autor: %s \n", newLibro.autor);
    printf("Isbn: %s \n", newLibro.isbn);
    printf("Año publicacion: %d \n", newLibro.anioPublicacion);
    printf("ID categoria: %d \n\n", newLibro.idCategoria);

}

void leerArchivoLibro(char archivoLibro[]){

    FILE *arch = fopen(archivoLibro, "rb");
    stLibro aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            mostrarUnLibro(aux);
        }

        fclose(arch);

    } else {
        printf("El archivo no se pudo leer. \n");
    }
}

///Ejercicio1

stLibro* buscarLibroPorAutor(char archivoLibro[], char nombreAutor[], int *cantidadEncontrados){

    FILE* arch = fopen(archivoLibro,"rb");
    stLibro aux;
    stLibro *arregloLibrosDeAutor = NULL;
    int i = 0;
    int cont = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            if(strcmpi(aux.autor, nombreAutor) == 0){
                cont++;
            }
        }

        if(cont > 0){
            arregloLibrosDeAutor = (stLibro*) malloc(sizeof(stLibro)*cont);
        }

        fseek(arch, 0, SEEK_SET);

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            if(strcmpi(aux.autor, nombreAutor) == 0){

                 arregloLibrosDeAutor[i] = aux;
                 i++;
            }
        }

        fclose(arch);
    } else {
        printf("El archivo no se pudo leer. \n");
    }

    *cantidadEncontrados = cont;

    printf("Cantidad de libros encontrados: %d \n\n", *cantidadEncontrados);

    return arregloLibrosDeAutor;
}

void mostrarArregloLibroXAutor(stLibro *librosXAutor, int cantidadEncontrados){

    for(int i=0; i<cantidadEncontrados; i++){

        mostrarUnLibro(librosXAutor[i]);
    }
}

///Ejercicio2

void eliminarLibroPorISBN

