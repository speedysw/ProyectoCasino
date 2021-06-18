#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "treemap.h"

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

void menu();
void instrucciones();
void infoRojoAzul(FILE *);
int seguridad(usuario *);
void basedatos(usuario *);
void exportar(TreeMap *, usuario *);
const char *get_csv_field (char *, int);
void importar(TreeMap *, usuario *);
void registrarse(TreeMap *);
void iniciarSesion(TreeMap *);

long long lower_than_int(void* key1, void* key2){ //Funcion utilizada para crear arbol binario
    long long k1 = *((long long*) (key1));
    long long k2 = *((long long*) (key2));
    return k1<k2;
}

int main()
{
    menu();
    return 0;
}

void menu(){
    int a = 1;
    TreeMap* cuentas = createTreeMap(lower_than_int);
    while(a!= 5){
         printf("TIME LIMIT EXCEEDED \n");
         printf("1. Iniciar sesion\n");
         printf("2. Registrarse\n");
         printf("3. Jugar por diversion\n");
         printf("4. ¿Aprender a jugar?\n");
         printf("5. Salir\n");
         fflush(stdin);
         scanf("%d",&a);
         fflush(stdin);
         switch(a){
            case 1: iniciarSesion(cuentas);break;
            case 2: registrarse(cuentas); break;
            case 3: break;
            case 4: instrucciones(); break;
            case 5: printf("GRACIAS POR PASARSE POR EL CASINO, REGRESE PRONTO"); break;
            default: printf("\nEl numero que ingreso es incorrecto\n");
        }
        printf("\n");
    }
}

void registrarse(TreeMap * cuentas){
    usuario* login = createLogin(login);
    char* aux = (char *) malloc(sizeof(char) * 20);
    int comprobar=0;
    printf("--------------------REGISTRO--------------------\n");
    printf("BIENVENIDOS AL CASINO, REGISTRESE PARA CONTINUAR \n");
    printf("Nombre: ");
    scanf("%s", login->nombre);
    fflush(stdin);
    printf("Apellido: ");
    scanf("%s", login->apellido);
    fflush(stdin);
    printf("Nombre de usuario: ");
    scanf("%s",login->id);
    fflush(stdin);
    basedatos(login);
    do{
        printf("Ejemplo: 4678 9845 0923 XXXX \n");
        printf("Inserte tarjeta de credito: ");
        scanf("%[^\n]",login->tarjeta->numero);
        fflush(stdin);
        int x = strlen(login->tarjeta->numero);
        if(x < 19 || x > 19) printf("TARJETA INVALIDA\n");
        if(x == 19){
         comprobar = 1;
        }
        login->tarjeta->saldo = 1000000;

    }while(comprobar == 0);

    do{
        comprobar = 0;
        printf("Contraseña: ");
        scanf("%s",login->password);
        fflush(stdin);
        printf("Confirmar contraseña: ");
        scanf("%s",aux);
        fflush(stdin);

        if(strcmp(login->password,aux) == 0){
            comprobar = seguridad(login);
            aux = login->password;
        }

        if(strcmp(login->password,aux) != 0) printf("LAS CONTRASEÑAS NO COINCIDEN INTENTELO DENUEVO\n");

    }while(comprobar == 0);

    if(strcmp(login->password,aux) == 0){
        printf("Sr. %s %s fue registrado con exito en nuestra aplicacion, su cuenta es la siguiente: \n", login->nombre, login->apellido);
        printf("Nombre de usuario de la cuenta: %s\n", login->id);
        printf("Clave de la cuenta: %s\n", login->password);
        printf("Tarjeta de credito: ");
        for(int i = 0 ; i < 15 ; i++){
            printf("%c", login->tarjeta->numero[i]);
        }
        printf("XXXX\n");
        printf("Este es el saldo de su tarjeta: %lu\n", login->tarjeta->saldo);
        printf("BIENVENIDO AL CASINO TIME LIMTID EXCEEDED EDITION!!");
    }
    insertTreeMap(cuentas, login->id, login);
    exportar(cuentas, login);
}

void exportar(TreeMap * cuentas, usuario * login){

    FILE *datos;
    char nombreArchivo[23];
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s%s", login->id, ".csv");
    datos = fopen(nombreArchivo,"w");

    usuario *d = (usuario *) malloc(sizeof(usuario)* 1);
    d = firstTreeMap(cuentas);
    char line[100];
    while(d != NULL){
        snprintf(line, sizeof(line), "%s,%s,%s,%s,%lu,%s\n",d->nombre,d->apellido,d->id,d->tarjeta->numero,d->tarjeta->saldo,d->password);
        fputs(line, datos);
        d = nextTreeMap(cuentas);
    }
    fclose(datos);
    //free(datos);
    //free(d);
}

void iniciarSesion(TreeMap * cuentas){
    usuario * aux = createLogin(aux);
    usuario * aux2 = createLogin(aux2);

    printf("--------------------INICIO DE SESION--------------------\n");
    printf("BIENVENIDO DEVUELTA AL TIME LIMITD EXCEEDED\n");

    printf("Nombre de usuario: ");
    scanf("%s", aux->id);
    strcpy(aux2->id,aux->id);
    fflush(stdin);

    printf("Contraseña: ");
    scanf("%s", aux2->password);
    fflush(stdin);

    importar(cuentas,aux);
    aux = searchTreeMap(cuentas, aux2->id);

    if(strcmp(aux->id,aux2->id) == 0 && strcmp(aux->password,aux2->password) == 0) printf("EL USUARIO HA INGRESADO CON EXITO, BIEN\n");

    if(strcmp(aux->id,aux2->id) != 0 || strcmp(aux->password,aux2->password) != 0){
        printf("Ups, el usuario o la contraseña no coinciden, vuelve a intentarlo\n");
        iniciarSesion(cuentas);
    }
}

int seguridad(usuario * login){
    int x = strlen(login->password);
    char* aux = (char *) malloc(sizeof(char) * 20);
    int comprobante = 0;
    if(x < 6){
        printf("CONTRASEÑA NO SEGURA, ESCOGA OTRA VEZ\n");
        do{
        printf("Contraseña: ");
        scanf("%s",login->password);
        fflush(stdin);
        printf("Confirmar contraseña: ");
        scanf("%s",aux);
        fflush(stdin);
        if(strcmp(login->password,aux) == 0) {
            comprobante = seguridad(login);
            aux = login->password;
        }
        if(strcmp(login->password,aux) != 0) printf("LAS CONTRASEÑAS NO COINCIDEN INTENTELO DENUEVO\n");
        }while(comprobante == 0);
    }
    return 1;
}

void importar(TreeMap* cuentas, usuario* lectura){
    FILE* archivo;
    char nombreArchivo[23];
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s%s", lectura->id, ".csv");
    archivo = fopen(nombreArchivo,"r");
    if(archivo == NULL){
        printf("Ups, el usuario o la contraseña no coinciden, vuelve a intentarlo\n");
        iniciarSesion(cuentas);
    }

    char line[100];
    while(fgets(line,100,archivo) != NULL){
        lectura->nombre = (char *)get_csv_field(line,0);
        lectura->apellido = (char *)get_csv_field(line,1);
        lectura->id = (char *)get_csv_field(line,2);
        lectura->tarjeta->numero = (char *)get_csv_field(line,3);
        lectura->tarjeta->saldo = atoi(get_csv_field(line,4));
        lectura->password = (char *) get_csv_field(line,5);
    }
    insertTreeMap(cuentas, lectura->id, lectura);
}

const char *get_csv_field (char * tmp, int k){ //Función para leer distintos datos del archivo.
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){ //mientras el tmp [siguiente del indice] sea distinto a null
        if(tmp[i]== '\"'){  //si el tmp [indice] es igual a comillas (las comillas son cuando hay mas de un tag)
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1; //(si openmark es un numero distinto a cero, ini_i = i++)
            i++;
            continue;
        }
        if(open_mark || tmp[i]!= ','){ // si no encuentra coma y openmark es numero !=0, avanza 1 y continua
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
        i++;
    }
    if(k==j){
       ret[i-ini_i] = 0;
       return ret;
    }
    return NULL;
}

void basedatos(usuario * login){
    FILE *Datos;
    char nombreArchivo[23];
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s%s", login->id, ".csv");
    Datos = fopen(nombreArchivo,"r");
    if(Datos == NULL){
        printf("El nombre de usuario no existe\n");
    }
    if(Datos != NULL){
        printf("Nombre de usuario no disponible, seleccione otro porfavor");
        printf("Nombre de usuario: ");
        scanf("%s", login->id);
        fflush(stdin);
        basedatos(login);
    }
    //fclose(Datos);
    //free(Datos);
}

void instrucciones(){
    int a = 1;
    FILE *lectura;
    while(a!= 8){
        printf("INSTRUCCIONES \n");
        printf("1. Tragamonedas\n");
        printf("2. Ruleta\n");
        printf("3. Craps\n");
        printf("4. Blackjack\n");
        printf("5. Keno\n");
        printf("6. Rojo y Azul\n");
        printf("7. Adivina la carta\n");
        printf("8. Volver al menu principal\n");
        fflush(stdin);
        scanf("%d",&a);
        fflush(stdin);
        switch(a){
            case 1: /*infoTragamonedas(lectura);*/break;
            case 2: /*infoRuleta(lectura);*/ break;
            case 3: /*infoCraps(lectura);*/ break;
            case 4: /*infoBlackjack(lectura);*/ break;
            case 5: /*infoKeno(lectura);*/ break;
            case 6: infoRojoAzul(lectura); break;
            case 7: //infoCarta(lectura); break;
            case 8: menu(); break;
            default: printf("\nEl numero que ingreso es incorrecto\n");
        }
        printf("\n");
    }
}

infoRojoAzul(FILE *lectura){
    lectura = fopen("RojoAzul.txt", "rb");
    if(lectura == NULL){
        printf("Error en la apertura del archivo");
        return 1;
    }

    char leer;
    while(feof(lectura) == 0){
        leer = fgetc(lectura);
        printf("%c", leer);
    }
    fclose(lectura);
}

