/*
  Definicion de estructura de pilas de enteros y de nodo,
  elemento basico para crear pilas.

  Tambien, firmas de las funciones basicas para manipular pilas.

*/

/* ----------------------------------- */
/* Estructura nodo                     */
/* ----------------------------------- */

// definicion de un nodo con su valor y apuntador al siguiente nodo
typedef struct _nodo {
  // es un nodo que guarda valores de enteros
  int valor;
  struct _nodo *siguiente;
} nodo;

/* ------------------------------------ */
/* Estructura pilas y metodos asociados */
/* ------------------------------------ */

// Definicion de una pila con su tamano, nodo inicial y nodo
// final
typedef struct {
  int tamano;
  nodo *inicial;
} pila;

// Para inicializar una pila recien creada
void inicializa(pila *pil);

// regresa el numero de elementos de la pila, 0 si es vacia
int longitud(pila *pil);

// regresa 1 si la pila es vacia 0 si no
int esVacia(pila *pil);

// regresa el elemento en la posicion tope de la pila
int tope(pila *pil);

// inserta un elemento en la posicion siguiente al tope de la pila
void push(pila *pil, int elemento);

// borra el elemento que esta en la posicion tope de la lista
void pop(pila *pil);
