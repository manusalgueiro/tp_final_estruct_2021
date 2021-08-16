Funcion valor_leido_32 <- leer_uint32_desde_archivo ( n_dato Por Valor, n_paq Por Valor )
	Escribir "(Leyendo dato ", n_dato, " del " Sin Saltar
	Escribir npaq " desde archivo)"
Fin Funcion

Funcion leer_lista_uint32 ( lista Por Referencia, n_paq Por Valor, n_datos Por Valor )
	Para cont <- 1 Hasta n_datos Con Paso 1 Hacer
		lista[n_paq, cont] <- leer_uint32_desde_archivo(cont, n_paq)
	Fin Para
Fin Funcion

Funcion valor_leido_8 <- leer_uint8_desde_archivo ( etiqueta Por Valor, n_paq Por Valor )
	Escribir "(Leyendo desde archivo ", etiqueta Sin Saltar
	Escribir " del paquete ", n_paq, ")"
Fin Funcion

Funcion abrir_archivo ()
	Escribir "Abrir archivo (algoritmo_abrir_archivo.psc)"
Fin Funcion

Algoritmo Leer_Paquetes_Desde_Archivos

	Definir cant_paquetes Como Entero
	cant_paquetes <- 10 // por ejemplo
	cant_datos <- 10 // por ejemplo

	// En C es una estructura, aquí son arreglos paralelos

	Dimension h1_s(cant_paquetes)			// uint8
	Dimension h2_s(cant_paquetes)			// uint8
	Dimension id_s(cant_paquetes)			// uint8
	Dimension origenes(cant_paquetes)		// uint8
	Dimension destinos(cant_paquetes)		// uint8
	Dimension tipos(cant_paquetes)			// uint8
	Dimension datos(cant_paquetes, cant_datos)	// uint32's
	Dimension crc1_s(cant_paquetes)			// uint8
	Dimension crc2_s(cant_paquetes)			// uint8
	
	abrir_archivo()
	
	Para cont <- 1 Hasta cant_paquetes Con Paso 1 Hacer

		h1_s[cont] <- leer_uint8_desde_archivo("h1", cont)
		h2_s[cont] <- leer_uint8_desde_archivo("h2", cont)

		id_s[cont] <- leer_uint8_desde_archivo("id", cont)
		origenes[cont] <- leer_uint8_desde_archivo("origen", cont)
		destinos[cont] <- leer_uint8_desde_archivo("destino", cont)

		tipos[cont] <- leer_uint8_desde_archivo("tipo", cont)

		leer_lista_uint32(datos, cont, cant_datos)

		crc1_s[cont] <- leer_uint8_desde_archivo("crc1", cont)
		crc2_s[cont] <- leer_uint8_desde_archivo("crc2", cont)
	Fin Para
	
FinAlgoritmo
