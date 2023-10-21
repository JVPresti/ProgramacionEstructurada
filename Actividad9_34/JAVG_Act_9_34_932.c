#include "procesos.h"
#define TRUE 1
#define FALSE 0

void menu(void);
void curpmain(void);
void genData(char name[], char name2[], char apPat[], char apMat[], char sday[], char smonth[], char syear[], char ssex[], int sex, int state, int day, int month, int year, char curp[]);
void fecha(int day, int month, int year, char sday[], char smonth[], char syear[]);
void states(void);
void meses(void);
void inicio4(char apPat[], char apMat[], char name[], char name2[], char curp[]);
void curpFecha(char curp[], char sday[], char smonth[], char syear[]);
void curpSexo(char curp[], char ssex[]);
void curpState(char curp[], int state);
void curpConso(char curp[], char apPat[], char apMat[], char name[], char name2[]);
void curpHomonimia(char curp[], char syear[]);

int main()
{
    srand(time(NULL));
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
    char curp[19], apPat[30], apMat[30], name[20], name2[20], sday[10], smonth[10], syear[10], ssex[10];

    system("cls");
    genData(name, name2, apPat, apMat, sday, smonth, syear, ssex, sex, state, day, month, year, curp);
    inicio4(apPat, apMat, name, name2, curp);
    curpFecha(curp, sday, smonth, syear);
    curpSexo(curp, ssex);
    curpConso(curp, apPat, apMat, name, name2);
    curpHomonimia(curp, syear);

    system("cls");
    for (int i = 0; i < 18; i++)
    {
        printf("%c", curp[i]);
    }
    printf("\n");
    system("pause");
}

void genData(char name[], char name2[], char apPat[], char apMat[], char sday[], char smonth[], char syear[], char ssex[], int sex, int state, int day, int month, int year, char curp[])
{
    int op;
    char prepos[19][5] = {"DA ", "DE ", "DI ", "DD ", "EL ", "LA ", "LE ", "MC ", "DAS ", "DEL ", "DER ", "DIE ", "LOS ", "LAS ", "LES ", "MAC ", "VAN ", "VON ", "Y "};

    op = validar("Tiene apellido paterno? \n1. SI \n0. NO\n", 0, 1);
    while (op == 1)
    {
        do
        {
            printf("\nAPELLIDO PATERNO: ");
        } while (validarCad(apPat) == 1);
        op = 0;
    }
    eliminarPrepo(apPat, prepos);
    eliminarPrepo(apPat, prepos);
    eliminarPrepo(apPat, prepos);
    removeEspacios(apPat);
    validEnie(apPat);
    system("CLS");

    op = validar("Tiene apellido materno? \n1. SI \n0. NO\n", 0, 1);
    while (op == 1)
    {
        do
        {
            printf("\nAPELLIDO MATERNO: ");
        } while (validarCad(apMat) == 1);
        op = 0;
    }
    eliminarPrepo(apMat, prepos);
    eliminarPrepo(apMat, prepos);
    eliminarPrepo(apMat, prepos);
    removeEspacios(apMat);
    validEnie(apMat);

    system("CLS");
    do
    {
        printf("\nPRIMER NOMBRE: ");
    } while (validarCad(name) == 1);

    op = validar("Tiene mas nombres? \n1. SI \n0. NO\n", 0, 1);
    while (op == 1)
    {
        do
        {
            printf("\nDEMAS NOMBRES: ");
        } while (validarCad(name2) == 1);
        op = 0;
    }
    validEnie(name);
    validEnie(name2);
    eliminarPrepo(name, prepos);
    eliminarPrepo(name, prepos);
    eliminarPrepo(name, prepos);
    eliminarPrepo(name2, prepos);
    eliminarPrepo(name2, prepos);
    eliminarPrepo(name2, prepos);
    removeEspacios(name);
    removeEspacios(name2);
    validU(name2);

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
        curpState(curp, state);
    } while (state == 0);
}

void fecha(int day, int month, int year, char sday[], char smonth[], char syear[])
{
    int bi = FALSE;

    printf("FECHA DE NACIMIENTO\n");
    year = validar("AÑO DE NACIMIENTO (CUATRO DIGITOS): ", 1893, 2023);
    system("cls");
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        bi = TRUE;
    }

    meses();
    do
    {
        month = validar("ELIGE EL NUMERO DE TU MES: ", 1, 12);
    } while (year == 2023 && month > 10);
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
    int same, i = 0, j, band = FALSE, band2;
    char iniciales[4];
    char pnegadas[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    char jose[4] = "JOSE";
    char maria[5] = "MARIA";

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
    char jose[4] = "JOSE";
    char maria[5] = "MARIA";
    char ma[2] = "MA";
    char m[1] = "M";
    char maP[3] = "MAX";
    char ij[1] = "J";
    char jP[2] = "JX";

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

    if ((strcmp(name, ma) != 0) || (strcmp(name, maP) != 0) || (strcmp(name, m) != 0) || (strcmp(name, maria) != 0))
    {
        band2 = TRUE;
    }
    if ((strcmp(name, ij) != 0) || (strcmp(name, jP) != 0) || (strcmp(name, jose) != 0))
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

    if (strcmp(name, "MAX") == 0)
    {
        curp[15] = buscaCons(name2);
    }
    else
    {
        if (strcmp(name, "MA") == 0)
        {
            curp[15] = buscaCons(name2);
        }
        else
        {
            if (strcmp(name, "M") == 0)
            {
                curp[15] = buscaCons(name2);
            }
            else
            {
                if (strcmp(name, "JX") == 0)
                {
                    curp[15] = buscaCons(name2);
                }
                else
                {
                    if (strcmp(name, "J") == 0)
                    {
                        curp[15] = buscaCons(name2);
                    }
                    else
                    {
                        if (strcmp(name, "MARIA") == 0)
                        {
                            curp[15] = buscaCons(name2);
                        }
                        else
                        {
                            if (strcmp(name, "JOSE") == 0)
                            {
                                curp[15] = buscaCons(name2);
                            }
                        }
                    }
                }
            }
        }
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
