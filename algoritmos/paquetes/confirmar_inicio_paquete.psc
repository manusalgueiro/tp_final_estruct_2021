Funcion es_cabecera <- confirmar_inicio_paquete ( archivo )
	Definir h1 Como Entero
	Definir h2 Como Entero
	
	h1, h2 = leer_cabecera(archivo)
	
	es_cabecera = (h1 = 60) y (h2 = 77)
	
	// Regresar puntero a posición original
	mover_puntero_lectura(archivo, -2, pos_actual)
	
Fin Funcion

Algoritmo hhh
	
FinAlgoritmo
