#include "header/utils.h"
#include <stdlib.h>

int main() {
    int opcion;
    NumeroAstronomico *result;

    printf("Calculadora de Numeros Astronomicos\nSeleccione la operacion que quiera realizar:\n");
    printf("1.Sumar valores\n2.Verificar igualdad de dos numeros\n3.Verificar menor valor\n"
           "4.Guardar resultados\n5.Cargar resultados\n6.Salir\n");
    scanf("%d", &opcion);

    switch ((int) opcion) {
        case 1:
            system("cls");
            result = realizarSuma();
            limpiarResultado(result);
            break;
        case 2:
            system("cls");
            verificarIgualdad();
            break;
        case 3:
            system("cls");
            obtenerMenor(result);
            break;
        case 4:
            system("cls");
            guardarResultado(result);
            break;
        case 5:
            system("cls");
            result = cargarResultado();
            limpiarResultado(result);
            break;
        case 6:
            exit(0);
        default:
            printf("Opcion invalida\n");
            break;
    }

    return 0;
}