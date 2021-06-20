#include <stdio.h>
#include <stdlib.h>
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
void azulYrojo();
void gotoxy(int, int);

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
    printf("%s" ROJO_T "            ROJO "  RESET_COLOR "EMPATE" AZUL_T " AZUL " RESET_COLOR"%15s\n",asterisco,asterisco);
    //printf("%s             AZUL EMPATE ROJO              *\n");
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
                        gotoxy(2,8);printf(AZUL_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: azulYrojo(); break;
            case 1: terminar_programa=1; printf("\n");
        }

    }while(terminar_programa != 1);
}

void gotoxy(int x , int y){

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);

}

void azulYrojo(){
     system("COLOR");
    int apuesta;
    int color;

    int pos,end,flag=0,terminar_programa=0;
    char key;

    do{
        pos = 0;
        end = 0;
        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
        gotoxy(2,13);printf(ROJO_F " - $1000" NEGRO_F);
        gotoxy(2,14);printf(" - $2500");
        gotoxy(2,15);printf(" - $5000");
        gotoxy(2,16);printf(" - $10000");
        gotoxy(2,17);printf(" - $20000");
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
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(ROJO_F " - $1000" NEGRO_F);
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(" - $20000");
                        flag=0;
                        break;
                case 1:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(ROJO_F " - $2500" NEGRO_F);
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(" - $20000");
                        flag=1;
                        break;
                case 2:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(ROJO_F " - $5000" NEGRO_F);
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(" - $20000");
                        flag=2;
                        break;
                case 3:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(ROJO_F " - $10000" NEGRO_F);
                        gotoxy(2,17);printf(" - $20000");
                        flag=3;
                        break;
                case 4:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(ROJO_F " - $20000" NEGRO_F);
                        flag=4;
                        break;
            }
        }while(end != 1);

        switch(flag)
        {
            case 0: apuesta = 1000;
                    terminar_programa = 1;
                    break;

            case 1: apuesta = 2500;
                    terminar_programa = 1;
                    break;

            case 2: apuesta = 5000;
                    terminar_programa = 1;
                    break;
            case 3:
                    apuesta = 10000;
                    terminar_programa = 1;
                    break;
            case 4:
                    apuesta = 20000;
                    terminar_programa = 1;
                    break;
        }

    }while(terminar_programa != 1);

    int pos1,end1,flag1=0,terminar_programa1=0;
    char key1;

    do{
        pos1 = 0;
        end1 = 0;
        gotoxy(5,19);printf("ESCOJA UNA OPCION");
        gotoxy(2,20);printf(ROJO_F " -ROJO" NEGRO_F);
        gotoxy(2,21);printf(" -EMPATE");
        gotoxy(2,22);printf(" -AZUL");
        do{
            key1 = getch();
            switch(key1){
                case 72: if (pos1 == 0)
                        pos1 = 2;
                        else pos1--;
                        break;
                case 80: if (pos1 == 2) pos1 =0;
                        else pos1++;
                        break;
                case 13: end1 = 1;
            }
            switch(pos1){
                case 0:
                        gotoxy(5,19);printf("ESCOJA UNA OPCION");
                        gotoxy(2,20);printf(ROJO_F " -ROJO" NEGRO_F);
                        gotoxy(2,21);printf(" -EMPATE");
                        gotoxy(2,22);printf(" -AZUL");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,19);printf("ESCOJA UNA OPCION");
                        gotoxy(2,20);printf(" -ROJO");
                        gotoxy(2,21);printf(BLANCO_F NEGRO_T " -EMPATE" NEGRO_F BLANCO_T);
                        gotoxy(2,22);printf(" -AZUL");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(5,19);printf("ESCOJA UNA OPCION");
                        gotoxy(2,20);printf(" -ROJO");
                        gotoxy(2,21);printf(" -EMPATE");
                        gotoxy(2,22);printf(AZUL_F " -AZUL" NEGRO_F);
                        flag1=2;
                        break;
            }
        }while(end1 != 1);

        switch(flag1)
        {
            case 0: color = 1;
                    terminar_programa1 = 1;
                    break;

            case 1: color = 2;
                    terminar_programa1 = 1;
                    break;

            case 2: color = 3;
                    terminar_programa1 = 1;
                    break;
        }

    }while(terminar_programa1 != 1);

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
    printf("\n");
    system("pause");
    system("cls");
    titulo();
}
