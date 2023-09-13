// Jorge Antono Vazquez Guzman 372504
// 12 de septiembre de 2023
// Esqueleto de actividad 6 parte 2
// JAVG_Act6_P2_932
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void menu(void);
void derexam(void);
void tabmul(void);
void numrang(void);
void pesopas(void);
void repeti(void);

int main(){
    menu();

    return 0;
}

void menu(){
    int op;
    printf("Ingrese la opcion a ejecutar\n");
    printf("1. Derecho a examen\n");
    printf("2. Tablas de multiplicar\n");
    printf("3. Leer un numero dentro de un rango\n");
    printf("4. Peso de pasajeros\n");
    printf("5. Maxima cantidad de repeticiones\n");
    scanf("%d", &op);

    switch(op){
        case 1:
            derexam();
        break;
        case 2:
            tabmul();
        break;
        case 3:
            numrang();
        break;
        case 4:
            pesopas();
        break;
        case 5:
            repeti();
        break;
        default:
            printf("Opcion no valida\n");
    }
}

void derexam(){
    int i, calif, prom, c;

    c=0;
    for(i=0; i<=40; i++){
        printf("\nIngrese la primera calificacion: ");
        scanf("%d", &calif);
        prom+=calif;
        printf("\nIngrese la segunda calificacion: ");
        scanf("%d", &calif);
        prom+=calif;
        printf("\n Ingrese la tercera calificacion: ");
        scanf("%d", &calif);
        prom+=calif;
        printf("\n Ingrese la cuarta calificacion: ");
        scanf("%d", &calif);
        prom+=calif;
        printf("\n Ingrese la quinta calificacion: ");
        scanf("%d", &calif);
        prom+=calif;
        prom=prom/5;
        if(prom<50){
            c++;
        }
    }
    printf("\n La cantidad de alumnos sin derecho a examen es de %d", c);
}

void tabmul(){
    int i, j;

    for(i=1; i<11; i++){
        system("cls");
        for(j=1; j<11; j++){
            printf("%d * %d = %d", i, j, i*j);
        }
        printf("\n Ingrese una tecla para continuar...");
        getch();
    }
}

void numrang(){
    
}


