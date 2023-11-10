#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

void curpmain(char name[], char name2[], char apPat[], char apMat[], char state[], char sexo[], char day[], char month[], char year[], char curp[], Todo alum[], int alumnos);
void curpMainRand(char name[], char apPat[], char apMat[], int state, char sexo[], int day, int month, int year, char curp[]);
void genData(char name[], char name2[], char apPat[], char apMat[]);
void genDataRand(char name[], char apPat[], char apMat[]);
void fecha(char day[], char month[], char year[]);
void states(void);
void meses(void);
void inicio4(char apPat[], char apMat[], char name[], char name2[], char curp[]);
void curpFecha(char curp[], char sday[], char smonth[], char syear[]);
void curpSexo(char curp[], char ssex[]);
void curpState(char curp[], int state);
void curpConso(char curp[], char apPat[], char apMat[], char name[], char name2[]);
void curpHomonimia(char curp[], char syear[]);

void curpmain(char name[], char name2[], char apPat[], char apMat[], char state[], char sexo[], char day[], char month[], char year[], char curp[], Todo alum[], int alumnos)
{
    srand(time(NULL));
    int istate;
    istate = atoi(state);

    system("cls");
    genData(name, name2, apPat, apMat);
    inicio4(apPat, apMat, name, name2, curp);
    curpFecha(curp, day, month, year);
    curpSexo(curp, sexo);
    curpState(curp, istate);
    curpConso(curp, apPat, apMat, name, name2);
    curpHomonimia(curp, year);

    for (int i = 0; i < 18; i++)
    {
        printf("%c", curp[i]);
    }
    printf("\n");
    system("pause");
}

void curpMainRand(char name[], char apPat[], char apMat[], int state, char sexo[], int day, int month, int year, char curp[])
{
    srand(time(NULL));
    char name2[2] = "\0";
    char sday[3], smonth[3], syear[5];
    itoa(day, sday, 3);
    itoa(month, smonth, 3);
    itoa(year, syear, 5);

    for (int i = 0; i < 18; i++)
    {
        printf("%c", curp[i]);
    }
    printf("\n");
    system("pause");
}

void genData(char name[], char name2[], char apPat[], char apMat[])
{
    char prepos[19][5] = {"DA ", "DE ", "DI ", "DD ", "EL ", "LA ", "LE ", "MC ", "DAS ", "DEL ", "DER ", "DIE ", "LOS ", "LAS ", "LES ", "MAC ", "VAN ", "VON ", "Y "};
    eliminarPrepo(apPat, prepos);
    removeEspacios(apPat);
    validEnie(apPat);
    eliminarPrepo(apMat, prepos);
    removeEspacios(apMat);
    validEnie(apMat);

    validEnie(name);
    validEnie(name2);
    eliminarPrepo(name, prepos);
    eliminarPrepo(name2, prepos);
    removeEspacios(name);
    removeEspacios(name2);
    validU(name2);

    system("cls");
    system("pause");
}

void genDataRand(char name[], char apPat[], char apMat[])
{
    char prepos[19][5] = {"DA ", "DE ", "DI ", "DD ", "EL ", "LA ", "LE ", "MC ", "DAS ", "DEL ", "DER ", "DIE ", "LOS ", "LAS ", "LES ", "MAC ", "VAN ", "VON ", "Y "};
    eliminarPrepo(apPat, prepos);
    removeEspacios(apPat);
    validEnie(apPat);
    eliminarPrepo(apMat, prepos);
    removeEspacios(apMat);
    validEnie(apMat);

    validEnie(name);
    eliminarPrepo(name, prepos);
    removeEspacios(name);

    system("cls");
    system("pause");
}

void fecha(char day[], char month[], char year[])
{
    int bi = FALSE;
    int iyear, iday, imonth;

    printf("FECHA DE NACIMIENTO\n");
    iyear = validar("AÑO DE NACIMIENTO (CUATRO DIGITOS): ", 1893, 2023);
    snprintf(year, sizeof(year), "%d", iyear);

    system("cls");
    if ((iyear % 4 == 0 && iyear % 100 != 0) || (iyear % 400 == 0))
    {
        bi = TRUE;
    }

    meses();
    do
    {
        imonth = validar("ELIGE EL NUMERO DE TU MES: ", 1, 12);
    } while (iyear == 2023 && imonth > 10);
    snprintf(month, sizeof(month), "%d", imonth);
    system("cls");
    if (imonth == 2)
    {
        if (bi == TRUE)
        {
            iday = validar("INGRESA EL DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 29);
        }
        else
        {
            iday = validar("INGRESA EL DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 28);
        }
    }
    else
    {
        if (imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11)
        {
            iday = validar("INGRESA TU DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 30);
        }
        else
        {
            iday = validar("INGRESA TU DIA DE NACIMIENTO (DOS DIGITOS): ", 1, 31);
        }
    }
    snprintf(day, sizeof(day), "%d", iday);

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
    int same, i = 0, j, band = FALSE, band2;
    char iniciales[4];
    char pnegadas[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    char jose[5] = "JOSE";
    char maria[6] = "MARIA";

    if ((unsigned char)apPat[0] != 'Ñ')
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

    band2 = FALSE;
    i = 0;
    do
    {
        if (name[i] == maria[i])
        {
            i++;
        }
        else
        {
            band2 = TRUE;
        }
    } while (band2 == FALSE && i < 5);

    if (band == FALSE || band2 == FALSE)
    {
        iniciales[3] = name2[0];
    }
    else
    {
        iniciales[3] = name[0];
    }

    // Valida J. J MA. MA
    if (strcmp(name, "JX") == 0)
    {
        iniciales[3] = name2[0];
    }

    if (strcmp(name, "J") == 0)
    {
        iniciales[3] = name2[0];
    }

    if (strcmp(name, "MAX") == 0)
    {
        iniciales[3] = name2[0];
    }

    if (strcmp(name, "MA") == 0)
    {
        iniciales[3] = name2[0];
    }

    i = 0;

    do
    { // Verifica que las 4 iniciales no este en las palabras inconvenientes
        band = FALSE;
        same = 0;
        j = 0;
        do
        {
            if (iniciales[j] == pnegadas[i][j])
            {
                same++;
                j++;
            }
            else
            {
                band = TRUE;
            }
        } while (band == FALSE && j < 4);
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

void curpState(char curp[], int estado)
{
    char iniEstado[33][3] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "DF", "NE"};
    curp[11] = iniEstado[estado - 1][0];
    curp[12] = iniEstado[estado - 1][1];
}

void curpConso(char curp[], char apPat[], char apMat[], char name[], char name2[])
{
    int band, band2, i = 0;
    char jose[5] = "JOSE";
    char maria[6] = "MARIA";
    char ma[3] = "MA";
    char m[2] = "M";
    char maP[4] = "MAX";
    char ij[2] = "J";
    char jP[3] = "JX";

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

    band2 = FALSE;
    i = 0;
    do
    {
        if (name[i] == maria[i])
        {
            i++;
        }
        else
        {
            band2 = TRUE;
        }
    } while (band2 == FALSE && i < 5);

    if ((strcmp(name, ma) == 1) && (strcmp(name, maP) == 1) && (strcmp(name, m) == 1))
    {
        band = TRUE;
    }
    if ((strcmp(name, ij) == 1) && (strcmp(name, jP) == 1))
    {
        band = TRUE;
    }

    if (band == FALSE || band2 == FALSE)
    {
        curp[15] = buscaCons(name2);
    }
    else
    {
        curp[15] = buscaCons(name);
    }
}

void curpHomonimia(char curp[], char syear[])
{
    int year, n;
    char num[10];
    year = atoi(syear);
    if (year < 2000)
    {
        curp[16] = '0';
    }
    else
    {
        if (year >= 2000 && year <= 2009)
        {
            curp[16] = 'A';
        }
        else
        {
            if (year >= 2010 && year <= 2019)
            {
                curp[16] = 'B';
            }
            else
            {
                curp[16] = 'C';
            }
        }
    }
    n = rand() % 9 + 1;
    itoa(n, num, 10);
    curp[17] = num[0];
    curp[18] = '\0';
}
