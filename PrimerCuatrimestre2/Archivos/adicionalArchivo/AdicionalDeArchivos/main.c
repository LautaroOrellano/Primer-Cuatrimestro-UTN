#include <stdio.h>
#include <stdlib.h>

#define DIM 30


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

int main()
{
    char nombreArchivo[] = "Peliculas.bin";



    return 0;
}

void limpiarString(char string[]){

    int posicion = strcspn(string, "\n");
    string(posicion) = '\0';
}

stPelicula cargarPelicula(){

        stPelicula newPelicula;

        static int idAutoIncremental = 1;
        pelicula.idPelicula = idAutoIncremental;
        idAutoIncremental ++;

        printf("Nombre de la pelicula: ");
        fgets(pelicula.nombrePelicula, DIM, stdin);
        limpiarString(pelicula.nombrePelicula);

        printf("Nombre del director: ");
        fgets(pelicula.director);
        limpiarString(pelicula.director, DIM, stdin);

        printf("Genero de la pelicula: ");
        fgets(pelicula.genero, DIM, stdin);
        limpiarString(pelicula.genero);

        printf("Pais de origen: ");
        fgets(pelicula.pais, DIM, stdin);
        limpiarString(pelicula.pais);

        printf("Año de estreno: ");
        scanf("%d", pelicula.anio);

        printf("Valoracion: ");
        scanf("%d", pelicula.valoracion);

        printf("Pm (0: si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18): ");
        scanf("%d", pelicula.pm);

        eliminado = 0; //indicar con 1 para eliminar

        return newPelicula;
}


void guardarPelicula(stPelicula newPelicula, FILE *arch){

    fwrite(&newPelicula, sizeof(stPelicula), 1, arch);
}


void guardarPeliculaAarchivo(char nombreArchivo[]){

    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi == NULL){
        archi = fopen(nombreArchivo, "wb");
        if(arch != NULL){
            printf("Se crea el archivo por primera vez \n");
            printf("\n");

            while()
            stPelicula newPelicula = cargarPelicula();
            guardarPeliculaAarchivo(newPelicula, archi);


}



        }


    }


}
