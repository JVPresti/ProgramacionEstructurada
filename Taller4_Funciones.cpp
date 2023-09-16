/*
Taller4_Funciones.cpp
Jorge Antonio Vazquez Guzman
16 de septiembre  de 2023
Este archivo contiene el codigo de calcular el factorial sin recursividad
*/

#include <stdio.h>

//Declaracion del prototipo
void facto(int n);

//Funcion main, pide el valor, valida y llama a otra funcion
int main(){
    int n, op;

    do {
        printf("Ingrese un numero para calcular su factorial: ");
        scanf("%d", &n);

        if (n<0){
            printf("Ingrese un numero no negativo\n");
            continue;
        }

        facto(n);

        printf("Quieres realizar otro factorial? \n1. Si\n 2. No\n  ");
        scanf(" %d", &op);
    } while (op==1);//pregunta si desea hacerlo nuevamente

    printf("Gracias por estar aqui \n");
    return 0;
}


// Funcion que calcula el factorial sin recursividad, no retorna nada
void facto(int n){
    int res = 1;
    for (int i=1;i <=n;i++){
        res*= i;
    }
    printf("El factorial es %d\n", res);
}