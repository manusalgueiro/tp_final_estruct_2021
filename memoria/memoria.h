#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#include "../estructuras.h"

void* cheq_mem_ptr(void* puntero, char* mensaje);

void* res_memoria(size_t n_bytes);

void* redim_memoria(void* ptr_original, size_t cant_bytes);

void liberar_lista_paquetes(paquetes lista, uint8_t cant);

#endif // MEMORIA_H_INCLUDED
