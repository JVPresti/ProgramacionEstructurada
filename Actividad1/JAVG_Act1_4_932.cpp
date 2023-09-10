//Jorge Antono Vazquez Guzman 372504
//22 de agosto de 2022
//Muestra si es hombre o mujer
//JAVG_Act1_4_932
#include <stdio.h>

int main(){
    int n;

    printf("Eres hombre o mujer? ");
    printf("\n 1. Hombre \n 2. Mujer \n");
    scanf("%d", &n);

    if(n==1 && n!=2){
        printf("HOLA, ERES HOMBRE ");
    }
    else{
        printf("HOLA, ERES MUJER ");
    }

    return 0;
}