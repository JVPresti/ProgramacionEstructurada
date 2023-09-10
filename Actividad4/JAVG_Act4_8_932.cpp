//Jorge Antono Vazquez Guzman 372504
//2 de septiembre de 2022
//Juego de ChinChamPu
//JAVG_Act4_8_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int opc, ran, vic;

    srand(time(NULL));
    ran= rand() % 3 + 1;

    printf("Ingresa tu jugada\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijeras\n");
    scanf("%d", &opc);
    printf("La computadora selecciono %d\n", ran);

    vic=(opc-ran+3)%3;

    if(vic==1){
        printf("Gana el usuario ");
    }
    else{
        if(vic==0){
            printf("Empate ");
        }
        else{
            printf("Gana la computadora ");
        }
    }

    return 0;
}
