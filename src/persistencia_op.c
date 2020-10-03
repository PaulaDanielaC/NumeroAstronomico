#include <string.h>
#include <stdio.h>
#include "persist.h"

void read(NumeroAstronomico* numero) {

}

void write(NumeroAstronomico* numero, FILE* archivo) {
    printf("Llegue al write\n");
    fwrite(numero->entero, strlen(numero->entero) + 1, 1, archivo);
    fclose(archivo);
}