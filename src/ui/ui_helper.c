#include "ui_helper.h"
#include "aritm_op.h"
#include "creacion_op.h"
#include "errores.h"
#include "salida_op.h"
#include "persist.h"
#include <stdlib.h>
#include <ctype.h>
#include <mem.h>

NumeroAstronomico *crearNumero();
NumeroAstronomico* armarCifraSeguidaDeCeros();
int inputInvalido(unsigned int);
char* obtenerInput();

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

NumeroAstronomico *crearNumero() {
    NumeroAstronomico *num = (NumeroAstronomico*) malloc(sizeof(NumeroAstronomico));
    num->longitudError = Ninguno;
    unsigned int opcion;

    printf("1.Ingresar valor\n2.Ingresar cifra significativa y cantidad de ceros\n"
           "3.Crear numero aleatorio\n");
    printf("Opcion:\n");
    fflush(stdin);
    opcion = getc(stdin);

    switch (opcion) {
        case 49:
            num = crearDesdeCadena(obtenerInput());
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
    scanf("%d", &cifra);

    if (inputInvalido(cifra)) {
        perror("Error");
        return NULL;
    }

    printf("Ingrese la cantidad de ceros: \n");
    scanf("%d", &cantCeros);

    if (inputInvalido(cantCeros)) {
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

void ponerPuntos(NumeroAstronomico *num, char *numero) {
    int cantPuntos;
    if ((num->longitudError % 3) != 0)
        cantPuntos = num->longitudError / 3;
    else
        cantPuntos = (num->longitudError / 3) - 1;

    int cantCaracteres = (num->longitudError - 1) + cantPuntos;
    int cantLeidos = num->longitudError;
    int cantImpresos = 0;

    while (cantCaracteres >= 0) {

        if (cantImpresos != 0 && cantImpresos != num->longitudError && cantImpresos % 3 == 0) {
            numero[cantCaracteres] = '.';
            cantCaracteres--;
        }

        numero[cantCaracteres] = num->entero[cantLeidos - 1];
        cantLeidos--;
        cantCaracteres--;
        cantImpresos++;
    }

    numero[(num->longitudError) + cantPuntos] = '\0';
}

char* obtenerInput() {
    printf("Numero:\n");
    char* cadena = (char*) malloc(NUM_LIMIT);
    int cantCaracteres = 0;
    char input;

    fflush(stdin);
    while ((input = getchar()) != '\n' && input != EOF && cantCaracteres <= NUM_LIMIT) {
        if (isdigit(input)) {
            cadena[cantCaracteres] = input;
            cantCaracteres++;
        } else {
            free(cadena);
            return NULL;
        }
    }

    if (cantCaracteres >= NUM_LIMIT)
        printf("La cadena ingresada supero los 100 digitos, el excedente sera descartado\n");

    cadena[cantCaracteres] = '\0';
    return cadena;
}

void dividirNumero(char *numero, unsigned int cantGrupos) {
    int j = 0;
    int saltosLinea = 0;
    int longitud = (int) strlen(numero);
    unsigned int charPorLinea = (cantGrupos * 3) + cantGrupos;
    char *cadenaAux = (char *) malloc(sizeof(char) * longitud);
    int i = 0;

    if (charPorLinea > longitud) {
        return;
    }

    while (i <= charPorLinea && i < longitud) {
        cadenaAux[i] = numero[i];
        i++;

        if (i % charPorLinea == 0) {
            cadenaAux[i] = '\n';
            j = i + 1;
            saltosLinea++;
            i = 0;
            break;
        }
    }

    cantGrupos = cantGrupos - 1;
    charPorLinea = (cantGrupos * 3) + cantGrupos;

    while (j < longitud + saltosLinea) {
        if (i % charPorLinea == 0 && i != 0) {
            cadenaAux[j] = '\n';
            i = 0;
            j++;
            saltosLinea++;
        }

        cadenaAux[j] = numero[j - saltosLinea];
        i++;
        j++;
    }

    cadenaAux[j] = '\0';
    memcpy(numero, cadenaAux, strlen(cadenaAux) + 1);
}