#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int sal, n, cal1, cal2, cal3, prom;
    n=1;
    sal=1; 

    do{
        system("CLS");
        printf("Ingresa la primera calificacion: ");
        scanf("%d", &cal1);
        printf("\n Ingresa la segunda calificacion: ");
        scanf("%d", &cal2);
        printf("\n Ingresa la tercera calificacion: ");
        scanf("%d", &cal3);
        prom= (cal1+cal2+cal3)/3;
        if(prom>=60){
            printf("\nSu promedio final es de %d", prom);
            printf("\n Has aprobado, felicidades");
            sal=2;
        }
        else{
            printf("\n Su promedio final es de %d", prom);
            n++;
            if(4>n){
                printf("\nRepite la materia\n");
            }
            else{
                printf("\n Lo siento, superaste el limite de intentos, te has ido a baja academica, adios...");
            }
        }
        printf("\n Presiona una tecla para continuar...");
        getch();
    }while(n!=4 && sal==1);
    return 0;
}