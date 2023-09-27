// Jorge Antono Vazquez Guzman 372504
// 26 de septiembre de 2023
// Esqueleto de actividad 8 
// JAVG_Act8_P1_932
#include <stdio.h>
#include <stdlib.h>

void menu(void);
void vectorman(void);
void vectorrand(void);
void vector1y2(void);
void imprimir(void);
void matriz4(void);
void imprimirmat(void);

int main(){
    menu();

    return 0;
}

void menu(){
    int op, c=0;

    do{
        system("CLS");
        c++;
        printf("\t MENU \n");
        printf("1. Llenado de vector manualmente. \n");
        printf("2. Llenado de vector aleatorio.\n");
        printf("3. Llenado de vector con los primeros 2.\n");
        printf("4. Imprimir vectores.\n");
        printf("5. Llenado de matriz 4x4.\n");
        printf("6. Imprimir matriz 4x4.\n");
        printf("0. Salir.\n");
        scanf("%d", &op);
        
        switch(op){
            case 1:
                vectorman();
            break;
            case 2:
                vectorrand();
            break;
            case 3:
                vector1y2();
            break;
            case 4:
                imprimir();
            break;
            case 5:
                matriz4();
            break;
            case 6: 
                imprimirmat();
            break;
            case 0:
                printf("Repetiste el menu un total de %d veces. Fue un placer...\n", c);
            break;
            default:
                printf("Opcion no valida\n");
            break;
        system("CLS");
        printf("\n Deseas repetir el menu?\n 1. Si\n 0. No\n");
        scanf("%d", &op);
        }
    }while(op!=0);
}