#include <NumeroAstronomico.h>
#include <creacion_op.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "../header/errores.h"

static char* agregarCerosAlfinal(int);
static int obtenerNumeroRandom();

NumeroAstronomico* crearDesdeCadena(char* cadena, unsigned int longCadena) {
    NumeroAstronomico* numAstro = malloc(sizeof(NumeroAstronomico));

    for (int i = 0; i < longCadena; i++) {
        if (!isdigit(cadena[i])) {
            numAstro->longitudError = CadenaInvalida;
            return numAstro;        
        }
    }

    numAstro->entero = cadena;
    numAstro->longitudError = longCadena;
    return numAstro;
}

NumeroAstronomico* crearDesdeCifraSeguidaDeCeros() {
    NumeroAstronomico* numAstro = malloc(sizeof(NumeroAstronomico));
    unsigned int cifra;
    unsigned int cantCeros;

    printf("Ingrese la cifra\n");
    scanf("%d", &cifra);
    printf("Ingrese la cantidad de ceros\n");
    scanf("%d", &cantCeros);

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