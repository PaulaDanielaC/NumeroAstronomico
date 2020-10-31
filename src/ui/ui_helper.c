#include "ui_helper.h"
#include "aritm_op.h"
#include "creacion_op.h"
#include "errores.h"
#include "salida_op.h"
#include "persist.h"
#include <stdlib.h>
#include <ctype.h>
#include <mem.h>

#define TOTAL_LIMIT 100

NumeroAstronomico *crearNumero();
void obtenerDigitosInput(NumeroAstronomico*);
NumeroAstronomico* armarCifraSeguidaDeCeros();
int inputInvalido(unsigned int);

void realizarSuma(NumeroAstronomico *result) {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor\n");
    num1 = crearNumero();
    if (tieneError(num1)) {
        result->longitudError = num1->longitudError;
        limpiarResultado(num1);
        return;
    }

    printf("\nSegundo valor\n");
    num2 = crearNumero();
    if (tieneError(num2)) {
        result->longitudError = num2->longitudError;
        limpiarResultado(num2);
        return;
    }

    memcpy(result, sumar(num1, num2), sizeof(NumeroAstronomico));
    if (tieneError(result))
        return;

    system("cls");
    printf("El resultado de la suma es:\n");
    mostrar(result, 3, stdout);
    limpiarResultado(num1);
    limpiarResultado(num2);
}

void verificarIgualdad() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("\nSegundo valor:\n");
    num2 = crearNumero();

    if(sonIguales(num1, num2))
        printf("Los numeros ingresados son iguales\n");
    else
        printf("Los numeros ingresados no son iguales\n");

    system("pause");
}

void obtenerMenor() {
    NumeroAstronomico *num1, *num2;

    printf("Primer valor:\n");
    num1 = crearNumero();
    printf("\nSegundo valor:\n");
    num2 = crearNumero();

    if(esMenor(num1, num2))
        printf("El primer numero es menor que el segundo\n");
    else
        printf("El segundo numero es menor que el primero\n");

    system("pause");
}

void guardarResultado(NumeroAstronomico *num) {
    FILE* archivo;

    printf("Elija un formato de archivo\n");
    printf("1- Texto\n");
    printf("2- Binario\n");
    fflush(stdin);
    int opcion = getc(stdin);

    switch (opcion) {
        case 49:
            archivo = fopen(ARCHIVO_TEXTO, "w");
            print(num, archivo);
            fclose(archivo);
            break;
        case 50:
            archivo = fopen(ARCHIVO_BINARIO, "wb");
            write(num, archivo);
            fclose(archivo);
            break;
        default:
            printf("Opcion invalida\n");
            break;
    }
}

void cargarResultado() {
    NumeroAstronomico *num = (NumeroAstronomico*) malloc(sizeof(NumeroAstronomico));
    FILE* stream = NULL;

    printf("Elija un formato de archivo\n");
    printf("1- Texto\n");
    printf("2- Binario\n");
    fflush(stdin);
    int opcion = getc(stdin);

    switch (opcion) {
        case 49:
            memcpy(num, scan(stream), sizeof(NumeroAstronomico));
            break;
        case 50:
            num = read(stream);
            break;
        default:
            printf("Opcion invalida\n");
            break;
    }
}

void limpiarResultado(NumeroAstronomico *num) {
    free(num->entero);
    free(num);
}

/* Funciones auxiliares */

void obtenerDigitosInput(NumeroAstronomico* num) {

    printf("Numero:\n");
    int cantCaracteres = 0;
    char input;

    fflush(stdin);
    while ((input = getchar()) != '\n' && input != EOF && cantCaracteres <= TOTAL_LIMIT) {
        if (isdigit(input)) {
            num->entero[cantCaracteres] = input;
            cantCaracteres++;
        } else {
            num->longitudError = CadenaInvalida;
            return;
        }
    }

    num->entero[cantCaracteres] = '\0';
    num->longitudError = (int) strlen(num->entero);
}

NumeroAstronomico *crearNumero() {
    NumeroAstronomico *num = (NumeroAstronomico*) malloc(sizeof(NumeroAstronomico));
    num->entero = (char*) malloc(TOTAL_LIMIT);
    num->longitudError = Ninguno;
    unsigned int opcion;

    printf("1.Ingresar valor\n2.Ingresar cifra significativa y cantidad de ceros\n"
           "3.Crear numero aleatorio\n");
    printf("Opcion:\n");
    fflush(stdin);
    opcion = getc(stdin);

    switch (opcion) {
        case 49:
            obtenerDigitosInput(num);
            break;
        case 50:
            num = armarCifraSeguidaDeCeros();
            break;
        case 51:
            num = crearAleatorio();
            break;
        default:
            system("cls");
            printf("Opcion invalida\n");
            break;
    }

    return num;
}

NumeroAstronomico* armarCifraSeguidaDeCeros() {
    unsigned int cifra, cantCeros;
    fflush(stdin);

    printf("Ingrese la cifra: \n");
    cifra = scanf("%d", &cifra);

    if (inputInvalido(cifra)) {
        perror("Error");
        return NULL;
    }

    printf("Ingrese la cantidad de ceros: \n");
    cifra = scanf("%d", &cantCeros);

    if (inputInvalido(cifra)) {
        perror("Error");
        return NULL;
    }

    return crearDesdeCifraSeguidaDeCeros(cifra, cantCeros);
}

int inputInvalido(unsigned int input) {
    if (input == EINVAL || input == EOF) {
        return 1;
    }
    return 0;
}