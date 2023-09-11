#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int adi, ran, c, op;
    c=0;

    srand(time(NULL));
    ran= rand() % 100 + 1;
    printf("xxxxxx=%d", ran);

    inicio:
        printf("BIENVENIDO\n");
        printf("Este juego trata de adivinar el numero del 1 al 100\n");
        printf("Tendras muchas oportunidades, mientras antes lo logres mejor\n");
        printf("Mucha suerte\n");
    adivinanza:
        printf("Ingresa el numero que creas: ");
        scanf("%d", &adi);
    if(adi==ran){
        printf("Felicidades has ganado con un total de %d intentos", c);
        goto reinicio;
    }
    if(adi<ran){
        printf("Demasiado bajo");
        goto adivinanza;
    }
    if(adi>ran){
        printf("Demasiado alto");
        goto adivinanza;
    }

    c++;

    reinicio:
        c=0;
        ran=rand() % 100 + 1;
        printf("\nDesea jugar otra vez? ");
        printf("1. Si\n2. No");
        scanf("%d", &op);
        if(op==1){
            goto inicio;
        }
        else if(op==2){
            printf("Fue un placer, hasta luego");
        }
        else{
            printf("Opcion no valida");
            goto reinicio;
        }
        
    return 0;
}