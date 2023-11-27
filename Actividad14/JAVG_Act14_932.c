// Jorge Antono Vazquez Guzman 372504
// 14 de noviembre de 2023
// Esqueleto de actividad 13
// JAVG_Act13_932

#include "procesos.h"
#define N 5000
#define TRUE 1
#define FALSE 0

// Declaracion de prototipos de funciones
void menu();
void imprimir(TWrkr vect[], int n);
void imprimirIn(Tindex vect[], int n);
Tindex genAlumRan(Tindex *alum, int alumnos, char nom[]);
int busqSeqMatricula(TWrkr index[], int n, int matri);
int busqBin(TWrkr vect[], int n, int matri);
bool ordVect(Tindex vect[], int n);
bool ordVectQuick(Tindex vect[]);
int compararEnteros(const void *a, const void *b);
void archivo(TWrkr vect[], int n, char nom2[]);
void archivoIn(Tindex vect[], int n, char nom2[]);
void impriOne(TWrkr alum);
int readFile(Tindex vect[], int *i, char nom[]);
void addData(Tindex alum[], int alumnos, char nom[]);
void archivoBorrados(Tindex vect[], int n);
void archivoActPrin(Tindex vect[], int n);
void imprimirBorrados(Tindex vect[], int n);
void archivoBin(Tindex vect[], int n);
int cargarBin(Tindex vect[], int n);
bool cargarIndex(Tindex index[], int *alumnos, TWrkr vect[]);
void eliminar(TWrkr index[], int alumnos, bool band);
void buscarReg(Tindex index[], int alumnos, bool band);

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
    int op, i, j, alumnos = 0, matri, new, bandCar = FALSE, tDatos = 0, op2;
    char nom2[30];
    bool band, cargado = FALSE;
    tDatos = 3360;
    tDatos *= 1.25;       // Tamaño de vector
    TWrkr vect[tDatos];   // El vector donde se guarda toda la informacion
    Tindex index[tDatos]; // La copia del vector
    cargado = cargarIndex(index, &alumnos, vect);

    do
    {

        system("CLS");
        printf("\n \t MENU");
        printf("\n1. AGREGAR");
        printf("\n2. ELIMINAR");                     // TODO: LOGRADO
        printf("\n3. BUSCAR");                       // TODO: LOGRADO
        printf("\n4. ORDENAR");                      // TODO: LOGRADO
        printf("\n5. IMPRIMIR REGISTROS ORIGINAL");  // TODO: LOGRADO
        printf("\n6. IMPRIMIR REGISTROS ORDENADO "); // TODO: LOGRADO
        printf("\n7. CREAR ARCHIVO DE TEXTO");       // TODO: LOGRADO
        printf("\n8. EMPAQUETAR");
        printf("\n0. SALIR");                            // TODO: LOGRADO
        op = validar("\n INGRESA UNA OPCION: \n", 0, 8); // Valida las opciones

        switch (op)
        {
        case 1:

            break;
        case 2:
            eliminar(vect, alumnos, band);
            system("pause");
            break;
        case 3:
            buscarReg(vect, alumnos, band);
            system("pause");
            break;
        case 4:
            if (band == true) // Esto es para saber si el vector ya esta ordenado y no lo haga otra vez
            {
                printf("El vector ya esta ordenado\n");
                system("pause");
            }
            else
            {
                if (alumnos < 500)
                {
                    band = ordVect(index, alumnos);
                    printf("El vector se ha ordenado con exito usando Bubble Sort\n");
                    system("pause");
                }
                else
                {
                    band = ordVectQuick(index);
                    printf("El vector se ha ordenado con exito usando el metodo de QuickSort\n");
                    system("pause");
                }
            }
            break;
        case 5:
            imprimir(vect, alumnos); // Vect contiene los registros tal cual el original
            break;
        case 6:
            imprimirIn(index, alumnos); // Index contiene los registros ordenados (modificados)
            break;
        case 7:
            system("cls");
            printf("INGRESE EL NOMBRE QUE DESEA PARA EL ARCHIVO: (NO AGREGUE EXTENSIONES): ");
            fflush(stdin);
            gets(nom2);
            printf("DESEA GENERAR EL ARCHIVO DE TEXTO DE LOS REGISTROS ORDENADOS O NORMAL?");
            op2 = validar("\n1. ORDENADOS\n2. NORMAL\n", 1, 2);
            if (op2 == 1)
            {
                archivoIn(index, alumnos, nom2);
            }
            else
            {
                archivo(vect, alumnos, nom2);
            }

            break;
        case 8:
            printf("Ingrese el nombre del archivo (NO AGREGUE EXTENSIONES): ");
            fflush(stdin);
            gets(nom2);

            printf("nose");
            imprimir(vect, alumnos);

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

bool cargarIndex(Tindex index[], int *alumnos, TWrkr vect[])
{
    TWrkr temp;
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
        return false; // Agregamos un return false para indicar un error
    }
    else
    {
        while (fread(&temp, sizeof(TWrkr), 1, fa))
        {
            if (temp.status == 1)
            {
                vect[i] = temp;
                index[i].enrollment = temp.enrollment;
                index[i].indice = i;
                (*alumnos)++;
                i++;
            }
        }

        fclose(fa);
        return true;
    }
}

void eliminar(TWrkr index[], int alumnos, bool band)
{
    Tkey i;
    int num, op;
    FILE *fa;
    TWrkr reg;
    num = validar("\n Ingresa la matricula a eliminar: ", 300000, 399999);
    if (band == true)
    {
        i = busqBin(index, alumnos, num);
    }
    else
    {
        i = busqSeqMatricula(index, alumnos, num);
    }

    if (i != -1)
    {
        fa = fopen("datos.dat", "rb+");
        fseek(fa, index[i].enrollment * sizeof(TWrkr), SEEK_SET);
        fread(&reg, sizeof(TWrkr), 1, fa);
        impriOne(reg);
        op = validar("\nDesea eliminarlo? 1. Si\n2. No  ", 1, 2);
        if (op == 1)
        {
            reg.status = 0;
            fseek(fa, index[i].enrollment * sizeof(TWrkr), SEEK_SET);
            fwrite(&reg, sizeof(TWrkr), 1, fa);
            printf("Se ha eliminado con exito\n");
        }
        else
        {
            printf("No se ha eliminado\n");
        }
        fclose(fa);
    }
    else
    {
        printf("No se ha encontrado\n");
    }

    return i;
}

void buscarReg(Tindex index[], int alumnos, bool band)
{
    Tkey i;
    int num;
    FILE *fa;
    TWrkr reg;
    num = validar("\n Ingresa la matricula a buscar: ", 300000, 399999);
    if (band == true)
    {
        i = busqBin(index, alumnos, num);
    }
    else
    {
        i = busqSeqMatricula(index, alumnos, num);
    }

    if (i != -1)
    {
        fa = fopen("datos.dat", "rb+");
        fseek(fa, index[i].indice * sizeof(TWrkr), SEEK_SET);
        fread(&reg, sizeof(TWrkr), 1, fa);
        impriOne(reg);
        fclose(fa);
    }
    else
    {
        printf("No se ha encontrado\n");
    }

    return i;
}

int readFile(Tindex vect[], int *i, char nom[])
{
    Tindex reg;
    FILE *fa;
    int x;
    fa = fopen(nom, "r");
    if (fa == NULL)
    {
        printf("No se ha encontrado el archivo\n");
        system("pause");
    }
    else
    {
        while (fscanf(fa, "%d %d %s %s %s %d %s", &x, &reg.enrollment, reg.name, reg.LastName1, reg.LastName2, &reg.age, reg.sex) == 7)
        {
            if ((*i) < N)
            {
                vect[(*i)++] = reg;
            }
            else
            {
                printf("Se ha llegado al límite\n");
                return 1;
            }
        }
        fclose(fa);
    }
    return 0;
}

// Esta funcion imprime los registros
void imprimir(TWrkr vect[], int n)
{
    int i, on = 0, op;

    system("CLS");
    printf("------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO  | PUESTO      \n");
    printf("------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0) // Esto es para que solo imprima a los que tienen estatus 1
        {
            printf("%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s      %-7s\n", on, vect[i].enrollment, vect[i].name, vect[i].LastName1, vect[i].LastName2, vect[i].age, vect[i].sex, vect[i].JobPosition); // Imprime Tindexs los datos
            on++;
        }

        if ((on) % 40 == 0 && on < n)
        {
            op = validar("\nDesea imprimir mas? 1. Si\n2. No  ", 1, 2);

            if (op == 1)
            {
                system("CLS");
                printf("Registros %d - %d\n\n", on + 1, (on + 40) > n ? n : (on + 40));
                printf("------------------------------------------------------------------------------------------\n");
                printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO  | PUESTO      \n");
                printf("------------------------------------------------------------------------------------------\n");
            }
            else
            {
                return;
            }
        }
    }
    system("pause");
}

void imprimirIn(Tindex vect[], int n)
{
    int i, on = 0, op;

    system("CLS");
    printf("-------------------\n");
    printf("  No  | MATRICULA |\n");
    printf("-------------------\n");
    for (i = 0; i < n; i++)
    {

        printf("%4d.-  %6d\n", vect[i].indice, vect[i].enrollment);
        on++;

        if ((on) % 40 == 0 && on < n)
        {
            op = validar("\nDesea imprimir mas? 1. Si\n2. No  ", 1, 2);

            if (op == 1)
            {
                system("CLS");
                printf("Registros %d - %d\n\n", on + 1, (on + 40) > n ? n : (on + 40));
                printf("-------------------\n");
                printf("  No  | MATRICULA |\n");
                printf("-------------------\n");
            }
            else
            {
                return;
            }
        }
    }
    system("pause");
}

void impriOne(TWrkr alum)
{
    printf("1. STATUS: ");
    printf("%s\n", alum.status == 1 ? "ACTIVO" : "NO ACTIVO");
    printf("2. MATRICULA: ");
    printf("%d\n", alum.enrollment);
    printf("3. NOMBRE: ");
    printf("%s\n", alum.name);
    printf("4. AP. PATERNO: ");
    printf("%s\n", alum.LastName1);
    printf("5. AP. MATERNO: ");
    printf("%s\n", alum.LastName2);
    printf("6. EDAD: ");
    printf("%d\n", alum.age);
    printf("7. SEXO: ");
    printf("%s\n", alum.sex);
    printf("8. PUESTO: ");
    printf("%s\n", alum.JobPosition);
}

// Esta funcion ordena el vector por matriculas, es booleana para que la bandera sepa que ya esta ordenado
bool ordVect(Tindex vect[], int n)
{
    int i, j;
    Tindex aux;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j].enrollment <= vect[i].enrollment) // Condicion para ordenar por bubble sort
            {
                aux = vect[i];
                vect[i] = vect[j];
                vect[j] = aux;
            }
        }
    }
    return true;
}

bool ordVectQuick(Tindex vect[])
{
    int n = 0;
    n = sizeof(vect) / sizeof(vect[0]);
    qsort(vect, n, sizeof(int), compararEnteros);
    return true;
}

int compararEnteros(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Esta funcion genera a un alumno de manera aleatoria
Tindex genAlumRan(Tindex *alum, int alumnos, char nom[])
{
    char nameH[20][30] = {"RODRIGO", "ERNESTO", "PEDRO", "ISMAEL", "CARLOS", "JUAN", "LUIS", "ANGEL", "ANTONIO", "OMAR", "ISRAEL", "EDGAR", "ARMANDO", "ENRIQUE", "RICARDO", "JAVIER", "ALFREDO", "ALEX", "MIGUEL", "MANUEL"};
    char nameM[20][30] = {"GABRIELA", "ROSARIO", "SOFIA", "TRINIDAD", "GABRIELA", "LUISA", "MONICA", "MELISSA", "JAZMIN", "JANNETH", "DANNA", "LIZETH", "XIMENA", "TALIA", "ESTHER", "ISIS", "LUCIA", "ISABELA", "ISABEL", "ANA"};
    char lastname[40][30] = {"PEREZ", "RODRIGUEZ", "BUSTAMANTE", "GONZALEZ", "VAZQUEZ", "GUZMAN", "FERNANDEZ", "OSUNA", "VILLEGAS", "BUENO", "CORTES", "CORONADO0", "SANCHEZ", "SILVA", "OROZCO", "MARTINEZ", "GOMEZ", "ANDA", "FLORES", "JAUREGUI", "DIAZ", "VALENZUELA", "OCTAVIANO", "MORALES", "RABAGO", "PACHECO", "DUARTE", "DIARTE", "COLOMO", "CASTRO", "MORENO", "TORRES", "ORTIZ", "GUTIERRREZ", "CONCLIN", "ISLAS", "REYES", "CAZARES", "MEDINA", "MELENDEZ"};
    char chambas[10][30] = {"GERENTE", "SECRETARIA", "CAJERO", "VENDEDOR", "REPARTIDOR", "LIMPIADOR", "MESERO", "COCINERO", "GUARDIA", "CHOFER"};
    char name1[30], apPat[30], apMat[30], curp[19], dayCad[3], monthCad[3], yearCad[3];
    int edad = 0;
    int sex, est, year, month, day, bi = FALSE;

    alum[alumnos].status = 1;
    alum[alumnos].enrollment = nrand(300000, 399999);        // Genera una matricula aleatoria
    alum[alumnos].enrollment = alum[alumnos].enrollment;     // Guarda la matricula en la llave
    strcpy(alum[alumnos].LastName1, lastname[nrand(0, 39)]); // Toma uno de los apellidos/nombres de manera aleatoria
    strcpy(alum[alumnos].LastName2, lastname[nrand(0, 39)]);
    strcpy(alum[alumnos].JobPosition, chambas[nrand(0, 9)]);

    sex = rand() % 2 + 1;
    if (sex == 1)
    {
        strcpy(alum[alumnos].sex, "MASCULINO");
    }
    else
    {
        strcpy(alum[alumnos].sex, "FEMENINO");
    }

    if (sex == 1)
    {
        strcpy(alum[alumnos].name, nameH[nrand(0, 19)]);
    }
    else
    {
        strcpy(alum[alumnos].name, nameM[nrand(0, 19)]);
    }

    alum[alumnos].age = nrand(18, 60);

    //! addData(alum, alumnos, nom);

    return alum[alumnos];
}

// Agrega los datos al archivo
void addData(Tindex alum[], int alumnos, char nom[])
{
    FILE *fa;
    int x = 0;
    fa = fopen(nom, "a");
    if (fa == NULL)
    {
        printf("No se ha encontrado el archivo\n");
        system("pause");
    }
    else
    {
        fprintf(fa, "%d %d %s %s %s %d %s\n", x, alum[alumnos].enrollment, alum[alumnos].name, alum[alumnos].LastName1, alum[alumnos].LastName2, alum[alumnos].age, alum[alumnos].sex);
        x++;
        fclose(fa);
    }
}

// Esta funcion busca la matricula de manera secuencial (desordenado)
int busqSeqMatricula(TWrkr index[], int n, int matri)
{
    int i;

    for (i = 0; i < n; i++) // Recorre
    {
        if (index[i].enrollment == matri) // Compara
        {
            return i; // Si esta
        }
    }
    return -1; // No esta
}

// Esta funcion busca la matricula de manera binaria (ordenado)
int busqBin(TWrkr vect[], int n, int matri)
{
    int med, ri = 0, rf = n;
    while (ri <= rf) // Cuando haya un rango existente entra
    {
        med = ri + (rf - ri) / 2; // Encuentra el medio de los datos

        if (vect[med].enrollment == matri) // Se encuentra en la posicion 0 (1)
        {
            return med + 1; // Retorna la posicion con un +1 para no estar en la posicion 0
        }

        if (vect[med].enrollment < matri) // Si estas condiciones se cumples se reduce el rango o aumenta
        {
            ri = med++;
        }

        if (vect[med].enrollment > matri)
        {
            rf = med--;
        }
    }

    return -1; // No se encontro
}

void archivo(TWrkr vect[], int n, char nom2[])
{
    int i;
    FILE *fa;
    strcat(nom2, ".txt");
    fa = fopen(nom2, "w");
    fprintf(fa, "MATRICULA   NOMBRE         APPAT         APMAT          EDAD \t \t\t SEXO \t \t PUESTO  \n");
    for (i = 0; i < n; i++)
    {
        fprintf(fa, "%-9d   %-15s   %-10s   %-10s   %-4d \t %-4s\t%-4s\n", vect[i].enrollment, vect[i].name, vect[i].LastName1, vect[i].LastName2, vect[i].age, vect[i].sex, vect[i].JobPosition);
    }

    printf("Archivo escrito con exito");
    fclose(fa);
    system("pause");
}

void archivoIn(Tindex vect[], int n, char nom2[])
{
    int i;
    FILE *fa;
    strcat(nom2, ".txt");
    fa = fopen(nom2, "w");
    fprintf(fa, "MATRICULA   NOMBRE         APPAT         APMAT          EDAD \t \t\t SEXO \t \t PUESTO  \n");
    for (i = 0; i < n; i++)
    {
        fprintf(fa, "%-9d   %-15s   %-10s   %-10s   %-4d \t %-4s\t%-4s\n", vect[i].enrollment, vect[i].name, vect[i].LastName1, vect[i].LastName2, vect[i].age, vect[i].sex, vect[i].JobPosition);
    }

    printf("Archivo escrito con exito");
    fclose(fa);
    system("pause");
}

void archivoBorrados(Tindex vect[], int n)
{
    int i;
    FILE *fa;
    fa = fopen("borrados.txt", "w");
    fprintf(fa, "MATRICULA   NOMBRE         APPAT         APMAT          EDAD \t \t\t SEXO  \n");
    for (i = 0; i <= n; i++)
    {
        if (vect[i].status == 0)
        {
            fprintf(fa, "%-9d   %-15s   %-10s   %-10s   %-4d \t %-4s\n", vect[i].enrollment, vect[i].name, vect[i].LastName1, vect[i].LastName2, vect[i].age, vect[i].sex);
        }
    }

    printf("Archivo escrito con exito");
    fclose(fa);
    system("pause");
}

void archivoBin(Tindex vect[], int n)
{
    FILE *fa;
    char nom[11] = "datos.dll";
    rename("datos.dll", "datos.tmp");
    fa = fopen(nom, "wb");
    if (fa == NULL)
    {
        printf("No se ha encontrado el archivo\n");
        system("pause");
    }
    else
    {
        fwrite(vect, sizeof(Tindex), n, fa);
        fclose(fa);
    }
}

int cargarBin(Tindex vect[], int n)
{
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dll", "rb");
    if (fa == NULL)
    {
        printf("No se ha encontrado el archivo\n");
        system("pause");
    }
    else
    {
        while (fread(&vect[i], sizeof(Tindex), 1, fa) == 1 && n < N)
        {
            vect[i].status = nrand(0, 1);
            vect[i].enrollment = vect[i].enrollment;
            i++;
        }
        fclose(fa);
        printf("El archivo se ha cargado con exito\n");
        system("pause");
    }
    return i;
}
