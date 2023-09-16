#include <stdio.h>

// Función recursiva para calcular el término n de la serie de Fibonacci y mostrar todos los valores
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        int a = fibonacci(n - 1);
        int b = fibonacci(n - 2);
        int resultado = a + b;
        printf("%d ", resultado); // Imprimir el valor actual
        return resultado;
    }
}

int main() {
    int n;
    printf("Ingresa el valor de n para calcular los términos de la serie de Fibonacci: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("El valor de n debe ser mayor o igual a 0.\n");
    } else {
        printf("Serie de Fibonacci para n = %d:\n", n);
        for (int i = 0; i <= n; i++) {
            int resultado = fibonacci(i);
            if (i < n) {
                printf(", "); // Separar los valores con comas
            }
        }
        printf("\n");
    }

    return 0;
}
