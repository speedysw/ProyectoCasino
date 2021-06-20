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
#define NARANJA_T  "\x1b[10m"

void sieteRojo(int);
void sieteAzul(int);
void sieteAmarillo(int);
void limon(int);
void manzana(int);
void ciruela(int);
void uva(int);
void cereza(int);

void gotoxy(int x , int y){

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);

}

int main(){

    system("COLOR");
    int n;
    srand(time(NULL));
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
    for(int i = 0; i < 3 ; i++){
        n = rand () % 8 + 1;
        //n = 1;
        switch(n) {
        case 1: sieteRojo(i); break;
        case 2: sieteAzul(i); break;
        case 3: sieteAmarillo(i); break;
        case 4: limon(i); break;
        case 5: manzana(i); break;
        case 6: ciruela(i); break;
        case 7: uva(i); break;
        case 8: cereza(i); break;
    }
    }
    printf("\n");
    return 0;
}

void sieteRojo(int x) {
    if(x == 0) {
        gotoxy(1,1); printf(ROJO_T "    *****");
        gotoxy(1,2); printf("       *");
        gotoxy(1,3); printf("      *");
        gotoxy(1,4); printf("     *");
        gotoxy(1,5); printf("    *" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(ROJO_T "    *****");
        gotoxy(15,2); printf("       *");
        gotoxy(15,3); printf("      *");
        gotoxy(15,4); printf("     *");
        gotoxy(15,5); printf("    *" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(ROJO_T "    *****");
        gotoxy(30,2); printf("       *");
        gotoxy(30,3); printf("      *");
        gotoxy(30,4); printf("     *");
        gotoxy(30,5); printf("    *" RESET_COLOR);
    }
}

void sieteAzul(int x) {
    if(x == 0) {
        gotoxy(1,1); printf(AZUL_T "    *****");
        gotoxy(1,2); printf("       *");
        gotoxy(1,3); printf("      *");
        gotoxy(1,4); printf("     *");
        gotoxy(1,5); printf("    *" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(AZUL_T "    *****");
        gotoxy(15,2); printf("       *");
        gotoxy(15,3); printf("      *");
        gotoxy(15,4); printf("     *");
        gotoxy(15,5); printf("    *" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(AZUL_T "    *****");
        gotoxy(30,2); printf("       *");
        gotoxy(30,3); printf("      *");
        gotoxy(30,4); printf("     *");
        gotoxy(30,5); printf("    *" RESET_COLOR);
    }

}

void sieteAmarillo(int x) {
    if(x == 0) {
        gotoxy(1,1); printf(AMARILLO_T "    *****");
        gotoxy(1,2); printf("       *");
        gotoxy(1,3); printf("      *");
        gotoxy(1,4); printf("     *");
        gotoxy(1,5); printf("    *" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(AMARILLO_T "    *****");
        gotoxy(15,2); printf("       *");
        gotoxy(15,3); printf("      *");
        gotoxy(15,4); printf("     *");
        gotoxy(15,5); printf("    *" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(AMARILLO_T "    *****");
        gotoxy(30,2); printf("       *");
        gotoxy(30,3); printf("      *");
        gotoxy(30,4); printf("     *");
        gotoxy(30,5); printf("    *" RESET_COLOR);
    }
}

void limon(int x) {
    if(x == 0) {
        gotoxy(1,1); printf(AMARILLO_T "    ****");
        gotoxy(1,2); printf("  *      *");
        gotoxy(1,3); printf(" *        *");
        gotoxy(1,4); printf("  *      *");
        gotoxy(1,5); printf("    ****" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(AMARILLO_T "    ****");
        gotoxy(15,2); printf("  *      *");
        gotoxy(15,3); printf(" *        *");
        gotoxy(15,4); printf("  *      *");
        gotoxy(15,5); printf("    ****" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(AMARILLO_T "    ****");
        gotoxy(30,2); printf("  *      *");
        gotoxy(30,3); printf(" *        *");
        gotoxy(30,4); printf("  *      *");
        gotoxy(30,5); printf("    ****" RESET_COLOR);
    }

}

void manzana(int x) {
    if(x == 0) {
        gotoxy(1,1); printf(ROJO_T "    ****");
        gotoxy(1,2); printf("  *      *");
        gotoxy(1,3); printf(" *        *");
        gotoxy(1,4); printf("  *      *");
        gotoxy(1,5); printf("    ****" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(ROJO_T "    ****");
        gotoxy(15,2); printf("  *      *");
        gotoxy(15,3); printf(" *        *");
        gotoxy(15,4); printf("  *      *");
        gotoxy(15,5); printf("    ****" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(ROJO_T "    ****");
        gotoxy(30,2); printf("  *      *");
        gotoxy(30,3); printf(" *        *");
        gotoxy(30,4); printf("  *      *");
        gotoxy(30,5); printf("    ****" RESET_COLOR);
    }
}

void ciruela(int x) {
    char a = 92;
    if(x == 0) {
        gotoxy(1,1); printf(VERDE_T"     /");
        gotoxy(1,2); printf("    / %c", a);
        gotoxy(1,3); printf(MAGENTA_T"   ** **");
        gotoxy(1,4); printf(" *  *    *");
        gotoxy(1,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(VERDE_T"     /");
        gotoxy(15,2); printf("    / %c", a);
        gotoxy(15,3); printf(MAGENTA_T"   ** **");
        gotoxy(15,4); printf(" *  *    *");
        gotoxy(15,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(VERDE_T"     /");
        gotoxy(30,2); printf("    / %c", a);
        gotoxy(30,3); printf(MAGENTA_T"   ** **");
        gotoxy(30,4); printf(" *  *    *");
        gotoxy(30,5); printf("   ** **" RESET_COLOR);
    }

}

void uva(int x) {
    if(x == 0) {
        gotoxy(1,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(1,2); printf("  ()()()()");
        gotoxy(1,3); printf("   ()()()");
        gotoxy(1,4); printf("    ()()");
        gotoxy(1,5); printf("     ()" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(15,2); printf("  ()()()()");
        gotoxy(15,3); printf("   ()()()");
        gotoxy(15,4); printf("    ()()");
        gotoxy(15,5); printf("     ()" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(30,2); printf("  ()()()()");
        gotoxy(30,3); printf("   ()()()");
        gotoxy(30,4); printf("    ()()");
        gotoxy(30,5); printf("     ()" RESET_COLOR);
    }

}

void cereza(int x) {
    char a = 92;
    if(x == 0) {
        gotoxy(1,1); printf(VERDE_T"     /");
        gotoxy(1,2); printf("    / %c", a);
        gotoxy(1,3); printf(ROJO_T "   ** **");
        gotoxy(1,4); printf(" *  *    *");
        gotoxy(1,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 1) {
        gotoxy(15,1); printf(VERDE_T"     /");
        gotoxy(15,2); printf("    / %c", a);
        gotoxy(15,3); printf(ROJO_T"   ** **");
        gotoxy(15,4); printf(" *  *    *");
        gotoxy(15,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 2) {
        gotoxy(30,1); printf(VERDE_T"     /");
        gotoxy(30,2); printf("    / %c", a);
        gotoxy(30,3); printf(ROJO_T"   ** **");
        gotoxy(30,4); printf(" *  *    *");
        gotoxy(30,5); printf("   ** **" RESET_COLOR);
    }
}
