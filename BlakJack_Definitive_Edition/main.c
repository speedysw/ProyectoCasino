#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
#include <stdbool.h>
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

typedef struct {
    int numero;
    char *pinta;
} Baraja;

void *createBaraja() {
    Baraja *baraja = (Baraja *) malloc(sizeof(Baraja));
    baraja->pinta = (char *) malloc(sizeof(char)* 8);
    return baraja;
}

void barajaAleatoria(HashMap *);
int sacarCarta(HashMap *, int);
void generarCarta(int *, char *, HashMap *);
void gotoxy(int , int );
void titulo();

int main(){
    menu();
    return 0;
}

void menu(){
    system("color");
    titulo();
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F);
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

        switch(flag1)
        {
            case 0: menuJuego(); break;
            case 1: terminar_programa=1; printf("\n");
        }

    }while(terminar_programa != 1);
}

void menuJuego(){
    system("cls");
    srand(time(NULL));
    HashMap *mapBaraja = createMap(52);
    barajaAleatoria(mapBaraja);
    system("color");
    int dinero;
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
        gotoxy(1,2);printf(ROJO_F "- $1000" NEGRO_F);
        gotoxy(1,3);printf("- $2000");
        gotoxy(1,4);printf("- $3500");
        gotoxy(1,5);printf("- $5000");
        gotoxy(1,6);printf("- $7500");
        gotoxy(1,7);printf("- $10000");
        do{
            key = getch();
            switch(key){
                case 72: if (pos == 0)
                        pos = 5;
                        else pos--;
                        break;
                case 80: if (pos == 5) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf(ROJO_F "- $1000" NEGRO_F);
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf(ROJO_F "- $2000" NEGRO_F);
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf(ROJO_F "- $3500" NEGRO_F);
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf(ROJO_F "- $5000" NEGRO_F);
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf(ROJO_F "- $7500" NEGRO_F);
                        gotoxy(1,7);printf("- $10000");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf(ROJO_F "- $10000" NEGRO_F);
                        flag1=5;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: dinero = 1000; terminar_programa=1; break;
            case 1: dinero = 2000; terminar_programa=1; break;
            case 2: dinero = 3500; terminar_programa=1; break;
            case 3: dinero = 5000; terminar_programa=1; break;
            case 4: dinero = 7500; terminar_programa=1; break;
            case 5: dinero = 10000; terminar_programa=1; break;
        }
    }while(terminar_programa != 1);

    dinero = sacarCarta(mapBaraja, dinero);
}

void gotoxy(int x , int y){
HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);
}

void titulo(){
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "                BLACKJACK" RESET_COLOR"%19s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

void barajaAleatoria(HashMap *mapBaraja) {
    int *carta;
    char *key;
    Baraja *baraja;

    for(int i = 0 ; i < 40 ; i++) {
        baraja = createBaraja();
        carta = (int *) malloc(sizeof(int));
        key = (char *) malloc(sizeof(char) * 10);

        *carta = rand() % 40 + 1;
        sprintf(key, "%i", *carta);

        while(searchMap(mapBaraja, key) != NULL) {
            *carta = rand() % 40 + 1;
            sprintf(key, "%i", *carta);
        }

        if(*carta <= 10) {
            baraja->numero = *carta;
            strcpy(baraja->pinta, "moneda");
        } else if(*carta <= 20) {
            if(*carta % 10 == 0) baraja->numero = 10;
            else baraja->numero = *carta % 10;
            strcpy(baraja->pinta, "baston");
        } else if(*carta <= 30) {
            if(*carta % 10 == 0) baraja->numero = 10;
            else baraja->numero = *carta % 10;
            strcpy(baraja->pinta, "espada");
        } else {
            if(*carta % 10 == 0) baraja->numero = 10;
            else baraja->numero = *carta % 10;
            strcpy(baraja->pinta, "copa");
        }
        insertMap(mapBaraja, key, baraja);
    }
}

int sacarCarta(HashMap *mapBaraja, int dinero) {
    system("cls");
    int *carta;
    char *key;

    carta = (int *) malloc(sizeof(int));
    key = (char *) malloc(sizeof(char) * 10);

    generarCarta(carta, key, mapBaraja);
    Baraja *aux = searchMap(mapBaraja, key);
    gotoxy(1,1);printf("Su primera carta es: %i de %s\n", aux->numero, aux->pinta);
    int suma = aux->numero;
    eraseMap(mapBaraja, key);

    generarCarta(carta, key, mapBaraja);
    aux = searchMap(mapBaraja, key);
    gotoxy(1,2);printf("Su segunda carta es: %i de %s\n", aux->numero, aux->pinta);
    suma += aux->numero;
    eraseMap(mapBaraja, key);

    gotoxy(1,3);printf("Ahora se entregara una carta al Crupier\n");
    generarCarta(carta, key, mapBaraja);
    aux = searchMap(mapBaraja, key);
    gotoxy(1,4);printf("Carta Crupier: %i de %s\n", aux->numero, aux->pinta);
    int sumaC = aux->numero;
    eraseMap(mapBaraja, key);
    gotoxy(1,5);printf("Usted suma: %i", suma);

    bool perder = false;
    int decision;

    do {
        int pos,end,flag1=0,terminar_programa=0;
        char keyMenu;

        do{
        pos = 0;
        end = 0;
            gotoxy(1,7);printf("OPCIONES");
            gotoxy(1,8);printf(ROJO_F "- PLANTARSE" NEGRO_F);
            gotoxy(1,9);printf("- SACAR CARTA");
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
                            gotoxy(1,7);printf("OPCIONES");
                            gotoxy(1,8);printf(ROJO_F "- PLANTARSE" NEGRO_F);
                            gotoxy(1,9);printf("- SACAR CARTA");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(1,7);printf("OPCIONES");
                            gotoxy(1,8);printf("- PLANTARSE ");
                            gotoxy(1,9);printf(ROJO_F "- SACAR CARTA" NEGRO_F);
                            flag1=1;
                            break;
                }
            }while(end != 1);

            switch(flag1)
            {
                case 0:
                        terminar_programa=1;
                        break;
                case 1:
                        generarCarta(carta, key, mapBaraja);
                        aux = searchMap(mapBaraja, key);
                        system("cls");
                        gotoxy(1,1);printf("Su nueva carta es: %i de %s\n", aux->numero, aux->pinta);
                        suma += aux->numero;
                        gotoxy(1,2);printf("Usted suma: %i", suma);
                        eraseMap(mapBaraja, key);
                        if(suma > 21) {
                            perder = true;
                            gotoxy(1,3);printf(AMARILLO_T "SOBREPASASTE 21\n" RESET_COLOR);
                            gotoxy(1,4);printf(ROJO_T "Perdiste $%i" RESET_COLOR, dinero);
                            gotoxy(1,5);system("pause");
                            system("cls");
                            titulo();
                            terminar_programa = 1;
                            break;
                        }

                        break;
            }
        }while(terminar_programa != 1);
    } while(decision == 2 && perder == false);

    if(perder == false) {
        system("cls");
        printf("Se ha plantado con %i\n", suma);
        if(suma == 21) {
            printf(MAGENTA_T "BLACK JACK\n" RESET_COLOR);
            printf(VERDE_T "Has ganado: $%i\n" RESET_COLOR , dinero * 2);
            dinero += dinero * 2;
            system("pause");
            system("cls");
            titulo();
        } else {
            do {
                printf("Ahora se entregara otra carta al crupier\n");
                generarCarta(carta, key, mapBaraja);
                Baraja *aux = searchMap(mapBaraja, key);
                printf("Carta Crupier: %i de %s\n", aux->numero, aux->pinta);
                sumaC += aux->numero;
                printf("Crupier suma: %i\n", sumaC);
                eraseMap(mapBaraja, key);
            } while(sumaC < 17);
            if(sumaC > 21) {
                printf(VERDE_T "Has ganado: $%i\n" RESET_COLOR, dinero);
                dinero += dinero;
                system("pause");
                system("cls");
                titulo();
            } else {
                if(sumaC > suma) {
                    printf(ROJO_T "Has perdido: $%i\n" RESET_COLOR, dinero);
                    dinero -= dinero;
                    system("pause");
                    system("cls");
                    titulo();
                } else if(sumaC == suma) {
                    printf(CYAN_T "Empate, conservas tu dinero\n" RESET_COLOR);
                    system("pause");
                    system("cls");
                    titulo();
                } else {
                    printf(VERDE_T "Has ganado: $%i\n" RESET_COLOR, dinero);
                    dinero += dinero;
                    system("pause");
                    system("cls");
                    titulo();
                }
            }
        }
    }

    return dinero;
}

void generarCarta(int *carta, char *key, HashMap *mapBaraja) {
    *carta = rand() % 40 + 1;
    sprintf(key, "%i", *carta);
    while(searchMap(mapBaraja, key) == NULL) {
        *carta = rand() % 40 + 1;
        sprintf(key, "%i", *carta);
    }
}
