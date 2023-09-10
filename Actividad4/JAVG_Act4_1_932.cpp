//Jorge Antono Vazquez Guzman 372504
//29 de agosto de 2023
//Menu con operaciones basicas
//JAVG_Act4_1_932
#include <stdio.h>

int main(){
    int op, n1, n2;

    printf("Ingrese la operacion a realizar\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    scanf("%d", &op);
    printf("Ingrese el primer digito\n ");
    scanf("%d", &n1);
    printf("Ingresa el segundo digito\n");
    scanf("%d", &n2);

    if(op==1){
        printf("El resultado de la suma es %d", n1+n2);
    }
    else{
        if(op==2){
            printf("El resultado de la resta es %d", n1-n2);
        }
        else{
            if(op==3){
                printf("El resultado de la multiplicacion es %d", n1*n2);
            }
            else{
                printf("El resultado de la division es %d", n1/n2);
            }
        }
    }

    return 0;
}