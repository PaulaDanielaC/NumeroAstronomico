#include "../header/utils.h"
#include "../header/aritm_op.h"
#include "../header/creacion_op.h"
#include "../header/errores.h"
#include "../header/persist.h"
#include "../header/salida_op.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHAR_LIMIT 100

typedef struct {
    char string[ CHAR_LIMIT];
    unsigned int longitud;
} Texto;

NumeroAstronomico *crearNumero();

Texto *obtenerDigitosInput();

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

Texto *obtenerDigitosInput() {
    printf("Numero: ");
    fflush(stdin);
    Texto *texto = malloc(sizeof(Texto));
    unsigned int cantCaracteres = 0;
    char input;

    while ((input = getchar()) != '\n' && input != EOF && cantCaracteres <= CHAR_LIMIT) {
        if (isdigit(input)) {
            texto->string[cantCaracteres] = input;
            cantCaracteres++; // TODO Esto hace cualquier cosa
        }
    }

    texto->longitud = cantCaracteres;
    return texto;
}

NumeroAstronomico *crearNumero() {
    NumeroAstronomico *num;
    Texto *string;

    printf("1.Ingresar valor\n2.Ingresar cifra significativa y cantidad de ceros\n"
           "3.Crear numero aleatorio\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            string = obtenerDigitosInput();
            num = crearDesdeCadena(string->string, string->longitud);
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