#include <NumeroAstronomico.h>
#include <stdio.h>
#include <malloc.h>

char* darVuelta(char*, int);

void mostrar(NumeroAstronomico* num, unsigned int cantGrupos, FILE* stream) {
    int i = 0;

    while(i < 9) {

        if(i != 0 && i % cantGrupos == 0) {
            fprintf(stream, "%c", '.');
        }

        fprintf(stream, "%c", num->entero[i]);
        i++;
    }

    fprintf(stream, "%s", ".");
    int gruposImpresos = 0;

    while (i < num->longitudError) {

        if(i != 9 && i % cantGrupos == 0) {
            fprintf(stream, "%c", '.');
            gruposImpresos++;
        }

        if(i % 3 == 0 && gruposImpresos % 2 == 0) {
            fprintf(stream, "%c", '\n');
        }

        fprintf(stream, "%c", num->entero[i]);
        i++;
    }

    fprintf(stream, "%c", '\n');

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