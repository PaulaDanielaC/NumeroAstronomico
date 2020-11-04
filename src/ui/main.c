#include "ui_helper.h"
#include "errores.h"
#include <stdlib.h>

void menu(NumeroAstronomico *);

int main() {
    printf("\n\t\t\tCALCULADORA  DE NUMEROS ASTRONOMICOS DE IGNACIO GARCIA Y PAULA CHITTARO\n\n"
           "Seleccione la operacion que quiera realizar:\n");

    NumeroAstronomico *result = (NumeroAstronomico *) malloc(sizeof(NumeroAstronomico));
    result->longitudError = Ninguno;

    while (!tieneError(result))
        menu(result);

    int errorCode = getTipoDeError(result);
    imprimirError(result);
    limpiarResultado(result);
    return errorCode;
}

void menu(NumeroAstronomico *result) {
    printf("1.Sumar valores\n2.Verificar igualdad de dos numeros\n3.Verificar menor valor\n"
           "4.Guardar resultados\n5.Cargar resultados\n6.Salir\n\nOpcion:\n");
    int opcion = getc(stdin);

    switch (opcion) {
        case 49:
            realizarSuma(result);
            break;
        case 50:
            verificarIgualdad();
            break;
        case 51:
            obtenerMenor(result);
            break;
        case 52:
            guardarResultado(result);
            break;
        case 53:
            cargarResultado();
            break;
        case 54:
            limpiarResultado(result);
            exit(Ninguno);
        default:
            printf("Opcion Invalida, ingrese nuevamente\n\n");
            break;
    }

    system("cls");
}