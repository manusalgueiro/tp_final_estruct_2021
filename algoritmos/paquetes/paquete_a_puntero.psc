Funcion paquete_a_puntero ( paquetes Por Referencia,  cant Por Referencia, archivo Por Referencia, dest Por Valor)
	
	Definir comienza_paquete Como Logico
	Definir paquete_correcto Como Logico
	Definir paquete_roto Como Logico
	
	comienza_paquete <- confirmar_inicio_paquete(archivo)
	
	Si comienza_paquete Entonces
		paquete_auxiliar <- leer_paquete_auxiliar(archivo)
	FinSi
	
	paquete_roto <- verificar_paquete(archivo, cant)
	
	paquete_correcto <- (destino = destino_prompt) y (no paquete_roto)
	
	Si (paquete_correcto) Entonces
		lista[cant] <- paquete_auxiliar
		cant <- cant + 1
	FinSi
Fin Funcion

Algoritmo sin_titulo
	
FinAlgoritmo
