#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include <stdint.h>

#define NATURAL_32 4
#define DOBLE 8

// ESTRUCTURA CABECERA DE PAQUETE

typedef struct
{
    uint8_t h1; // H1 = 0x3C
    uint8_t h2; // ​H2 = 0x4D​

} cabecera_t;

// ESTRUCTURA IDENTIFICADORES DE PAQUETE

typedef struct
{
    uint8_t id;     // identificador de paquete
    uint8_t orig;   // ​0x01
    uint8_t dest;   // 0x05 o 0x10

} ident_t;

// ESTRUCTURA DE DATOS DE PAQUETE

typedef struct
{
    uint8_t     tam;    // tamanio de datos
    uint32_t*   datos;  // array de 'tam' datos de 32 bits
    double*     norm;   // datos normalizados

} datos_t;

// ESTRUCTURA DE CRC'S DE PAQUETE

typedef struct
{
    uint8_t crc1;   // CRC1
    uint8_t crc2;   // CRC2

} crcs_t;

// ESTRUCTURA DE UN PAQUETE

typedef struct
{
    cabecera_t  enc;        // Encabezados H1 y H2
    ident_t     identif;    // Identificadores ID, ORIG y DEST
    uint8_t     tipo;       // Tipo: 0x30 o 0x40
    datos_t     infopaq;    // Datos de un paquete
    crcs_t      crcs;       // CRC1 y CRC2

} paquete_t;

// PUNTERO A PAQUETES
typedef paquete_t* paquetes;    // Puntero a paquete_t (lista de paquetes)

#endif // ESTRUCTURAS_H_INCLUDED
