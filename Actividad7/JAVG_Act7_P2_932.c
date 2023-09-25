// Jorge Antono Vazquez Guzman 372504
// 19 de septiembre de 2023
// Esqueleto de actividad 7 parte 1
// JAVG_Act7_P1_932
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void convmayus(char cadena[]);
void convminus(char cadena[]);
void capital(char cadena[]);
void largo_cadena(char cadena[]);
void reversa(char cadena[]);
void sinespacios(char cadena[]);
void caracteres(char cadena[]);
void todo(char cadena[]);
void palindromo(char cadena[]);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int op;
    char cadena[30];
    printf("\t MENU\n");
    printf("1. Convertir a mayusculas\n");
    printf("2. Convertir a minusculas\n");
    printf("3. Convertir a capital\n");
    printf("4. Contar los caracteres\n");
    printf("5. Cadena al reves\n");
    printf("6. Cadena sin espacios\n");
    printf("7. Cadena sin inicio o fin de espacios\n");
    printf("8. Todas las anteriores\n");
    printf("9. Palindromo?\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    printf("Ingrese una cadena: ");
    fflush(stdin);
    gets(cadena);
    system("CLS");
    switch (op)
    {
    case 1:
        convmayus(cadena);
        break;

    case 2:
        convminus(cadena);
        break;

    case 3:
        capital(cadena);
        break;

    case 4:
        largo_cadena(cadena);
        break;

    case 5:
        reversa(cadena);
        break;

    case 6:
        sinespacios(cadena);
        break;

    case 7:
        caracteres(cadena);
        break;

    case 8:
        todo(cadena);
        break;

    case 9:
        palindromo(cadena);
        break;

    default:
        printf("\n Opcion invalida...\n");
    }
}

// Esta funcion cuando es llamada imprime la cadena en mayusculas
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
        printf("%c", caracter);
    }
}

// Esta funcion cuando es llamada imprime la cadena en minusculas
void convminus(char cadena[])
{
    int i;
    char caracter;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];
        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }
        printf("%c", caracter);
    }
}

// Esta funcion cuando es llamada imprime la cadena con capital
void capital(char cadena[])
{
    int i;
    char caracter;

    caracter = cadena[0];
    if (caracter >= 'a' && caracter <= 'z') // Esto es para el inicio ponerle la capital
    {
        caracter -= 32;
    }
    printf("%c", caracter);

    for (i = 1; cadena[i] != '\0'; i++) // Esto es para el resto de la cadena pasarlo a minusculas
    {
        caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }
        printf("%c", caracter);
    }
}

// Esta funcion cuando es llamada cuenta el largo de la cadena
void largo_cadena(char cadena[])
{
    int largo;

    for (largo = 0; cadena[largo] != '\0'; largo++)
    {
    }

    printf("\nLa cadena tiene %d caracteres", largo);
}

// Esta funcion cuando es llamada imprime la cadena al reves
void reversa(char cadena[])
{
    int i, j, largo;
    char reves[30];

    for (largo = 0; cadena[largo] != '\0'; largo++)
    {
    }

    for (i = largo - 1, j = 0; i >= 0; i--, j++)
    {
        reves[j] = cadena[i];
        printf("%c", reves[j]);
    }
}

//Esta funcion cuando es llamada imprime la cadena sin espacios
void sinespacios(char cadena[])
{
    int i, j;
    char noespacios[30];

    for (i = 0, j = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            noespacios[j] = cadena[i];
            printf("%c", noespacios[j]);
            j++;
        }
    }
}

//Esta funcion cuando es llamada solo imprime de la cadena los caracteres alfabeticos y espacios
void caracteres(char cadena[])
{
    int i, j;
    char cadena2[30];

    j=0;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if ((cadena[i] == ' ') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) //Esta condicion valida que sea alfabetico o espacios
        {
            if (cadena[i] != ' ' || (i > 0 && cadena[i + 1] != '\0' && cadena[i - 1] != ' '))//Esto verifica el doble espaciado asi como el inicio y fin con el mismo
            {
                cadena2[j] = cadena[i];
                printf("%c", cadena2[j]);
                j++;
            }
        }
    }
}

//Esta funcion cuando es llamada llama a funciones previas para hacer todo lo que ellas hacen
void todo(char cadena[])
{
    //Aqui comienza a llamar a otras funciones
    printf("\nLa cadena en mayusculas: \n");
    convmayus(cadena);
    printf("\nLa cadena en minusculas: \n");
    convminus(cadena);
    printf("\nLa cadena con capital: \n");
    capital(cadena);
    printf("\n La cadena sin espacios: \n");
    sinespacios(cadena);
    printf("\n La cadena al reves: \n");
    reversa(cadena);
}

//Esta funcion cuando es llamada revisa si la cadena es un palindromo
void palindromo(char cadena[])
{
    int i, inicio, final, largo;
    char caracter;
    char cadena2[30];
    inicio= 0;
    largo=0;

    for (i = 0; cadena[i] != '\0'; i++)// Crea una copia de la cadena original para pruebas
    {
        caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')//Convierte de minusculas a mayusculas
        {
            caracter -= 32; 
        }

        if (caracter != ' ')//Valda si es un espacio o no
        {
            cadena2[largo] = caracter;
            largo++;
        }
    }
    final = largo - 1;

    while (inicio < final)//Esto valida el palindromo
    {
        if (cadena2[inicio] != cadena2[final])
        {
            printf("No es un palindromo");
            return;
        }

        inicio++;
        final--;
    }

    printf("Si es un palindromo");
}