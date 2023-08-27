#include <stdio.h>
#include <math.h>

int main(){
    float b, e, res;

    printf("dame la base b: ");
    scanf("%f", &b);
    printf("Dame el exponente: ");
    scanf(" %f", &e);

    res= calcularPotencial(b, e);

    return 0;
}

float calcularPotencia( b, e){
    float res;
    res=pow(b,e);
    printf("El numero elevado es: %f", res);

    return res;
}