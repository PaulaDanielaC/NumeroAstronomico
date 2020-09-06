#ifndef ERRORES_H
#define ERRORES_H

#include "NumeroAstronomico.h"

int esSecuenciaNula(NumeroAstronomico*);
int esSecuenciaInvalida(NumeroAstronomico*);
int esOverflow(NumeroAstronomico*);
int esPunteroNulo(NumeroAstronomico*);
//TipoDeError getTipoDeError(NumeroAstronomico*);
int esError(NumeroAstronomico*);

#endif