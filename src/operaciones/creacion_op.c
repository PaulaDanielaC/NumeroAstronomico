#include <NumeroAstronomico.h>
#include <creacion_op.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "errores.h"

static char *agregarCerosAlfinal(unsigned int);

static int obtenerNumeroRandom();

NumeroAstronomico *crearDesdeCifraSeguidaDeCeros(unsigned int cifra, unsigned int cantCeros) {
    NumeroAstronomico *numAstro = (NumeroAstronomico *) malloc(sizeof(NumeroAstronomico));

    if (cifra == 0) {
        numAstro->longitudError = CadenaNula;
        return numAstro;
    }

    char* numero = malloc(cifra);
    sprintf(numero, "%d", cifra);
    char* ceros = agregarCerosAlfinal(cantCeros);
    strcat(numero, ceros);

    numAstro->entero = numero;
    numAstro->longitudError = cifra + cantCeros;
    return numAstro;
}

NumeroAstronomico *crearAleatorio() {
    NumeroAstronomico *numAstro = malloc(sizeof(NumeroAstronomico));
    int cifra = obtenerNumeroRandom();
    printf("Numero que genere: %i\n", cifra);
    numAstro->entero = malloc(cifra);
    sprintf(numAstro->entero, "%d\n", cifra);
    numAstro->longitudError = (int) strlen(numAstro->entero);
    return numAstro;
}

NumeroAstronomico *crearDesdeCadena(char *cadena) {
    NumeroAstronomico *num = (NumeroAstronomico *) malloc(sizeof(NumeroAstronomico));
    int longitud = (int) strlen(cadena);
    num->entero = (char*) malloc(longitud);

    if (cadena != NULL) {
        memcpy(num->entero, cadena, longitud + 1);
        num->entero[longitud] = '\0';
        num->longitudError = longitud;
        free(cadena);
    } else {
        num->longitudError = CadenaInvalida;
    }

    return num;
}

/* Operacion auxiliares */

static int obtenerNumeroRandom() {
    time_t sysTime;
    srand((unsigned) time(&sysTime));
    return rand();
}

static char *agregarCerosAlfinal(unsigned int cantidad) {
    char *cadenaCeros = malloc(cantidad + 1);
    memset(cadenaCeros, '0', cantidad);
    cadenaCeros[cantidad] = '\0';
    return cadenaCeros;
}