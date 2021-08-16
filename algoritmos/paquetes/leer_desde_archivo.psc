Funcion leer_desde_archivo ( lista Por Referencia, np Por Referencia, arch Por Referencia, dest Por Referencia)
	Definir tam_paquete Como Entero
	Definir tam_archivo Como Entero
	Definir indice Como Entero
	
	indice <- 1
	
	tam_archivo <- obtener_tam_arch(arch)
	
	lista <- reservar_memoria(tam_paquete)
	
	Mientras ( posicion_puntero() <> tam_archivo ) Hacer
		lista[indice] <- redim_memoria( tam_paquete * (indice + 1) )
		
		paquete_a_puntero(lista, np, arch, dest)
	FinMientras
	
Fin Funcion

Algoritmo bbb
	
FinAlgoritmo
