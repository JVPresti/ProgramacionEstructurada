// Jorge Antono Vazquez Guzman 372504
// 26 de septiembre de 2023
// Esqueleto de actividad 8 
// JAVG_Act8_P1_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void);
int vectorman(int vector1[]);
int vectorrand(int vector2[]);
int vector1y2(int vector3[]);
int imprimir(int vector1[], int vector2[], int vector3[]);
void matriz4(void);
void imprimirmat(void);

int main(){
    srand(time(NULL));
    menu();

    return 0;
}

void menu(){
    int op, c=0, vector1[10], vector2[10], vector3[20];

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
                vectorman(vector1);
            break;
            case 2:
                vectorrand(vector2);
            break;
            case 3:
                vector1y2(vector3);
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

int vectorman(int vector1[10]){
    int i, val;

    for(i=0; i<10; i++){
        valido: //QUITAR LAS ETIQUETAS
        printf("Ingrese un valor entre el 30 y el 70: ");
        scanf("%d", &val);
        if(val>=30 && val<=70){
            vector1[i]=val;
        }
        else{
            printf("Ingrese un valor valido\n");
            goto valido; //QUITAR ETIQUETAS
        }
    }
}

int vectorrand(int vector2[10]){
    int i, n, j;

    for(i=0; i<10;i++){
        intentar:
        n=rand() % 20 + 1;
        for(j=0; j<i; j++){
            if(n==vector2[j]){
                goto intentar;
            }
        }
        vector2[i]=n;
    }
}

int vector1y2(int vector3[20]){
    int vector1[10], vector2[10], i, j;

    vectorman(vector1);
    vectorrand(vector2);

    for(i=0; i<10; i++){
        vector3[i]=vector1[i];
    }
    for(j=0; j<10; j++){
        vector3[j+10]= vector2[j];
    }
}

int imprimir(int vector1[10], int vector2[10], int vector3[20]){
    int i;
    
    vectorman(vector1);
    vectorrand(vector2);
    vector1y2(vector3);

    printf("\n Vectoe 1: \n");
    for(i=0; i<10; i++){
        printf("%d\n", vector1[i]);
    }
    printf("\n Vector 2: \n");
    for(i=0; i<10; i++){
        printf("%d\n", vector2[i]);
    }
    printf("\n Vector 3: \n");
    for(i=0; i<20; i++){
        printf("%d\n", vector3[i]);
    }
}

void matriz4(){
    


}


