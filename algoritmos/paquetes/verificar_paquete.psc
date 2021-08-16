Funcion verificado <- verificar_paquete ( archivo Por Referencia, dimension_data Por Valor )
	Definir dim Como Entero
	Definir i Como Entero
	
	// DIM = 7 bytes + N bytes + 2 bytes
	dim <- 7 + dimension_data + 2
	
	Dimension vector(dim)
	
	mover_puntero_lectura(archivo, -dim, posicion_actual)
	
	Para i <- 1 Hasta dim Con Paso 1 Hacer
		vector[i] <- leer_uint8_desde_archivo(archivo)
	Fin Para
	
	// Provista por cátedra
	verificado <- calcular_suma_verificacion(vector, dim)
Fin Funcion

Algoritmo nnn
	
FinAlgoritmo
