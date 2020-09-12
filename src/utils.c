#include "../header/utils.h"
#include "../header/aritm_op.h"
#include "../header/creacion_op.h"
#include "../header/errores.h"
#include "../header/persist.h"
#include "../header/salida_op.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* string;
    unsigned int longitud;
} Texto;

NumeroAstronomico* crearNumero();
Texto* obtenerDigitosInput();
int opcion;

NumeroAstronomico* realizarSuma() {
    NumeroAstronomico* num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("Segundo valor:\n");
    num2 = crearNumero();

    printf("Ahora suma:\n");
    NumeroAstronomico* result = sumar(num1, num2);
    mostrar(result, 3);
    return result;
}

void verificarIgualdad() {
    NumeroAstronomico* num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("Segundo valor:\n");
    num2 = crearNumero();

    int verificaIgualdad = sonIguales(num1, num2);
    printf("%i\n", verificaIgualdad); //TODO: Armar mensaje
}

void obtenerMenor(NumeroAstronomico* num1) {
    NumeroAstronomico* num2;

    printf("Especificar otro valor:\n");
    num2 = crearNumero();
    esMenor(num1, num2);
}

void guardarResultado(NumeroAstronomico* num) {
    // TODO: Implementar
}

NumeroAstronomico* cargarResultado() {
    // TODO: Implementar
    NumeroAstronomico* num;
    return num;
}

void limpiarResultado(NumeroAstronomico* num) {
    free(num->entero);
    free(num);
}

/* Funciones auxiliares */

Texto* obtenerDigitosInput() {
    // Si tengo overflow y carry para que hice esta funcion? So many questions... 😵

    Texto* texto = malloc(sizeof(Texto));
    unsigned int cantMax = 128;
    unsigned int tamActual = 0;
    texto->string = malloc(cantMax + 2); //Para overflow y carry
    tamActual = cantMax;

//    TODO: Do-while saco ese if
//    TODO: Verificar que sean unicamente valores numericos
//    TODO: Sacar todos estos comments
    if (texto->string != NULL) {
        int caracter = EOF;
        unsigned int cant = 0;
        fflush(stdin);
        while (( caracter = getchar() ) != '\n' && caracter != EOF) {
            texto->string[cant++] = (char) caracter; //Ese casteo es una cagada
            if(cant == tamActual) {
                tamActual = cant+cantMax;
                texto->string = realloc(texto->string, tamActual + 2); //Para overflow y carry
            }
        }

//      Re horrible esto, I know
        /*memcpy(&texto->string[2], texto->string, cant);
        texto->string[0] = '0';
        texto->string[1] = '0';
        texto->string[cant+2] = '\0';

        printf("%s\n", texto->string);*/

        texto->longitud = cant;
    }

    return texto;
}

NumeroAstronomico* crearNumero() {
    NumeroAstronomico* num;
    Texto* string;

    printf("1.Ingresar valor\n2.Ingresar cifra significativa y cantidad de ceros\n"
           "3.Crear numero aleatorio\n");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
        string = obtenerDigitosInput();
        num = crearDesdeCadena(string->string, string->longitud);
        break;
    case 2:
        num = crearDesdeCifraSeguidaDeCeros();
        break;
    case 3:
        num = crearAleatorio();
        break;        
    default:
        printf("Opcion invalida\n");
        break;
    }

    return num;
}