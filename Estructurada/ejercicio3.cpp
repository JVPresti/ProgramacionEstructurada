//Jorge Antono Vazquez Guzman 372504
//22 de agosto de 2022
//Lee calificaciones y muestra aprobado o no
//JAVG_Act1_3_932
#include <stdio.h>

int main(){
    float ac, calif, prom;

    ac=0;
    printf("Ingrese la calificacion 1: ");
    scanf("%f", &calif);
    ac=ac+calif;
    printf("Ingrese la calificacion 2: ");
    scanf("%f", &calif);
    ac=ac+calif;
    printf("Ingrese la calificacion 3: ");
    scanf("%f", &calif);
    ac=ac+calif;
    printf("Ingrese la calificacion 4: ");
    scanf("%f", &calif);
    ac=ac+calif;

    prom=ac/4;

    if(prom>=60 && prom<=100){
        printf("Su promedio es de %.2f y esta aprobado", prom);
    }
    else{
        printf("Su promedio es dde %.2f y esta reprobado", prom);
    }

    return 0;
}