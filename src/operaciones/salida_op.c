#include <NumeroAstronomico.h>
#include <stdio.h>
#include <malloc.h>
#include <ui_helper.h>

FILE* mostrar(NumeroAstronomico *num, unsigned int cantGrupos, FILE *stream) {

    char *cadena = (char*) malloc(sizeof(char) * num->longitudError);
    ponerPuntos(num, cadena);
    dividirNumero(cadena, cantGrupos);
    fprintf(stream, "%s\n", cadena);
    system("pause");

    return stream;
}