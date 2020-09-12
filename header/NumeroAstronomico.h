#ifndef NUMERO_ASTRONOMICO_H
#define NUMERO_ASTRONOMICO_H

typedef struct {
  char* entero;
  int longitudError;
} NumeroAstronomico;

enum TipoDeError {
    Ninguno = 0,
    CadenaNula = -1,
    CadenaInvalida = -2,
    Overflow = -3 ,
    PunteroNulo = -4,
    Error = -5
};

#endif


