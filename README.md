# Trabajo Práctico Final de Programación Estructurada (2021): Documentación de las Funciones utilizadas en la resolución del problema
***
Nota: Al final de esta documentación se encuentran las estructuras de datos que modelan los paquetes y los resultados obtenidos de la ejecución del programa.
***

El Programa realiza varias tareas para satisfacer las necesidades del problema, y dichas tareas fueron separadas en las siguientes secciones: **prompt**, **archivos**, **memoria** y **paquetes**.

## Administración de entradas del prompt

### Verificar el número de argumentos del prompt
```c
    int verif_argum(int n_argum);
```
Esta función se encarga de constatar que el número de argumentos ingresados desde la terminal coincidan con el deseado.

Cuatro argumentos:

- Nombre de programa.
- Identificador de destino.
- Archivo binario de entrada.
- Archivo de texto de salida.

##### Pseudocódigo

```
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
```

### Mostrar los argumentos ingresados desde prompt
```c
    void mostrar_args(char** datos);
```
Si los argumentos del prompt fueron validados, esta función informa por pantalla la información recientemente ingresada por el usuario (Programa, Receptor, Entrada y Salida).
##### Pseudocódigo
```
Funcion mostrar_args ()
	Escribir "Archivo de entrada: entrada.bin"
	Escribir "Receptor: <numero id>"
	Escribir "Archivo de salida: salida.txt"
Fin Funcion
```
### Reportar error de carga de argumentos
```c
    void reportar_error(void);
```
Si los argumentos no fueron validados, esta función informará de manera genérica al usuario que ha cometido un error en la carga.
##### Pseudocódigo
```
Funcion reportar_error_args ()
	Escribir "Por favor, ingrese los argumentos correctamente:"
	Escribir  "Formato: pkgr.exe <dest> <entrada> <salida>"
Fin Funcion
```
***
## Administración de archivos y salida por pantalla
### Archivos
#### Abrir un archivo
```c
    FILE* abrir_archivo(char *nombre, const char *modo);
```
Esta función se encarga de generar un puntero a ```FILE*``` para abrir un archivo según un modo especificado. En este programa se hace uso de los modos **lectura binaria** y **escritura secuencial**.
##### Pseudocódigo
```
Funcion puntero <- reservar_puntero ()
	puntero <- trunc(Aleatorio(0, 1024))
Fin Funcion

Funcion abrir_archivo (nombre_arch, modo_apert )
	Si reservar_puntero() <> 0 Entonces
		Escribir "Abrir archivo ", nombre_arch Sin Saltar
		Escribir " en modo ", modo_apert
	FinSi
Fin Funcion
```
#### Obtener el tamaño de un archivo cualquiera
```c
    size_t obtener_tam_arch(FILE* archivo);
```
Esta función permite obtener el tamaño de un archivo cualquiera en formato ```size_t```; dicho valor se utiliza como control para recorrer el archivo binario durante la carga de paquetes.
#### Leer un entero sin signo de 8 bits desde archivo
```c
    uint8_t leer_uint8_desde_archivo(FILE* archivo);
```
Durante la carga de paquetes, muchos de los campos y/o datos son enteros sin signo de 8 bits. Esta función viene a satisfacer esta necesidad, evitando tener muchas sentencias ```fread()``` dentro del bloque.
##### Pseudocódigo
```
Funcion valor_leido_8 <- leer_uint8_desde_archivo ( etiqueta, n_paq )
	Escribir "(Leyendo desde archivo ", etiqueta, " del paquete ", n_paq, ")"
Fin Funcion
```
#### Leer un entero sin signo de 32 bits desde archivo
```c
    uint32_t leer_uint32_desde_archivo(FILE* archivo);
```
Esta función es análoga a la anterior, para enteros sin signo de 32 bits.
##### Pseudocódigo
```
Funcion valor_leido_32 <- leer_uint32_desde_archivo ( n_dato, n_paq )
	Escribir "(Leyendo dato ", n_dato, " del " Sin Saltar
	Escribir npaq " desde archivo)"
Fin Funcion
```
### Salida por pantalla y a archivos txt
#### Guardar un punto (x,y) en archivo
```c
    void guardar_punto(paquete_t p, int ult_indice, FILE* archivo);
```
Esta función se encarga de guardar un punto (x,y) en un archivo con el formato ``x ; y \n"`` dentro de un strean de manera secuencial, donde las abcisas son un indice que se va icrementando a medida que recorre elementos de los distintos campos ``DATA`` de cada paquete, y las ordenadas la versión normalizada de los datos de dicho campo. Es llamada por otra función que se describe a continuación. Recibe como entrada un ``paquete_t`` y un puntero a ``FILE``.
##### Pseudocódigo
```
Funcion guardar_punto ( cant_datos, datos_norm_paq, ult_indice, archivo )
	Definir ordenada Como Real
	Definir indice Como Entero
	Definir cantidad Como Entero
	
	cantidad <- cant_datos
	
	Para indice <- 1 Hasta cantidad Con Paso 1 Hacer
		ordenada <- datos_norm_paq[indice]
		Escribir "Guardar en archivo (", indice + ult_indice," ; ",ordenada,")"
	Fin Para
	
Fin Funcion
```
#### Guardar todos los puntos (x,y) de todos los paquetes en un archivo
```c
    void guardar_valores_en_txt(char* nom, paquetes lista, uint8_t np);
```
``guardar_valores_en_txt`` toma la lista de paquetes completa y guarda consecutivamente todos los puntos obtenidos de cada paquete. Para ello requiere llamar a la función ``guardar_punto`` para guardar un punto (abcisa, ordenada).
##### Pseudocódigo
```
Funcion  guardar_valores_en_txt ( nombre, lista, cant_paquetes )
	Definir inicio Como Entero
	Definir i Como Entero
	Definir archivo Como Entero
	
	archivo <- abrir_archivo(nombre, "w")
	inicio <- 0
	
	Para i <- 1 Hasta cant_paquetes Con Paso 1 Hacer
		guardar_punto(lista[i], inicio, archivo)
	Fin Para
Fin Funcion
```
#### Mostrar en pantalla el encabezado de un paquete
```c
    void mostrar_encabezado(paquete_t paq);
```
Imprime en pantalla los valores de ``H1`` y ``H2`` de un paquete.
#### Mostrar en pantalla los identificadores de un paquete
```c
    void mostrar_identificadores(paquete_t paq);
```
Imprime en pantalla los valores de ``ID``, ``ORIG`` y ``DEST`` de un paquete.
#### Mostrar en pantalla el campo ``TYPE`` en pantalla
```c
    void mostrar_tipo(uint8_t tipo);
```
Imprime en pantalla el valor de ``TYPE`` de un paquete.
#### Mostrar en pantalla el contenido de ``DATA`` en un paquete
```c
    void mostrar_datos(paquete_t paq);
```
Recorre en forma iterativa el campo ``DATA`` de un paquete para imprimir en pantalla y formato hexadecimal cada elemento.
#### Mostrar en pantalla todos los paquetes leídos desde archivo
```c
    void mostrar_paquetes_en_pantalla(paquetes lista, uint8_t cant);
```
Esta función muestra los paquetes leídos desde archivo. Sirve para el usuario como una muestra de lo obtenido y también me fue de utilidad como un método de inspección rápida frente a errores en la lectura de datos hexadecimales del campo ``DATA``.
***
## Administración de memoria
### Chequear la existencia del puntero
```c
    void* cheq_mem_ptr(void* puntero, char* mensaje);
```
La única responsabilidad de esta función es dar cuenta al usuario del tipo de error que ocurre en la asignación de punteros. La función recibe como entradas una dirección y un string. Si pudo reservarse memoria -es decir, es distinto de ``NULL``- devuelve la dirección del puntero recibido, caso contrario muestra en pantalla un mensaje de error personalizado, provisto por ``char*`` ("No hay suficiente memoria", "No existe el archivo", etc).
##### Pseudocódigo
```
Funcion puntero_salida <- cheq_mem_ptr ( puntero,  mensaje_error )
	Si puntero = 0 Entonces
		Escribir mensaje_error
	FinSi
	puntero_salida <- puntero
Fin Funcion
```
### Reservar una cantidad de bytes de memoria para un puntero
```c
    void* res_memoria(size_t n_bytes);
```
##### Pseudocódigo
```
Funcion puntero <- reservar_memoria ( cantidad_bytes )
	puntero <- funcion_de_sistema( cantidad_bytes )
	
	puntero <- cheq_mem_ptr ( puntero,  "Memoria Insuficiente" )
Fin Funcion
```
Esta función recibe una entrada de tipo ``size_t`` que significa la cantidad de bytes que se desean reservar en memoria. Da como salida la dirección del puntero a dicha memoria reservada, verificando antes mediante la función ``cheq_mem_ptr``.

### Redimensionar un puntero dado a un nuevo tamaño
```c
    void* redim_memoria(void* ptr_original, size_t cant_bytes);
```
Análogamente a la anterior, esta función devuelve la dirección de un puntero que corresponde a la memoria apuntada por ``ptr_original`` con el nuevo tamaño de ``cant_bytes``.
##### Pseudocódigo
```
Funcion puntero <- redimensionar_memoria (puntero, nueva_cantidad_bytes )
	nuevo_puntero <- funcion_de_sistema( nueva_cantidad_bytes )
	
	nuevo_puntero <- cheq_mem_ptr ( puntero,  "Memoria Insuficiente" )
Fin Funcion
```
### Liberar la memoria de un puntero del tipo ``paquetes``
```c
    void liberar_lista_paquetes(paquetes lista, uint8_t cant);
```
``liberar_lista_paquetes`` se encarga de liberar la memoria de los campos ``DATA`` y los datos normalizados de cada paquete, y por último liberar la memoria dedicada al puntero a ``paquetes_t`` que guardaba la lista de estructuras.

Por estar específicamente dedicada a un puntero a ``paquetes_t``, esta función podría haber sido ubicada en la sección **paquetes**, pero por realizar únicamente tareas de memoria permanecen en esta parte del programa.
##### Pseudocódigo
```
Funcion liberar_lista_paquetes ( paquetes, cantidad )
	
	Para indice <- 1 Hasta cantidad Con Paso 1 Hacer
		liberar_datos_paquete(paquetes[indice]) // en C: free()
		liberar_datos_normalizados(paquetes[indice]) // en C: free()
	Fin Para
	
Fin Funcion
```
***
## Lectura, Verificación, Ordenación por ``ID`` y Normalización de Paquetes

### Lectura de Paquetes desde Archivo

#### Leer una lista de enteros sin signo de 32 bits
```c
    void leer_lista_uint32(FILE* archivo, uint32_t* enteros, uint8_t cantidad);
```
``leer_lista_uint32`` se encarga de leer una lista de enteros sin signo de 32 bits desde un archivo. Es requerida por otras funciones para cargar cada uno de los valores del campo ``DATA`` de un paquete ``paquete_t``.
##### Pseudocódigo
```
Funcion leer_lista_uint32 ( lista, n_paq, n_datos )
	Para cont <- 1 Hasta n_datos Con Paso 1 Hacer
		lista[n_paq, cont] <- leer_uint32_desde_archivo(cont, n_paq)
	Fin Para
Fin Funcion
```
#### Leer la cabecera de un paquete (``H1``y ``H2``) desde archivo
```c
    cabecera_t leer_cabecera(FILE* archivo);
```
Esta función lee una estructura del tipo ``cabecera_t`` (que como miembros tiene a ``H1`` y ``H2`` de un paquete) desde un archivo. Es utilizada desde otras funciones para la lectura de un paquete y adicionalmente para verificar que el puntero de lectura de archivos se encuentra en el inicio de un nuevo paquete. Se vale de la función ``leer_uint8_desde_archivo()`` para ambos valores.

#### Leer los identificadores ``ID``, ``ORIG`` y ``DEST`` de un paquete desde archivo
```c
    ident_t leer_identificadores(FILE* archivo);
```
Análogamente a la función anterior, se encarga de leer una estructura de tipo ``ident_t`` (cuyos miembros son los campos ``ID``, ``ORIG`` y ``DEST`` de un paquete) desde un archivo. Se vale de la función ``leer_uint8_desde_archivo()`` para los tres valores.

#### Leer los datos del campo ``DATA`` de un paquete desde archivo
```c
    void leer_datos_paquete(uint8_t tamanio, FILE* archivo, uint32_t* datos);
```
Esta función realiza la lectura de todos los valores del campo ``DATA`` de un paquete en particular desde archivo. Tiene como entradas el campo ``SIZE`` (tamaño en bytes de ``DATA``), un puntero a archivo y un puntero a ``uint32_t`` que corresponde la lista de enteros del campo ``DATA``. Se vale de ``leer_lista_uint32()`` para cumplir su cometido.

#### Leer los datos ``CRC1`` y ``CRC2`` de un paquete desde archivo
```c
    crcs_t leer_crcs(FILE* archivo);
```
Como su nombre lo indica, se encarga de leer los datos correspondientes a ``CRC1`` y ``CRC2`` de un paquete desde archivo. La salida es una estructura de tipo ``crcs_t`` que contiene ambos valores. Se vale de la función ``leer_uint8_desde_archivo()``.

#### Leer un paquete desde archivo de forma auxiliar
```c
    paquete_t leer_paquete_auxiliar(FILE* arch);
```
Esta función se vale de las anteriores para leer un paquete completo -desde ``H1`` hasta ``CRC2``- y guardarlo en una estructura del tipo ``paquete_t``.

#### Enviar un paquete previamente leído desde archivo a un puntero ``paquetes``
```c
    void paquete_a_puntero(paquetes lista, uint8_t* cant, FILE* arch, uint8_t dest);
```
Previo control de las condiciones de **inicio de paquete** y **suma de verificación válida**, esta función se encarga de guardar definitivamente un paquete leído de manera auxiliar con ``leer_paquete_auxiliar()`` dentro del puntero a paquetes ``paquetes``.
##### Pseudocódigo
```
Funcion paquete_a_puntero ( lista,  cant, archivo, dest )
	
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
```
#### Leer todos los paquetes desde archivo
```c
    void leer_desde_archivo(paquetes *lista, uint8_t *np, FILE* arch, uint8_t  dest);
```
Esta función es la más general de todas en esta sección: Encierra la estructura de "cebolla" que conforman todas las funciones de lectura de los paquetes. Es la que define por primera vez la memoria del puntero de tipo ``paquetes`` y lo redimentsiona cada vez que llega un nuevo ``paquete_t`` desde el proceso de lectura.
##### Pseudocódigo
```
Funcion leer_desde_archivo ( lista ,np ,arch , dest )
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
```
### Verificación de Paquetes

#### Realizar la suma de verificación de un paquete
```c
    uint16_t verificar_paquete(FILE* arch, uint8_t n_campo_data);
```
Esta función recibe como entradas un puntero a ``FILE`` y el tamaño del campo ``DATA``. A partir de ellos genera un arreglo de ``uint8_t`` que guarda toda la información en bloques del tamaño de un entero sin signo de 8 bits (desde ``H1`` hasta ``CRC2`` sin discriminar por campo), para posteriormente realizar la suma de verificación mediante la función ``calculate_checksum`` provista por la cátedra. Esta función devuelve ``0`` si el paquete se verifica.
##### Pseudocódigo
```
Funcion verificado <- verificar_paquete ( archivo, dimension_data  )
	Definir dim Como Entero
	Definir i Como Entero
	
	// DIM = 7 bytes + N bytes + 2 bytes
	dim <- 7 + dimension_data + 2
	
	Dimension vector(dim)
	
	// Retroceder el puntero el tamaño de un paquete
	mover_puntero_lectura(archivo, -dim, posicion_actual)
	
	Para i <- 1 Hasta dim Con Paso 1 Hacer
		vector[i] <- leer_uint8_desde_archivo(archivo)
	Fin Para
	
	// Provista por cátedra
	verificado <- calcular_suma_verificacion(vector, dim)
Fin Funcion
```
**ATENCION**: **La función sólo tiene sentido luego de la lectura de un paquete** para su posterior asignación a la lista de paquetes. Un cambio en el orden de llamada dentro del proceso de lectura puede resultar en serios problemas (pérdida de referencia respecto de la posición del puntero sobre los datos).
#### Confirmar el inicio de un paquete
```c
    uint8_t confirmar_inicio_paquete(FILE* archivo);
```
Como su nombre lo indica, confirma que el puntero de lectura de archivo se encuentra sobre el inicio de un nuevo paquete. Es decir, verifica que los primeros bytes de lectura corresponden a los valores hexadecimales ``0x3c`` y ``0x4d``. Esta función y la anterior son las que manejan la carga o no de un nuevo paquete. Hace uso de la función ``leer_cabecera`` para confirmar el inicio.
##### Pseudocódigo
```
Funcion es_cabecera <- confirmar_inicio_paquete ( archivo )
	Definir h1 Como Entero
	Definir h2 Como Entero
	
	h1, h2 = leer_cabecera(archivo)
	
	es_cabecera = (h1 = 60) y (h2 = 77)
	
	// Regresar puntero a posición original
	mover_puntero_lectura(archivo, -2, pos_actual)
	
Fin Funcion
```
### Ordenación de paquetes según ``ID``

#### Comparar dos paquetes según su ``ID``
```c
    int comparar_ids(const void* valor_1, const void* valor_2);
```
Es una función de callback que sirve de criterio de ordenación de paquetes para la función ``qsort()``. Internamente se realizan casts a ``paquetes`` sobre ``valor_1`` y ``valor_2`` para comparar según sus ``ID``, que son miembros de la estructura anidada ``ident_t``, perteneciente a todo paquete ``paquete_t``.

#### Ordenar todos los paquetes cargados en puntero del tipo ``paquetes`` según su ``ID``
```c
    void ordenar_por_id(paquetes lista, uint8_t cantidad);
```

Esta función consiste en una llamada a ``qsort()``, que recibe como argumentos un puntero del tipo ``paquetes``, la cantidad total de paquetes con destino ``DEST`` (desde prompt), el tamaño de un ``paquete_t`` y la función de callback ``comparar_ids``.

### Normalización de paquetes

#### Encontrar el valor mínimo del campo ``DATA`` de un paquete
```c
    double encontrar_minimo_parcial(paquete_t paq, uint8_t n_datos);
```
Se encarga de encontrar el mínimo entre los datos del campo ``DATA`` de un paquete, recibiendo como argumentos una variable ``paquete_t`` y otra del tipo ``uint8_t`` que contiene la cantidad de datos (no el tamaño del campo ``SIZE``, sino éste último dividido entre ``sizeof(uint32_t)``).

#### Encontrar el valor mínimo general
```c
    double encontrar_minimo(paquetes lista, uint8_t cant);
```
Esta función encuentra el mínimo general de todos los paquetes. Se vale de ``encontrar_minimo_parcial()`` para comparar el mínimo general con el de cada mínimo parcial.

#### Encontrar el valor máximo del campo ``DATA`` de un paquete
```c
    double encontrar_maximo_parcial(paquete_t paq, uint8_t n_datos);
```
Análoga a ``encontrar_minimo_parcial()`` en términos de encontrar el **máximo parcial**.

#### Encontrar el valor máximo general
```c
    double encontrar_maximo(paquetes lista, uint8_t cant);
```
Análoga a ``encontrar_minimo()`` en términos de encontrar el **máximo general**.

#### Generar los datos normalizados en [0,1] de un paquete
```c
    void datos_normalizados_paquete(paquetes paq, double maximo, double minimo);
```
A partir de los máximos y mínimos generales obtenidos en las funciones anteriores, ``datos_normalizados_paquete()`` se encarga de generar sobre un paquete en particular los datos normalizados a partir de los existentes en el campo ``DATA`` y los almacena en un puntero a ``uint32_t`` denominado ``norm``, perteneciente a la misma estructura que los datos originales.

#### Obtener los datos normalizados para todos los paquetes
```c
    void obtener_datos_normalizados(paquetes *lista, uint8_t  cantidad);
```
Esta función se encarga de gobernar el proceso de obtener la versión normalizada en [0,1] del campo ``DATA`` para todos los paquetes leídos desde archivo. Recibe como argumentos la lista de paquetes (puntero ``paquetes``) y la cantidad total de paquetes con destino ``DEST``.
***
## Estructuras de datos utilizadas
Las funciones que se describieron anteriormente hacen referencia a distintos tipos de datos del tipo ``struct`` y punteros. A continuación se muestran todas las estructuras que describen la forma en que se almacenan en memoria los paquetes y cómo las funciones sacan provecho de las mismas.

```c
// ESTRUCTURA CABECERA DE PAQUETE
typedef struct
{
    uint8_t h1; // H1 = 0x3C
    uint8_t h2; // ​H2 = 0x4D​
} cabecera_t;

// ESTRUCTURA IDENTIFICADORES DE PAQUETE
typedef struct
{
    uint8_t id;     // identificador de paquete
    uint8_t orig;   // ​0x01
    uint8_t dest;   // 0x05 o 0x10
} ident_t;

// ESTRUCTURA DE DATOS DE PAQUETE
typedef struct
{
    uint8_t     tam;    // tamanio de datos
    uint32_t*   datos;  // array de 'tam' datos de 32 bits
    double*     norm;   // datos normalizados
} datos_t;

// ESTRUCTURA DE CRC'S DE PAQUETE
typedef struct
{
    uint8_t crc1;   // CRC1
    uint8_t crc2;   // CRC2
} crcs_t;

// ESTRUCTURA DE UN PAQUETE
typedef struct
{
    cabecera_t  enc;        // Encabezados H1 y H2
    ident_t     identif;    // Identificadores ID, ORIG y DEST
    uint8_t     tipo;       // Tipo: 0x30 o 0x40
    datos_t     infopaq;    // Datos de un paquete
    crcs_t      crcs;       // CRC1 y CRC2
} paquete_t;

// PUNTERO A PAQUETES
typedef paquete_t* paquetes;    // Puntero a paquete_t (lista de paquetes)
```
***
## Resultados obtenidos

Se muestran a continuación capturas de pantalla de las pruebas de ejecución del programa para los dos casos posibles de identificadores de destino (``DEST``): ``0x05`` y ``0x10``.

### Primera Ejecución: Caso ``0x05`` (5 decimal)

#### Ejecución desde el terminal
En esta primera prueba, se ejecutó desde el terminal el programa ``tpfinal.exe``. En la imagen se pueden apreciar los cuatro argumentos que son relevantes al programa: el nombre del ejecutable, el identificador de destino (el equivalente decimal de ``0x05``) y los archivos de entrada y salida con sus respectivas rutas.

![1.png](https://www.dropbox.com/s/yxjk5m6eywdonym/1.png?dl=0&raw=1)


#### Ejecución exitosa y vista previa de los paquetes cargados en memoria

Luego de ejecutar el programa, se puede ver parte de la lista de paquetes, en los que se detallan cada uno de los campos y el volcado del contenido de ``DATA`` para cada uno, en formato hexadecimal.

![2.png](https://www.dropbox.com/s/xbvcm81evtks1so/2.png?dl=0&raw=1)

#### Carga de Archivo de Salida En Microsoft Excel

Si vamos a la ubicación de la ruta de salida, encontraremos un archivo en formato *.txt, con los pares (x,y). El próximo paso es abrir el archivo de excel ``Salida.xlsm``.

![3.png](https://www.dropbox.com/s/rqscmlt4prcpknp/3.png?dl=0&raw=1)

#### Observación de Curva Resultante a Partir de los Datos

Se puede observar que para el identificador de destino ``0x05 (5)`` se obtiene una señal senoidal entre 0 y 1, la cual tiene las siguientes características:

- Valor Medio = 0.5
- Período = 52
- Valor Pico a Pico = 1

![4.png](https://www.dropbox.com/s/qrfaq6h4t6i2y94/4.png?dl=0&raw=1)

### Segunda Ejecución: Caso ``0x10`` (16 decimal)

En este caso, dentro de las instrucciones para la ejecución del programa, sólo se modificó el valor del identificador de destino al equivalente decimal de ``0x10`` (16 decimal).

![5.png](https://www.dropbox.com/s/26cq5jue8b5k4rl/5.png?dl=0&raw=1)

#### Observación de Curva Resultante a Partir de los Datos

Se puede observar que para el identificador de destino ``0x10 (16)`` se obtiene una señal triangular entre 0 y 1, la cual tiene las siguientes características:

- Valor Medio = 0.5
- Período = 129
- Valor Pico a Pico = 1

![6.png](https://www.dropbox.com/s/6m1ipu1otj7i7xi/6.png?dl=0&raw=1)
