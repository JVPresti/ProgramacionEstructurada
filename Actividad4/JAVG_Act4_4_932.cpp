//Jorge Antono Vazquez Guzman 372504
//29 de agosto de 2023
//Calculo del salario
//JAVG_Act4_4_932
#include <stdio.h>

int main(){
    int horas, norm, ex, ex2;
    float sal, pago, pagoex, total;

    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &horas);
    printf("\nIngrese el salario por hora: ");
    scanf("%f", &sal);

    if(horas>40){
        norm=40;
        horas=horas-40;
        pago= norm*sal;
        printf("Usted trabajo %d horas normales\n", norm);
        if(horas<=9 && horas>0){
            ex=horas;
            pagoex= (sal*2)*ex;
            printf("Tambien %d horas extras\n", ex);
            printf("Se la pagara %.2f por las primeras 40 horas y %.2f por las horas extras\n", pago, pagoex);
        }
        if(horas>9){
            ex=9;
            ex2=horas-9;
            pagoex=((sal*2)*9)+((sal*3)*ex2);
            printf("Tambien %d horas extras y %d horas extras dobles\n", ex, ex2);
            printf("Se la pagara %.2f por las primeras 40 horas y %.2f por las horas extras\n", pago, pagoex);
        }
    }else{
        pago=horas*sal;
        printf("Usted trabajo %d horas y se le pagara %.2f\n", horas, pago);
    }

    total=pago+pagoex;
    printf("Su salario completo es de %.2f\n", total);
    
    return 0;
}