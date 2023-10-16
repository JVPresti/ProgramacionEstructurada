// Jorge Antono Vazquez Guzman 372504
// 10 de octubre del 2023 -- 15 de octubre del 2023
// Esqueleto de actividad 10
// JAVG_Act10_932

#include "procesos.h"
#define N 500

// Declaracion del struct
typedef struct
{
    int status;
    int matri;
    char apPat[30];
    char apMat[30];
    char nombre[30];
    int edad;
    int sexo;
} Talum; // Nueva manera de identificarlo

// Lista de nombres y apellidos
char nameH[20][30] = {"RODRIGO", "ERNESTO", "PEDRO", "ISMAEL", "CARLOS", "JUAN", "LUIS", "ANGEL", "ANTONIO", "OMAR", "ISRAEL", "EDGAR", "ARMANDO", "ENRIQUE", "RICARDO", "JAVIER", "ALFREDO", "ALEX", "MIGUEL", "MANUEL"};
char nameM[20][30] = {"MARIA", "ROSARIO", "SOFIA", "TRINIDAD", "GABRIELA", "LUISA", "MONICA", "MELISSA", "JAZMIN", "JANNETH", "DANNA", "LIZETH", "XIMENA", "TALIA", "ESTHER", "ISIS", "LUCIA", "ISABELA", "ISABEL", "ANA"};
char lastname[40][30] = {"PEREZ", "RODRIGUEZ", "BUSTAMANTE", "GONZALEZ", "VAZQUEZ", "GUZMAN", "FERNANDEZ", "OSUNA", "VILLEGAS", "BUENO", "CORTES", "CORONADO0", "SANCHEZ", "SILVA", "OROZCO", "MARTINEZ", "GOMEZ", "ANDA", "FLORES", "JAUREGUI", "DIAZ", "VALENZUELA", "OCTAVIANO", "MORALES", "RABAGO", "PACHECO", "DUARTE", "DIARTE", "COLOMO", "CASTRO", "MORENO", "TORRES", "ORTIZ", "GUTIERRREZ", "CONCLIN", "ISLAS", "REYES", "CAZARES", "MEDINA", "MELENDEZ"};

// Declaracion de prototipos de funciones
void menu();
void imprimir(Talum vect[], int n);
Talum genAlumRan();
Talum genAlumMan();
int busqSeqMatricula(Talum vect[], int n, int matri);
int busqMatricula(Talum vect[], int n, int matri, bool band);
int busqBin(Talum vect[], int n, int matri);
bool ordVect(Talum vect[], int n);

// Funcion main
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

// Funcion que depende la opcion del usuario llama a las funciones necesarias para llevar a cabo el proceso
void menu()
{
    int op, i, j, alumnos = 0, matri;
    bool band;
    Talum alum;    // Un solo alumno
    Talum vect[N]; // El vector donde se guarda toda la informacion

    system("CLS");
    do
    {

        printf("\n \t MENU");
        printf("\n1. Agregar (10 registros automaticos)");
        printf("\n2. Agregar manual");
        printf("\n3. Eliminar registro");
        printf("\n4. Buscar");
        printf("\n5. Ordenar");
        printf("\n6. Imprimir");
        printf("\n0. Salir");
        op = validar("\n Ingresa una opcion\n", 0, 6); // Valida las opciones

        switch (op)
        {
        case 1:
            if ((alumnos + 10) <= N) // Esto es para llenar 10 registros solamente, siempre y cuando no superen el limite
            {
                for (j = 0; j < 10; j++)
                {
                    alum = genAlumRan();                                      // Funcion que genera al alumno aleatorio
                    while (busqSeqMatricula(vect, alumnos, alum.matri) != -1) // Esto busca que no se repita la matricula
                    {
                        alum.matri = nrand(300000, 399999); // Genera la matricula
                    }
                    vect[alumnos] = alum; // Guarda al alumno en una posicion de vector
                    alumnos++;
                }
                band = false; // Bandera en falso quiere decir que no esta ordenado
            }
            else
            {
                printf("Se ha llegado al limite\n");
                system("pause");
            }
            break;
        case 2:
            if ((alumnos + 1) <= N) // Esto es para llenado manual
            {
                alum = genAlumMan(); // Llama a la funcion para generar a un alumno de manera manual

                while ((busqSeqMatricula(vect, alumnos, alum.matri)) != -1) // Valida que no se repita la matricula
                {
                    alum.matri = validar("Esa matricula ya existe, ingresa otra: ", 300000, 399999);
                }
                vect[alumnos] = alum; // Guarda al alumno
                alumnos++;
                band = false;
            }
            else
            {
                printf("Se ha llegado al limite\n");
                system("pause");
            }
            break;
        case 3:
            matri = validar("Ingresa una matricula a eliminar: ", 300000, 399999); // Valida los rangos
            i = busqMatricula(vect, alumnos, matri, band);                         // Busca la matricula para saber si se encuentra o no

            if (i != -1) // Si esto se cumple es que si se encontro
            {
                if (vect[i].status != 0) // Si el estatus es 1 es porque si estaba activo
                {
                    vect[i].status = 0;
                    printf("Se ha eliminado la matricula \n");
                    system("pause");
                }
                else
                {
                    printf("Ya se encuentra inactivo\n");
                    system("pause");
                }
            }
            else
            {
                printf("No se ha encontrado, revisa que este bien escrito. \n");
                system("pause");
            }
            break;
        case 4:
            matri = validar("Ingrese la matricula a buscar: ", 300000, 399999);
            i = busqMatricula(vect, alumnos, matri, band);

            if (i != -1)
            {
                printf("Si se encuentra en el vector\n");
                system("pause");
            }
            else
            {
                printf("No se encuentra en el vector\n");
                system("pause");
            }
            break;
        case 5:
            if (band == true) // Esto es para saber si el vector ya esta ordenado y no lo haga otra vez
            {
                printf("El vector ya esta ordenado\n");
                system("pause");
            }
            else
            {
                band = ordVect(vect, alumnos);
                printf("El vector se ha ordenado con exito\n");
                system("pause");
            }
            break;
        case 6:
            imprimir(vect, alumnos);
            break;
        case 0:
            printf("Hasta luego....\n");
            system("pause");
            break;
        default:
            printf("Opcion invalida...");
            system("pause");
        }
    } while (op != 0); // Cuando es 0 el programa termina
}

// Esta funcion imprime los registros
void imprimir(Talum vect[], int n)
{
    int i;
    system("CLS");
    printf("MATRICULA   NOMBRE                           APPAT                            APMAT                            EDAD   SEXO  \n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0) // Esto es para que solo imprima a los que tienen estatus 1
        {
            printf("%-9d   %-30s   %-30s   %-30s   %-4d   ", vect[i].matri, vect[i].nombre, vect[i].apPat, vect[i].apMat, vect[i].edad); // Imprime todos los datos
            if (vect[i].sexo == 1)
            {
                printf("HOMBRE\n");
            }
            else
            {
                printf("MUJER\n");
            }
        }
    }
    system("pause");
}

// Esta funcion ordena el vector por matriculas, es booleana para que la bandera sepa que ya esta ordenado
bool ordVect(Talum vect[], int n)
{
    int i, j;
    Talum aux;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j].matri <= vect[i].matri) // Condicion para ordenar por bubble sort
            {
                aux = vect[i];
                vect[i] = vect[j];
                vect[j] = aux;
            }
        }
    }
    return true;
}

// Esta funcion genera a un alumno de manera aleatoria
Talum genAlumRan()
{
    Talum alum;

    alum.status = 1;
    alum.matri = nrand(300000, 399999);         // Genera una matricula aleatoria
    strcpy(alum.apPat, lastname[nrand(0, 39)]); // Toma uno de los apellidos/nombres de manera aleatoria
    strcpy(alum.apMat, lastname[nrand(0, 39)]);
    alum.edad = nrand(18, 65); // Rango de edades
    alum.sexo = nrand(1, 2);

    if (alum.sexo == 1)
    {
        strcpy(alum.nombre, nameH[nrand(0, 19)]);
    }
    else
    {
        strcpy(alum.nombre, nameM[nrand(0, 19)]);
    }

    return alum;
}

// Esta funcion genera un alumno de manera manual
Talum genAlumMan()
{
    Talum alum;
    char txt[30];

    alum.status = validar("Estatus (0. No activo, 1. Activo): ", 0, 1);
    system("CLS");

    alum.matri = validar("Matricula (Entre 300000 y 399999): ", 300000, 399999); // Te valida la matricula y en el menu te dice si es que ya se encuentra
    system("CLS");

    do
    {
        system("CLS");
        printf("Ingresa el apellido paterno: ");
        fflush(stdin);
        gets(txt);
    } while (validarCad(txt) == 0); // Valida los caracteres especiales, alfabeticos, doble espacios (libreria)
    strcpy(alum.apPat, txt);        // Copia lo que se escribio al registro del apellido

    do
    {
        system("CLS");
        printf("Ingresa el apellido materno: ");
        fflush(stdin);
        gets(txt);
    } while (validarCad(txt) == 0);
    strcpy(alum.apMat, txt);

    do
    {
        system("CLS");
        printf("Ingresa los nombres: ");
        fflush(stdin);
        gets(txt);
    } while (validarCad(txt) == 0);
    strcpy(alum.nombre, txt);

    system("CLS");
    alum.edad = validar("Edad: ", 17, 65);

    system("CLS");
    alum.sexo = validar("Sexo (1. Hombre, 2. Mujer): ", 1, 2);

    return alum;
}

// Esta funcion busca la matricula de manera secuencial (desordenado)
int busqSeqMatricula(Talum vect[], int n, int matri)
{
    int i;

    for (i = 0; i < n; i++) // Recorre
    {
        if (vect[i].matri == matri) // Compara
        {
            return i; // Si esta
        }
    }
    return -1; // No esta
}

// Esta funcion busca la matricula y llama a la secuencial o binaria, depende si esta ordenado o no
int busqMatricula(Talum vect[], int n, int matri, bool band)
{
    int i;
    if (band) // Verdadero
    {
        printf("Busqueda binaria: \n");
        i = busqBin(vect, n, matri); // Llama a la busqueda binaria para buscar la matricula
    }
    else
    {
        printf("Busqueda secuencial: \n");
        i = busqSeqMatricula(vect, n, matri); // Llama a la busqueda secuencial para buscar la matricula (no esta ordenado)
    }
    return i; // Retorna si esta o no
}

// Esta funcion busca la matricula de manera binaria (ordenado)
int busqBin(Talum vect[], int n, int matri)
{
    int med, ri = 0, rf = n;
    while (ri <= rf) // Cuando haya un rango existente entra
    {
        med = ri + (rf - ri) / 2; // Encuentra el medio de los datos

        if (vect[med].matri == matri) // Se encuentra en la posicion 0 (1)
        {
            return med + 1; // Retorna la posicion con un +1 para no estar en la posicion 0
        }

        if (vect[med].matri < matri) // Si estas condiciones se cumples se reduce el rango o aumenta
        {
            ri = med++;
        }

        if (vect[med].matri > matri)
        {
            rf = med--;
        }
    }

    return -1; // No se encontro
}