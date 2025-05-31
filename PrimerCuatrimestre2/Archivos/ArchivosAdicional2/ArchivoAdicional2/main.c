#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMPALABRA 50

typedef struct{
    int idLibro;
    char titulo[DIMPALABRA];
    char autor[DIMPALABRA];
    int stock;
} stLibro;

typedef struct{
    int idUsuario;
    char nombre[DIMPALABRA];
    int prestamosActivos;
} stUsuario;

typedef struct{
    int idPrestamo;
    int idUsuario;
    int idLibro;
    char fechaPrestamo[11];
    char fechaDevolucion[11];
} stPrestamo;

//Prototipado
void limpiarString(char string[]);
stLibro cargarUnLibro();
stUsuario cargarUnUsuario();
void guardarLibroArchivo(stLibro newLibro, FILE* arch);
void guardarUsuarioArchivo(stUsuario newUsuario, FILE* arch);
void cargarRegistroLibrosArchivo(char archivoLibros[]);
void cargarRegistroUsuariosArchivo(char archivoUsuarios[]);
void mostrarRegistrosArchivosLibro(char archivoLibros[]);
void mostrarRegistrosArchivosUsuario(char archivoUsuarios[]);
void agregarLibro(stLibro newLibro, FILE* arch);
void agregarUsuario(stUsuario newUsuario, FILE* arch);
void mostrarUnRegistro(stLibro aux);
void buscarIdLibros(char archivoLibros[]);


int main()
{

    char archivoLibros [] = "libros.bin";
    char archivoUsuarios [] = "usuarios.bin";
    int opcion;
    int salirMenu = 1;


    ///Ejercicio1
    while(salirMenu == 1){

        printf("Ingrese una opcion..\n");
        printf("--------------------\n");
        printf("1-Cargar libro \n");
        printf("2-Cargar usuario \n");
        printf("3-Mostrar libro \n");
        printf("4-Mostrar usuario \n");
        printf("5-Buscar usuario \n");
        printf("--------------------\n");
        scanf("%d", &opcion);
        while(getchar() != '\n');

        switch(opcion){

        case 1:
            cargarRegistroLibrosArchivo(archivoLibros);
            break;

        case 2:
            cargarRegistroUsuariosArchivo(archivoUsuarios);
            break;

        case 3:
            mostrarRegistrosArchivosLibro(archivoLibros);
            break;

        case 4:
            mostrarRegistrosArchivosUsuario(archivoUsuarios);
            break;

        case 5:
            buscarIdLibros(archivoLibros);
            break;

        default:
            printf("La opcion no es correcta. \n");

        }

        printf("Desea seguir en el menu (1 para continuar, 0 para salir): ");
        scanf("%d", &salirMenu);
        while( getchar() != '\n');
        printf("\n");
    }

    return 0;
}

void limpiarString(char string[]){
    int posicion = strcspn(string, "\n");
    string[posicion] = '\0';
}

/**1. Generar las funciones necesarias para cargar cada estructura en su correspondiente
archivo. Modularizar de manera que exista una función que genere la estructura con
id autoincremental y otra que se encargue de abrir/cerrar el archivo y escribir el
nuevo dato. */

stLibro cargarUnLibro(){

    stLibro newLibro;

    //Sacar afuera de cualquier funcion static in idAutoIncremental para que sirva el autoincrementador
    static int idAutoIncremental = 1;
    newLibro.idLibro = idAutoIncremental;
    idAutoIncremental ++;

    printf("Titulo del libro a cargar: ");
    fgets(newLibro.titulo, DIMPALABRA, stdin);
    limpiarString(newLibro.titulo);

    printf("Autor del libro a cargar: ");
    fgets(newLibro.autor, DIMPALABRA, stdin);
    limpiarString(newLibro.autor);

    printf("Stock del libro a cargar: ");
    scanf("%d", &newLibro.stock);
    while(getchar() != '\n');

    return newLibro;
}

stUsuario cargarUnUsuario(){

    stUsuario newUsuario;

    static int idAutoIncremental = 1;
    newUsuario.idUsuario = idAutoIncremental;
    idAutoIncremental ++;

    printf("Nombre del usuario a cargar: ");
    fgets(newUsuario.nombre, DIMPALABRA, stdin);
    limpiarString(newUsuario.nombre);

    newUsuario.prestamosActivos = 0;

    return newUsuario;
}

void guardarLibroArchivo(stLibro newLibro, FILE* arch){
    fwrite(&newLibro, sizeof(stLibro), 1, arch);
}

void guardarUsuarioArchivo(stUsuario newUsuario, FILE* arch){
    fwrite(&newUsuario, sizeof(stUsuario), 1, arch);
}

void cargarRegistroLibrosArchivo(char archivoLibros[]){

    FILE *arch = fopen(archivoLibros, "ab");
    char opcion = 's';

    if(arch != NULL){

        while(opcion == 's'){

            stLibro newLibro = cargarUnLibro();
            guardarLibroArchivo(newLibro, arch);

            printf("Desea cargar otro libro (s - n)?: ");
            scanf("%c", &opcion);
            while(getchar() != '\n');

        }

        fclose(arch);

    } else {
        printf("No se pudo abrir el archivo. \n");
    }
}

void cargarRegistroUsuariosArchivo(char archivoUsuarios[]){

void agregarLibro( stLibro newLibro, FILE* arch){
    fwrite(&newLibro, sizeof(stLibro), 1, arch);
}

void agregarUsuario(stUsuario newUsuario, FILE* arch){
    fwrite(&newUsuario, sizeof(stUsuario), 1, arch);
}

void guardarLibroArchivo(char archivoLibro[]){

    FILE *arch = fopen(archivoLibro, "ab");
    stLibro newLibro;

    if(arch != NULL){

        newLibro = cargarUnLibro();
        agregarLibro(newLibro, arch);
        fclose(arch);

    } else {
        printf("Error al abrir archivo");
    }
}


    FILE *arch = fopen(archivoUsuarios, "ab");

    if(arch != NULL){

        stUsuario newUsuario = cargarUnUsuario();
        guardarUsuarioArchivo(newUsuario, arch);
        fclose(arch);

    } else {
        printf("No se pudo abrir el archivo. \n");
    }
}

void mostrarRegistrosArchivosLibro(char archivoLibros[]){

    FILE *arch = fopen(archivoLibros, "rb");
    stLibro aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stLibro), 1, arch)){

            printf("Id: %d \n", aux.idLibro);
            printf("Titulo del libro: %s\n", aux.titulo);
            printf("Autor del libro: %s\n", aux.autor);
            printf("Stock del libro: %d\n", aux.stock);

        }
        fclose(arch);
    } else {
        printf("Error al abrir el archivo.\n");
    }
}

void mostrarRegistrosArchivosUsuario(char archivoUsuarios[]){

    FILE *arch = fopen(archivoUsuarios, "rb");
    stUsuario aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stUsuario), 1, arch)){

            printf("Usuario: %s\n", aux.nombre);
            printf("Prestamos activos: %d\n", aux.prestamosActivos);

        }
        fclose(arch);
    } else {
        printf("Error al abrir el archivo.\n");
    }
}

void mostrarUnRegistro(stLibro aux){

    printf("----------------------\n");
    printf("Titulo: %s\n", aux.titulo);
    printf("Autor: %s\n", aux.autor);
    printf("Stock: %d\n", aux.autor);
    printf("----------------------\n");
}
void buscarIdLibros(char archivoLibros[]){

    FILE *arch = fopen(archivoLibros, "rb");
    stLibro aux;
    int buscaId;

    if(arch != NULL){

        printf("Id del libro a buscar");
        scanf("%d", &buscaId);
        while(fread(&aux, sizeof(stLibro), 1,arch) > 0){

            if(aux.idLibro == buscaId){
                mostrarUnRegistro(aux);

            }
        }

    } else {
        printf("No se pudo abrir el archivo. \n");
    }
}

