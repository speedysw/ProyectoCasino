#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hashmap.h"

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


typedef struct{

    char *carta;

}adivino;


void llenarMapa(HashMap *);
void titulo();
void menu(HashMap *);
void resultado(int, int);

adivino *crearMaso(){

    adivino *aux = (adivino *) malloc(sizeof(adivino));
    aux->carta = (char *) malloc(sizeof(char) * 20);
    return aux;
}

int main(){


    HashMap *adv = createMap(10);
    llenarMapa(adv);
    menu(adv);
    system("pause");
    return 0;
}

void llenarMapa(HashMap *adv){
    adivino *maso;
    int *random;
    char *key;
    for(int i = 0; i <= 3; i++){

        maso = crearMaso();

        random = (int *) malloc(sizeof(int));

        key = (char *) malloc(sizeof(char)* 10);


        *random = i + 1;

        sprintf(key, "%i", *random);

        if(i == 0) maso->carta =  strdup("AS DE COPAS");
        if(i == 1) maso->carta =  strdup("AS DE BASTOS");
        if(i == 2) maso->carta =  strdup("AS DE OROS");
        if(i == 3) maso->carta =  strdup("AS DE ESPADAS");
        insertMap(adv, key, maso);

    }
}


void titulo(){


    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "             ADIVINA LA CARTA" RESET_COLOR"%15s\n",asterisco,asterisco);
    //printf("%s             AZUL EMPATE ROJO              *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");

}

void menu(HashMap *adv){

    int n;
    while(n != 0){
         titulo();
         printf("\nOPCIONES\n");
         printf("1. Jugar\n");
         printf("0. salir\n");
         fflush(stdin);
         scanf("%d",&n);
         fflush(stdin);

        switch(n){
            case 1: carta(adv); break;
            case 0: break;
            default: printf("\nEl numero que ingreso es incorrecto\n"); break;
        }
        printf("\n");
     }


}

void carta(HashMap *adv){

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

    printf(AMARILLO_T"\nINSTRUCCIONES\n"RESET_COLOR);
    printf(VERDE_T"\nBienvenido al juego adivina la carta\n"RESET_COLOR);
    printf(AZUL_T "\nEste juego consta en adivinar que carta saldra\n"RESET_COLOR);
    printf("\nEscoge una opcion: \n");
    printf(CYAN_T "\n1: AS DE COPAS\n"RESET_COLOR);
    printf(MAGENTA_T "2: AS DE BASTOS\n"RESET_COLOR);
    printf(ROJO_T "3: AS DE OROS\n"RESET_COLOR);
    printf(AMARILLO_T "4: AS DE ESPADAS\n"RESET_COLOR);

    do{

    scanf("%d",&carta);
    fflush(stdin);
    if(carta < 1 || carta > 4) printf("La opcion ingresada no es valida, vuelva a intentarlo\n");

    }while(carta < 1 || carta > 4);

    *usuario = carta;
    srand(time(NULL));
    *n = rand () % 4 + 1;;

    printf("\nIngrese Su Apuesta\n");
    scanf("%d",&apuesta);
    fflush(stdin);
    sprintf(key, "%i", *n);

    printf("\n=== Presione cualquier tecla para sacar una carta === \n");
    scanf("%d",&revolver);
    fflush(stdin);
    system("cls");

    adivino *p = searchMap(adv, key);
    printf(AMARILLO_T "Ha salido la carta %s",*p);

    if(*usuario == *n){
        printf(VERDE_T "\nGANASTE!!\n");
        printf(VERDE_T "Has ganado %d",apuesta *= 2);
        printf(""RESET_COLOR);
    }else{
        printf(ROJO_T "\nHas perdido, vuelve a intentarlo\n" RESET_COLOR);
    }

    printf("\n");
    system("PAUSE");
    system("cls");
}
