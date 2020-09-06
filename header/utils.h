#ifndef UTILS_H
#define UTILS_H

#include "NumeroAstronomico.h"
#include <stdio.h>

NumeroAstronomico* realizarSuma();
void verificarIgualdad(NumeroAstronomico*);
void obtenerMenor(NumeroAstronomico*);
void guardarResultado(NumeroAstronomico*);
NumeroAstronomico* cargarResultado();
void limpiarResultado(NumeroAstronomico*);

#endif