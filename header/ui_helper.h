#ifndef UTILS_H
#define UTILS_H

#include "NumeroAstronomico.h"
#include <stdio.h>

void realizarSuma(NumeroAstronomico*);
void verificarIgualdad();
void obtenerMenor();
void guardarResultado(NumeroAstronomico*);
void cargarResultado();
void limpiarResultado(NumeroAstronomico*);
void ponerPuntos(NumeroAstronomico *num, char *numero);
void dividirNumero(char *numero, unsigned int cantGrupos);

#endif