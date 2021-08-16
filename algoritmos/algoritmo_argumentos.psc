Funcion mostrar_args ()
	Escribir "Archivo de entrada: entrada.bin"
	Escribir "Receptor: <numero id>"
	Escribir "Archivo de salida: salida.txt"
Fin Funcion

Funcion reportar_error_args ()
	Escribir "Por favor, ingrese los argumentos correctamente:"
	Escribir  "Formato: pkgr.exe <dest> <entrada> <salida>"
Fin Funcion

Algoritmo Verificar_Argumentos
	Definir cantidad_de_argumentos Como Entero
	Dimension lista_argumentos(cantidad_de_argumentos)
	Definir valor_retorno Como Logico
	
	Si cantidad_de_argumentos = 4 Entonces
		reportar_error_args()
		valor_retorno <- Falso
	SiNo
		mostrar_args()
		valor_retorno <- Verdadero
	Fin Si
FinAlgoritmo
