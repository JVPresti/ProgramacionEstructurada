//Jorge Antono Vazquez Guzman 372504
//2 de septiembre de 2023
//Juego de ChinChamPu con switch
//JAVG_Act4_9_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int opc, ran;

    srand(time(NULL));
    ran= rand() % 3 + 1;

    printf("Ingresa tu jugada\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijeras\n");
    scanf("%d", &opc);
    printf("La computadora selecciono %d\n", ran);

    switch((opc-ran+3)%3){
        case 1:
            printf("Gana el usuario");
        break;
        case 0:
            printf("Empate");
        break;
        default:
            printf("Gana la computadora");
        break;
    }
    return 0;
}