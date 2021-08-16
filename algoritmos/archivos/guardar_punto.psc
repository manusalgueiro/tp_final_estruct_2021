Funcion guardar_punto ( cant_datos Por Valor, datos_norm_paq Por Referencia, ult_indice Por Valor, archivo Por Referencia)
	Definir ordenada Como Real
	Definir indice Como Entero
	Definir cantidad Como Entero
	
	cantidad <- cant_datos
	
	Para indice <- 1 Hasta cantidad Con Paso 1 Hacer
		ordenada <- datos_norm_paq[indice]
		Escribir "Guardar en archivo (", indice + ult_indice Sin Saltar
		Escribir " ; ",ordenada,")"
	Fin Para
	
Fin Funcion

Funcion abrir_archivo (nombre_arch Por Valor, modo_apert Por Valor)
	
Fin Funcion

Funcion  guardar_valores_en_txt ( nombre Por Referencia, lista Por Referencia, cant_paquetes Por Valor)
	Definir inicio Como Entero
	Definir i Como Entero
	Definir archivo Como Entero
	
	archivo <- abrir_archivo(nombre, "w")
	inicio <- 0
	
	Para i<-1 Hasta cant_paquetes Con Paso paso Hacer
		guardar_punto(lista[i], inicio, archivo)
	Fin Para
	
Fin Funcion

Algoritmo guardar_paquetes
	
FinAlgoritmo
