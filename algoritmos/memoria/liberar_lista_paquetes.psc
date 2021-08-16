Funcion liberar_lista_paquetes ( paquetes Por Referencia, cantidad Por Valor)
	
	Para indice <- 1 Hasta cantidad Con Paso 1 Hacer
		liberar_datos_paquete(paquetes[indice])
		liberar_datos_normalizados(paquetes[indice])
	Fin Para
	
Fin Funcion

Algoritmo aaa
	
FinAlgoritmo
