#include <NumeroAstronomico.h>
#include <stdio.h>
#include <malloc.h>
#include <mem.h>

void ponerPuntos(NumeroAstronomico* num, char* numero);
void dividirNumero(char* numero, unsigned int cantGrupos);

void mostrar(NumeroAstronomico* num, unsigned int cantGrupos, FILE* stream) {

    char* cadena = malloc(sizeof(char));
    ponerPuntos(num, cadena);
    dividirNumero(cadena, cantGrupos);
    printf("termine de operar el num\n");
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

    numero[(num->longitudError) + cantPuntos] = '\0';
}

void dividirNumero(char* numero, unsigned int cantGrupos) {

    int longitud = (int) strlen(numero);
    printf("cant de numeros %d\n", longitud);
    int charPorLinea = (cantGrupos * 3) + cantGrupos;
    char* cadenaAux = malloc(sizeof(char) * longitud);
    int i = 0;

    while (i < charPorLinea && i < longitud) {
        cadenaAux[i] = numero[i];
        i++;
    }

    cadenaAux[i] = '\n';
    i++;
    printf("Le meti el barra n\n");

    int charRestantes = longitud - charPorLinea;
    printf("charRestantes %d\n", charRestantes);
    cantGrupos = cantGrupos - 1;
    printf("cantGrupos %d\n", cantGrupos);
    charPorLinea = (cantGrupos * 3) + cantGrupos;
    printf("charPorLinea %d\n", charPorLinea);
    int j = i;
    i = 0;
    int k = 1;

    while (i < charRestantes) {
        if (i % charPorLinea == 0 && i != 0) {
            cadenaAux[j] = '\n';
            i++;
            j++;
            k++;
        }

        cadenaAux[j] = numero[j-k];
        i++;
        j++;
    }

    cadenaAux[i] = '\0';
    printf("numero como deberia quedar %s\n", cadenaAux);
//    memcpy(numero, cadenaAux, strlen(cadenaAux) + 1);
//    numero = &cadenaAux;
}