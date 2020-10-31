#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "persist.h"

NumeroAstronomico *read(FILE *stream) {
    stream = fopen(ARCHIVO_TEXTO, "r");
    if (stream == NULL) {
        perror("Error leyendo el archivo: \n");
        return NULL;
    }

    return stream;
}

FILE *print(NumeroAstronomico *num, FILE *stream) {
    if (stream == NULL) {
        perror("Error leyendo el archivo: \n");
        return NULL;
    }

    fwrite(num->entero, strlen(num->entero) + 1, 1, stream);
    return stream;
}

FILE *write(NumeroAstronomico *numero, FILE *stream) {
    if (stream == NULL) {
        perror("Error leyendo el archivo: \n");
        return NULL;
    }

    fwrite(numero->entero, strlen(numero->entero) + 1, 1, stream);
    return stream;
}

NumeroAstronomico *scan(FILE *stream) {
    stream = fopen(ARCHIVO_TEXTO, "r");
    NumeroAstronomico *numero = malloc(sizeof(NumeroAstronomico));

    if (stream == NULL) {
        perror("Error leyendo el archivo: \n");
        return NULL;
    }

    while (stream) {
        fread(numero->entero, 1, sizeof(char), stream);
    }

    printf("resultado archivo %s\n", numero->entero);

    return numero;
}