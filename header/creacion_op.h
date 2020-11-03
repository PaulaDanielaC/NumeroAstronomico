#ifndef CREACION_OP_H
#define CREACION_OP_H

#include <NumeroAstronomico.h>

NumeroAstronomico* crearDesdeCadena(char* cadena);
NumeroAstronomico* crearDesdeCifraSeguidaDeCeros(unsigned int, unsigned int);
NumeroAstronomico* crearAleatorio();

#endif