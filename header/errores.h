#ifndef ERRORES_H
#define ERRORES_H

#include "NumeroAstronomico.h"

int esSecuenciaNula(NumeroAstronomico*);
int esSecuenciaInvalida(NumeroAstronomico*);
int esOverflow(NumeroAstronomico*);
int esPunteroNulo(NumeroAstronomico*);
int getTipoDeError(NumeroAstronomico*);
int tieneError(NumeroAstronomico*);
void imprimirError(NumeroAstronomico*);

enum TipoDeError {
    Ninguno = 0,
    CadenaNula = -1,
    CadenaInvalida = -2,
    Overflow = -3 ,
    PunteroNulo = -4,
    Error = -5
};

#endif