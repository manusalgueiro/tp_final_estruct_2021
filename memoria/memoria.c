#include <stdio.h>
#include <stdlib.h>

#include "../estructuras.h"

void*
cheq_mem_ptr(void* puntero, char* mensaje)
{
    // Verifica la existencia del puntero.
    // Caso contrario: Mensaje de error

    if (NULL == puntero)
    {
        printf("%s.\n", mensaje);
    }
    return puntero;
}

void*
res_memoria(size_t n_bytes)
{
    // Reserva n_bytes de memoria para un ponteru

    void*   ptr_mem = NULL;

    ptr_mem = malloc(n_bytes);

    return cheq_mem_ptr(ptr_mem, "Memoria Insuficiente");
}

void*
redim_memoria(void* ptr_original, size_t cant_bytes)
{
    // Modifica a cant_bytes la memoria de un puntero

    void*   ptr_nuevo = NULL;

    ptr_nuevo = realloc(ptr_original, cant_bytes);

    return cheq_mem_ptr(ptr_nuevo, "Memoria Insuficiente");
}

void
liberar_lista_paquetes(paquetes lista, uint8_t cant)
{
    // Libera la memoria de la lista de paquetes

    for (uint8_t i = 0; i < cant; i++)
    {
        free(lista[i].infopaq.datos);

        free(lista[i].infopaq.norm);
    }
    free(lista);
}
