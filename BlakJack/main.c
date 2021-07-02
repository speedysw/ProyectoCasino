#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
#include <stdbool.h>

typedef struct {
    int numero;
    char *pinta;
} Baraja;

void *createBaraja() {
    Baraja *baraja = (Baraja *) malloc(sizeof(Baraja));
    baraja->pinta = (char *) malloc(sizeof(char)* 8);
    return baraja;
}

void barajaAleatoria(HashMap *);
int sacarCarta(HashMap *, int);
void generarCarta(int *, char *, HashMap *);

int main()
{
    srand(time(NULL));
    HashMap *mapBaraja = createMap(52);
    barajaAleatoria(mapBaraja);

    printf("Ingrese la cantidad de dinero que quiere apostar: ");
    int dinero;
    scanf("%i", &dinero);

    int salir;
    do {
        printf("Si desea retirarse con su dinero, escriba: 1\n");
        printf("Si desea continuar, escriba: 2\n");
        scanf("%i", &salir);
        if(salir == 2) dinero = sacarCarta(mapBaraja, dinero);
        printf("\n");
    } while(salir == 2 && dinero != 0);
    return 0;
}

void barajaAleatoria(HashMap *mapBaraja) {
    int *carta;
    char *key;
    Baraja *baraja;

    for(int i = 0 ; i < 40 ; i++) {
        baraja = createBaraja();
        carta = (int *) malloc(sizeof(int));
        key = (char *) malloc(sizeof(char) * 10);

        *carta = rand() % 40 + 1;
        sprintf(key, "%i", *carta);

        while(searchMap(mapBaraja, key) != NULL) {
            *carta = rand() % 40 + 1;
            sprintf(key, "%i", *carta);
        }

        if(*carta <= 10) {
            baraja->numero = *carta;
            strcpy(baraja->pinta, "moneda");
        } else if(*carta <= 20) {
            if(*carta % 10 == 0) baraja->numero = 10;
            else baraja->numero = *carta % 10;
            strcpy(baraja->pinta, "baston");
        } else if(*carta <= 30) {
            if(*carta % 10 == 0) baraja->numero = 10;
            else baraja->numero = *carta % 10;
            strcpy(baraja->pinta, "espada");
        } else {
            if(*carta % 10 == 0) baraja->numero = 10;
            else baraja->numero = *carta % 10;
            strcpy(baraja->pinta, "copa");
        }
        insertMap(mapBaraja, key, baraja);
    }
}

int sacarCarta(HashMap *mapBaraja, int dinero) {
    int *carta;
    char *key;

    carta = (int *) malloc(sizeof(int));
    key = (char *) malloc(sizeof(char) * 10);

    generarCarta(carta, key, mapBaraja);
    Baraja *aux = searchMap(mapBaraja, key);
    printf("Su primera carta es: %i de %s\n", aux->numero, aux->pinta);
    int suma = aux->numero;
    eraseMap(mapBaraja, key);

    generarCarta(carta, key, mapBaraja);
    aux = searchMap(mapBaraja, key);
    printf("Su segunda carta es: %i de %s\n", aux->numero, aux->pinta);
    suma += aux->numero;
    eraseMap(mapBaraja, key);

    printf("Ahora se entregara una carta al Crupier\n");
    generarCarta(carta, key, mapBaraja);
    aux = searchMap(mapBaraja, key);
    printf("Carta Crupier: %i de %s\n", aux->numero, aux->pinta);
    int sumaC = aux->numero;
    eraseMap(mapBaraja, key);

    bool perder = false;
    int desicion;
    do {
        printf("Usted suma %i, si desea plantarse ingrese 1\n", suma);
        printf("Si desea volver a sacar una carta ingrese 2\n");
        scanf("%i", &desicion);
        if(desicion == 2) {
            generarCarta(carta, key, mapBaraja);
            aux = searchMap(mapBaraja, key);
            printf("Su nueva carta es: %i de %s\n", aux->numero, aux->pinta);
            suma += aux->numero;
            eraseMap(mapBaraja, key);
            if(suma > 21) {
                perder = true;
                printf("Tu suma fue %i, sobrepasaste 21, PERDISTE\n", suma);
            }
        }
    } while(desicion == 2 && perder == false);

    if(perder == false) {
        printf("Se ha plantado con %i\n", suma);
        if(suma == 21) {
            printf("BLACK JACK\n");
            printf("Has ganado: $%i\n", dinero * 2);
            dinero += dinero * 2;
        } else {
            do {
                printf("Ahora se entregara otra carta al crupier\n");
                generarCarta(carta, key, mapBaraja);
                Baraja *aux = searchMap(mapBaraja, key);
                printf("Carta Crupier: %i de %s\n", aux->numero, aux->pinta);
                sumaC += aux->numero;
                printf("Crupier suma: %i\n", sumaC);
                eraseMap(mapBaraja, key);
            } while(sumaC < 17);
            if(sumaC > 21) {
                printf("Has ganado: $%i\n", dinero);
                dinero += dinero;
            } else {
                if(sumaC > suma) {
                    printf("Has perdido: $%i\n", dinero);
                    dinero -= dinero;
                } else if(sumaC == suma) {
                    printf("Empate, conservas tu dinero\n");
                } else {
                    printf("Has ganado: $%i\n", dinero);
                    dinero += dinero;
                }
            }
        }
    }

    return dinero;
}

void generarCarta(int *carta, char *key, HashMap *mapBaraja) {
    *carta = rand() % 40 + 1;
    sprintf(key, "%i", *carta);
    while(searchMap(mapBaraja, key) == NULL) {
        *carta = rand() % 40 + 1;
        sprintf(key, "%i", *carta);
    }
}
