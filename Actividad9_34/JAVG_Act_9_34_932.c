#include "procesos.h"
#define TRUE 1
#define FALSE 0

void menu(void);
void curpmain(void);
void genData(char name[], char name2[], char apPat[], char apMat[], char sday[], char smonth[], char syear[], char ssex[], int sex, int state, int day, int month, int year, char sstate[]);
void fecha(int day, int month, int year, char sday[], char smonth[], char syear[]);
void states(void);
void meses(void);
void inicio4(char apPat[], char apMat[], char name[], char name2[], char curp[]);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;

    do
    {
        system("CLS");
        printf("\t\nMenu\n");
        printf("1. Curp\n"),
            printf("0. Salir\n");
        op = validar("Seleccione una opcion", 0, 1);

        switch (op)
        {
        case 0:
            printf("\nAdios...\n");
            system("pause");
            break;
        case 1:
            system("cls");
            curpmain();
            break;
        default:
            printf("\nOpcion invalida...");
            break;
        }
    } while (op != 0);
}

void curpmain()
{
    int sex, day, month, year, state;
    char curp[18], apPat[30], apMat[30], name[20], name2[20], sday[3], smonth[3], syear[5], ssex[3], sstate[3];

    system("cls");
    genData(name, name2, apPat, apMat, sday, smonth, syear, ssex, sex, state, day, month, year, sstate);
    inicio4(apPat, apMat, name, name2, curp);
}

void genData(char name[], char name2[], char apPat[], char apMat[], char sday[], char smonth[], char syear[], char ssex[], int sex, int state, int day, int month, int year, char sstate[])
{
    printf("APELLIDO PATERNO: ");
    fflush(stdin);
    gets(apPat);
    validEnie(apPat);
    convmayus(apPat);

    system("cls");
    printf("APELLIDO MATERNO: ");
    fflush(stdin);
    gets(apMat);
    validEnie(apMat);
    convmayus(apMat);

    system("cls");
    do
    {
        printf("PRIMER NOMBRE: ");
        fflush(stdin);
        gets(name);
        printf("\n SEGUNDO NOMBRE (EN CASO DE TENER): ");
        fflush(stdin);
        gets(name2);
    } while (name[0] == '\0');
    validEnie(name);
    validEnie(name2);
    convmayus(name);
    convmayus(name2);

    system("cls");
    printf("SEXO:\n");
    printf("1. HOMBRE\n2. MUJER\n");
    sex = validar("INGRESA TU SEXO: ", 1, 2);
    itoa(sex, ssex, 3);

    system("cls");
    fecha(day, month, year, sday, smonth, syear);

    system("pause");
    states();
    state = validar("INGRESA TU ESTADO DE NACIMIENTO: ", 1, 32);
    sstate[0] = state;
}

void fecha(int day, int month, int year, char sday[], char smonth[], char syear[])
{
    int bi = FALSE;

    printf("FECHA DE NACIMIENTO\n");
    year = validar("AÑO DE NACIMIENTO (CUATRO DIGITOS): ", 1893, 2023);
    system("cls");
    if (year % 4 == 0)
    {
        bi = TRUE;
    }

    meses();
    month = validar("ELIGE EL NUMERO DE TU MES: ", 1, 12);
    system("cls");
    if (month == 2)
    {
        if (bi == TRUE)
        {
            day = validar("INGRESA EL DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 29);
        }
        else
        {
            day = validar("INGRESA EL DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 28);
        }
    }
    else
    {
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            day = validar("INGRESA TU DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 30);
        }
        else
        {
            day = validar("INGRESA TU DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 31);
        }
    }

    itoa(day, sday, 3);
    itoa(month, smonth, 3);
    itoa(year, syear, 5);
    system("cls");
}

void meses()
{
    system("cls");
    printf("1. Enero\n");
    printf("2. Febrero\n");
    printf("3. Marzo\n");
    printf("4. Abril\n");
    printf("5. Mayo\n");
    printf("6. Junio\n");
    printf("7. Julio\n");
    printf("8. Agosto\n");
    printf("9. Septiembre\n");
    printf("10. Octubre\n");
    printf("11. Noviembre\n");
    printf("12. Diciembre\n");
}

void states()
{
    system("cls");
    printf("1. Aguascalientes\n");
    printf("2. Baja California\n");
    printf("3. Baja California Sur\n");
    printf("4. Campeche\n");
    printf("5. Chiapas\n");
    printf("6. Chihuaha\n");
    printf("7. Coahuila\n");
    printf("8. Colima\n");
    printf("9. Durango\n");
    printf("10. Guanajuato\n");
    printf("11. Guerrero\n");
    printf("12. Hidalgo\n");
    printf("13. Jalisco\n");
    printf("14. Estado de Mexico\n");
    printf("15. Michoacan\n");
    printf("16. Morelos\n");
    printf("17. Nayarit\n");
    printf("18. Nuevo Leon\n");
    printf("19. Oaxaca\n");
    printf("20. Puebla\n");
    printf("21. Queretaro\n");
    printf("22. Quintana Roo\n");
    printf("23. San Luis Potosi\n");
    printf("24. Sinaloa\n");
    printf("25. Sonora\n");
    printf("26. Tabasco \n");
    printf("27. Tamaulipas\n");
    printf("28. Tlaxcala\n");
    printf("29. Veracruz\n");
    printf("30. Yucatan\n");
    printf("31. Zacatecas\n");
    printf("32. Ciudad de Mexico\n");
}

void inicio4(char apPat[], char apMat[], char name[], char name2[], char curp[])
{
    int same, i = 0, j, band = FALSE;
    char iniciales[4];
    char pnegadas[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    char jose[4] = "JOSE";
    char maria[5] = "MARIA";

    if (apPat[0] != 'Ñ')
    {
        iniciales[0] = apPat[0];
    }
    else
    {
        iniciales[0] = 'X';
    }

    iniciales[1] = buscavocal(apPat);
    if (iniciales[1] == '/' || iniciales[1] == '-' || iniciales[1] == '.')
    {
        iniciales[1] = 'X';
    }
    if (apMat[0] == '\0')
    {
        iniciales[2] = 'X';
    }
    else
    {
        iniciales[2] = apMat[0];
    }

    do
    {
        if (name[i] == jose[i])
        {
            i++;
        }
        else
        {
            band = TRUE;
        }
    } while (band == FALSE && i < 4);

    i = 0;
    do
    {
        if (name[i] == maria[i])
        {
            i++;
        }
        else
        {
            band = TRUE;
        }
    } while (band == FALSE && i < 5);

    if (band == TRUE)
    {
        iniciales[3] = name[0];
    }
    else
    {
        iniciales[3] = name2[0];
    }

    j = 0;
    do
    { // Verifica que las 4 iniciales no este en las palabras inconvenientes
        band = FALSE;
        same = 0;
        i = 0;
        do
        {
            if (iniciales[i] == pnegadas[j][i])
            {
                same++;
                i++;
            }
            else
            {
                band = TRUE;
            }
        } while (band == FALSE && i < 4);
        if (same == 4)
        {
            iniciales[1] = 'X';
        }
        j++;
    } while (band == TRUE && i < 81);

    for (i = 0; i < 4; i++)
    {
        curp[i] = iniciales[i];
    }
}
