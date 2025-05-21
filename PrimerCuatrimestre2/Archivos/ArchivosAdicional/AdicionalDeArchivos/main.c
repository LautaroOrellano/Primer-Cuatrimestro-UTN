#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30
static int idAutoIncremental = 1;

typedef struct {

        int idPelicula;
        char nombrePelicula[30];
        char director[20];
        char genero[20];
        char pais[20];
        int anio;
        int valoracion;
        int pm;
        int eliminado; // indica 1 o 0 si la película fue eliminada

} stPelicula;

//Prototipado

void limpiarString(char string[]);
stPelicula cargarPelicula(char nombreArchivo[], int *idAutoIncremental);
void guardarPelicula(stPelicula newPelicula, char nombreArchivo[], FILE *arch);
void guardarPeliculaAarchivo(char nombreArchivo[], int *idAutoIncremental);
int existePelicula(char nombreArchivo[], stPelicula newPelicula);
void mostrarRegistros(char nombreArchivo[]);
void eliminaPelicula(char nombreArchivo[]);
void mostrarPelicula(stPelicula aux);
void modificarPelicula(char nombreArchivo[]);
void consultarPelicula(char nombreArchivo[]);
void ordenarPeliculaXSeleccion(stPelicula vectorPeliculas[], int validos);
void listadosPorNombrePelicula(char nombreArchivo[]);
void ordenarPeliculaXInserccion(stPelicula vectorPeliculas[], int validos);
void listadosPorGeneroPelicula(char nombreArchivo[]);

int main()
{
    char nombreArchivo[] = "Peliculas.bin";
    int opcion, validos;
    int salirMenu = 1;

    while(salirMenu == 1) {

        printf("Menu de Peliculas: \n");
        printf("\n");
        printf("------------------------------------------\n");
        printf("1- Cargar pelicula nueva. \n");
        printf("2- Mostrar peliculas cargadas. \n");
        printf("3- Borrar pelicula cargada. \n");
        printf("4- Modificar una pelicula cargada. \n");
        printf("5- Consultar por criterio a las peliculas. \n");
        printf("6- Listado de pelicula por titulo. \n");
        printf("7- Listado de pelicula por genero. \n");
        printf("------------------------------------------\n");
        printf("Elija una opcion valida: \n");
        scanf("%d", &opcion);
        while(getchar() != '\n');

        switch(opcion){

            case 1:
                guardarPeliculaAarchivo(nombreArchivo, &idAutoIncremental);
                break;

            case 2:
                mostrarRegistros(nombreArchivo);
                break;

            case 3:
                eliminaPelicula(nombreArchivo);
                break;

            case 4:
                modificarPelicula(nombreArchivo);
                break;

            case 5:
                consultarPelicula(nombreArchivo);
                break;

            case 6:
                listadosPorNombrePelicula(nombreArchivo);
                break;

            case 7:
                listadosPorGeneroPelicula(nombreArchivo);
                break;

            default:
                printf("Opción no válida \n");
                break;
        }
        printf("\n");
        printf("Desea salir del menu (0 para salir 1 para continuar)? \n");
        scanf("%d", &salirMenu);
        while(getchar() != '\n');
        printf("\n");
    }

    return 0;
}

void limpiarString(char string[]){
    int posicion = strcspn(string, "\n");
    string[posicion] = '\0';
}

stPelicula cargarPelicula(char nombreArchivo[], int *idAutoIncremental){

        stPelicula newPelicula;
        int flag = 0;

        newPelicula.idPelicula = *idAutoIncremental;
        (*idAutoIncremental) ++;

        while( flag == 0){

            printf("Nombre de la pelicula: ");
            fgets(newPelicula.nombrePelicula, DIM, stdin);
            limpiarString(newPelicula.nombrePelicula);

            if(existePelicula(nombreArchivo, newPelicula) == 1){
                printf("La pelicula con ese nombre ya exite. Ingrese uno nuevamente. \n");
            } else {
                flag = 1;
            }
        }

        printf("Nombre del director: ");
        fgets(newPelicula.director, DIM, stdin);
        limpiarString(newPelicula.director);

        printf("Genero de la pelicula: ");
        fgets(newPelicula.genero, DIM, stdin);
        limpiarString(newPelicula.genero);

        printf("Pais de origen: ");
        fgets(newPelicula.pais, DIM, stdin);
        limpiarString(newPelicula.pais);

        printf("Año de estreno: ");
        scanf("%d", &newPelicula.anio);
        while(getchar() != '\n');

        printf("Valoracion: ");
        scanf("%d", &newPelicula.valoracion);
        while(getchar() != '\n');

        printf("Pm (0: si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18): ");
        scanf("%d", &newPelicula.pm);
        while(getchar() != '\n');

        newPelicula.eliminado = 0; //indicar con 1 para eliminar

        return newPelicula;
}

int existePelicula(char nombreArchivo[], stPelicula newPelicula){

    FILE *arch = fopen(nombreArchivo, "rb");
    stPelicula aux;

    if(arch!=NULL){

        while(fread(&aux, sizeof(stPelicula), 1, arch) > 0){
            if(strcmpi(aux.nombrePelicula, newPelicula.nombrePelicula) == 0){
                fclose(arch);
                return 1;
            }
        }
        fclose(arch);
        return 0;

    } else {
        printf("Error al abrir el archivo.");
    }
}

void guardarPelicula(stPelicula newPelicula, char nombreArchivo[], FILE *arch){

    fwrite(&newPelicula, sizeof(stPelicula), 1, arch);
}

void guardarPeliculaAarchivo(char nombreArchivo[], int *idAutoIncremental){

    FILE *archi = fopen(nombreArchivo, "ab");
    int opcion = 's';

    if(archi != NULL){

            while(opcion == 's'){
                stPelicula newPelicula = cargarPelicula(nombreArchivo, idAutoIncremental);
                guardarPelicula(newPelicula, nombreArchivo, archi);

                printf("Desea cargar otra Pelicula? (s o n): ");
                scanf("%c", &opcion);
                while(getchar() != '\n');
            }

    } else {
        printf("Error al abrir archivo.");
    }
    fclose(archi);
}

void mostrarRegistros(char nombreArchivo[]){

    FILE *arch = fopen(nombreArchivo, "rb");
    stPelicula aux;

    if(arch != NULL){

        while(fread(&aux, sizeof(stPelicula), 1, arch) > 0){

            printf("--------------------------\n");
            printf("ID: %d\n", aux.idPelicula);
            printf("Nombre de la pelicula: %s\n", aux.nombrePelicula);
            printf("Nombre del director: %s\n", aux.director);
            printf("Genero: %s\n", aux.genero);
            printf("Pais de origen: %s\n", aux.pais);
            printf("Año de estreno: %d\n", aux.anio);
            printf("Valoracion: %d\n", aux.valoracion);
            printf("Pm: +%d \n", aux.pm);
            printf("Eliminado: %d\n", aux.eliminado);
            printf("--------------------------\n");

        }
        fclose(arch);

    } else {
        printf("El archivo no se pudo abrir");
    }

}

void mostrarPelicula(stPelicula aux){

            printf("--------------------------\n");
            printf("ID: %d\n", aux.idPelicula);
            printf("Nombre de la pelicula: %s\n", aux.nombrePelicula);
            printf("Nombre del director: %s\n", aux.director);
            printf("Genero: %s\n", aux.genero);
            printf("Pais de origen: %s\n", aux.pais);
            printf("Año de estreno: %d\n", aux.anio);
            printf("Valoracion: %d\n", aux.valoracion);
            printf("Pm: %d\n", aux.pm);
            printf("Eliminado: %d\n", aux.eliminado);
            printf("--------------------------\n");

}

void eliminaPelicula(char nombreArchivo[]){

    FILE *arch = fopen(nombreArchivo, "rb+");
    stPelicula aux;
    int idABorrar;

    if(arch !=NULL){

        printf("Ingrese el ID de la pelicula a eliminar: ");
        scanf("%d", &idABorrar);

        fseek(arch, sizeof(stPelicula)*(idABorrar-1), SEEK_SET);

        if(fread(&aux, sizeof(stPelicula), 1, arch) > 0){
            if(aux.eliminado == 0){
                aux.eliminado = 1;

                fseek(arch, -sizeof(stPelicula), SEEK_CUR);
                fwrite(&aux, sizeof(stPelicula), 1, arch);

                printf("Pelicula eliminada correctamente. \n");
            } else {
                printf("La pelicula ya esta eliminada.\n");
            }

        } else {
                printf("No se encontro una pelicula con ese ID");
        }
        fclose(arch);
    } else {
        printf("El archivo no se logro abrir.");
    }
}

void modificarPelicula(char nombreArchivo[]){


    FILE *arch = fopen(nombreArchivo, "rb+");
    stPelicula aux;
    int idAModificar, opcion;
    int encontrado = 0;

    if(arch !=NULL){

        printf("Ingrese el ID de la pelicula a modificar: \n");
        scanf("%d", &idAModificar);
        while(getchar() != '\n');

        //Busco el registro por el id
        while(fread(&aux, sizeof(stPelicula), 1, arch) > 0){
            if(aux.idPelicula == idAModificar && aux.eliminado == 0){
                encontrado = 1;

                mostrarPelicula(aux);

                printf("Ingre el numero del campo a modificar? \n");
                printf("\n");
                printf("1-nombre de la pelicula \n");
                printf("2-nombre del director \n");
                printf("3-Genero \n");
                printf("4-Pais de origen \n");
                printf("5-Año de estreno \n");
                printf("6-Valoracion \n");
                printf("7-Pm \n");
                scanf("%d", &opcion);
                while(getchar() != '\n');

                if(opcion == 1){

                    int flag = 0;

                    while( flag == 0){
                        printf("Ingrese el nuevo nombre de la pelicula. \n");
                        fgets(aux.nombrePelicula, DIM, stdin);
                        limpiarString(aux.nombrePelicula);
                        if(existePelicula(nombreArchivo, aux) == 1){
                            printf("La pelicula con ese nombre ya exite. Ingrese uno nuevamente. \n");
                        } else {
                            flag = 1;
                        }
                }

                } else if(opcion == 2){

                    printf("Nombre del nuevo director: ");
                    fgets(aux.director, DIM, stdin);
                    limpiarString(aux.director);

                } else if(opcion == 3){

                    printf("Nuevo genero de la pelicula: ");
                    fgets(aux.genero, DIM, stdin);
                    limpiarString(aux.genero);

                } else if(opcion == 4){

                    printf("Nuevo pais de origen: ");
                    fgets(aux.pais, DIM, stdin);
                    limpiarString(aux.pais);

                } else if(opcion == 5){

                    printf("Nuevo año de estreno: ");
                    scanf("%d", &aux.anio);
                    while(getchar() != '\n');

                } else if(opcion == 6){

                    printf("Nueva valoracion: ");
                    scanf("%d", &aux.valoracion);
                    while(getchar() != '\n');

                } else if(opcion == 7){
                    printf("Nuevo pm (0: si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18): ");
                    scanf("%d", &aux.pm);
                    while(getchar() != '\n');
                } else {
                    printf("Opcion invalida.");
                }

                fseek(arch, -sizeof(stPelicula), SEEK_CUR);
                fwrite(&aux, sizeof(stPelicula), 1, arch);

                printf("Registro modificado con exito. \n");
                break;
            }
        }

        if(!encontrado){
            printf("No se encontro un registro con ese id o fue eliminado.");
        }

        fclose(arch);

    } else {
        printf("Error al abrir el archivo. \n");
    }
}

void consultarPelicula(char nombreArchivo[]){

    FILE *arch = fopen(nombreArchivo, "rb");
    stPelicula aux;
    int opcion, numeroAbuscar;
    int flag = 0;
    char nombreABuscar[DIM];

    if(arch != NULL){

                printf("Por que tipo desea consultar? \n");
                printf("\n");
                printf("1-nombre de la pelicula \n");
                printf("2-nombre del director \n");
                printf("3-Genero \n");
                printf("4-Pais de origen \n");
                printf("5-Año de estreno \n");
                printf("6-Valoracion \n");
                printf("7-Pm \n");
                scanf("%d", &opcion);
                while (getchar() != '\n');

                switch(opcion){

                    case 1:

                        printf("Ingrese el nombre de la pelicula a buscar \n");
                        fgets(nombreABuscar, 30, stdin);
                        limpiarString(nombreABuscar);

                        if(flag == 0){}
                        while(fread(&aux, sizeof(stPelicula), 1, arch) > 0){
                            if(strcmp(aux.nombrePelicula, nombreABuscar) == 0){
                                mostrarPelicula(aux);
                                flag = 1;
                            }
                        }
                        if(!flag){
                            printf("No se encontro una pelicula con ese nombre.");
                        }
                        break;

                    case 2:

                        printf("Ingrese el nombre del director a buscar \n");
                        fgets(nombreABuscar, 30, stdin);
                        limpiarString(nombreABuscar);

                        if(flag == 0){
                            while(fread(&aux, sizeof(stPelicula), 1, arch) >0 ){
                                if(strcmp(aux.director, nombreABuscar) == 0){
                                    mostrarPelicula(aux);
                                    flag = 1;
                                }
                            }
                        }
                        if(!flag){
                            printf("No se encontro una pelicula con ese director.");
                        }
                        break;

                    case 3:

                        printf("Ingrese el genero a buscar \n");
                        fgets(nombreABuscar, 30, stdin);
                        limpiarString(nombreABuscar);

                        if(flag == 0){
                            while(fread(&aux, sizeof(stPelicula), 1, arch) >0 ){
                                if(strcmp(aux.genero, nombreABuscar) == 0){
                                    mostrarPelicula(aux);
                                    flag = 1;
                                }
                            }
                        }
                        if(!flag){
                            printf("No se encontro una pelicula con ese genero.");
                        }

                    case 4:

                        printf("Ingrese el pais a buscar \n");
                        fgets(nombreABuscar, 30, stdin);
                        limpiarString(nombreABuscar);

                        if(flag == 0){
                            while(fread(&aux, sizeof(stPelicula), 1, arch) >0 ){
                                if(strcmp(aux.pais, nombreABuscar) == 0){
                                    mostrarPelicula(aux);
                                    flag = 1;
                                }
                            }
                        }
                        if(!flag){
                            printf("No se encontro una pelicula con ese pais.");
                        }

                    case 5:

                        printf("Ingrese el año de estreno a buscar \n");
                        scanf("%d", &numeroAbuscar);


                        if(flag == 0){
                            while(fread(&aux, sizeof(stPelicula), 1, arch) >0 ){
                                if(aux.anio == numeroAbuscar){
                                    mostrarPelicula(aux);
                                    flag = 1;
                                }
                            }
                        }
                        if(!flag){
                            printf("No se encontro una pelicula con ese año de estreno.");
                        }

                    case 6:

                        printf("Ingrese la valoracion a buscar \n");
                        scanf("%d", &numeroAbuscar);


                        if(flag == 0){
                            while(fread(&aux, sizeof(stPelicula), 1, arch) >0 ){
                                if(aux.valoracion == numeroAbuscar){
                                    mostrarPelicula(aux);
                                    flag = 1;
                                }
                            }
                        }
                        if(!flag){
                            printf("No se encontro una pelicula con esa valoracion.");
                        }

                    case 7:

                        printf("Ingrese el pm a buscar \n");
                        scanf("%d", &numeroAbuscar);


                        if(flag == 0){
                            while(fread(&aux, sizeof(stPelicula), 1, arch) >0 ){
                                if(aux.pm == numeroAbuscar){
                                    mostrarPelicula(aux);
                                    flag = 1;
                                }
                            }
                        }
                        if(!flag){
                            printf("No se encontro un pm con ese valor.");
                        }

                    default:
                        printf("Opcion no valida");
                        break;
                }

    } else {
        printf("El archivo no se pudo abrir.");
    }

    fclose(arch);
}

void ordenarPeliculaXSeleccion(stPelicula vectorPeliculas[], int validos){

    int i, j, min;
    stPelicula aux;

    for(i=0; i<validos-1; i++){
        min = i;
        for(j=i+1; j<validos; j++){
            if(strcmpi(vectorPeliculas[j].nombrePelicula, vectorPeliculas[min].nombrePelicula) < 0 ){
                min = j;
            }
        }

        if(i!= min){
            aux = vectorPeliculas[i];
            vectorPeliculas[i] = vectorPeliculas[min];
            vectorPeliculas[min] = aux;
        }
    }
}

void listadosPorNombrePelicula(char nombreArchivo[]){

    FILE *arch = fopen(nombreArchivo, "rb");
    stPelicula vectorPeliculas[DIM];
    int validos = 0;

    if(arch != NULL){
        stPelicula aux;

        while(fread(&aux, sizeof(stPelicula), 1, arch) > 0){
            if(aux.eliminado == 0){
                vectorPeliculas[validos] = aux;
                validos++;
            }
        }

        fclose(arch);

        ordenarPeliculaXSeleccion(vectorPeliculas, validos);

        for(int i=0; i<validos; i++){
            mostrarPelicula(vectorPeliculas[i]);
        }

    } else {
        printf("Error al cargar el archivo");
    }
}

void ordenarPeliculaXInserccion(stPelicula vectorPeliculas[], int validos){

    int i, j;
    stPelicula aux;

    for(i=1; i<validos; i++){
        aux = vectorPeliculas[i];
        j = i - 1;

        while(j >= 0 && strcmpi(aux.genero, vectorPeliculas[j].genero) < 0){

            vectorPeliculas[j+1] = vectorPeliculas[j];
            j--;
        }

        vectorPeliculas[j+1] = aux;
    }
}

void listadosPorGeneroPelicula(char nombreArchivo[]){

    FILE *arch = fopen(nombreArchivo, "rb");
    stPelicula vectorPeliculas[DIM];
    int validos = 0;

    if(arch != NULL){
        stPelicula aux;

        while(fread(&aux, sizeof(stPelicula), 1, arch) > 0){
            if(aux.eliminado == 0){
                vectorPeliculas[validos] = aux;
                validos++;
            }
        }

        fclose(arch);

        ordenarPeliculaXInserccion(vectorPeliculas, validos);

        for(int i=0; i<validos; i++){
            mostrarPelicula(vectorPeliculas[i]);
        }

    } else {
        printf("Error al cargar el archivo");
    }
}
