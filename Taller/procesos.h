//Jorge Antono Vazquez Guzman 372504
//Libreria procesos
//JAVG_Act9_932

//Eres como una libreria, porque te necesito para que todo en mi funcione

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//Declaracion de los prototipos de las funciones de la libreria
int busq_seq(int vect[], int n, int num);
int largo_cadena(char cadena[]);
void convmayus(char cadena[]);
void convminus(char cadena[]);
int validar(char msg[], int ri, int rf);
void ordenar(int vect[], int n);
int nrand(int ri, int rf);
int validarCad(char cadena[]);
int valiAlfa(char cadena[]);
int valiEspacios(char cadena[]);

// Valida la entrada del usuario en un rango de numeros
int validar(char msg[], int ri, int rf)
{
    char cadena[50];
    int op;

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        op = atoi(cadena); //Convierte la cadena a un numero
    } while (op < ri || op > rf); //Valida que este dentro de los rangos

    return op;
}

//Funcion que valida que no haya caracteres especiales
int validarCad(char cadena[]){
    convmayus(cadena);

    if(valiAlfa(cadena)==0){
        return 0;
    }
    if(valiEspacios(cadena)==0){
        return 0;
    }
    return 1;
}

//Funcionq ue valide que no inicie o termine con especios, ni haya doble espacios
int valiEspacios(char cadena[]){
    int i=0;

    if(cadena[0] == ' '){
        return 0;
    }
    if(cadena[largo_cadena(cadena)] == ' '){
        return 0;
    }

    while(cadena[i] != '\0'){
        if(cadena[i]== ' '){
            if(cadena[i+1] == ' '){
                return 0;
            }
        }
        i++;
    }

    return 1;
}

//Funcion que valida que no haya caracteres no alfabeticos
int valiAlfa(char cadena[])
{
    int i = 0;

    while (cadena[i] != '\0')
    {
        if (cadena[i] != ' ')
        {
            if (cadena[i] < 'A' || cadena[i] > 'Z')
            {
                return 0; 
            }
        }

        i++;
    }

    return 1;
}

// Funcion que ordena el vector de menor a mayor
void ordenar(int vect[], int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j] <= vect[i])
            {
                aux = vect[i]; //Metodo de burbuja
                vect[i] = vect[j];
                vect[j] = aux;
            }
        }
    }
}

// Funcion que busca si hay n elemento en el un vector
int busq_seq(int vect[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vect[i] == num)
        {
            return i; // Regresa esto si encontro un numero igual
        }
    }
    return -1; // regresa esto si es que no hay ninguno igual
}

// Funcion que cuando es llamada cuanta el largo de la cadena
int largo_cadena(char cadena[])
{
    int i;
    i = 0;
    while (cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

// Funcion que cuando es llamada convierte todoa mayusculas
void convmayus(char cadena[])
{
    int i;
    char caracter;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
        }

        cadena[i] = caracter;
    }
}

// Esta funcion cuando es llamada convierte la cadena a minusculas
void convminus(char cadena[])
{
    int i;
    char caracter;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];
        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }
    }
}

//Esta funcion genera numeros random
int nrand(int ri, int rf){
    int rango;
    rango=(rf-ri+1);
    return rand() % rango +ri;
}
