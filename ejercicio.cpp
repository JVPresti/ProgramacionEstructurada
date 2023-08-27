#include <stdio.h>
#include <limits.h>
#define N 100

int main(){
    int op, num, bin[32], i, bits, ac;
    int cal, inventario, opinv, addinv, salirono;
    i=0;

    printf("1. Transformador a binario\n");
    printf("2. Numeros a letras\n");
    printf("3. Gestion de inventario\n");
    printf("Ingresa una opcion: ");
    scanf("%d", &op);

    switch(op){
        case 1:
            printf("Ingrese un numero decimal: ");
            scanf("%d", &num);
            printf("Ingrese la cantidad de bits a utilizar ");
            scanf("%d", &bits);

            while(num>0 || i<bits){
                bin[i]= num%2;
                num=num/2;
                i++;
               
            }
            
            ac=0;
            printf("El numero en binario es ");
            for(int j=i-1; j>=0; j--){//esto imprime el numero como tal
                if(bin[j]==1){
                    ac=ac+1;//esto acumula los 1
                }
                printf("%d", bin[j]);
            }

            for(int j=i-1; j>=0; j--){//Esto imprime las posiciones
                 if(bin[j]==1){
                    printf("\n%d\n", j);
                }
            }

        break;
        case 2:
            printf("Ingrese una calificacion entre el 0 y el 100: ");
            scanf("%d", &cal);
            if(cal>=0 && cal<60){
                printf("Usted tiene una F, en numero eso seria %d", cal);
            }
            else if(cal>=60 && cal<70){
                printf("Usted tiene un D, en  numero eso seria %d", cal);
            }
            else if(cal>=70 && cal<80){
                printf("Usted tiene una C, en numero eso seria %d", cal);
            }
            else if(cal>=80 && cal<90){
                printf("Usted tiene una B, en numero eso seria %d", cal);
            }
            else{
                printf("Usted tiene una A, en numero eso seria %d", cal);
            }
        break;
        case 3:
            inventario=0;
            do{
            printf("Desea agregar, retirar o mostrar el inventario?\n");
            printf("1. Agregar elementos al inventario \n");
            printf("2. Retirar elementos del inventario\n");
            printf("3. Mostrar inventario\n");
            scanf("%d", &opinv);

            if(opinv==1){
                printf("El inventario cuenta con %d objetos, cuantos desea agregar? ", inventario);
                scanf("%d", &addinv);
                if(inventario+addinv<=100){
                    inventario=inventario+addinv;
                    printf("\n Genial el inventario ahora cuenta con %d objetos \n", inventario);
                }
                else{
                    printf("Eso supera la cantidad maxima del almacen, la cual es 100\n");
                }
            }
            else if(opinv==2){
                printf("El inventario cuenta con %d objetos, cuantos desea quitarle? ", inventario);
                scanf("%d", &addinv);
                if(inventario-addinv<=0){
                    inventario=inventario-addinv;
                    printf("Genia el inventario ahora cuenta con %d objetos\n", inventario);
                }
                else{
                    printf("ELl inventario no puede quedar negativo\n");
                }
            }
            else if(opinv==3){
                printf("El inventario cuenta con %d objetos\n", inventario);
            }
            printf("Desea realizar otra operacion? \n 1. SI \n 2. NO\n");
            scanf("%d", &salirono);
            }while(salirono==1);
        break;
        default:
            printf("Opocion no valida\n");
    }

    return 0;
}