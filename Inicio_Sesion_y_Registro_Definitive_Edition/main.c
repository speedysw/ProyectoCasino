#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "treemap.h"
#include <windows.h>
#define RESET_COLOR "\x1b[0m"
#define NEGRO_T "\x1b[30m"
#define NEGRO_F "\x1b[40m"
#define ROJO_T "\x1b[31m"
#define ROJO_F "\x1b[41m"
#define VERDE_T "\x1b[32m"
#define VERDE_F "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define AMARILLO_F "\x1b[43m"
#define AZUL_T "\x1b[34m"
#define AZUL_F "\x1b[44m"
#define MAGENTA_T "\x1b[35m"
#define MAGENTA_F "\x1b[45m"
#define CYAN_T "\x1b[36m"
#define CYAN_F "\x1b[46m"
#define BLANCO_T "\x1b[37m"
#define BLANCO_F "\x1b[47m"

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
void gotoxy(int x , int y);

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
    system("cls");
    TreeMap* cuentas = createTreeMap(lower_than_int);
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;
    do{
    pos = 0;
    end = 0;
        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
        gotoxy(2,3);printf(BLANCO_F NEGRO_T " -INICIAR SESION" NEGRO_F BLANCO_T);
        gotoxy(2,4);printf(" -REGISTRARSE");
        gotoxy(2,5);printf(" -JUGAR POR DIVERSION");
        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
        gotoxy(2,7);printf(" -SALIR");
        do{
            key = getch();
            switch(key){
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
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(BLANCO_F NEGRO_T " -INICIAR SESION" NEGRO_F BLANCO_T);
                        gotoxy(2,4);printf(" -REGISTRARSE");
                        gotoxy(2,5);printf(" -JUGAR POR DIVERSION");
                        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(BLANCO_F NEGRO_T " -REGISTRARSE" NEGRO_F BLANCO_T);
                        gotoxy(2,5);printf(" -JUGAR POR DIVERSION");
                        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=1;
                        break;

                case 2:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRARSE");
                        gotoxy(2,5);printf(BLANCO_F NEGRO_T " -JUGAR POR DIVERSION" NEGRO_F BLANCO_T);
                        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRARSE");
                        gotoxy(2,5);printf(" -JUGAR POR DIVERSION" );
                        gotoxy(2,6);printf(BLANCO_F NEGRO_T " -NUEVO EN EL CASINO?" NEGRO_F BLANCO_T);
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRARSE");
                        gotoxy(2,5);printf(" -JUGAR POR DIVERSION" );
                        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
                        gotoxy(2,7);printf(BLANCO_F NEGRO_T " -SALIR" NEGRO_F BLANCO_T);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: iniciarSesion(cuentas); break; //Iniciar Sesion
            case 1: registrarse(cuentas); break; //Registrarse
            case 2: break; //Jugar por diversion
            case 3: printf("\n\n"); instrucciones(); break; //Nuevo en el casino?
            case 4: terminar_programa=1; break;;//Salir
        }
    }while(terminar_programa != 1);
}

void registrarse(TreeMap * cuentas){
    system("cls");
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
    system("cls");
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
        printf("BIENVENIDO AL CASINO TIME LIMTID EXCEEDED EDITION!!\n");
    }
    insertTreeMap(cuentas, login->id, login);
    exportar(cuentas, login);
    system("pause");
    system("cls");

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
    system("cls");
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
    system("pause");
    system("cls");
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
    usuario * d = firstTreeMap(cuentas);
    while(d!= NULL){
        printf("%s,%s,%s,%s,%lu,%s\n",d->nombre,d->apellido,d->id,d->tarjeta->numero, d->tarjeta->saldo, d->password);
        d = nextTreeMap(cuentas);
    }
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
    system("cls");
    FILE *lectura;
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,2);printf("***INSTRUCCIONES***");
        gotoxy(2,3);printf(BLANCO_F NEGRO_T " -TRAGAMONEDAS" NEGRO_F BLANCO_T);
        gotoxy(2,4);printf(" -RULETA");
        gotoxy(2,5);printf(" -CRAPS");
        gotoxy(2,6);printf(" -BLACKJACK");
        gotoxy(2,7);printf(" -KENO");
        gotoxy(2,8);printf(" -ROJO Y AZUL");
        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
        do{
            key = getch();
            switch(key){
                case 72: if (pos == 0)
                        pos = 7;
                        else pos--;
                        break;
                case 80: if (pos == 7) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(BLANCO_F NEGRO_T " -TRAGAMONEDAS" NEGRO_F BLANCO_T);
                        gotoxy(2,4);printf(" -RULETA");
                        gotoxy(2,5);printf(" -CRAPS");
                        gotoxy(2,6);printf(" -BLACKJACK");
                        gotoxy(2,7);printf(" -KENO");
                        gotoxy(2,8);printf(" -ROJO Y AZUL");
                        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
                        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(" -TRAGAMONEDAS");
                        gotoxy(2,4);printf(BLANCO_F NEGRO_T " -RULETA" NEGRO_F BLANCO_T);;
                        gotoxy(2,5);printf(" -CRAPS");
                        gotoxy(2,6);printf(" -BLACKJACK");
                        gotoxy(2,7);printf(" -KENO");
                        gotoxy(2,8);printf(" -ROJO Y AZUL");
                        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
                        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
                        flag1=1;
                        break;

                case 2:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(" -TRAGAMONEDAS");
                        gotoxy(2,4);printf(" -RULETA");
                        gotoxy(2,5);printf(BLANCO_F NEGRO_T " -CRAPS" NEGRO_F BLANCO_T);;
                        gotoxy(2,6);printf(" -BLACKJACK");
                        gotoxy(2,7);printf(" -KENO");
                        gotoxy(2,8);printf(" -ROJO Y AZUL");
                        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
                        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(" -TRAGAMONEDAS");
                        gotoxy(2,4);printf(" -RULETA");
                        gotoxy(2,5);printf(" -CRAPS");
                        gotoxy(2,6);printf(BLANCO_F NEGRO_T " -BLACKJACK" NEGRO_F BLANCO_T);
                        gotoxy(2,7);printf(" -KENO");
                        gotoxy(2,8);printf(" -ROJO Y AZUL");
                        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
                        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(" -TRAGAMONEDAS");
                        gotoxy(2,4);printf(" -RULETA");
                        gotoxy(2,5);printf(" -CRAPS");
                        gotoxy(2,6);printf(" -BLACKJACK");
                        gotoxy(2,7);printf(BLANCO_F NEGRO_T " -KENO" NEGRO_F BLANCO_T);
                        gotoxy(2,8);printf(" -ROJO Y AZUL");
                        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
                        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(" -TRAGAMONEDAS");
                        gotoxy(2,4);printf(" -RULETA");
                        gotoxy(2,5);printf(" -CRAPS");
                        gotoxy(2,6);printf(" -BLACKJACK");
                        gotoxy(2,7);printf(" -KENO" );
                        gotoxy(2,8);printf(BLANCO_F NEGRO_T " -ROJO Y AZUL" NEGRO_F BLANCO_T);
                        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
                        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
                        flag1=5;
                        break;
                case 6:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(" -TRAGAMONEDAS");
                        gotoxy(2,4);printf(" -RULETA");
                        gotoxy(2,5);printf(" -CRAPS");
                        gotoxy(2,6);printf(" -BLACKJACK");
                        gotoxy(2,7);printf(" -KENO" );
                        gotoxy(2,8);printf(" -ROJO Y AZUL");
                        gotoxy(2,9);printf(BLANCO_F NEGRO_T " -ADIVINA LA CARTA" NEGRO_F BLANCO_T);
                        gotoxy(2,10);printf(" -VOLVER AL MENU PRINCIPAL");
                        flag1=6;
                        break;
                case 7:
                        gotoxy(5,2);printf("***INSTRUCCIONES***");
                        gotoxy(2,3);printf(" -TRAGAMONEDAS");
                        gotoxy(2,4);printf(" -RULETA");
                        gotoxy(2,5);printf(" -CRAPS");
                        gotoxy(2,6);printf(" -BLACKJACK");
                        gotoxy(2,7);printf(" -KENO" );
                        gotoxy(2,8);printf(" -ROJO Y AZUL");
                        gotoxy(2,9);printf(" -ADIVINA LA CARTA");
                        gotoxy(2,10);printf(BLANCO_F NEGRO_T " -VOLVER AL MENU PRINCIPAL" NEGRO_F BLANCO_T);
                        flag1=7;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: break;
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: printf("\n\n"); infoRojoAzul(lectura); system("pause"); system("cls"); break;
            case 6: break;
            case 7: menu(); terminar_programa = 1; break;
        }

    }while(terminar_programa != 1);

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

void gotoxy(int x , int y){

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);

}
