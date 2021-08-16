#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../memoria/memoria.h"

FILE*
abrir_archivo(char *nombre, const char *modo)
{
    // Abre un archivo en un modo especificado

    FILE *archivo = fopen(nombre, modo);

    return cheq_mem_ptr(archivo, "No se pudo abrir archivo");
}

size_t
obtener_tam_arch(FILE* archivo)
{
    // Calcula el tamanio de un archivo

    size_t  tamanio = 0;

    fseek(archivo, 0L, SEEK_END);

    tamanio = ftell(archivo);

    fseek(archivo, 0L, SEEK_SET);

    return tamanio;
}

uint8_t
leer_uint8_desde_archivo(FILE* archivo)
{
    // Lee un entero sin signo de 8 bits desde archivo

    uint8_t valor_leido = 0;

    fread(&valor_leido, sizeof(uint8_t), 1, archivo);

    return valor_leido;
}

uint32_t
leer_uint32_desde_archivo(FILE* archivo)
{
    // Lee un entero sin signo de 32 bits desde archivo

    uint32_t valor_leido = 0;

    fread(&valor_leido, sizeof(uint32_t), 1, archivo);

    return valor_leido;
}
