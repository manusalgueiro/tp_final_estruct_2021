#include <stdio.h>

#include "../estructuras.h"
#include "../archivos/archivos.h"
#include "../memoria/memoria.h"
#include "verificar.h"

void
leer_lista_uint32(FILE* archivo, uint32_t* enteros, uint8_t cantidad)
{
    // Lee desde archivo una lista de
    // enteros sin signo de 32 bits

    for (uint32_t cont = 0; cont < cantidad; cont++)
    {
        *(enteros + cont) = leer_uint32_desde_archivo(archivo);
    }
}

cabecera_t
leer_cabecera(FILE* archivo)
{
    // Lee los datos correspondientes
    // a la cabecera de un paquete

    cabecera_t aux;

    aux.h1 = leer_uint8_desde_archivo(archivo);

    aux.h2 = leer_uint8_desde_archivo(archivo);

    return aux;
}

ident_t
leer_identificadores(FILE* archivo)
{
    // Lee los datos correspondientes
    // a los identificadores de un paquete

    ident_t aux;

    aux.id = leer_uint8_desde_archivo(archivo);

    aux.orig = leer_uint8_desde_archivo(archivo);

    aux.dest = leer_uint8_desde_archivo(archivo);

    return aux;
}

void
leer_datos_paquete(uint8_t tamanio, FILE* archivo, uint32_t* datos)
{
    // Lee los datos correspondientes
    // al campo DATA de un paquete

    uint32_t cant = (tamanio/NATURAL_32);

    leer_lista_uint32(archivo, datos, cant);
}

crcs_t
leer_crcs(FILE* archivo)
{
    // Lee los datos correspondientes
    // a los CRC1 y CRC2 de un paquete

    crcs_t  aux;

    aux.crc1 = leer_uint8_desde_archivo(archivo);

    aux.crc2 = leer_uint8_desde_archivo(archivo);

    return aux;
}

paquete_t
leer_paquete_auxiliar(FILE* arch)
{
    // Lee un paquete de forma auxiliar a
    // partir de un archivo

    paquete_t aux;

    // H1 H2
    aux.enc = leer_cabecera(arch);

    // ID ORIG DEST
    aux.identif = leer_identificadores(arch);

    // TYPE
    aux.tipo = leer_uint8_desde_archivo(arch);

    // SIZE
    aux.infopaq.tam = leer_uint8_desde_archivo(arch);

    aux.infopaq.datos = (uint32_t*) res_memoria(aux.infopaq.tam);

    // DATA
    leer_datos_paquete(aux.infopaq.tam, arch, aux.infopaq.datos);

    // CRC1 CRC2
    aux.crcs = leer_crcs(arch);

    return aux;
}

void
paquete_a_puntero(paquetes lista, uint8_t* cant, FILE* arch, uint8_t dest)
{
    // Carga cada uno de los paquetes leidos
    // desde archivo a un puntero a paquete_t

    paquete_t   aux;                        // Paquete auxiliar

    uint8_t     comienza_paquete    = 0,    // 1 si 3d4d
                paquete_correcto    = 0;    // 1: correcto para guardar

    uint16_t    paquete_roto        = 1;    // 0: verificado


    comienza_paquete = confirmar_inicio_paquete(arch);

    if (comienza_paquete)
    {
        aux = leer_paquete_auxiliar(arch);
    }

    paquete_roto = verificar_paquete(arch, aux.infopaq.tam);

    paquete_correcto = (aux.identif.dest == dest) && (!paquete_roto);

    if (paquete_correcto)
    {
        lista[*cant] = aux;
        *cant += 1;
    }
}

void
leer_desde_archivo(paquetes *lista, uint8_t *np, FILE* arch, uint8_t  dest)
{
    // Lee todos los paquetes con DEST ingresado
    // desde prompt y que verifiquen checksum

    const uint8_t   TAM_PAQUETE = sizeof(paquete_t);

    const size_t    TAM_ARCHIVO = obtener_tam_arch(arch);


    *lista = (paquetes) res_memoria(TAM_PAQUETE);

    while (TAM_ARCHIVO != ftell(arch))
    {
        *lista = (paquetes) redim_memoria(*lista, (*np + 1) * TAM_PAQUETE);

        paquete_a_puntero(*lista, np, arch, dest);
    }
    fclose(arch);
}
