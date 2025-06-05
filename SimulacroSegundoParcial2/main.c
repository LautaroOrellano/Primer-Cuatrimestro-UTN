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
void mostrarUnaCategoria(stCategoria newCategoria);
void mostrarUnLibro(stLibro newLibro);
void leerArchivoLibro(char archivoLibro[]);
void leerArchivoCategoria(char archivoCateg[]);
stLibro* buscarLibroPorAutor(char archivoLibro[], char nombreAutor[], int *cantidadEncontrados);
void mostrarArregloLibroXAutor(stLibro *librosXAutor, int cantidadEncontrados);
void copiarDatosActualizadosLibro(char archivo[], stLibro aux);
void eliminarLibroPorISBN(char archivoLibro[], char nISBN[DIM]);
void listarLibroPorCategoria(char archivoLibro[], int bucarCat);
void actualizarCapacidadCategoria(char archivoCateg[], int idActualCat, int valorCapacidad);
int contarLibroPorAnio(char archivoLibro[], int anioLibro);
void librosPorAutor(char archivoLibro[], char nombreDeAutor[]);
stLibro* cargarArregloLibros(char archivoLibro[], int *validosLibro);
int calcularTotalDeLibroPorCategoria(stLibro *vectorLibro, int *validosLibro, int idCateBuscada, int i);
//---------------------------------

int main()
{
    char archivoCateg[] = "categorias.bin";
    char archivoLibro[] = "libros.bin";
    stLibro *librosXAutor = NULL;
    char nombreAutor[DIM];
    char nombreDeAutor[DIM];
    int cantidadEncontrados = 0;
    char nISBN[DIM];
    int bucarCat = 0;
    int idActualCat = 0;
    int valorCapacidad = 0;
    int anioLibro = 0;
    int cantLibros = 0;
    int *validosLibro = 0;
    int idCateBuscada = 0;
    int i = 0;
    stLibro* vectorLibro = NULL;


    ///Ejercicio1

    leerArchivoLibro(archivoLibro);

    printf("Ingrese el nombre del autor a buscar: \n");
    fgets(nombreAutor, DIM, stdin);
    limpiarString(nombreAutor);
    while(getchar() != '\n');

    librosXAutor = buscarLibroPorAutor(archivoLibro, nombreAutor, &cantidadEncontrados);
    mostrarArregloLibroXAutor(librosXAutor, cantidadEncontrados);

    system("pause");
    system("cls");

    ///Ejercicio2

    /**printf("Ingrese el n de ISBN que desea eliminar");
    fgets(nISBN, DIM, stdin);
    limpiarString(nISBN);

    eliminarLibroPorISBN(archivoLibro, nISBN);
    leerArchivoLibro(archivoLibro);

    system("pause");
    system("cls");*/

    ///Ejercicio3

    printf("Id de la categoria a buscar: ");
    scanf("%d", &bucarCat);
    while(getchar() != '\n');

    listarLibroPorCategoria(archivoLibro, bucarCat);

    system("pause");
    system("cls");

    ///Ejercicio4

    leerArchivoCategoria(archivoCateg);

    printf("Que id categoria queres modificar?: ");
    scanf("%d", &idActualCat);
    while(getchar() != '\n');

    printf("Que cantidad de capacidad queres agregarle?: ");
    scanf("%d", &valorCapacidad);
    while(getchar() != '\n');

    actualizarCapacidadCategoria(archivoCateg, idActualCat,  valorCapacidad);

    leerArchivoCategoria(archivoCateg);

    system("pause");
    system("cls");

    ///Ejercicio5

    /**printf("Que anio de publicacion queres buscar en los libros?: ");
    scanf("%d", &anioLibro);
    while(getchar() != '\n');

    cantLibros = contarLibroPorAnio(archivoLibro, anioLibro);

    printf("La cantidad de libros para esa fecha de publicacion es de: %d \n", cantLibros);

    system("pause");
    system("cls");

    ///Ejercicio6

    printf("Nombre del autor a buscar para crear el archivo txt");
    fgets(nombreDeAutor, DIM, stdin);
    limpiarString(nombreDeAutor);
    while(getchar() != '\n');

    librosPorAutor(archivoLibro, nombreDeAutor);

    system("pause");
    system("cls");*/

    ///Ejercicio7

    vectorLibro = cargarArregloLibros(archivoLibro, validosLibro);

    printf("Que id categoria queres buscar?: ");
    scanf("%d", &idCateBuscada);
    while(getchar() != '\n');

    calcularTotalDeLibroPorCategoria(vectorLibro, validosLibro, idCateBuscada, i);

    system("pause");
    system("cls");

    free(librosXAutor);
    return 0;
}

void limpiarString(char string[]){
    int posicion = strcspn(string, "\n");
    string[posicion] = '\0';
}

void mostrarUnaCategoria(stCategoria newCategoria){

    printf("ID: %d \n", newCategoria.idCategoria);
    printf("Cantidad de libros: %d \n", newCategoria.cantidadLibros);
    printf("Nombre Categoria: %s \n", newCategoria.nombreCategoria);
    printf("Capacidad: %d \n", newCategoria.capacidad);

}

void mostrarUnLibro(stLibro newLibro){

    printf("ID: %d \n", newLibro.idLibro);
    printf("Titulo: %s \n", newLibro.titulo);
    printf("Autor: %s \n", newLibro.autor);
    printf("Isbn: %s \n", newLibro.isbn);
    printf("Año publicacion: %d \n", newLibro.anioPublicacion);
    printf("ID categoria: %d \n\n", newLibro.idCategoria);

}

void leerArchivoCategoria(char archivoCateg[]){

    FILE *arch = fopen(archivoCateg, "rb");
    stCategoria aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stCategoria), 1, arch) > 0){

            mostrarUnaCategoria(aux);
        }

        fclose(arch);

    } else {
        printf("El archivo no se pudo leer. \n");
    }
}

void leerArchivoLibro(char archivoLibro[]){

    FILE *arch = fopen(archivoLibro, "rb");
    stLibro aux;
    int cont = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            mostrarUnLibro(aux);
            cont ++;
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
    printf("\n");

    return arregloLibrosDeAutor;
}

void mostrarArregloLibroXAutor(stLibro *librosXAutor, int cantidadEncontrados){

    for(int i=0; i<cantidadEncontrados; i++){

        mostrarUnLibro(librosXAutor[i]);
    }
}

///Ejercicio2

void eliminarLibroPorISBN(char archivoLibro[], char nISBN[DIM]){

    char archivoLibro1[] = "libros1.bin";

    FILE *arch = fopen(archivoLibro, "rb");
    stLibro aux;

    if(arch != NULL){

            while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

                if(strcmpi(aux.isbn, nISBN) != 0){

                    copiarDatosActualizadosLibro(archivoLibro1, aux);
                }
            }

        fclose(arch);

        remove(archivoLibro);
        rename("libros1.bin", "libros.bin");
    } else {
        printf("El archivo no se pudo leer correctamente.");
    }
}

void copiarDatosActualizadosLibro(char archivo[], stLibro aux){

    FILE *arch = fopen(archivo, "ab");

    if(arch != NULL){

        fwrite(&aux, sizeof(stLibro), 1, arch);

        fclose(arch);

    } else {
        printf("El archivo no se pudo abrir correctamente. \n");
    }
}

///Ejercicio3

void listarLibroPorCategoria(char archivoLibro[], int bucarCat){

    FILE *arch = fopen(archivoLibro, "rb");
    stLibro aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            if(bucarCat == aux.idCategoria){
                printf("Titulo: %s \n", aux.titulo);
                printf("Autor: %s \n\n", aux.autor);

            }
        }

        fclose(arch);
    } else {
        printf("El archivo no se pudo leer. \n");
    }
}

///Ejercicio4

void actualizarCapacidadCategoria(char archivoCateg[], int idActualCat, int valorCapacidad){

    FILE* arch = fopen(archivoCateg, "r+b");
    stCategoria aux;

    if(arch != NULL){

        //Me ubico en la posicion del id que me paso el usuario -1
        fseek(arch, (idActualCat-1) * sizeof(stCategoria),SEEK_SET);

        if(fread(&aux, sizeof(stCategoria), 1, arch) > 0){
            //modifico la capacidad
            aux.capacidad = valorCapacidad;

            //Volvemos para atras para actualizar el registro
            fseek(arch, (-1 * sizeof(stCategoria)), SEEK_CUR);
            fwrite(&aux, sizeof(stCategoria), 1, arch);
        }

        printf("Capacidad actualizada correctamente \n");
        fclose(arch);
    } else {
        printf("No se pudo leer correctamente el archivo. \n");
    }
}

///Ejercicio5

int contarLibroPorAnio(char archivoLibro[], int anioLibro){

    FILE *arch = fopen(archivoLibro, "rb");
    stLibro aux;
    int cont = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            if(aux.anioPublicacion == anioLibro){

                cont ++;
            }
        }

        fclose(arch);
    } else {
        printf("El archivo no se pudo leer correctamente. \n");
    }

    return cont;
}

///Ejercicio6

void librosPorAutor(char archivoLibro[], char nombreDeAutor[]){

    char archivoTexto[100];

    sprintf(archivoTexto, "%s.txt", nombreDeAutor);

    FILE *archTxt = fopen(archivoTexto, "w");
    FILE *archBin = fopen(archivoLibro, "rb");

    stLibro aux;

    if(archBin != NULL && archTxt != NULL){

        while(fread(&aux, sizeof(stLibro), 1, archBin) > 0){

            if(strcmpi(aux.autor, nombreDeAutor) == 0){

                fprintf(archTxt,"Titulo: %s \nISBN: %s \nAño de publicacion: %d", aux.titulo, aux.isbn, aux.anioPublicacion);
            }
        }

        fclose(archBin);
        fclose(archTxt);

    } else {
        printf("El archivo o los archivos no se pudo abrir correctamente. \n");
    }

}

///Ejercicio7

stLibro* cargarArregloLibros(char archivoLibro[], int *validosLibro){

    FILE *arch = fopen(archivoLibro, "rb");
    stLibro aux;
    stLibro* vectorLibro = NULL;
    int i = 0;
    int cant = 0;

    if(arch != NULL){

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            cant++;
        }

        vectorLibro = (stLibro*) malloc(sizeof(stLibro)*cant);

        fseek(arch, 0, SEEK_SET);

        while(fread(&aux, sizeof(stLibro), 1, arch) > 0){

            vectorLibro[i] = aux;
            i++;

        }
        fclose(arch);
        *validosLibro = cant;
    } else {
        printf("No se pudo leer el archivo \n");
    }

    return vectorLibro;
}

int calcularTotalDeLibroPorCategoria(stLibro *vectorLibro, int *validosLibro, int idCateBuscada, int i){

    if( i == validosLibro ){

        return -1;
    }

    if(vectorLibro[i].idCategoria == idCateBuscada){
       return 1 + calcularTotalDeLibroPorCategoria(vectorLibro, validosLibro, idCateBuscada, i+1);

    } else{
        return calcularTotalDeLibroPorCategoria(vectorLibro, validosLibro, idCateBuscada, i+1);
    }

}
