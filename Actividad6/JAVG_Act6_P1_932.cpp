// Jorge Antono Vazquez Guzman 372504
// 12 de septiembre de 2023
// Esqueleto de actividad 6 parte 1
// JAVG_Act6_P1_932
#include <stdio.h>

//Declaracion de los protipos de las funciones
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

//Funcion main que manda a llamar al menu y retorna 0
int main()
{
    menu();

    return 0;
}

//Funcion que muestra un menu y llama a una fucnion segun la seleccion del usuario
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

//Funcion que hace Fibonacci con ciclo for
void forfibo()
{
    int n, ant, sig, res, i;

    printf("\n Ingrese la cantidad de veces que quiere que se repita el ciclo: ");
    scanf("%d", &n);

    ant = -1;
    sig = 1;
    for (i = 0; i <= n - 2; i++)//Ciclo para fibonacci
    {
        res = ant + sig;
        printf(" %d,", res);
        ant = sig;
        sig = res;
    }
}

//Funcion que hace Fibonacci con ciclo while
void whifibo()
{
    int n, ant, sig, res, i;

    printf("\n Ingresa la cantidad de veces que quiere que se repita el ciclo: ");
    scanf("%d", &n);

    ant = -1;
    sig = 1;
    i = 0;
    while (i <= n - 2) //Condicion del ciclo
    {
        res = ant + sig;
        printf(" %d,", res);
        ant = sig;
        sig = res;
        i++;
    }
}

//Funcion que hace Fibonacci con ciclo do while
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
    } while (i <= n); //Condicion para el ciclo
}

//Funcion que hace el factorial con ciclo for
void forfacto()
{
    int n, i, res;

    printf("Ingrese el numero del que quiere el factorial: ");
    scanf("%d", &n);

    res = n;
    for (i = n - 1; i > 0; i--)//Condicion para el ciclo del factorial
    {
        res *= i;
    }
    printf("\nEl resultado es %d", res);
}

//Funcion que hace el factorial con ciclo while
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

//Funcion que hace el factorial con ciclo do while
void dofacto()
{
    int i, n, res;

    printf("Ingrese un numero del que quiere el factorial: ");
    scanf("%d", &n);

    res = n;
    i = n - 1;
    do
    {
        res *= i; //Multiplicaciones que hace el factorial
        i--;
    } while (i > 0);
    printf("\n El resultado es %d", res);
}

//Funcion que cuenta digitos con ciclo for
void forcantdig()
{
    int n, x, i;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    x = 1;
    for (i = 0; n > x; i++) //Condicion para contar
    {
        x = x * 10;
    }
    printf("El numero tiene un total de %d digitos", i);
}

//Funcion que cuenta digitos con ciclo while
void whicantdig()
{
    int n, x, i;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    x = 1;
    i = 0;
    while (n > x)//Con esta condicion para
    {
        x *= 10;
        i++;
    }
    printf("El numero tiene un total de %d digitos", i);
}

//Funcion que cuenta digitos con ciclo do while
void docantdig()
{
    int n, x, i;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    x = 1;
    i = 0;
    do
    {
        x *= 10; //Esto encuentra los digitos
        i++;
    } while (n > x);
    printf("El numero tiene un total de %d digitos", i);
}
