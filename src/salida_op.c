#include <NumeroAstronomico.h>
#include <stdio.h>
#include <malloc.h>
#include <mem.h>

void ponerPuntos(NumeroAstronomico *num, char *numero);
void dividirNumero(char *numero, unsigned int cantGrupos);
void mostrar(NumeroAstronomico *num, unsigned int cantGrupos, FILE *stream) {

    char *cadena = (char*) malloc(sizeof(char) * num->longitudError);
    ponerPuntos(num, cadena);
    dividirNumero(cadena, cantGrupos);
    fprintf(stream, "%s\n", cadena);
    free(cadena);
}

void ponerPuntos(NumeroAstronomico *num, char *numero) {
    int cantPuntos;
    if ((num->longitudError % 3) != 0)
        cantPuntos = num->longitudError / 3;
    else
        cantPuntos = (num->longitudError / 3) - 1;

    int cantCaracteres = (num->longitudError - 1) + cantPuntos;
    int cantLeidos = num->longitudError;
    int cantImpresos = 0;

    while (cantCaracteres >= 0) {

        if (cantImpresos != 0 && cantImpresos != num->longitudError && cantImpresos % 3 == 0) {
            numero[cantCaracteres] = '.';
            cantCaracteres--;
        }

        numero[cantCaracteres] = num->entero[cantLeidos - 1];
        cantLeidos--;
        cantCaracteres--;
        cantImpresos++;
    }

    numero[(num->longitudError) + cantPuntos] = '\0';
}

void dividirNumero(char *numero, unsigned int cantGrupos) {
    int j = 0;
    int saltosLinea = 0;
    int longitud = (int) strlen(numero);
    unsigned int charPorLinea = (cantGrupos * 3) + cantGrupos;
    char *cadenaAux = (char *) malloc(sizeof(char) * longitud);
    int i = 0;

    if (charPorLinea > longitud) {
        return;
    }

    while (i <= charPorLinea && i < longitud) {
        cadenaAux[i] = numero[i];
        i++;

        if (i % charPorLinea == 0) {
            cadenaAux[i] = '\n';
            j = i + 1;
            saltosLinea++;
            i = 0;
            break;
        }
    }

    cantGrupos = cantGrupos - 1;
    charPorLinea = (cantGrupos * 3) + cantGrupos;

    while (j < longitud + saltosLinea) {
        if (i % charPorLinea == 0 && i != 0) {
            cadenaAux[j] = '\n';
            i = 0;
            j++;
            saltosLinea++;
        }

        cadenaAux[j] = numero[j - saltosLinea];
        i++;
        j++;
    }

    cadenaAux[j] = '\0';
    memcpy(numero, cadenaAux, strlen(cadenaAux) + 1);
}