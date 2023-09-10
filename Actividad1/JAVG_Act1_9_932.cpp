//Jorge Antono Vazquez Guzman 372504
//22 de agosto de 2022
//Lee 3 numeros y despliega en orden ascente
//JAVG_Act1_9_932
#include <stdio.h>

int main(){
    int num1, num2, num3;
    
    printf("Dame el primer valor: ");
    scanf("%d", &num1);
    printf("Dame el segundo valor: ");
    scanf("%d", &num2);
    printf("Dame el tercer valor: ");
    scanf("%d", &num3);

    if(num1>num2){
        if(num1<num3){
            printf("%d %d %d", num2, num1, num3);
        }
        else if(num1>num3 && num3>num2){
            printf("%d %d %d", num2, num3, num1);
        }
        else if(num1>num3 && num3<num2){
            printf("%d %d %d", num3, num2, num1);
        }
    }
    if(num2>num1){
        if(num2<num3){
            printf("%d %d %d", num1, num2, num3);
        }
        else if(num2>num3 && num3>num1){
            printf("%d %d %d", num1, num3, num2);
        }
        else if(num2>num3 && num3<num1){
            printf("%d %d %d", num3, num1, num2);
        }
    }
    if(num3>num1){
        if(num3<num2){
            printf("%d %d %d", num1, num3, num2);
        }
        else if(num3>num2 && num2>num1){
            printf("%d %d %d", num1, num2, num3);
        }
        else if(num3>num2 && num2<num1){
            printf("%d %d %d", num2, num1, num3);
        }
    }





    return 0;
}