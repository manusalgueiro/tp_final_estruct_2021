#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

FILE* abrir_archivo(char *nombre, const char *modo);

size_t obtener_tam_arch(FILE* archivo);

uint8_t leer_uint8_desde_archivo(FILE* archivo);

uint32_t leer_uint32_desde_archivo(FILE* archivo);

#endif // ARCHIVOS_H_INCLUDED
