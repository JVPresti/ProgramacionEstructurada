//Jorge Antono Vazquez Guzman 372504
//Libreria procesos
//JAVG_Act9_932
//Eres como una libreria, porque te necesito para que todo en mi funcione


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaracion de los prototipos de las funciones de la libreria
void numrand(int n, int ri, int rf);
int busq_seq(int vect[], int n, int num);
void fillnorep(int vect[], int n, int ri, int rf);
int largo_cadena(char cadena[]);
void convmayus(char cadena[]);
void vocal(char cadena[]);
void consonan(char cadena[]);
void convminus(char cadena[]);
int valida(char msg[], int ri, int rf);
void ordenar(int vect[], int n);
int busq_seqmat(int mat[][4], int m, int n, int num);
void fillmatnorep(int mat[][4], int m, int n, int ri, int rf);
void printmat(int mat[][4], int m, int n);
void printvect(int vect[], int n);

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

// Funcion que genera n numeros aleatorios y los almacena en un vector, dice la cantidad de pares, impares y la media.
void numrand(int n, int ri, int rf)
{
    int num, i, par, suma, rango;

    rango = (rf - ri) + 1;
    suma = 0;
    par = 0;
    for (i = 0; i < n; i++)
    {
        num = (rand() % rango) + ri;
        printf("%d\n", num);
        if (num % 2 == 0)
        {
            par++;
        }
        suma += num;
    }
    printf("Cantidad de pares: %d\n", par);
    printf("Cantidad de impares: %d\n", n - par);
    printf("Media: %d\n", suma / n);
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

// Funcion que busca si hay n elemento en la matriz
int busq_seqmat(int mat[][4], int m, int n, int num)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mat[i][j] == num)
            {
                return i; // Retorna la posicion en la que se encuentras
            }
        }
    }

    return -1; // Retorna una posicion invalida si no se encontro
}

// Esta funcion rellena un vector con numeros aleatorios pero sin repeticion, para esto llama a la funcion busq_seq para saber si ya se encuentra o no
void fillnorep(int vect[], int n, int ri, int rf)
{
    int i, num, rango;
    rango = rf - ri + 1;

    for (i = 0; i < n; i++)
    {
        do
        {
            num = (rand() % rango) + ri;
        } while (busq_seq(vect, i, num) != -1); //Llama a la otra funcion para confirmar que no se encuentra

        vect[i] = num;
    }
}

// Esta funcion rellena una matriz con numeros aleatorios sin repeticion
void fillmatnorep(int mat[][4], int m, int n, int ri, int rf)
{
    int i, j, cont, largo;
    largo = m * n;

    int vect[largo];
    fillnorep(vect, largo, ri, rf);//Llena el vector para despues llenar la matriz

    for (i = 0, cont = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, cont++)
        {
            mat[i][j] = vect[cont];
        }
    }
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

// Funcion que cuando es llamada imprime las vocales de la cadena
void vocal(char cadena[])
{
    int i;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }

        if ((caracter >= 'a' && caracter <= 'z') && (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'))
        {
            printf("%c", cadena[i]);
        }
    }
}

// Funcion que cuando es llamada imprime las consonantes de la cadena
void consonan(char cadena[])
{
    int i;

    for (i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }

        if ((caracter >= 'a' && caracter <= 'z') && (caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u'))
        {
            printf("%c", cadena[i]);
        }
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

// Funcion que imprime la matriz
void printmat(int mat[][4], int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%2d]", mat[i][j]);
        }
        printf("\n");
    }
}

void printvect(int vect[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d \n", vect[i]);
    }
}
