#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cosa(char cadena[]);
int largo_cadena(char cadena[]);

int main(){
    char cadena[30];

    printf("Ingresa una cadena: ");
    fflush(stdin);
    gets(cadena);
    cosa(cadena);

    return 0;
}

int largo_cadena(char cadena[]){
    int i;
    i=0;
    while(cadena[i]!='\0'){
        i++;
    }
    return i;
}


void cosa(char cadena[]){
    int i, n, j, k;
    char cadena2[30]; 

    n= largo_cadena(cadena);
    printf("%s", cadena);
    for(i=1; i<=n; i++){
        for(j=i+1, k=0; j!='\0'; j++, k++){
            cadena2[k]=cadena[j];
            printf("%s", cadena2);
        }
       
    } 
}