// Jorge Antono Vazquez Guzman 372504
// 26 de septiembre de 2023   --    1 de octubre de 2023
// Esqueleto de actividad 8
// JAVG_Act8_P1_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Declaracion de prototipos
void menu(void);
int vectorman(int vector1[], int size);
int vectorrand(int vector2[], int size);
int vector1y2(int vector1[], int vector2[], int vector3[], int size);
int imprimir(int vector[], int size);
int matriz4(int matriz[][4], int vector1[], int vector2[], int size);
int imprimirmat(int matriz[][4], int size);

// Funcion main
int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

// Funcion que cuando es llamada le da al usuario la opcion de escoger, ademas de contabilizar el total de veces usado, tambien llama a las funciones necesarias
void menu()
{
    int op, c = 0, vector1[10], vector2[10], vector3[20], matriz[4][4];

    do
    {
        system("CLS");
        c++;
        printf("\t MENU \n");
        printf("1. Llenado de vector manualmente. \n");
        printf("2. Llenado de vector aleatorio.\n");
        printf("3. Llenado de vector con los primeros 2.\n");
        printf("4. Imprimir vectores.\n");
        printf("5. Llenado de matriz 4x4.\n");
        printf("6. Imprimir matriz 4x4.\n");
        printf("0. Salir.\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            vectorman(vector1, 10);
            break;
        case 2:
            vectorrand(vector2, 10);
            break;
        case 3:
            vector1y2(vector1, vector2, vector3, 10);
            break;
        case 4:
            imprimir(vector1, 10);
            imprimir(vector2, 10);
            imprimir(vector3, 20);
            break;
        case 5:
            matriz4(matriz, vector1, vector2, 4);
            break;
        case 6:
            imprimirmat(matriz, 4);
            break;
        case 0:
            printf("Repetiste el menu un total de %d veces. Fue un placer...\n", c);
            break;
        default:
            printf("Opcion no valida\n");
            break;
            system("CLS");
            printf("\n Deseas repetir el menu?\n 1. Si\n 0. No\n");
            scanf("%d", &op);
        }
    } while (op != 0);
}

// Funcion que cuando es llamada le pide al usuario llenar el vector de manera manual con un rango inferior y superior
int vectorman(int vector1[], int size)
{
    int i, val, sal;

    for (i = 0; i < size; i++)
    {
        sal = 1;
        do
        {
            printf("Ingrese un valor entre el 30 y el 70: ");
            scanf("%d", &val);
            if (val >= 30 && val <= 70) // Valida que este dentro del rango
            {
                vector1[i] = val;
                sal = 1;
            }
            else
            {
                printf("Ingrese un valor valido\n");
                system("pause");
                sal = 0;
            }
        } while (sal != 1);
    }
    printf("\nProceso terminado con exito...");
    system("pause");
    return 0;
}

// Funcion que cuando es llamada llena el vector de manera de automatica
int vectorrand(int vector2[], int size)
{
    int i, n, j, sal;

    for (i = 0; i < size; i++)
    {
        sal = 1;
        do
        {
            n = rand() % 20 + 1;
            for (j = 0; j < i; j++) // Ciclo que se encarga que no se repita
            {
                if (vector2[j] == n)
                {
                    sal = 0;
                }
            }
            if (sal == 1)
            {
                vector2[i] = n;
            }
        } while (sal != 1);
    }
    printf("\nProceso terminado con exito...");
    system("pause");
    return 0;
}

// Funcion que cuando es llamada llena un vector con los 2 anteriores
int vector1y2(int vector1[], int vector2[], int vector3[], int size)
{
    int i, j;

    for (i = 0; i < size; i++) // Llena con vector 1
    {
        vector3[i] = vector1[i];
    }
    for (j = 0; j < size; j++) // Llena con vector 2
    {
        vector3[j + 10] = vector2[j];
    }
    printf("\nProceso terminado con exito...");
    system("pause");
    return 0;
}

// Funcion que cuando es llamada imprime los 3 vectores
int imprimir(int vector[], int size)
{
    int i;

    printf("\n Vector: \n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", vector[i]);
    }
    printf("\nProceso terminado con exito...");
    system("pause");
    return 0;
}

// Funcion que cuando es llamada llena la matriz 4x4 con los vectores 1 y 2
int matriz4(int matriz[][4], int vector1[], int vector2[], int size)
{
    int i, j, sup1 = 0, sup2 = 0;

    for (i = 0; i < size; i++)
    { // Ciclos para recorrer la matriz
        for (j = 0; j < size; j++)
        {
            if (sup1 < 10)
            { // Esto verifica que no se sobrepase de los 10 elementos del vector 1
                matriz[i][j] = vector1[sup1++];
            }
            else
            {
                if (sup2 < 10)
                { // Si ya paso los 10 elementos, pasa al vector 2
                    matriz[i][j] = vector2[sup2++];
                }
            }
        }
    }
    printf("\nProceso terminado con exito...");
    system("pause");
    return 0;
}

// Funcion que cuando es llamada imprime la matriz 4x4
int imprimirmat(int matriz[][4], int size)
{
    int i, j;

    printf("Elementos de la matriz:\n");
    for (i = 0; i < size; i++) // Estos ciclos recorren la matriz
    {
        for (j = 0; j < size; j++)
        {
            printf("%d \t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nProceso terminado con exito...");
    system("pause");

    return 0;
}
