#ifndef VERIFICAR_H_INCLUDED
#define VERIFICAR_H_INCLUDED

uint16_t verificar_paquete(FILE* arch, uint8_t n_campo_data);

uint8_t confirmar_inicio_paquete(FILE* archivo);

#endif // VERIFICAR_H_INCLUDED
