// Jorge Antono Vazquez Guzman 372504
// 5 de septiembre de 2023
// Esqueleto
// JAVG_Act3_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Aqui se declaran los prototipos para que el preprocesador reciba menos carga
void menu(void);
void califi(void);
void chinani(void);
void chinmul(void);
void nmayor(void);
void nmedio(void);
void nascen(void);
void signo(void);

// Funcion principal la cual llama al menu y se encarga de todo
int main()
{
    menu();
    return 0;
}

// Esta funcion siempre es llamada y contiene el poder de llamar al resto de las funciones segun sea necesario, contiene el menu y la capacidad de elegir
void menu()
{
    int op;
    // Aqui te muestra todas las opciones que contiene el codigo para que puedas elegir
    printf("Ingrese el programa a ejecutar\n");
    printf("1. Calificaciones y promedio\n");
    printf("2. Chinchampu condicion anidado\n");
    printf("3. Chinchampu seleccion multiple\n");
    printf("4. Numero mayor\n");
    printf("5. Numero del medio\n");
    printf("6. Numeros en forma ascendente\n");
    printf("7. Signo zodiaco y horoscopo\n");
    scanf("%d", &op);

    // Dependiendo la opcion que el usuario haya dado entrara a una case y llamara a alguna funcion que se encargara del resto
    switch (op)
    {
    case 1:
        califi();
        break;
    case 2:
        chinani();
        break;
    case 3:
        chinmul();
        break;
    case 4:
        nmayor();
        break;
    case 5:
        nmedio();
        break;
    case 6:
        nascen();
        break;
    case 7:
        signo();
        break;
    default: // Esto es en caso de que el usuario haya dado una opcion no valida o fuera de limites
        printf("Opcion no valida\n");
        break;
    }
}

// Esta funcion cuando es llamada pide calificaciones y las promedio para mostrar el tipo de calificacion que obtuvo en palabras
void califi()
{
    int c1, c2, c3, prom;

    system("cls");
    printf("Ingrese la primera calificacion ");
    scanf("%d", &c1);
    printf("Ingresa la segunda calificacion ");
    scanf("%d", &c2);
    printf("Ingrese la tercera calificacion ");
    scanf("%d", &c3);
    prom = (c1 + c2 + c3) / 3;

    // Despues de promediar empieza las comparaciones mediante el metodo de arbol para determinar cual darte
    if (prom >= 80)
    {
        if (prom >= 90)
        {
            if (prom >= 98)
            {
                if (prom > 100)
                {
                    printf("Error en promedio");
                }
                else
                {
                    printf("Excelente");
                }
            }
            else
            {
                printf("Muy bien");
            }
        }
        else
        {
            printf("bien");
        }
    }
    else // En caso de no haber entrado en la primera parte, continua aca
    {
        if (prom >= 70)
        {
            printf("Regular");
        }
        else
        {
            if (prom >= 60)
            {
                printf("Suficiente");
            }
            else
            {
                if (prom >= 30)
                {
                    printf("Extraordinario");
                }
                else
                {
                    printf("Repetir");
                }
            }
        }
    }
}

// Esta funcion cuando es llamda inicia el juego chinchampu mediante una serie de ifs anidados y te indica el ganador
void chinani()
{
    int opc, ran, vic;

    srand(time(NULL));    // Esto genera una semilla para que genere numeros
    ran = rand() % 3 + 1; // Esto genera un numero aleatorio y lo asigna a la variable

    printf("Ingresa tu jugada\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijeras\n");
    scanf("%d", &opc);
    printf("La computadora selecciono %d\n", ran);
    // Aqui inicia la operacion para determinar el ganador
    vic = (opc - ran + 3) % 3;

    // Aqui dependiendo el resultado marca el ganador
    if (vic == 1)
    {
        printf("Gana el usuario ");
    }
    else
    {
        if (vic == 0)
        {
            printf("Empate ");
        }
        else
        {
            printf("Gana la computadora ");
        }
    }
}

// Esta funcion cuando es llamada inicia el juego chinchampu mediante un switch y te indica el ganador
void chinmul()
{
    int opc, ran;

    srand(time(NULL));    // Esto genera una semilla para que el numero cambie
    ran = rand() % 3 + 1; // Esto genera el numero aleatorio y lo asigna a una variable

    system("cls");
    printf("Ingresa tu jugada\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijeras\n");
    scanf("%d", &opc);
    printf("La computadora selecciono %d\n", ran);

    // Aqui resuelve y elige el resultado
    switch ((opc - ran + 3) % 3)
    {
    case 1:
        printf("Gana el usuario");
        break;
    case 0:
        printf("Empate");
        break;
    default:
        printf("Gana la computadora");
        break;
    }
}

// Esta funcion cuando es llamada te pide 3 numeros y te despliega el numero mayor
void nmayor()
{
    int n1, n2, n3;

    system("cls");
    printf("Ingrese el primer numero ");
    scanf("%d", &n1);
    printf("Ingrese el segundo numero ");
    scanf("%d", &n2);
    printf("Ingrese el tercer numero ");
    scanf("%d", &n3);

    // Aqui comienza la comparacion para poder determinar el numero mayor
    if (n1 > n2 && n1 > n3)
    {
        printf("El numero mayor es %d", n1);
    }
    if (n2 > n1 && n2 > n3)
    {
        printf("El numero mayor es %d", n2);
    }
    if (n3 > n1 && n3 > n2)
    {
        printf("El numero mayor es %d", n3);
    }
}

// Esta funcion cuando es llamada te pide 3 numeros y te despliega el numero del medio
void nmedio()
{
    int num1, num2, num3;

    system("cls");
    printf("Dame el primer valor: ");
    scanf("%d", &num1);
    printf("Dame el segundo valor: ");
    scanf("%d", &num2);
    printf("Dame el tercer valor: ");
    scanf("%d", &num3);

    // Aqui comienza la comparacion para encontrar el numero del medio
    if ((num1 > num2 && num3 > num1) || (num1 > num3 && num2 > num1))
    {
        printf("El numero del medio es el primero y vale %d", num1);
    }
    else if ((num2 > num1 && num3 > num2) || (num2 > num3 && num1 > num2))
    {
        printf("El numero del medio es el segundo y vale %d", num2);
    }
    else
    {
        printf("El numero del medio es el tercero y vale %d", num3);
    }
}

// Esta funcion cuando es llamada te pide 3 numeros y los despliega ordenados de manera ascendente
void nascen()
{
    int num1, num2, num3;

    system("cls");
    printf("Dame el primer valor: ");
    scanf("%d", &num1);
    printf("Dame el segundo valor: ");
    scanf("%d", &num2);
    printf("Dame el tercer valor: ");
    scanf("%d", &num3);

    // Aqui comienza a ordenar los numeros
    if (num1 > num2)
    {
        if (num1 < num3)
        {
            printf("%d %d %d", num2, num1, num3);
        }

        if (num1 > num3 && num3 > num2)
        {
            printf("%d %d %d", num2, num3, num1);
        }

        if (num1 > num3 && num3 < num2)
        {
            printf("%d %d %d", num3, num2, num1);
        }
    }
    if (num2 > num1)
    {
        if (num2 < num3)
        {
            printf("%d %d %d", num1, num2, num3);
        }

        if (num2 > num3 && num3 > num1)
        {
            printf("%d %d %d", num1, num3, num2);
        }

        if (num2 > num3 && num3 < num1)
        {
            printf("%d %d %d", num3, num1, num2);
        }
    }
    if (num3 > num1)
    {
        if (num3 < num2)
        {
            printf("%d %d %d", num1, num3, num2);
        }
        if (num3 > num2 && num2 > num1)
        {
            printf("%d %d %d", num1, num2, num3);
        }
        if (num3 > num2 && num2 < num1)
        {
            printf("%d %d %d", num2, num1, num3);
        }
    }
}

// Esta funcion cuando es llamada te despliega las opciones de dia y mes en que naciste para decirte tu signo y tu horoscopo del dia
void signo()
{
    system("cls"); // Esto limpia la pantalla
    int dia, mes;

    printf("Ingresa el dia en que naciste ");
    scanf("%d", &dia);
    printf("Ingresa el mes en que naciste ");
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
    scanf("%d", &mes);

    // Apartir de aqui comienza a validar tu fecha de nacimiento
    if ((dia >= 1 && dia <= 31) && (mes>=1 && mes<=12))//Esto valida que este dentro del rango de 31 dias y 12 meses
    {
        if (mes == 1)
        {
            if (dia >= 21 && dia <= 31)
            {
                printf("Eres Acuario");
                printf("\nImagínate que una persona que es tu principal fan, fuera también tu peor enemiga. Sería una relación complicada. ");
            }
            else
            {
                printf("Eres Capricornio");
                printf("\nPodrías estar ante una situación más complicada. Las cosas podrían ir a peor. Podrías estar haciendo frente a un escenario que te generase mucho más estrés del que tienes en estos momentos.");
            }
        }
        if (mes == 2)
        {
            if (dia >= 1 && dia <= 19)
            {
                printf("Eres Acuario");
                printf("\nImagínate que una persona que es tu principal fan, fuera también tu peor enemiga. Sería una relación complicada. ");
            }
            else
            {
                printf("Eres Piscis");
                printf("\nLa gente acude a ti en busca de consejo. Y como eres generosa con tu tiempo, disfrutas ayudándoles a afrontar sus retos. Al fin y al cabo, para eso están los amigos.");
            }
        }
        if (mes == 3)
        {
            if (dia >= 1 && dia <= 20)
            {
                printf("Eres Piscis");
                printf("\nLa gente acude a ti en busca de consejo. Y como eres generosa con tu tiempo, disfrutas ayudándoles a afrontar sus retos. Al fin y al cabo, para eso están los amigos.");
            }
            else
            {
                printf("Eres Aries");
                printf("\nLo estás haciendo lo mejor que puedes. Pero nadie puede ser perfecto todo el tiempo. Ni ser el mejor en todo. Todos cometemos errores. ");
            }
        }
        if (mes == 4)
        {
            if (dia >= 1 && dia <= 20)
            {
                printf("Eres Aries");
                printf("\n Lo estás haciendo lo mejor que puedes. Pero nadie puede ser perfecto todo el tiempo. Ni ser el mejor en todo. Todos cometemos errores. ");
            }
            else
            {
                printf("Eres Tauro");
                printf("\n nos enfrentamos a amenazas con las que nuestros antepasados no podían soñar. Coches. Aviones. Estafadores. Pero lo que nos preocupa más que los riesgos reales de vivir en el siglo XXI, son los problemas con los que probablemente no nos encontraremos.");
            }
        }
        if (mes == 5)
        {
            if (dia >= 1 && dia <= 21)
            {
                printf("Eres Tauro");
                printf("\nnos enfrentamos a amenazas con las que nuestros antepasados no podían soñar. Coches. Aviones. Estafadores. Pero lo que nos preocupa más que los riesgos reales de vivir en el siglo XXI, son los problemas con los que probablemente no nos encontraremos.");
            }
            else
            {
                printf("Eres Geminis");
                printf("\n¡Redobla esfuerzos! ¡Ejerce tu autoridad! No es una petición descabellada. Y es lo que el cosmos te invita a hacer. Lo que muchas veces te impide darte a valer no son las dudas, sino el miedo. Conoces tus puntos fuertes");
            }
        }
        if (mes == 6)
        {
            if (dia >= 1 && dia <= 21)
            {
                printf("Eres Geminis");
                printf("\n¡Redobla esfuerzos! ¡Ejerce tu autoridad! No es una petición descabellada. Y es lo que el cosmos te invita a hacer. Lo que muchas veces te impide darte a valer no son las dudas, sino el miedo. Conoces tus puntos fuertes");
            }
            else
            {
                printf("Eres Cancer");
                printf("\nNo siempre basta con saber, en lo más profundo de nuestro corazón, que estamos apoyando a una persona que tiene problemas. Ella también necesita saberlo.");
            }
        }
        if (mes == 7)
        {
            if (dia >= 1 && dia <= 22)
            {
                printf("Eres Cancer");
                printf("\n No siempre basta con saber, en lo más profundo de nuestro corazón, que estamos apoyando a una persona que tiene problemas. Ella también necesita saberlo.");
            }
            else
            {
                printf("Eres Leo");
                printf("\n¿Realmente justifica la intensa situación en la que estás centrando tu atención toda esa cantidad de energía? En lugar de abordar un reto de enormes proporciones, a veces nos dejamos llevar por detalles relativamente triviales. ");
            }
        }
        if (mes == 8)
        {
            if (dia >= 1 && dia <= 22)
            {
                printf("Eres Leo");
                printf("\n ¿Realmente justifica la intensa situación en la que estás centrando tu atención toda esa cantidad de energía? En lugar de abordar un reto de enormes proporciones, a veces nos dejamos llevar por detalles relativamente triviales. ");
            }
            else
            {
                printf("Eres Virgo");
                printf("\nTendemos a compararnos con las categorías de éxito que tienen otras personas. Lo malo de esto es que cada uno de nosotros tenemos nuestro propio sistema de medición.");
            }
        }
        if (mes == 9)
        {
            if (dia >= 1 && dia <= 22)
            {
                printf("Eres Virgo");
                printf("\nTendemos a compararnos con las categorías de éxito que tienen otras personas. Lo malo de esto es que cada uno de nosotros tenemos nuestro propio sistema de medición.");
            }
            else
            {
                printf("Eres Libra");
                printf("\nEncogernos de hombros y decir \"no es mi problema\" no nos lleva muy lejos. Sólo porque alguien lo haya liado todo no significa que no necesite que le echemos una mano para aclararlo. ");
            }
        }
        if (mes == 10)
        {
            if (dia >= 1 && dia <= 22)
            {
                printf("Eres Libra");
                printf("\nEncogernos de hombros y decir \"no es mi problema\" no nos lleva muy lejos. Sólo porque alguien lo haya liado todo no significa que no necesite que le echemos una mano para aclararlo. ");
            }
            else
            {
                printf("Eres Escorpio");
                printf("\nCreemos saber qué \"deberíamos\" estar haciendo. Cuando lo hacemos, nos sentimos tranquilos y satisfechos. Y cuando no, tenemos que acallar nuestros sentimientos de culpa.");
            }
        }
        if (mes == 11)
        {
            if (dia >= 1 && dia <= 22)
            {
                printf("Eres Escorpio");
                printf("\nCreemos saber qué \"deberíamos\" estar haciendo. Cuando lo hacemos, nos sentimos tranquilos y satisfechos. Y cuando no, tenemos que acallar nuestros sentimientos de culpa.");
            }
            else
            {
                printf("Eres Sagitario");
                printf("\n eniendo a la suerte de tu lado y alas en los pies, prácticamente puedes elegir en qué estrella te quieres columpiar y qué te gustaría iluminar con tus rayos de luna.");
            }
        }
        if (mes == 12)
        {
            if (dia >= 1 && dia <= 21)
            {
                printf("Eres Sagitario");
                printf("\n eniendo a la suerte de tu lado y alas en los pies, prácticamente puedes elegir en qué estrella te quieres columpiar y qué te gustaría iluminar con tus rayos de luna.");
            }
            else
            {
                printf("Eres Capricornio");
                printf("\nPodrías estar ante una situación más complicada. Las cosas podrían ir a peor. Podrías estar haciendo frente a un escenario que te generase mucho más estrés del que tienes en estos momentos.");
            }
        }
    }
}
