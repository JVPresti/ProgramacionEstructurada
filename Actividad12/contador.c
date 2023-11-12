#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error: Debe ingresar 2 argumentos\n");
        system("pause");
        exit(1);
    }

    FILE *fa;
    char name[30], linea[90];
    int cont = 0, status = atoi(argv[2]);
    strcpy(name, argv[1]);
    strcat(name, ".txt");

    fa = fopen(name, "r");
    if (fa)
    {
        while (!feof(fa))
        {
            fgets(linea, 90, fa);
            if (strlen(linea) > 10)
            {
                cont++;
            }
        }
        fclose(fa);
    }
    else
    {
        exit(0);
    }

    return cont;
}