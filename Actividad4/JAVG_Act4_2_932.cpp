//Jorge Antono Vazquez Guzman 372504
//29 de agosto de 2023
//Menu que convierte unidades
//JAVG_Act4_2_932
#include <stdio.h>

int main(){
    int op;
    float uni;

    printf("Ingrese la conversion que desea\n");
    printf("1. cm a pulgadas\n");
    printf("2. cm a pies\n");
    printf("3. Km a millas\n");
    printf("4. Pulgadas a cm\n");
    printf("5. pies a cm\n");
    printf("6. millas a Km\n");
    scanf("%d", &op);
    printf("Ingrese el valor a convertir ");
    scanf("%f", &uni);

    if(op==1){
        printf("El valor en pulgadas es %.2f", uni/2.54);
    }
    else{
        if(op==2){
            printf("El valor en pies es %.2f", uni/30.48);
        }
        else{
            if(op==3){
                printf("El valor en millas es %.2f", uni/1.609);
            }
            else{
                if(op==4){
                    printf("El valor en centimetros es %.2f", uni*2.54);
                }
                else{
                    if(op==5){
                        printf("El valor en centimetros es %.2f", uni*30.48);
                    }
                    else{
                        printf("El valor en kilometros es %.2f", uni*1.609);
                    }
                }
            }
        }
    }

    return 0;
}