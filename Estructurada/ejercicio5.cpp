//Jorge Antono Vazquez Guzman 372504
//22 de agosto de 2022
//Lee 3 calificaciones y calcule el promedio anidado por el verdadero
//JAVG_Act1_5_932
#include <stdio.h>

int main(){
    float cal1, cal2, cal3, prom;

    printf("Ingrese la primera calificacion ");
    scanf("%f", &cal1);
    printf("Ingrese la segunda calificacion ");
    scanf("%f", &cal2);
    printf("Ingrese la tercera calificacion ");
    scanf("%f", &cal3);
    prom=(cal1+cal2+cal3)/3.0;

    if(prom<30){
        printf("Repetir");
    }
    else if(prom>=30 && prom<60){
        printf("Extraordinario");
    }
    else if(prom>=60 && prom<70){
        printf("Suficiente");
    }
    else if(prom>=70 && prom<80){
        printf("Regular");
    }
    else if(prom>=80 && prom<90){
        printf("Bien");
    }
    else if(prom>=90 && prom<98){
        printf("Muy bien");
    }
    else if(prom>=98 && prom<=100){
        printf("Excelente");
    }
    else if(prom>100){
        printf("Error en el promedio");
    }



    return 0;
}

