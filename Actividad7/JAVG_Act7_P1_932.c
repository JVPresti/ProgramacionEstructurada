// Jorge Antono Vazquez Guzman 372504
// 19 de septiembre de 2023
// Esqueleto de actividad 6 parte 2
// JAVG_Act7_P1_932
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int largo_cadena(char cadena[]);
void menu(void);
void sali1(char cadena[]);
void sali2(char cadena[]);
void sali3(char cadena[]);
void sali4(char cadena[]);
void sali5(char cadena[]);
void sali6(char cadena[]);
void sali7(char cadena[]);
void sali8(char cadena[]);
void sali9(char cadena[]);


int main(){
    menu();

    return 0;
}

void menu(){
    int op;
    char cadena[30];

    printf("\t MENU\n");
    printf("1. Salida 1\n");
    printf("2. Salida 2\n");
    printf("3. Salida 3\n");
    printf("4. Salida 4\n");
    printf("5. Salida 5\n");
    printf("6. Salida 7\n");
    printf("7. Salida 7\n");
    printf("8. Salida 8\n");
    printf("9. Salida 9\n");
    scanf("%d", &op);
    printf("\n Ingresa una cadena de caracteres: ");
    fflush(stdin);
    gets(cadena);

    switch(op){
        case 1:
            sali1(cadena);
        break;
        case 2:
            sali2(cadena);
        break;
        case 3:
            sali3(cadena);
        break;
        case 4:
            sali4(cadena);
        break;
        case 5:
            sali5(cadena);
        break;
        case 6:
            sali6(cadena);
        break;
        case 7:
            sali7(cadena);
        break;
        case 8:
            sali8(cadena);
        break;
        case 9:
            sali9(cadena);
        break;
        default:
            printf("\n Opcion no valida");
    }
}

int largo_cadena(char cadena[]){
    int i;
    i=0;
    while(cadena[i]!='\0'){
        i++;
    }
    return i;
}

void sali1(char cadena[]){
    printf("%s", cadena);
}

void sali2(char cadena[]){
    char cadena2[30];
    int i, j;
    j= largo_cadena(cadena);

    for(i=0; i<j; i++){
        cadena2[j-i-1]=cadena[i];
    }

    printf("%s", cadena2);
}

void sali3(char cadena[]){
    printf("\n%s", cadena);
}

void sali4(char cadena[]){
    char cadena2[30];
    int i, j;
    j= largo_cadena(cadena);

    for(i=0; i<j; i++){
        cadena2[j-i-1]=cadena[i];
    }

    printf("\n%s", cadena2);
}

void sali5(char cadena[]){
    int i, n; 

    n= largo_cadena(cadena);
    printf("%s", cadena);
    for(i=n-1; i>=0; i--){
        cadena[i]='\0';
        printf("\n%s", cadena);
    } 
}

void sali6(char cadena[]){
    char cadena2[30];
    int i, n;
    n= largo_cadena(cadena);

    for(i=0; i<n; i++){
        cadena2[n-i-1]=cadena[i];
    }
    printf("%s", cadena2);
    for(i=n-1; i>=0; i--){
        cadena2[i]='\0';
        printf("\n%s", cadena2);
    } 
}

void sali7(char cadena[]){
    int i, n; 

    n= largo_cadena(cadena);
    printf("%s", cadena);
    for(i=0; i<=n; i--){
        cadena[i]='\0';
        printf("\n%s", cadena);
    } 
    printf("%d", i);//quitar esta linea
}



//Tengo que terminar este codigo