#ifndef NUMERO_ASTRONOMICO_H
#define NUMERO_ASTRONOMICO_H

#include <stdio.h>

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

/* Operaciones de creacion */
NumeroAstronomico* crearDesdeCadena(char* cadena, unsigned int longCadena); 
NumeroAstronomico* crearDesdeCifraSeguidaDeCeros(unsigned int cifra, unsigned int cantCeros);
NumeroAstronomico* crearAleatorio();

/* Operaciones de manejo de errores */
int esSecuenciaNula(NumeroAstronomico* numero);
int esSecuenciaInvalida(NumeroAstronomico* numero);
int esOverflow(NumeroAstronomico* numero);
int esPunteroNulo(NumeroAstronomico* numero);
//TipoDeError getTipoDeError(NumeroAstronomico* numero);
int esError(NumeroAstronomico* numero);

/* Operaciones de salida */
void mostrar(NumeroAstronomico numero, int lineas); //Mostrar(na, 3, stdout1)

/* Operaciones aritmeticas */
NumeroAstronomico sumar(NumeroAstronomico num1, NumeroAstronomico num2);
int sonIguales(NumeroAstronomico num1, NumeroAstronomico num2);
int esMenor(NumeroAstronomico num1, NumeroAstronomico num2);

/* De persistencia */
void read(NumeroAstronomico numero);
void write(FILE* archivo);

/* Binario */
void scan(FILE* archivo);
void print(NumeroAstronomico numero);

#endif


