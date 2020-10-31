#include <NumeroAstronomico.h>
#include <creacion_op.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "../header/errores.h"

static char* agregarCerosAlfinal(unsigned int);
static int obtenerNumeroRandom();

NumeroAstronomico* crearDesdeCifraSeguidaDeCeros(unsigned int cifra, unsigned int cantCeros) {
    NumeroAstronomico* numAstro = (NumeroAstronomico*) malloc(sizeof(NumeroAstronomico));

    if (cifra == 0) { 
        numAstro->longitudError = CadenaNula; 
        return numAstro;
    }

    char* numero = (char*) malloc(cifra + cantCeros);
    sprintf(numero, "%d\n", cifra);

    numAstro->entero = numero;
    memcpy(numAstro->entero + 2, agregarCerosAlfinal(cantCeros), cantCeros); //<-- TODO: Sacar ese 2 hardcodeado de ahi
    numAstro->longitudError = cifra + cantCeros;
    return numAstro;
}

NumeroAstronomico* crearAleatorio() {
    NumeroAstronomico* numAstro = malloc(sizeof(NumeroAstronomico));
    int cifra = obtenerNumeroRandom();
    printf("Numero que genere: %i\n", cifra);
    numAstro->entero = malloc(cifra);
    sprintf(numAstro->entero, "%d\n", cifra);
    numAstro->longitudError = (int) strlen(numAstro->entero);
    return numAstro;
}

/* Operacion auxiliares */

static int obtenerNumeroRandom() {  //TODO: Ver esto!
    time_t sysTime;
    srand((unsigned) time(&sysTime));
    return rand();
}

static char* agregarCerosAlfinal(unsigned int cantidad) {
    char* cadenaCeros = malloc(cantidad);
    memset(cadenaCeros, '0', cantidad);
    return cadenaCeros;
}