#include "../header/aritm_op.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int obtenerNumMasDigitos(int, int);

NumeroAstronomico *sumar(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    NumeroAstronomico *result = malloc(sizeof(NumeroAstronomico));
    char *pEnd;
    unsigned long op1 = strtol(num1->entero, &pEnd, 10);
    unsigned long op2 = strtol(num2->entero, &pEnd, 10);
    unsigned long resultado = op1 + op2;

//  Primer 0 overflow
//  Segundo 0 carry

    result->entero = malloc(1000); // TODO: Cambiar tamaño de malloc
    itoa(resultado, result->entero, 10); // TODO: Cambiar funcion que maneje longs
    int longitudRes = strlen(result->entero);
    memcpy(&result->entero[2], result->entero, longitudRes + 2);

    result->entero[0] = '0';
//    TODO Manejar overflow
    int mayorDigitos = obtenerNumMasDigitos(num1->longitudError, num2->longitudError);
    if (longitudRes > mayorDigitos) {
        result->entero[1] = '1';
    } else {
        result->entero[1] = '0';
    }

    result->longitudError = longitudRes;
    return result;
}

int obtenerNumMasDigitos(int longNum1, int longNum2) {
    if (longNum1 > longNum2) {
        return longNum1;
    }

    return longNum2;
}

int sonIguales(NumeroAstronomico *num1, NumeroAstronomico *num2) {

    int longNum1 = num1->longitudError;
    int longNum2 = num2->longitudError;

    if (longNum1 != longNum2) {
        return 0;
    }

    for (int i = 0; i < longNum1; i++) {
        if (num1->entero[i] != num2->entero[i]) {
            return 0;
        }
    }

    return 1;
}

int esMenor(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    return 0;
}

