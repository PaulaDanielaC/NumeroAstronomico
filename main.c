#include "header/utils.h"
#include <stdlib.h>
#include <mem.h>

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

    return 0;
}

int menu(int opcion, NumeroAstronomico *result) {
    switch (opcion) {
        case 49:
            system("cls");
            NumeroAstronomico resultado = *realizarSuma();
            memcpy(result, &resultado, sizeof(resultado.longitudError));
            return 0;
        case 50:
            system("cls");
            verificarIgualdad();
            return 0;
        case 51:
            system("cls");
            obtenerMenor(result);
            return 0;
        case 52:
            system("cls");
            guardarResultado(result);
            return 0;
        case 53:
            system("cls");
            cargarResultado();
            return 0;
        case 54:
            limpiarResultado(result);
            exit(0);
        default:
            system("cls");
            printf("Opcion Invalida, ingrese nuevamente\n\n");
            return 0;
    }
}