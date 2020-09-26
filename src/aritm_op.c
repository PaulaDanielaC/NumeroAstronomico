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
    NumeroAstronomico *resultado = malloc(sizeof(NumeroAstronomico));
    resultado->entero = malloc(CHAR_LIMIT);
    int digitoResult = 0;
    int longitud = 0;
    int carry = 0;

    for (int i = 0; i < obtenerNumMasDigitos(num1->longitudError, num2->longitudError); i++) {
        if (num1->entero[i] == '\n') {
            char* cadenaRestante = malloc(CHAR_LIMIT - 2);
            memcpy(cadenaRestante, num2->entero, CHAR_LIMIT-2-i);
            break;
        }

        if(num2->entero[i] == '\n') {
            char* cadenaRestante = malloc(CHAR_LIMIT);
            memcpy(cadenaRestante, num1->entero, CHAR_LIMIT-2-i);
            break;
        }

        int d1 = ((int)num1->entero[i]) - ((int)'0');
        int d2 = ((int)num2->entero[i]) - ((int)'0');
        digitoResult = d1 + d2 + carry;

        if (digitoResult > 9) {
            digitoResult = digitoResult - 10;
            carry = 1;
        } else {
            carry = 0;
        }

        itoa(digitoResult, &resultado->entero[i], 10);
        longitud++;
    }

//    memcpy(&result->entero[2], result->entero, longitudRes + 2);
//    if (longitud > 101) {
//
//    }


    printf("resultado: %s\n", resultado->entero);
    return resultado;
}

int obtenerNumMasDigitos(int longNum1, int longNum2) {
    if (longNum1 > longNum2) {
        return longNum1;
    }

    return longNum2;
}

int sonIguales(NumeroAstronomico *num1, NumeroAstronomico *num2) {

    if (getTipoDeError(num1) == Ninguno || getTipoDeError(num2) == Ninguno) {
        if(strcmp(num1->entero, num2->entero) == 0) {
            printf("Son iguales\n");
            return 1;
        }

        printf("Son distintos\n");
        return 0;
    }
}

int esMenor(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    if (getTipoDeError(num1) == Ninguno || getTipoDeError(num2) == Ninguno) {
        if(strcmp(num1->entero, num2->entero) < 0) {
            printf("Es menor %s", num1->entero);
            return 1;
        }

        printf("Es menor %s", num2->entero);
        return 0;
    }
}