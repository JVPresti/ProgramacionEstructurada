//Jorge Antono Vazquez Guzman 372504
//29 de agosto de 2023
//Preio de una llamada
//JAVG_Act4_5_932
#include <stdio.h>

int main(){
    int tipo, min, subt, min2;
    float iva, total;

    printf("Seleccione el tipo de llamada que esta realizando: \n");
    printf("1. Llamada Local\n");
    printf("2. Llamada Nacional\n");
    printf("3. Llamada Internacional\n");
    scanf("%d", &tipo);
    printf("\n Ingrese la cantidad de minutos: ");
    scanf("%d" ,&min);

    if(tipo==1){
        subt=3;
        iva=3*0.16;
        total=subt+iva;
        printf("Por su llamada se le cobra una tarifa de %d pesos, un iva de %.2f, en total %.2f pesos", subt, iva, total);
    }
    if(tipo==2){
        if(min>3){
            min2=3;
            min=min-3;
            subt=(min2*7)+(min*2);
            iva=subt*0.16;
            total=subt+iva;
            printf("Por su llamada se le cobra una tarifa de %d pesos, un iva de %.2f, en total %.2f pesos", subt, iva, total);
        }
        else{
            subt=min*7;
            iva=subt*0.16;
            total=subt+iva;
            printf("Por su llamada se le cobra una tarifa de %d pesos, un iva de %.2f, en total %.2f pesos", subt, iva, total);
        }
    }
    if(tipo==3){
        if(min>2){
            min2=2;
            min=min-2;
            subt=(min2*9)+(min*4);
            iva=subt*0.16;
            total=subt+iva;
            printf("Por su llamada se le cobra una tarifa de %d pesos, un iva de %.2f, en total %.2f pesos", subt, iva, total);
        }
        else{
            subt=min*9;
            iva=subt*0.16;
            total=subt+iva;
            printf("Por su llamada se le cobra una tarifa de %d pesos, un iva de %.2f, en total %.2f pesos", subt, iva, total);
        }
    }

    return 0;
}