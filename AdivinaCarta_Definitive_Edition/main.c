#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hashmap.h"
#include <windows.h>

#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

typedef struct{  //Estructura para crear el mapa
    char *carta;
}adivino;

void llenarMapa(HashMap *); //Funcion para insertar datos en el mapa que contendra los nombres de las cartas
void titulo();//Funcion para mostrar el titulo de la aplicacion por pantalla
void menu(HashMap *);
void resultado(int, int);

adivino *crearMaso(){ //Funcion para asignarle memoria dinamicamente a la struct

    adivino *aux = (adivino *) malloc(sizeof(adivino)); //Con un malloc vamos asignando espacio a la struct mediante vayamos necesitando
    aux->carta = (char *) malloc(sizeof(char) * 20);
    return aux;
}

int main(){
    HashMap *adv = createMap(10);//Se crea el map
    llenarMapa(adv);
    menu(adv);
    return 0;
}

void llenarMapa(HashMap *adv){ //Funcion para insertar datos en el mapa que contendra los nombres de las cartas
    adivino *maso;
    int *random;
    char *key;
    for(int i = 0; i <= 3; i++){

        maso = crearMaso();

        random = (int *) malloc(sizeof(int));

        key = (char *) malloc(sizeof(char)* 10);

        *random = i + 1;

        sprintf(key, "%i", *random);//Funcion para transformar int a char

        if(i == 0) maso->carta =  strdup("AS DE COPAS");
        if(i == 1) maso->carta =  strdup("AS DE BASTOS");
        if(i == 2) maso->carta =  strdup("AS DE OROS");
        if(i == 3) maso->carta =  strdup("AS DE ESPADAS");
        insertMap(adv, key, maso);//Insertamos la key
    }
}

void titulo(){ //Funcion para mostrar el titulo de la aplicacion por pantalla
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "             ADIVINA LA CARTA" RESET_COLOR"%15s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

void menu(HashMap *adv){ //Menu de la aplicacion
    system("color");
    titulo();
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F); //Esto permite elegir entre jugar y salir de la aplicacion
        gotoxy(17,6);printf(" -SALIR");
        do{
            keyMenu = getch();
            switch(keyMenu){
                case 72: if (pos == 0)
                        pos = 1;
                        else pos--;
                        break;
                case 80: if (pos == 1) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F);
                        gotoxy(17,6);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(17,5);printf(" -JUGAR");
                        gotoxy(17,6);printf(ROJO_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1) //Este switch sirve para que el programa sepa que opcion eligio el usuario
        {
            case 0: carta(adv); break;
            case 1: terminar_programa=1; printf("\n");
        }

    }while(terminar_programa != 1);
}

void gotoxy(int x , int y){ //Funcion para hacer un menu de opciones dinamicos
HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);
}

void carta(HashMap *adv){ //Funcion la cual nos entrega las instrucciones, opciones de apuesta y resultados del juego del usuario
    system("cls");
    char *key;
    char *key2;
    int carta;
    int *n;
    int *usuario;
    int apuesta;
    int revolver;

    n = (int *) malloc(sizeof(int));
    usuario = (int *) malloc(sizeof(int));
    key = (char *) malloc(sizeof(char)* 10);
    key2= (char *) malloc(sizeof(char)* 10);

    printf(AMARILLO_T"INSTRUCCIONES\n"RESET_COLOR);
    printf(VERDE_T"\nBienvenido al juego adivina la carta\n"RESET_COLOR);
    printf(AZUL_T "\nEste juego consta en adivinar que carta saldra\n"RESET_COLOR);
    printf("\nEscoge una opcion:");

    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,8);printf(CYAN_F"- AS DE COPAS" NEGRO_F);
        gotoxy(1,9);printf("- AS DE BASTOS");
        gotoxy(1,10);printf("- AS DE OROS");
        gotoxy(1,11);printf("- AS DE ESPADAS");
        do{
            keyMenu = getch();
            switch(keyMenu){
                case 72: if (pos == 0)
                        pos = 3;
                        else pos--;
                        break;
                case 80: if (pos == 3) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(1,8);printf(CYAN_F"- AS DE COPAS" NEGRO_F);
                        gotoxy(1,9);printf("- AS DE BASTOS");
                        gotoxy(1,10);printf("- AS DE OROS");
                        gotoxy(1,11);printf("- AS DE ESPADAS");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,8);printf("- AS DE COPAS");
                        gotoxy(1,9);printf(MAGENTA_F "- AS DE BASTOS" NEGRO_F);
                        gotoxy(1,10);printf("- AS DE OROS");
                        gotoxy(1,11);printf("- AS DE ESPADAS");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(1,8);printf("- AS DE COPAS");
                        gotoxy(1,9);printf("- AS DE BASTOS");
                        gotoxy(1,10);printf(ROJO_F "- AS DE OROS" NEGRO_F);
                        gotoxy(1,11);printf("- AS DE ESPADAS");
                        flag1=1;
                        break;
                case 3:
                        gotoxy(1,8);printf("- AS DE COPAS");
                        gotoxy(1,9);printf("- AS DE BASTOS");
                        gotoxy(1,10);printf("- AS DE OROS");
                        gotoxy(1,11);printf(AMARILLO_F "- AS DE ESPADAS" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: carta = 1; terminar_programa=1; break;
            case 1: carta = 2; terminar_programa=1; break;
            case 2: carta = 3; terminar_programa=1; break;
            case 3: carta = 4; terminar_programa=1; break;
        }

    }while(terminar_programa != 1);

    *usuario = carta;
    srand(time(NULL));
    *n = rand () % 4 + 1;;

    sprintf(key, "%i", *n);//Funcion la cual nos permite transformar un int a un char para que se pueda usar como key del mapa

    flag1=0,terminar_programa=0;
    do{
    pos = 0;
    end = 0;
        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
        gotoxy(1,14);printf(ROJO_F "- $1000" NEGRO_F);
        gotoxy(1,15);printf("- $2000");
        gotoxy(1,16);printf("- $3500");
        gotoxy(1,17);printf("- $5000");
        gotoxy(1,18);printf("- $7500");
        gotoxy(1,19);printf("- $10000");
        do{
            keyMenu = getch();
            switch(keyMenu){
                case 72: if (pos == 0)
                        pos = 5;
                        else pos--;
                        break;
                case 80: if (pos == 5) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){ //Opciones de apuesta monetaria del usuario
                case 0:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf(ROJO_F "- $1000" NEGRO_F);
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf(ROJO_F "- $2000" NEGRO_F);
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf(ROJO_F "- $3500" NEGRO_F);
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf(ROJO_F "- $5000" NEGRO_F);
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf(ROJO_F "- $7500" NEGRO_F);
                        gotoxy(1,19);printf("- $10000");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf(ROJO_F "- $10000" NEGRO_F);
                        flag1=5;
                        break;
            }
        }while(end != 1);

        switch(flag1) //Switch para saber cuanto aposto el usuario
        {
            case 0: apuesta = 1000; terminar_programa=1; break;
            case 1: apuesta = 2000; terminar_programa=1; break;
            case 2: apuesta = 3500; terminar_programa=1; break;
            case 3: apuesta = 5000; terminar_programa=1; break;
            case 4: apuesta = 7500; terminar_programa=1; break;
            case 5: apuesta = 10000; terminar_programa=1; break;
        }
    }while(terminar_programa != 1);

    gotoxy(1,20);printf("=== Presione cualquier tecla para sacar una carta ===");
    gotoxy(25,22);revolver = getch();
    system("cls");
    adivino *p = searchMap(adv, key);
    gotoxy(1,1);printf(AMARILLO_T "Ha salido la carta %s\n",*p);

    if(*usuario == *n){ //Condicional que nos muestra el resultado de la apuesta
        gotoxy(1,2);printf(VERDE_T "GANASTE!!");
        gotoxy(1,3);printf(VERDE_T "Has ganado %d",apuesta *= 2);
        printf(""RESET_COLOR);
    }else{
        gotoxy(1,2);printf(ROJO_T "Has perdido, vuelve a intentarlo" RESET_COLOR);
    }

    printf("\n");
    printf(" ");
    system("PAUSE");
    system("cls");
    titulo();
}
