#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159268

int main(){
    int op, adi, good, opi;
    float num1, num2, res, base, h, radio, lado;
    char carac;
do{
    printf("Ingrese la aplicacion que desea utilizar: \n");
    printf("1. Calculadora\n");
    printf("2. Adivinar el numero\n");
    printf("3. Calculadora de areas\n");
    printf("0. Salir\n");
    scanf("%d", &op);
    fflush(stdin);

    while(op==1){
        printf("Ingrese el primer valor: ");
        scanf("%f", &num1);
        printf("Ingrese el simbolo de la operacion a realizar");
        fflush(stdin);
        scanf("%c", &carac);
        fflush(stdin);

        switch(carac){
            case '+':
                printf("Ingrese el segundo valor: ");
                scanf("%f", &num2);
                res=num1+num2;
            break;
            case '-':
                printf("Ingrese el segundo valor: ");
                scanf("%f", &num2);
                res=num1-num2;
            break;
            case '*':
                printf("Ingrese el segundo valor: ");
                scanf("%f", &num2);
                res=num1*num2;
            break;
            case '/':
                printf("Ingrese el segundo valor: ");
                scanf("%f", &num2);
                res=num1/num2;
            break;
            default:
                printf("Error 404: Not found \nOperacion no detectada");
            break;
    }
        printf("El resultado de tu operacion es %.2f", res);
        printf("Desea continuar? \n1=Si \n0=No");
        scanf("%d", &op);
    }


    while(op==2){
        good= rand() % 101 + 1;
        
        printf("Adivina el numero del 1 al 100: ");
        do{
            scanf("%d", &adi);
            if(good>adi){
                printf("Demasiado bajo, intentalo de nuevo: ");
            }
            else if(good<adi){
                printf("Demasiado alto, intentalo de nuevo: ");
            }
            else if(good==adi){
                printf("FELICIDIDES, HAS GANADO!!\n");
            }
        }while(good!=adi);
        printf("Desea jugar de nuevo?\n 2. Si \n 0. No");
        scanf("%d", &op);
    }

    while(op==3){
        printf("Que area desea desea obtener? \n");
        printf("1. Triangulo\n");
        printf("2. Ciculo\n");
        printf("3. Rectangulo\n");
        printf("4. Cubo\n");
        printf("5. Cilindro\n");
        scanf("%d", &opi);
        fflush(stdin);

        switch(opi){
            case 1:
                printf("Ingrese la base: ");
                scanf("%f", &base);
                fflush(stdin);
                printf("Ingrese la altura: ");
                scanf("%f", &h);
                res=(base*h)/2;
                printf("El area del triangulo es %f", res);
            break;
            case 2:
                printf("Ingrese el radio: ");
                scanf("%f", &radio);
                res=PI*(pow(radio,2));
                printf("El area del circulo es %f", res);
            break;
            case 3:
                printf("Ingrese la base: ");
                scanf("%f", &base);
                fflush(stdin);
                printf("Ingrese la altura: ");
                scanf("%f", &h);
                res=base*h;
                printf("El area del rectangulo es %f", res);
            break;
            case 4:
                printf("Ingrese el lado del cubo: ");
                scanf("%f", &lado);
                res=6*(pow(lado,2));
                printf("El area del cubo es: %f", res);
            break;
            case 5:
                printf("Ingrese el radio del cilindro: ");
                scanf("%f", &radio);
                fflush(stdin);
                printf("Ingrese la altura del cilindro: ");
                scanf("%f", &h);
                res=(2*PI*radio*h)+(2*PI*pow(radio,2));
                printf("El area del cilindro es %f", res);
            break;
            default:
                printf("Adios...");
            break;
        }
        printf("Desea continuar? \n3. Si \n 0. No");
        scanf("%d", &op);
    }

    while(op==0){
        printf("Fue un placer servirte a ti y a tu generacion, hasta nunca o hasta siempre :D");
        op=10;
    }
}while(op!=10);

    return 0;
}