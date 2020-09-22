#include "../header/aritm_op.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../header/errores.h"

#define CHAR_LIMIT 103
#define OVERFLOW 0
#define CARRY 1

int obtenerNumMasDigitos(int, int);

NumeroAstronomico *sumar(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    NumeroAstronomico *result = malloc(sizeof(NumeroAstronomico));
    char *pEnd;
    printf("El num1 es %s\n", num1->entero);
    long long op1 = strtoll(num1->entero, &pEnd, 10);
    long long op2 = strtoll(num2->entero, &pEnd, 10);
    printf("El num1 es %lld\n", op1);
    printf("El num2 es %lld\n", op2);
    long long resultado = op1 + op2;
    printf("El resultado double es: %lld\n", resultado);

    result->entero = malloc(CHAR_LIMIT);
    sprintf(result->entero, "%lld\n", resultado);
    unsigned int longitudRes = strlen(result->entero);

    memcpy(&result->entero[2], result->entero, longitudRes + 2);

    if(longitudRes > 100) {
        result->entero[OVERFLOW] = '1';
    } else {
        result->entero[OVERFLOW] = '0';
    }

    int mayorDigitos = obtenerNumMasDigitos(strlen(num1->entero), strlen(num2->entero)); // TODO Este carry funca como el ogt
    if (longitudRes > mayorDigitos) {
        result->entero[CARRY] = '1';
    } else {
        result->entero[CARRY] = '0';
    }

    result->longitudError = (int) longitudRes;
    return result;
}

int obtenerNumMasDigitos(int longNum1, int longNum2) {
    if (longNum1 > longNum2) {
        return longNum1;
    }

    return longNum2;
}

int sonIguales(NumeroAstronomico *num1, NumeroAstronomico *num2) {

    if (getTipoDeError(num1) == Ninguno || getTipoDeError(num2) == Ninguno) {
        if(strcmp(num1->entero, num2->entero) == 0)
            return 1;
    }

    return 0;
}

int esMenor(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    if (getTipoDeError(num1) == Ninguno || getTipoDeError(num2) == Ninguno) {
        int resultado = strcmp(num1->entero, num2->entero);
        printf("strcmp %i\n", resultado);
        if(resultado < 0)
            return 1;
    }

    return 0;
}

