#include "procesos.h"

void menu(void);
void cancion(void);
void asciArt(void);
void crear(void);

int main()
{
    menu();

    return 0;
}

void menu()
{
    int op;

    do
    {
        printf("\n\t Menu\n");
        printf("0. Salir\n");
        printf("1. Letra de cancion \n");
        printf("2. Asci Art\n");
        printf("3. Crear archivo\n");
        op = validar("Ingresa una opcion: ", 0, 3);

        switch (op)
        {
        case 1:
            cancion();
            break;
        case 2:
            asciArt();
            break;
        case 3:
            crear();
            break;
        case 0:
            printf("\n Adios...");
            break;
        default:
            printf("Opcion invalida...");
            break;
        }
    } while (op != 0);
}

void cancion()
{
    char car;
    FILE *fa;

    fa = fopen("cancion.txt", "r");

    if (fa)
    {
        do
        {
            car = fgetc(fa);
            printf("%c", car);
        } while (!(feof(fa)));

        fclose(fa);
    }
    else
    {
        printf("No se encontró el archivo");
    }
}

void asciArt()
{
    char car;
    FILE *fa;

    fa = fopen("dibujo.txt", "r");

    if (fa)
    {
        do
        {
            car = fgetc(fa);
            printf("%c", car);
        } while (!(feof(fa)));

        fclose(fa);
    }
    else
    {
        printf("No se encontró el archivo");
    }
}

void crear()
{
    FILE *fa;
    fa=fopen("nombres.txt", "a");

    fprintf(fa, "Jorge Vazquez 19 Nacido en mxli\n");
    fclose(fa);
}
