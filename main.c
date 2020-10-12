#include "header/utils.h"
#include <stdlib.h>
#include "salida_op.h"

int menu(int, NumeroAstronomico*);

int main() {
    NumeroAstronomico *result = NULL;
    int opcion;
    int finaliza = 0;

    printf("\n\t\t\tCALCULADORA DE NUMEROS ASTRONOMICOS DE IGNACIO GARCIA Y PAULA CHITTARO\n\n"
           "Seleccione la operacion que quiera realizar:\n");

    NumeroAstronomico numerito;
    numerito.entero = "11111111111111111111\n";
    numerito.longitudError = 21;
    mostrar(&numerito, 3, stdout);
    system("pause");
//    while (finaliza == 0) {
//        printf("1.Sumar valores\n2.Verificar igualdad de dos numeros\n3.Verificar menor valor\n"
//               "4.Guardar resultados\n5.Cargar resultados\n6.Salir\n\n");
//        printf("Opcion:");
//        scanf("%d", &opcion);
//        finaliza = menu(opcion, result);
//    }

    return 0;
}

//Borrar comment
int menu(int opcion, NumeroAstronomico* result) {
    switch (opcion) {
        case 1:
            system("cls");
            realizarSuma(result);
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
            cargarResultado();
            //limpiarResultado(result);
            return 0;
        case 6:
            exit(0);
        default:
            printf("Opcion Invalida, ingrese nuevamente\n");
            return 0;
    }
}