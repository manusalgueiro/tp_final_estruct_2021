Funcion puntero <- reservar_memoria (cantidad_bytes Por Valor)
	puntero <- trunc(Aleatorio(0, 1024))
	
	Si puntero <> 0 Entonces
		Escribir "Guardar puntero de ", cantidad_bytes Sin Saltar
		Escribir " bytes en dirección ", puntero
	SiNo
		Escribir "Memoria insuficiente."
	FinSi
Fin Funcion

Algoritmo Reservar_Memoria_Puntero
	Definir cant_bytes Como Entero
	Definir puntero Como Entero
	
	cant_bytes <- 10
	
	puntero <- reservar_memoria(cant_bytes)
	
FinAlgoritmo
