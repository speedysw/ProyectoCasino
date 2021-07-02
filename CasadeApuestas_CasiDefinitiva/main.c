#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
   // apuestasTennis(prueba); //falta la wea del dinero;
    apuestasFormula1(prueba);
    //apuestasNBA(prueba);
    //apuestasFutbol(prueba);
/*
    int a = 1;
    while(a!= 5){
         printf("TIME LIMIT EXCEEDED \n");
         printf("1. Apuestas de Futbol\n");
         printf("2. Apuestas de Basketball\n");
         printf("3. Apuestas de Tennis\n");
         printf("4. Apuestas de Formula 1\n");
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
    importarATP(MapATP);
    encuentrosATP(MapATP, prueba);
}

void encuentrosATP(HashMap* MapATP, usuario * prueba){
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
            escogerApuesta(prueba,d,x,escogido);
            cont++;
        }
    }
    printf("Este es tu saldo actual: %lu CLP\n", prueba->tarjeta->saldo);
    printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
    printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);
}

/*void escoger(deportes * x, deportes *d, usuario * prueba, deportes* escogido){
            int numero;
            unsigned long apuesta;
            HashMap* mapApuestas = createMap(4);
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
}*/

void importarATP(HashMap *MapATP){
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

void apuestasFormula1(usuario * prueba){
    int aux = 12 + 10 * 0.3;
    HashMap *Formula1 = createMap(aux);
    importarFormula(Formula1);
    /*deportes *d = firstMap(Formula1);
    while(d != NULL){
        printf("| Clasificacion: %4d | %20s | %15s | %9i | %16.2f |\n",d->clave, d->nombre, d->pais, d->ranking, d->multiplicador);
        d = nextMap(Formula1);
    }*/
    encuentrosF1(Formula1, prueba);
}

void encuentrosF1(HashMap * Formula1, usuario * prueba){
    int piloto;
    unsigned long apuesta;
    deportes *d = firstMap(Formula1);
    printf("|                               FORMULA 1: GRAN PREMIO DE FRANCIA                             |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("|                     |         PILOTO       |    ESCUADRA     |   DORSAL  |   MULTIPLICADOR  |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    while(d != NULL){
        printf("| Clasificacion: %4d | %20s | %15s | %9i | %16.2f |\n",d->clave, d->nombre, d->pais, d->ranking, d->multiplicador);
        d = nextMap(Formula1);
    }
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("¿DESEA REALIZAR APUESTA POR ESTA CARRERA?\n");
    printf("PRESIONE 1, SI DESEA APOSTAR POR ESTA CARRERA\n");
    printf("PRESIONE 0, SI NO DESEA APOSTAR POR ESTA CARRERA\n");
    int respuesta;
    scanf("%i",&respuesta);
    if(respuesta == 1){
            printf("SELECCIONE A UN PILOTO (POR SU CLASIFICACION): ");
        scanf("%i", &piloto);
        deportes* aux = searchMap(Formula1, &piloto);
        printf("PILOTO ESCOGIDO: %s\n", aux->nombre);
        printf("INGRESE APUESTA: ");
        scanf("%lu", &apuesta);
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

            while(searchMap(Formula1,&posicion) == NULL){
                    posicion = rand () % 11 + 1;
            }

            deportes *ubicacion = searchMap(Formula1, &posicion);
            if(ubicacion != NULL){
                posicion = i + 1;
                printf("| Posicion: %7d | %20s | %15s | %9i | %16.2f |\n",posicion, ubicacion->nombre, ubicacion->pais, ubicacion->ranking, ubicacion->multiplicador);
                i++;
            }

            if(posicion == 1){
                insertMap(Ganadores, &posicion, ubicacion);
            }

            eraseMap(Formula1, &ubicacion->clave);
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

    printf(" -------------------------------------------------------------------------------------------\n");
    printf("SI DESEA VOLVER AL MENU PRESIONE 1 , SI DESEA GENERAR UNA CARRERA NUEVA PRESIONE 2\n");
    scanf("%i",&respuesta);

    if(respuesta == 2){
        encuentrosF1(Formula1, prueba);
    }

}

void importarFormula(HashMap *Formula1){
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
    int cont = i - 1;
    for(i=0 ; i < cont ; i++){
        insertMap(Formula1,&datos[i].clave,&datos[i]);
    }
}

void apuestasNBA(usuario * prueba){
    int aux = 12 + 10 * 0.3;
    HashMap *mapDeportes = createMap(aux);
    importarNBA(mapDeportes);
    deportes *d = firstMap(mapDeportes);
    while(d != NULL){
        printf("| Clasificacion: %4d | %20s | %15s | %9i | %16.2f |\n",d->clave, d->nombre, d->pais, d->ranking, d->multiplicador);
        d = nextMap(mapDeportes);
    }
    encuentrosNBA(mapDeportes, prueba);
}

void encuentrosNBA(HashMap *mapDeportes, usuario * prueba){
    int sorteo,sorteo1;
    int cont = 0;
    int aux=12;
    deportes* escogido = createDeportes();
    srand(time(NULL));
    while(cont < 6){

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
            if((strcmp(d->pais,"Conferencia Este") == 0) && (strcmp(x->pais,"Conferencia Este") == 0)) printf("ENCUENTRO DE LA CONFERENCIA ESTE\n");
            if((strcmp(d->pais,"Conferencia Oeste") == 0) && (strcmp(x->pais,"Conferencia Oeste") == 0)) printf("ENCUENTRO DE LA CONFERENCIA OESTE\n");
            if((strcmp(d->pais,"Conferencia Oeste") != 0) && (strcmp(x->pais,"Conferencia Oeste") == 0)) printf("ENCUENTRO AMISTOSO DE LA NBA\n");
            if((strcmp(d->pais,"Conferencia Este") != 0) && (strcmp(x->pais,"Conferencia Este") == 0)) printf("ENCUENTRO AMISTOSO DE LA NBA\n");
            printf("| Clasificacion: %d | %s | %s | x%10.2f | vs | Clasificacion: %d | %s | %s | x%.2f |\n",d->ranking,d->pais,d->nombre,d->multiplicador,x->ranking,x->pais,x->nombre,x->multiplicador);
            printf("¿DESEA APOSTAR POR ESTE ENCUENTRO?\n");
            printf("Presione 1, si esque desea apostar\n");
            printf("Presione 2, para pasar al siguiente encuentro\n");
            scanf("%i",&respuesta);
            if(respuesta == 1){
                deportes* apostado = createDeportes();
                printf("SELECCIONE A UN EQUIPO(POR NOMBRE)");
                scanf("%[^\n]",apostado->nombre);
                fflush(stdin);
                escogerApuesta(prueba, d, x, apostado);
            }
            cont++;
        }
        printf("Este es el contador: %i", cont);
    }

    printf("Este es tu saldo actual: %lu CLP\n", prueba->tarjeta->saldo);
    printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
    printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);

}

void escogerApuesta(usuario* prueba, deportes* equipo1, deportes* equipo2, deportes* apostado){
    int sorteo;
    unsigned long apuesta;

    if(strcmp(apostado->nombre,equipo1->nombre) == 0){
        printf("Introduzca su apuesta: ");
        scanf("%lu",&apuesta);
        prueba->tarjeta->saldo = prueba->tarjeta->saldo - apuesta;
        printf("Tu apuesta fue de: %lu CLP \n", apuesta);
        sorteo = rand() % 2 + 1;

        if(sorteo == 1){
            printf("GANADOR: %s\n", equipo1->nombre);
            printf("GANASTE!!! %.2f CLP \n", apuesta * equipo1->multiplicador);
            prueba->tarjeta->ganancias += (apuesta * equipo1->multiplicador);
            prueba->tarjeta->saldo += (apuesta * equipo1->multiplicador);
        }

        if(sorteo == 2){
            printf("GANADOR: %s\n", equipo2->nombre);
            printf("PERDISTE!!!\n");
            prueba->tarjeta->perdidas += apuesta;
        }
    }

    if(strcmp(apostado->nombre,equipo2->nombre) == 0){
        printf("Introduzca su apuesta: ");
        scanf("%lu",&apuesta);
        prueba->tarjeta->saldo = prueba->tarjeta->saldo - apuesta;
        printf("Tu apuesta fue de: %lu CLP \n", apuesta);
        sorteo = rand() % 2 + 1;
        if(sorteo == 1){
            printf("GANADOR: %s\n", equipo2->nombre);
            printf("GANASTE!!! %.2f CLP \n", apuesta * equipo2->multiplicador);
            prueba->tarjeta->ganancias += (apuesta * equipo2->multiplicador);
            prueba->tarjeta->saldo += (apuesta * equipo2->multiplicador);
        }

        if(sorteo == 2){
            printf("GANADOR: %s\n", equipo1->nombre);
            printf("PERDISTE!!!\n");
            prueba->tarjeta->perdidas += apuesta;
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
        datos[i].clave = i;
        i++;
    }

    int cont = i;
    for(i=1 ; i < cont ; i++){
        insertMap(mapDeportes,&datos[i].clave,&datos[i]);
    }
}

void apuestasFutbol(usuario * prueba){
    int aux = 32 + 10 * 0.3;
    HashMap *mapDeportes = createMap(aux);
    //printf("HOLA");
    importarFutbol(mapDeportes);
    deportes *d = firstMap(mapDeportes);
    /*while(d != NULL){
        printf("| %20s | %15s | %16.2f |\n", d->nombre, d->pais, d->multiplicador);
        d = nextMap(mapDeportes);
    }*/
    encuentrosFutbol(mapDeportes, prueba);
}

void importarFutbol(HashMap * mapDeportes){
    //printf("HOLA");
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
        //printf("%s\n",datos[i].nombre);
        //printf("%i\n",datos[i].clave);
        i++;
    }

    int cont = i;
    //printf("contador: %i\n",cont);
    for(i=0 ; i < cont ; i++){
       // printf("%i\n",i);
        insertMap(mapDeportes,&datos[i].clave,&datos[i]);
    }
}

void encuentrosFutbol(HashMap * mapDeportes, usuario * prueba){
    int sorteo,sorteo1;
    int cont = 0;
    int aux= 32;
    deportes* escogido = createDeportes();
    printf("HOLA");
    srand(time(NULL));
    while(cont < 16){

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
            printf("| %s | %s | x%.2f | vs | %s | %s | x%.2f |\n",d->pais,d->nombre,d->multiplicador,x->pais,x->nombre,x->multiplicador);
            printf("¿DESEA APOSTAR POR ESTE ENCUENTRO?\n");
            printf("Presione 1, si esque desea apostar\n");
            printf("Presione 2, para pasar al siguiente encuentro\n");
            scanf("%i",&respuesta);
            if(respuesta == 1){
                deportes* apostado = createDeportes();
                printf("SELECCIONE A UN EQUIPO(POR NOMBRE): ");
                scanf("%[^\n]",apostado->nombre);
                fflush(stdin);
                escogerApuesta(prueba, d, x, apostado);
            }
            cont++;
        }
        printf("Este es el contador: %i", cont);
    }

    printf("Este es tu saldo actual: %lu CLP\n", prueba->tarjeta->saldo);
    printf("Esto es lo que ganaste: %lu CLP\n", prueba->tarjeta->ganancias);
    printf("Esto es lo que perdiste: %lu CLP\n", prueba->tarjeta->perdidas);
}
