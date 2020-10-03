#include "../header/utils.h"
#include "../header/aritm_op.h"
#include "../header/creacion_op.h"
#include "../header/errores.h"
#include "../header/salida_op.h"
#include <stdlib.h>
#include <ctype.h>

#define TOTAL_LIMIT 100

NumeroAstronomico *crearNumero();
void obtenerDigitosInput(char*);

int opcion;

NumeroAstronomico *realizarSuma() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor\n");
    num1 = crearNumero();
    printf("\nSegundo valor\n");
    num2 = crearNumero();

    printf("\nAhora suma:\n");
    NumeroAstronomico *result = sumar(num1, num2);
    mostrar(result, 3);
    system("pause");
    return result;
}

void verificarIgualdad() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("\nSegundo valor:\n");
    num2 = crearNumero();

    sonIguales(num1,num2);
    system("pause");
}

void obtenerMenor() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("\nSegundo valor:\n");
    num2 = crearNumero();

    esMenor(num1,num2);
    system("pause");
}

void guardarResultado(NumeroAstronomico *num) {
    // TODO: Implementar
}

NumeroAstronomico *cargarResultado() {
    // TODO: Implementar
    NumeroAstronomico *num;
    return num;
}

void limpiarResultado(NumeroAstronomico *num) {
    free(num->entero);
    free(num);
}

/* Funciones auxiliares */

void obtenerDigitosInput(char* cadena) {

    printf("Numero:\n");
    int cantCaracteres = 0;
    char input;

    fflush(stdin);
    while ((input = getchar()) != '\n' && input != EOF && cantCaracteres <= TOTAL_LIMIT) {
        if (isdigit(input)) {
            cadena[cantCaracteres] = input;
            cantCaracteres++;
        } else {
            itoa(CadenaInvalida, cadena, 10);
        }
    }

    cadena[cantCaracteres+1] = '\0';
}

NumeroAstronomico *crearNumero() {
    NumeroAstronomico *num;
    char* string = malloc(TOTAL_LIMIT);
    int cifra, cantCeros;

    printf("1.Ingresar valor\n2.Ingresar cifra significativa y cantidad de ceros\n"
           "3.Crear numero aleatorio\n");
    printf("Opcion:");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            obtenerDigitosInput(string);
            num = crearDesdeCadena(string);
            break;
        case 2:
            printf("Ingrese la cifra: ");
            scanf("%d", &cifra);
            printf("Ingrese la cantidad de ceros: ");
            scanf("%d", &cantCeros);
            num = crearDesdeCifraSeguidaDeCeros(cifra, cantCeros);
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