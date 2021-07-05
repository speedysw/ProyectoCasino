#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashmap.h"
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

typedef struct{
    char *numero;
    unsigned long saldo;
    unsigned long ganancias;
    unsigned long perdidas;
}credito;

typedef struct{
    char* nombre;
    char* apellido;
    credito* tarjeta;
    char* id;
    char* password;
}usuario;

typedef struct{
    char* nombre;
    float multiplicador;
    char* pais;
    int ranking;
    int clave;
}deportes;

usuario *createLogin(){
    usuario *aux = (usuario *) malloc(sizeof(usuario)*100);
    aux->nombre = (char *) malloc(sizeof(char) * 20);
    aux->apellido = (char *) malloc(sizeof(char) * 20);
    aux->id = (char *) malloc(sizeof(char) * 20);
    aux->password = (char *) malloc(sizeof(char) * 20);
    aux->tarjeta = (credito *) malloc(sizeof(credito)*100);
    aux->tarjeta->numero = (char *) malloc(sizeof(char) * 20);
    return aux;
}

deportes *createDeportes(){
    deportes *aux = (deportes *) malloc(sizeof(deportes)*40);
    aux->nombre = (char *) malloc(sizeof(char) * 25);
    aux->pais = (char *) malloc(sizeof(char) * 15);
    return aux;
}

void importarATP(HashMap *);
void importarFormula(HashMap *);
void importarNBA(HashMap *);
void importarFutbol(HashMap *);
const char *get_csv_field (char *, int );
void apuestasTennis(usuario *) ;
void apuestasFormula1(usuario *);
void apuestasNBA(usuario *);
void apuestasFutbol(usuario *);
void encuentrosATP(HashMap *, usuario *);
void encuentrosF1(HashMap *, usuario *);
void encuentrosNBA(HashMap *, usuario *);
void encuentrosFutbol(HashMap *, usuario *);
void escoger(deportes *, deportes *, usuario *, deportes *);
void escogerApuesta(usuario*, deportes *, deportes *, deportes *);

int main(){
    usuario* prueba = createLogin(prueba);
    prueba->nombre = "Cesar";
    prueba->apellido = "Maureira";
    prueba->id = "SpeedySW";
    prueba->password = "hola123";
    prueba->tarjeta->numero = "1234 5343 5432 1234";
    prueba->tarjeta->saldo = 1000000;
    int a = 1;
    while(a!= 5){
        system("color");
        int pos,end,flag1=0,terminar_programa=0;
        char keyMenu;

        do{
        pos = 0;
        end = 0;
            gotoxy(1,1);printf("BIENVENIDO AL CASINO DE APUESTAS");
            gotoxy(1,2);printf(ROJO_F "- Apuestas de futbol" RESET_COLOR);
            gotoxy(1,3);printf("- Apuestas de la NBA");
            gotoxy(1,4);printf("- Apuestas de tenis");
            gotoxy(1,5);printf("- Apuestas de la formula 1");
            gotoxy(1,6);printf("- Atras");
            do{
                keyMenu = getch();
                switch(keyMenu){
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
                            gotoxy(1,1);printf("BIENVENIDO AL CASINO DE APUESTAS");
                            gotoxy(1,2);printf(ROJO_F "- Apuestas de futbol" RESET_COLOR);
                            gotoxy(1,3);printf("- Apuestas de la NBA");
                            gotoxy(1,4);printf("- Apuestas de tenis");
                            gotoxy(1,5);printf("- Apuestas de la formula 1");
                            gotoxy(1,6);printf("- Atras");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(1,1);printf("BIENVENIDO AL CASINO DE APUESTAS");
                            gotoxy(1,2);printf("- Apuestas de futbol");
                            gotoxy(1,3);printf(ROJO_F "- Apuestas de la NBA" RESET_COLOR);
                            gotoxy(1,4);printf("- Apuestas de tenis");
                            gotoxy(1,5);printf("- Apuestas de la formula 1");
                            gotoxy(1,6);printf("- Atras");
                            flag1=1;
                            break;
                    case 2:
                            gotoxy(1,1);printf("BIENVENIDO AL CASINO DE APUESTAS");
                            gotoxy(1,2);printf("- Apuestas de futbol");
                            gotoxy(1,3);printf("- Apuestas de la NBA");
                            gotoxy(1,4);printf(ROJO_F "- Apuestas de tenis" RESET_COLOR);
                            gotoxy(1,5);printf("- Apuestas de la formula 1");
                            gotoxy(1,6);printf("- Atras");
                            flag1=2;
                            break;
                    case 3:
                            gotoxy(1,1);printf("BIENVENIDO AL CASINO DE APUESTAS");
                            gotoxy(1,2);printf("- Apuestas de futbol");
                            gotoxy(1,3);printf("- Apuestas de la NBA");
                            gotoxy(1,4);printf("- Apuestas de tenis");
                            gotoxy(1,5);printf(ROJO_F "- Apuestas de la formula 1" RESET_COLOR);
                            gotoxy(1,6);printf("- Atras");
                            flag1=3;
                            break;
                    case 4:
                            gotoxy(1,1);printf("BIENVENIDO AL CASINO DE APUESTAS");
                            gotoxy(1,2);printf("- Apuestas de futbol");
                            gotoxy(1,3);printf("- Apuestas de la NBA");
                            gotoxy(1,4);printf("- Apuestas de tenis");
                            gotoxy(1,5);printf("- Apuestas de la formula 1");
                            gotoxy(1,6);printf(ROJO_F "- Atras" RESET_COLOR);
                            flag1=4;
                            break;
                }
            }while(end != 1);

            switch(flag1)
            {
                case 0: apuestasFutbol(prueba); terminar_programa=1; break;
                case 1: apuestasNBA(prueba); terminar_programa=1; break;
                case 2: apuestasTennis(prueba); terminar_programa=1; break;
                case 3: apuestasFormula1(prueba); terminar_programa=1; break;
                case 4: terminar_programa=1; break;
            }
        }while(terminar_programa != 1);
        return 0;
    }

}

void apuestasTennis(usuario * prueba){
    int aux = 10 + 10 * 0.3;
    HashMap *mapDeportes = createMap(aux);
    importarATP(mapDeportes);
    deportes *d = firstMap(mapDeportes);
    while(d != NULL){
        printf("| %20s | %15s | %16.2f |\n", d->nombre, d->pais, d->multiplicador);
    d = nextMap(mapDeportes);
    }
    encuentrosATP(mapDeportes, prueba);
}

void gotoxy(int x , int y){
HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);
}

void encuentrosATP(HashMap* mapDeportes, usuario * prueba){
    system("cls");
    int sorteo,sorteo1;
    int cont = 0;
    int aux = 10;
    srand(time(NULL));
    while(cont < 5){
        system("cls");
        sorteo = rand () % aux + 1; // 8
        sorteo1 = rand () % aux + 1; // 1
        if(sorteo == sorteo1){
                sorteo = rand () % aux + 1; // 8
                sorteo1 = rand () % aux + 1; // 1
        }
        while(searchMap(mapDeportes,&sorteo) == NULL){
                sorteo = rand () % aux + 1;
        }
        while(searchMap(mapDeportes,&sorteo1) == NULL){
                sorteo1 = rand() % aux + 1;
        }
        if(sorteo != sorteo1){
            int respuesta;
            deportes *d = searchMap(mapDeportes, &sorteo); // le da los datos del 1
            deportes *x = searchMap(mapDeportes, &sorteo1); // le da los datos del 8
            eraseMap(mapDeportes, &sorteo1);
            eraseMap(mapDeportes, &sorteo);
            insertMap(mapDeportes, &d->nombre, &d);
            insertMap(mapDeportes, &x->nombre, &x);
            printf("\n");
            printf("ENCUENTRO %i - TORNEO ATP \n", cont+1);
            printf("\n");
            printf("%s v/s %s\n", d->nombre, x->nombre);
            printf("-------------------------------------------------\n");
            printf("DATOS DE LOS TENISTAS\n");
            printf("-------------------------------------------------\n");
            printf("TENISTA: %s\n",d->nombre);
            printf("RANKING ATP: %d\n",d->ranking);
            printf("NACIONALIDAD: %s\n",d->pais);
            printf("Multiplica la apuesta x%.2f\n",d->multiplicador);
            printf("-------------------------------------------------\n");
            printf("TENISTA: %s\n",x->nombre);
            printf("RANKING ATP: %d\n",x->ranking);
            printf("NACIONALIDAD: %s\n",x->pais);
            printf("Multiplica la apuesta x%.2f\n",x->multiplicador);
            printf("-------------------------------------------------\n");
            system("color");
            int pos,end,flag1=0,terminar_programa=0;
            char keyMenu;

            do{
            pos = 0;
            end = 0;
                gotoxy(1,18);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                gotoxy(1,19);printf(ROJO_F "- Apostar" RESET_COLOR);
                gotoxy(1,20);printf("- Pasar al siguiente encuentro");
                gotoxy(1,21);printf("- Terminar ronda de apuestas");
                do{
                    keyMenu = getch();
                    switch(keyMenu){
                        case 72: if (pos == 0)
                                pos = 2;
                                else pos--;
                                break;
                        case 80: if (pos == 2) pos =0;
                                else pos++;
                                break;
                        case 13: end = 1;
                    }
                    switch(pos){
                        case 0:
                                gotoxy(1,18);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,19);printf(ROJO_F "- Apostar" RESET_COLOR);
                                gotoxy(1,20);printf("- Pasar al siguiente encuentro");
                                gotoxy(1,21);printf("- Terminar ronda de apuestas");
                                flag1=0;
                                break;

                        case 1:
                                gotoxy(1,18);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,19);printf("- Apostar");
                                gotoxy(1,20);printf(ROJO_F "- Pasar al siguiente encuentro" RESET_COLOR);
                                gotoxy(1,21);printf("- Terminar ronda de apuestas");
                                flag1=1;
                                break;
                        case 2:
                                gotoxy(1,18);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,19);printf("- Apostar");
                                gotoxy(1,20);printf("- Pasar al siguiente encuentro");
                                gotoxy(1,21);printf(ROJO_F "- Terminar ronda de apuestas" RESET_COLOR);
                                flag1=2;
                                break;
                    }
                }while(end != 1);

                switch(flag1)
                {
                    case 0: respuesta = 1; terminar_programa=1; break;
                    case 1: respuesta = 2; terminar_programa=1; break;
                    case 2: respuesta = 3; terminar_programa=1; break;
                }
            }while(terminar_programa != 1);

            if(respuesta == 1){
                deportes* escogido = createDeportes();
                flag1=0,terminar_programa=0;

                do{
                pos = 0;
                end = 0;
                    gotoxy(51,1);printf("SELECCIONE A UN JUGADOR");
                    gotoxy(51,2);printf(ROJO_F "%s" RESET_COLOR, d->nombre);
                    gotoxy(51,3);printf("%s", x->nombre);
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
                                    gotoxy(51,1);printf("SELECCIONE A UN JUGADOR");
                                    gotoxy(51,2);printf(ROJO_F "%s" RESET_COLOR, d->nombre);
                                    gotoxy(51,3);printf("%s", x->nombre);
                                    flag1=0;
                                    break;

                            case 1:
                                    gotoxy(51,1);printf("SELECCIONE A UN JUGADOR");
                                    gotoxy(51,2);printf("%s", d->nombre);
                                    gotoxy(51,3);printf(ROJO_F "%s" RESET_COLOR, x->nombre);
                                    flag1=1;
                                    break;
                        }
                    }while(end != 1);

                    switch(flag1)
                    {
                        case 0: escogido->nombre = d->nombre; terminar_programa=1; break;
                        case 1: escogido->nombre = x->nombre; terminar_programa=1; break;
                    }
                }while(terminar_programa != 1);
                escogerApuesta(prueba,d,x,escogido);
            }
            if(respuesta == 3) break;
            cont++;
        }
    }
    system("cls");
    printf("Este es tu saldo actual: %lu CLP\n", prueba->tarjeta->saldo);
    printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
    printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);
    int respuesta;
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,4);printf("OPCIONES");
        gotoxy(1,5);printf(ROJO_F " - Volver al menu de la casa de apuestas" NEGRO_F);
        gotoxy(1,6);printf(" - Generar nueva ronda de apuestas");
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
                        gotoxy(1,4);printf("OPCIONES");
                        gotoxy(1,5);printf(ROJO_F " - Volver al menu de la casa de apuestas" NEGRO_F);
                        gotoxy(1,6);printf(" - Generar nueva ronda de apuestas");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,4);printf("OPCIONES");
                        gotoxy(1,5);printf(" - Volver al menu de la casa de apuestas");
                        gotoxy(1,6);printf(ROJO_F " - Generar nueva ronda de apuestas" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: respuesta = 1; terminar_programa=1; break;
            case 1: respuesta= 2; terminar_programa=1; break;
        }

    }while(terminar_programa != 1);
    system("cls");
    if(respuesta == 1) main();
    if(respuesta == 2){
        free(mapDeportes);
        apuestasTennis(prueba);
    }
}

void importarATP(HashMap *mapDeportes){
    FILE* archivo;
    archivo = fopen("ATP.csv","r");
    if(archivo == NULL){
        printf("El archivo no se abrio correctamente\n");
        return exit(1);
    }
    int i = 0 ;
    char line[40];
    deportes *datos = createDeportes();
    while(fgets(line,40,archivo) != NULL){
        datos[i].nombre = (char *)get_csv_field(line,0);
        datos[i].ranking = atoi(get_csv_field(line,1));
        datos[i].pais = (char *)get_csv_field(line,2);
        datos[i].multiplicador = atof(get_csv_field(line,3));
        datos[i].clave = i + 1;
        i++;
    }
    int cont = i;
    for(i=0 ; i < cont ; i++){
        insertMap(mapDeportes,&datos[i].clave,&datos[i]);
    }
}

const char *get_csv_field (char * tmp, int k){ //Función para leer distintos datos del archivo.
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){ //mientras el tmp [siguiente del indice] sea distinto a null
        if(tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }
        if(tmp[i]== ','){ // si encuentra coma, retorna
            if(k==j) {
               ret[i-ini_i] = 0; //
               return ret;
            }
            j++; ini_i = i+1;
        }
        if(tmp[i]== '\0'){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }
        i++;
    }
    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }
    return NULL;
}

void apuestasFormula1(usuario * prueba){
    int aux = 12 + 10 * 0.3;
    HashMap *mapDeportes = createMap(aux);
    importarFormula(mapDeportes);
    deportes *d = firstMap(mapDeportes);
    while(d != NULL){
        printf("| %20s | %15s | %16.2f |\n", d->nombre, d->pais, d->multiplicador);
    d = nextMap(mapDeportes);
    }
    encuentrosF1(mapDeportes, prueba);
}

void encuentrosF1(HashMap * mapDeportes, usuario * prueba){
    system("cls");
    int piloto;
    unsigned long apuesta;
    deportes *d = firstMap(mapDeportes);
    printf("|                               FORMULA 1: GRAN PREMIO DE FRANCIA                             |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("|                     |         PILOTO       |    ESCUADRA     |   DORSAL  |   MULTIPLICADOR  |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    while(d != NULL){
        printf("| Clasificacion: %4d | %20s | %15s | %9i | %16.2f |\n",d->clave, d->nombre, d->pais, d->ranking, d->multiplicador);
        d = nextMap(mapDeportes);
    }
    int respuesta;
    printf("-----------------------------------------------------------------------------------------------");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
        pos = 0;
        end = 0;
        gotoxy(1,17);printf("DESEA APOSTAR POR ESTA CARRERA?");
        gotoxy(1,18);printf(ROJO_F "- Apostar" RESET_COLOR);
        gotoxy(1,19);printf("- No apostar");
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
                            gotoxy(1,17);printf("DESEA APOSTAR POR ESTA CARRERA?");
                            gotoxy(1,18);printf(ROJO_F "- Apostar" RESET_COLOR);
                            gotoxy(1,19);printf("- No apostar");
                            flag1=0;
                            break;
                    case 1:
                            gotoxy(1,17);printf("DESEA APOSTAR POR ESTA CARRERA?");
                            gotoxy(1,18);printf("- Apostar");
                            gotoxy(1,19);printf(ROJO_F "- No apostar" RESET_COLOR);
                            flag1=1;
                            break;
                }
            }while(end != 1);

            switch(flag1)
            {
                case 0: respuesta = 1; terminar_programa=1; break;
                case 1: respuesta = 2; terminar_programa=1; break;
            }
    }while(terminar_programa != 1);

    if(respuesta == 1){
        flag1=0,terminar_programa=0;

        do{
            pos = 0;
            end = 0;
            gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
            gotoxy(96,2);printf(ROJO_F "Max Verstappen" RESET_COLOR);
            gotoxy(96,3);printf("Lewis Hamilton");
            gotoxy(96,4);printf("Sergio Perez");
            gotoxy(96,5);printf("Lando Norris");
            gotoxy(96,6);printf("Valtteri Bottas");
            gotoxy(96,7);printf("Charles Leclerc");
            gotoxy(96,8);printf("Carlos Sainz");
            gotoxy(96,9);printf("Pierre Gasly");
            gotoxy(96,10);printf("Daniel Ricciardo");
            gotoxy(96,11);printf("Sebastian Vettel");
            gotoxy(96,12);printf("Fernando Alonso");
            do{
                    keyMenu = getch();
                    switch(keyMenu){
                        case 72: if (pos == 0)
                                    pos = 10;
                                 else pos--;
                                 break;
                        case 80: if (pos == 10) pos =0;
                                 else pos++;
                                 break;
                        case 13: end = 1;
                    }
                    switch(pos){
                        case 0:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf(ROJO_F "Max Verstappen" RESET_COLOR);
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=0;
                                break;
                        case 1:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf(ROJO_F "Lewis Hamilton" RESET_COLOR);
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=1;
                                break;
                        case 2:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf(ROJO_F "Sergio Perez" RESET_COLOR);
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=2;
                                break;
                        case 3:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf(ROJO_F "Lando Norris" RESET_COLOR);
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=3;
                                break;
                        case 4:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf(ROJO_F "Valtteri Bottas" RESET_COLOR);
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=4;
                                break;
                        case 5:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf(ROJO_F "Charles Leclerc" RESET_COLOR);
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=5;
                                break;
                        case 6:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf(ROJO_F "Carlos Sainz" RESET_COLOR);
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=6;
                                break;
                        case 7:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf(ROJO_F "Pierre Gasly" RESET_COLOR);
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=7;
                                break;
                        case 8:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf(ROJO_F "Daniel Ricciardo" RESET_COLOR);
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=8;
                                break;
                        case 9:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf(ROJO_F "Sebastian Vettel" RESET_COLOR);
                                gotoxy(96,12);printf("Fernando Alonso");
                                flag1=9;
                                break;
                        case 10:
                                gotoxy(96,1);printf("SELECCIONE A UN PILOTO");
                                gotoxy(96,2);printf("Max Verstappen");
                                gotoxy(96,3);printf("Lewis Hamilton");
                                gotoxy(96,4);printf("Sergio Perez");
                                gotoxy(96,5);printf("Lando Norris");
                                gotoxy(96,6);printf("Valtteri Bottas");
                                gotoxy(96,7);printf("Charles Leclerc");
                                gotoxy(96,8);printf("Carlos Sainz");
                                gotoxy(96,9);printf("Pierre Gasly");
                                gotoxy(96,10);printf("Daniel Ricciardo");
                                gotoxy(96,11);printf("Sebastian Vettel");
                                gotoxy(96,12);printf(ROJO_F "Fernando Alonso" RESET_COLOR);
                                flag1=10;
                                break;
                        }
                    }while(end != 1);

                    switch(flag1)
                    {
                        case 0: piloto = 1; terminar_programa=1; break;
                        case 1: piloto = 2; terminar_programa=1; break;
                        case 2: piloto = 3; terminar_programa=1; break;
                        case 3: piloto = 4; terminar_programa=1; break;
                        case 4: piloto = 5; terminar_programa=1; break;
                        case 5: piloto = 6; terminar_programa=1; break;
                        case 6: piloto = 7; terminar_programa=1; break;
                        case 7: piloto = 8; terminar_programa=1; break;
                        case 8: piloto = 9; terminar_programa=1; break;
                        case 9: piloto = 10; terminar_programa=1; break;
                        case 10: piloto = 11; terminar_programa=1; break;
                    }
        }while(terminar_programa != 1);

        system("cls");
        deportes* aux = searchMap(mapDeportes, &piloto);
        printf("PILOTO ESCOGIDO: %s\n", aux->nombre);


        int pos,end,flag1=0,terminar_programa=0;
        char key;

        do{
        pos = 0;
        end = 0;
            gotoxy(1,2);printf("SELECCIONE SU APUESTA");
            gotoxy(1,3);printf(ROJO_F "- $1000" NEGRO_F);
            gotoxy(1,4);printf("- $2000");
            gotoxy(1,5);printf("- $3500");
            gotoxy(1,6);printf("- $5000");
            gotoxy(1,7);printf("- $7500");
            gotoxy(1,8);printf("- $10000");
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
                            gotoxy(1,2);printf("SELECCIONE SU APUESTA");
                            gotoxy(1,3);printf(ROJO_F "- $1000" NEGRO_F);
                            gotoxy(1,4);printf("- $2000");
                            gotoxy(1,5);printf("- $3500");
                            gotoxy(1,6);printf("- $5000");
                            gotoxy(1,7);printf("- $7500");
                            gotoxy(1,8);printf("- $10000");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(1,2);printf("SELECCIONE SU APUESTA");
                            gotoxy(1,3);printf("- $1000");
                            gotoxy(1,4);printf(ROJO_F "- $2000" NEGRO_F);
                            gotoxy(1,5);printf("- $3500");
                            gotoxy(1,6);printf("- $5000");
                            gotoxy(1,7);printf("- $7500");
                            gotoxy(1,8);printf("- $10000");
                            flag1=1;
                            break;
                    case 2:
                            gotoxy(1,2);printf("SELECCIONE SU APUESTA");
                            gotoxy(1,3);printf("- $1000");
                            gotoxy(1,4);printf("- $2000");
                            gotoxy(1,5);printf(ROJO_F "- $3500" NEGRO_F);
                            gotoxy(1,6);printf("- $5000");
                            gotoxy(1,7);printf("- $7500");
                            gotoxy(1,8);printf("- $10000");
                            flag1=2;
                            break;
                    case 3:
                            gotoxy(1,2);printf("SELECCIONE SU APUESTA");
                            gotoxy(1,3);printf("- $1000");
                            gotoxy(1,4);printf("- $2000");
                            gotoxy(1,5);printf("- $3500");
                            gotoxy(1,6);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(1,7);printf("- $7500");
                            gotoxy(1,8);printf("- $10000");
                            flag1=3;
                            break;
                    case 4:
                            gotoxy(1,2);printf("SELECCIONE SU APUESTA");
                            gotoxy(1,3);printf("- $1000");
                            gotoxy(1,4);printf("- $2000");
                            gotoxy(1,5);printf("- $3500");
                            gotoxy(1,6);printf("- $5000");
                            gotoxy(1,7);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(1,8);printf("- $10000");
                            flag1=4;
                            break;
                    case 5:
                            gotoxy(1,2);printf("SELECCIONE SU APUESTA");
                            gotoxy(1,3);printf("- $1000");
                            gotoxy(1,4);printf("- $2000");
                            gotoxy(1,5);printf("- $3500");
                            gotoxy(1,6);printf("- $5000");
                            gotoxy(1,7);printf("- $7500");
                            gotoxy(1,8);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=5;
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
        printf("Realizaste una apuesta de %lu CLP por %s \n", apuesta, aux->nombre);
        prueba->tarjeta->saldo -= apuesta;
        printf(" -------------------------------------------------------------------------------------------\n");

        srand(time(NULL));
        int cont=0;
        printf("|                         RESULTADO FORMULA 1: GRAN PREMIO DE FRANCIA                       |\n");
        printf(" -------------------------------------------------------------------------------------------\n");
        printf("|   CLASIFICACION   |         PILOTO       |    ESCUADRA     |   DORSAL  |   MULTIPLICADOR  |\n");
        printf(" -------------------------------------------------------------------------------------------\n");

        int i = 0;
        HashMap* Ganadores = createMap(4);
        while(cont < 11){
            int posicion = rand() % 11 + 1;
            //printf("esta es la posicon %i\n", posicion);

            while(searchMap(mapDeportes,&posicion) == NULL){
                    posicion = rand () % 11 + 1;
            }

            deportes *ubicacion = searchMap(mapDeportes, &posicion);
            if(ubicacion != NULL){
                posicion = i + 1;
                printf("| Posicion: %7d | %20s | %15s | %9i | %16.2f |\n",posicion, ubicacion->nombre, ubicacion->pais, ubicacion->ranking, ubicacion->multiplicador);
                i++;
            }

            if(posicion == 1){
                insertMap(Ganadores, &posicion, ubicacion);
            }

            eraseMap(mapDeportes, &ubicacion->clave);
            cont++;
        }
        printf(" -------------------------------------------------------------------------------------------\n");
        printf("                                RESULTADOS DE LA APUESTA                                    \n");
        deportes* ganador = firstMap(Ganadores);

        if(strcmp(ganador->nombre, aux->nombre) == 0){
            printf("Ganador de la carrera: %s\n", ganador->nombre);
            printf("Ganaste la apuesta\n");
            unsigned long resultante = (ganador->multiplicador * apuesta);
            prueba->tarjeta->ganancias += resultante;
            resultante = prueba->tarjeta->saldo + resultante;
            prueba->tarjeta->saldo += resultante;
            printf("Ganaste %lu CLP\n", prueba->tarjeta->ganancias);
        }

        if(strcmp(ganador->nombre, aux->nombre) != 0){
            printf("Ganador de la carrera: %s\n", ganador->nombre);
            printf("Perdiste la apuesta\n");
            prueba->tarjeta->perdidas += apuesta;
        }

        printf("Este es tu saldo actual: %llu CLP\n", prueba->tarjeta->saldo);
        printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
        printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);
    }

    flag1=0,terminar_programa=0;

    do{
        pos = 0;
        end = 0;
        gotoxy(1,25);printf("OPCIONES");
        gotoxy(1,26);printf(ROJO_F "- Volver al menu de apuestas" RESET_COLOR);
        gotoxy(1,27);printf("- Generar nueva carrera");
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
                            gotoxy(1,25);printf("OPCIONES");
                            gotoxy(1,26);printf(ROJO_F "- Volver al menu de apuestas" RESET_COLOR);
                            gotoxy(1,27);printf("- Generar nueva carrera");
                            flag1=0;
                            break;
                    case 1:
                            gotoxy(1,25);printf("OPCIONES");
                            gotoxy(1,26);printf("- Volver al menu de apuestas");
                            gotoxy(1,27);printf(ROJO_F "- Generar nueva carrera" RESET_COLOR);
                            flag1=1;
                            break;
                }
                }while(end != 1);

            switch(flag1){
                    case 0: respuesta = 1; terminar_programa=1; break;
                    case 1: respuesta = 2; terminar_programa=1; break;
            }
    }while(terminar_programa != 1);

    if(respuesta == 1){
            system("cls");
            main();
    }
    if(respuesta == 2){
        system("cls");
        free(mapDeportes);
        apuestasFormula1(prueba);
    }

}

void importarFormula(HashMap *mapDeportes){
    FILE* archivo;
    archivo = fopen("Formula1.csv","r");
    if(archivo == NULL){
        printf("El archivo no se abrio correctamente\n");
        return 1;
    }
    int i = 0 ;
    char line[50];
    deportes *datos = createDeportes();
    while(fgets(line,50,archivo) != NULL){
        datos[i].nombre = (char *)get_csv_field(line,0);
        datos[i].ranking = atoi(get_csv_field(line,1));
        datos[i].pais = (char *)get_csv_field(line,2);
        datos[i].multiplicador = atof(get_csv_field(line,3));
        datos[i].clave = i + 1;
        i++;
    }
    int cont = i;
    for(i=0 ; i < cont ; i++){
        insertMap(mapDeportes,&datos[i].clave,&datos[i]);
    }
}

void apuestasNBA(usuario * prueba){
    int aux = 12 + 10 * 0.3;
    HashMap *mapDeportes = createMap(aux);
    importarNBA(mapDeportes);
    deportes *d = firstMap(mapDeportes);
    while(d != NULL){
        printf("| %20s | %15s | %16.2f |\n", d->nombre, d->pais, d->multiplicador);
    d = nextMap(mapDeportes);
    }
    encuentrosNBA(mapDeportes, prueba);
}

void encuentrosNBA(HashMap *mapDeportes, usuario * prueba){
    system("cls");
    int sorteo,sorteo1;
    int cont = 0;
    int aux=12;
    deportes* escogido = createDeportes();
    srand(time(NULL));
    while(cont < 6){
        system("cls");

        sorteo = rand () % aux + 1; // 8
        sorteo1 = rand () % aux + 1; // 1


        if(sorteo == sorteo1){
                sorteo = rand () % aux + 1; // 8
                sorteo1 = rand () % aux + 1; // 1
        }

        while(searchMap(mapDeportes,&sorteo) == NULL){
                sorteo = rand () % aux + 1;
        }

        while(searchMap(mapDeportes,&sorteo1) == NULL){
                sorteo1 = rand() % aux + 1;
        }

        if(sorteo != sorteo1){
            int respuesta= 0;
            deportes *d = searchMap(mapDeportes, &sorteo); // le da los datos del 1
            deportes *x = searchMap(mapDeportes, &sorteo1); // le da los datos del 8
            eraseMap(mapDeportes, &sorteo1);
            eraseMap(mapDeportes, &sorteo);
            insertMap(mapDeportes, &d->nombre, &d);
            insertMap(mapDeportes, &x->nombre, &x);
            if((strcmp(d->pais,"Conferencia Este") == 0) && (strcmp(x->pais,"Conferencia Este") == 0)) printf("ENCUENTRO %i - CONFERENCIA ESTE\n",cont + 1);
            if((strcmp(d->pais,"Conferencia Oeste") == 0) && (strcmp(x->pais,"Conferencia Oeste") == 0)) printf("ENCUENTRO %i - CONFERENCIA OESTE\n",cont + 1);
            if((strcmp(d->pais,"Conferencia Oeste") != 0) && (strcmp(x->pais,"Conferencia Oeste") == 0)) printf("ENCUENTRO %i - NBA\n",cont + 1);
            if((strcmp(d->pais,"Conferencia Este") != 0) && (strcmp(x->pais,"Conferencia Este") == 0)) printf("ENCUENTRO %i - NBA\n",cont + 1);
            printf("\n");
            printf("%s v/s %s\n", d->nombre, x->nombre);
            printf("-------------------------------------------------\n");
            printf("DATOS DE LOS EQUIPOS\n");
            printf("-------------------------------------------------\n");
            printf("EQUIPO: %s\n",d->nombre);
            printf("Clasificacion %i en la %s\n",d->ranking,d->pais);
            printf("Multiplica la apuesta x%.2f\n",d->multiplicador);
            printf("-------------------------------------------------\n");
            printf("EQUIPO: %s\n",x->nombre);
            printf("Clasificacion %i en la %s\n",x->ranking,x->pais);
            printf("Multiplica la apuesta x%.2f\n",x->multiplicador);
            printf("-------------------------------------------------\n");
            system("color");
            int pos,end,flag1=0,terminar_programa=0;
            char keyMenu;

            do{
            pos = 0;
            end = 0;
                gotoxy(1,15);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                gotoxy(1,16);printf(ROJO_F "- Apostar" RESET_COLOR);
                gotoxy(1,17);printf("- Pasar al siguiente encuentro");
                gotoxy(1,18);printf("- Terminar ronda de apuestas");
                do{
                    keyMenu = getch();
                    switch(keyMenu){
                        case 72: if (pos == 0)
                                pos = 2;
                                else pos--;
                                break;
                        case 80: if (pos == 2) pos =0;
                                else pos++;
                                break;
                        case 13: end = 1;
                    }
                    switch(pos){
                        case 0:
                                gotoxy(1,15);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,16);printf(ROJO_F "- Apostar" RESET_COLOR);
                                gotoxy(1,17);printf("- Pasar al siguiente encuentro");
                                gotoxy(1,18);printf("- Terminar ronda de apuestas");
                                flag1=0;
                                break;

                        case 1:
                                gotoxy(1,15);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,16);printf("- Apostar");
                                gotoxy(1,17);printf(ROJO_F "- Pasar al siguiente encuentro" RESET_COLOR);
                                gotoxy(1,18);printf("- Terminar ronda de apuestas");
                                flag1=1;
                                break;
                        case 2:
                                gotoxy(1,15);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,16);printf("- Apostar");
                                gotoxy(1,17);printf("- Pasar al siguiente encuentro");
                                gotoxy(1,18);printf(ROJO_F "- Terminar ronda de apuestas" RESET_COLOR);
                                flag1=2;
                                break;
                    }
                }while(end != 1);

                switch(flag1)
                {
                    case 0: respuesta = 1; terminar_programa=1; break;
                    case 1: respuesta = 2; terminar_programa=1; break;
                    case 2: respuesta = 3; terminar_programa=1; break;
                }
            }while(terminar_programa != 1);

            if(respuesta == 1){
                deportes* apostado = createDeportes();
                flag1=0,terminar_programa=0;

                do{
                pos = 0;
                end = 0;
                    gotoxy(51,1);printf("SELECCIONE A UN EQUIPO");
                    gotoxy(51,2);printf(ROJO_F "%s" RESET_COLOR, d->nombre);
                    gotoxy(51,3);printf("%s", x->nombre);
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
                                    gotoxy(51,1);printf("SELECCIONE A UN EQUIPO");
                                    gotoxy(51,2);printf(ROJO_F "%s" RESET_COLOR, d->nombre);
                                    gotoxy(51,3);printf("%s", x->nombre);
                                    flag1=0;
                                    break;

                            case 1:
                                    gotoxy(51,1);printf("SELECCIONE A UN EQUIPO");
                                    gotoxy(51,2);printf("%s", d->nombre);
                                    gotoxy(51,3);printf(ROJO_F "%s" RESET_COLOR, x->nombre);
                                    flag1=1;
                                    break;
                        }
                    }while(end != 1);

                    switch(flag1)
                    {
                        case 0: apostado->nombre = d->nombre; terminar_programa=1; break;
                        case 1: apostado->nombre = x->nombre; terminar_programa=1; break;
                    }
                }while(terminar_programa != 1);
                escogerApuesta(prueba, d, x, apostado);
            }

            if(respuesta == 3) break;
            cont++;
        }
    }
    system("cls");
    printf("Este es tu saldo actual: %lu CLP\n", prueba->tarjeta->saldo);
    printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
    printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);
    int respuesta;
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,4);printf("OPCIONES");
        gotoxy(1,5);printf(ROJO_F " - Volver al menu de la casa de apuestas" NEGRO_F);
        gotoxy(1,6);printf(" - Generar nueva ronda de apuestas");
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
                        gotoxy(1,4);printf("OPCIONES");
                        gotoxy(1,5);printf(ROJO_F " - Volver al menu de la casa de apuestas" NEGRO_F);
                        gotoxy(1,6);printf(" - Generar nueva ronda de apuestas");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,4);printf("OPCIONES");
                        gotoxy(1,5);printf(" - Volver al menu de la casa de apuestas");
                        gotoxy(1,6);printf(ROJO_F " - Generar nueva ronda de apuestas" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: respuesta = 1; terminar_programa=1; break;
            case 1: respuesta = 2; terminar_programa=1; break;
        }

    }while(terminar_programa != 1);
    system("cls");
    if(respuesta == 1) main();
    if(respuesta == 2){
        free(mapDeportes);
        apuestasNBA(prueba);
    }
}

void escogerApuesta(usuario* prueba, deportes* equipo1, deportes* equipo2, deportes* apostado){
    int sorteo;
    unsigned long apuesta;

    if(strcmp(apostado->nombre,equipo1->nombre) == 0){
        int pos,end,flag1=0,terminar_programa=0;
        char key;

        do{
        pos = 0;
        end = 0;
            gotoxy(51,5);printf("Seleccione su monto a apostar");
            gotoxy(51,6);printf(ROJO_F "- $1000" NEGRO_F);
            gotoxy(51,7);printf("- $2000");
            gotoxy(51,8);printf("- $3500");
            gotoxy(51,9);printf("- $5000");
            gotoxy(51,10);printf("- $7500");
            gotoxy(51,11);printf("- $10000");
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
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf(ROJO_F "- $1000" NEGRO_F);
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf(ROJO_F "- $2000" NEGRO_F);
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=1;
                            break;
                    case 2:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf(ROJO_F "- $3500" NEGRO_F);
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=2;
                            break;
                    case 3:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=3;
                            break;
                    case 4:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(51,11);printf("- $10000");
                            flag1=4;
                            break;
                    case 5:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=5;
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

        prueba->tarjeta->saldo = prueba->tarjeta->saldo - apuesta;
        system("cls");
        printf("Realizaste una apuesta de %lu CLP por %s \n", apuesta, apostado->nombre);
        system("pause");
        system("cls");
        sorteo = rand() % 2 + 1;

        if(sorteo == 1){
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo1->nombre);
            printf("Ganaste la apuesta\n", apuesta * equipo1->multiplicador);
            prueba->tarjeta->ganancias += (apuesta * equipo1->multiplicador);
            prueba->tarjeta->saldo += (apuesta * equipo1->multiplicador);
            printf("Ganaste %lu CLP\n", prueba->tarjeta->ganancias);
            system("pause");
        }

        if(sorteo == 2){
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo2->nombre);
            printf("Perdiste la apuesta\n");
            prueba->tarjeta->perdidas += apuesta;
            system("pause");
        }
    }

    if(strcmp(apostado->nombre,equipo2->nombre) == 0){

        int pos,end,flag1=0,terminar_programa=0;
        char key;

        do{
        pos = 0;
        end = 0;
            gotoxy(51,5);printf("Seleccione su monto a apostar");
            gotoxy(51,6);printf(ROJO_F "- $1000" NEGRO_F);
            gotoxy(51,7);printf("- $2000");
            gotoxy(51,8);printf("- $3500");
            gotoxy(51,9);printf("- $5000");
            gotoxy(51,10);printf("- $7500");
            gotoxy(51,11);printf("- $10000");
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
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf(ROJO_F "- $1000" NEGRO_F);
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf(ROJO_F "- $2000" NEGRO_F);
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=1;
                            break;
                    case 2:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf(ROJO_F "- $3500" NEGRO_F);
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=2;
                            break;
                    case 3:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf("- $10000");
                            flag1=3;
                            break;
                    case 4:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(51,11);printf("- $10000");
                            flag1=4;
                            break;
                    case 5:
                            gotoxy(51,5);printf("Seleccione su monto a apostar");
                            gotoxy(51,6);printf("- $1000");
                            gotoxy(51,7);printf("- $2000");
                            gotoxy(51,8);printf("- $3500");
                            gotoxy(51,9);printf("- $5000");
                            gotoxy(51,10);printf("- $7500");
                            gotoxy(51,11);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=5;
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

        prueba->tarjeta->saldo = prueba->tarjeta->saldo - apuesta;
        system("cls");
        printf("Realizaste una apuesta de %lu CLP por %s \n", apuesta, apostado->nombre);
        system("pause");
        system("cls");
        sorteo = rand() % 2 + 1;
        if(sorteo == 1){
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo2->nombre);
            printf("Ganaste la apuesta\n", apuesta * equipo2->multiplicador);
            prueba->tarjeta->ganancias += (apuesta * equipo2->multiplicador);
            prueba->tarjeta->saldo += (apuesta * equipo2->multiplicador);
            printf("Ganaste %lu CLP\n", prueba->tarjeta->ganancias);
            system("pause");
        }

        if(sorteo == 2){
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo1->nombre);
            printf("Perdiste la apuesta\n");
            prueba->tarjeta->perdidas += apuesta;
            system("pause");
            system("cls");
        }
    }

    if(strcmp(apostado->nombre,equipo1->nombre) != 0){
        if(strcmp(apostado->nombre,equipo2->nombre) != 0){
            scanf("%[^\n]",apostado->nombre);
            fflush(stdin);
            escogerApuesta(prueba,equipo1,equipo2,apostado);
        }
    }

    if(strcmp(apostado->nombre,equipo2->nombre) != 0){
        if(strcmp(apostado->nombre,equipo1->nombre) != 0){
            scanf("%[^\n]",apostado->nombre);
            fflush(stdin);
            escogerApuesta(prueba,equipo1,equipo2,apostado);
        }
    }
}

void importarNBA(HashMap *mapDeportes){
    FILE* archivo;
    archivo = fopen("NBA.csv","r");
    if(archivo == NULL){
        printf("El archivo no se abrio correctamente\n");
        return 1;
    }
    int i = 0 ;
    char line[50];
    deportes *datos = createDeportes();
    while(fgets(line,50,archivo) != NULL){
        datos[i].nombre = (char *)get_csv_field(line,0);
        datos[i].ranking = atoi(get_csv_field(line,1));
        datos[i].pais = (char *)get_csv_field(line,2);
        datos[i].multiplicador = atof(get_csv_field(line,3));
        datos[i].clave = i+1;
        i++;
    }

    int cont = i;
    for(i=0 ; i < cont ; i++){
        insertMap(mapDeportes,&datos[i].clave,&datos[i]);
    }
}

void apuestasFutbol(usuario * prueba){
    int aux = 32 + 10 * 0.3;
    HashMap *mapDeportes = createMap(aux);
    importarFutbol(mapDeportes);
    deportes *d = firstMap(mapDeportes);
    encuentrosFutbol(mapDeportes, prueba);
}

void importarFutbol(HashMap * mapDeportes){
    FILE* archivo;
    archivo = fopen("Futbol.csv","r");
    if(archivo == NULL){
        printf("El archivo no se abrio correctamente\n");
        return 1;
    }
    int i = 0 ;
    char line[50];
    deportes *datos = createDeportes();
    while(fgets(line,50,archivo) != NULL){
        datos[i].nombre = (char *)get_csv_field(line,0);
        datos[i].pais = (char *)get_csv_field(line,1);
        datos[i].multiplicador = atof(get_csv_field(line,2));
        datos[i].clave = i+1;
        i++;
    }
    int cont = i;
    for(i=0 ; i < cont ; i++){
        insertMap(mapDeportes,&datos[i].clave,&datos[i]);
    }
}

void encuentrosFutbol(HashMap * mapDeportes, usuario * prueba){
    int sorteo,sorteo1;
    int cont = 0;
    int aux= 32;
    deportes* escogido = createDeportes();
    srand(time(NULL));
    while(cont < 16){
        system("cls");
        sorteo = rand () % aux + 1; // 8
        sorteo1 = rand () % aux + 1; // 1

        if(sorteo == sorteo1){
                sorteo = rand () % aux + 1;
                sorteo1 = rand () % aux + 1;
        }

        while(searchMap(mapDeportes,&sorteo) == NULL){
                sorteo = rand () % aux + 1;
        }

        while(searchMap(mapDeportes,&sorteo1) == NULL){
                sorteo1 = rand() % aux + 1;
        }

        if(sorteo != sorteo1){
            int respuesta= 0;
            deportes *d = searchMap(mapDeportes, &sorteo); // le da los datos del 1
            deportes *x = searchMap(mapDeportes, &sorteo1); // le da los datos del 8
            eraseMap(mapDeportes, &sorteo1);
            eraseMap(mapDeportes, &sorteo);
            insertMap(mapDeportes, &d->nombre, &d);
            insertMap(mapDeportes, &x->nombre, &x);
            printf("\n");
            printf("ENCUENTRO %i - TORNEO AUDI CUP \n", cont+1);
            printf("\n");
            printf("%s v/s %s\n", d->nombre, x->nombre);
            printf("-------------------------------------------------\n");
            printf("DATOS DE LOS EQUIPOS\n");
            printf("-------------------------------------------------\n");
            printf("EQUIPO: %s\n",d->nombre);
            printf("PAIS: %s\n",d->pais);
            printf("Multiplica la apuesta x%.2f\n",d->multiplicador);
            printf("-------------------------------------------------\n");
            printf("EQUIPO: %s\n",x->nombre);
            printf("PAIS: %s\n",x->pais);
            printf("Multiplica la apuesta x%.2f\n",x->multiplicador);
            printf("-------------------------------------------------\n");

            system("color");
            int pos,end,flag1=0,terminar_programa=0;
            char keyMenu;

            do{
            pos = 0;
            end = 0;
                gotoxy(1,16);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                gotoxy(1,17);printf(ROJO_F "- Apostar" RESET_COLOR);
                gotoxy(1,18);printf("- Pasar al siguiente encuentro");
                gotoxy(1,19);printf("- Terminar ronda de apuestas");
                do{
                    keyMenu = getch();
                    switch(keyMenu){
                        case 72: if (pos == 0)
                                pos = 2;
                                else pos--;
                                break;
                        case 80: if (pos == 2) pos =0;
                                else pos++;
                                break;
                        case 13: end = 1;
                    }
                    switch(pos){
                        case 0:
                                gotoxy(1,16);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,17);printf(ROJO_F "- Apostar" RESET_COLOR);
                                gotoxy(1,18);printf("- Pasar al siguiente encuentro");
                                gotoxy(1,19);printf("- Terminar ronda de apuestas");
                                flag1=0;
                                break;

                        case 1:
                                gotoxy(1,16);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,17);printf("- Apostar");
                                gotoxy(1,18);printf(ROJO_F "- Pasar al siguiente encuentro" RESET_COLOR);
                                gotoxy(1,19);printf("- Terminar ronda de apuestas");
                                flag1=1;
                                break;
                        case 2:
                                gotoxy(1,16);printf("DESEA APOSTAR POR ESTE ENCUENTRO?\n");
                                gotoxy(1,17);printf("- Apostar");
                                gotoxy(1,18);printf("- Pasar al siguiente encuentro");
                                gotoxy(1,19);printf(ROJO_F "- Terminar ronda de apuestas" RESET_COLOR);
                                flag1=2;
                                break;
                    }
                }while(end != 1);

                switch(flag1)
                {
                    case 0: respuesta = 1; terminar_programa=1; break;
                    case 1: respuesta = 2; terminar_programa=1; break;
                    case 2: respuesta = 3; terminar_programa=1; break;
                }
            }while(terminar_programa != 1);

            if(respuesta == 1){
                deportes* apostado = createDeportes();

                flag1=0,terminar_programa=0;

                do{
                pos = 0;
                end = 0;
                    gotoxy(51,1);printf("SELECCIONE A UN EQUIPO");
                    gotoxy(51,2);printf(ROJO_F "%s" RESET_COLOR, d->nombre);
                    gotoxy(51,3);printf("%s", x->nombre);
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
                                    gotoxy(51,1);printf("SELECCIONE A UN EQUIPO");
                                    gotoxy(51,2);printf(ROJO_F "%s" RESET_COLOR, d->nombre);
                                    gotoxy(51,3);printf("%s", x->nombre);
                                    flag1=0;
                                    break;

                            case 1:
                                    gotoxy(51,1);printf("SELECCIONE A UN EQUIPO");
                                    gotoxy(51,2);printf("%s", d->nombre);
                                    gotoxy(51,3);printf(ROJO_F "%s" RESET_COLOR, x->nombre);
                                    flag1=1;
                                    break;
                        }
                    }while(end != 1);

                    switch(flag1)
                    {
                        case 0: apostado->nombre = d->nombre; terminar_programa=1; break;
                        case 1: apostado->nombre = x->nombre; terminar_programa=1; break;
                    }
                }while(terminar_programa != 1);
                escogerApuesta(prueba, d, x, apostado);
            }

            if(respuesta == 3) break;
            cont++;
        }
    }
    system("cls");
    printf("Este es tu saldo actual: %lu CLP\n", prueba->tarjeta->saldo);
    printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
    printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);

    int respuesta;
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,4);printf("OPCIONES");
        gotoxy(1,5);printf(ROJO_F " - Volver al menu de la casa de apuestas" NEGRO_F);
        gotoxy(1,6);printf(" - Generar nueva ronda de apuestas");
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
                        gotoxy(1,4);printf("OPCIONES");
                        gotoxy(1,5);printf(ROJO_F " - Volver al menu de la casa de apuestas" NEGRO_F);
                        gotoxy(1,6);printf(" - Generar nueva ronda de apuestas");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,4);printf("OPCIONES");
                        gotoxy(1,5);printf(" - Volver al menu de la casa de apuestas");
                        gotoxy(1,6);printf(ROJO_F " - Generar nueva ronda de apuestas" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: respuesta = 1; terminar_programa=1; break;
            case 1: respuesta= 2; terminar_programa=1; break;
        }

    }while(terminar_programa != 1);
    system("cls");
    if(respuesta == 1){
            main();
    }
    if(respuesta == 2){
        free(mapDeportes);
        apuestasFutbol(prueba);
    }
}
