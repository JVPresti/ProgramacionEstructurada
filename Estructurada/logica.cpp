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
       printf("El numero del medio es %d", num1); 
    }
    else if((num2>num1 && num3>num2) || (num2>num3 && num1>num2)){
        printf("El numero del medio es %d", num2);
    }
    else if((num3>num2 && num1>num3) || (num3>num1 && num2>num3)){
        printf("El numero del medio es %d", num3);
    }
    else{
        printf("Al haber numeros repetidos no se encuentra un numero en el medio");
    }

    return 0;
}