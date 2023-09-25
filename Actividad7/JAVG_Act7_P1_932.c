// Jorge Antono Vazquez Guzman 372504
// 19 de septiembre de 2023
// Esqueleto de actividad 7 parte 1
// JAVG_Act7_P1_932
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaracion de los prototipos
int largo_cadena(char cadena[]);
void menu(void);
void convmayus(char cadena[]);
void sali1(char cadena[]);
void sali2(char cadena[]);
void sali3(char cadena[]);
void sali4(char cadena[]);
void sali5(char cadena[]);
void sali6(char cadena[]);
void sali7(char cadena[]);
void sali8(char cadena[]);
void sali9(char cadena[]);
void sali10(char cadena[]);

//Funcion main que llama al menu
int main()
{
    menu();

    return 0;
}

//Funcion que da al usuario la opcion de elegir alguna salida
void menu()
{
    int op;
    char cadena[30];

    printf("\t MENU\n");
    printf("1. Salida 1\n");
    printf("2. Salida 2\n");
    printf("3. Salida 3\n");
    printf("4. Salida 4\n");
    printf("5. Salida 5\n");
    printf("6. Salida 7\n");
    printf("7. Salida 7\n");
    printf("8. Salida 8\n");
    printf("9. Salida 9\n");
    printf("10. Salida 10\n");
    scanf("%d", &op);
    printf("\n Ingresa una cadena de caracteres: ");
    fflush(stdin);
    gets(cadena);
    convmayus(cadena);

    switch (op)
    {
    case 1:
        sali1(cadena);
        break;
    case 2:
        sali2(cadena);
        break;
    case 3:
        sali3(cadena);
        break;
    case 4:
        sali4(cadena);
        break;
    case 5:
        sali5(cadena);
        break;
    case 6:
        sali6(cadena);
        break;
    case 7:
        sali7(cadena);
        break;
    case 8:
        sali8(cadena);
        break;
    case 9:
        sali9(cadena);
        break;
    case 10:
        sali10(cadena);
        break;
    default:
        printf("\n Opcion no valida");
    }
}

//Funcion que cuando es llamada cuanta el largo de la cadena
int largo_cadena(char cadena[])
{
    int i;
    i = 0;
    while (cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

//Funcion que cuando es llamada convierte todo a mayusculas
void convmayus(char cadena[])
{
    int i;
    char caracter;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
        }

        cadena[i] = caracter;
    }
}

//Funcion que cuando es llamada imprime la cadena normal
void sali1(char cadena[])
{
    printf("%s", cadena);
}

//Funcion que cuando es llamada imprime la cadena al reves
void sali2(char cadena[])
{
    char cadena2[30];
    int i, j;
    j = largo_cadena(cadena);

    for (i = 0; i < j; i++)
    {
        cadena2[j - i - 1] = cadena[i];
    }

    printf("%s", cadena2);
}

//Funcion que cuando es llamada imprime la cadena en forma de lista
void sali3(char cadena[])
{
    printf("\n%s", cadena);
}

//Funcion que cuando es llamada imprime la cadena al reves en forma de lista
void sali4(char cadena[])
{
    char cadena2[30];
    int i, j;
    j = largo_cadena(cadena);

    for (i = 0; i < j; i++)
    {
        cadena2[j - i - 1] = cadena[i];
    }

    printf("\n%s", cadena2);
}

//Funcion que cuando es llamada imprime la cadena normal y le va eliminando caracteres a la derecha
void sali5(char cadena[])
{
    int i, n;

    n = largo_cadena(cadena);
    printf("%s", cadena);
    for (i = n - 1; i >= 0; i--)
    {
        cadena[i] = '\0';
        printf("\n%s", cadena);
    }
}

//Funcion que cuando es llamada imprime la cadena al reves y le va eliminando caracteres a la derecha
void sali6(char cadena[])
{
    char cadena2[30];
    int i, n;
    n = largo_cadena(cadena);

    for (i = 0; i < n; i++)
    {
        cadena2[n - i - 1] = cadena[i];
    }
    printf("%s", cadena2);
    for (i = n - 1; i >= 0; i--)
    {
        cadena2[i] = '\0';
        printf("\n%s", cadena2);
    }
}

//Funcion que cuando es llamada imprime la cadena y le va eliminando caracteres a la izquierda
void sali7(char cadena[])
{
    int i, j, n;

    n = largo_cadena(cadena);

    for (i = n; i >= 0; i--)
    {
        for (j = n - i; j <= n; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

//Funcion que cuando es llamada imprime la cadena al reves y le va eliminando caracteres a la izquierda
void sali8(char cadena[])
{
    int i, j, n;

    n = largo_cadena(cadena);

    for (i = n; i >= 0; i--)
    {
        for (j = i; j >= 0; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

//Funcion que cuando es llamada imprime las consonantes de la cadena
void sali9(char cadena[])
{
    int i;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }

        if ((caracter >= 'a' && caracter <= 'z') && (caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u'))
        {
            printf("%c", cadena[i]);
        }
    }
}

//Funcion que cuando es llamada imprime las vocales de la cadena
void sali10(char cadena[])
{
    int i;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }

        if ((caracter >= 'a' && caracter <= 'z') && (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'))
        {
            printf("%c", cadena[i]);
        }
    }
}