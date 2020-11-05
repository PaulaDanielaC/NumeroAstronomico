#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "persist.h"

NumeroAstronomico *read(FILE *stream) {
    NumeroAstronomico *numero = malloc(sizeof(NumeroAstronomico));
    stream = fopen(ARCHIVO_BINARIO, "rb");
    int i = 0;

    if (stream == NULL) {
        perror("Error leyendo el archivo: \n");
        return NULL;
    }

    while (fread(&numero->entero[i], 1, sizeof(char), stream))
        i++;


    numero->longitudError = (int) strlen(numero->entero);
    printf("resultado archivo %s\n", numero->entero);
    system("pause");
    return numero;
}

FILE *print(NumeroAstronomico *num, FILE *stream) {

    if (stream == NULL) {
        perror("Error creando el archivo: \n");
        return NULL;
    }

    fwrite(num->entero, num->longitudError * sizeof(char), 1, stream);
    system("pause");
    return stream;
}

FILE *write(NumeroAstronomico *num, FILE *stream) {
    if (stream == NULL) {
        perror("Error creando el archivo: \n");
        return NULL;
    }

    fwrite(num->entero, num->longitudError * sizeof(char), 1, stream);
    system("pause");
    return stream;
}

NumeroAstronomico *scan(FILE *stream) {
    NumeroAstronomico *numero = malloc(sizeof(NumeroAstronomico));
    fflush(stdin);
    fflush(stdout);
    stream = fopen(ARCHIVO_TEXTO, "r");

    int i = 0;
    if (stream == NULL) {
        perror("Error leyendo el archivo: \n");
        return NULL;
    }

    while (fread(&numero->entero[i], sizeof(char),1, stream))
        i++;

    numero->longitudError = (int) strlen(numero->entero);
    printf("resultado archivo %s\n", numero->entero);
    system("pause");
    return numero;
}