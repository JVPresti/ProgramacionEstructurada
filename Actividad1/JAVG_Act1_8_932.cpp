//Jorge Antono Vazquez Guzman 372504
//22 de agosto de 2022
//Lee 3 numeros y despliega el del medio
//JAVG_Act1_8_932
#include <stdio.h>

int main(){
    int num1, num2, num3;
    
    printf("Dame el primer valor: ");
    scanf("%d", &num1);
    printf("Dame el segundo valor: ");
    scanf("%d", &num2);
    printf("Dame el tercer valor: ");
    scanf("%d", &num3);

    if((num1>num2 && num3>num1) || (num1>num3 && num2>num1)){
       printf("El numero del medio es el primero y vale %d", num1); 
    }
    else if((num2>num1 && num3>num2) || (num2>num3 && num1>num2)){
        printf("El numero del medio es el segundo y vale %d", num2);
    }
    else{
        printf("El numero del medio es el tercero y vale %d", num3);
    }
    

    return 0;
}