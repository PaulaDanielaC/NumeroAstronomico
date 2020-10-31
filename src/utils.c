#include <stdio.h>
#include <errores.h>
#include <stdlib.h>
#include "utils.h"

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