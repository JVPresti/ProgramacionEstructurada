#include <stdio.h>
#include <stdlib.h>
#include "procesos.h"

void menu();
void buscar(int vect[]);

int main()
{
    menu();
    return 0;
}

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
        op = validar("Ingrese la opcion que desee: ", 0, 6);

        switch (op)
        {
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

void buscar(int vect[])
{
    int n, i;

    printf("\n Ingrese un numero que desee buscar entre 100 y 200: ");
    n = validar(" ", 100, 200);
    i = busq_seq(vect, 15, n);

    if (i != -1)
    {
        printf("\n El numero %d se encuentra en la posicion %d ", n, i);
    }
    else
    {
        printf("\n El numero no se encuentra");
    }
}