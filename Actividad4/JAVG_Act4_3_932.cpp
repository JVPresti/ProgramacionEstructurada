//Jorge Antono Vazquez Guzman 372504
//29 de agosto de 2023
//Despliega el mayor de 6 numeros
//JAVG_Act4_3_932
#include <stdio.h>

int main(){
    int n1, n2, n3, n4, n5, n6, mayor;

    printf("Ingresa el valor del primer numero ");
    scanf("%d", &n1);
    printf("\nIngresa el valor del segundo numero ");
    scanf("%d", &n2);
    printf("\nIngresa el valor del tercer numero ");
    scanf("%d", &n3);
    printf("\nIngresa el valor del cuarto numero ");
    scanf("%d", &n4);
    printf("\nIngresa el valor del quinto numero ");
    scanf("%d", &n5);
    printf("\nIngresa el valor del sexto numero ");
    scanf("%d", &n6);
    mayor=n1;

    if(n2>mayor){
        mayor=n2;
    }
    if(n3>mayor){
        mayor=n3;
    }
    if(n4>mayor){
        mayor=n4;
    }
    if(n5>mayor){
        mayor=n5;
    }
    if(n6>mayor){
        mayor=n6;
    }
    
    printf("El numero mayor es %d", mayor);

    return 0;
}