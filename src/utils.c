#include "../header/utils.h"
#include "../header/aritm_op.h"
#include "../header/creacion_op.h"
#include "../header/errores.h"
#include "../header/salida_op.h"
#include <stdlib.h>
#include <ctype.h>

#define CHAR_LIMIT 103

NumeroAstronomico *crearNumero();
void obtenerDigitosInput(char*);

int opcion;

NumeroAstronomico *realizarSuma() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("Segundo valor:\n");
    num2 = crearNumero();

    printf("Ahora suma:\n");
    NumeroAstronomico *result = sumar(num1, num2);
    mostrar(result, 3);
    system("pause");
    return result;
}

void verificarIgualdad() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("Segundo valor:\n");
    num2 = crearNumero();

    int verificaIgualdad = sonIguales(num1, num2);
    printf("%i\n", verificaIgualdad); //TODO: Armar mensaje
}

void obtenerMenor() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("Especificar otro numero:\n");
    num2 = crearNumero();
    int menor = esMenor(num1, num2);

    printf("Es menor %i\n", menor);
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
    while ((input = getchar()) != '\n' && input != EOF && cantCaracteres <= CHAR_LIMIT - 3) {
        if (isdigit(input)) {
            cadena[cantCaracteres] = input;
            cantCaracteres++;
        } else {
            itoa(CadenaInvalida, cadena, 10);
        }
    }

    cadena[cantCaracteres] = '\n';
}

NumeroAstronomico *crearNumero() {
    NumeroAstronomico *num;
    char* string = malloc(CHAR_LIMIT);
    int cifra, cantCeros;

    printf("1.Ingresar valor\n2.Ingresar cifra significativa y cantidad de ceros\n"
           "3.Crear numero aleatorio\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            obtenerDigitosInput(string);
            num = crearDesdeCadena(string);
            break;
        case 2:
            printf("Ingrese la cifra\n");
            scanf("%d", &cifra);
            printf("Ingrese la cantidad de ceros\n");
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