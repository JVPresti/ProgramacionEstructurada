#include <stdio.h>
#include <stdlib.h>
#include "cosas.h"

void menu();
void fillvect(int vect[], int n, int ri, int rf);
void fillmat(int mat[][4], int n, int ri, int rf);
void printvect(int vect[], int n);
void printmat(int mat[][4], int n);
void ordvect(int vect[], int n);
void buscarvect(int vect[], int n, int num);

int main(){
    menu();
    return 0;
}

void menu(){
    int op, n, ri, rf, vect[15], mat[4][4], num;

    printf("\t MENU\n");
    printf("1. Llenar vector \n");
    printf("2. Llenar matriz \n");
    printf("3. Imprimir vector \n");
    printf("4. Imprimir matriz \n");
    printf("5. Ordenar vector \n");
    printf("6. Buscar valor en vector \n");
    printf("0. Salir\n");
    op= validar("Ingrese la opcion que desee: ", 0, 6);
    do{
    switch(op){
        case 1:
            fillvect(vect, n, ri, rf);
        break;
        case 2:
            fillmat(mat[][4], 4, ri, rf);
        break;
        case 3:
            printvect(vect, 15);
        break;
        case 4:
            printmat(mat[][4], 4);
        break;
        case 5:
            ordvect(vect, 15);
        break;
        case 6:
            buscarvect(vect, 15, num);
        break;
        case 0:
            printf("\nHasta luego...");
        break;
        default:
            printf("\nOpcion no valida");
        break;

    }
    }while(op!=0);
}

void fillvector(int vect[], int n, int ri, int rf){
    

}

