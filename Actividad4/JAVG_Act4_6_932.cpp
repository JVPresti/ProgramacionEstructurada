//Jorge Antono Vazquez Guzman 372504
//29 de agosto de 2023
//Total a pagar por consumo de agua
//JAVG_Act4_6_932
#include <stdio.h>

int main(){
    int m3, subt;
    float iva;

    printf("Ingrese la cantidad de M3 de agua gastados\n");
    scanf("%d", &m3);

    if(m3<=4){
        iva=50*0.16;
        printf("Su subtotal es de %d, un iva del %.2f, un total de %.2f", 50, iva, iva+50);
    }
    else{
        if(m3<=15){
            subt=(m3-4)*8+50;
            iva=subt*0.16;
            printf("Su subtotal es de %d, un iva de %.2f, un total de %.2f", subt, iva, iva+subt);
        }
        else{
            if(15<m3 && m3<=50){
                subt=50+(11*8)+((m3-15)*10);
                iva=subt*0.16;
                printf("Su subtotal es de %d, un iva del %.2f, un total de %.2f", subt, iva, subt+iva);
            }
            else{
                subt= 50+(11*8)+(35*10)+((m3-50)*11);
                iva=subt*0.16;
                printf("Su subtotal es de %d, su iva del %.2f, un total de %.2f", subt, iva, subt+iva);
            }
        }
    }

    return 0;
}