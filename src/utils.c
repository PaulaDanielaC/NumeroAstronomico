#include "../header/utils.h"
#include "../header/aritm_op.h"
#include "../header/creacion_op.h"
#include "../header/errores.h"
#include "../header/persist.h"
#include "../header/salida_op.h"
#include <stdlib.h>

static NumeroAstronomico* crearNumero();
int opcion;

NumeroAstronomico* realizarSuma() {
    NumeroAstronomico* num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("Segundo valor:\n");
    num2 = crearNumero();
    return sumar(num1, num2);
}

void verificarIgualdad(NumeroAstronomico* num1) {
    NumeroAstronomico* num2;

    printf("Especificar otro valor:\n");
    num2 = crearNumero();
    sonIguales(num1, num2);
}

void obtenerMenor(NumeroAstronomico* num1) {
    NumeroAstronomico* num2;

    printf("Especificar otro valor:\n");
    num2 = crearNumero();
    esMenor(num1, num2);
}

void guardarResultado(NumeroAstronomico* num) {
    // TODO: Implementar
}

NumeroAstronomico* cargarResultado() {
    // TODO: Implementar
}

void limpiarResultado(NumeroAstronomico* num) {
    free(num->entero);
    free(num);
}

/* Funciones auxiliares */
static NumeroAstronomico* crearNumero() {
    NumeroAstronomico* num;

    printf("1.Ingresar valor\n2.Ingresar cifra significativa y cantidad de ceros\n"
           "3.Crear numero aleatorio\n");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
        num = crearDesdeCadena();
        break;
    case 2:
        num = crearDesdeCifraSeguidaDeCeros();
        break;
    case 3:
        num = crearAleatorio();
        break;        
    default:
        printf("Opcion invalida\n");
        break;
    }

    return num;
}