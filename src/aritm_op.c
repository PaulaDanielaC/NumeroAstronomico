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
    int long1 = num1->longitudError-1;
    int long2 = num2->longitudError-1;
    int numMasLargo = obtenerNumMasDigitos(long1, long2)-1;
    int carry = 0;

    while(long1 != 0 || long2 != 0) {

        int d1 = ((int)num1->entero[long1-1]) - ((int)'0');
        int d2 = ((int)num2->entero[long2-1]) - ((int)'0');
        digitoResult = d1 + d2 + carry;

        if (digitoResult > 9) {
            digitoResult = digitoResult - 10;
            carry = 1;
        } else {
            carry = 0;
        }

        itoa(digitoResult, &resultado->entero[numMasLargo], 10);
        printf("result %d\n", digitoResult);
        long1--;
        long2--;
        numMasLargo--;
    }

    resultado->entero[numMasLargo] = '\n';
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