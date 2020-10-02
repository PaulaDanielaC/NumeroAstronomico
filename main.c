#include "header/utils.h"
#include <stdlib.h>

int main() {
    int opcion;
    NumeroAstronomico *result;

    printf("\n                         CALCULADORA DE NUMEROS ASTRONOMICOS DE IGNACIO GARCIA Y PAULA CHITTARO\n\n"
           "Seleccione la operacion que quiera realizar:\n");
    printf("1.Sumar valores\n2.Verificar igualdad de dos numeros\n3.Verificar menor valor\n"
           "4.Guardar resultados\n5.Cargar resultados\n6.Salir\n");
    printf("Opcion:");
    scanf("%d", &opcion);

        switch (opcion) {
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
                printf("Opcion Invalida");
                break;
        }

        //TODO: Ver si se puede modificar algo del menu. Porque no me gusta
        // Que cuando nos diga opción invalida se termine la ejecucion

        return 0;

}