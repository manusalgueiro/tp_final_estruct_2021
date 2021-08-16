Funcion puntero <- reservar_puntero ()
	puntero <- trunc(Aleatorio(0, 1024))
Fin Funcion

Funcion abrir_archivo (nombre_arch Por Valor, modo_apert Por Valor)
	Si reservar_puntero() <> 0 Entonces
		Escribir "Abrir archivo ", nombre_arch Sin Saltar
		Escribir " en modo ", modo_apert
	FinSi
Fin Funcion

Algoritmo Abrir_Un_Archivo
	Definir nombre_archivo Como Caracter
	Definir modo_apertura Como Caracter
	
	nombre_archivo <- "entrada.bin"
	modo_apertura <- "read"
	abrir_archivo(nombre_archivo, modo_apertura)
FinAlgoritmo
