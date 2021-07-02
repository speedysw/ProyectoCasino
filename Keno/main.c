#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

void recompensa();
void generarA(HashMap *, int);
void generarM(HashMap *, int);
void correctas(HashMap *, HashMap *, HashMap *);
void escribirCorrectas(HashMap *, HashMap *, float);
void escribirApuesta(HashMap *);

int main(){
    system("COLOR");
    srand(time(NULL));
    int num = 0, capacidad = 26;
    HashMap *mapKeno = createMap(capacidad);

    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 10 ; j++ ) {
            num++;
            printf("  %2i ", num);
        }
        printf("\n");
    }

    recompensa();
    printf("Ingrese la cantidad de dinero que quiere apostar: ");
    int dinero;
    scanf("%i", &dinero);
    generarA(mapKeno, 20);

    printf("Ingrese la cantidad de numeros que quiere apostar: ");
    int x;
    do {
        scanf("%i", &x);
        if(x < 1 || x > 20) printf("Numero invalido, recuerde que puede apostar desde uno a veinte numeros\n");
    } while(x < 1 || x > 20);

    int aux;
    printf("Generar numeros aleatorios = 1\n");
    printf("Generar numeros manualmente = 2\n");
    scanf("%i", &aux);

    HashMap *apuestaKeno = createMap(capacidad);
    if(aux == 1) {
        generarA(apuestaKeno, x);
    } else {
        generarM(apuestaKeno, x);
    }

    escribirApuesta(apuestaKeno);
    HashMap *mapResultado = createMap(capacidad);
    correctas(mapKeno, apuestaKeno, mapResultado);
    escribirCorrectas(mapResultado, mapKeno, dinero);

    return 0;
}

void recompensa() {
    printf("\n| APUESTA | AUMENTO |\n");
    float multiplicador = 0;
    for(int i = 0 ; i < 10 ; i++) {
        printf("|   %2i    |   %.2f  |\n", i + 1, multiplicador);
        multiplicador += 0.25;
    }
    printf("\n");
}

void generarA(HashMap *map, int x) {
    int *value;
    char *key;
    for(int i = 0 ; i < x ; i++) {
        value = (int*) malloc(sizeof(int));
        key = malloc(sizeof(char) * 10);
        *value = rand() % 80 + 1;
        sprintf(key, "%i", *value);
        while(searchMap(map, key) != NULL) {
            *value = rand() % 80 + 1;
            sprintf(key, "%i", *value);
        }
        insertMap(map, key, value);
    }
}

void generarM(HashMap *map, int x) {
    int *num;
    for(int i = 0 ; i < x ; i++) {
        num = (int *) malloc(sizeof(int));
        char *key = malloc(sizeof(char) * 10);
        printf("Ingrese apuesta %i: ", i + 1);
        do {
            scanf("%i", num);
            sprintf(key, "%i", *num);
            if(*num < 1 || *num > 80) printf("Numero invalido, recuerde que puede apostar desde el uno al ochenta\n");
            if(searchMap(map, key) != NULL) printf("Este numero ya fue apostado, seleccione uno nuevo : ");
        } while(*num < 1 || *num > 80 || searchMap(map, key) != NULL);
        insertMap(map, key, num);
    }
    printf("\n");
}

void escribirApuesta(HashMap *apuestaKeno) {
    printf("Numeros apostados: ");
    int *p = firstMap(apuestaKeno);
    while(p != NULL) {
        printf("| %i ", *p);
        p = nextMap(apuestaKeno);
    }
    printf("|\n\n");
}

void correctas(HashMap *mapKeno, HashMap *apuestaKeno, HashMap *mapResultado) {
    int *value = firstMap(apuestaKeno);
    while(value != NULL) {
        char *key = malloc(sizeof(char) * 10);
        sprintf(key, "%i", *value);
        if(searchMap(mapKeno, key) != NULL) {
            insertMap(mapResultado, key, value);
        }
        value = nextMap(apuestaKeno);
    }
}

void escribirCorrectas(HashMap *mapResultado, HashMap *mapKeno, float dinero) {
    int num = 0;
    float multiplicador = -0.25, auxDinero = dinero;
    int *value;
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 10 ; j++ ) {
            value = (int *) malloc(sizeof(int));
            *value = num;
            char *key = malloc(sizeof(char) * 10);
            sprintf(key, "%i", *value);
            if(searchMap(mapKeno, key) != NULL) {
                if(searchMap(mapResultado, key) != NULL) {
                    printf(" \x1b[41m %2i \x1b[0m", num);
                    multiplicador += 0.25;
                } else {
                    printf(" \x1b[47m\x1b[30m %2i \x1b[0m", num);
                }
            } else {
                printf("  %2i ", num);
            }
            num++;
        }
        printf("\n");
    }
    if(multiplicador != -0.25) {
        dinero += dinero * multiplicador;
        if(dinero == auxDinero) printf("\nNo hubo ganancias\n");
        else printf("\nGanaste $%f\n", dinero);
    } else {
        printf("\nPerdiste! $-%.0f\n", dinero);
    }
}
