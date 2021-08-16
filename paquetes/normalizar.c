#include <stdint.h>
#include <float.h>

#include "../estructuras.h"
#include "../memoria/memoria.h"

double
encontrar_minimo_parcial(paquete_t paq, uint8_t n_datos)
{
    // Encuentra el mínimo parcial a partir del
    // mínimo de un paquete

    double  min_parcial = DBL_MAX;  // Minimo parcial

    double  valor       = 0;        // Valor temporal de comparacion


    for (uint8_t j = 0; j < n_datos; j++)
    {
        valor = paq.infopaq.datos[j] * 1.0;

        if (valor < min_parcial)
        {
            min_parcial = valor;
        }
    }

    return min_parcial;
}

double
encontrar_minimo(paquetes lista, uint8_t cant)
{
    // Encuentra el mínimo general
    // de todos los paquetes

    double  minimo         = DBL_MAX,   // Minimo general de la lista de paq
            minimo_parcial = DBL_MAX;   // Mínimo parcial de un paq

    uint8_t n_datos = 0;                // Cantidad de datos por paquete

    for (uint8_t i = 0; i < cant; i++)
    {
        n_datos = lista[i].infopaq.tam/NATURAL_32;  // 64bytes/4bytes = 16 paq

        minimo_parcial = encontrar_minimo_parcial(lista[i], n_datos);

        if (minimo_parcial < minimo)
        {
            minimo = minimo_parcial;
        }
    }
    return minimo;
}

double
encontrar_maximo_parcial(paquete_t paq, uint8_t n_datos)
{
    // Encuentra el maximo parcial a partir de un paquete

    double  max_parcial = 0,    // Maximo parcial de un paquete
            valor = 0;          // Valor temporal de comparacion


    for (uint8_t j = 0; j < n_datos; j++)
    {
        valor = paq.infopaq.datos[j] * 1.0;

        if (valor > max_parcial)
        {
            max_parcial = valor;
        }
    }

    return max_parcial;
}

double
encontrar_maximo(paquetes lista, uint8_t cant)
{
    // Encontrar el maximo general de todos los
    // datos presentes en los paquetes

    double  maximo          = 0,    // Maximo general de lista de paquetes
            maximo_parcial  = 0;    // Maximo parcial de un paquete

    uint8_t n_datos = 0;            // Cantidad de datos de un paquete


    for (uint8_t i = 0; i < cant; i++)
    {
        n_datos = lista[i].infopaq.tam/NATURAL_32;

        maximo_parcial = encontrar_maximo_parcial(lista[i], n_datos);

        if (maximo_parcial > maximo)
        {
            maximo = maximo_parcial;
        }
    }

    return maximo;
}

void
datos_normalizados_paquete(paquetes paq, double maximo, double minimo)
{
    // Obtiene los datos normalizados de un paquqete en particular

    uint8_t n       = (paq->infopaq.tam)/NATURAL_32;    // Cant. de paquetes

    double  temp    = 0;                                // Valor auxiliar double


    paq->infopaq.norm = (double*) res_memoria(n*DOBLE);

    for (uint8_t j = 0; j < n; j++)
    {
        temp = paq->infopaq.datos[j] * 1.0;

        paq->infopaq.norm[j] = (temp - minimo)/(maximo - minimo);
    }
}

void
obtener_datos_normalizados(paquetes *lista, uint8_t  cantidad)
{
    double  minimo = DBL_MAX,   // Minimo general
            maximo = 0;         // Maximo general


    minimo = encontrar_minimo(*lista, cantidad);

    maximo = encontrar_maximo(*lista, cantidad);

    for (uint8_t indice = 0; indice < cantidad; indice++)
    {
        datos_normalizados_paquete((*lista + indice), maximo, minimo);
    }
}
