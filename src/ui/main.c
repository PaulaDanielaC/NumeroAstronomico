#include "op_helper.h"
#include "errores.h"
#include <stdlib.h>
#include <mem.h>
#include <utils.h>

int menu(int, NumeroAstronomico *);

int main() {
    NumeroAstronomico *result = (NumeroAstronomico *) malloc(sizeof(NumeroAstronomico));
    int opcion;
    int finaliza = 0;

    printf("\n\t\t\tCALCULADORA DE NUMEROS ASTRONOMICOS DE IGNACIO GARCIA Y PAULA CHITTARO\n\n"
           "Seleccione la operacion que quiera realizar:\n");

    while (finaliza == 0) {
        printf("1.Sumar valores\n2.Verificar igualdad de dos numeros\n3.Verificar menor valor\n"
               "4.Guardar resultados\n5.Cargar resultados\n6.Salir\n\n");
        printf("Opcion:\n");
        opcion = getc(stdin);
        finaliza = menu(opcion, result);
    }

    return result->longitudError;
}

int menu(int opcion, NumeroAstronomico *result) {
    switch (opcion) {
        case 49: // TODO: Despues acomodo este case gigante
            system("cls");
            NumeroAstronomico resultado = *realizarSuma();

            if (tieneError(&resultado)) {
                imprimirError(&resultado);
                limpiarResultado(result);
                return resultado.longitudError;
            }

            memcpy(result, &resultado, sizeof(resultado.longitudError));
            return Ninguno;
        case 50:
            system("cls");
            verificarIgualdad();
            return Ninguno;
        case 51:
            system("cls");
            obtenerMenor(result);
            return Ninguno;
        case 52:
            system("cls");
            guardarResultado(result);
            return Ninguno;
        case 53:
            system("cls");
            cargarResultado();
            return Ninguno;
        case 54:
            limpiarResultado(result);
            exit(Ninguno);
        default:
            system("cls");
            printf("Opcion Invalida, ingrese nuevamente\n\n");
            return Ninguno;
    }
}