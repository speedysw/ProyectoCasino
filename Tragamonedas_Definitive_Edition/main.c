#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

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
#define NARANJA_T  "\x1b[10m"

void sieteRojo(int);
void limon(int);
void manzana(int);
void ciruela(int);
void uva(int);
void cereza(int);
void maquina(int);
void titulo();
void menuJuego();
void menu();

void gotoxy(int x , int y){
HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);
}

int main(){
    menu();
    return 0;
}

void menu(){
    system("cls");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    titulo();

    flag1=0,terminar_programa=0;
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
            case 1: terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void menuJuego(){
    system("cls");
    int dinero, n;

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
    system("cls");

    flag1=0,terminar_programa=0;

    do{
        pos = 0;
        end = 0;

        gotoxy(0,0); printf("%c", 201);
        gotoxy(43,0); printf("%c", 187);
        gotoxy(0,6); printf("%c", 200);
        gotoxy(43,6); printf("%c", 188);
        for(int i = 1 ; i < 43 ; i++) {
            if(i == 14 || i == 29) {
                gotoxy(i,0); printf("%c", 203);
                gotoxy(i,6); printf("%c", 202);
            }else{
                gotoxy(i,0); printf("%c", 205);
                gotoxy(i,6); printf("%c", 205);
            }
        }
        for(int i = 1 ; i < 6 ; i++) {
            gotoxy(0,i); printf("%c", 186);
            gotoxy(43,i); printf("%c", 186);
            gotoxy(14,i); printf("%c", 186);
            gotoxy(29,i); printf("%c", 186);
        }

        gotoxy(45,2);printf("***TRAGAMONEDAS***");
        gotoxy(45,3);printf(CYAN_F " -HACER TIRADA" NEGRO_F);
        do{
            key = getch();
            switch(key){
                case 72: if (pos == 0)
                        pos = 0;
                        else pos--;
                        break;
                case 80: if (pos == 0) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(45,2);printf("***TRAGAMONEDAS***");
                        gotoxy(45,3);printf(CYAN_F " -HACER TIRADA" NEGRO_F);
                        flag1=0;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: maquina(dinero); terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void titulo(){
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "                TRAGAMONEDAS" RESET_COLOR"%16s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

void maquina(int dinero){
    system("COLOR");
    int n;
    srand(time(NULL));
    // El gotoxy es utilizado para decoracion y elegancia
    gotoxy(0,0); printf("%c", 201);
    gotoxy(43,0); printf("%c", 187);
    gotoxy(0,6); printf("%c", 200);
    gotoxy(43,6); printf("%c", 188);
    for(int i = 1 ; i < 43 ; i++) {
        if(i == 14 || i == 29) {
            gotoxy(i,0); printf("%c", 203);
            gotoxy(i,6); printf("%c", 202);
        } else {
            gotoxy(i,0); printf("%c", 205);
            gotoxy(i,6); printf("%c", 205);
        }
    }
    for(int i = 1 ; i < 6 ; i++) {
        gotoxy(0,i); printf("%c", 186);
        gotoxy(43,i); printf("%c", 186);
        gotoxy(14,i); printf("%c", 186);
        gotoxy(29,i); printf("%c", 186);
    }
    int a, b, c; // a = simbolo izquierdo, b = simbolo central, c = simbolo derecha
    for(int i = 0; i < 3 ; i++){
        n = rand () % 6 + 1;
        if(i == 0) a = n;
        if(i == 1) b = n;
        if(i == 2) c = n;
        // Dependiendo de la n aleatoria, se dibujara el respectivo simbolo
        switch(n) {
        case 1: sieteRojo(i); break;
        case 2: limon(i); break;
        case 3: manzana(i); break;
        case 4: ciruela(i); break;
        case 5: uva(i); break;
        case 6: cereza(i); break;
        }
    }
    // Si coinciden los 3 simbolos, se le entrega el premio al usuario, en caso contrario pierde la mitad
    if(a == b && a == c) {
        printf("\n\n\nHas ganado : %i", dinero);
        dinero += dinero;
    } else {
        dinero = trunc(dinero/2);
        printf("\n\n\nHas perdido : %i", dinero);
    }
    printf("\n");
    system("pause");
    system("cls");
    titulo();
}

// Se escribe el simbolo que reprecenta al "siete", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void sieteRojo(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(ROJO_T "    *****");
        gotoxy(1,2); printf("       *");
        gotoxy(1,3); printf("      *");
        gotoxy(1,4); printf("     *");
        gotoxy(1,5); printf("    *" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(ROJO_T "    *****");
        gotoxy(15,2); printf("       *");
        gotoxy(15,3); printf("      *");
        gotoxy(15,4); printf("     *");
        gotoxy(15,5); printf("    *" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(ROJO_T "    *****");
        gotoxy(30,2); printf("       *");
        gotoxy(30,3); printf("      *");
        gotoxy(30,4); printf("     *");
        gotoxy(30,5); printf("    *" RESET_COLOR);
    }
}

// Se escribe el simbolo que reprecenta al "limon", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void limon(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(AMARILLO_T "    ****");
        gotoxy(1,2); printf("  *      *");
        gotoxy(1,3); printf(" *        *");
        gotoxy(1,4); printf("  *      *");
        gotoxy(1,5); printf("    ****" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(AMARILLO_T "    ****");
        gotoxy(15,2); printf("  *      *");
        gotoxy(15,3); printf(" *        *");
        gotoxy(15,4); printf("  *      *");
        gotoxy(15,5); printf("    ****" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(AMARILLO_T "    ****");
        gotoxy(30,2); printf("  *      *");
        gotoxy(30,3); printf(" *        *");
        gotoxy(30,4); printf("  *      *");
        gotoxy(30,5); printf("    ****" RESET_COLOR);
    }

}

// Se escribe el simbolo que reprecenta a la "manzana", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void manzana(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(ROJO_T "    ****");
        gotoxy(1,2); printf("  *      *");
        gotoxy(1,3); printf(" *        *");
        gotoxy(1,4); printf("  *      *");
        gotoxy(1,5); printf("    ****" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(ROJO_T "    ****");
        gotoxy(15,2); printf("  *      *");
        gotoxy(15,3); printf(" *        *");
        gotoxy(15,4); printf("  *      *");
        gotoxy(15,5); printf("    ****" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(ROJO_T "    ****");
        gotoxy(30,2); printf("  *      *");
        gotoxy(30,3); printf(" *        *");
        gotoxy(30,4); printf("  *      *");
        gotoxy(30,5); printf("    ****" RESET_COLOR);
    }
}

// Se escribe el simbolo que reprecenta a la "ciruela", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void ciruela(int x) {
    char a = 92;
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(VERDE_T"     /");
        gotoxy(1,2); printf("    / %c", a);
        gotoxy(1,3); printf(MAGENTA_T"   ** **");
        gotoxy(1,4); printf(" *  *    *");
        gotoxy(1,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(VERDE_T"     /");
        gotoxy(15,2); printf("    / %c", a);
        gotoxy(15,3); printf(MAGENTA_T"   ** **");
        gotoxy(15,4); printf(" *  *    *");
        gotoxy(15,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(VERDE_T"     /");
        gotoxy(30,2); printf("    / %c", a);
        gotoxy(30,3); printf(MAGENTA_T"   ** **");
        gotoxy(30,4); printf(" *  *    *");
        gotoxy(30,5); printf("   ** **" RESET_COLOR);
    }

}

// Se escribe el simbolo que reprecenta a la "uva", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void uva(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(1,2); printf("  ()()()()");
        gotoxy(1,3); printf("   ()()()");
        gotoxy(1,4); printf("    ()()");
        gotoxy(1,5); printf("     ()" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(15,2); printf("  ()()()()");
        gotoxy(15,3); printf("   ()()()");
        gotoxy(15,4); printf("    ()()");
        gotoxy(15,5); printf("     ()" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(30,2); printf("  ()()()()");
        gotoxy(30,3); printf("   ()()()");
        gotoxy(30,4); printf("    ()()");
        gotoxy(30,5); printf("     ()" RESET_COLOR);
    }

}

// Se escribe el simbolo que reprecenta a la "cereza", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void cereza(int x) {
    char a = 92;
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(VERDE_T"     /");
        gotoxy(1,2); printf("    / %c", a);
        gotoxy(1,3); printf(ROJO_T "   ** **");
        gotoxy(1,4); printf(" *  *    *");
        gotoxy(1,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(VERDE_T"     /");
        gotoxy(15,2); printf("    / %c", a);
        gotoxy(15,3); printf(ROJO_T"   ** **");
        gotoxy(15,4); printf(" *  *    *");
        gotoxy(15,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(VERDE_T"     /");
        gotoxy(30,2); printf("    / %c", a);
        gotoxy(30,3); printf(ROJO_T"   ** **");
        gotoxy(30,4); printf(" *  *    *");
        gotoxy(30,5); printf("   ** **" RESET_COLOR);
    }
}

