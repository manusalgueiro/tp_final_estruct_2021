#ifndef SALIDAS_H_INCLUDED
#define SALIDAS_H_INCLUDED

void guardar_punto(paquete_t p, int ult_indice, FILE* archivo);

void guardar_valores_en_txt(char* nom, paquetes lista, uint8_t np);

void mostrar_encabezado(paquete_t paq);

void mostrar_identificadores(paquete_t paq);

void mostrar_tipo(uint8_t tipo);

void mostrar_datos(paquete_t paq);

void mostrar_crcs(paquete_t paq);

void mostrar_paquetes_en_pantalla(paquetes lista, uint8_t cant);

#endif // SALIDAS_H_INCLUDED
