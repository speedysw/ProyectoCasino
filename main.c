#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include "hashmap.h"
#include <windows.h>
#include <stdbool.h>
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
    unsigned long saldoT;
    unsigned long saldoJ;
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

deportes *createDeportes(){ // Funcion para asignarle memoria dinamica a la struc
    deportes *aux = (deportes *) malloc(sizeof(deportes)*40);
    aux->nombre = (char *) malloc(sizeof(char) * 25);
    aux->pais = (char *) malloc(sizeof(char) * 15);
    return aux;
}

usuario *createLogin() { // Funcion para signarle memoria dinamica al a struct
    usuario *aux = (usuario *) malloc(sizeof(usuario)*100);
    aux->nombre = (char *) malloc(sizeof(char) * 20);
    aux->apellido = (char *) malloc(sizeof(char) * 20);
    aux->id = (char *) malloc(sizeof(char) * 20);
    aux->password = (char *) malloc(sizeof(char) * 20);
    aux->tarjeta = (credito *) malloc(sizeof(credito)*100);
    aux->tarjeta->numero = (char *) malloc(sizeof(char) * 20);
    return aux;
}

typedef struct {
    int numero;
    char *pinta;
} Baraja;

void *createBaraja() { // funcion para asignarle memoria dinamica a la struct
    Baraja *baraja = (Baraja *) malloc(sizeof(Baraja));
    baraja->pinta = (char *) malloc(sizeof(char)* 8);
    return baraja;
}

Baraja *crearMazo(){ //Funcion para asignarle memoria dinamicamente a la struct
    Baraja *aux = (Baraja *) malloc(sizeof(Baraja)); //Con un malloc vamos asignando espacio a la struct mediante vayamos necesitando
    aux->pinta = (char *) malloc(sizeof(char) * 20);
    return aux;
}

void menu();
void instrucciones();
void infoRojoAzul(FILE *);
void infoCraps(FILE *);
void infoAdivinaCarta(FILE *);
void infoRuleta(FILE *);
void infoBlackJack(FILE *);
void infoKeno(FILE *);
void infoTragaMonedas(FILE *);
int seguridad(usuario *);
void respaldo(usuario *);
void exportar(HashMap *, usuario *);
const char *get_csv_field (char *, int);
void importar(HashMap *, usuario *);
void registrarse(HashMap *);
void iniciarSesion(HashMap *);
void gotoxy(int x , int y);
void menuIniciarSesion(usuario *);
void juegos(usuario *);
void apuestas(usuario *);
char *contrasena();
void retirarSaldo(usuario *);
void ingresarSaldo(usuario *);
void exportar2(usuario *);
void tragamonedasPorDiversion();
void jugarPorDiversion();
void maquinaDiversion();

void ruletaDiversionMenu();
void resultadoDiversion(int , int );
void ruletaDiversion(int );



//FUNCIONES JUEGOS Y CASA DE APUESTA

//funciones tragamonedas
void tragamonedas(usuario *);
void menuTragamonedas(usuario *);
void tituloTragamonedas();
void maquinaTragamonedas(int , usuario *);
void sieteRojo(int);
void limon(int);
void manzana(int);
void ciruela(int);
void uva(int);
void cereza(int);
// fin tragamoendas

//funciones Keno
void keno(usuario *);
void menuKeno(usuario *);
void recompensaKeno();
void generarA(HashMap *, int);
void generarM(HashMap *, int);
void correctas(HashMap *, HashMap *, HashMap *);
void escribirCorrectas(HashMap *, HashMap *, float, usuario*);
void escribirApuesta(HashMap *);
// fin keno

//funciones BlackJack
void blackJack(usuario *);
void menuBlackJack(usuario *);
void tituloBlackJack();
void barajaAleatoria(HashMap *);
int sacarCarta(HashMap *, int);
void generarCarta(int *, char *, HashMap *);
// fin keno

//funciones RojoAzul
void azulyrojo(usuario *);
void menuAzulRojo(usuario *);
void tituloAzulRojo();
// fin azulyrojo

//funciones Ruleta
void tituloruleta();
void menuRuleta(usuario *);
void ruletaMenu(usuario *);
void ruleta(int, int, usuario *);
void resultado(int, int, int, usuario *);
// fin ruleta

//Funciones Adivina Carta

void menuAdivinaCarta(usuario *);
void llenarMapa(HashMap *); //Funcion para insertar datos en el mapa que contendra los nombres de las cartas
void tituloAdivinaCarta();//Funcion para mostrar el titulo de la aplicacion por pantalla
void carta(HashMap *, usuario *);

//FIN ADIVINA CARTA

//FUNCIONES CRAPS
void tituloCraps();//Funcion para mostrar el titulo de la aplicacion
void menuCraps(usuario *);//Funcion para acceder al menu de la aplicacion
void crapsMenu(usuario *); //Funcion para escoger las opciones de apuesta del craps
void craps(int,int,int, usuario *); //Funcion que da los resultados y revuelve los dados

// Funciones Casa de Apuestas

void importarATP(HashMap *);
void importarFormula(HashMap *);
void importarNBA(HashMap *);
void importarFutbol(HashMap *);
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

// FIN CASA DE APUESTAS

int main(){
    menu();
    return 0;
}

void menu(){
    system("cls");
    HashMap* cuentas = createMap(20);
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
        gotoxy(2,7);printf(" -SALIR [2 veces para confirmar]");
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
                        gotoxy(2,7);printf(" -SALIR [2 veces para confirmar]");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(BLANCO_F NEGRO_T " -REGISTRARSE" NEGRO_F BLANCO_T);
                        gotoxy(2,5);printf(" -JUGAR POR DIVERSION");
                        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
                        gotoxy(2,7);printf(" -SALIR [2 veces para confirmar]");
                        flag1=1;
                        break;

                case 2:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRARSE");
                        gotoxy(2,5);printf(BLANCO_F NEGRO_T " -JUGAR POR DIVERSION" NEGRO_F BLANCO_T);
                        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
                        gotoxy(2,7);printf(" -SALIR [2 veces para confirmar]");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRARSE");
                        gotoxy(2,5);printf(" -JUGAR POR DIVERSION" );
                        gotoxy(2,6);printf(BLANCO_F NEGRO_T " -NUEVO EN EL CASINO?" NEGRO_F BLANCO_T);
                        gotoxy(2,7);printf(" -SALIR [2 veces para confirmar]");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,2);printf("***CASINO TIME LIMIT EXCEEDED EDITION***");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRARSE");
                        gotoxy(2,5);printf(" -JUGAR POR DIVERSION" );
                        gotoxy(2,6);printf(" -NUEVO EN EL CASINO?");
                        gotoxy(2,7);printf(BLANCO_F NEGRO_T " -SALIR [2 veces para confirmar]" NEGRO_F BLANCO_T);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: iniciarSesion(cuentas); break; //Iniciar Sesion
            case 1: registrarse(cuentas); break; //Registrarse
            case 2: jugarPorDiversion(); break; //Jugar por diversion
            case 3: instrucciones(); break; //Nuevo en el casino?
            case 4: terminar_programa=1; break;//Salir
        }
    }while(terminar_programa != 1);
}

// En esta funcion el jugador se va a registrar en la aplicación
void registrarse(HashMap * cuentas){
    system("cls");
    usuario* login = createLogin(login); // Se crea el vector donde estara el usuario
    char* aux = (char *) malloc(sizeof(char) * 20); // Se declara una variable de tipo char aux que nos servira para comparar las contraseñas
    int comprobar=0; // Esta variable se usara para salir del int
    // Se escanean los datos que se le van pidiendo en pantalla al usuario
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
    respaldo(login); // En esta funcion se comprubea si el nombre de usuario se encuentra disponible o no
    do{
        printf("Ejemplo: 4678 9845 0923 XXXX \n");
        printf("Inserte tarjeta de credito: ");
        scanf("%[^\n]",login->tarjeta->numero);
        fflush(stdin);
        int x = strlen(login->tarjeta->numero); // Se saca el largo de la variable login->tarjeta->numero para comprobar si la tarjeta es valida o no
        if(x < 19 || x > 19) printf("TARJETA INVALIDA\n");
        if(x == 19){
         comprobar = 1; // si es valida saldra del while
        }
        // se le asignan un valor fijo al saldo total de la tarjeta y al saldo de juego
        login->tarjeta->saldoT = 1000000; // saldo total
        login->tarjeta->saldoJ = 0; // saldo juego
    }while(comprobar == 0);

    do{
        comprobar = 0;
        printf("Contrasena: ");
        login->password = contrasena(); // la funcion contrasena se encarga de ponerle **** a la password
        printf("\n");

        printf("Confirmar contrasena: ");
        aux = contrasena();
        printf("\n");

        if(strcmp(login->password,aux) == 0){ // si las contraseñas son iguales entrara a este if para comprobar su seguridad
            comprobar = seguridad(login); // la funcion seguridad retornara 1 si la contraseña cumple con los requisitos de seguridad
            aux = login->password; //se guarda el valor de la llave
        }

        if(strcmp(login->password,aux) != 0) printf("LAS CONTRASEÑAS NO COINCIDEN INTENTELO DENUEVO\n"); // si no coninciden las contras se repitira el proceso de la contraseña

    }while(comprobar == 0);
    system("cls");
    // aca se comprueba nuevamente si la contraseña con el aux coinciden
    if(strcmp(login->password,aux) == 0){
        printf("%s %s fue registrado con exito en nuestra aplicacion, su cuenta es la siguiente: \n", login->nombre, login->apellido);
        printf("Nombre de usuario de la cuenta: %s\n", login->id);
        printf("Clave de la cuenta: %s\n", login->password);
        printf("Tarjeta de credito: ");
        for(int i = 0 ; i < 15 ; i++){
            printf("%c", login->tarjeta->numero[i]);
        }
        printf("XXXX\n");
        printf("Este es el saldo de su tarjeta: %lu\n", login->tarjeta->saldoT);
        printf("BIENVENIDO AL CASINO TIME LIMTID EXCEEDED EDITION!!\n");
    }
    insertMap(cuentas, login->id, login); // se inserta en el mapa cuentas el usuario con key = nombre de usuario;
    exportar(cuentas, login); // se manda a la funcion exportar para que se genere un archivo con el usuario
    system("pause");
    system("cls");

}
// Funcion donde se exporta el usuario
void exportar(HashMap * cuentas, usuario * login){
    FILE *datos;
    char nombreArchivo[23]; // Se asigna una variable char que se le dara el nombre de usuario
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s%s", login->id, ".csv"); // se crea el archivo con el nombre de usuario del jugador

    datos = fopen(nombreArchivo,"w"); // se abre el archivo

    usuario *d = (usuario *) malloc(sizeof(usuario)* 1); // se genera un vector de tipo usuario
    // se recorre el mapa y se va insertando en el archivo
    d = firstMap(cuentas);
    char line[100];
    while(d != NULL){
        snprintf(line, sizeof(line), "%s,%s,%s,%s,%lu,%lu,%s\n",d->nombre,d->apellido,d->id,d->tarjeta->numero,d->tarjeta->saldoT,d->tarjeta->saldoJ,d->password);
        fputs(line, datos);
        d = nextMap(cuentas);
    }
    fclose(datos); // cuando se inserte todo en el archivo, se cerrara dicho archivo.
}

// Funcion para iniciar sesion del usuario
void iniciarSesion(HashMap * cuentas){
    system("cls");
    // se crea dos variables de tipo usuarios que nos serviran para comparar en el ingreso de sesion
    usuario * aux = createLogin(aux);
    usuario * aux2 = createLogin(aux2);
    printf("--------------------INICIO DE SESION--------------------\n");
    printf("BIENVENIDO DEVUELTA AL TIME LIMITD EXCEEDED\n");
    printf("Nombre de usuario: ");
    scanf("%s", aux->id);
    strcpy(aux2->id,aux->id); // se copia el nombre de usuario en el segundo aux2
    fflush(stdin);
    printf("Contraseña: ");
    aux2->password = contrasena(); // se escribe la contraseña de la cuenta con **
    printf("\n");
    importar(cuentas,aux); // se importa un archivo.csv con el nombre de usuario
    aux = searchMap(cuentas, aux2->id); // si al aux se le asigna el valor del mapa significa que se leyo el archivo con exito

    // Si la contraseña no coinciden se entrara en su if y se repetira todo el proceso, en caso contrario el usuario habra ingresado a la aplicacion
    if(strcmp(aux->id,aux2->id) == 0 && strcmp(aux->password,aux2->password) == 0) printf("EL USUARIO HA INGRESADO CON EXITO, BIEN\n");
    if(strcmp(aux->id,aux2->id) != 0 || strcmp(aux->password,aux2->password) != 0){
        printf("Ups, el usuario o la contraseña no coinciden, vuelve a intentarlo\n");
        system("pause");
        iniciarSesion(cuentas);
    }
    system("pause");
    system("cls");

    menuIniciarSesion(aux); // te manda al menu del casino
}

int seguridad(usuario * login){
   /* En esta funcion se comprueba si la contraseña es segura o no mediante la cantidad de caracteres que
   esta contenga, si es segura se retorna un 1 para que en la funcion donde se llame pueda salir de su ciclo
   repetitivo con exito*/

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

// Funcion donde se importa el usuario creado por el jugador
void importar(HashMap* cuentas, usuario* lectura){
    FILE* archivo;
    char nombreArchivo[23]; // Al igual que en el exportar se crea una variable char que nos servira para abrir el archivo
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s%s", lectura->id, ".csv"); // se le asigna a la variable char el nombre del archivo
    archivo = fopen(nombreArchivo,"r"); // se abre el archivo
    if(archivo == NULL){ // si el archivo no existe mandara un mensaje en pantalla y se mandara al menu principal de la aplicación
        printf("Ups, el usuario o la contraseña no coinciden, vuelve a intentarlo\n");
        system("pause");
        menu();
        exit(EXIT_SUCCESS);
    }

    // en este ciclo while se lee el archivo con linea
    char line[100];
    while(fgets(line,100,archivo) != NULL){
        lectura->nombre = (char *)get_csv_field(line,0);
        lectura->apellido = (char *)get_csv_field(line,1);
        lectura->id = (char *)get_csv_field(line,2);
        lectura->tarjeta->numero = (char *)get_csv_field(line,3);
        lectura->tarjeta->saldoT = atoi(get_csv_field(line,4));
        lectura->tarjeta->saldoJ = atoi(get_csv_field(line,5));
        lectura->password = (char *) get_csv_field(line,6);
    }
    // se inserta en el mapa cuenta los datos del archivo con key = nombre de usuario
    insertMap(cuentas, lectura->id, lectura);
    usuario * d = firstMap(cuentas);
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

// Esta funcion se encarga de comprobar si un nombre de usuario se encuentra disponible o no
void respaldo(usuario * login){
    FILE *Datos;
    // se hace el mismo proceso que en el importar y exportar en el nombre de archivo
    char nombreArchivo[23];
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s%s", login->id, ".csv");
    Datos = fopen(nombreArchivo,"r"); // se abre el archivo
    //si el archivo no existe significa que el nombre de usuario esta disponible, de lo contrario esta ocupado
    if(Datos == NULL){
        printf("El nombre de usuario no existe\n");
    }
    if(Datos != NULL){
        // Si el nombre de usuario no esta disponible, el usuario tendra que escoger otro
        printf("Nombre de usuario no disponible, seleccione otro porfavor\n");
        printf("Nombre de usuario: ");
        scanf("%s", login->id);
        fflush(stdin);
        respaldo(login);
    }
    //fclose(Datos);
    //free(Datos);
}
// esta funcion dependiendo de la opcion leera distintos archivos de texto
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
            case 0: printf("\n\n"); infoTragaMonedas(lectura); system("pause"); system("cls"); break;
            case 1: printf("\n\n"); infoRuleta(lectura); system("pause"); system("cls");break;
            case 2: printf("\n\n"); infoCraps(lectura); system("pause"); system("cls");break;
            case 3: printf("\n\n"); infoBlackJack(lectura); system("pause"); system("cls");break;
            case 4: printf("\n\n"); infoKeno(lectura); system("pause"); system("cls");break;
            case 5: printf("\n\n"); infoRojoAzul(lectura); system("pause"); system("cls"); break;
            case 6: printf("\n\n"); infoAdivinaCarta(lectura); system("pause"); system("cls");break;
            case 7: menu(); terminar_programa = 1; break;
        }

    }while(terminar_programa != 1);

}

// De las funciones infoCraps a infoRojoAzul se lee un archivo de texto
void infoCraps(FILE *lectura){ //Info craps
    system("cls");
    tituloCraps();
    lectura = fopen("Craps.txt", "rb");
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

void infoAdivinaCarta(FILE *lectura){ //Info adivina carta
    system("cls");
    tituloAdivinaCarta();
    lectura = fopen("AdivinaCarta.txt", "rb");
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

void infoRuleta(FILE *lectura){ //Info ruleta
    system("cls");
    tituloruleta();
    lectura = fopen("Ruleta.txt", "rb");
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

void infoBlackJack(FILE *lectura){ //Info Blackjack
    system("cls");
    tituloBlackJack();
    lectura = fopen("Blackjack.txt", "rb");
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

void infoKeno(FILE *lectura){ //Info Keno
    system("cls");

        char asterisco[2];
        strcpy(asterisco,"*");
        printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("%s%44s\n",asterisco,asterisco);
        printf("%s" CYAN_T "                   KENO" RESET_COLOR"%21s\n",asterisco,asterisco);
        printf("%s%44s\n",asterisco,asterisco);
        printf("* * * * * * * * * * * * * * * * * * * * * * *\n");

    lectura = fopen("Keno.txt", "rb");
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

void infoTragaMonedas(FILE *lectura){ //Primera info traga monedas
    system("cls");
    tituloTragamonedas();
    lectura = fopen("Tragamonedas.txt", "rb");
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

void infoRojoAzul(FILE *lectura){
    system("cls");
    tituloAzulRojo();
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

// funcion para la interfaz del programa
void gotoxy(int x , int y){

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);

}

// Funcion que te dejara ingresar a las distintas opciones del casino
void menuIniciarSesion(usuario *cuenta) {
    system("cls");

    int pos,end,flag1=0,terminar_programa=0;
    char key;
    do{
    pos = 0;
    end = 0;
        gotoxy(1,1);printf("*** MENU ***");
        gotoxy(1,2);printf(BLANCO_F NEGRO_T " - Retirar dinero a mi tarjeta" NEGRO_F BLANCO_T);
        gotoxy(1,3);printf(" - Ingresar dinero al casino");
        gotoxy(1,4);printf(" - Juegos");
        gotoxy(1,5);printf(" - Apuestas deportivas");
        gotoxy(1,6);printf(" - Cerrar sesion");
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
                        gotoxy(1,1);printf("*** MENU ***");
                        gotoxy(1,2);printf(BLANCO_F NEGRO_T " - Retirar dinero a mi tarjeta" NEGRO_F BLANCO_T);
                        gotoxy(1,3);printf(" - Ingresar dinero al casino");
                        gotoxy(1,4);printf(" - Juegos");
                        gotoxy(1,5);printf(" - Apuestas deportivas");
                        gotoxy(1,6);printf(" - Cerrar sesion");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,1);printf("*** MENU ***");
                        gotoxy(1,2);printf(" - Retirar dinero a mi tarjeta");
                        gotoxy(1,3);printf(BLANCO_F NEGRO_T " - Ingresar dinero al casino" NEGRO_F BLANCO_T);
                        gotoxy(1,4);printf(" - Juegos");
                        gotoxy(1,5);printf(" - Apuestas deportivas");
                        gotoxy(1,6);printf(" - Cerrar sesion");
                        flag1=1;
                        break;

                case 2:
                        gotoxy(1,1);printf("*** MENU ***");
                        gotoxy(1,2);printf(" - Retirar dinero a mi tarjeta");
                        gotoxy(1,3);printf(" - Ingresar dinero al casino" );
                        gotoxy(1,4);printf(BLANCO_F NEGRO_T " - Juegos" NEGRO_F BLANCO_T);
                        gotoxy(1,5);printf(" - Apuestas deportivas");
                        gotoxy(1,6);printf(" - Cerrar sesion");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(1,1);printf("*** MENU ***");
                        gotoxy(1,2);printf(" - Retirar dinero a mi tarjeta");
                        gotoxy(1,3);printf(" - Ingresar dinero al casino");
                        gotoxy(1,4);printf(" - Juegos");
                        gotoxy(1,5);printf(BLANCO_F NEGRO_T " - Apuestas deportivas" NEGRO_F BLANCO_T);
                        gotoxy(1,6);printf(" - Cerrar sesion");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(1,1);printf("*** MENU ***");
                        gotoxy(1,2);printf(" - Retirar dinero a mi tarjeta");
                        gotoxy(1,3);printf(" - Ingresar dinero al casino");
                        gotoxy(1,4);printf(" - Juegos");
                        gotoxy(1,5);printf(" - Apuestas deportivas");
                        gotoxy(1,6);printf(BLANCO_F NEGRO_T " - Cerrar sesion" NEGRO_F BLANCO_T);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: ingresarSaldo(cuenta); terminar_programa=1; break; // Ingresa dinero a tu tarjeta de credito
            case 1: retirarSaldo(cuenta); terminar_programa=1; break; // Saca dinero de tu tarjeta de credito
            case 2: juegos(cuenta); terminar_programa=1; break;
            case 3: apuestas(cuenta); terminar_programa=1; break;
            case 4: exportar2(cuenta); menu(); terminar_programa=1; break;
        }
    }while(terminar_programa != 1);

    system("cls");
}

/* funcion que cumple el mismo proposito que el exportar anteriormente explicado, pero
este nos servira para guardar el proceso del jugador en la aplicacion
(se sobreeescribe el archivo anteriormente guardado)*/
void exportar2(usuario * login){
    // El mismo procedimiento que en el anterior exportar, con la diferencia de que aqui solo se mandara al tipo de dato usuario y se crea el mismo mapa cuentas
    HashMap* cuenta = createMap(4);
    insertMap(cuenta,login->id,login);
    FILE *datos;
    char nombreArchivo[23];
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s%s", login->id, ".csv");

    datos = fopen(nombreArchivo,"w");

    usuario *d = (usuario *) malloc(sizeof(usuario)* 1);
    d = firstMap(cuenta);
    char line[100];
    while(d != NULL){
        snprintf(line, sizeof(line), "%s,%s,%s,%s,%lu,%lu,%s\n",d->nombre,d->apellido,d->id,d->tarjeta->numero,d->tarjeta->saldoT,d->tarjeta->saldoJ,d->password);
        fputs(line, datos);
        d = nextMap(cuenta);
    }
    fclose(datos);
}

// En esta funcion el usuario puede ingresar el dinero de la aplicacion a su tarjeta de credito
void ingresarSaldo(usuario* cuenta){
    system("cls");
    printf("SALDO ACTUAL EN LA APLICACION: %lu\n",cuenta->tarjeta->saldoJ);
    printf("SALDO EN LA TARJETA DE CREDITO: %lu\n", cuenta->tarjeta->saldoT);
    printf("INDIQUE LA CANTIDAD DE SALDO QUE QUIERE RETIRAR HACIA SU TARJETA DE CREDITO / SI NO TIENE SALDO INGRESE 0\n");
    unsigned long saldo;
    // Este ciclo while es para que corresponda el saldo retirado con el de la aplicacion
    do{
        gotoxy(0,3);scanf("%i",&saldo);
        if(cuenta->tarjeta->saldoJ < saldo){
            printf("El saldo que indico excede al saldo que tiene en su tarjeta de credito\n");
            system("pause");
            gotoxy(0,4);printf("                                                                       ");
            gotoxy(0,3);printf("                                                                      ");
            gotoxy(0,5);printf("                                                                      ");
        }
    }while(cuenta->tarjeta->saldoJ < saldo);

    cuenta->tarjeta->saldoJ = cuenta->tarjeta->saldoJ - saldo;
    cuenta->tarjeta->saldoT = cuenta->tarjeta->saldoT + saldo;
    printf("SALDO ACTUALIZADO DE LA TARJETA DE CREDITO: %lu\n", cuenta->tarjeta->saldoT);
    printf("SALDO ACTUAL EN LA APLICACION: %lu\n", cuenta->tarjeta->saldoJ);

    int pos,end,flag1=0,terminar_programa=0;
    char key;
    int respuesta;
    do{
    pos = 0;
    end = 0;
        gotoxy(1,7);printf("¿DESEA RETIRAR MAS SALDO?\n");
        gotoxy(1,8);printf(BLANCO_F NEGRO_T " - RETIRAR MAS SALDO" NEGRO_F BLANCO_T);
        gotoxy(1,9);printf(" - VOLVER AL MENU DE LA CUENTA");
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
                        gotoxy(1,7);printf("¿DESEA RETIRAR MAS SALDO?\n");
                        gotoxy(1,8);printf(BLANCO_F NEGRO_T " - RETIRAR MAS SALDO" NEGRO_F BLANCO_T);
                        gotoxy(1,9);printf(" - VOLVER AL MENU DE LA CUENTA");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,7);printf("¿DESEA RETIRAR MAS SALDO?\n");
                        gotoxy(1,8);printf(" - RETIRAR MAS SALDO");
                        gotoxy(1,9);printf(BLANCO_F NEGRO_T " - VOLVER AL MENU DE LA CUENTA" NEGRO_F BLANCO_T);
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
        system("cls");
        ingresarSaldo(cuenta);
    }

    if(respuesta == 2){
        system("cls");
        menuIniciarSesion(cuenta);
    }
}

// En esta funcion el usuario puede ingresar el dinero de su tarjeta de credito a la aplicacion
void retirarSaldo(usuario *cuenta){
    system("cls");
    printf("SALDO DISPONIBLE EN SU TARJETA DE CREDITO: %lu\n", cuenta->tarjeta->saldoT);
    printf("SALDO ACTUAL EN LA APLICACION: %lu\n", cuenta->tarjeta->saldoJ);
    printf("INDIQUE EL NUMERO DE SALDO A RETIRAR DE SU TARJETA DE CREDITO / SI NO TIENE SALDO INGRESE 0\n");
    unsigned long saldo;
    // Este ciclo while es para que corresponda el saldo ingresado a la aplicacion con el de la tarjeta
    do{
        gotoxy(0,3);scanf("%i",&saldo);
        if(cuenta->tarjeta->saldoT < saldo){
            printf("El saldo que indico excede al saldo que tiene en su tarjeta de credito\n");
            system("pause");
            gotoxy(0,4);printf("                                                                       ");
            gotoxy(0,3);printf("                                                                      ");
            gotoxy(0,5);printf("                                                                      ");

        }
    }while(cuenta->tarjeta->saldoT < saldo);

    cuenta->tarjeta->saldoJ = cuenta->tarjeta->saldoJ + saldo;
    cuenta->tarjeta->saldoT = cuenta->tarjeta->saldoT - saldo;

    printf("SALDO DISPONIBLE EN SU TARJETA DE CREDITO: %lu\n", cuenta->tarjeta->saldoT);
    printf("SALDO ACTUAL EN LA APLICACION: %lu\n", cuenta->tarjeta->saldoJ);
    int pos,end,flag1=0,terminar_programa=0;
    char key;
    int respuesta;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,7);printf("¿DESEA RETIRAR MAS SALDO?\n");
        gotoxy(1,8);printf(BLANCO_F NEGRO_T " - RETIRAR MAS SALDO" NEGRO_F BLANCO_T);
        gotoxy(1,9);printf(" - VOLVER AL MENU DE LA CUENTA");
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
                        gotoxy(1,7);printf("¿DESEA RETIRAR MAS SALDO?\n");
                        gotoxy(1,8);printf(BLANCO_F NEGRO_T " - RETIRAR MAS SALDO" NEGRO_F BLANCO_T);
                        gotoxy(1,9);printf(" - VOLVER AL MENU DE LA CUENTA");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,7);printf("¿DESEA RETIRAR MAS SALDO?\n");
                        gotoxy(1,8);printf(" - RETIRAR MAS SALDO");
                        gotoxy(1,9);printf(BLANCO_F NEGRO_T " - VOLVER AL MENU DE LA CUENTA" NEGRO_F BLANCO_T);
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
        system("cls");
        retirarSaldo(cuenta);
    }

    if(respuesta == 2){
        system("cls");
        menuIniciarSesion(cuenta);
    }
}

//menu de las apuestas deportivas
void apuestas(usuario *cuenta){
    system("cls");
    int a = 1;
    gotoxy(1,8);printf("este es tu saldo: %lu",cuenta->tarjeta->saldoJ);
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
                case 0: apuestasFutbol(cuenta); terminar_programa=1; break;
                case 1: apuestasNBA(cuenta); terminar_programa=1; break;
                case 2: apuestasTennis(cuenta); terminar_programa=1; break;
                case 3: apuestasFormula1(cuenta); terminar_programa=1; break;
                case 4: menuIniciarSesion(cuenta); terminar_programa=1; break;
            }
        }while(terminar_programa != 1);
        return 0;
    }
}

// COMIENZO DE LAS FUNCIOENS DE LA CASA DE APUESTA

//Funcion que genera la apuesta de tennis
void apuestasTennis(usuario * cuenta){
    int aux = 10 + 10 * 0.3; // este valor siempre es fijo
    HashMap *mapDeportes = createMap(aux); // se crea un mapa con el espacio del aux
    importarATP(mapDeportes); // se importan los datos de un archivo.csv
    /*deportes *d = firstMap(mapDeportes);
    while(d != NULL){
        printf("| %20s | %15s | %16.2f |\n", d->nombre, d->pais, d->multiplicador);
    d = nextMap(mapDeportes);
    }*/
    encuentrosATP(mapDeportes, cuenta); // aqui se van generando los encuentros de tennis, mediante los datos leidos del archivo
}

// Funcion que genera los encuentros de las apuestas
void encuentrosATP(HashMap* mapDeportes, usuario * cuenta){
    /* En esta funcion se crean dos variables int llamadas "sorteo" y "sorteo1" que iran sorteando mediante un random
    numeros del 1 al valor del aux, estos valores se buscaran en el mapa Deportes ya que este contendra a los tenistas
    luego de encontrar los valores del mapa deportes, se cambiara la key (primera key sera el numero de ingreso al mapa y
    la segunda llave corresponde al nombre del tenista, esto con el fin de que no se puedan repetir los tenistas)
    despues de realizar esto se mostraran los encuentros uno por uno, despues de que se genera un encuentro
    el usuario tendra tres opciones, apostar, pasar al siguiente encuentro y volver al menu de las apuestas */

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
        while(searchMap(mapDeportes,&sorteo) == NULL){ // Si no se encuentra nada en el mapa el random soltara otro numero
                sorteo = rand () % aux + 1;
        }
        while(searchMap(mapDeportes,&sorteo1) == NULL){
                sorteo1 = rand() % aux + 1;
        }
        if(sorteo != sorteo1){ // para los encuentros ambas variables tienen que ser distintas para que no se enfrente el mismo tenista con el mismo
            int respuesta;
            // aqui se realiza el cambio de llave y la busqueda en el mapa
            deportes *d = searchMap(mapDeportes, &sorteo);
            deportes *x = searchMap(mapDeportes, &sorteo1);
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

            if(respuesta == 1){ // en este if el usuario podra escoger a quien apostarle
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
                escogerApuesta(cuenta,d,x,escogido); // en esta funcion se hace el proceso de apuesta
            }
            if(respuesta == 3) break; // aqui termina el ciclo y se vuelve al menu del casino
            cont++;
        }
    }
    system("cls");
    printf("Este es tu saldo actual: %lu CLP\n", cuenta->tarjeta->saldoJ); // se muestra el saldo despues de realizar las apuestas
    // Lo que continua con el codigo tiene que ver si esque desea generar nuevamente encuentros desde el comienzo (repitiendo todo el ciclo) o volver al menu de apuestas
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
    if(respuesta == 1) apuestas(cuenta);
    if(respuesta == 2){
        free(mapDeportes);
        apuestasTennis(cuenta);
    }
}

// Se importan los datos de las apuestas de Tenis
void importarATP(HashMap *mapDeportes){
    FILE* archivo;
    archivo = fopen("ATP.csv","r");
    if(archivo == NULL){ // Comprobacion por si el archivo no se encuentra
        printf("El archivo no se abrio correctamente\n");
        return exit(1);
    }
    // Se importa de la misma manera que la funcion importar explicada anteriormente
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
    // Se va insertando lso valores del archivo en el mapaDeportes
    int cont = i;
    for(i=0 ; i < cont ; i++){
        insertMap(mapDeportes,&datos[i].clave,&datos[i]);
    }
}

// Esta funcion realiza el mismo procedimiento que apuestasATP, genera las apuestas de Formula 1
void apuestasFormula1(usuario * cuenta){
    int aux = 12 + 10 * 0.3; // valor siempre fijo
    HashMap *mapDeportes = createMap(aux); // se crea nuevamente un mapa
    importarFormula(mapDeportes); // se importan los datos correspondiente del deportes mediante un archivo.csv
    deportes *d = firstMap(mapDeportes);
    while(d != NULL){
        printf("| %20s | %15s | %16.2f |\n", d->nombre, d->pais, d->multiplicador);
    d = nextMap(mapDeportes);
    }
    encuentrosF1(mapDeportes, cuenta); // se generan las carreras de F1
}
// En esta funcion se genera los encuentros y se apuesta
void encuentrosF1(HashMap * mapDeportes, usuario * cuenta){
    system("cls");
    int piloto;
    unsigned long apuesta;
    // se recorre el mapa para mostrar a todos los pilotos de la carrera
    deportes *d = firstMap(mapDeportes);
    printf("|                               FORMULA 1: GRAN PREMIO DE FRANCIA                             |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("|                     |         PILOTO       |    ESCUADRA     |   DORSAL  |   MULTIPLICADOR  |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    //
    while(d != NULL){
        printf("| Clasificacion: %4d | %20s | %15s | %9i | %16.2f |\n",d->clave, d->nombre, d->pais, d->ranking, d->multiplicador);
        d = nextMap(mapDeportes);
    }
    // Aqui se decide si el usuario desea apostar o no
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
    // Si el usuario apuesta podra seleccionar a su piloto y apostarle un dicho monto
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
        // se busca en el mapa si el piloto escogido existe
        deportes* aux = searchMap(mapDeportes, &piloto);
        printf("PILOTO ESCOGIDO: %s\n", aux->nombre);

        // En esta fraccion del codigo se selecciona el monto de la apuesta
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

        // En este if se comprubea si el saldo es ineficiente o no
        if(cuenta->tarjeta->saldoJ < apuesta){
            int seleccion;
            system("cls");
            printf("SALDO INEFICIENTE\n");
            printf("NO SE PUDO COMPLETAR SU APUESTA\n");
            printf("MARQUE 1 SI DESEA IR DIRECTAMENTE A INGRESAR SALDO\n");
            printf("MARQUE 2 SI DESEA VOLVER AL MENU DEL CASINO\n");
            scanf("%i",&seleccion);

            if(seleccion == 1){
                retirarSaldo(cuenta);
                exit(EXIT_SUCCESS);
            }

            if(seleccion == 2){
                apuestas(cuenta);
                exit(EXIT_SUCCESS);
            }
        }
        // Si el saldo es suficiente se le restara la apuesta al saldo de juego y se genera los resultados de la carrera mediante un random
        system("cls");
        printf("Realizaste una apuesta de %lu CLP por %s \n", apuesta, aux->nombre);
        cuenta->tarjeta->saldoJ -= apuesta;
        printf(" -------------------------------------------------------------------------------------------\n");

        srand(time(NULL));
        int cont=0;
        printf("|                         RESULTADO FORMULA 1: GRAN PREMIO DE FRANCIA                       |\n");
        printf(" -------------------------------------------------------------------------------------------\n");
        printf("|   CLASIFICACION   |         PILOTO       |    ESCUADRA     |   DORSAL  |   MULTIPLICADOR  |\n");
        printf(" -------------------------------------------------------------------------------------------\n");

        int i = 0;
        HashMap* Ganadores = createMap(4); // En este mapa se inserta la primera posicion de la carrera
        while(cont < 11){
            int posicion = rand() % 11 + 1;
            //printf("esta es la posicon %i\n", posicion);

            while(searchMap(mapDeportes,&posicion) == NULL){ // Si el mapa esta vacio generara otro numero
                    posicion = rand () % 11 + 1;
            }
            // se busca en el mapa y se muestra al piloto por pantalla
            deportes *ubicacion = searchMap(mapDeportes, &posicion);
            if(ubicacion != NULL){
                posicion = i + 1;
                printf("| Posicion: %7d | %20s | %15s | %9i | %16.2f |\n",posicion, ubicacion->nombre, ubicacion->pais, ubicacion->ranking, ubicacion->multiplicador);
                i++;
            }

            if(posicion == 1){ // el primer lugar se guarda en el mapa
                insertMap(Ganadores, &posicion, ubicacion);
            }

            eraseMap(mapDeportes, &ubicacion->clave); // se elimina la clave para que no se repita los pilotos
            cont++;
        }
        printf(" -------------------------------------------------------------------------------------------\n");
        printf("                                RESULTADOS DE LA APUESTA                                    \n");
        deportes* ganador = firstMap(Ganadores); // se crea una variable deportes que se encarga de comparar al apostado con el ganador
        // si el ganador y el aux coinciden significa que el usuario gano la apuesta, de lo contrario perdio
        if(strcmp(ganador->nombre, aux->nombre) == 0){
            printf("Ganador de la carrera: %s\n", ganador->nombre);
            printf("Ganaste la apuesta\n");
            unsigned long resultante = (ganador->multiplicador * apuesta);
            resultante = cuenta->tarjeta->saldoJ + resultante;
            cuenta->tarjeta->saldoJ += resultante;
            printf("Ganaste %lu CLP\n", resultante);
        }

        if(strcmp(ganador->nombre, aux->nombre) != 0){
            printf("Ganador de la carrera: %s\n", ganador->nombre);
            printf("Perdiste la apuesta\n");
        }

        printf("Este es tu saldo actual: %llu CLP\n", cuenta->tarjeta->saldoJ);
    }
    // en esta ultima fraccion se seleccionara si el usuario desea volver al menu o generar otra carrera
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
            apuestas(cuenta);
    }
    if(respuesta == 2){
        system("cls");
        free(mapDeportes);
        apuestasFormula1(cuenta);
    }

}

// Esta funcion hace el mismo procedimiento que el importarATP
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

// Funcion que hace el mismo procedimiento de las apuestas anteriores
void apuestasNBA(usuario * cuenta){
    int aux = 12 + 10 * 0.3; // valor fijo
    HashMap *mapDeportes = createMap(aux); // se crea el archivo
    importarNBA(mapDeportes); // se importa el archivo.csv
    deportes *d = firstMap(mapDeportes);
    while(d != NULL){
        printf("| %20s | %15s | %16.2f |\n", d->nombre, d->pais, d->multiplicador);
    d = nextMap(mapDeportes);
    }
    encuentrosNBA(mapDeportes, cuenta); // Se genera el encuentro
}

// Tiene la misma funcion que el encuentrosATP
void encuentrosNBA(HashMap *mapDeportes, usuario * cuenta){
    /* En esta funcion se crean dos variables int llamadas "sorteo" y "sorteo1" que iran sorteando mediante un random
    numeros del 1 al valor del aux, estos valores se buscaran en el mapa Deportes ya que este contendra a los tenistas
    luego de encontrar los valores del mapa deportes, se cambiara la key (primera key sera el numero de ingreso al mapa y
    la segunda llave corresponde al nombre del equipo, esto con el fin de que no se puedan repetir los equipo)
    despues de realizar esto se mostraran los encuentros uno por uno, despues de que se genera un encuentro
    el usuario tendra tres opciones, apostar, pasar al siguiente encuentro y volver al menu de las apuestas */

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

        // si son iguales se vuelve a sortear los numeros
        if(sorteo == sorteo1){
                sorteo = rand () % aux + 1; // 8
                sorteo1 = rand () % aux + 1; // 1
        }
        // se comprueba que los mapas contengan algo
        while(searchMap(mapDeportes,&sorteo) == NULL){
                sorteo = rand () % aux + 1;
        }

        while(searchMap(mapDeportes,&sorteo1) == NULL){
                sorteo1 = rand() % aux + 1;
        }

        if(sorteo != sorteo1){ // si son diferentes entrara aca
            int respuesta= 0;
            // cambio de clave
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
            // Aca se le pregunta al usuario que desea hacer, si apostar, generar otro encuentro o terminar la apuesta
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
            // si el usuario escgio apostar, seleccionara al equipo que desea apostarle
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
                escogerApuesta(cuenta, d, x, apostado); // en esta funcion se hace el procedimiento de la apuesta
            }

            if(respuesta == 3) break; // para volver al menu de las apuestas
            cont++;
        }
    }
    system("cls");
    printf("Este es tu saldo actual: %lu CLP\n", cuenta->tarjeta->saldoJ);
    int respuesta;
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;
    // en esta ultima funcion se le pregunta al usuario si desea generar otra ronda de apuesta o ir al menu de apuestas
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
    if(respuesta == 1) apuestas(cuenta);
    if(respuesta == 2){
        free(mapDeportes);
        apuestasNBA(cuenta);
    }
}

// Funcion que hace el procedimiento de las apuestas
void escogerApuesta(usuario* cuenta, deportes* equipo1, deportes* equipo2, deportes* apostado){
    int sorteo; // para generar al ganador y perdedor
    unsigned long apuesta;
    // primero se comparara si lo que escogio el usuario, corresponde a los equipo/deportistas del encuentro
    if(strcmp(apostado->nombre,equipo1->nombre) == 0){
        int pos,end,flag1=0,terminar_programa=0;
        char key;
    // el usuario selecciona su monto a apostar
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
        // se comprueba de que su saldo sea suficiente para realizar la apuesta, si no es suficiente tendra dos opciones
        if(cuenta->tarjeta->saldoJ < apuesta){
            int seleccion;
            system("cls");
            printf("SALDO INEFICIENTE\n");
            printf("NO SE PUDO COMPLETAR SU APUESTA\n");
            printf("MARQUE 1 SI DESEA IR DIRECTAMENTE A INGRESAR SALDO\n");
            printf("MARQUE 2 SI DESEA VOLVER AL MENU DEL CASINO\n");
            scanf("%i",&seleccion);

            if(seleccion == 1){
                retirarSaldo(cuenta);
                exit(EXIT_SUCCESS);
            }

            if(seleccion == 2){
                apuestas(cuenta);
                exit(EXIT_SUCCESS);
            }
        }
        // aqui se le quita lo que aposto a la cuenta y se muestra lo que aposto y a quien le aposto
        cuenta->tarjeta->saldoJ = cuenta->tarjeta->saldoJ - apuesta;
        system("cls");
        printf("Realizaste una apuesta de %lu CLP por %s \n", apuesta, apostado->nombre);
        system("pause");
        system("cls");
        sorteo = rand() % 2 + 1; // aca se genera el ganador o perdedor del encuentro

        // si el sorteo es 1 significa que el usuario gano y se le devuelve su dinero y la recompensa de la apuesta
        if(sorteo == 1){
            unsigned long premio = apuesta * equipo1->multiplicador;
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo1->nombre);
            printf("Ganaste la apuesta\n");
            cuenta->tarjeta->saldoJ += (apuesta * equipo1->multiplicador + apuesta);
            printf("Ganaste %lu CLP\n", premio);
            system("pause");
        }
        // si el sorteo es 2 el usuario perdio
        if(sorteo == 2){
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo2->nombre);
            printf("Perdiste la apuesta\n");
            system("pause");
        }
    }
    // este if hace el mismo procedimiento descrito anteriormente, solamente en el caso de que haya escogido al segundo equipo/deportista
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

        if(cuenta->tarjeta->saldoJ < apuesta){
            int seleccion;
            system("cls");
            printf("SALDO INEFICIENTE\n");
            printf("NO SE PUDO COMPLETAR SU APUESTA\n");
            printf("MARQUE 1 SI DESEA IR DIRECTAMENTE A INGRESAR SALDO\n");
            printf("MARQUE 2 SI DESEA VOLVER AL MENU DEL CASINO\n");
            scanf("%i",&seleccion);

            if(seleccion == 1){
                retirarSaldo(cuenta);
                exit(EXIT_SUCCESS);
            }

            if(seleccion == 2){
                apuestas(cuenta);
                exit(EXIT_SUCCESS);
            }
        }

        cuenta->tarjeta->saldoJ = cuenta->tarjeta->saldoJ - apuesta;
        system("cls");
        printf("Realizaste una apuesta de %lu CLP por %s \n", apuesta, apostado->nombre);
        system("pause");
        system("cls");
        sorteo = rand() % 2 + 1;
        if(sorteo == 1){
            unsigned long premio = apuesta * equipo1->multiplicador;
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo2->nombre);
            printf("Ganaste la apuesta\n");
            cuenta->tarjeta->saldoJ += (apuesta * equipo2->multiplicador);
            printf("Ganaste %lu CLP\n", premio);
            system("pause");
        }

        if(sorteo == 2){
            system("cls");
            printf("Ganador del encuentro: %s\n", equipo1->nombre);
            printf("Perdiste la apuesta\n");
            system("pause");
            system("cls");
        }
    }
    /* Estos dos if son para comprobar si coincide lo escogido con lo que estaba en el encuentro
    si llega a no coincidr este final de codigo se encarga de volver a escanear la apuesta*/

    if(strcmp(apostado->nombre,equipo1->nombre) != 0){
        if(strcmp(apostado->nombre,equipo2->nombre) != 0){
            scanf("%[^\n]",apostado->nombre);
            fflush(stdin);
            escogerApuesta(cuenta,equipo1,equipo2,apostado);
        }
    }

    if(strcmp(apostado->nombre,equipo2->nombre) != 0){
        if(strcmp(apostado->nombre,equipo1->nombre) != 0){
            scanf("%[^\n]",apostado->nombre);
            fflush(stdin);
            escogerApuesta(cuenta,equipo1,equipo2,apostado);
        }
    }
}

// Funcion que realiza el mismo trabajo que el importar ATP y importar F1, pero con sus datos correspondiente
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

// Al igual que las otras apuestas, se realiza el mismo funcionamiento en esta funcion
void apuestasFutbol(usuario * cuenta){
    int aux = 32 + 10 * 0.3;
    HashMap *mapDeportes = createMap(aux);
    importarFutbol(mapDeportes);
    encuentrosFutbol(mapDeportes, cuenta);
}

// Esta funcion importar es igual a los importar anteriores de las demas apuestas deportivas
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

// Realiza el mismo trabajo que el encuentrosNBA y ATP solamente que con sus datos correspondiente del archivo
void encuentrosFutbol(HashMap * mapDeportes, usuario * cuenta){
    /* En esta funcion se crean dos variables int llamadas "sorteo" y "sorteo1" que iran sorteando mediante un random
    numeros del 1 al valor del aux, estos valores se buscaran en el mapa Deportes ya que este contendra a los tenistas
    luego de encontrar los valores del mapa deportes, se cambiara la key (primera key sera el numero de ingreso al mapa y
    la segunda llave corresponde al nombre del equipo, esto con el fin de que no se puedan repetir los equipo)
    despues de realizar esto se mostraran los encuentros uno por uno, despues de que se genera un encuentro
    el usuario tendra tres opciones, apostar, pasar al siguiente encuentro y volver al menu de las apuestas */

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
                escogerApuesta(cuenta, d, x, apostado);
            }

            if(respuesta == 3) break;
            cont++;
        }
    }
    system("cls");
    printf("Este es tu saldo actual: %lu CLP\n", cuenta->tarjeta->saldoJ);

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
            apuestas(cuenta);
    }
    if(respuesta == 2){
        free(mapDeportes);
        apuestasFutbol(cuenta);
    }
}

// FIN DE LA CASA DE APUESTA Y COMIENZO DE LAS FUNCIONES DE LOS JUEGOS

void juegos(usuario *cuenta) {
    system("cls");

    int pos,end,flag1=0,terminar_programa=0;
    char key;
    do{
    pos = 0;
    end = 0;
        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
        gotoxy(1,2);printf(BLANCO_F NEGRO_T " - Ruleta" NEGRO_F BLANCO_T);
        gotoxy(1,3);printf(" - Tragamonedas");
        gotoxy(1,4);printf(" - Blackjack");
        gotoxy(1,5);printf(" - Keno");
        gotoxy(1,6);printf(" - Craps");
        gotoxy(1,7);printf(" - Adivinar Carta");
        gotoxy(1,8);printf(" - Azul y Rojo");
        gotoxy(1,9);printf(" - Salir");
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
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(BLANCO_F NEGRO_T " - Ruleta" NEGRO_F BLANCO_T);
                        gotoxy(1,3);printf(" - Tragamonedas");
                        gotoxy(1,4);printf(" - Blackjack");
                        gotoxy(1,5);printf(" - Keno");
                        gotoxy(1,6);printf(" - Craps");
                        gotoxy(1,7);printf(" - Adivinar Carta");
                        gotoxy(1,8);printf(" - Azul y Rojo");
                        gotoxy(1,9);printf(" - Salir");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(" - Ruleta");
                        gotoxy(1,3);printf(BLANCO_F NEGRO_T " - Tragamonedas" NEGRO_F BLANCO_T);
                        gotoxy(1,4);printf(" - Blackjack");
                        gotoxy(1,5);printf(" - Keno");
                        gotoxy(1,6);printf(" - Craps");
                        gotoxy(1,7);printf(" - Adivinar Carta");
                        gotoxy(1,8);printf(" - Azul y Rojo");
                        gotoxy(1,9);printf(" - Salir");
                        flag1=1;
                        break;

                case 2:
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(" - Ruleta");
                        gotoxy(1,3);printf(" - Tragamonedas");
                        gotoxy(1,4);printf(BLANCO_F NEGRO_T " - Blackjack" NEGRO_F BLANCO_T);
                        gotoxy(1,5);printf(" - Keno");
                        gotoxy(1,6);printf(" - Craps");
                        gotoxy(1,7);printf(" - Adivinar Carta");
                        gotoxy(1,8);printf(" - Azul y Rojo");
                        gotoxy(1,9);printf(" - Salir");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(" - Ruleta");
                        gotoxy(1,3);printf(" - Tragamonedas");
                        gotoxy(1,4);printf(" - Blackjack");
                        gotoxy(1,5);printf(BLANCO_F NEGRO_T " - Keno" NEGRO_F BLANCO_T);
                        gotoxy(1,6);printf(" - Craps");
                        gotoxy(1,7);printf(" - Adivinar Carta");
                        gotoxy(1,8);printf(" - Azul y Rojo");
                        gotoxy(1,9);printf(" - Salir");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(" - Ruleta");
                        gotoxy(1,3);printf(" - Tragamonedas");
                        gotoxy(1,4);printf(" - Blackjack");
                        gotoxy(1,5);printf(" - Keno");
                        gotoxy(1,6);printf(BLANCO_F NEGRO_T " - Craps" NEGRO_F BLANCO_T);
                        gotoxy(1,7);printf(" - Adivinar Carta");
                        gotoxy(1,8);printf(" - Azul y Rojo");
                        gotoxy(1,9);printf(" - Salir");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(" - Ruleta");
                        gotoxy(1,3);printf(" - Tragamonedas");
                        gotoxy(1,4);printf(" - Blackjack");
                        gotoxy(1,5);printf(" - Keno");
                        gotoxy(1,6);printf(" - Craps");
                        gotoxy(1,7);printf(BLANCO_F NEGRO_T " - Adivinar Carta" NEGRO_F BLANCO_T);
                        gotoxy(1,8);printf(" - Azul y Rojo");
                        gotoxy(1,9);printf(" - Salir");
                        flag1=5;
                        break;
                case 6:
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(" - Ruleta");
                        gotoxy(1,3);printf(" - Tragamonedas");
                        gotoxy(1,4);printf(" - Blackjack");
                        gotoxy(1,5);printf(" - Keno");
                        gotoxy(1,6);printf(" - Craps");
                        gotoxy(1,7);printf(" - Adivinar Carta");
                        gotoxy(1,8);printf(BLANCO_F NEGRO_T " - Azul y Rojo" NEGRO_F BLANCO_T);
                        gotoxy(1,9);printf(" - Salir");
                        flag1=6;
                        break;
                case 7:
                        gotoxy(1,1);printf("*** MENU DE JUEGOS ***");
                        gotoxy(1,2);printf(" - Ruleta");
                        gotoxy(1,3);printf(" - Tragamonedas");
                        gotoxy(1,4);printf(" - Blackjack");
                        gotoxy(1,5);printf(" - Keno");
                        gotoxy(1,6);printf(" - Craps");
                        gotoxy(1,7);printf(" - Adivinar Carta");
                        gotoxy(1,8);printf(" - Azul y Rojo");
                        gotoxy(1,9);printf(BLANCO_F NEGRO_T " - Salir" NEGRO_F BLANCO_T);
                        flag1=7;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: menuRuleta(cuenta); juegos(cuenta); terminar_programa=1; break;
            case 1: tragamonedas(cuenta); juegos(cuenta); terminar_programa=1; break;
            case 2: blackJack(cuenta); juegos(cuenta); terminar_programa=1; break;
            case 3: Keno(cuenta); juegos(cuenta); terminar_programa=1; break;
            case 4: menuCraps(cuenta); juegos(cuenta); terminar_programa=1; break;
            case 5: menuAdivinaCarta(cuenta); juegos(cuenta); terminar_programa=1; break;
            case 6: menuAzulRojo(cuenta); juegos(cuenta); terminar_programa=1; break;
            case 7: menuIniciarSesion(cuenta); terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

//INICIO TRAGAMONEDAS

void tragamonedas(usuario *cuenta) {
    system("cls");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    tituloTragamonedas();

    flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F);
        gotoxy(17,6);printf(" -SALIR");
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
                        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F);
                        gotoxy(17,6);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(17,5);printf(" -JUGAR");
                        gotoxy(17,6);printf(ROJO_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: menuTragamonedas(cuenta); break;
            case 1: terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void menuTragamonedas(usuario *cuenta) {
    system("cls");
    int dinero, n;
    int pos,end,flag1=0,terminar_programa=0;
    char key;
        do{
            pos = 0;
            end = 0;
            gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
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
                            gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                            gotoxy(1,2);printf(ROJO_F "- $1000" NEGRO_F);
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf(ROJO_F "- $2000" NEGRO_F);
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=1;
                            break;
                    case 2:
                            gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf(ROJO_F "- $3500" NEGRO_F);
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=2;
                            break;
                    case 3:
                            gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=3;
                            break;
                    case 4:
                            gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(1,7);printf("- $10000");
                            flag1=4;
                            break;
                    case 5:
                            gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=5;
                            break;
                }
            }while(end != 1);

            //comprobarApuesta(flag1, cuenta);
            system("cls");
            switch(flag1)
            {
                case 0:
                        if(cuenta->tarjeta->saldoJ < 1000){
                            printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                            system("pause");
                            system("cls");
                            tituloTragamonedas();
                            return;
                        }
                        else {
                            dinero = 1000; terminar_programa=1; break;
                        }
                case 1:
                        if(cuenta->tarjeta->saldoJ < 2000) {
                            printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                            system("pause");
                            system("cls");
                            tituloTragamonedas();
                            return;
                        }
                        else {
                            dinero = 2000; terminar_programa=1; break;
                        }
                case 2:
                        if(cuenta->tarjeta->saldoJ < 3500) {
                            printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                            system("pause");
                            system("cls");
                            tituloTragamonedas();
                            return;
                        }
                        else {
                            dinero = 3500; terminar_programa=1; break;
                        }
                case 3:
                        if(cuenta->tarjeta->saldoJ < 5000) {
                            printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                            system("pause");
                            system("cls");
                            tituloTragamonedas();
                            return;
                        }
                        else {
                            dinero = 5000; terminar_programa=1; break;
                        }
                case 4:
                        if(cuenta->tarjeta->saldoJ < 7500) {
                            printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                            system("pause");
                            system("cls");
                            tituloTragamonedas();
                            return;
                        }
                        else {
                            dinero = 7500; terminar_programa=1; break;
                        }
                case 5:
                        if(cuenta->tarjeta->saldoJ < 10000) {
                            printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                            system("pause");
                            system("cls");
                            tituloTragamonedas();
                            return;
                        }
                        else {
                            dinero = 10000; terminar_programa=1; break;
                        }
            }
        }while(terminar_programa != 1);
        system("cls");

        flag1=0,terminar_programa=0;

        do{
            pos = 0;
            end = 0;

            gotoxy(0,0); printf("%c", 201);
            gotoxy(43,0); printf("%c", 187);
            gotoxy(0,6); printf("%c", 200);
            gotoxy(43,6); printf("%c", 188);
            for(int i = 1 ; i < 43 ; i++) {
                if(i == 14 || i == 29) {
                    gotoxy(i,0); printf("%c", 203);
                    gotoxy(i,6); printf("%c", 202);
                }else{
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

            gotoxy(45,2);printf("***TRAGAMONEDAS***");
            gotoxy(45,3);printf(CYAN_F " -HACER TIRADA" NEGRO_F);
            do{
                key = getch();
                switch(key){
                    case 72: if (pos == 0)
                            pos = 0;
                            else pos--;
                            break;
                    case 80: if (pos == 0) pos =0;
                            else pos++;
                            break;
                    case 13: end = 1;
                }
                switch(pos){
                    case 0:
                            gotoxy(45,2);printf("***TRAGAMONEDAS***");
                            gotoxy(45,3);printf(CYAN_F " -HACER TIRADA" NEGRO_F);
                            flag1=0;
                            break;
                }
            }while(end != 1);

            switch(flag1)
            {
                case 0: maquinaTragamonedas(dinero, cuenta); terminar_programa=1; break;
            }
        }while(terminar_programa != 1);
}

void tituloTragamonedas() {
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "                TRAGAMONEDAS" RESET_COLOR"%16s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

void maquinaTragamonedas(int dinero, usuario * cuenta){
    system("COLOR");
    int n;
    srand(time(NULL));
    // El gotoxy es utilizado para decoracion y elegancia
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
    int a, b, c; // a = simbolo izquierdo, b = simbolo central, c = simbolo derecha
    for(int i = 0; i < 3 ; i++){
        n = rand () % 6 + 1;
        if(i == 0) a = n;
        if(i == 1) b = n;
        if(i == 2) c = n;
        // Dependiendo de la n aleatoria, se dibujara el respectivo simbolo
        switch(n) {
        case 1: sieteRojo(i); break;
        case 2: limon(i); break;
        case 3: manzana(i); break;
        case 4: ciruela(i); break;
        case 5: uva(i); break;
        case 6: cereza(i); break;
        }
    }
    // Si coinciden los 3 simbolos, se le entrega el premio al usuario, en caso contrario pierde la mitad
    if(a == b && a == c) {
        printf("\n\n\nHas ganado : %i", dinero);
        cuenta->tarjeta->saldoJ += dinero;
    } else {
        dinero = trunc(dinero/2);
        printf("\n\n\nHas perdido : %i", dinero);
        cuenta->tarjeta->saldoJ -= dinero;
    }
    printf("\nEste es tu monedero actual %lu",cuenta->tarjeta->saldoJ);
    printf("\n");
    system("pause");
    system("cls");
    tituloTragamonedas();
}

// Se escribe el simbolo que reprecenta al "siete", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void sieteRojo(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(ROJO_T "    *****");
        gotoxy(1,2); printf("       *");
        gotoxy(1,3); printf("      *");
        gotoxy(1,4); printf("     *");
        gotoxy(1,5); printf("    *" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(ROJO_T "    *****");
        gotoxy(15,2); printf("       *");
        gotoxy(15,3); printf("      *");
        gotoxy(15,4); printf("     *");
        gotoxy(15,5); printf("    *" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(ROJO_T "    *****");
        gotoxy(30,2); printf("       *");
        gotoxy(30,3); printf("      *");
        gotoxy(30,4); printf("     *");
        gotoxy(30,5); printf("    *" RESET_COLOR);
    }
}

// Se escribe el simbolo que reprecenta al "limon", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void limon(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(AMARILLO_T "    ****");
        gotoxy(1,2); printf("  *      *");
        gotoxy(1,3); printf(" *        *");
        gotoxy(1,4); printf("  *      *");
        gotoxy(1,5); printf("    ****" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(AMARILLO_T "    ****");
        gotoxy(15,2); printf("  *      *");
        gotoxy(15,3); printf(" *        *");
        gotoxy(15,4); printf("  *      *");
        gotoxy(15,5); printf("    ****" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(AMARILLO_T "    ****");
        gotoxy(30,2); printf("  *      *");
        gotoxy(30,3); printf(" *        *");
        gotoxy(30,4); printf("  *      *");
        gotoxy(30,5); printf("    ****" RESET_COLOR);
    }

}

// Se escribe el simbolo que reprecenta a la "manzana", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void manzana(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(ROJO_T "    ****");
        gotoxy(1,2); printf("  *      *");
        gotoxy(1,3); printf(" *        *");
        gotoxy(1,4); printf("  *      *");
        gotoxy(1,5); printf("    ****" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(ROJO_T "    ****");
        gotoxy(15,2); printf("  *      *");
        gotoxy(15,3); printf(" *        *");
        gotoxy(15,4); printf("  *      *");
        gotoxy(15,5); printf("    ****" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(ROJO_T "    ****");
        gotoxy(30,2); printf("  *      *");
        gotoxy(30,3); printf(" *        *");
        gotoxy(30,4); printf("  *      *");
        gotoxy(30,5); printf("    ****" RESET_COLOR);
    }
}

// Se escribe el simbolo que reprecenta a la "ciruela", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void ciruela(int x) {
    char a = 92;
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(VERDE_T"     /");
        gotoxy(1,2); printf("    / %c", a);
        gotoxy(1,3); printf(MAGENTA_T"   ** **");
        gotoxy(1,4); printf(" *  *    *");
        gotoxy(1,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(VERDE_T"     /");
        gotoxy(15,2); printf("    / %c", a);
        gotoxy(15,3); printf(MAGENTA_T"   ** **");
        gotoxy(15,4); printf(" *  *    *");
        gotoxy(15,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(VERDE_T"     /");
        gotoxy(30,2); printf("    / %c", a);
        gotoxy(30,3); printf(MAGENTA_T"   ** **");
        gotoxy(30,4); printf(" *  *    *");
        gotoxy(30,5); printf("   ** **" RESET_COLOR);
    }

}

// Se escribe el simbolo que reprecenta a la "uva", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void uva(int x) {
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(1,2); printf("  ()()()()");
        gotoxy(1,3); printf("   ()()()");
        gotoxy(1,4); printf("    ()()");
        gotoxy(1,5); printf("     ()" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(15,2); printf("  ()()()()");
        gotoxy(15,3); printf("   ()()()");
        gotoxy(15,4); printf("    ()()");
        gotoxy(15,5); printf("     ()" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(MAGENTA_T " ()()()()()");
        gotoxy(30,2); printf("  ()()()()");
        gotoxy(30,3); printf("   ()()()");
        gotoxy(30,4); printf("    ()()");
        gotoxy(30,5); printf("     ()" RESET_COLOR);
    }

}

// Se escribe el simbolo que reprecenta a la "cereza", dependiendo de la x cambiara la posicion entre izquierda, centro o derecha
void cereza(int x) {
    char a = 92;
    if(x == 0) {

        gotoxy(1,1); printf("             ");
        gotoxy(1,2); printf("             ");
        gotoxy(1,3); printf("             ");
        gotoxy(1,4); printf("             ");
        gotoxy(1,5); printf("             ");

        gotoxy(1,1); printf(VERDE_T"     /");
        gotoxy(1,2); printf("    / %c", a);
        gotoxy(1,3); printf(ROJO_T "   ** **");
        gotoxy(1,4); printf(" *  *    *");
        gotoxy(1,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 1) {

        gotoxy(15,1); printf("             ");
        gotoxy(15,2); printf("             ");
        gotoxy(15,3); printf("             ");
        gotoxy(15,4); printf("             ");
        gotoxy(15,5); printf("             ");

        gotoxy(15,1); printf(VERDE_T"     /");
        gotoxy(15,2); printf("    / %c", a);
        gotoxy(15,3); printf(ROJO_T"   ** **");
        gotoxy(15,4); printf(" *  *    *");
        gotoxy(15,5); printf("   ** **" RESET_COLOR);
    }
    if(x == 2) {

        gotoxy(30,1); printf("             ");
        gotoxy(30,2); printf("             ");
        gotoxy(30,3); printf("             ");
        gotoxy(30,4); printf("             ");
        gotoxy(30,5); printf("             ");

        gotoxy(30,1); printf(VERDE_T"     /");
        gotoxy(30,2); printf("    / %c", a);
        gotoxy(30,3); printf(ROJO_T"   ** **");
        gotoxy(30,4); printf(" *  *    *");
        gotoxy(30,5); printf("   ** **" RESET_COLOR);
    }
}

//FIN TRAGAMONEDAS

//INICIO KENO

void Keno(usuario *cuenta) {
    system("cls");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;

        char asterisco[2];
        strcpy(asterisco,"*");
        printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("%s%44s\n",asterisco,asterisco);
        printf("%s" CYAN_T "                   KENO" RESET_COLOR"%21s\n",asterisco,asterisco);
        printf("%s%44s\n",asterisco,asterisco);
        printf("* * * * * * * * * * * * * * * * * * * * * * *\n");

        gotoxy(19,6);printf(ROJO_F "-JUGAR" NEGRO_F);
        gotoxy(19,7);printf("-SALIR");
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
                        gotoxy(19,6);printf(ROJO_F "-JUGAR" NEGRO_F);
                        gotoxy(19,7);printf("-SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(19,6);printf("-JUGAR");
                        gotoxy(19,7);printf(ROJO_F "-SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: menuKeno(cuenta); break;
            case 1: terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void menuKeno(usuario *cuenta) {
    system("cls");
    system("color");
    srand(time(NULL));
    int num = 0, capacidad = 26;
    HashMap *mapKeno = createMap(capacidad);

    char asterisco[2];
    strcpy(asterisco,"*");
    printf("   * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("   %s%44s\n",asterisco,asterisco);
    printf("   %s" CYAN_T "                TABLA KENO" RESET_COLOR"%18s\n",asterisco,asterisco);
    printf("   %s%44s\n",asterisco,asterisco);
    printf("   * * * * * * * * * * * * * * * * * * * * * * *\n");

    // Con los for se escriben los 80 numeros que se pueden elegir para apostar
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 10 ; j++ ) {
            num++;
            printf("  %2i ", num);
        }
        printf("\n");
    }
    recompensaKeno();

    int pos,end,flag1=0,terminar_programa=0;
    char key;
    int dinero;

    do{
    pos = 0;
    end = 0;
        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
        gotoxy(2,15);printf(ROJO_F "- $1000" NEGRO_F);
        gotoxy(2,16);printf("- $2000");
        gotoxy(2,17);printf("- $3500");
        gotoxy(2,18);printf("- $5000");
        gotoxy(2,19);printf("- $7500");
        gotoxy(2,20);printf("- $10000");
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
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf(ROJO_F "- $1000" NEGRO_F);
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf(ROJO_F "- $2000" NEGRO_F);
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf(ROJO_F "- $3500" NEGRO_F);
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf(ROJO_F "- $5000" NEGRO_F);
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf("- $10000");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf(ROJO_F "- $7500" NEGRO_F);
                        gotoxy(2,20);printf("- $10000");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(2,14);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(2,15);printf("- $1000");
                        gotoxy(2,16);printf("- $2000");
                        gotoxy(2,17);printf("- $3500");
                        gotoxy(2,18);printf("- $5000");
                        gotoxy(2,19);printf("- $7500");
                        gotoxy(2,20);printf(ROJO_F "- $10000" NEGRO_F);
                        flag1=5;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0:
                    if(cuenta->tarjeta->saldoJ < 1000){
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        return;
                    }
                    else {
                        dinero = 1000; terminar_programa=1; break;
                    }
            case 1:
                    if(cuenta->tarjeta->saldoJ < 2000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        return;
                    }
                    else {
                        dinero = 2000; terminar_programa=1; break;
                    }
            case 2:
                    if(cuenta->tarjeta->saldoJ < 3500) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        return;
                    }
                    else {
                        dinero = 3500; terminar_programa=1; break;
                    }
            case 3:
                    if(cuenta->tarjeta->saldoJ < 5000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        return;
                    }
                    else {
                        dinero = 5000; terminar_programa=1; break;
                    }
            case 4:
                    if(cuenta->tarjeta->saldoJ < 7500) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        return;
                    }
                    else {
                        dinero = 7500; terminar_programa=1; break;
                    }
            case 5:
                    if(cuenta->tarjeta->saldoJ < 10000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        return;
                    }
                    else {
                        dinero = 10000; terminar_programa=1; break;
                    }
        }
    }while(terminar_programa != 1);

    generarA(mapKeno, 20);

    gotoxy(2,14);printf("                                        ");
    gotoxy(2,15);printf("                                        ");
    gotoxy(2,16);printf("                                        ");
    gotoxy(2,17);printf("                                        ");
    gotoxy(2,18);printf("                                        ");
    gotoxy(2,19);printf("                                        ");
    gotoxy(2,20);printf("                                        ");


    // en el do while se escanea la cantidad de numeros que apostará el usuario entre 1 y 20
    int x;
    do {
        gotoxy(2,14);printf("                                                              ");
        gotoxy(2,14);printf("Ingrese la cantidad de numeros que quiere apostar: ");
        scanf("%i", &x);
        if(x < 1 || x > 20){
            gotoxy(2,15);printf("Numero invalido, recuerde que puede apostar desde uno a veinte numeros\n");
            printf("  ");
            system("pause");
            gotoxy(2,15);printf("                                                                              ");
            gotoxy(2,16);printf("                                                                              ");

        }
    } while(x < 1 || x > 20);


    int aux;
    do{
    pos = 0;
    end = 0;
        gotoxy(2,14);printf("                                                        ");
        gotoxy(2,15);printf("                                                        ");
        gotoxy(2,16);printf("                                                        ");

        gotoxy(2,14);printf("Seleccione una opcion");
        gotoxy(2,15);printf(ROJO_F "- Escoger numeros automaticamente" NEGRO_F);
        gotoxy(2,16);printf("- Escoger numeros manualmente");

	// en este do while el usuario decide si apostar manualmente o generar un keno automatico
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
                        gotoxy(2,14);printf("Seleccione una opcion");
                        gotoxy(2,15);printf(ROJO_F "- Escoger numeros automaticamente" NEGRO_F);
                        gotoxy(2,16);printf("- Escoger numeros manualmente");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(2,14);printf("Seleccione una opcion");
                        gotoxy(2,15);printf("- Escoger numeros automaticamente");
                        gotoxy(2,16);printf(ROJO_F "- Escoger numeros manualmente" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: aux = 1; terminar_programa=1; break;
            case 1: aux = 2; terminar_programa=1; break;

        }
    }while(terminar_programa != 1);

    // dependiendo de la desicion se accederá a una de estas funciones que generan un keno
    HashMap *apuestaKeno = createMap(capacidad);
    if(aux == 1) {
        generarA(apuestaKeno, x);
    } else {
        generarM(apuestaKeno, x);
    }

    escribirApuesta(apuestaKeno);
    HashMap *mapResultado = createMap(capacidad);
    correctas(mapKeno, apuestaKeno, mapResultado);
    escribirCorrectas(mapResultado, mapKeno, dinero, cuenta);
}

// Esta funcion muestra las recompensas por atinar a X cantidad de numeros
void recompensaKeno() {
    gotoxy(52,1);printf("| APUESTA | AUMENTO |");
    float multiplicador = 0;
    for(int i = 0 ; i < 10 ; i++) {
        gotoxy(52, 2+i);printf("|   %2i    |   %.2f  |\n", i + 1, multiplicador);
        multiplicador += 0.25;
    }
    printf("\n");
}

// Esta funcion genera un Keno entre 1 y 20 numeros aleatorios
void generarA(HashMap *map, int x) {
    int *value;
    char *key;
    for(int i = 0 ; i < x ; i++) {
        value = (int*) malloc(sizeof(int)); // numero
        key = malloc(sizeof(char) * 10); // key
        *value = rand() % 80 + 1; // valor aleatorio para el numero
        sprintf(key, "%i", *value); // key igual al numero del value pero en char

	// Verifica que no se repitan numeros
        while(searchMap(map, key) != NULL) {
            *value = rand() % 80 + 1;
            sprintf(key, "%i", *value);
        }
        insertMap(map, key, value); // insertar numeros diferentes entre si
    }
}

// Esta funcion genera un Keno entre 1 y 20 numeros manualmente
void generarM(HashMap *map, int x) {
    int *num;

    gotoxy(2,14);printf("                                              ");
    gotoxy(2,15);printf("                                              ");
    gotoxy(2,16);printf("                                              ");

    for(int i = 0 ; i < x ; i++) {
        num = (int *) malloc(sizeof(int)); // numero
        char *key = malloc(sizeof(char) * 10); // key
        gotoxy(2,i+14);printf("Ingrese apuesta %i: ", i + 1);
        do {
            scanf("%i", num); // valor ingresado por usuario para el numero
            sprintf(key, "%i", *num); // key igual al numero del value pero en char
            if(*num < 1 || *num > 80){
                    gotoxy(2,i+15);printf("Numero invalido, recuerde que puede apostar desde el uno al ochenta\n");
                    gotoxy(2,i+16);system("pause");
                    gotoxy(2,i+15);printf("                                                                   ");
                    gotoxy(2,i+16);printf("                                                                   ");
                    gotoxy(2,i+14);printf("                                                                   ");
                    gotoxy(2,i+14);printf("Ingrese apuesta %i: ", i + 1);
            }

	    // Verifica que no se repitan numeros
            if(searchMap(map, key) != NULL){
                    gotoxy(2,i+15);printf("Este numero ya fue apostado, seleccione uno nuevo\n");
                    gotoxy(2,i+16);system("pause");
                    gotoxy(2,i+15);printf("                                                                   ");
                    gotoxy(2,i+16);printf("                                                                   ");
                    gotoxy(2,i+14);printf("                                                                   ");
                    gotoxy(2,i+14);printf("Ingrese apuesta %i: ", i + 1);
            }
        } while(*num < 1 || *num > 80 || searchMap(map, key) != NULL);
        insertMap(map, key, num); // insertar numeros diferentes entre si
    }
    printf("\n");
}

// Se escribe recorriendo el mapa los numeros apostados por el usuario
void escribirApuesta(HashMap *apuestaKeno) {
    system("cls");
    printf("Numeros apostados: ");
    int *p = firstMap(apuestaKeno);
    while(p != NULL) {
        printf("| %i ", *p);
        p = nextMap(apuestaKeno);
    }
    printf("|\n\n");
}

// Se verifica los numeros que coinciden con la apuesta y el Keno que genera el programa, guardandolos en un mapa
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

// Se escriben los numeros del 1 al 80 nuevamente, pero con fondo blanco las del Keno generado por el programa y fondo rojo las que atinó el usuario
void escribirCorrectas(HashMap *mapResultado, HashMap *mapKeno, float dinero, usuario * cuenta) {
    int num = 1;
    float multiplicador = -0.25, auxDinero = dinero;
    int *value;
    for(int i = 0 ; i < 8 ; i++) {
        for(int j = 0 ; j < 10 ; j++ ) {
            value = (int *) malloc(sizeof(int));
            *value = num;
            char *key = malloc(sizeof(char) * 10);
            sprintf(key, "%i", *value);
	    // si se encuentra, se vuelve a verificar en el siguiente if, en caso contrario se escriber el numero normal
            if(searchMap(mapKeno, key) != NULL) {
		// si se encuentra en el mapa se escribe el numero con fondo rojo y se aumenta el multiplicador, si no se escribe con fondo blanco
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
    // dependiendo del valor del multiplicador, se verá si pierde, gana o ninguna de estas dos
    if(multiplicador != -0.25) {
        dinero += dinero * multiplicador;
        if(dinero == auxDinero){
            printf("\nNo hubo ganancias\n");
            system("pause");
            system("cls");
        }else{
            printf("\nGanaste $%.0f\n", dinero);
            system("pause");
            system("cls");
        }
    } else {
        printf("\nPerdiste! $%.0f\n", dinero);
        dinero *= -1;
        system("pause");
        system("cls");
    }
    cuenta->tarjeta->saldoJ = cuenta->tarjeta->saldoJ + dinero;
}

//FIN KENO

void blackJack(usuario *cuenta) {
    system("cls");
    system("color");
    tituloBlackJack();
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F);
        gotoxy(17,6);printf(" -SALIR");
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
                        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F);
                        gotoxy(17,6);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(17,5);printf(" -JUGAR");
                        gotoxy(17,6);printf(ROJO_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: menuBlackJack(cuenta); break;
            case 1: terminar_programa=1; printf("\n");
        }

    }while(terminar_programa != 1);
}

void menuBlackJack(usuario *cuenta){
    system("cls");
    srand(time(NULL));
    HashMap *mapBaraja = createMap(52);
    barajaAleatoria(mapBaraja);
    system("color");
    int dinero;
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
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
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf(ROJO_F "- $1000" NEGRO_F);
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf(ROJO_F "- $2000" NEGRO_F);
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf(ROJO_F "- $3500" NEGRO_F);
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf(ROJO_F "- $5000" NEGRO_F);
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf("- $10000");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf(ROJO_F "- $7500" NEGRO_F);
                        gotoxy(1,7);printf("- $10000");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(1,1);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,2);printf("- $1000");
                        gotoxy(1,3);printf("- $2000");
                        gotoxy(1,4);printf("- $3500");
                        gotoxy(1,5);printf("- $5000");
                        gotoxy(1,6);printf("- $7500");
                        gotoxy(1,7);printf(ROJO_F "- $10000" NEGRO_F);
                        flag1=5;
                        break;
            }
        }while(end != 1);

        system("cls");
        switch(flag1)
        {
            case 0:
                    if(cuenta->tarjeta->saldoJ < 1000){
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloBlackJack();
                        return;
                    }
                    else {
                        dinero = 1000; terminar_programa=1; break;
                    }
            case 1:
                    if(cuenta->tarjeta->saldoJ < 2000) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloBlackJack();
                        return;
                    }
                    else {
                        dinero = 2000; terminar_programa=1; break;
                    }
            case 2:
                    if(cuenta->tarjeta->saldoJ < 3500) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloBlackJack();
                        return;
                    }
                    else {
                        dinero = 3500; terminar_programa=1; break;
                    }
            case 3:
                    if(cuenta->tarjeta->saldoJ < 5000) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloBlackJack();
                        return;
                    }
                    else {
                        dinero = 5000; terminar_programa=1; break;
                    }
            case 4:
                    if(cuenta->tarjeta->saldoJ < 7500) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloBlackJack();
                        return;
                    }
                    else {
                        dinero = 7500; terminar_programa=1; break;
                    }
            case 5:
                    if(cuenta->tarjeta->saldoJ < 10000) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloBlackJack();
                        return;
                    }
                    else {
                        dinero = 10000; terminar_programa=1; break;
                    }
            }
        }while(terminar_programa != 1);

    cuenta->tarjeta->saldoJ = cuenta->tarjeta->saldoJ - dinero;
    dinero = sacarCarta(mapBaraja, dinero);
    if(dinero > 0){
        cuenta->tarjeta->saldoJ = cuenta->tarjeta->saldoJ + dinero;
    }
    gotoxy(1,8);printf("Este el dinero en su monedero: %lu",cuenta->tarjeta->saldoJ);
}

void tituloBlackJack(){
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "                BLACKJACK" RESET_COLOR"%19s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

// Funcion que crea una baraja española de 40 cartas
void barajaAleatoria(HashMap *mapBaraja) {
    int *carta;
    char *key;
    Baraja *baraja;

    for(int i = 0 ; i < 40 ; i++) {
        baraja = createBaraja();
        carta = (int *) malloc(sizeof(int));
        key = (char *) malloc(sizeof(char) * 10);

        *carta = rand() % 40 + 1; // carta aleatoria
        sprintf(key, "%i", *carta); // key es desde el 1 al 40 pero tipo char

        // se comprueba que no este en el mapa, para que no hayan valores repetidos
        while(searchMap(mapBaraja, key) != NULL) {
            *carta = rand() % 40 + 1;
            sprintf(key, "%i", *carta);
        }
        // si carta esta entre 1 y 10, equivale a la carta con pinta = moneda
        // si esta entre 11 y 20, se obtiene el resto de carta, para que quede un valor entre 1 y 10 y pinta = baston
        // si esta entre 21 y 30, se obtiene el resto de carta, para que quede un valor entre 1 y 10 y pinta = espada
        // si esta entre 31 y 40, se obtiene el resto de carta, para que quede un valor entre 1 y 10 y pinta = copa
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
        insertMap(mapBaraja, key, baraja); // se inserta en el mapa
    }
}

// funcion que escoge una carta al azar del mapa y la entrega
int sacarCarta(HashMap *mapBaraja, int dinero) {
    system("cls");
    int *carta;
    char *key;

    carta = (int *) malloc(sizeof(int));
    key = (char *) malloc(sizeof(char) * 10);

    // se entrega la primera carta del usuario
    generarCarta(carta, key, mapBaraja);
    Baraja *aux = searchMap(mapBaraja, key);
    gotoxy(1,1);printf("Su primera carta es: %i de %s\n", aux->numero, aux->pinta);
    int suma = aux->numero;
    eraseMap(mapBaraja, key); // se borra del mapa porque la carta ya fue utilizada

    // se entrega la segunda carta del usuario
    generarCarta(carta, key, mapBaraja);
    aux = searchMap(mapBaraja, key);
    gotoxy(1,2);printf("Su segunda carta es: %i de %s\n", aux->numero, aux->pinta);
    suma += aux->numero;
    eraseMap(mapBaraja, key); // se borra del mapa porque la carta ya fue utilizada

    // se entrega la primera carta del crupier
    gotoxy(1,3);printf("Ahora se entregara una carta al Crupier\n");
    generarCarta(carta, key, mapBaraja);
    aux = searchMap(mapBaraja, key);
    gotoxy(1,4);printf("Carta Crupier: %i de %s\n", aux->numero, aux->pinta);
    int sumaC = aux->numero;
    eraseMap(mapBaraja, key); // se borra del mapa porque la carta ya fue utilizada
    gotoxy(1,5);printf("Usted suma: %i", suma);

    bool perder = false;
    int decision;

    // si el usuario se planta sale de esta funcion, si saca carta, se le entrega una nueva aleatoria, si suma mas de 21 pierde automaticamente
    do {
        int pos,end,flag1=0,terminar_programa=0;
        char keyMenu;

        do{
        pos = 0;
        end = 0;
            gotoxy(1,7);printf("OPCIONES");
            gotoxy(1,8);printf(ROJO_F "- PLANTARSE" NEGRO_F);
            gotoxy(1,9);printf("- SACAR CARTA");
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
                            gotoxy(1,7);printf("OPCIONES");
                            gotoxy(1,8);printf(ROJO_F "- PLANTARSE" NEGRO_F);
                            gotoxy(1,9);printf("- SACAR CARTA");
                            flag1=0;
                            break;

                    case 1:
                            gotoxy(1,7);printf("OPCIONES");
                            gotoxy(1,8);printf("- PLANTARSE ");
                            gotoxy(1,9);printf(ROJO_F "- SACAR CARTA" NEGRO_F);
                            flag1=1;
                            break;
                }
            }while(end != 1);

            switch(flag1)
            {
                case 0:
                        terminar_programa=1;
                        break;
                case 1:
                        generarCarta(carta, key, mapBaraja);
                        aux = searchMap(mapBaraja, key);
                        system("cls");
                        gotoxy(1,1);printf("Su nueva carta es: %i de %s\n", aux->numero, aux->pinta);
                        suma += aux->numero;
                        gotoxy(1,2);printf("Usted suma: %i", suma);
                        eraseMap(mapBaraja, key);
                        if(suma > 21) {
                            perder = true;
                            gotoxy(1,3);printf(AMARILLO_T "SOBREPASASTE 21\n" RESET_COLOR);
                            gotoxy(1,4);printf(ROJO_T "Perdiste $%i" RESET_COLOR, dinero);
                            gotoxy(1,5);system("pause");
                            system("cls");
                            dinero *= -1;
                            tituloBlackJack();
                            terminar_programa = 1;
                            break;
                        }

                        break;
            }
        }while(terminar_programa != 1);
    } while(decision == 2 && perder == false);

    // si el usuario se planta o no sumo mas de 21,
    if(perder == false) {
        system("cls");
        printf("Se ha plantado con %i\n", suma);

        // si la suma en este instante fue 21, el usuario gana y se le entrega su recompensa
        if(suma == 21) {
            printf(MAGENTA_T "BLACK JACK\n" RESET_COLOR);
            printf(VERDE_T "Has ganado: $%i\n" RESET_COLOR , dinero * 2);
            dinero += dinero * 2;
            system("pause");
            system("cls");
            tituloBlackJack();
        // en caso contrario se le entregara cartas al crupier hasta que suma mas de 16
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
            // si el crupier se pasa de 21, gana el usuario y se le entrega la recompensa
            if(sumaC > 21) {
                printf(VERDE_T "Has ganado: $%i\n" RESET_COLOR, dinero);
                dinero += dinero;
                system("pause");
                system("cls");
                tituloBlackJack();
            } else {
                // si el crupier suma mas que el usuario, este ultimo pierde y se le quita el dinero
                if(sumaC > suma) {
                    printf(ROJO_T "Has perdido: $%i\n" RESET_COLOR, dinero);
                    dinero *= -1;
                    system("pause");
                    system("cls");
                    tituloBlackJack();
                // si el crupier y el usuario suman lo mismo, el usuario conserva el dinero apostado
                } else if(sumaC == suma) {
                    printf(CYAN_T "Empate, conservas tu dinero\n" RESET_COLOR);
                    system("pause");
                    system("cls");
                    tituloBlackJack();
                // si el usuario suma mas que el crupier, el usuario gana y se le entrega la recompensa
                } else {
                    printf(VERDE_T "Has ganado: $%i\n" RESET_COLOR, dinero);
                    dinero += dinero;
                    system("pause");
                    system("cls");
                    tituloBlackJack();
                }
            }
        }
    }
    return dinero;
}

// funcion que genera una carta aleatoria
void generarCarta(int *carta, char *key, HashMap *mapBaraja) {
    *carta = rand() % 40 + 1;
    sprintf(key, "%i", *carta);
    while(searchMap(mapBaraja, key) == NULL) {
        *carta = rand() % 40 + 1;
        sprintf(key, "%i", *carta);
    }
}

void azulyrojo(usuario * cuenta){
    system("COLOR");
    //system("cls");
    int apuesta;
    int color;

    int pos,end,flag=0,terminar_programa=0;
    char key;

    do{
        pos = 0;
        end = 0;
        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
        gotoxy(2,13);printf(ROJO_F " - $1000" NEGRO_F);
        gotoxy(2,14);printf(" - $2500");
        gotoxy(2,15);printf(" - $5000");
        gotoxy(2,16);printf(" - $10000");
        gotoxy(2,17);printf(" - $20000");
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
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(ROJO_F " - $1000" NEGRO_F);
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(" - $20000");
                        flag=0;
                        break;
                case 1:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(ROJO_F " - $2500" NEGRO_F);
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(" - $20000");
                        flag=1;
                        break;
                case 2:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(ROJO_F " - $5000" NEGRO_F);
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(" - $20000");
                        flag=2;
                        break;
                case 3:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(ROJO_F " - $10000" NEGRO_F);
                        gotoxy(2,17);printf(" - $20000");
                        flag=3;
                        break;
                case 4:
                        gotoxy(5,12);printf("ESCOJA UNA CANTIDAD DE DINERO PARA APOSTAR");
                        gotoxy(2,13);printf(" - $1000");
                        gotoxy(2,14);printf(" - $2500");
                        gotoxy(2,15);printf(" - $5000");
                        gotoxy(2,16);printf(" - $10000");
                        gotoxy(2,17);printf(ROJO_F " - $20000" NEGRO_F);
                        flag=4;
                        break;
            }
        }while(end != 1);

        switch(flag)
        {
            case 0:
                    if(cuenta->tarjeta->saldoJ < 1000){
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAzulRojo();
                        return;
                    }
                    else {
                        apuesta = 1000; terminar_programa=1; break;
                    }
            case 1:
                    if(cuenta->tarjeta->saldoJ < 2000){
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAzulRojo();
                        return;
                    }
                    else {
                        apuesta = 2000; terminar_programa=1; break;
                    }
            case 2:
                    if(cuenta->tarjeta->saldoJ < 3500) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAzulRojo();
                        return;
                    }
                    else {
                        apuesta = 3500; terminar_programa=1; break;
                    }
            case 3:
                    if(cuenta->tarjeta->saldoJ < 5000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAzulRojo();
                        return;
                    }
                    else {
                        apuesta = 5000; terminar_programa=1; break;
                    }
            case 4:
                    if(cuenta->tarjeta->saldoJ < 10000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAzulRojo();
                        return;
                    }
                    else {
                        apuesta = 10000; terminar_programa=1; break;
                    }
            case 5:
                    if(cuenta->tarjeta->saldoJ < 20000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAzulRojo();
                        return;
                    }
                    else {
                        apuesta = 20000; terminar_programa=1; break;
                    }
            }
    }while(terminar_programa != 1);

    int pos1,end1,flag1=0,terminar_programa1=0;
    char key1;

    do{
        pos1 = 0;
        end1 = 0;
        gotoxy(5,19);printf("ESCOJA UNA OPCION");
        gotoxy(2,20);printf(ROJO_F " -ROJO" NEGRO_F);
        gotoxy(2,21);printf(" -EMPATE");
        gotoxy(2,22);printf(" -AZUL");
        do{
            key1 = getch();
            switch(key1){
                case 72: if (pos1 == 0)
                        pos1 = 2;
                        else pos1--;
                        break;
                case 80: if (pos1 == 2) pos1 =0;
                        else pos1++;
                        break;
                case 13: end1 = 1;
            }
            switch(pos1){
                case 0:
                        gotoxy(5,19);printf("ESCOJA UNA OPCION");
                        gotoxy(2,20);printf(ROJO_F " -ROJO" NEGRO_F);
                        gotoxy(2,21);printf(" -EMPATE");
                        gotoxy(2,22);printf(" -AZUL");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,19);printf("ESCOJA UNA OPCION");
                        gotoxy(2,20);printf(" -ROJO");
                        gotoxy(2,21);printf(BLANCO_F NEGRO_T " -EMPATE" NEGRO_F BLANCO_T);
                        gotoxy(2,22);printf(" -AZUL");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(5,19);printf("ESCOJA UNA OPCION");
                        gotoxy(2,20);printf(" -ROJO");
                        gotoxy(2,21);printf(" -EMPATE");
                        gotoxy(2,22);printf(AZUL_F " -AZUL" NEGRO_F);
                        flag1=2;
                        break;
            }
        }while(end1 != 1);

        switch(flag1)
        {
            case 0: color = 1;
                    terminar_programa1 = 1;
                    break;

            case 1: color = 2;
                    terminar_programa1 = 1;
                    break;

            case 2: color = 3;
                    terminar_programa1 = 1;
                    break;
        }

    }while(terminar_programa1 != 1);

    int n;
    srand(time(NULL));
    n = rand () % 3 + 1;

    if(n == 1){

        if(n == color){
            apuesta *= 2;
            printf(ROJO_T "\nGanaste ha salido ROJO\n");
            cuenta->tarjeta->saldoJ += apuesta;
            printf(RESET_COLOR "FELICIDADES GANASTE %d",apuesta);
        }else{
            printf(ROJO_T "\nPERDISTE HA SALIDO ROJO \n");
            cuenta->tarjeta->saldoJ -= apuesta;
            printf("GANASTE 0");
        }
    }

    if(n == 2){

         if(n == color){
            apuesta *= 2;
            printf(RESET_COLOR "\nGanaste ha salido EMPATE\n");
            cuenta->tarjeta->saldoJ += apuesta;
            printf(RESET_COLOR "GANASTE %d",apuesta);
        }else{
            printf(RESET_COLOR "\nPERDISTE HA SALIDO EMPATE\n");
            cuenta->tarjeta->saldoJ -= apuesta;
            printf("GANASTE 0");
        }
    }

        if(n == 3){
         if(n == color){
            apuesta *= 2;
            printf(AZUL_T "\nGanaste ha salido AZUL\n");
            cuenta->tarjeta->saldoJ += apuesta;
            printf(RESET_COLOR "GANASTE %d",apuesta);
        }else{
            printf(AZUL_T "\nPERDISTE HA SALIDO AZUL \n");
            cuenta->tarjeta->saldoJ -= apuesta;
            printf("GANASTE 0\n");
        }
        }
    printf(RESET_COLOR"");
    printf("\n");
    printf("Este el saldo de tu monedero %lu\n", cuenta->tarjeta->saldoJ);
    system("pause");
    system("cls");
    tituloAzulRojo();
}

void menuAzulRojo(usuario* cuenta){
    system("color");
    system("cls");
    tituloAzulRojo();
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,6);printf("OPCIONES");
        gotoxy(2,7);printf(ROJO_F " -JUGAR" NEGRO_F);
        gotoxy(2,8);printf(" -SALIR");
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
                        gotoxy(5,6);printf("OPCIONES");
                        gotoxy(2,7);printf(ROJO_F " -JUGAR" NEGRO_F);
                        gotoxy(2,8);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,6);printf("OPCIONES");
                        gotoxy(2,7);printf(" -JUGAR");
                        gotoxy(2,8);printf(AZUL_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: azulyrojo(cuenta); break;
            case 1: terminar_programa=1; printf("\n"); break;
        }

    }while(terminar_programa != 1);
}

void tituloAzulRojo(){
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" ROJO_T "            ROJO "  RESET_COLOR "EMPATE" AZUL_T " AZUL " RESET_COLOR"%15s\n",asterisco,asterisco);
    //printf("%s             AZUL EMPATE ROJO              *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

//FIN AZUL Y ROJO
//INICIO RULETA
void menuRuleta(usuario *cuenta){
    system("color");
    system("cls");
    tituloruleta();
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,6);printf("OPCIONES");
        gotoxy(2,7);printf(ROJO_F " -JUGAR" NEGRO_F);
        gotoxy(2,8);printf(" -SALIR");
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
                        gotoxy(5,6);printf("OPCIONES");
                        gotoxy(2,7);printf(ROJO_F " -JUGAR" NEGRO_F);
                        gotoxy(2,8);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,6);printf("OPCIONES");
                        gotoxy(2,7);printf(" -JUGAR");
                        gotoxy(2,8);printf(ROJO_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: ruletaMenu(cuenta); break;
            case 1: terminar_programa=1; printf("\n"); break;
        }
    }while(terminar_programa != 1);
}

void ruletaMenu(usuario * cuenta){
    printf("\n\n***INSTRUCCIONES***\n");
    printf("Bienvenido al juego de la ruleta\n"RESET_COLOR);
    printf("\nExisten 5 opciones que puedes elegir luego de ingresar tu apuesta:\n");
    printf(MAGENTA_T"\n1: Esta opcion te multiplica tu apuesta x1.\n");
    printf(VERDE_T "2: Esta opcion te multiplica tu apuesta x2.\n");
    printf(ROJO_T "5: Esta opcion te multiplica tu apuesta x5.\n");
    printf(CYAN_T "10: Esta opcion te multiplica tu apuesta x10.\n");
    printf(AMARILLO_T "Bonus: Esta opcion te multiplica tu apuesta por un numero random entre 1 y 100.\n"RESET_COLOR);
    printf("\n");
    system("pause");

    int apuesta;
    system("cls");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,1);printf("Seleccione su apuesta");
        gotoxy(2,2);printf(ROJO_F " - 2500$" NEGRO_F);
        gotoxy(2,3);printf(" - 5000$");
        gotoxy(2,4);printf(" - 10000$");
        gotoxy(2,5);printf(" - 15000$");
        gotoxy(2,6);printf(" - 20000$");
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
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(ROJO_F " - 2500$" NEGRO_F);
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(ROJO_F " - 5000$" NEGRO_F);
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(ROJO_F " - 10000$" NEGRO_F);
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(ROJO_F " - 15000$" NEGRO_F);
                        gotoxy(2,6);printf(" - 20000$");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,1);printf("Seleccione su apuesta");
                        gotoxy(2,2);printf(" - 2500$");
                        gotoxy(2,3);printf(" - 5000$");
                        gotoxy(2,4);printf(" - 10000$");
                        gotoxy(2,5);printf(" - 15000$");
                        gotoxy(2,6);printf(ROJO_F " - 20000$" NEGRO_F);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        system("cls");
        switch(flag1)
        {
            case 0:
                    if(cuenta->tarjeta->saldoJ < 1000){
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloruleta();
                        return;
                    }
                    else {
                        apuesta = 1000; terminar_programa=1; break;
                    }
            case 1:
                    if(cuenta->tarjeta->saldoJ < 2000) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloruleta();
                        return;
                    }
                    else {
                        apuesta = 2000; terminar_programa=1; break;
                    }
            case 2:
                    if(cuenta->tarjeta->saldoJ < 3500) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloruleta();
                        return;
                    }
                    else {
                        apuesta = 3500; terminar_programa=1; break;
                    }
            case 3:
                    if(cuenta->tarjeta->saldoJ < 5000) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloruleta();
                        return;
                    }
                    else {
                        apuesta = 5000; terminar_programa=1; break;
                    }
            case 4:
                    if(cuenta->tarjeta->saldoJ < 10000) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloruleta();
                        return;
                    }
                    else {
                        apuesta = 10000; terminar_programa=1; break;
                    }
            case 5:
                    if(cuenta->tarjeta->saldoJ < 20000) {
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloruleta();
                        return;
                    }
                    else {
                        apuesta = 20000; terminar_programa=1; break;
                    }
            }
    }while(terminar_programa != 1);

    int seleccion;
    system("cls");
    system("color");
    flag1=0,terminar_programa=0;

    do{
    pos = 0;
    end = 0;
        gotoxy(5,1);printf("Seleccione su opcion de juego");
        gotoxy(2,2);printf(MAGENTA_T BLANCO_F "x1\n" NEGRO_F);
        gotoxy(2,3);printf(VERDE_T"x2\n");
        gotoxy(2,4);printf(ROJO_T"x5\n");
        gotoxy(2,5);printf(CYAN_T"x10\n");
        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
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
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T BLANCO_F "x1\n" NEGRO_F);
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T BLANCO_F "x2\n" NEGRO_F);
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=1;
                        break;
                case 2:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T BLANCO_F "x5\n" NEGRO_F);
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T BLANCO_F "x10\n" NEGRO_F);
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T BLANCO_F "Bonus\n"RESET_COLOR);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: seleccion = 1; terminar_programa = 1; break;
            case 1: seleccion = 2; terminar_programa = 1; break;
            case 2: seleccion = 5; terminar_programa = 1; break;
            case 3: seleccion = 10; terminar_programa = 1; break;
            case 4: seleccion = 99; terminar_programa = 1; break;
        }
    }while(terminar_programa != 1);

    ruleta(apuesta,seleccion,cuenta);
}

void ruleta(int apuesta,int seleccion, usuario * cuenta){
    int ruleta[36] = {1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10};

    int Seg1,Seg2;
    Seg1=(int)clock()/CLOCKS_PER_SEC;
    Seg2=Seg1;
    int i;

    srand(time(NULL));
    while((Seg2-Seg1) < 10){
        if(clock() % 400 < 10){
            system("cls");
            i = rand() % 35 + 1;
            printf("                                \x1b[46m 10 \x1b[0m  \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                          \x1b[30m\x1b[47m 1 \x1b[0m              \x1b[42m 2 \x1b[0m\n");
            printf("                    \x1b[41m 5 \x1b[0m                         \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                \x1b[42m 2 \x1b[0m                                 \x1b[43m 99 \x1b[0m\n\n");
            printf("           \x1b[30m\x1b[47m 1 \x1b[0m                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("        \x1b[43m 99 \x1b[0m                                                 \x1b[42m 2 \x1b[0m\n\n");
            printf("     \x1b[30m\x1b[47m 1 \x1b[0m                                                       \x1b[41m 5 \x1b[0m\n\n");
            printf("   \x1b[42m 2 \x1b[0m                                                          \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("  \x1b[30m\x1b[47m 1 \x1b[0m               %15d                             \x1b[46m 10 \x1b[0m\n\n", ruleta[i]);
            printf("  \x1b[46m 10 \x1b[0m                                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("   \x1b[30m\x1b[47m 1 \x1b[0m                                                          \x1b[42m 2 \x1b[0m\n\n");
            printf("     \x1b[41m 5 \x1b[0m                                                      \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("        \x1b[42m 2 \x1b[0m                                                \x1b[43m 99 \x1b[0m\n\n");
            printf("           \x1b[30m\x1b[47m 1 \x1b[0m                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("               \x1b[43m 99 \x1b[0m                                  \x1b[42m 2 \x1b[0m\n");
            printf("                     \x1b[30m\x1b[47m 1 \x1b[0m                        \x1b[41m 5 \x1b[0m\n");
            printf("                          \x1b[42m 2 \x1b[0m              \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                               \x1b[30m\x1b[47m 1 \x1b[0m   \x1b[46m 10 \x1b[0m\n");
        }
        Seg2=(int)clock()/CLOCKS_PER_SEC;
    }
    system("Pause");
    system("cls");
    int n = ruleta[i];
    switch(n){
            case 1: if(seleccion == 1) resultado(apuesta,1,n,cuenta); else resultado(apuesta,0,n,cuenta); break;
            case 2: if(seleccion == 2) resultado(apuesta,2,n,cuenta); else resultado(apuesta,0,n,cuenta); break;
            case 5: if(seleccion == 5) resultado(apuesta,5,n,cuenta); else resultado(apuesta,0,n,cuenta); break;
            case 10: if(seleccion == 10) resultado(apuesta,10,n,cuenta); else resultado(apuesta,0,n,cuenta);break;
            case 99: if(seleccion == 99) resultado(apuesta,99,n,cuenta); else resultado(apuesta,0,n,cuenta);break;
            case 22: break;
    }
}

void resultado(int apuesta, int multiplicador, int n, usuario * cuenta){
    int Seg1,Seg2;
    Seg1=(int)clock()/CLOCKS_PER_SEC;
    Seg2=Seg1;
    int i;

    int bonus[10] = {10,20,30,40,50,60,70,80,90,100};

    if(multiplicador == 99){
        printf(AMARILLO_T "BONUS\n" RESET_COLOR);

        srand(time(NULL));
        while((Seg2-Seg1) < 10){
            if(clock() % 400 < 10){
                system("cls");
                i = rand() % 10;
                printf ( AMARILLO_T "\n BONUS :\n\n\t%d " RESET_COLOR , multiplicador = bonus[i]);
            }
            Seg2=(int)clock()/CLOCKS_PER_SEC;
        }
            printf("\nFELICIDADES GANASTE: %d\n", apuesta = (apuesta * multiplicador) + apuesta);
            cuenta->tarjeta->saldoJ += apuesta;
    }else{

        if(multiplicador == 0){
            printf("\nLO SIENTO PERDISTE\n");
            cuenta->tarjeta->saldoJ -= apuesta;
        }else{
          printf("\nFELICIDADES GANASTE: %d\n",  apuesta = (apuesta * multiplicador) + apuesta );
          cuenta->tarjeta->saldoJ += apuesta;
        }
    }

    printf("Este es mi monedero: %lu", cuenta->tarjeta->saldoJ);
}

void tituloruleta(){
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "                 RULETA" RESET_COLOR"%21s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

//FIN RULETA

//INICIO ADIVINA CARTA
void menuAdivinaCarta(usuario * cuenta){ //Menu de la aplicacion
    HashMap *adv = createMap(10);
    llenarMapa(adv);
    system("color");
    system("cls");
    tituloAdivinaCarta();
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F); //Esto permite elegir entre jugar y salir de la aplicacion
        gotoxy(17,6);printf(" -SALIR");
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
                        gotoxy(17,5);printf(ROJO_F " -JUGAR" NEGRO_F);
                        gotoxy(17,6);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(17,5);printf(" -JUGAR");
                        gotoxy(17,6);printf(ROJO_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1) //Este switch sirve para que el programa sepa que opcion eligio el usuario
        {
            case 0: carta(adv, cuenta); break;
            case 1: terminar_programa=1; printf("\n");
        }

    }while(terminar_programa != 1);
}

void llenarMapa(HashMap *adv){ //Funcion para insertar datos en el mapa que contendra los nombres de las cartas
    Baraja *mazo;
    int *random;
    char *key;
    for(int i = 0; i <= 3; i++){

        mazo = crearMazo();

        random = (int *) malloc(sizeof(int));

        key = (char *) malloc(sizeof(char)* 10);

        *random = i + 1;

        sprintf(key, "%i", *random);//Funcion para transformar int a char

        if(i == 0) mazo->pinta =  strdup("AS DE COPAS");
        if(i == 1) mazo->pinta =  strdup("AS DE BASTOS");
        if(i == 2) mazo->pinta =  strdup("AS DE OROS");
        if(i == 3) mazo->pinta =  strdup("AS DE ESPADAS");
        insertMap(adv, key, mazo);//Insertamos la key
    }
}

void carta(HashMap *adv, usuario * cuenta){ //Funcion la cual nos entrega las instrucciones, opciones de apuesta y resultados del juego del usuario
    system("cls");
    char *key;
    char *key2;
    int carta;
    int *n;
    int *usuario;
    int apuesta;
    int revolver;

    n = (int *) malloc(sizeof(int));
    usuario = (int *) malloc(sizeof(int));
    key = (char *) malloc(sizeof(char)* 10);
    key2= (char *) malloc(sizeof(char)* 10);

    printf(AMARILLO_T"INSTRUCCIONES\n"RESET_COLOR);
    printf(VERDE_T"\nBienvenido al juego adivina la carta\n"RESET_COLOR);
    printf(AZUL_T "\nEste juego consta en adivinar que carta saldra\n"RESET_COLOR);
    printf("\nEscoge una opcion:");

    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,8);printf(CYAN_F"- AS DE COPAS" NEGRO_F);
        gotoxy(1,9);printf("- AS DE BASTOS");
        gotoxy(1,10);printf("- AS DE OROS");
        gotoxy(1,11);printf("- AS DE ESPADAS");
        do{
            keyMenu = getch();
            switch(keyMenu){
                case 72: if (pos == 0)
                        pos = 3;
                        else pos--;
                        break;
                case 80: if (pos == 3) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0:
                        gotoxy(1,8);printf(CYAN_F"- AS DE COPAS" NEGRO_F);
                        gotoxy(1,9);printf("- AS DE BASTOS");
                        gotoxy(1,10);printf("- AS DE OROS");
                        gotoxy(1,11);printf("- AS DE ESPADAS");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,8);printf("- AS DE COPAS");
                        gotoxy(1,9);printf(MAGENTA_F "- AS DE BASTOS" NEGRO_F);
                        gotoxy(1,10);printf("- AS DE OROS");
                        gotoxy(1,11);printf("- AS DE ESPADAS");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(1,8);printf("- AS DE COPAS");
                        gotoxy(1,9);printf("- AS DE BASTOS");
                        gotoxy(1,10);printf(ROJO_F "- AS DE OROS" NEGRO_F);
                        gotoxy(1,11);printf("- AS DE ESPADAS");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(1,8);printf("- AS DE COPAS");
                        gotoxy(1,9);printf("- AS DE BASTOS");
                        gotoxy(1,10);printf("- AS DE OROS");
                        gotoxy(1,11);printf(AMARILLO_F "- AS DE ESPADAS" NEGRO_F);
                        flag1=3;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: carta = 1; terminar_programa=1; break;
            case 1: carta = 2; terminar_programa=1; break;
            case 2: carta = 3; terminar_programa=1; break;
            case 3: carta = 4; terminar_programa=1; break;
        }

    }while(terminar_programa != 1);

    *usuario = carta;
    srand(time(NULL));
    *n = rand () % 4 + 1;;

    sprintf(key, "%i", *n);//Funcion la cual nos permite transformar un int a un char para que se pueda usar como key del mapa

    flag1=0,terminar_programa=0;
    do{
    pos = 0;
    end = 0;
        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
        gotoxy(1,14);printf(ROJO_F "- $1000" NEGRO_F);
        gotoxy(1,15);printf("- $2000");
        gotoxy(1,16);printf("- $3500");
        gotoxy(1,17);printf("- $5000");
        gotoxy(1,18);printf("- $7500");
        gotoxy(1,19);printf("- $10000");
        do{
            keyMenu = getch();
            switch(keyMenu){
                case 72: if (pos == 0)
                        pos = 5;
                        else pos--;
                        break;
                case 80: if (pos == 5) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){ //Opciones de apuesta monetaria del usuario
                case 0:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf(ROJO_F "- $1000" NEGRO_F);
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf(ROJO_F "- $2000" NEGRO_F);
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf(ROJO_F "- $3500" NEGRO_F);
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=2;
                        break;
                case 3:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf(ROJO_F "- $5000" NEGRO_F);
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf("- $10000");
                        flag1=3;
                        break;
                case 4:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf(ROJO_F "- $7500" NEGRO_F);
                        gotoxy(1,19);printf("- $10000");
                        flag1=4;
                        break;
                case 5:
                        gotoxy(1,13);printf("Seleccione la cantidad de dinero que quiere apostar");
                        gotoxy(1,14);printf("- $1000");
                        gotoxy(1,15);printf("- $2000");
                        gotoxy(1,16);printf("- $3500");
                        gotoxy(1,17);printf("- $5000");
                        gotoxy(1,18);printf("- $7500");
                        gotoxy(1,19);printf(ROJO_F "- $10000" NEGRO_F);
                        flag1=5;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0:
                    if(cuenta->tarjeta->saldoJ < 1000){
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAdivinaCarta();
                        return;
                    }
                    else {
                        apuesta = 1000; terminar_programa=1; break;
                    }
            case 1:
                    if(cuenta->tarjeta->saldoJ < 2000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAdivinaCarta();
                        return;
                    }
                    else {
                        apuesta = 2000; terminar_programa=1; break;
                    }
            case 2:
                    if(cuenta->tarjeta->saldoJ < 3500) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAdivinaCarta();
                        return;
                    }
                    else {
                        apuesta = 3500; terminar_programa=1; break;
                    }
            case 3:
                    if(cuenta->tarjeta->saldoJ < 5000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAdivinaCarta();
                        return;
                    }
                    else {
                        apuesta = 5000; terminar_programa=1; break;
                    }
            case 4:
                    if(cuenta->tarjeta->saldoJ < 7500) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAdivinaCarta();
                        return;
                    }
                    else {
                        apuesta = 7500; terminar_programa=1; break;
                    }
            case 5:
                    if(cuenta->tarjeta->saldoJ < 10000) {
                        system("cls");
                        printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                        system("pause");
                        system("cls");
                        tituloAdivinaCarta();
                        return;
                    }
                    else {
                        apuesta = 10000; terminar_programa=1; break;
                    }
            }
    }while(terminar_programa != 1);

    gotoxy(1,20);printf("=== Presione cualquier tecla para sacar una carta ===");
    gotoxy(25,22);revolver = getch();
    system("cls");
    Baraja *p = searchMap(adv, key);
    gotoxy(1,1);printf(AMARILLO_T "Ha salido la carta %s\n",p->pinta);

    if(*usuario == *n){ //Condicional que nos muestra el resultado de la apuesta
        gotoxy(1,2);printf(VERDE_T "GANASTE!!");
        gotoxy(1,3);printf(VERDE_T "Has ganado %d",apuesta *= 2);
        cuenta->tarjeta->saldoJ += apuesta;
        printf(""RESET_COLOR);
    }else{
        gotoxy(1,2);printf(ROJO_T "Has perdido, vuelve a intentarlo" RESET_COLOR);
        cuenta->tarjeta->saldoJ -= apuesta;
    }

    printf("\n");
    printf(" ");
    printf("Este es el saldo de tu monedero %lu\n",cuenta->tarjeta->saldoJ);
    system("PAUSE");
    system("cls");
    tituloAdivinaCarta();
}

void tituloAdivinaCarta(){ //Funcion para mostrar el titulo de la aplicacion por pantalla
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" CYAN_T "             ADIVINA LA CARTA" RESET_COLOR"%15s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

//INICIO CRAPS

void tituloCraps(){//Funcion para mostrar el titulo de la aplicacion
    system("COLOR");
    char asterisco[2];
    strcpy(asterisco,"*");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("%s%44s\n",asterisco,asterisco);
    printf("%s" VERDE_T "                 CRAPS" RESET_COLOR"%22s\n",asterisco,asterisco);
    printf("%s%44s\n",asterisco,asterisco);
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
}

void menuCraps(usuario *cuenta){//Funcion para acceder al menu de la aplicacion
    system("cls");
    tituloCraps();
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
            case 0: crapsMenu(cuenta); break;
            case 1: terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void crapsMenu(usuario*cuenta){//Funcion para escoger las opciones de apuesta del craps
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
                            flag1=2;
                            break;
                    case 3:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=3;
                            break;
                    case 4:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(1,7);printf("- $10000");
                            flag1=4;
                            break;
                    case 5:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=5;
                            break;
                }
                }while(end != 1);

                system("cls");
                switch(flag1)
                {
                    case 0:
                            if(cuenta->tarjeta->saldoJ < 1000){
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 1000; terminar_programa=1; break;
                            }
                    case 1:
                            if(cuenta->tarjeta->saldoJ < 2000) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 2000; terminar_programa=1; break;
                            }
                    case 2:
                            if(cuenta->tarjeta->saldoJ < 3500) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 3500; terminar_programa=1; break;
                            }
                    case 3:
                            if(cuenta->tarjeta->saldoJ < 5000) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 5000; terminar_programa=1; break;
                            }
                    case 4:
                            if(cuenta->tarjeta->saldoJ < 7500) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 7500; terminar_programa=1; break;
                            }
                    case 5:
                            if(cuenta->tarjeta->saldoJ < 10000) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 10000; terminar_programa=1; break;
                            }
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
                            flag1=2;
                            break;
                    case 3:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf(ROJO_F "- $5000" NEGRO_F);
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf("- $10000");
                            flag1=3;
                            break;
                    case 4:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf(ROJO_F "- $7500" NEGRO_F);
                            gotoxy(1,7);printf("- $10000");
                            flag1=4;
                            break;
                    case 5:
                            gotoxy(1,1);printf(AMARILLO_T "Seleccione el monto de su apuesta" RESET_COLOR);
                            gotoxy(1,2);printf("- $1000");
                            gotoxy(1,3);printf("- $2000");
                            gotoxy(1,4);printf("- $3500");
                            gotoxy(1,5);printf("- $5000");
                            gotoxy(1,6);printf("- $7500");
                            gotoxy(1,7);printf(ROJO_F "- $10000" NEGRO_F);
                            flag1=5;
                            break;
                }
                }while(end != 1);

                system("cls");
                switch(flag1)
                {
                    case 0:
                            if(cuenta->tarjeta->saldoJ < 1000){
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 1000; terminar_programa=1; break;
                            }
                    case 1:
                            if(cuenta->tarjeta->saldoJ < 2000) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 2000; terminar_programa=1; break;
                            }
                    case 2:
                            if(cuenta->tarjeta->saldoJ < 3500) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 3500; terminar_programa=1; break;
                            }
                    case 3:
                            if(cuenta->tarjeta->saldoJ < 5000) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 5000; terminar_programa=1; break;
                            }
                    case 4:
                            if(cuenta->tarjeta->saldoJ < 7500) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 7500; terminar_programa=1; break;
                            }
                    case 5:
                            if(cuenta->tarjeta->saldoJ < 10000) {
                                printf("No cuenta con el suficiente dinero para apostar, intente ingresando mas dinero\n");
                                system("pause");
                                system("cls");
                                tituloCraps();
                                return;
                            }
                            else {
                                apuesta = 10000; terminar_programa=1; break;
                            }
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
    craps(apuesta,sumaUsuario,n,cuenta);
}

void craps(int apuesta, int sumaUsuario,int n, usuario* cuenta){ //Funcion que da los resultados y revuelve los dados
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
            cuenta->tarjeta->saldoJ += apuesta;
            printf("Este es tu monedero actual %lu\n", cuenta->tarjeta->saldoJ);
            system("pause");
            system("cls");
            tituloCraps();
        }else{
            printf("\nPERDISTE\n");
            cuenta->tarjeta->saldoJ -= apuesta;
            printf("Este es tu monedero actual %lu\n", cuenta->tarjeta->saldoJ);
            system("pause");
            system("cls");
            tituloCraps();
        }
    }

    if(n == 2){

        if((sumaUsuario == dado1) || (sumaUsuario == dado2)){
            apuesta = (apuesta * 1) + apuesta;
            printf("GANASTE!!!\n");
            printf("\nHas ganado $ %d\n",apuesta);
            cuenta->tarjeta->saldoJ += apuesta;
            printf("Este es tu monedero actual %lu\n", cuenta->tarjeta->saldoJ);
            system("pause");
            system("cls");
            tituloCraps();
        }else{
            printf("\nPERDISTE\n");
            cuenta->tarjeta->saldoJ -= apuesta;
            printf("Este es tu monedero actual %lu\n", cuenta->tarjeta->saldoJ);
            system("pause");
            system("cls");
            tituloCraps();
        }
    }
}

//FIN CRAPS

char *contrasena() {
    char *password = (char *) malloc(sizeof(char) * 20);
    int x = 0;
    for(int i = 0 ; i < 20 ; i = x) {
        password[i] = getch();
        if(password[i] == 13) {
            password[i] = '\0';
            break;
        }
        if(password[i] == 8) {
            if(i > 0) {
            x = i - 1;
            printf("\b \b");
            }
        } else {
            printf("*");
            x++;
        }
    }
    return password;
}

void tragamonedasPorDiversion(){
    system("cls");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    int n;



    do{
        pos = 0;
        end = 0;

        gotoxy(0,0); printf("%c", 201);
        gotoxy(43,0); printf("%c", 187);
        gotoxy(0,6); printf("%c", 200);
        gotoxy(43,6); printf("%c", 188);
        for(int i = 1 ; i < 43 ; i++) {
            if(i == 14 || i == 29) {
                gotoxy(i,0); printf("%c", 203);
                gotoxy(i,6); printf("%c", 202);
            }else{
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

        gotoxy(45,2);printf("TRAGAMONEDAS");
        gotoxy(45,3);printf(CYAN_F " -HACER TIRADA" NEGRO_F);
        gotoxy(45,4);printf(" -SALIR");
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
                        gotoxy(45,2);printf("TRAGAMONEDAS");
                        gotoxy(45,3);printf(CYAN_F " -HACER TIRADA" NEGRO_F);
                        gotoxy(45,4);printf(" -SALIR");
                        flag1=0;
                        break;
                case 1:
                        gotoxy(45,2);printf("TRAGAMONEDAS");
                        gotoxy(45,3);printf(" -HACER TIRADA");
                        gotoxy(45,4);printf(CYAN_F " -SALIR" NEGRO_F);
                        flag1=1;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: tragamonedasPorDiversion(); break;;
            case 1: terminar_programa=1;
        }

    }while(terminar_programa != 1);
}

void jugarPorDiversion(){
    system("cls");
    int pos,end,flag1=0,terminar_programa=0;
    char keyMenu;

    do{
    pos = 0;
    end = 0;
        gotoxy(1,1);printf("*** MENU JUGAR POR DIVERSION ***");
        gotoxy(1,2);printf(ROJO_F "- Tragamonedas" NEGRO_F);
        gotoxy(1,3);printf("- Ruleta");
        gotoxy(1,4);printf("- Salir");
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
                        gotoxy(1,1);printf("*** MENU JUGAR POR DIVERSION ***");
                        gotoxy(1,2);printf(ROJO_F "- Tragamonedas" NEGRO_F);
                        gotoxy(1,3);printf("- Ruleta");
                        gotoxy(1,4);printf("- Salir");
                        flag1=0;
                        break;

                case 1:
                        gotoxy(1,1);printf("*** MENU JUGAR POR DIVERSION ***");
                        gotoxy(1,2);printf("- Tragamonedas");
                        gotoxy(1,3);printf(ROJO_F "- Ruleta" NEGRO_F);
                        gotoxy(1,4);printf("- Salir");
                        flag1=1;
                        break;
                case 2:
                        gotoxy(1,1);printf("*** MENU JUGAR POR DIVERSION ***");
                        gotoxy(1,2);printf("- Tragamonedas");
                        gotoxy(1,3);printf("- Ruleta");
                        gotoxy(1,4);printf(ROJO_F "- Salir" NEGRO_F);
                        flag1=2;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: system("cls"); maquinaDiversion(); break;
            case 1: system("cls"); ruletaDiversionMenu(); break;
            case 2: system("cls"); terminar_programa=1; break;
        }
    }while(terminar_programa != 1);
}

void maquinaDiversion(){
    int n;
    srand(time(NULL));
    // El gotoxy es utilizado para decoracion y elegancia
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
    int a, b, c; // a = simbolo izquierdo, b = simbolo central, c = simbolo derecha
    for(int i = 0; i < 3 ; i++){
        n = rand () % 6 + 1;
        if(i == 0) a = n;
        if(i == 1) b = n;
        if(i == 2) c = n;
        // Dependiendo de la n aleatoria, se dibujara el respectivo simbolo
        switch(n) {
        case 1: sieteRojo(i); break;
        case 2: limon(i); break;
        case 3: manzana(i); break;
        case 4: ciruela(i); break;
        case 5: uva(i); break;
        case 6: cereza(i); break;
        }
    }
    // Si coinciden los 3 simbolos, se le entrega el premio al usuario, en caso contrario pierde la mitad
    if(a == b && a == c) {
        printf("\n\n\n\n\nHas ganado!\n");
        system("pause");
        system("cls");
    } else {
        printf("\n\n\n\n\nHas perdido!\n");
        system("pause");
        system("cls");
    }
}

void ruletaDiversionMenu(){
    printf("\n\n***INSTRUCCIONES***\n");
    printf("Bienvenido al juego de la ruleta\n"RESET_COLOR);
    printf("\nExisten 5 opciones que puedes elegir luego de ingresar tu apuesta:\n");
    printf(MAGENTA_T"\n1: Esta opcion te multiplica tu apuesta x1.\n");
    printf(VERDE_T "2: Esta opcion te multiplica tu apuesta x2.\n");
    printf(ROJO_T "5: Esta opcion te multiplica tu apuesta x5.\n");
    printf(CYAN_T "10: Esta opcion te multiplica tu apuesta x10.\n");
    printf(AMARILLO_T "Bonus: Esta opcion te multiplica tu apuesta por un numero random entre 1 y 100.\n"RESET_COLOR);
    printf("\n");
    system("pause");

    int apuesta;
    system("cls");
    system("color");
    int pos,end,flag1=0,terminar_programa=0;
    char key;

    int seleccion;
    system("cls");
    system("color");

    do{
    pos = 0;
    end = 0;
        gotoxy(5,1);printf("Seleccione su opcion de juego");
        gotoxy(2,2);printf(MAGENTA_T BLANCO_F "x1\n" NEGRO_F);
        gotoxy(2,3);printf(VERDE_T"x2\n");
        gotoxy(2,4);printf(ROJO_T"x5\n");
        gotoxy(2,5);printf(CYAN_T"x10\n");
        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
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
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T BLANCO_F "x1\n" NEGRO_F);
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=0;
                        break;

                case 1:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T BLANCO_F "x2\n" NEGRO_F);
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=1;
                        break;
                case 2:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T BLANCO_F "x5\n" NEGRO_F);
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=2;
                        break;
                case 3:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T BLANCO_F "x10\n" NEGRO_F);
                        gotoxy(2,6);printf(AMARILLO_T"Bonus\n"RESET_COLOR);
                        flag1=3;
                        break;
                case 4:
                        gotoxy(5,1);printf("Seleccione su opcion de juego");
                        gotoxy(2,2);printf(MAGENTA_T"x1\n");
                        gotoxy(2,3);printf(VERDE_T"x2\n");
                        gotoxy(2,4);printf(ROJO_T"x5\n");
                        gotoxy(2,5);printf(CYAN_T"x10\n");
                        gotoxy(2,6);printf(AMARILLO_T BLANCO_F "Bonus\n"RESET_COLOR);
                        flag1=4;
                        break;
            }
        }while(end != 1);

        switch(flag1)
        {
            case 0: seleccion = 1; terminar_programa = 1; break;
            case 1: seleccion = 2; terminar_programa = 1; break;
            case 2: seleccion = 5; terminar_programa = 1; break;
            case 3: seleccion = 10; terminar_programa = 1; break;
            case 4: seleccion = 99; terminar_programa = 1; break;
        }
    }while(terminar_programa != 1);

    ruletaDiversion(seleccion);
}

void ruletaDiversion(int seleccion){
    int ruleta[36] = {1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10,1,2,1,99,1,2,5,1,10};

    int Seg1,Seg2;
    Seg1=(int)clock()/CLOCKS_PER_SEC;
    Seg2=Seg1;
    int i;

    srand(time(NULL));
    while((Seg2-Seg1) < 10){
        if(clock() % 400 < 10){
            system("cls");
            i = rand() % 35 + 1;
            printf("                                \x1b[46m 10 \x1b[0m  \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                          \x1b[30m\x1b[47m 1 \x1b[0m              \x1b[42m 2 \x1b[0m\n");
            printf("                    \x1b[41m 5 \x1b[0m                         \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                \x1b[42m 2 \x1b[0m                                 \x1b[43m 99 \x1b[0m\n\n");
            printf("           \x1b[30m\x1b[47m 1 \x1b[0m                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("        \x1b[43m 99 \x1b[0m                                                 \x1b[42m 2 \x1b[0m\n\n");
            printf("     \x1b[30m\x1b[47m 1 \x1b[0m                                                       \x1b[41m 5 \x1b[0m\n\n");
            printf("   \x1b[42m 2 \x1b[0m                                                          \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("  \x1b[30m\x1b[47m 1 \x1b[0m               %15d                             \x1b[46m 10 \x1b[0m\n\n", ruleta[i]);
            printf("  \x1b[46m 10 \x1b[0m                                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("   \x1b[30m\x1b[47m 1 \x1b[0m                                                          \x1b[42m 2 \x1b[0m\n\n");
            printf("     \x1b[41m 5 \x1b[0m                                                      \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("        \x1b[42m 2 \x1b[0m                                                \x1b[43m 99 \x1b[0m\n\n");
            printf("           \x1b[30m\x1b[47m 1 \x1b[0m                                           \x1b[30m\x1b[47m 1 \x1b[0m\n\n");
            printf("               \x1b[43m 99 \x1b[0m                                  \x1b[42m 2 \x1b[0m\n");
            printf("                     \x1b[30m\x1b[47m 1 \x1b[0m                        \x1b[41m 5 \x1b[0m\n");
            printf("                          \x1b[42m 2 \x1b[0m              \x1b[30m\x1b[47m 1 \x1b[0m\n");
            printf("                               \x1b[30m\x1b[47m 1 \x1b[0m   \x1b[46m 10 \x1b[0m\n");
        }
        Seg2=(int)clock()/CLOCKS_PER_SEC;
    }
    system("Pause");
    system("cls");
    int n = ruleta[i];
    switch(n){
            case 1: if(seleccion == 1) resultadoDiversion(1,n); else resultadoDiversion(0,n); break;
            case 2: if(seleccion == 2) resultadoDiversion(2,n); else resultadoDiversion(0,n); break;
            case 5: if(seleccion == 5) resultadoDiversion(5,n); else resultadoDiversion(0,n); break;
            case 10: if(seleccion == 10) resultadoDiversion(10,n); else resultadoDiversion(0,n);break;
            case 99: if(seleccion == 99) resultadoDiversion(99,n); else resultadoDiversion(0,n);break;
            case 22: break;
    }
}

void resultadoDiversion(int multiplicador, int n){
    int Seg1,Seg2;
    Seg1=(int)clock()/CLOCKS_PER_SEC;
    Seg2=Seg1;
    int i;

    int bonus[10] = {10,20,30,40,50,60,70,80,90,100};

    if(multiplicador == 99){
        printf(AMARILLO_T "BONUS\n" RESET_COLOR);

        srand(time(NULL));
        while((Seg2-Seg1) < 10){
            if(clock() % 400 < 10){
                system("cls");
                i = rand() % 10;
                printf ( AMARILLO_T "\n BONUS :\n\n\t%d " RESET_COLOR , multiplicador = bonus[i]);
            }
            Seg2=(int)clock()/CLOCKS_PER_SEC;
        }
            printf("\nFELICIDADES GANASTE!");
            system("pause");
            system("cls");
    }else{

        if(multiplicador == 0){
            printf("\nLO SIENTO PERDISTE\n");
            system("pause");
            system("cls");
        }else{
          printf("\nFELICIDADES GANASTE!");
          system("pause");
          system("cls");
        }
    }
}
