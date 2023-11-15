// Jorge Antono Vazquez Guzman 372504
// 14 de noviembre de 2023
// Esqueleto de actividad 13
// JAVG_Act13_932

#include "procesos.h"
#define N 5000

typedef long Tkey;

typedef struct _nom
{
    char name[30];
    char apPat[30];
    char apMat[30];
} Tname;

typedef struct _fecha
{
    char day[3];
    char month[3];
    char year[5];
    int edad;
} Tfecha;

typedef struct _personas
{
    int status;
    Tkey key;
    int matri;
    Tname name;
    Tfecha fecha;
    char puesto[30];
    char sexo[11];
} Todo;

// Declaracion de prototipos de funciones
void menu();
void imprimir(Todo vect[], int n);
Todo genAlumRan(Todo *alum, int alumnos, char nom[]);
int busqSeqMatricula(Todo vect[], int n, int matri);
int busqMatricula(Todo vect[], int n, int matri, bool band);
int busqBin(Todo vect[], int n, int matri);
bool ordVect(Todo vect[], int n);
bool ordVectQuick(Todo vect[]);
int compararEnteros(const void *a, const void *b);
void archivo(Todo vect[], int n, char nom2[]);
void impriOne(Todo alum);
int readFile(Todo vect[], int *i, char nom[]);
void addData(Todo alum[], int alumnos, char nom[]);
void archivoBorrados(Todo vect[], int n);
void archivoActPrin(Todo vect[], int n);
void imprimirBorrados(Todo vect[], int n);
int archivoBin(Todo vect[], int n, char nom2[]);
int cargarBin(Todo vect[], int n, int max);

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
    int op, i, j, alumnos = 0, matri, op1 = FALSE, con, total = 0, opEdit, max=0, new, bandCar=FALSE;
    char nom2[30], name[30];
    bool band;
    Todo alum[N]; // Un solo alumno
    Todo vect[N]; // El vector donde se guarda toda la informacion

    system("CLS");
    do
    {

        printf("\n \t MENU");
        printf("\n1. AGREGAR AUTOMATICO (100)"); // TODO: LOGRADO
        printf("\n2. EDITAR REGISTRO");          // TODO: LOGRADO
        printf("\n3. ELIMINAR REGISTRO");        // TODO: LOGRADO
        printf("\n4. BUSCAR");                   // TODO: LOGRADO
        printf("\n5. ORDENAR");                  // TODO: LOGRADO
        printf("\n6. IMPRIMIR");                 // TODO: LOGRADO
        printf("\n7. GENERAR ARCHIVO DE TEXTO"); // TODO: LOGRADO
        printf("\n8. VER ARCHIVO DE TEXTO");     //! no entendi bien
        printf("\n9. CREAR ARCHIVO BINARIO");    // TODO: LOGRADO
        printf("\n10. CARGAR ARCHIVO BINARIO");
        printf("\n11. MOSTRAR ELIMINADOS");
        printf("\n0. SALIR");                             // TODO: LOGRADO
        op = validar("\n INGRESA UNA OPCION: \n", 0, 11); // Valida las opciones

        switch (op)
        {
        case 1:
            if ((alumnos + 100) <= N) // Esto es para llenar 100 registros solamente, siempre y cuando no superen el limite
            {
                for (j = 0; j < 100; j++)
                {
                    if ((alumnos + 1) <= N)
                    {
                        alum[alumnos] = genAlumRan(alum, alumnos, "datos.txt"); // Funcion que genera al alumno aleatorio

                        while (busqSeqMatricula(vect, alumnos, alum[alumnos].matri) != -1) // Esto busca que no se repita la matricula
                        {
                            alum[alumnos].matri = nrand(300000, 399999); // Genera la matricula
                            alum[alumnos].key = alum[alumnos].matri;
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
            matri = validar("Ingresa una matricula a editar: ", 300000, 399999);
            i = busqMatricula(vect, alumnos, matri, band);
            if (i != -1 && vect[i].status != 0)
            {
                impriOne(vect[i]);
                opEdit = ("Ingrese el campo a editar (1-8): ", 1, 8);
                switch (opEdit)
                {
                case 1:
                    vect[i].status = validar("Ingrese el nuevo status: (1. Activo   0. Inactivo): ", 0, 1);
                    break;
                case 2:
                    do
                    {
                        vect[i].matri = validar("Ingrese la nueva matricula: ", 300000, 399999);
                    } while (busqSeqMatricula(vect, alumnos, vect[i].matri) != -1);
                    break;
                case 3:
                    printf("Ingrese el nuevo nombre: ");
                    fflush(stdin);
                    gets(vect[i].name.name);
                    break;
                case 4:
                    printf("Ingrese el nuevo apellido paterno: ");
                    fflush(stdin);
                    gets(vect[i].name.apPat);
                    break;
                case 5:
                    printf("Ingrese el nuevo apellido materno: ");
                    fflush(stdin);
                    gets(vect[i].name.apMat);
                    break;
                case 6:
                    vect[i].fecha.edad = validar("Ingrese la nueva edad: ", 0, 100);
                    break;
                case 7:
                    printf("Ingrese el nuevo sexo: ");
                    fflush(stdin);
                    gets(vect[i].sexo);
                    break;
                case 8:
                    printf("Ingrese el nuevo puesto: ");
                    fflush(stdin);
                    gets(vect[i].puesto);
                    break;
                default:
                    printf("Opcion invalida...");
                    system("PAUSE");
                }
            }
            else
            {
                printf("No se ha encontrado, revisa que este bien escrito. \n");
                system("pause");
            }
            break;
        case 3:
            matri = validar("Ingresa una matricula a eliminar: ", 300000, 399999);
            i = busqMatricula(vect, alumnos, matri, band);

            if (i != -1) // Si esto se cumple es que si se encontro
            {
                if (vect[i].status != 0) // Si el estatus es 1 es porque si estaba activo
                {
                    vect[i].status = 0;
                    impriOne(vect[i]);
                    printf("Se ha eliminado la matricula \n");
                    system("pause");
                    archivoBorrados(vect, i);
                    archivoActPrin(vect, i);
                }
                else
                {
                    impriOne(vect[i]);
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
            imprimir(vect, alumnos);
            break;
        case 7:
            system("cls");
            printf("INGRESE EL NOMBRE QUE DESEA PARA EL ARCHIVO: (NO AGREGUE EXTENSIONES): ");
            fflush(stdin);
            gets(nom2);
            archivo(vect, alumnos, nom2);
            break;
        case 8:
            con = validar("Ingrese el archivo que desea contar: (1. Activos    2. Borrados): ", 1, 2);
            printf("Ingrese el nombre del archivo (NO AGREGUE EXTENSIONES): ");
            fflush(stdin);
            gets(name);

            total = contar(name, con);
            if (total == -1)
            {
                printf("No se ha encontrado el archivo\n");
            }
            else
            {
                printf("El archivo tiene %d registros\n", total);
                system("pause");
            }

            break;
        case 9:
            printf("Ingrese el nombre del archivo binario (NO AGREGUE EXTENSIONES): ");
            fflush(stdin);
            gets(nom2);
            archivoBin(vect, alumnos, nom2);
            break;
        case 10:
            if(bandCar==FALSE){
            max=sizeof(vect)/sizeof(vect[0]);
            new=cargarBin(vect, alumnos, max);
            alumnos=new;
            band=TRUE;
            }
            else{
                printf("Ya se ha cargado el archivo\n");
                system("pause");
            }
            break;
        case 0:
            archivo(vect, alumnos, "datos.txt");
            archivoActPrin(vect, alumnos);
            archivoBorrados(vect, alumnos);
            printf("Hasta luego....\n");
            system("pause");
            break;
        default:
            printf("Opcion invalida...");
            system("PAUSE");
        }
    } while (op != 0); // Cuando es 0 el programa termina
}

int readFile(Todo vect[], int *i, char nom[])
{
    Todo reg;
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
        while (fscanf(fa, "%d %d %s %s %s %d %s", &x, &reg.matri, reg.name.name, reg.name.apPat, reg.name.apMat, &reg.fecha.edad, reg.sexo) == 7)
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
}

// Esta funcion imprime los registros
void imprimir(Todo vect[], int n)
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
            printf("%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s      %-7s\n", on, vect[i].matri, vect[i].name.name, vect[i].name.apPat, vect[i].name.apMat, vect[i].fecha.edad, vect[i].sexo, vect[i].puesto); // Imprime todos los datos
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
        }
    }
    archivoActPrin(vect, n);
    system("pause");
}

void imprimirBorrados(Todo vect[], int n)
{
    int i, on = 0, op;

    system("CLS");
    printf("------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    printf("------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status == 0) // Esto es para que solo imprima a los que tienen estatus 0
        {
            printf("%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s\n", on, vect[i].matri, vect[i].name.name, vect[i].name.apPat, vect[i].name.apMat, vect[i].fecha.edad, vect[i].sexo); // Imprime todos los datos
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
                printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
                printf("------------------------------------------------------------------------------------------\n");
            }
        }
    }
    archivoBorrados(vect, n);
    system("pause");
}

void impriOne(Todo alum)
{
    printf("1. STATUS: ");
    printf("%s\n", alum.status == 1 ? "ACTIVO" : "NO ACTIVO");
    printf("2. MATRICULA: ");
    printf("%d\n", alum.matri);
    printf("3. NOMBRE: ");
    printf("%s\n", alum.name.name);
    printf("4. AP. PATERNO: ");
    printf("%s\n", alum.name.apPat);
    printf("5. AP. MATERNO: ");
    printf("%s\n", alum.name.apMat);
    printf("6. FECHA NAC: ");
    printf("%2s-%2s-%4s\n", alum.fecha.day, alum.fecha.month, alum.fecha.year);
    printf("7. SEXO: ");
    printf("%s\n", alum.sexo);
    printf("8. PUESTO: ");
    printf("%s\n", alum.puesto);
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
            if (vect[j].key <= vect[i].key) // Condicion para ordenar por bubble sort
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
Todo genAlumRan(Todo *alum, int alumnos, char nom[])
{
    char nameH[20][30] = {"RODRIGO", "ERNESTO", "PEDRO", "ISMAEL", "CARLOS", "JUAN", "LUIS", "ANGEL", "ANTONIO", "OMAR", "ISRAEL", "EDGAR", "ARMANDO", "ENRIQUE", "RICARDO", "JAVIER", "ALFREDO", "ALEX", "MIGUEL", "MANUEL"};
    char nameM[20][30] = {"GABRIELA", "ROSARIO", "SOFIA", "TRINIDAD", "GABRIELA", "LUISA", "MONICA", "MELISSA", "JAZMIN", "JANNETH", "DANNA", "LIZETH", "XIMENA", "TALIA", "ESTHER", "ISIS", "LUCIA", "ISABELA", "ISABEL", "ANA"};
    char lastname[40][30] = {"PEREZ", "RODRIGUEZ", "BUSTAMANTE", "GONZALEZ", "VAZQUEZ", "GUZMAN", "FERNANDEZ", "OSUNA", "VILLEGAS", "BUENO", "CORTES", "CORONADO0", "SANCHEZ", "SILVA", "OROZCO", "MARTINEZ", "GOMEZ", "ANDA", "FLORES", "JAUREGUI", "DIAZ", "VALENZUELA", "OCTAVIANO", "MORALES", "RABAGO", "PACHECO", "DUARTE", "DIARTE", "COLOMO", "CASTRO", "MORENO", "TORRES", "ORTIZ", "GUTIERRREZ", "CONCLIN", "ISLAS", "REYES", "CAZARES", "MEDINA", "MELENDEZ"};
    char chambas[10][30] = {"GERENTE", "SECRETARIA", "CAJERO", "VENDEDOR", "REPARTIDOR", "LIMPIADOR", "MESERO", "COCINERO", "GUARDIA", "CHOFER"};
    char name1[30], apPat[30], apMat[30], curp[19], dayCad[3], monthCad[3], yearCad[3];
    int edad = 0;
    int sex, est, year, month, day, bi = FALSE;

    alum[alumnos].status = 1;
    alum[alumnos].matri = nrand(300000, 399999);              // Genera una matricula aleatoria
    alum[alumnos].key = alum[alumnos].matri;                  // Guarda la matricula en la llave
    strcpy(alum[alumnos].name.apPat, lastname[nrand(0, 39)]); // Toma uno de los apellidos/nombres de manera aleatoria
    strcpy(alum[alumnos].name.apMat, lastname[nrand(0, 39)]);
    strcpy(alum[alumnos].puesto, chambas[nrand(0, 9)]);

    sex = rand() % 2 + 1;
    if (sex == 1)
    {
        strcpy(alum[alumnos].sexo, "MASCULINO");
    }
    else
    {
        strcpy(alum[alumnos].sexo, "FEMENINO");
    }

    if (sex == 1)
    {
        strcpy(alum[alumnos].name.name, nameH[nrand(0, 19)]);
    }
    else
    {
        strcpy(alum[alumnos].name.name, nameM[nrand(0, 19)]);
    }

    year = rand() % (2023 - 1943 + 1) + 1943;
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
    edad = 2023 - year;
    alum[alumnos].fecha.edad = edad;

    sprintf(dayCad, "%02d", day);
    sprintf(monthCad, "%02d", month);
    sprintf(yearCad, "%02d", year % 100);

    strcpy(alum[alumnos].fecha.day, dayCad);
    strcpy(alum[alumnos].fecha.month, monthCad);
    strcpy(alum[alumnos].fecha.year, yearCad);

    // printf("%s ", alum[alumnos].name.name);
    // system("pause");

    addData(alum, alumnos, nom);

    return alum[alumnos];
}

// Agrega los datos al archivo
void addData(Todo alum[], int alumnos, char nom[])
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
        fprintf(fa, "%d %d %s %s %s %d %s\n", x, alum[alumnos].matri, alum[alumnos].name.name, alum[alumnos].name.apPat, alum[alumnos].name.apMat, alum[alumnos].fecha.edad, alum[alumnos].sexo);
        x++;
        fclose(fa);
    }
}

// Esta funcion busca la matricula de manera secuencial (desordenado)
int busqSeqMatricula(Todo vect[], int n, int matri)
{
    int i;

    for (i = 0; i < n; i++) // Recorre
    {
        if (vect[i].key == matri) // Compara
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

        if (vect[med].key == matri) // Se encuentra en la posicion 0 (1)
        {
            return med + 1; // Retorna la posicion con un +1 para no estar en la posicion 0
        }

        if (vect[med].key < matri) // Si estas condiciones se cumples se reduce el rango o aumenta
        {
            ri = med++;
        }

        if (vect[med].key > matri)
        {
            rf = med--;
        }
    }

    return -1; // No se encontro
}

void archivo(Todo vect[], int n, char nom2[])
{
    int i;
    FILE *fa;
    strcat(nom2, ".txt");
    fa = fopen(nom2, "w");
    fprintf(fa, "MATRICULA   NOMBRE         APPAT         APMAT          EDAD \t \t\t SEXO \t \t PUESTO  \n");
    for (i = 0; i < n; i++)
    {
        fprintf(fa, "%-9d   %-15s   %-10s   %-10s   %-4d \t %-4s\t%-4s\n", vect[i].matri, vect[i].name.name, vect[i].name.apPat, vect[i].name.apMat, vect[i].fecha.edad, vect[i].sexo, vect[i].puesto);
    }

    printf("Archivo escrito con exito");
    fclose(fa);
    system("pause");
}

void archivoBorrados(Todo vect[], int n)
{
    int i;
    FILE *fa;
    fa = fopen("borrados.txt", "w");
    fprintf(fa, "MATRICULA   NOMBRE         APPAT         APMAT          EDAD \t \t\t SEXO  \n");
    for (i = 0; i <= n; i++)
    {
        if (vect[i].status == 0)
        {
            fprintf(fa, "%-9d   %-15s   %-10s   %-10s   %-4d \t %-4s\n", vect[i].matri, vect[i].name.name, vect[i].name.apPat, vect[i].name.apMat, vect[i].fecha.edad, vect[i].sexo);
        }
    }

    printf("Archivo escrito con exito");
    fclose(fa);
    system("pause");
}

void archivoActPrin(Todo vect[], int n)
{
    int i;
    FILE *fa;
    fa = fopen("Activos.txt", "w");
    fprintf(fa, "MATRICULA   NOMBRE         APPAT         APMAT          EDAD \t \t\t SEXO  \n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            fprintf(fa, "%-9d   %-15s   %-10s   %-10s   %-4d \t %-4s\n", vect[i].matri, vect[i].name.name, vect[i].name.apPat, vect[i].name.apMat, vect[i].fecha.edad, vect[i].sexo);
        }
    }
    fclose(fa);
}

int archivoBin(Todo vect[], int n, char nom2[])
{
    int i;
    FILE *fa;
    strcat(nom2, ".dll");
    fa = fopen(nom2, "ba");
    for (i = 0; i < n; i++)
    {
        fwrite(&vect[i], sizeof(Todo), 1, fa);
    }

    printf("Archivo escrito con exito");
    fclose(fa);
    system("pause");
    return 0;
}

int cargarBin(Todo vect[], int n, int max){
    int i;
    FILE *fa;
    fa = fopen("datos.dll", "ba");
    if (fa == NULL)
    {
        printf("No se ha encontrado el archivo\n");
        system("pause");
    }
    else
    {
        while (fread(&vect[i], sizeof(Todo), 1, fa) == 1)
        {
            if(i<max){
            vect[i++]=vect[i];
            }
            else{
                printf("Se ha llegado al limite\n");
                return i;
            }
        }
        fclose(fa);
    }
    return i;
}