#include "header/utils.h"
#include <stdlib.h>

int menu(int);

int main() {
    int opcion;
    int esOpcionInvalida = 1;

    printf("\n\t\t\tCALCULADORA DE NUMEROS ASTRONOMICOS DE IGNACIO GARCIA Y PAULA CHITTARO\n\n"
           "Seleccione la operacion que quiera realizar:\n");
    printf("1.Sumar valores\n2.Verificar igualdad de dos numeros\n3.Verificar menor valor\n"
           "4.Guardar resultados\n5.Cargar resultados\n6.Salir\n\n");

    while (esOpcionInvalida == 1) {
        printf("Opcion:");
        scanf("%d", &opcion);
        esOpcionInvalida = menu(opcion);
    }

    return 0;
}

int menu(int opcion) {
    NumeroAstronomico *result = NULL;

    switch (opcion) {
        case 1:
            system("cls");
            result = realizarSuma();
            limpiarResultado(result);
            return 0;
        case 2:
            system("cls");
            verificarIgualdad();
            return 0;
        case 3:
            system("cls");
            obtenerMenor(result);
            return 0;
        case 4:
            system("cls");
            guardarResultado(result);
            return 0;
        case 5:
            system("cls");
            result = cargarResultado();
            limpiarResultado(result);
            return 0;
        case 6:
            exit(0);
        default:
            printf("Opcion Invalida, ingrese nuevamente\n");
            return 1;
    }
}