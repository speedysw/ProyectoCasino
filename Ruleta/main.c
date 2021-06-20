#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void ruletaMenu();
void ruleta(int,int);
void resultado(int, int);
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
    printf("%s" CYAN_T "                 RULETA" RESET_COLOR"%21s\n",asterisco,asterisco);
    //printf("%s             AZUL EMPATE ROJO              *\n");
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
            case 1: ruletaMenu(); break;
            case 0: break;
            default: printf("\nEl numero que ingreso es incorrecto\n"); break;
        }
        printf("\n");
     }


}


void ruletaMenu(){

    printf("INSTRUCCIONES\n");
    printf("Bienvenido al juego de la ruleta\n"RESET_COLOR);
    printf("\nExisten 5 opciones que puedes elegir luego de ingresar tu apuesta:\n");
    printf(MAGENTA_T"\n1: Esta opcion te multiplica tu apuesta x1.\n");
    printf(VERDE_T "2: Esta opcion te multiplica tu apuesta x2.\n");
    printf(ROJO_T "5: Esta opcion te multiplica tu apuesta x5.\n");
    printf(CYAN_T "10: Esta opcion te multiplica tu apuesta x10.\n");
    printf(AMARILLO_T "Bonus: Esta opcion te multiplica tu apuesta por un numero random entre 1 y 100.\n"RESET_COLOR);

    int apuesta;
    printf("\nIngrese su apuesta \n");
    scanf("%d",&apuesta);

    int seleccion;
    printf("\nSeleccione Numero\n");
    printf("\nOPCIONES\n");
    printf(MAGENTA_T"1: x1.\n");
    printf(VERDE_T"2: x2.\n");
    printf(ROJO_T"5: x5.\n");
    printf(CYAN_T"10: x10.\n");
    printf(AMARILLO_T"99: Bonus\n"RESET_COLOR);
    scanf("%d",&seleccion);


    ruleta(apuesta,seleccion);
}

void ruleta(int apuesta,int seleccion){

    int ruleta[56] = {10,1,2,1,99,1,2,1,5,1,2,1,2,99,1,5,2,1,10,1,2,1,99,2,1,5,2,10,1,2,1,99,2,5,1,2,5,1,2,1,99,1,2,1,10,1,5,2,1,99,1,2,5,1};


    int Seg1,Seg2;
    Seg1=(int)clock()/CLOCKS_PER_SEC;
    Seg2=Seg1;
    int i;

    srand(time(NULL));
    while((Seg2-Seg1) < 10){
        if(clock() % 400 < 10){
            system("cls");
            i = rand() % 55;
            printf ("\n RULETA :\n\n\t%d ",ruleta[i]);
        }
        Seg2=(int)clock()/CLOCKS_PER_SEC;
    }
    int n = ruleta[i];
    n = 99;
    switch(n){
            case 1: if(seleccion == 1) resultado(apuesta,1); else resultado(apuesta,0); break;
            case 2: if(seleccion == 2) resultado(apuesta,2); else resultado(apuesta,0); break;
            case 5: if(seleccion == 5) resultado(apuesta,5); else resultado(apuesta,0); break;
            case 10: if(seleccion == 10) resultado(apuesta,10); else resultado(apuesta,0);break;
            case 99: if(seleccion == 99) resultado(apuesta,99); else resultado(apuesta,0);break;
            case 22: break;
    }




}

void resultado(int apuesta, int multiplicador){

    int Seg1,Seg2;
    Seg1=(int)clock()/CLOCKS_PER_SEC;
    Seg2=Seg1;
    int i;

    int bonus[10] = {10,20,30,40,50,60,70,80,90,100};


    if(multiplicador == 99){
        printf(AMARILLO_T "BONUS\n" RESET_COLOR);

        srand(time(NULL));
        while((Seg2-Seg1) < 10){
            if(clock() % 400 < 10){
                system("cls");
                i = rand() % 10;
                printf ( AMARILLO_T "\n BONUS :\n\n\t%d " RESET_COLOR , multiplicador = bonus[i]);
            }
            Seg2=(int)clock()/CLOCKS_PER_SEC;
        }
            printf("\nFELICIDADES GANASTE: %d\n", apuesta = (apuesta * multiplicador) + apuesta);
    }else{

        if(multiplicador == 0){
            printf("\nLO SIENTO PERDISTE\n");
        }else{
          printf("\nFELICIDADES GANASTE: %d\n",  apuesta = (apuesta * multiplicador) + apuesta );
        }
    }

    //PONERLO MAS BONITO;



}
