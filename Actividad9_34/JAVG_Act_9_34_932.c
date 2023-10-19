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
void curpFecha(char curp[], char sday[], char smonth[], char syear[]);
void curpSexo(char curp[], char ssex[]);
void curpState(char curp[], char sstate[]);
void curpConso(char curp[], char apPat[], char apMat[], char name[], char name2[]);

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
        op = validar("Seleccione una opcion: ", 0, 1);

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
    char curp[19], apPat[30], apMat[30], name[20], name2[20], sday[10], smonth[10], syear[10], ssex[10], sstate[10];

    system("cls");
    genData(name, name2, apPat, apMat, sday, smonth, syear, ssex, sex, state, day, month, year, sstate);
    inicio4(apPat, apMat, name, name2, curp);
    curpFecha(curp, sday, smonth, syear);
    curpSexo(curp, ssex);
    curpState(curp, sstate);
    curpConso(curp, apPat, apMat, name, name2);

    curp[16] = '\0';
    system("cls");
    for (int i = 0; i < 16; i++)
    {
        printf("%c", curp[i]);
    }
    printf("\n");
    system("pause");
}

void genData(char name[], char name2[], char apPat[], char apMat[], char sday[], char smonth[], char syear[], char ssex[], int sex, int state, int day, int month, int year, char sstate[])
{
    printf("APELLIDO PATERNO: ");
    fflush(stdin);
    gets(apPat);
    removeEspacios(apPat);
    validEnie(apPat);
    convmayus(apPat);

    system("cls");
    printf("APELLIDO MATERNO: ");
    fflush(stdin);
    gets(apMat);
    removeEspacios(apMat);
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
    removeEspacios(name);
    removeEspacios(name2);
    convmayus(name);
    convmayus(name2);

    system("cls");
    printf("SEXO:\n");
    printf("1. HOMBRE\n2. MUJER\n");
    do
    {
        sex = validar("INGRESA TU SEXO: ", 1, 2);
        itoa(sex, ssex, 10);
    } while (sex == 0);

    system("cls");
    fecha(day, month, year, sday, smonth, syear);

    system("pause");
    do
    {
        states();
        state = validar("INGRESA TU ESTADO DE NACIMIENTO: ", 1, 33);
        itoa(state, sstate, 10);
    } while (state == 0);
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

    itoa(day, sday, 10);
    itoa(month, smonth, 10);
    itoa(year, syear, 10);
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
    printf("33. Extranjero\n");
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
    i = 0;
    do
    { // Verifica que las 4 iniciales no este en las palabras inconvenientes
        band = FALSE;
        same = 0;
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
        i++;
    } while (band == TRUE && i < 81);

    for (i = 0; i < 4; i++)
    {
        curp[i] = iniciales[i];
    }
}

void curpFecha(char curp[], char sday[], char smonth[], char syear[])
{
    int mes, dia;
    dia = atoi(sday);
    mes = atoi(smonth);

    curp[4] = syear[2];
    curp[5] = syear[3];

    if (mes < 10)
    {
        curp[6] = '0';
        curp[7] = smonth[0];
    }
    else
    {
        curp[6] = smonth[0];
        curp[7] = smonth[1];
    }

    if (dia < 10)
    {
        curp[8] = '0';
        curp[9] = sday[0];
    }
    else
    {
        curp[8] = sday[0];
        curp[9] = sday[1];
    }
}

void curpSexo(char curp[], char ssex[])
{
    if (ssex[0] == '1')
    {
        curp[10] = 'H';
    }
    else
    {
        curp[10] = 'M';
    }
}

void curpState(char curp[], char sstate[])
{
    int i, estado;
    estado = atoi(sstate);
    i = estado - 1;
    char iniEstado[33][3] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};
    curp[11] = iniEstado[i][0];
    curp[12] = iniEstado[i][1];
}

void curpConso(char curp[], char apPat[], char apMat[], char name[], char name2[])
{
    int band, i = 0;
    char jose[4] = "JOSE";
    char maria[5] = "MARIA";
    curp[13] = buscaCons(apPat);
    curp[14] = buscaCons(apMat);

    band = FALSE;
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

    if (band)
    {
        curp[15] = buscaCons(name);
    }
    else
    {
        curp[15] = buscaCons(name2);
    }
}
