#include <NumeroAstronomico.h>
#include <stdio.h>
#include <malloc.h>
#include <mem.h>

void ponerPuntos(NumeroAstronomico* num, char* numero);
void ponerEspacios(char* numero, unsigned int cantGrupos);

void mostrar(NumeroAstronomico* num, unsigned int cantGrupos, FILE* stream) {

    char* cadena = malloc(sizeof(char));
    ponerPuntos(num, cadena);
    ponerEspacios(cadena, cantGrupos);
    fprintf(stream, "%s\n", cadena);
}

void ponerPuntos(NumeroAstronomico* num, char* numero) {
    int cantPuntos;
    if((num->longitudError % 3) != 0)
        cantPuntos = num->longitudError / 3;
    else
        cantPuntos = (num->longitudError / 3) - 1;

    int cantCaracteres = (num->longitudError - 1) + cantPuntos;
    int cantLeidos = num->longitudError;
    int cantImpresos = 0;

    while (cantCaracteres >= 0) {

        if(cantImpresos != 0 && cantImpresos != num->longitudError && cantImpresos % 3 == 0) {
            numero[cantCaracteres] = '.';
            cantCaracteres--;
        }

        numero[cantCaracteres] = num->entero[cantLeidos-1];
        cantLeidos--;
        cantCaracteres--;
        cantImpresos++;
    }
}

void ponerEspacios(char* numero, unsigned int cantGrupos) {

    int longitud = (int) strlen(numero);
    char* cadenaAux;


}