#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED

void leer_lista_uint32(FILE* archivo, uint32_t* enteros, uint8_t cantidad);

cabecera_t leer_cabecera(FILE* archivo);

ident_t leer_identificadores(FILE* archivo);

void leer_datos_paquete(uint8_t tamanio, FILE* archivo, uint32_t* datos);

crcs_t leer_crcs(FILE* archivo);

paquete_t leer_paquete_auxiliar(FILE* arch);

void paquete_a_puntero(paquetes lista, uint8_t* cant, FILE* arch, uint8_t dest);

void leer_desde_archivo(paquetes *lista, uint8_t *np, FILE* arch, uint8_t  dest);

#endif // LECTURA_H_INCLUDED
