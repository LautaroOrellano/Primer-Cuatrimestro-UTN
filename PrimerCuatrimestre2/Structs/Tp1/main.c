#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20

typedef struct {
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

//Prototipado

///Ejercicio1
int cargarAlumnos(stAlumno vectorAlumnos[DIM], int *validos);
///Ejercicio2
void mostrarAlumnos(stAlumno vectorAlumnos[DIM], int *validos);
///Ejercicio3
void buscarAlumnoXMatricula(stAlumno vectorAlumnos[DIM], int *validos);
void mostrarAlumno(stAlumno unAlumno);
///Ejercicio4
int posicionMenor(stAlumno vectorAlumnos[DIM], int *validos, int inicio);
void ordenarMatricula(stAlumno vectorAlumnos[DIM], int *validos);
///Ejercicio5
void mostrarAlumXGen(stAlumno vectorAlumnos[DIM], int *validos, char genero);
///Ejercicio6
void crearNuevoAlumno(stAlumno vectorAlumnos[DIM], int *validos);
void insertarEnVectorOrdenado(stAlumno vectorAlumnos[DIM], int *validos);
///Ejercicio7

///Ejercicio8
int cantAlumnoXGenero(stAlumno vectorAlumos[DIM], int *validos, char genero);
///Ejercicio9
void funcionPrincipal(stAlumno vecttorAlumnos[DIM], stAlumno unAlumno, int *validos, int inicio, int u, int dato, int genero);



int main()
{
    /**
    ///Ejercicio1
    stAlumno vectorAlumnos[DIM];
    stAlumno unAlumno;
    int validos;
    validos=cargarAlumnos(vectorAlumnos, &validos);

    ///Ejercicio2
    mostrarAlumnos(vectorAlumnos, &validos);

    ///Ejercicio3
    buscarAlumnoXMatricula(vectorAlumnos, &validos);

    ///Ejercicio4
    ordenarMatricula(vectorAlumnos, &validos);
    printf("Ordenando Alumnos por numero de matricula....\n");
    mostrarAlumnos(vectorAlumnos, &validos);

    ///Ejercicio5
    char genero;
    printf("Alumno de que genero desea buscar ?: ");
    scanf(" %c", &genero);
    mostrarAlumXGen(vectorAlumnos, &validos, genero);

    ///Ejercicio6
    insertarEnVectorOrdenado(vectorAlumnos, &validos);

    ///Ejercicio7

    ///Ejercicio8
    int cantGenero = 0;
    printf("Que genero desea buscar ?\n");
    scanf(" %c", &genero);
    fflush(stdin);
    cantGenero =cantAlumnoXGenero(vectorAlumnos, &validos, genero);
    printf("La cantidad de alumnos con ese genero son: %d \n", cantGenero);*/

    stAlumno vectorAlumnos[DIM];
    stAlumno unAlumno;
    int inicio;
    int u;
    int dato;
    int validos = 0;
    char genero;

    funcionPrincipal(vectorAlumnos, unAlumno, &validos, inicio, u, dato, genero);

    return 0;
}

///Ejercicio1
int cargarAlumnos(stAlumno vectorAlumnos[DIM], int *validos){

    int i = 0;
    char opcion = 's';
    while(opcion == 's' && i<DIM){

        printf("Dame la matricula del alumno %d: ", i+1);
        while (scanf("%d", &vectorAlumnos[i].matricula)!=1){
            printf("Entrada incorrecta, ingrese un numero: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');

        printf("Dame el nombre del alumno %d: ", i+1);
        gets(vectorAlumnos[i].nombre);

        printf("Define el genero (m o f) del alumno %d: ", i+1);
        scanf(" %c", &vectorAlumnos[i].genero);
        while (getchar() != '\n');

        do{
            printf("\n");
        printf("Desea continuar con otro alumno? (s.continuar-n.abortar): ");
        scanf("%c", &opcion);
        while (getchar() != '\n');

        if(opcion != 's' && opcion != 'n'){
            printf("No ingreso un caracter, (s o n)");
        }
        printf("\n");

        } while (opcion !='s' && opcion != 'n');


        i++;
    }

    return i;
}
///Ejercicio2
void mostrarAlumnos(stAlumno vectorAlumnos[DIM], int *validos){

    printf("\n");
    for(int i=0; i<*validos; i++){

        printf("_______________________________\n");
        printf("Matricula del alumno %d: %d\n", i+1, vectorAlumnos[i].matricula);
        printf("Nombre del alumno %d: %s\n", i+1, vectorAlumnos[i].nombre);
        printf("Genero del alumno %d: %c\n", i+1, vectorAlumnos[i].genero);
        printf("_______________________________\n");
    }
}
///Ejercicio3
void buscarAlumnoXMatricula(stAlumno vectorAlumnos[DIM], int *validos){

    int nMatricula;
    char opcion = 's';

    while(opcion == 's'){

        int flag = 0;
        printf("Escriba la matricula del alumno a buscar: ");
        scanf("%d", &nMatricula);

        for(int i=0; i<*validos; i++){

            if(vectorAlumnos[i].matricula == nMatricula){
                mostrarAlumno(vectorAlumnos[i]);
                flag = 1;
            }
        }

        if(flag == 0 ){
            printf("No se encontro alumno con ese numero de matricula \n");
        }

        do{
            printf("Desea buscar otro alumno? (s-n):  ");
            scanf(" %c", &opcion);
            while(getchar() != '\n');

            if(opcion != 's' && opcion != 'n'){
                printf("No ingreso un caracter correcto. \n");
            }
        } while(opcion != 's' && opcion != 'n');
    }
}
void mostrarAlumno(stAlumno unAlumno){

    printf("\n");
    printf("-----------------------------\n");
    printf("Matricula del alumno: %d\n", unAlumno.matricula);
    printf("Nombre del alumno: %s\n", unAlumno.nombre);
    printf("Genero del alumno: %c\n", unAlumno.genero);
    printf("-----------------------------\n");
    printf("\n");

}
///Ejercicio4
int posicionMenor(stAlumno vectorAlumnos[DIM], int *validos, int inicio){

    int posMenor = inicio;
    int menor = vectorAlumnos[inicio].matricula;

    for(int i = inicio +1; i<*validos; i++){
        if(menor > vectorAlumnos[i].matricula){
            menor = vectorAlumnos[i].matricula;
            posMenor = i;
        }
    }

    return posMenor;
}
void ordenarMatricula(stAlumno vectorAlumnos[DIM], int *validos){

    stAlumno aux;

    for(int i=0; i<*validos-1; i++){

        int posMenor = posicionMenor(vectorAlumnos, validos, i);
        aux = vectorAlumnos[posMenor];
        vectorAlumnos[posMenor]= vectorAlumnos[i];
        vectorAlumnos[i] = aux;
    }
}
///Ejercico5
void mostrarAlumXGen(stAlumno vectorAlumnos[DIM], int *validos, char genero){

    for(int i=0; i<*validos; i++){
        if(vectorAlumnos[i].genero == genero){
            mostrarAlumno(vectorAlumnos[i]);
        }
    }
}
///Ejercicio6
void crearNuevoAlumno(stAlumno vectorAlumnos[DIM], int *validos){

        printf("Datos del nuevo alumno:\n");

        printf("Dame la matricula del nuevo alumno: ");
        scanf("%d", &vectorAlumnos[*validos].matricula);
        while (getchar() != '\n');

        printf("Dame el nombre del nuevo alumno: ");
        gets(vectorAlumnos[*validos].nombre);

        printf("Define el genero (m o f) del nuevo alumno: ");
        scanf(" %c", &vectorAlumnos[*validos].genero);
        while (getchar() != '\n');

        //Asigno un lugar mas al arreglo vectorAlumnos
        (*validos)++;
}
void insertarEnVectorOrdenado(stAlumno vectorAlumnos[DIM], int *validos){

    crearNuevoAlumno(vectorAlumnos,validos);
    ordenarMatricula(vectorAlumnos, validos);
    mostrarAlumnos(vectorAlumnos, validos);

}
///Ejercicio7
void ordenarAlumnosPorNombre(stAlumno vectorAlumnos[DIM], int *validos){

    int u = 0;
    while(u<*validos-1){

        insertarAlumno(vectorAlumnos, u, vectorAlumnos[u+1]);
        u++;
    }
}
void insertarAlumno(stAlumno vectorAlumnos[DIM], int u, int dato){

    int i = ult;
    while(i>=0 && dato<vectorAlumnos[i]){
       vectorAlumnos[i+1] = vectorAlumnos[i];
       i--;
    }
    vectorAlumnos[i+1] = dato;
}
///Ejercicio8
int cantAlumnoXGenero(stAlumno vectorAlumnos[DIM], int *validos, char genero){

    int cont = 0;
    for(int i=0; i<*validos; i++){

        if(vectorAlumnos[i].genero == genero){
                cont++;
        }
    }
    return cont;
}
///Ejercicio9
void funcionPrincipal(stAlumno vectorAlumnos[DIM], stAlumno unAlumno, int *validos, int inicio, int u, int dato, int genero){

    int cantGenero = 0;
    int opcionMenu;

    do{

        printf("_________________________________________________\n");
        printf("1-Cargar alumnos                                 |\n");
        printf("2-Mostrar alumnos                                |\n");
        printf("3-Buscar alumnos por matricula                   |\n");
        printf("4-Ordenar alumnos por matricula de menor a mayor |\n");
        printf("5-Buscar alumnos por genero                      |\n");
        printf("6-Crear alumnos nuevo                            |\n");
        printf("7-Ordenar alumnos por nombre                     |\n");
        printf("8-Cantidad de alumnos por genero                 |\n");
        printf("_________________________________________________|\n");

        printf("\n");
        printf("Ingrese una opcion valida (1-8): ");
        scanf("%d", &opcionMenu);
        fflush(stdin);
        while(getchar() != '\n');
        printf("\n");

        switch(opcionMenu){

            case 1:
                 *validos = cargarAlumnos(vectorAlumnos, validos);
                break;

            case 2:
                if(validos != 0){
                    mostrarAlumnos(vectorAlumnos, validos);
                } else {
                    printf("Debe cargar Alumnos primero");
                }
                break;

            case 3:
                buscarAlumnoXMatricula(vectorAlumnos, validos);
                break;

            case 4:
                ordenarMatricula(vectorAlumnos, validos);
                printf("Ordenando Alumnos por numero de matricula....\n");
                mostrarAlumnos(vectorAlumnos, validos);
                break;

            case 5:
                printf("Alumno de que genero desea buscar ?: ");
                scanf(" %c", &genero);
                mostrarAlumXGen(vectorAlumnos, validos, genero);
                break;

            case 6:
                insertarEnVectorOrdenado(vectorAlumnos, validos);
                break;

            case 7:

            case 8:
                printf("Que genero desea buscar ?\n");
                scanf(" %c", &genero);
                fflush(stdin);
                cantGenero =cantAlumnoXGenero(vectorAlumnos, validos, genero);
                printf("La cantidad de alumnos con ese genero son: %d \n", cantGenero);
                break;

            default:
                printf("Opcion incorrecta ingrese una opcion valida.");
                break;
        }


    }while(opcionMenu != 0);

}

