#include <stdio.h>
#include <stdlib.h>

#include "../estructuras.h"
#include "archivos.h"

// SALIDA A ARCHIVO TXT

void
guardar_punto(paquete_t p, int ult_indice, FILE* archivo)
{
    // Guardar un punto geométrico en un archivo txt

    double  ordenada = 0;

    uint32_t indice = 0,
             cantidad = 0;

    cantidad = p.infopaq.tam/NATURAL_32;

    for (indice = 0; indice < cantidad; indice++)
    {
        ordenada = p.infopaq.norm[indice];
        fprintf(archivo, "%d ; %lf \n", indice + ult_indice, ordenada);
    }
}

void
guardar_valores_en_txt(char* nom, paquetes lista, uint8_t np)
{
    // Guardar puntos obtenidos en un archivo txt

    FILE*   archivo_texto = abrir_archivo(nom, "w");

    int inicio = 0;

    fprintf(archivo_texto, "x ; y \n");

    for (uint8_t i = 0; i < np; i++)
    {
        guardar_punto(lista[i], inicio, archivo_texto);

        inicio += lista[i].infopaq.tam/NATURAL_32;
    }
}

// SALIDA EN PANTALLA

void
mostrar_encabezado(paquete_t paq)
{
    printf("H1: %2d ", paq.enc.h1);

    printf("H2: %2d ", paq.enc.h2);
}

void
mostrar_identificadores(paquete_t paq)
{
    printf("ID: %2d ", paq.identif.id);

    printf("ORIG: %2d ", paq.identif.orig);

    printf("DEST: %2d ", paq.identif.dest);
}

void
mostrar_tipo(uint8_t tipo)
{
    printf("TYPE: %2d ", tipo);
}

void
mostrar_datos(paquete_t paq)
{
    uint8_t n = paq.infopaq.tam/NATURAL_32;

    printf("SIZE: %2d ", paq.infopaq.tam);

    printf("DATA:\t");

    for (uint8_t j = 0; j < n; j++)
    {
        printf("%4x ", paq.infopaq.datos[j]);
    }
}

void
mostrar_crcs(paquete_t paq)
{
    printf("CRC1: %3d ", paq.crcs.crc1);

    printf("CRC2: %3d ", paq.crcs.crc2);
}

void
mostrar_paquetes_en_pantalla(paquetes lista, uint8_t cant)
{
    for (uint8_t i = 0; i < cant; i++)
    {
        mostrar_encabezado(lista[i]);

        mostrar_identificadores(lista[i]);

        mostrar_tipo(lista[i].tipo);

        mostrar_datos(lista[i]);

        mostrar_crcs(lista[i]);

        printf("\n");

        //system("pause");
    }
}
