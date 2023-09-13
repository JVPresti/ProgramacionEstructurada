#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
       int i, j;

    for(i=1; i<11; i++){
        system("cls");
        for(j=1; j<11; j++){
            printf("\n%d * %d = %d", i, j, i*j);
        }
        printf("\n Ingrese una tecla para continuar...");
        getch();
    }
    return 0;
}