#ifndef PERSIST_H
#define PERSIST_H

#include <stdio.h>
#include "NumeroAstronomico.h"

#define ARCHIVO_TEXTO "resultado_texto.txt"
#define ARCHIVO_BINARIO "resultado_binario.txt"

FILE* print(NumeroAstronomico*, FILE*);
NumeroAstronomico* read(FILE*);
FILE* write(NumeroAstronomico*, FILE*);
NumeroAstronomico* scan(FILE*);

#endif