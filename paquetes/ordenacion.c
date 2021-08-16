#include <stdlib.h>
#include <stdint.h>
#include "../estructuras.h"

int
comparar_ids(const void* valor_1, const void* valor_2)
{
    // Compara dos paquetes por su ID como criterio de ordenación

    paquetes    paq_1   = (paquetes) valor_1;   // Paquete a comparar 1
    paquetes    paq_2   = (paquetes) valor_2;   // Paquete a comparar 2

    int         comp    = 0;                    // Resultado de la comparacion


    if( (paq_1->identif.id) < (paq_2->identif.id) )
    {
        comp = -1;
    }
    else if( (paq_1->identif.id) == (paq_2->identif.id) )
    {
        comp = 0;
    }
    else
    {
        comp = 1;
    }
    return comp;
}

void
ordenar_por_id(paquetes lista, uint8_t cantidad)
{
    // Ordena de menor a mayor 'cantidad' de paquetes

    qsort(lista, cantidad, sizeof(lista[0]), comparar_ids);
}
