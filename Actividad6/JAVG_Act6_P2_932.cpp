// Jorge Antono Vazquez Guzman 372504
// 12 de septiembre de 2023
// Esqueleto de actividad 6 parte 2
// JAVG_Act6_P2_932
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Declaracion de los protipos de las funciones
void menu(void);
void derexam(void);
void tabmul(void);
void numrang(void);
void pesopas(void);
void repeti(void);

// Funcion main que llama a menu y retorna 0
int main()
{
    menu();

    return 0;
}

// Esta funcion cuando es llamada despliega el menu de opciones de los codigos, ademas de llamar al codigo seleccionado
void menu()
{
    int op;
    printf("Ingrese la opcion a ejecutar\n");
    printf("1. Derecho a examen\n");
    printf("2. Tablas de multiplicar\n");
    printf("3. Leer un numero dentro de un rango\n");
    printf("4. Peso de pasajeros\n");
    printf("5. Maxima cantidad de repeticiones\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        derexam();
        break;
    case 2:
        tabmul();
        break;
    case 3:
        numrang();
        break;
    case 4:
        pesopas();
        break;
    case 5:
        repeti();
        break;
    default:
        printf("Opcion no valida\n");
    }
}

// Esta funcion cuando es llamada calcula los promedios y si tienen o no derecho a examen
void derexam()
{
    int i, calif, prom, c;

    c = 0;
    for (i = 0; i < 40; i++)
    {
        prom = 0;
        system("CLS");
        do
        {
            printf("\nIngrese la primera calificacion: ");
            scanf("%d", &calif);
            if (calif < 0 || calif > 100)
            {
                printf("\nIngresa una calificacion valida entre 0 y 100");
            }
        } while (calif < 0 || calif > 100);
        prom += calif;
        do
        {
            printf("\nIngrese la segunda calificacion: ");
            scanf("%d", &calif);
            if (calif < 0 || calif > 100)
            {
                printf("\nIngresa una calificacion valida entre 0 y 100");
            }
        } while (calif < 0 || calif > 100);
        prom += calif;
        do
        {
            printf("\n Ingrese la tercera calificacion: ");
            scanf("%d", &calif);
            if (calif < 0 || calif > 100)
            {
                printf("\nIngresa una calificacion valida entre 0 y 100");
            }
        } while (calif < 0 || calif > 100);
        prom += calif;
        do
        {
            printf("\n Ingrese la cuarta calificacion: ");
            scanf("%d", &calif);
            if (calif < 0 || calif > 100)
            {
                printf("\nIngresa una calificacion valida entre 0 y 100");
            }
        } while (calif < 0 || calif > 100);
        prom += calif;
        do
        {
            printf("\n Ingrese la quinta calificacion: ");
            scanf("%d", &calif);
            if (calif < 0 || calif > 100)
            {
                printf("\nIngresa una calificacion valida entre 0 y 100");
            }
        } while (calif < 0 || calif > 100);
        prom += calif;
        prom = prom / 5;
        if (prom < 50)
        {
            c++;
        }
        printf("\n Presione una tecla para continuar...");
        getch();
    }
    system("CLS");
    printf("\n La cantidad de alumnos sin derecho a examen es de %d", c);
}

// Esta funcion cuando es llamada genera las tablas de multiplicar del 1 al 10 al ritmo del usuario
void tabmul()
{
    int i, j;

    for (i = 1; i < 11; i++)
    {
        system("cls");
        for (j = 1; j < 11; j++)
        {
            printf("%d * %d = %d", i, j, i * j);
        }
        printf("\n Ingrese una tecla para continuar...");
        getch();
    }
}

// Esta funcion cuando es llamada pide al usuario un rango de numeros para despues pedirle n numeros dentro del rango, con eso sacar suma y promedio de esos numeros
void numrang()
{
    int min, max, n, i, sum, num;

    system("CLS");
    printf("\nIngrese el valor minimo del rango: ");
    scanf("%d", &min);
    printf("\n Ingrese el valor maximo del rango: ");
    scanf("%d", &max);
    printf("\n Ingrese la cantidad de numeros que quiere dentro de ese rango: ");
    scanf("%d", &n);

    printf("\nIngrese los numeros dentro del rango (si no estan dentro del rango no contaran)");

    for (i = 1; i <= n; i++)
    {
        printf("\nNumero %d: ", i);
        scanf("%d", &num);
        if (num >= min && num <= max)
        {
            sum += num;
        }
    }
    if (sum == 0)
    {
        printf("No ingresaste numeros validos, por lo que no te puedo ayudar :(\n");
    }
    else
    {
        printf("\n La suma de los numeros validos en el rango es de %d\n", sum);
        printf("El promedio de los dentro del rango es de %d", sum / n);
    }
    printf("\nPresione una tecla para continuar...");
    getch();
}

// Esta funcion cuando es llamada pide al usuario que ingrese una cierta cantidad de pasajeros con un cierto peso cada uno hasta que se cumpla alguna condicion
void pesopas()
{
    int peso, pasaje, n, tpeso;
    peso = 700 * 1.15;
    n = 0;
    tpeso = 0;

    while (n <= 9 && peso >= tpeso)
    { // Esto valida que el peso o cantidad de pasajeros no se sobrepase
        printf("\nIngrese el peso del pasajero %d: ", n + 1);
        scanf("%d", &pasaje);
        tpeso += pasaje;
        n++;
    }
    // Estas 2 condiciones es para saber por que de los 2 motivos salio
    if (peso < tpeso)
    {
        printf("\nEl barco supero el total de peso");
    }
    if (n == 10)
    {
        printf("\nEl barco llego al limite de pasajeros");
    }
    tpeso = tpeso / n;
    system("CLS");
    printf("\n El promedio de peso de los pasajeros es de %d", tpeso);
    printf("\n Total de pasajeros= %d", n);
    printf("\n Presione una tecla para continuar...");
    getch();
}

// Esta funcion cuando es llamada pide al usuario que ingrese calificaciones y las promedia, dependiendo el promedio pasa o no, tiene 3 oportunidades para pasar
void repeti()
{
    int sal, n, cal1, cal2, cal3, prom;
    n = 1;
    sal = 1;

    do
    {
        system("CLS");
        do
        {
            printf("Ingresa la primera calificacion: ");
            scanf("%d", &cal1);
            if (cal1 < 0 && cal1 > 100)
            {
                printf("\n Ingresa una calificacion valida entre 0 y 100");
            }
        } while (cal1 < 0 && cal1 > 100); // Estas condiciones son para validar las condiciones
        do
        {
            printf("\n Ingresa la segunda calificacion: ");
            scanf("%d", &cal2);
            if (cal2 < 0 && cal2 > 100)
            {
                printf("\n Ingresa una calificacion valida entre 0 y 100");
            }
        } while (cal2 < 0 && cal2 > 100);
        do
        {
            printf("\n Ingresa la tercera calificacion: ");
            scanf("%d", &cal3);
            if (cal3 < 0 && cal3 > 100)
            {
                printf("\nIngresa una calificacion valida entre 0 y 100");
            }
        } while (cal3 < 0 && cal3 > 100);
        prom = (cal1 + cal2 + cal3) / 3;
        if (prom >= 60)
        { // Esto valida si paso o no el alummno
            printf("\nSu promedio final es de %d", prom);
            printf("\n Has aprobado, felicidades");
            sal = 2; // En caso de pasar esto le da el fallo a la condicion con lo cual lo saca
        }
        else
        {
            printf("\n Su promedio final es de %d", prom);
            n++;
            if (4 > n)
            { // Condicion para saber si no ha cursado la materia mas de lo permitido
                printf("\nRepite la materia\n");
            }
            else
            {
                printf("\n Lo siento, superaste el limite de intentos, te has ido a baja academica, adios...");
            }
        }
        printf("\nPresione una tecla para continuar...");
        getch();
    } while (n != 4 && sal == 1); // Condicion para saber cuando salir
}
