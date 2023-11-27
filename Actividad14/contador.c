#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Tkey;
typedef struct _Wrkr
{
    int status;
    Tkey enrollment;
    char name[30];
    char LastName1[50];
    char LastName2[50];
    char sex[15];
    char JobPosition[30];
    char state[30];
    int age;
    Tkey cellPhone;
} TWrkr;

typedef struct _index
{
    Tkey key;
    int indice;
} Tindex;

int main()
{
    FILE *fa;
    int i = 0;

    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        fseek(fa, 0, SEEK_END);
        long fileSize = ftell(fa);
        i = fileSize / sizeof(TWrkr);
        fclose(fa);
    }
    else
    {
        printf("Error: No se pudo abrir el archivo\n");
        exit(1);
    }
    printf("%d\n", i);

    return i;
}