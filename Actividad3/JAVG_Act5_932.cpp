// Jorge Antono Vazquez Guzman 372504
// 10 de septiembre de 2023
// Esqueleto de actividad 5
// JAVG_Act5_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 35

// Aqui se declaran los prototipos para que el preprocesador reciba menos carga
void menu(void);
void nposi(void);
void nran(void);
void nmenmay(void);
void tablamul(void);

int main()
{
    srand(time(NULL)); // Semilla para generar numeros aleatorios
    menu();
    return 0;
}

// Esta funcion es llamada y dependiendo la opcion del usuario llama al resto de funciones necesarias
void menu()
{
    int op;
    printf("Seleccione el programa a ejecutar\n");
    printf("1. Desplegar numeros enteros en orden descendente\n");
    printf("2. Numeros aleatorios par o impar\n");
    printf("3. Numeros aleatorios mayor y menor\n");
    printf("4. Tabla de multiplicar del 1 al 20\n");
    scanf("%d", &op);

    switch (op) // Aqui el usuario elige la operacion
    {
    case 1:
        nposi();
        break;
    case 2:
        nran();
        break;
    case 3:
        nmenmay();
        break;
    case 4:
        tablamul();
        break;
    default:
        printf("Opcion no valida\n");
    }
}

// Esta funcion cuando es llamada pide al usuario un numero y despliega sus predecesores
void nposi()
{
    int n;

    printf("Ingrese un numero entero positivo\n");
    scanf("%d", &n);

    if (n >= 0) // Esto es para validar que el numero sea positivo
    {
        printf("Los numeros enteros positivos son: ");
        for (int i = n - 1; i > 0; i--) // Este ciclo permite que pueda mostrar los numeros anteriores
        {
            printf("\n%d", i);
        }
    }
    else
    {
        printf("El numero ingresado no es positivo\n");
    }
}

// Esta funcion cuando es llamada genera 40 numeros aleatorios, su suma, cantidad y si son pares o no
void nran()
{
    int npar, sumpar, sumimpar, nimpar, nran;
    npar = 0;
    sumpar = 0;
    sumimpar = 0;
    nimpar = 0;

    for (int i = 0; i < 40; i++) // Este ciclo permite que se generen 40 numeros
    {
        nran = rand() % 201;
        printf("\n%d ", nran);
        if (nran % 2 == 0) // Valida si son pares o no
        {
            printf("(par)");
            npar++;
            sumpar += nran;
        }
        else
        {
            printf("(impar)");
            nimpar++;
            sumimpar += nran;
        }
    }
    printf("\nHay un total de %d numeros pares\n", npar);
    printf("Hay un total de %d numeros impares\n", nimpar);
    printf("La suma de los numeros impares es igual a %d\n", sumpar);
    printf("La suma de los numeros impares es igual a %d\n", sumimpar);
}

// Genera N cantidad de numeros en un margen y despliega el menor y el mayor
void nmenmay()
{
    int num, nmay, nmen;
    nmen = 200;
    nmay = 100;

    for (int i = 0; i < N; i++) // Este ciclo permite que solo se generen N cantidad de numeros
    {
        num = rand() % 101 + 100;
        printf("\n%d ", num);

        if (num < nmen) // Estos ciclos es para determinar si son el menor o el mayor
        {
            nmen = num;
        }
        if (num > nmay)
        {
            nmay = num;
        }
    }
    printf("\n El numero mayor es %d y el menor es %d", nmay, nmen);
}

// Esta funcion cuando es llamada le permite mostrar al usuario alguna tabla de multiplicar entre 1 y 20
void tablamul()
{
    int n;

    printf("Ingrese un numero entre el 1 y el 20 para su tabla de multiplicar\n");
    scanf("%d", &n);

    if (n < 21 && n > 0) // Esto valida que este entre el 1 y el 20
    {
        for (int i = 0; i < 10; i++)
        {
            printf("\n %d * %d = %d", n, i + 1, n * (i + 1)); // Esto imprime y calcula la tabla de multiplicar
        }
    }
    else
    {
        printf("El numero que proporcionaste no esta dentro de los limites\n");
    }
}
