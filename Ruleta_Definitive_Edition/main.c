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
void ruletaMenu();
void ruleta(int,int);
void resultado(int, int, int);
void gotoxy(int , int );

int main(){

    titulo();
    menu();
    return 0;
}

void titulo(){
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "                 RULETA" RESET_COLOR"%21s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

void menu(){
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,6);printf("OPCIONES");
        gotoxy(2,7);printf(ROJO_F " -JUGAR" NEGRO_F);
        gotoxy(2,8);printf(" -SALIR");
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
                        gotoxy(5,6);printf("OPCIONES");
                        gotoxy(2,7);printf(ROJO_F " -JUGAR" NEGRO_F);
                        gotoxy(2,8);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,6);printf("OPCIONES");
                        gotoxy(2,7);printf(" -JUGAR");
                        gotoxy(2,8);printf(ROJO_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: ruletaMenu(); break;
            case 1: terminar_programa=1; printf("\n");
        }
    }while(terminar_programa != 1);
}

void ruletaMenu(){
    printf("\n\n***INSTRUCCIONES***\n");
    printf("Bienvenido al juego de la ruleta\n"RESET_COLOR);
    printf("\nExisten 5 opciones que puedes elegir luego de ingresar tu apuesta:\n");
    printf(MAGENTA_T"\n1: Esta opcion te multiplica tu apuesta x1.\n");
    printf(VERDE_T "2: Esta opcion te multiplica tu apuesta x2.\n");
    printf(ROJO_T "5: Esta opcion te multiplica tu apuesta x5.\n");
    printf(CYAN_T "10: Esta opcion te multiplica tu apuesta x10.\n");
    printf(AMARILLO_T "Bonus: Esta opcion te multiplica tu apuesta por un numero random entre 1 y 100.\n"RESET_COLOR);
    printf("\n");
    system("pause");

    int apuesta;
    system("cls");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,1);printf("Seleccione su apuesta");
        gotoxy(2,2);printf(ROJO_F " - 2500$" NEGRO_F);
        gotoxy(2,3);printf(" - 5000$");
        gotoxy(2,4);printf(" - 10000$");
        gotoxy(2,5);printf(" - 15000$");
        gotoxy(2,6);printf(" - 20000$");
        do{
            key = getch();
            switch(key){
                case 72: if (pos == 0)
                        pos = 4;
                        else pos--;
                        break;
                case 80: if (pos == 4) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(ROJO_F " - 2500$" NEGRO_F);
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(ROJO_F " - 5000$" NEGRO_F);
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(ROJO_F " - 10000$" NEGRO_F);
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(ROJO_F " - 15000$" NEGRO_F);
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(ROJO_F " - 20000$" NEGRO_F);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: apuesta = 2500; terminar_programa = 1; break;
            case 1: apuesta = 5000; terminar_programa = 1; break;
            case 2: apuesta = 10000; terminar_programa = 1; break;
            case 3: apuesta = 15000; terminar_programa = 1; break;
            case 4: apuesta = 20000; terminar_programa = 1; break;
        }
    }while(terminar_programa != 1);

    int seleccion;
    system("cls");
    system("color");
    flag1=0,terminar_programa=0;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,1);printf("Seleccione su opcion de juego");
        gotoxy(2,2);printf(MAGENTA_T BLANCO_F "x1\n" NEGRO_F);
        gotoxy(2,3);printf(VERDE_T"x2\n");
        gotoxy(2,4);printf(ROJO_T"x5\n");
        gotoxy(2,5);printf(CYAN_T"x10\n");
        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
        do{
            key = getch();
            switch(key){
                case 72: if (pos == 0)
                        pos = 4;
                        else pos--;
                        break;
                case 80: if (pos == 4) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T BLANCO_F "x1\n" NEGRO_F);
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T BLANCO_F "x2\n" NEGRO_F);
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=1;
                        break;
                case 2:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T BLANCO_F "x5\n" NEGRO_F);
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T BLANCO_F "x10\n" NEGRO_F);
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T BLANCO_F "Bonus\n"RESET_COLOR);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: seleccion = 1; terminar_programa = 1; break;
            case 1: seleccion = 2; terminar_programa = 1; break;
            case 2: seleccion = 5; terminar_programa = 1; break;
            case 3: seleccion = 10; terminar_programa = 1; break;
            case 4: seleccion = 99; terminar_programa = 1; break;
        }
    }while(terminar_programa != 1);

    ruleta(apuesta,seleccion);
}

void ruleta(int apuesta,int seleccion){
    int ruleta[36] = {1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10};

    int Seg1,Seg2;
    Seg1=(int)clock()/CLOCKS_PER_SEC;
    Seg2=Seg1;
    int i;

    srand(time(NULL));
    while((Seg2-Seg1) < 10){
        if(clock() % 400 < 10){
            system("cls");
            i = rand() % 35 + 1;
            printf("                                \x1b[46m 10 \x1b[0m  \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                          \x1b[30m\x1b[47m 1 \x1b[0m              \x1b[42m 2 \x1b[0m\n");
            printf("                    \x1b[41m 5 \x1b[0m                         \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                \x1b[42m 2 \x1b[0m                                 \x1b[43m 99 \x1b[0m\n\n");
            printf("           \x1b[30m\x1b[47m 1 \x1b[0m                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("        \x1b[43m 99 \x1b[0m                                                 \x1b[42m 2 \x1b[0m\n\n");
            printf("     \x1b[30m\x1b[47m 1 \x1b[0m                                                       \x1b[41m 5 \x1b[0m\n\n");
            printf("   \x1b[42m 2 \x1b[0m                                                          \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("  \x1b[30m\x1b[47m 1 \x1b[0m               %15d                             \x1b[46m 10 \x1b[0m\n\n", ruleta[i]);
            printf("  \x1b[46m 10 \x1b[0m                                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("   \x1b[30m\x1b[47m 1 \x1b[0m                                                          \x1b[42m 2 \x1b[0m\n\n");
            printf("     \x1b[41m 5 \x1b[0m                                                      \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("        \x1b[42m 2 \x1b[0m                                                \x1b[43m 99 \x1b[0m\n\n");
            printf("           \x1b[30m\x1b[47m 1 \x1b[0m                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("               \x1b[43m 99 \x1b[0m                                  \x1b[42m 2 \x1b[0m\n");
            printf("                     \x1b[30m\x1b[47m 1 \x1b[0m                        \x1b[41m 5 \x1b[0m\n");
            printf("                          \x1b[42m 2 \x1b[0m              \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                               \x1b[30m\x1b[47m 1 \x1b[0m   \x1b[46m 10 \x1b[0m\n");
        }
        Seg2=(int)clock()/CLOCKS_PER_SEC;
    }
    system("Pause");
    system("cls");
    int n = ruleta[i];
    switch(n){
            case 1: if(seleccion == 1) resultado(apuesta,1,n); else resultado(apuesta,0,n); break;
            case 2: if(seleccion == 2) resultado(apuesta,2,n); else resultado(apuesta,0,n); break;
            case 5: if(seleccion == 5) resultado(apuesta,5,n); else resultado(apuesta,0,n); break;
            case 10: if(seleccion == 10) resultado(apuesta,10,n); else resultado(apuesta,0,n);break;
            case 99: if(seleccion == 99) resultado(apuesta,99,n); else resultado(apuesta,0,n);break;
            case 22: break;
    }
}

void resultado(int apuesta, int multiplicador, int n){
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
}

void gotoxy(int x , int y){
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(consola,pos);
}
