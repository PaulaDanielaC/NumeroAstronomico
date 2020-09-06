#include "NumeroAstronomico.h"
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* agregarCerosAlfinal(int);
int obtenerNumeroRandom();

/* Operaciones de creacion */

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

    numAstro->entero = malloc(cifra);
    sprintf(numAstro->entero, "%d", cifra);
    numAstro->longitudError = Ninguno; //TODO: Calcular long del numero, too tired for that now
    return numAstro;
}

/* Operaciones de manejo de errores */

int esSecuenciaNula(NumeroAstronomico* numero) {
    return numero->entero == NULL;
}

int esSecuenciaInvalida(NumeroAstronomico* numero) {
    return numero->longitudError == CadenaInvalida;
}

int esOverflow(NumeroAstronomico* numero) {
    return numero->longitudError == Overflow;
}

int esPunteroNulo(NumeroAstronomico* numero) {
    return numero == NULL;
}

/*TipoDeError getTipoDeError(NumeroAstronomico* numero) {
    Preguntar esto
}*/

/* Operacion auxiliares */

int obtenerNumeroRandom() {
    time_t sysTime;
    srand((unsigned) time(&sysTime));
    return rand();
}

char* agregarCerosAlfinal(int cantidad) {
    char* cadenaCeros = malloc(cantidad);
    memset(cadenaCeros, '0', cantidad);
    return cadenaCeros;
}


// Pa' probar, el main hay que volarlo
int main() {
    NumeroAstronomico* num = crearDesdeCadena("345748765345435000000000000000", 30);
    printf("crearDesdeCadena: %s\n", num->entero);
    printf("longitud: %i\n", num->longitudError);

    num = crearDesdeCifraSeguidaDeCeros(15, 10);
    printf("crearDesdeCifraSeguidaDeCeros: %s\n", num->entero);
    printf("longitud: %i\n", num->longitudError);

    num = crearAleatorio();
    printf("crearAleatorio: %s\n", num->entero);
    printf("longitud: %i\n", num->longitudError);

    free(num->entero);
    free(num);
    return 0;
}