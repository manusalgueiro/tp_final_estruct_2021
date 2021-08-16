Funcion puntero <- redimensionar_memoria (puntero Por Valor, nueva_cantidad_bytes Por Valor)
	puntero <- trunc(Aleatorio(0, 1024))
	
	Si puntero <> 0 Entonces
		Escribir "Guardar puntero de ", nueva_cantidad_bytes Sin Saltar
		Escribir " bytes en dirección ", puntero
	SiNo
		Escribir "Memoria insuficiente."
	FinSi
Fin Funcion

Algoritmo Redimensionar_Memoria_Puntero
	Definir cant_bytes Como Entero
	Definir puntero Como Entero
	
	cant_bytes <- 10
	
	puntero <- redimensionar_memoria(puntero, cant_bytes)
	
FinAlgoritmo