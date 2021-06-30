#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

void generar(HashMap *, int);

int main(){
    srand(time(NULL));
    int num = 0, capacidad = 26;
    HashMap *mapKeno = createMap(&capacidad);
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 10 ; j++ ) {
            num++;
            printf("  %2i ", num);
        }
        printf("\n");
    }
    generar(mapKeno, 20);
    printf("Ingrese la cantidad de numeros que quiere apostar\n");
    int x;
    do {
        scanf("%i", &x);
        if(x < 1 || x > 20) printf("Numero invalido, recuerde que puede apostar desde uno a veinte numeros\n");
    } while(x < 1 || x > 20);
    int aux;
    printf("Generar numeros aleatorios = 1\n");
    printf("Generar numeros manualmente = 2\n");
    scanf("%i", &aux);
    HashMap *apuestaKeno = createMap(&capacidad);
    if(aux == 1) {
        generar(apuestaKeno, x);
    } else {
        for(int i = 0 ; i < x ; i++) {
            printf("Ingrese apuesta %i: ", i + 1);
            do {
                scanf("%i", &num);
                if(num < 1 || num > 80) printf("Numero invalido, recuerde que puede apostar desde el uno al ochenta\n");
            } while(num < 1 || num > 80);
            insertMap(apuestaKeno, &num, num);
        }
    }
    int p = firstMap(mapKeno);
    while(p != NULL) {
        printf("%i ", p);
        p = nextMap(mapKeno);
    }
    printf("\n");

    p = firstMap(apuestaKeno);
    while(p != NULL) {
        printf("%i ", p);
        p = nextMap(apuestaKeno);
    }
    printf("\n");

    p = firstMap(apuestaKeno);
    while(p != NULL) {

        if(searchMap(mapKeno, &p) == p) {
            printf("%i\n", p);
        }
        p = nextMap(apuestaKeno);
    }
    return 0;
}

void generar(HashMap *map, int x) {
    int aux;
    for(int i = 0 ; i < x ; i++) {
        aux = rand() % 80 + 1;
        while(searchMap(map, &aux) == aux) {
            aux = rand() % 80 + 1;
        }
        insertMap(map, &aux, aux);
    }
    printf("\n");
}
