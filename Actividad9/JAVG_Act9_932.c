// Jorge Antono Vazquez Guzman 372504
// 8 de octubre del 2023
// Esqueleto de actividad 9
// JAVG_Act9_932

#include <stdio.h>
#include <stdlib.h>
#include "procesos.h" //Libreria creada

//Declaracion de prototipos de funciones
void menu();
void buscar(int vect[]);

int main()
{
    menu();
    return 0;
}

//Funcion que se encarga de leer la seleccion del usuario
void menu()
{
    int op, vect[15], mat[4][4];

    do
    {
        printf("\t MENU\n");
        printf("1. Llenar vector \n");
        printf("2. Llenar matriz \n");
        printf("3. Imprimir vector \n");
        printf("4. Imprimir matriz \n");
        printf("5. Ordenar vector \n");
        printf("6. Buscar valor en vector \n");
        printf("0. Salir\n");
        op = validar("Ingrese la opcion que desee: ", 0, 6); //Llama a una funcion de la libreria e impide que se rompa el programa

        switch (op)
        { //Todas a excepcio de la 6 son funcion de la libreria que se mandan a llamar
        case 1:
            fillnorep(vect, 15, 100, 200);
            break;
        case 2:
            fillmatnorep(mat, 4, 4, 1, 16);
            break;
        case 3:
            printvect(vect, 15);
            break;
        case 4:
            printmat(mat, 4, 4);
            break;
        case 5:
            ordenar(vect, 15);
            break;
        case 6:
            buscar(vect);
            break;
        case 0:
            printf("\nHasta luego...");
            break;
        default:
            printf("\nOpcion no valida");
            break;
        }
    } while (op != 0);
}

//Funcion que cuando es llamada llama a una funcion de la libreria y te dice si esta o no en el vector
void buscar(int vect[])
{
    int n, i;

    n = validar("\n Ingrese un numero que desee buscar entre 100 y 200:  ", 100, 200); //Valida que el numero este dentro del rango y no rompa el programa
    i = busq_seq(vect, 15, n); //Llama a una funcion que busque el valor en el vector

    if (i != -1)
    {
        printf("\n El numero %d se encuentra en la posicion %d ", n, i);
    }
    else
    {
        printf("\n El numero no se encuentra");
    }
}