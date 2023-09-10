//Jorge Antono Vazquez Guzman 372504
//22 de agosto de 2022
//Lee un numero y muestra si es par o no
//JAVG_Act1_2_932
#include <stdio.h>

int main(){
    int n;

    printf("Dame un numero entero ");
    scanf("%d", &n);

    if(n%2 == 0){
        printf("Su numero es par");
    }
    else{
        printf("Su numero no es par");
    }

    return 0;
}