//Jorge Antono Vazquez Guzman 372504
//22 de agosto de 2022
//Lee 3 numeros y despliega el menor
//JAVG_Act1_7_932
#include <stdio.h>

int main(){
    int n1, n2, n3;

    printf("Ingrese el primer numero ");
    scanf("%d", &n1);
    printf("Ingrese el segundo numero ");
    scanf("%d", &n2);
    printf("Ingrese el tercer numero ");
    scanf("%d", &n3);

    if(n1<n2 && n1<n3){
        printf("El numero menor es el primero y vale %d", n1);
    }
    else if(n2<n1 && n2<n3){
        printf("El numero menor es el segundo y vale %d",  n2);
    }
    else{
        printf("EL numero menor es el tercero y vale %d", n3);
    }

    return 0;
}