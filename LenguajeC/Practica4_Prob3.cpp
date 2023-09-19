#include <stdio.h>
void generarTrianguloPascal(int n); 

int main(){
    int n, op;

    do{
        printf("Ingrese el numero de filas del Triangulo de Pascal que desea mostrar: ");
        scanf("%d", &n);

        if (n<0){
            printf("El numero de filas debe ser un numero positivo\n");
        } else {
            printf("Triangulo de Pascal con %d filas\n", n);
            generarTrianguloPascal(n);
        }

        printf("\nRequiere generar otro triangulo?\n 1. Si\n 2. No\n ");
        scanf(" %d", &op);

    } while (op==1);

    printf("\n Fue un placer\n");

    return 0;
}

// Función para calcular el coeficiente binomial C(n, k)
int coeficienteBinomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return coeficienteBinomial(n - 1, k - 1) + coeficienteBinomial(n - 1, k);
    }
}

// Función para generar y mostrar el Triángulo de Pascal con n filas
void generarTrianguloPascal(int n) {
    for (int i = 0; i < n; i++) {
        // Imprimir espacios en blanco para alinear los valores en el triángulo
        for (int j = 0; j < n - i - 1; j++) {
            printf("   ");
        }

        // Calcular y mostrar los coeficientes binomiales en la fila actual
        for (int j = 0; j <= i; j++) {
            int coeficiente = coeficienteBinomial(i, j);
            printf("%6d   ", coeficiente);
        }

        printf("\n");
    }

}


