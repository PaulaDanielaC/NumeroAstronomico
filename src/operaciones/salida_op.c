#include <NumeroAstronomico.h>
#include <stdio.h>
#include <malloc.h>
#include <ui_helper.h>

FILE *mostrar(NumeroAstronomico *num, unsigned int cantGrupos, FILE *stream) {

    char *cadena = num->entero;
    ponerPuntos(num, cadena);
    dividirNumero(cadena, cantGrupos);
    fprintf(stream, "%s\n", cadena);
    system("pause");

    if (stream != stdout)
        fclose(stream);

    return stream;
}