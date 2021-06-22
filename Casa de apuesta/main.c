#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>>
#include "hashmap.h"
#include <time.h>

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

usuario *createLogin() {
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
    deportes *aux = (deportes *) malloc(sizeof(deportes)*10);
    aux->nombre = (char *) malloc(sizeof(char) * 18);
    aux->pais = (char *) malloc(sizeof(char) * 9);
    return aux;
}

void apuestasTennis(usuario *) ;
void importar(HashMap *);
const char *get_csv_field (char *, int );
void emparejamiento(HashMap *, usuario *);
void escoger(deportes *, deportes *, usuario *, deportes *);

int main()
{
    usuario* prueba = createLogin(prueba);
    prueba->nombre = "Cesar";
    prueba->apellido = "Maureira";
    prueba->id = "SpeedySW";
    prueba->password = "hola123";
    prueba->tarjeta->numero = "1234 5343 5432 1234";
    prueba->tarjeta->saldo = 1000000;
    apuestasTennis(prueba);
/*
    int a = 1;
    while(a!= 5){
         printf("TIME LIMIT EXCEEDED \n");
         printf("1. Apuestas de Futbol\n");
         printf("2. Apuestas de Basketball\n");
         printf("3. Apuestas de Tennis\n");
         printf("4. Carrera de caballos\n");
         printf("5. Atras\n");
         fflush(stdin);
         scanf("%d",&a);
         fflush(stdin);
         switch(a){
            case 1: ; break;
            case 2: ; break;
            case 3: apuestasTennis(prueba); break;
            case 4: ; break;
            case 5: break;
            default: printf("\nEl numero que ingreso es incorrecto\n");
        }
        printf("\n");
    }
    */
    return 0;
}

void apuestasTennis(usuario * prueba){
    int aux = 10 + 10 * 0.3;
    HashMap *MapATP = createMap(aux);
    importar(MapATP);

    deportes *d = firstMap(MapATP);
    /*while(d != NULL){
        printf("---------------------------------\n");
        printf("Tenista: %s\n",d->nombre);
        printf("Ranking ATP: %i\n", d->ranking);
        printf("Pais: %s\n",d->pais);
        printf("Multiplciador del Tenista: %.2f\n",d->multiplicador);
        printf("Clave del mapa: %d\n",d->clave);
        d = nextMap(MapATP);
    }*/
        //printf("")
    emparejamiento(MapATP, prueba);
}

void emparejamiento(HashMap* MapATP, usuario * prueba){

    int sorteo,sorteo1;
    int cont = 0;
    int aux=10;
    deportes* escogido = createDeportes();
    srand(time(NULL));
    while(cont < 5){

        sorteo = rand () % aux + 1; // 8
        sorteo1 = rand () % aux + 1; // 1


        if(sorteo == sorteo1){
                sorteo = rand () % aux + 1; // 8
                sorteo1 = rand () % aux + 1; // 1
        }

        while(searchMap(MapATP,&sorteo) == NULL){
                sorteo = rand () % aux + 1;
        }

        while(searchMap(MapATP,&sorteo1) == NULL){
                sorteo1 = rand() % aux + 1;
        }


        if(sorteo != sorteo1){
            deportes *d = searchMap(MapATP, &sorteo); // le da los datos del 1
            deportes *x = searchMap(MapATP, &sorteo1); // le da los datos del 8
            eraseMap(MapATP, &sorteo1);
            eraseMap(MapATP, &sorteo);
            insertMap(MapATP, &d->nombre, &d);
            insertMap(MapATP, &x->nombre, &x);
            printf("|Ranking ATP: %i | %s , %s | x%.2f | vs |Ranking ATP: %i | %s , %s | x%.2f |\n",d->ranking,d->nombre,d->pais,d->multiplicador,x->ranking,x->nombre,x->pais,x->multiplicador);
            printf("Escoja a uno de los dos tenistas (introduzca el nombre completo): ");
            scanf("%[^\n]",escogido->nombre);
            fflush(stdin);
            escoger(x,d,prueba,escogido);
            cont++;
        }
    }
    printf("Este es tu saldo actual: %lu CLP\n", prueba->tarjeta->saldo);
    printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
    printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);
}

void escoger(deportes * x, deportes *d, usuario * prueba, deportes* escogido){
            int numero;
            unsigned long apuesta;
            HashMap* mapApuestas = createMap(4);
            //printf("HOLA");
            if(strcmp(escogido->nombre,d->nombre) == 0){

                int clave = 1;
                insertMap(mapApuestas,&clave,&d);
                printf("Introduzca su apuesta: ");
                scanf("%lu",&apuesta);
                prueba->tarjeta->saldo = prueba->tarjeta->saldo - apuesta;
                printf("Tu apuesta fue de: %lu CLP \n", apuesta);
                numero = rand() % 2 + 1;


                if(numero == 1){
                        printf("GANADOR: %s\n", d->nombre);
                        printf("GANASTE!!! %.2f CLP \n", apuesta * d->multiplicador);
                        prueba->tarjeta->ganancias += (apuesta * d->multiplicador);
                        prueba->tarjeta->saldo += (apuesta * d->multiplicador);
                }

                if(numero == 2){
                        printf("GANADOR: %s\n", x->nombre);
                        printf("PERDISTE!!!\n");
                        prueba->tarjeta->perdidas += apuesta;
                }
            }

            if(strcmp(escogido->nombre,x->nombre) == 0){
                int clave = 2;
                insertMap(mapApuestas,&clave,&x);
                printf("Introduzca su apuesta: ");
                scanf("%lu",&apuesta);
                prueba->tarjeta->saldo = prueba->tarjeta->saldo - apuesta;
                printf("Tu apuesta fue de: %lu CLP \n", apuesta);

                numero = rand() % 2 + 1;
                if(numero == 2){
                        printf("GANADOR: %s\n", x->nombre);
                        printf("GANASTE!!! %.2f CLP \n", apuesta * x->multiplicador);
                        prueba->tarjeta->ganancias += (apuesta * x->multiplicador);
                        prueba->tarjeta->saldo += (apuesta * x->multiplicador);

                }

                if(numero == 1){
                        printf("GANADOR: %s\n", d->nombre);
                        printf("PERDISTE!!!\n");
                        prueba->tarjeta->perdidas += apuesta;
                }
            }

            if(strcmp(escogido->nombre,d->nombre) != 0){
               if(strcmp(escogido->nombre,x->nombre) != 0){
                    scanf("%[^\n]",escogido->nombre);
                    fflush(stdin);
                    escoger(x,d,prueba,escogido);
                }
            }

            if(strcmp(escogido->nombre,x->nombre) != 0){
               if(strcmp(escogido->nombre,d->nombre) != 0){
                    scanf("%[^\n]",escogido->nombre);
                    fflush(stdin);
                    escoger(x,d,prueba,escogido);
               }
            }
}

void importar(HashMap *MapATP){
    FILE* archivo;
    archivo = fopen("ATP.csv","r");
    if(archivo == NULL){
        printf("El archivo no se abrio correctamente\n");
        return 1;
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
    int cont = i - 1;
    for(i=0 ; i < cont ; i++){
        insertMap(MapATP,&datos[i].clave,&datos[i]);
    }
}

const char *get_csv_field (char * tmp, int k){ //Función para leer distintos datos del archivo.
    //int open_mark = 0;
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
