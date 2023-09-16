#include <stdio.h>

int calcularfibonaccirecursivo(int n);

int main(){
    int n, res;
    printf("Ingresa el valor del que deseas su fibonacci: ");
    scanf("%d", &n);

    if (n<0){
        printf("El valor de n debe ser mayor o igual a 0\n");
    } 
    else{
        printf("Serie de Fibonacci para %d\n", n);
        for (int i = 0; i <= n; i++) {
            res = calcularfibonaccirecursivo(i);
            if(i<n){
                printf(", "); 
            }
        }
        printf("\n");
    }

    return 0;
}

int calcularfibonaccirecursivo(int n){
    int a, b, res;
    if (n <= 1){
        return n;
    } 
    else{
        a = calcularfibonaccirecursivo(n - 1);
        b = calcularfibonaccirecursivo(n - 2);
        res= a + b;
        printf("%d ", res); 
        return res;
    }
}