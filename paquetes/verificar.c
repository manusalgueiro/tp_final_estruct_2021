#include <stdio.h>
#include <stdint.h>

#include "../crc_16.h"
#include "../estructuras.h"
#include "lectura.h"
#include "../archivos/archivos.h"

uint16_t
verificar_paquete(FILE* arch, uint8_t n_campo_data)
{
    // Realiza la suma de verificacion a partir de un
    // vector uint8_t con todos los datos del paquete

    // DIM = 7 bytes + N bytes + 2 bytes
    const uint16_t  DIM = (7 + n_campo_data + 2);

    uint8_t         vector[DIM];


    // Retroceder el puntero el equivalente en bytes a un paquete completo
    fseek(arch, -DIM, SEEK_CUR);

    // Leer DIM elementos de sizeof(uint8_t) bytes
    for (uint8_t i = 0; i < DIM; i++)
    {
        vector[i] = leer_uint8_desde_archivo(arch);
    }

    return calculate_checksum(vector, DIM); // 0: verificado
}

uint8_t
confirmar_inicio_paquete(FILE* archivo)
{
    cabecera_t  aux;                // Variable auxiliar de cabecera de paquete

    uint8_t     es_cabecera = 0;    // 1 si corresponden a valores de cabecera


    aux = leer_cabecera(archivo);

    // Es inicio de paquete si H1 = 3C y H2 = 4D

    es_cabecera = (aux.h1 == 60) && (aux.h2 == 77);

    // Retroceder dos bytes para luego leer paquete

    fseek(archivo, -2L, SEEK_CUR);

    return es_cabecera;
}
