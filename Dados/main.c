#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void titulo();
void menu();
void crapsMenu();
void craps(int,int,int);

void gotoxy(int x , int y){

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);

}


int main(){

    titulo();
    menu();
    system("pause");
    return 0;
}


void titulo(){

    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" VERDE_T "                 CRAPS" RESET_COLOR"%22s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");

}

void menu(){

    int n;
    while(n != 0){
         printf("\nOPCIONES\n");
         printf("1. Jugar\n");
         printf("0. salir\n");
         scanf("%d",&n);
         fflush(stdin);
       switch(n){
            case 1: crapsMenu(); break;
            case 0: break;
            default: printf("\nEl numero que ingreso es incorrecto\n"); break;
        }
        printf("\n");
     }
}

void crapsMenu(){

    int n;

    int apuesta;
    int sumaUsuario,sumaDados;
    int revolver;
    printf(AMARILLO_T"\nINSTRUCCIONES\n"RESET_COLOR);
    printf(VERDE_T"\nBienvenido al juego craps\n"RESET_COLOR);
    printf(AZUL_T "\nPuede elegir entre 2 opciones de apuesta:\n"RESET_COLOR);
    printf("1: Apuestas a acertar la suma de ambos dados x2.\n");
    printf(CYAN_T "2: Apuestas a acertar el numero de un dado x1.\n"RESET_COLOR);

    printf("\nEscoga su opcion\n");
    scanf("%d",&n);

      if(n == 1){
        printf(AMARILLO_T"\n$$ Ingrese cuanto desea apostar $$\n"RESET_COLOR);
        scanf("%d",&apuesta);
        printf(VERDE_T"\n** Ingrese cuanto sumaran ambos dados **\n"RESET_COLOR);
        scanf("%d",&sumaUsuario);
        printf("\n=== Presione R para revolver dados === \n");
        scanf("%d",&revolver);
     }

       if(n == 2){
        printf(AMARILLO_T"\n$$ Ingrese cuanto desea apostar $$\n"RESET_COLOR);
        scanf("%d",&apuesta);
        printf(VERDE_T"\n** Ingrese cual sera el numero de al menos un dado **\n"RESET_COLOR);
        scanf("%d",&sumaUsuario);
        printf("\n=== Presione R para revolver dados === \n");
        scanf("%d",&revolver);
     }
        craps(apuesta,sumaUsuario,n);

}

void craps(int apuesta, int sumaUsuario,int n){
    system("cls");
    int dado1,dado2;
    int sumaDados;
    srand(time(NULL));
    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;

    printf("\nDado 1: %d y Dado 2: %d\n",dado1,dado2 );
    sumaDados = dado1 + dado2;

    if(n == 1){
        if(sumaUsuario == sumaDados){
            apuesta = (apuesta * 2) + apuesta;
            printf("GANASTE!!!");
            printf("\nHas ganado $ %d",apuesta);
        }else{
            printf("\nPERDISTE\n");
        }
    }

    if(n == 2){

        if((sumaUsuario == dado1) || (sumaUsuario == dado2)){
            apuesta = (apuesta * 1) + apuesta;
            printf("GANASTE!!!\n");
            printf("\nHas ganado $ %d",apuesta);
        }else{
            printf("\nPERDISTE\n");
        }
    }

}
