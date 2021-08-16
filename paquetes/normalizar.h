#ifndef NORMALIZAR_H_INCLUDED
#define NORMALIZAR_H_INCLUDED

double encontrar_minimo_parcial(paquete_t paq, uint8_t n_datos);

double encontrar_minimo(paquetes lista, uint8_t cant);

double encontrar_maximo_parcial(paquete_t paq, uint8_t n_datos);

double encontrar_maximo(paquetes lista, uint8_t cant);

void datos_normalizados_paquete(paquetes paq, double maximo, double minimo);

void obtener_datos_normalizados(paquetes *lista, uint8_t  cantidad);

#endif // NORMALIZAR_H_INCLUDED
