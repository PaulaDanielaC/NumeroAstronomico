# NumeroAstronomico 🪐

***Introducción***

El NumeroAstronomico permite a programadores del área astronómica manejar cifras muy grandes.
Las siguientes dos secciones son guías y restricciones para el diseño del TAD pero no son ni la
especificación y ni la implementación.

***Valores***

Un valor NumeroAstronomico es un par ordenado formado por una secuencia de hasta 100 dígitos y un
indicador de error.
En la implementación, un valor NumeroAstronomico es un par ordenado formado por una secuencia de
hasta 100 dígitos y un segundo dato que representará o bien la longitud del número, o bien un código de error.
```
typedef struct {
  const char* entero;
  int longitudError;
} NumeroAstronomico;
```

El campo entero es un puntero al comienzo de un arreglo que fue definido dinámicamente. Este arreglo
contiene cada uno de los dígitos del NumeroAstronomico. Evaluar diferentes posibilidades: dígito más
significativo al principio o al final? Guardar el valor numérico del dígito o el código asociado al
símbolo? (i.e. el valor cero ó el 48, que es el código ASCII del carácter '0'). Dejar espacio para el carry y
marcar el overflow? Cómo se puede almacenar los diferentes errores y longitud del número en un mismo
campo?

***Operaciones***

**Operaciones de Creación**

Aplicar malloc para reservar espacio para la estructura y para el arreglo entero dentro de la estructura.
1. **CrearDesdeCadena** : Cadena → NumeroAstronomico
Especificar con y sin precondiciones (pero implementar únicamente sin precondiciones).
2. **CrearDesdeCifraSeguidaDeCeros** : Cifra × CantidadDeCeros → NumeroAstronomico
Especificar con y sin precondiciones (pero implementar únicamente sin precondiciones). Ejemplo:
CrearDesdeCifraSeguidaDeCeros(25, 7) = (250000000, Ninguno)
3. **CrearAleatorio** : PróximoNúmeroDeLaSecuenciaAleatoria → NumeroAstronomico
Esta operación tiene precondiciones? En la especificación o en la implementación? Aplicar rand.
En la implementación, no habrá parámetro de entrada, ya que el próximo número de la secuencia está implícito luego de invocar a srand.

**Operaciones de Manejo de Errores**

4. **EsSecuenciaNula** : NumeroAstronomico → Boolean
5. **EsSecuenciaInvalida** : NumeroAstronomico → Boolean
6. **EsOverflow** : NumeroAstronomico → Boolean
7. **EsPunteroNulo.** Esta operación es propia de la implementación.
8. **GetTipoDeError :** NumeroAstronomico → TipoDeError
TipoDeError = {Ninguno, CadenaNula, CadenaInvalida, Overflow(, PunteroNulo)}
TipoDeError se implementa como un enum. PunteroNulo es propia de la implementación.
9. **EsError :** NumeroAstronomico → Boolean
Esta operación equivale a: EsCadenaNula ∨ EsCadenaInvalida ∨ EsOverflow

**Operaciones de Salida**

10. **Mostrar :** NumeroAstronomico × GruposEnPrimeraLinea × Flujo → Flujo
Ejemplo:
Sea na = (800700600500400300200100, Ninguno) ∈ NumeroAstronomico entonces:
Mostrar(na, 3, stdout1) = stdout2
escribe en stdout las siguientes líneas:
```
\t\t800.700.600.\n
\t\t 500.400.\n
\t\t 300.200.\n
\t\t 100\n
```
¿Por qué stdout es diferente a stdout2? Notar que la primer línea tiene 3 grupos y las siguientes uno
menos (como máximo). Analizar la necesidad de precondiciones.

**Operaciones Aritméticas**

11. **Sumar :** NumeroAstronomico × NumeroAstronomico → NumeroAstronomico
12. **SonIguales :** NumeroAstronomico × NumeroAstronomico → Boolean
13. **EsMenor :** NumeroAstronomico × NumeroAstronomico → Boolean

**De Persistencia**

Permiten guardar y recuperar valores NumeroAstronomico en memoria externa, en formatos de texto y binario.

**Binario**

Definir una representación medianamente eficiente del NumeroAstronomico en disco y en forma binaria.

14. **Read :** Flujo → NumeroAstronomico × Flujo

15. **Write :** NumeroAstronomico × Flujo → Flujo

**Texto**

El formato de un NumeroAstronómico en un archivo de texto es el siguiente:
secuenciadedigitos#
El dígito más significativo es el primero.

16. **Scan:** Flujo → NumeroAstronomico × Flujo

17. **Print :** NumeroAstronomico × Flujo → Flujo

Repasamos malloc y free

Las variables estáticas se asignan en la memoria principal, por lo general junto con el
código ejecutable del programa, y persisten durante toda la vida del programa; las variables
automáticas se asignan sobre la pila (stack), comienzan cuando se invocan las funciones y
acaban cuando se llama a return. Para las variables estáticas y automáticas se requiere que
el tamaño de la asignación sea constante en tiempo de compilación (antes de C99 , que
permite "arrays" automáticos de longitud variable). Si el tamaño requerido no se conoce
hasta el tiempo de ejecución la utilización de objetos de datos de tamaño fijo es
insuficiente. Ni la memoria estática ni automática es adecuada para todas las situaciones.
Estas limitaciones se evitan mediante el uso de la gestión de memoria en la que la memoria
es más explícitamente (y más flexiblemente) manejada, típicamente mediante la asignación
desde el montón (heap), un área de memoria estructurada para este fin.
MALLOC- FREE (`stdlib.h`)
Asigna/libera un bloque de memoria en el heap
```
int * vectorEnteros;
vectorEnteros = malloc (10 * sizeof (int));
vectorEnteros = (int *) malloc (10 * sizeof (*vectorEnteros));
```
