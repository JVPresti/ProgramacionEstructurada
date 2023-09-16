#include <stdio.h>
#include <stdlib.h>

void fibo(int n);

int main(){
    int n;

    printf("\n Ingrese el numero del que desea el fibonacci: ");
    scanf("%d", &n);
    fibo(n);

    return 0;
}

void fibo(int n){
    int ant, sig, res, i, op;

    numero:
    printf("Ingresa el numero del que desea el fibonacci\n");
    scanf("%d", &n);
    goto inicio;

    
    do{
    inicio:
    ant = -1;
    sig = 1;
    for (i = 0; i <= n; i++){
        res = ant + sig;
        printf(" %d,", res);
        ant = sig;
        sig = res;
    }
    printf("\nDesea repetir el ciclo para otro numero? 1. Si\n 2. No\n ");
    scanf("%d", &op);
    if(op==1){
        system("cls");
        goto numero;
    }
    }while(op!=2);
    printf("\nFue un placer tenerte aqui, hasta luego");
}




