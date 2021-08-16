#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prompt/prompt.h"
#include "estructuras.h"
#include "archivos/archivos.h"
#include "archivos/salidas.h"
#include "memoria/memoria.h"
#include "paquetes/ordenacion.h"
#include "paquetes/lectura.h"
#include "paquetes/normalizar.h"


int main(int num_args, char* args[])
{
    int         continuar   = 0;    // 1: argumentos ok, continuar
    uint8_t     cantidad    = 0;    // Cantidad de paquetes

    FILE*       arch_entr   = NULL; // Puntero a archivo binario

    paquetes    lista       = NULL; // Lista de paquetes como puntero


    // Verificar la validez de los argumentos desde prompt
    continuar = verif_argum(num_args);

    if (continuar)
    {
        // Mostrar los argumentos ingresados por prompt
        mostrar_args(args);

        // Abrir archivo binario "entrada.bin"
        arch_entr = abrir_archivo(args[2], "rb");

        // Leer desde archivo contenido de lista de paquetes
        leer_desde_archivo(&lista, &cantidad, arch_entr, atoi(args[1]));

        // Ordenar lista de paquetes segun ID
        ordenar_por_id(lista, cantidad);

        // Generar datos normalizados para cada paquete
        obtener_datos_normalizados(&lista, cantidad);

        // Mostrar resultados en pantalla
        mostrar_paquetes_en_pantalla(lista, cantidad);

        // Guardar pares de puntos (x = dato, y = dato normalizado)
        guardar_valores_en_txt(args[3], lista, cantidad);

        // Liberar memoria dedicada a la lista de paquetes
        liberar_lista_paquetes(lista, cantidad);
    }
    else
    {
        // Reportar error de falla en la carga desde prompt
        reportar_error();
    }
    return 0;
}
