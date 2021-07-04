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

void titulo();//Funcion para mostrar el titulo de la aplicacion
void menu();//Funcion para acceder al menu de la aplicacion
void crapsMenu(); //Funcion para escoger las opciones de apuesta del craps
void craps(int,int,int); //Funcion que da los resultados y revuelve los dados

void gotoxy(int x , int y){ //Funcion para hacer el menu dinamico
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

void titulo(){//Funcion para mostrar el titulo de la aplicacion
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" VERDE_T "                 CRAPS" RESET_COLOR"%22s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

void menu(){//Funcion para acceder al menu de la aplicacion
    titulo();
    int pos,end,flag1=0,terminar_programa=0;
    char key;
    do{
    pos = 0;
    end = 0;
        gotoxy(16,6);printf(ROJO_F "-JUGAR" NEGRO_F);
        gotoxy(16,7);printf("-SALIR");
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
                        gotoxy(16,6);printf(ROJO_F "-JUGAR" NEGRO_F);
                        gotoxy(16,7);printf("-SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(16,6);printf("-JUGAR");
                        gotoxy(16,7);printf(ROJO_F "-SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: crapsMenu(); break;
            case 1: terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void crapsMenu(){//Funcion para escoger las opciones de apuesta del craps
    system("cls");
    int n;
    int apuesta;
    int sumaUsuario,sumaDados;
    int revolver;

    gotoxy(1,1);printf(VERDE_T"Bienvenido al juego craps\n"RESET_COLOR);
    gotoxy(1,2);printf(AZUL_T "Puede elegir entre 2 opciones de apuesta:\n"RESET_COLOR);

    int pos,end,flag1=0,terminar_programa=0;
    char key;
    do{
    pos = 0;
    end = 0;
        gotoxy(1,4);printf(ROJO_F "- Apostar a acertar la suma de ambos dados" NEGRO_F); //Condicionales para las opciones de apuesta
        gotoxy(1,5);printf("- Apostar a acertar el numero de un dado");
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
                        gotoxy(1,4);printf(ROJO_F "- Apostar a acertar la suma de ambos dados" NEGRO_F);
                        gotoxy(1,5);printf("- Apostar a acertar el numero de un dado");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,4);printf("- Apostar a acertar la suma de ambos dados");
                        gotoxy(1,5);printf(ROJO_F "- Apostar a acertar el numero de un dado" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)  //Switch que permite saber que eligio el usuario
        {
            case 0: n = 1; terminar_programa=1; break;
            case 1: n = 2; terminar_programa=1; break;
        }
    }while(terminar_programa != 1);

      if(n == 1){
        system("cls");
        flag1=0,terminar_programa=0;
        do{
                pos = 0;
                end = 0;
                gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR); //Opciones para que el usuario escoga cuanto quiere apostar
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
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf(ROJO_F "- $1000" NEGRO_F);
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf(ROJO_F "- $2000" NEGRO_F);
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 2:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf(ROJO_F "- $3500" NEGRO_F);
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 3:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 4:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 5:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=1;
                            break;
                }
                }while(end != 1);

                switch(flag1) //Switch que nos permite saber cuanto aposto el usuario
                {
                    case 0: apuesta = 1000; terminar_programa=1; break;
                    case 1: apuesta = 2000; terminar_programa=1; break;
                    case 2: apuesta = 3500; terminar_programa=1; break;
                    case 3: apuesta = 5000; terminar_programa=1; break;
                    case 4: apuesta = 7500; terminar_programa=1; break;
                    case 5: apuesta = 10000; terminar_programa=1; break;
                }
                }while(terminar_programa != 1);

        system("cls");
        gotoxy(1,1);printf(VERDE_T"** Ingrese cuanto sumaran ambos dados **\n"RESET_COLOR); //Dependiendo de la opcion del usuario aca se le dara la opcion que el escoga
        gotoxy(18,2);
        do
        {
            scanf("%d", &sumaUsuario);

            if(sumaUsuario < 1 || sumaUsuario > 12){
                gotoxy(1,4);printf("Recuerde ingresar una suma entre 1 y 12");
                gotoxy(1,5);system("pause");
                gotoxy(1,5);printf("                                               ");
                gotoxy(1,4);printf("                                            ");
                gotoxy(18,2);printf("           ");
                gotoxy(18,2);scanf("%d", &sumaUsuario);
            }
        }while((sumaUsuario > 12 || sumaUsuario < 1));

        printf("\n=== Presione una tecla para revolver dados === \n"); //Funcion que permite revolver los dados y ir a otra funcion
        }

    if(n == 2){
            system("cls");
            flag1=0,terminar_programa=0;
            do{
                pos = 0;
                end = 0;
                gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
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
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf(ROJO_F "- $1000" NEGRO_F);
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf(ROJO_F "- $2000" NEGRO_F);
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 2:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf(ROJO_F "- $3500" NEGRO_F);
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 3:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 4:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 5:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=1;
                            break;
                }
                }while(end != 1);

                switch(flag1)
                {
                    case 0: apuesta = 1000; terminar_programa=1; break;
                    case 1: apuesta = 2000; terminar_programa=1; break;
                    case 2: apuesta = 3500; terminar_programa=1; break;
                    case 3: apuesta = 5000; terminar_programa=1; break;
                    case 4: apuesta = 7500; terminar_programa=1; break;
                    case 5: apuesta = 10000; terminar_programa=1; break;
                }
                }while(terminar_programa != 1);

            system("cls");
            gotoxy(1,1);printf(VERDE_T"** Ingrese cual sera el numero de al menos un dado **"RESET_COLOR);
            gotoxy(25,2);
            do
            {
                scanf("%d", &sumaUsuario);

                if(sumaUsuario < 1 || sumaUsuario > 6){
                    gotoxy(1,4);printf("Recuerde ingresar un numero de dado entre 1 y 6");
                    gotoxy(1,5);system("pause");
                    gotoxy(1,5);printf("                                                         ");
                    gotoxy(1,4);printf("                                                       ");
                    gotoxy(25,2);printf("                ");
                    gotoxy(25,2);scanf("%d", &sumaUsuario);
                }
            }while(sumaUsuario > 6 || sumaUsuario < 1);

            gotoxy(1,4);printf("=== Presione una tecla para revolver dados ===");
            gotoxy(22,5);revolver = getch();
    }
    craps(apuesta,sumaUsuario,n);
}

void craps(int apuesta, int sumaUsuario,int n){ //Funcion que da los resultados y revuelve los dados
    system("cls");
    int dado1,dado2;
    int sumaDados;
    srand(time(NULL));
    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;

    printf("\nDado 1: %d y Dado 2: %d\n",dado1,dado2 ); //Mediante 2 rand haremos la suma de los dados y mostraremos el resultado
    sumaDados = dado1 + dado2;

    if(n == 1){
        if(sumaUsuario == sumaDados){
            apuesta = (apuesta * 2) + apuesta;
            printf("GANASTE!!!");
            printf("\nHas ganado $ %d\n",apuesta);
            system("pause");
            system("cls");
            titulo();
        }else{
            printf("\nPERDISTE\n");
            system("pause");
            system("cls");
            titulo();
        }
    }

    if(n == 2){

        if((sumaUsuario == dado1) || (sumaUsuario == dado2)){
            apuesta = (apuesta * 1) + apuesta;
            printf("GANASTE!!!\n");
            printf("\nHas ganado $ %d\n",apuesta);
            system("pause");
            system("cls");
            titulo();
        }else{
            printf("\nPERDISTE\n");
            system("pause");
            system("cls");
            titulo();
        }
    }
}
