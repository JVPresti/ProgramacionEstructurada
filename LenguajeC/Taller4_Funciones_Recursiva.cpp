/*
Taller4_Funciones_Recursividad.cpp
Jorge Antonio Vazquez Guzman
16 de septiembre  de 2023
Este archivo contiene el codigo de calcular el factorial con recursividad
*/
#include <stdio.h>

//Declaracion del prototipo
int facto(int n);

//Funcion main, pide el valor y llama a otra funcion para calcular el factorial
int main(){
    int n, factor;
    
    printf("Ingresa el numero del que desea el factorial: ");
    scanf("%d", &n);

    if (n<0){//valida si es mayor a 0
        printf("Ingresa un numero no negativo\n");
    } else {
        factor= facto(n);
        printf("El factorial es %d\n", factor);
    }

    return 0;
}

// Función recursiva para calcular el factorial de manera recursiva, llamandose a ella misma
int facto(int n) {
    if (n==0 || n==1){
        return 1; // El factorial de 0 y 1 es 1
    } else {
        return n*facto(n-1);
    }
}