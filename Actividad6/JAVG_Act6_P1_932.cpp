// Jorge Antono Vazquez Guzman 372504
// 12 de septiembre de 2023
// Esqueleto de actividad 6 parte 1
// JAVG_Act6_P1_932
#include <stdio.h>

void menu(void);
void forfibo(void);
void forfacto(void);
void forcantdig(void);
void whifibo(void);
void whifacto(void);
void whicantdig(void);
void dofibo(void);
void dofacto(void);
void docantdig(void);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int op;
    printf("Ingrese el programa que desea ejecutar\n");
    printf("1. Fibonacci con ciclo for\n");
    printf("2. Fibonacci con ciclo while\n");
    printf("3. Fibonacci con ciclo do while\n");
    printf("4. Factorial con ciclo for\n");
    printf("5. Factorial con ciclo while\n");
    printf("6. Factorial con ciclo do while\n");
    printf("7. Cantidad de digitos con ciclo for\n");
    printf("8. Cantidad de digitos con ciclo while\n");
    printf("9. Cantidad de digitos con ciclo do while\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        forfibo();
        break;
    case 2:
        whifibo();
        break;
    case 3:
        dofibo();
        break;
    case 4:
        forfacto();
        break;
    case 5:
        whifacto();
        break;
    case 6:
        dofacto();
        break;
    case 7:
        forcantdig();
        break;
    case 8:
        whicantdig();
        break;
    case 9:
        docantdig();
        break;
    default:
        printf("Opcion no valida\n");
    }
}

void forfibo()
{
    int n, ant, sig, res, i;

    printf("\n Ingrese la cantidad de veces que quiere que se repita el ciclo: ");
    scanf("%d", &n);

    ant = -1;
    sig = 1;
    for (i = 0; i <= n - 2; i++)
    {
        res = ant + sig;
        printf(" %d,", res);
        ant = sig;
        sig = res;
    }
}

void whifibo()
{
    int n, ant, sig, res, i;

    printf("\n Ingresa la cantidad de veces que quiere que se repita el ciclo: ");
    scanf("%d", &n);

    ant = -1;
    sig = 1;
    i = 0;
    while (i <= n - 2)
    {
        res = ant + sig;
        printf(" %d,", res);
        ant = sig;
        sig = res;
        i++;
    }
}

void dofibo()
{
    int n, ant, sig, res, i;

    printf("\n Ingrese la cantidad de veces que quiere que se repita el ciclo: ");
    scanf("%d", &n);

    ant = -1;
    sig = 1;
    i = 0;

    do
    {
        res = ant + sig;
        printf(" %d,", res);
        ant = sig;
        sig = res;
        i++;
    } while (i <= n);
}

void forfacto()
{
    int n, i, res;

    printf("Ingrese el numero del que quiere el factorial: ");
    scanf("%d", &n);

    res = n;
    for (i = n - 1; i > 0; i--)
    {
        res *= i;
    }
    printf("\nEl resultado es %d", res);
}

void whifacto()
{
    int i, n, res;

    printf("Ingrese un numero del que quiere el factorial: ");
    scanf("%d", &n);

    res = n;
    i = n - 1;
    while (i > 0)
    {
        res *= i;
        i--;
    }
    printf("\n El resultado es %d ", res);
}

void dofacto()
{
    int i, n, res;

    printf("Ingrese un numero del que quiere el factorial: ");
    scanf("%d", &n);

    res = n;
    i = n - 1;
    do
    {
        res *= i;
        i--;
    } while (i > 0);
    printf("\n El resultado es %d", res);
}

void forcantdig()
{
    int n, x, i;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    x = 1;
    for (i = 0; n > x; i++)
    {
        x = x * 10;
    }
    printf("El numero tiene un total de %d digitos", i);
}

void whicantdig()
{
    int n, x, i;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    x = 1;
    i = 0;
    while (n > x)
    {
        x *= 10;
        i++;
    }
    printf("El numero tiene un total de %d digitos", i);
}

void docantdig()
{
    int n, x, i;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    x = 1;
    i = 0;
    do
    {
        x *= 10;
        i++;
    } while (n > x);
    printf("El numero tiene un total de %d digitos", i);
}
