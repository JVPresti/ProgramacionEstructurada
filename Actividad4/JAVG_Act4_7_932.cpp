//Jorge Antono Vazquez Guzman 372504
//2 de septiembre de 2023
//Promedio de 5 examenes con una calificacion anulada
//JAVG_Act4_7_932
#include <stdio.h>

int main(){
    int cal1, cal2, cal3, cal4, cal5, menor;
    float prom;

    printf("Ingresa la primera calificacion ");
    scanf("%d", &cal1);
    printf("\nIngresa la segunda calificacion ");
    scanf("%d", &cal2);
    printf("\nIngresa la tercera calificacion ");
    scanf("%d", &cal3);
    printf("\nIngresa la cuarta calificacion ");
    scanf("%d", &cal4);
    printf("\nIngresa la quinta calificacion ");
    scanf("%d", &cal5);
    menor=cal1;

    if(cal2<menor){
        menor=cal2;
    }
    if(cal3<menor){
        menor=cal3;
    }
    if(cal4<menor){
        menor=cal4;
    }
    if(cal5<menor){
        menor=cal5;
    }

    prom=(cal1+cal2+cal3+cal4+cal5-menor)/4;
    printf("El promedio final es de %.f", prom);

    return 0;
}