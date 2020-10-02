#include "../header/aritm_op.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../header/errores.h"

#define CHAR_LIMIT 103
#define OVERFLOW 0
#define CARRY 1

int obtenerNumMasDigitos(int, int);

NumeroAstronomico *sumar(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    NumeroAstronomico *resultado = malloc(sizeof(NumeroAstronomico));
    int numMasLargo = obtenerNumMasDigitos(num1->longitudError, num2->longitudError);
    resultado->entero = malloc(numMasLargo);
    int index = numMasLargo-1;
    int long1 = num1->longitudError-1;
    int long2 = num2->longitudError-1;
    int carry = 0;
    int digitoResultado;
    int overflow = 0;

    while(long1 != -1 && long2 != -1) {
        int d1 = ((int)num1->entero[long1]) - ((int)'0');
        int d2 = ((int)num2->entero[long2]) - ((int)'0');
        digitoResultado = d1 + d2 + carry;

        if (digitoResultado > 9) {
            digitoResultado = digitoResultado - 10;
            carry = 1;
        } else {
            carry = 0;
        }

        resultado->entero[index] = (char)(digitoResultado + '0');
        long1--;
        long2--;
        index--;
    }

//   TODO: Terminar de completar el numero si hay diferencia de digitos
//   TODO: Manejo del caso overflow  ----> No me acuerdo si iría 103 (ya con el carry y el overflow incluidos) o 101


    resultado->entero[numMasLargo] = '\0';
    printf("resultado: %s\n", resultado->entero);
    return resultado;
}

int obtenerNumMasDigitos(int longNum1, int longNum2) {
    if (longNum1 > longNum2) {
        return longNum1;
    }

    return longNum2;
}

int sonIguales(NumeroAstronomico *num1, NumeroAstronomico *num2) {

    if (getTipoDeError(num1) == Ninguno || getTipoDeError(num2) == Ninguno) { // TODO: Mepa que aca iria un and porque si uno da True, ya tendría error
        if(strcmp(num1->entero, num2->entero) == 0) {
            printf("\nSon iguales\n");
            system("pause"); // Para que no se cierre
            return 1;
        }
        else{
            printf("\nSon distintos\n");
            system("pause");
            return 0;
        }
    }
}

int esMenor(NumeroAstronomico *num1, NumeroAstronomico *num2) {
    if (getTipoDeError(num1) == Ninguno || getTipoDeError(num2) == Ninguno) { // TODO: Idem de sonIguales
        if (strcmp(num1->entero, num2->entero) < 0) {
            printf("Es menor %s\n\n\n", num1->entero); // TODO: Implementar primero el numero y despues el texto.
            system("pause");
            return 1;
        }
        else{
            printf("Es menor %s\n", num2->entero);
            system("pause");
            return 0;
        }
    }
}