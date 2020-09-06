#include "errores.h"
#define NULL 0

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