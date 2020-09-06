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
    Overflow = -3 
};

// Digito mas significativo: Adelante
// valor numerico del digito o codigo asociado al simbolo : Valor numerico
// Como marcamos errores(enum) y longitud del numero
// Como manejamos carry y overflow <--- ni idea

/* De persistencia */
//void read(NumeroAstronomico numero);
//void write(FILE* archivo);

/* Binario */
//void scan(FILE* archivo);
//void print(NumeroAstronomico numero);

#endif


