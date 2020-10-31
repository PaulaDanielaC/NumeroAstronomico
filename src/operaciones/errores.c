#include <stdlib.h>
#include <stdio.h>
#include "errores.h"

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

int tieneError(NumeroAstronomico* numero) {
    return numero->longitudError < 0;
}

int getTipoDeError(NumeroAstronomico* numero) {

    if (numero->longitudError >= 0)
        return Ninguno;
    else
        return numero->longitudError;
}

void imprimirError(NumeroAstronomico* num) {

    if (esSecuenciaNula(num))
        printf("El numero ingresado es nulo.\n");

    if (esSecuenciaInvalida(num))
        printf("El numero ingresado es invalido.\n");

    if (esOverflow(num))
        printf("El numero presento un error de overflow.\n");

    if (esPunteroNulo(num))
        printf("El puntero a la estructura es nulo.\n");

    system("pause");
}