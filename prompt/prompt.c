#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// NUMERO DE ARGUMENTOS DEL PROMPT
#define N_ARG 4

void
reportar_error(void)
{
    // Aviso de error generico frente a errores
    // de ingreso en el prompt

    printf("Por favor, ingrese los argumentos correctamente:\n");

    printf("Formato: programa.exe <id> <entrada> <salida>\n");
}

void
mostrar_args(char** datos)
{
    // Muestra los argumentos (validos) ingresados desde el prompt

    char etiquetas[N_ARG][9] = {"Programa:","Receptor:","Entrada:","Salida:"};


    for (uint8_t cont = 0; cont < N_ARG; cont++)
    {
        printf("%s\t%s\n", etiquetas[cont], datos[cont]);
    }
}

int
verif_argum(int n_argum)
{
    // Verifica la cantidad de argumentos del prompt

    int verif = 0;  // 1: Cantidad de argumentos coincide


    (N_ARG != n_argum) ? (verif = 0) : (verif = 1);

    return verif;
}
