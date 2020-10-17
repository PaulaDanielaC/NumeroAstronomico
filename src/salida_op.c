#include <NumeroAstronomico.h>
#include <stdio.h>
#include <malloc.h>

char* darVuelta(char*, int);

void mostrar(NumeroAstronomico* num, unsigned int cantGrupos, FILE* stream) {

    int cantPuntos;
    if((num->longitudError % 3) != 0)
        cantPuntos = num->longitudError / 3;
    else
        cantPuntos = (num->longitudError / 3) - 1;

    int cantCaracteres = (num->longitudError - 1) + cantPuntos;
    int cantLeidos = num->longitudError;
    int cantImpresos = 0;
    char* cadena = malloc(sizeof(char ));

    while (cantCaracteres >= 0) {
        if(cantImpresos != 0 && cantImpresos != num->longitudError && cantImpresos % 3 == 0) {
            cadena[cantCaracteres] = '.';
            cantCaracteres--;
        }

        cadena[cantCaracteres] = num->entero[cantLeidos-1];
        cantLeidos--;
        cantCaracteres--;
        cantImpresos++;
    }

    fprintf(stream, "%s", cadena);
}

char* darVuelta(char* numero, int longitud) {
    char* resultado = malloc(longitud);
    int cantMax = longitud;

    for (int i = 0; i < longitud; i++) {
        resultado[i] = numero[cantMax-1];
        cantMax--;
    }

    resultado[longitud] = '\0';
    return resultado;
}