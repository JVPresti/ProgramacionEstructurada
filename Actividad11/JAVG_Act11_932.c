// Jorge Antono Vazquez Guzman 372504
// 10 de octubre del 2023 -- 15 de octubre del 2023
// Esqueleto de actividad 10
// JAVG_Act10_932

#include "procesos.h"
#include "curp.h"
#define N 2000

// Declaracion de prototipos de funciones
void menu();
void imprimir(Todo vect[], int n);
Todo genAlumRan(Todo *alum, int alumnos);
Todo genAlumMan(Todo *alum, int alumnos);
int busqSeqMatricula(Todo vect[], int n, int matri);
int busqMatricula(Todo vect[], int n, int matri, bool band);
int busqBin(Todo vect[], int n, int matri);
bool ordVect(Todo vect[], int n);
bool ordVectQuick(Todo vect[]);
int compararEnteros(const void *a, const void *b);
void archivo(Todo vect[], int n);
void impriOne(Todo alum);

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
    Todo alum[N]; // Un solo alumno
    Todo vect[N]; // El vector donde se guarda toda la informacion

    system("CLS");
    do
    {

        printf("\n \t MENU");
        printf("\n1. Agregar Automatico (100)");
        printf("\n2. Agregar manual (1)");
        printf("\n3. Eliminar registro");
        printf("\n4. Buscar");
        printf("\n5. Ordenar");
        printf("\n6. Imprimir");
        printf("\n7. Archivo txt");
        printf("\n0. Salir");
        op = validar("\n Ingresa una opcion\n", 0, 7); // Valida las opciones

        switch (op)
        {
        case 1:
            if ((alumnos + 100) <= N) // Esto es para llenar 10 registros solamente, siempre y cuando no superen el limite
            {
                for (j = 0; j < 100; j++)
                {
                    if ((alumnos + 1) <= N)
                    {
                        alum[alumnos] = genAlumRan(alum, alumnos); // Funcion que genera al alumno aleatorio

                        while (busqSeqMatricula(vect, alumnos, alum[alumnos].matri) != -1) // Esto busca que no se repita la matricula
                        {
                            alum[alumnos].matri = nrand(300000, 399999); // Genera la matricula
                        }
                        vect[alumnos] = alum[alumnos]; // Guarda al alumno en una posicion de vector
                        alumnos++;
                    }
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
                alum[alumnos] = genAlumMan(alum, alumnos); // Llama a la funcion para generar a un alumno de manera manual

                while ((busqSeqMatricula(vect, alumnos, alum[alumnos].matri)) != -1) // Valida que no se repita la matricula
                {
                    alum[alumnos].matri = validar("Esa matricula ya existe, ingresa otra: ", 300000, 399999);
                }
                vect[alumnos] = alum[alumnos]; // Guarda al alumno
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
                impriOne(alum[i]);
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
                if (alumnos < 500)
                {
                    band = ordVect(vect, alumnos);
                    printf("El vector se ha ordenado con exito usando Bubble Sort\n");
                    system("pause");
                }
                else
                {
                    band = ordVectQuick(vect);
                    printf("El vector se ha ordenado con exito usando el metodo de QuickSort\n");
                    system("pause");
                }
            }
            break;
        case 6:
            imprimir(alum, alumnos);
            break;
        case 7:
            archivo(vect, alumnos);
            break;
        case 0:
            printf("Hasta luego....\n");
            system("pause");
            break;
        default:
            printf("Opcion invalida...");
            system("PAUSE");
        }
    } while (op != 0); // Cuando es 0 el programa termina
}

// Esta funcion imprime los registros
void imprimir(Todo vect[], int n)
{
    int i;
    system("CLS");
    printf("MATRICULA   NOMBRE    \t\t   APPAT      \t\t    APMAT  \t\t      EDAD \t \t\t CURP\t\t SEXO  \n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0) // Esto es para que solo imprima a los que tienen estatus 1
        {
            printf("%-9d   %-20s   %-20s   %-20s   %-4s/%-4s/%-4s \t %-4s  ", vect[i].matri, vect[i].name.name, vect[i].name.apPat, vect[i].name.apMat, vect[i].fecha.day, vect[i].fecha.month, vect[i].fecha.year, vect[i].curp); // Imprime todos los datos
            if (strcmp(vect[i].sexo, "H"))
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

void impriOne(Todo alum)
{
    printf("STATUS: ");
    printf("%s\n", alum.status == 1 ? "ACTIVO" : "NO ACTIVO");
    printf("MATRICULA: ");
    printf("%d\n", alum.matri);
    printf("NOMBRE: ");
    printf("%s\n", alum.name.name);
    printf("AP. PATERNO: ");
    printf("%s\n", alum.name.apPat);
    printf("AP. MATERNO: ");
    printf("%s\n", alum.name.apMat);
    printf("FECHA NAC: ");
    printf("%2s-%2s-%4s\n", alum.fecha.day, alum.fecha.month, alum.fecha.year);
    printf("SEXO: ");
    printf("%s\n", alum.sexo);
    printf("CURP: ");
    printf("%s\n", alum.curp);
}

// Esta funcion ordena el vector por matriculas, es booleana para que la bandera sepa que ya esta ordenado
bool ordVect(Todo vect[], int n)
{
    int i, j;
    Todo aux;

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

bool ordVectQuick(Todo vect[])
{
    int n;
    n = sizeof(vect) / sizeof(vect[0]);
    qsort(vect, n, sizeof(int), compararEnteros);
    return true;
}

int compararEnteros(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Esta funcion genera a un alumno de manera aleatoria
Todo genAlumRan(Todo *alum, int alumnos)
{
    char nameH[20][30] = {"RODRIGO", "ERNESTO", "PEDRO", "ISMAEL", "CARLOS", "JUAN", "LUIS", "ANGEL", "ANTONIO", "OMAR", "ISRAEL", "EDGAR", "ARMANDO", "ENRIQUE", "RICARDO", "JAVIER", "ALFREDO", "ALEX", "MIGUEL", "MANUEL"};
    char nameM[20][30] = {"GABRIELA", "ROSARIO", "SOFIA", "TRINIDAD", "GABRIELA", "LUISA", "MONICA", "MELISSA", "JAZMIN", "JANNETH", "DANNA", "LIZETH", "XIMENA", "TALIA", "ESTHER", "ISIS", "LUCIA", "ISABELA", "ISABEL", "ANA"};
    char lastname[40][30] = {"PEREZ", "RODRIGUEZ", "BUSTAMANTE", "GONZALEZ", "VAZQUEZ", "GUZMAN", "FERNANDEZ", "OSUNA", "VILLEGAS", "BUENO", "CORTES", "CORONADO0", "SANCHEZ", "SILVA", "OROZCO", "MARTINEZ", "GOMEZ", "ANDA", "FLORES", "JAUREGUI", "DIAZ", "VALENZUELA", "OCTAVIANO", "MORALES", "RABAGO", "PACHECO", "DUARTE", "DIARTE", "COLOMO", "CASTRO", "MORENO", "TORRES", "ORTIZ", "GUTIERRREZ", "CONCLIN", "ISLAS", "REYES", "CAZARES", "MEDINA", "MELENDEZ"};
    char name1[30], apPat[30], apMat[30], curp[19], dayCad[3], monthCad[3], yearCad[3];

    int sex, est, year, month, day, bi = FALSE;

    alum[alumnos].status = 1;
    alum[alumnos].matri = nrand(300000, 399999);              // Genera una matricula aleatoria
    strcpy(alum[alumnos].name.apPat, lastname[nrand(0, 39)]); // Toma uno de los apellidos/nombres de manera aleatoria
    strcpy(alum[alumnos].name.apMat, lastname[nrand(0, 39)]);

    sex = rand() % 2 + 1;
    if (sex == 1)
    {
        strcpy(alum[alumnos].sexo, "H");
    }
    else
    {
        strcpy(alum[alumnos].sexo, "M");
    }

    if (sex == 1)
    {
        strcpy(alum[alumnos].name.name, nameH[nrand(0, 19)]);
    }
    else
    {
        strcpy(alum[alumnos].name.name, nameM[nrand(0, 19)]);
    }

    year = rand() % (2023 - 1900 + 1) + 1900;
    snprintf(alum[alumnos].fecha.year, sizeof(alum[alumnos].fecha.year), "%d", year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        bi = TRUE;
    }

    if (year == 2023)
    {
        month = rand() % 11 + 1;
    }
    else
    {
        month = rand() % 12 + 1;
    }
    snprintf(alum[alumnos].fecha.month, sizeof(alum[alumnos].fecha.month), "%d", month);

    if (month == 2)
    {
        if (bi == TRUE)
        {
            day = rand() % 29 + 1;
        }
        else
        {
            day = rand() % 28 + 1;
        }
    }
    else
    {
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            day = rand() % 30 + 1;
        }
        else
        {
            day = rand() % 31 + 1;
        }
    }
    snprintf(alum[alumnos].fecha.day, sizeof(alum[alumnos].fecha.day), "%d", day);

    est = rand() % 33 + 1;

    alum[alumnos].state = est;

    sprintf(dayCad, "%02d", day);
    sprintf(monthCad, "%02d", month);
    sprintf(yearCad, "%02d", year % 100);

    curp[0] = primeraLetra(alum[alumnos].name.apPat) ? primeraLetra(alum[alumnos].name.apPat) : 'X';
    curp[1] = buscavocal(alum[alumnos].name.apPat);
    curp[2] = primeraLetra(alum[alumnos].name.apMat) ? primeraLetra(alum[alumnos].name.apMat) : 'X';
    curp[3] = primeraLetra(alum[alumnos].name.name);
    curp[4] = yearCad[0];
    curp[5] = yearCad[1];
    curp[6] = monthCad[0];
    curp[7] = monthCad[1];
    curp[8] = dayCad[0];
    curp[9] = dayCad[1];
    curp[10] = alum[alumnos].sexo[0];
    curpState(curp, est);
    curp[13] = buscaCons(alum[alumnos].name.apPat);
    curp[14] = buscaCons(alum[alumnos].name.apMat);
    curp[15] = buscaCons(alum[alumnos].name.name);
    curpHomonimia(curp, yearCad);

    strcpy(alum[alumnos].curp, curp);
    strcpy(alum[alumnos].fecha.day, dayCad);
    strcpy(alum[alumnos].fecha.month, monthCad);
    strcpy(alum[alumnos].fecha.year, yearCad);
    alum[alumnos].state = est;

    // printf("%s ", alum[alumnos].name.name);
    // system("pause");

    return alum[alumnos];
}

// Esta funcion genera un alumno de manera manual
Todo genAlumMan(Todo *alum, int alumnos)
{
    char name1[30], name2[30], apPat[30], apMat[30], sexo[2], state[3], day[3], month[3], year[5], curp[19];
    int op, sex, edo;

    alum[alumnos].status = validar("Estatus (0. No activo, 1. Activo): ", 0, 1);
    system("CLS");

    alum[alumnos].matri = validar("Matricula (Entre 300000 y 399999): ", 300000, 399999); // Te valida la matricula y en el menu te dice si es que ya se encuentra
    system("CLS");

    op = validar("Tiene apellido paterno? \n1. SI \n0. NO\n", 0, 1);
    while (op == 1)
    {
        do
        {
            printf("\nApellido Paterno: ");
        } while (validarCad(apPat) == 1);
        op = 0;
    }

    op = validar("Tiene apellido Materno? \n1. SI \n0. NO\n", 0, 1);
    while (op == 1)
    {
        do
        {
            printf("\nApellido Materno: ");
        } while (validarCad(apMat) == 1);
        op = 0;
    }

    do
    {
        printf("\nNombre: ");
    } while (validarCad(name1) == 1);

    op = validar("Tiene mas nombres? \n1. SI \n0. NO\n", 0, 1);
    while (op == 1)
    {
        do
        {
            printf("\nDemas Nombres: ");
        } while (validarCad(name2) == 1);
        op = 0;
        strcpy(alum[alumnos].name.name2, name2);
    }

    sex = validar("Sexo (1. Hombre, 2. Mujer): ", 1, 2);
    itoa(sex, sexo, 3);
    system("CLS");

    fecha(day, month, year);
    system("CLS");

    system("pause");
    states();
    edo = validar("Ingresa el numero del estado: ", 1, 33);
    snprintf(state, sizeof(state), "%d", edo);

    curpmain(name1, name2, apPat, apMat, state, sexo, day, month, year, curp, alum, alumnos);

    strcpy(alum[alumnos].name.name, name1);
    strcpy(alum[alumnos].name.apPat, apPat);
    strcpy(alum[alumnos].name.apMat, apMat);
    strcpy(alum[alumnos].curp, curp);
    strcpy(alum[alumnos].fecha.day, day);
    strcpy(alum[alumnos].fecha.month, month);
    strcpy(alum[alumnos].fecha.year, year);
    // alum[alumnos].sexo = atoi(sexo);
    alum[alumnos].state = atoi(state);
    if (sex == 1)
    {
        strcpy(alum[alumnos].sexo, "H");
    }
    else
    {
        strcpy(alum[alumnos].sexo, "M");
    }

    return alum[alumnos];
}

// Esta funcion busca la matricula de manera secuencial (desordenado)
int busqSeqMatricula(Todo vect[], int n, int matri)
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
int busqMatricula(Todo vect[], int n, int matri, bool band)
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
int busqBin(Todo vect[], int n, int matri)
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

void archivo(Todo vect[], int n)
{
    int i;
    FILE *fa;
    fa = fopen("registros.txt", "w");
    fprintf(fa, "MATRICULA   NOMBRE         APPAT         APMAT          EDAD \t \t\t CURP\t\t SEXO  \n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            fprintf(fa, "%-9d   %-15s   %-10s   %-10s   %-4s/%-4s/%-4s \t %-4s  %s\n", vect[i].matri, vect[i].name.name, vect[i].name.apPat, vect[i].name.apMat, vect[i].fecha.day, vect[i].fecha.month, vect[i].fecha.year, vect[i].curp, vect[i].sexo);
        }
    }

    printf("Archivo escrito con exito");
    fclose(fa);
    system("pause");
}