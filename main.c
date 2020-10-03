#include "header/utils.h"
#include <stdlib.h>

int menu(int, NumeroAstronomico*);

int main() {
    int opcion;
    int finaliza = 1;
    NumeroAstronomico *result = NULL;

    printf("\n\t\t\tCALCULADORA DE NUMEROS ASTRONOMICOS DE IGNACIO GARCIA Y PAULA CHITTARO\n\n"
           "Seleccione la operacion que quiera realizar:\n");

    while (finaliza == 1) {
        printf("1.Sumar valores\n2.Verificar igualdad de dos numeros\n3.Verificar menor valor\n"
               "4.Guardar resultados\n5.Cargar resultados\n6.Salir\n\n");
        printf("Opcion:");
        scanf("%d", &opcion);
        if(result != NULL)
            printf("resultadp %s\n", result->entero);
        else
            printf("adfasdfadsfas\n");
        finaliza = menu(opcion, result);
    }

    return 0;
}

int menu(int opcion, NumeroAstronomico *result) {

    switch (opcion) {
        case 1:
            system("cls");
            result = realizarSuma();
//            limpiarResultado(result);
            return 1;
        case 2:
            system("cls");
            verificarIgualdad();
            return 1;
        case 3:
            system("cls");
            obtenerMenor(result);
            return 1;
        case 4:
            system("cls");
            printf("result %s\n", result->entero);
            guardarResultado(result);
            return 1;
        case 5:
            system("cls");
            result = cargarResultado();
            limpiarResultado(result);
            return 1;
        case 6:
            exit(0);
        default:
            printf("Opcion Invalida, ingrese nuevamente\n");
            return 1;
    }
}