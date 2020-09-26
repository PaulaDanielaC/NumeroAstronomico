#include <NumeroAstronomico.h>
#include <creacion_op.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "../header/errores.h"

static char* agregarCerosAlfinal(int);
static int obtenerNumeroRandom();

NumeroAstronomico* crearDesdeCadena(char* cadena) {
    NumeroAstronomico* numAstro = malloc(sizeof(NumeroAstronomico));
    int longitud = (int) strlen(cadena);
    numAstro->entero = cadena;
    printf("Longitud %i\n", longitud); //TODO: Porque hiciste eso Paux????
    numAstro->longitudError = longitud;
    return numAstro;
}

NumeroAstronomico* crearDesdeCifraSeguidaDeCeros(unsigned int cifra, unsigned int cantCeros) {
    NumeroAstronomico* numAstro = malloc(sizeof(NumeroAstronomico));

    if (cifra == 0) { 
        numAstro->longitudError = CadenaNula; 
        return numAstro;
    }

    char* numero = malloc(cifra + cantCeros);
    sprintf(numero, "%d", cifra);

    numAstro->entero = numero;
    memcpy(numAstro->entero + 2, agregarCerosAlfinal(cantCeros), cantCeros); //<-- TODO: Sacar ese 2 hardcodeado de ahi
    numAstro->longitudError = cifra + cantCeros;
    return numAstro;
}

NumeroAstronomico* crearAleatorio() {
    NumeroAstronomico* numAstro = malloc(sizeof(NumeroAstronomico));
    int cifra = obtenerNumeroRandom();
    printf("Numero que genere %i", cifra);
    numAstro->entero = malloc(cifra);
    sprintf(numAstro->entero, "%d", cifra);
    numAstro->longitudError = strlen(numAstro->entero);
    return numAstro;
}

/* Operacion auxiliares */

static int obtenerNumeroRandom() {
    time_t sysTime;
    srand((unsigned) time(&sysTime));
    return rand();
}

static char* agregarCerosAlfinal(int cantidad) {
    char* cadenaCeros = malloc(cantidad);
    memset(cadenaCeros, '0', cantidad);
    return cadenaCeros;
}