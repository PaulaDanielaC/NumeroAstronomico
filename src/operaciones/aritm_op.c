#include "aritm_op.h"
#include <stdlib.h>
#include <string.h>
#include "errores.h"

void setOverflowDigit(NumeroAstronomico *, int, int);

int obtenerNumMasDigitos(int, int);

int checkCarry(int *);

NumeroAstronomico *sumar(NumeroAstronomico *num1, NumeroAstronomico *num2) { //Documentado
    NumeroAstronomico *resultado = (NumeroAstronomico *) malloc(sizeof(NumeroAstronomico));
    int numMasLargo = obtenerNumMasDigitos(num1->longitudError, num2->longitudError);
    resultado->entero = malloc(numMasLargo + 1);
    int long1 = num1->longitudError - 1;
    int long2 = num2->longitudError - 1;
    int index = numMasLargo - 1;
    int digitoResultado;
    int carry = 0;

    while (long1 != -1 && long2 != -1) {
        int d1 = ((int) num1->entero[long1]) - ((int) '0');
        int d2 = ((int) num2->entero[long2]) - ((int) '0');

        digitoResultado = d1 + d2 + carry;
        carry = checkCarry(&digitoResultado);
        resultado->entero[index] = (char) (digitoResultado + '0');
        long1--;
        long2--;
        index--;
    }

    while (long1 != -1) {
        int d1 = ((int) num1->entero[long1]) - ((int) '0');

        digitoResultado = d1 + carry;
        carry = checkCarry(&digitoResultado);
        resultado->entero[index] = (char) (digitoResultado + '0');
        long1--;
        index--;
    }

    while (long2 != -1) {
        int d2 = ((int) num2->entero[long2]) - ((int) '0');

        digitoResultado = d2 + carry;
        carry = checkCarry(&digitoResultado);
        resultado->entero[index] = (char) (digitoResultado + '0');
        long2--;
        index--;
    }

    setOverflowDigit(resultado, carry, numMasLargo);
    return resultado;
}

int sonIguales(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    if (strcmp(num1->entero, num2->entero) == 0) {
        return 1;
    }

    return 0;
}

int esMenor(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    if (strcmp(num1->entero, num2->entero) < 0) {
        return 1;
    }

    return 0;
}

int checkCarry(int *resultado) {
    int carryDigit;
    if (*resultado > 9) {
        *resultado = *resultado - 10;
        carryDigit = 1;
    } else {
        carryDigit = 0;
    }

    return carryDigit;
}

void setOverflowDigit(NumeroAstronomico *numero, int carry, int longitud) {
    if (carry != 0) {
        if ((longitud + carry) > NUM_LIMIT) {
            numero->longitudError = Overflow;
            return;
        } else { //Habria que ver que ese else funcione bien, me da mala espina
            memcpy(&numero->entero[1], numero->entero, longitud + 2);
            numero->entero[0] = (char) (carry + '0');
            numero->longitudError = longitud + 1;
        }
    }

    numero->entero[longitud] = '\0';
    numero->longitudError = longitud;
}

int obtenerNumMasDigitos(int longNum1, int longNum2) {
    if (longNum1 > longNum2) {
        return longNum1;
    }

    return longNum2;
}