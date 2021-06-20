#include <stdio.h>
#include <stdlib.h>

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
void azulYrojo();

int main()
{
    titulo();
    menu();

    system("PAUSE");
    return 0;
}

void titulo(){


    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" ROJO_T "            ROJO "  RESET_COLOR "EMPATE" AZUL_T " AZUL " RESET_COLOR"%15s\n",asterisco,asterisco);
    //printf("%s             AZUL EMPATE ROJO              *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");


}

void menu(){
    int n;
    while(n != 0){
         printf("\nOPCIONES\n");
         printf("1. Jugar\n");
         printf("2. Limpiar CMD\n");
         printf("0. salir\n");
         scanf("%d",&n);
         fflush(stdin);
       switch(n){
            case 1: azulYrojo(); break;
            case 2: system("cls"); titulo(); break;
            case 0: break;
            default: printf("\nEl numero que ingreso es incorrecto\n"); break;
        }
        printf("\n");
     }


}

void azulYrojo(){
    system("COLOR");
    int color;
    char resultado[10];
    int apuesta;
    printf("\nIngrese su apuesta\n");
    scanf("%d",&apuesta);
    printf("\nIngrese su opcion\n");
    printf(ROJO_T "1.ROJO\n");
    printf(RESET_COLOR "2.EMPATE\n");
    printf(AZUL_T "3.AZUL\n");
    printf(RESET_COLOR"");
    scanf("%d",&color);



    int n;
    srand(time(NULL));
    n = rand () % 3 + 1;

    if(n == 1){

        if(n == color){
            apuesta *= 2;
            printf(ROJO_T "\nGanaste ha salido ROJO\n");
            printf(RESET_COLOR "FELICIDADES GANASTE %d",apuesta);
        }else{
            printf(ROJO_T "\nPERDISTE HA SALIDO ROJO \n");
            printf("GANASTE 0");
        }
    }

    if(n == 2){

         if(n == color){
            apuesta *= 2;
            printf(RESET_COLOR "\nGanaste ha salido EMPATE\n");
            printf(RESET_COLOR "GANASTE %d",apuesta);
        }else{
            printf(RESET_COLOR "\nPERDISTE HA SALIDO EMPATE\n");
            printf("GANASTE 0");
        }
    }

        if(n == 3){
         if(n == color){
            apuesta *= 2;
            printf(AZUL_T "\nGanaste ha salido AZUL\n");
            printf(RESET_COLOR "GANASTE %d",apuesta);
        }else{
            printf(AZUL_T "\nPERDISTE HA SALIDO AZUL \n");
            printf("GANASTE 0\n");
        }
        }
    printf(RESET_COLOR"");

}
