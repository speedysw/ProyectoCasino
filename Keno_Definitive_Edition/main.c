#include <stdio.h>
#include <stdlib.h>
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

void recompensa();
void generarA(HashMap *, int);
void generarM(HashMap *, int);
void correctas(HashMap *, HashMap *, HashMap *);
void escribirCorrectas(HashMap *, HashMap *, float);
void escribirApuesta(HashMap *);
void gotoxy(int , int );
void juego();
void menu();

int main(){
    system("COLOR");
    menu();
    return 0;
}

void juego(){
    system("cls");
    system("color");
    srand(time(NULL));
    int num = 0, capacidad = 26;
    HashMap *mapKeno = createMap(capacidad);

    char asterisco[2];
    strcpy(asterisco,"*");
    printf("   * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("   %s%44s\n",asterisco,asterisco);
    printf("   %s" CYAN_T "                TABLA KENO" RESET_COLOR"%18s\n",asterisco,asterisco);
    printf("   %s%44s\n",asterisco,asterisco);
    printf("   * * * * * * * * * * * * * * * * * * * * * * *\n");

    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 10 ; j++ ) {
            num++;
            printf("  %2i ", num);
        }
        printf("\n");
    }
    recompensa();

    int pos,end,flag1=0,terminar_programa=0;
    char key;
    int dinero;

    do{
    pos = 0;
    end = 0;
        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
        gotoxy(2,15);printf(ROJO_F "- $1000" NEGRO_F);
        gotoxy(2,16);printf("- $2000");
        gotoxy(2,17);printf("- $3500");
        gotoxy(2,18);printf("- $5000");
        gotoxy(2,19);printf("- $7500");
        gotoxy(2,20);printf("- $10000");
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
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf(ROJO_F "- $1000" NEGRO_F);
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf(ROJO_F "- $2000" NEGRO_F);
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf(ROJO_F "- $3500" NEGRO_F);
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf(ROJO_F "- $5000" NEGRO_F);
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf(ROJO_F "- $7500" NEGRO_F);
                        gotoxy(2,20);printf("- $10000");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf(ROJO_F "- $10000" NEGRO_F);
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

    generarA(mapKeno, 20);

    gotoxy(2,14);printf("                                        ");
    gotoxy(2,15);printf("                                        ");
    gotoxy(2,16);printf("                                        ");
    gotoxy(2,17);printf("                                        ");
    gotoxy(2,18);printf("                                        ");
    gotoxy(2,19);printf("                                        ");
    gotoxy(2,20);printf("                                        ");



    int x;
    do {
        gotoxy(2,14);printf("                                                              ");
        gotoxy(2,14);printf("Ingrese la cantidad de numeros que quiere apostar: ");
        scanf("%i", &x);
        if(x < 1 || x > 20){
            gotoxy(2,15);printf("Numero invalido, recuerde que puede apostar desde uno a veinte numeros\n");
            printf("  ");
            system("pause");
            gotoxy(2,15);printf("                                                                              ");
            gotoxy(2,16);printf("                                                                              ");

        }
    } while(x < 1 || x > 20);


    int aux;
    do{
    pos = 0;
    end = 0;
        gotoxy(2,14);printf("                                                        ");
        gotoxy(2,15);printf("                                                        ");
        gotoxy(2,16);printf("                                                        ");

        gotoxy(2,14);printf("Seleccione una opcion");
        gotoxy(2,15);printf(ROJO_F "- Escoger numeros automaticamente" NEGRO_F);
        gotoxy(2,16);printf("- Escoger numeros manualmente");
        do{
            key = getch();
            switch(key){
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
                        gotoxy(2,14);printf("Seleccione una opcion");
                        gotoxy(2,15);printf(ROJO_F "- Escoger numeros automaticamente" NEGRO_F);
                        gotoxy(2,16);printf("- Escoger numeros manualmente");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(2,14);printf("Seleccione una opcion");
                        gotoxy(2,15);printf("- Escoger numeros automaticamente");
                        gotoxy(2,16);printf(ROJO_F "- Escoger numeros manualmente" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: aux = 1; terminar_programa=1; break;
            case 1: aux = 2; terminar_programa=1; break;

        }
    }while(terminar_programa != 1);

    HashMap *apuestaKeno = createMap(capacidad);
    if(aux == 1) {
        generarA(apuestaKeno, x);
    } else {
        generarM(apuestaKeno, x);
    }

    escribirApuesta(apuestaKeno);
    HashMap *mapResultado = createMap(capacidad);
    correctas(mapKeno, apuestaKeno, mapResultado);
    escribirCorrectas(mapResultado, mapKeno, dinero);
}

void gotoxy(int x , int y){
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(consola,pos);
}

void menu(){
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;



    do{
    pos = 0;
    end = 0;

        char asterisco[2];
        strcpy(asterisco,"*");
        printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("%s%44s\n",asterisco,asterisco);
        printf("%s" CYAN_T "                   KENO" RESET_COLOR"%21s\n",asterisco,asterisco);
        printf("%s%44s\n",asterisco,asterisco);
        printf("* * * * * * * * * * * * * * * * * * * * * * *\n");

        gotoxy(19,6);printf(ROJO_F "-JUGAR" NEGRO_F);
        gotoxy(19,7);printf("-SALIR");
        do{
            key = getch();
            switch(key){
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
                        gotoxy(19,6);printf(ROJO_F "-JUGAR" NEGRO_F);
                        gotoxy(19,7);printf("-SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(19,6);printf("-JUGAR");
                        gotoxy(19,7);printf(ROJO_F "-SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: juego(); break;
            case 1: terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void recompensa() {
    gotoxy(52,1);printf("| APUESTA | AUMENTO |");
    float multiplicador = 0;
    for(int i = 0 ; i < 10 ; i++) {
        gotoxy(52, 2+i);printf("|   %2i    |   %.2f  |\n", i + 1, multiplicador);
        multiplicador += 0.25;
    }
    printf("\n");
}

void generarA(HashMap *map, int x) {
    int *value;
    char *key;
    for(int i = 0 ; i < x ; i++) {
        value = (int*) malloc(sizeof(int));
        key = malloc(sizeof(char) * 10);
        *value = rand() % 80 + 1;
        sprintf(key, "%i", *value);
        while(searchMap(map, key) != NULL) {
            *value = rand() % 80 + 1;
            sprintf(key, "%i", *value);
        }
        insertMap(map, key, value);
    }
}

void generarM(HashMap *map, int x) {
    int *num;

    gotoxy(2,14);printf("                                              ");
    gotoxy(2,15);printf("                                              ");
    gotoxy(2,16);printf("                                              ");

    for(int i = 0 ; i < x ; i++) {
        num = (int *) malloc(sizeof(int));
        char *key = malloc(sizeof(char) * 10);
        gotoxy(2,i+14);printf("Ingrese apuesta %i: ", i + 1);
        do {
            scanf("%i", num);
            sprintf(key, "%i", *num);
            if(*num < 1 || *num > 80){
                    gotoxy(2,i+15);printf("Numero invalido, recuerde que puede apostar desde el uno al ochenta\n");
                    gotoxy(2,i+16);system("pause");
                    gotoxy(2,i+15);printf("                                                                   ");
                    gotoxy(2,i+16);printf("                                                                   ");
                    gotoxy(2,i+14);printf("                                                                   ");
                    gotoxy(2,i+14);printf("Ingrese apuesta %i: ", i + 1);
            }
            if(searchMap(map, key) != NULL){
                    gotoxy(2,i+15);printf("Este numero ya fue apostado, seleccione uno nuevo\n");
                    gotoxy(2,i+16);system("pause");
                    gotoxy(2,i+15);printf("                                                                   ");
                    gotoxy(2,i+16);printf("                                                                   ");
                    gotoxy(2,i+14);printf("                                                                   ");
                    gotoxy(2,i+14);printf("Ingrese apuesta %i: ", i + 1);
            }
        } while(*num < 1 || *num > 80 || searchMap(map, key) != NULL);
        insertMap(map, key, num);
    }
    printf("\n");
}

void escribirApuesta(HashMap *apuestaKeno) {
    system("cls");
    printf("Numeros apostados: ");
    int *p = firstMap(apuestaKeno);
    while(p != NULL) {
        printf("| %i ", *p);
        p = nextMap(apuestaKeno);
    }
    printf("|\n\n");
}

void correctas(HashMap *mapKeno, HashMap *apuestaKeno, HashMap *mapResultado) {
    int *value = firstMap(apuestaKeno);
    while(value != NULL) {
        char *key = malloc(sizeof(char) * 10);
        sprintf(key, "%i", *value);
        if(searchMap(mapKeno, key) != NULL) {
            insertMap(mapResultado, key, value);
        }
        value = nextMap(apuestaKeno);
    }
}

void escribirCorrectas(HashMap *mapResultado, HashMap *mapKeno, float dinero) {
    int num = 1;
    float multiplicador = -0.25, auxDinero = dinero;
    int *value;
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 10 ; j++ ) {
            value = (int *) malloc(sizeof(int));
            *value = num;
            char *key = malloc(sizeof(char) * 10);
            sprintf(key, "%i", *value);
            if(searchMap(mapKeno, key) != NULL) {
                if(searchMap(mapResultado, key) != NULL) {
                    printf(" \x1b[41m %2i \x1b[0m", num);
                    multiplicador += 0.25;
                } else {
                    printf(" \x1b[47m\x1b[30m %2i \x1b[0m", num);
                }
            } else {
                printf("  %2i ", num);
            }
            num++;
        }
        printf("\n");
    }
    if(multiplicador != -0.25) {
        dinero += dinero * multiplicador;
        if(dinero == auxDinero){
            printf("\nNo hubo ganancias\n");
            system("pause");
            system("cls");
        }else{
            printf("\nGanaste $%.0f\n", dinero);
            system("pause");
            system("cls");
        }
    } else {
        printf("\nPerdiste! $-%.0f\n", dinero);
        system("pause");
        system("cls");
    }
}
