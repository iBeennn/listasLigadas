/*
  Definicion de estructura de lista ligada de enteros y de nodo,
  elemento basico para crear listas.

  Tambien, firmas de las funciones basicas para manipular listas.

  Marco Antonio Heredia Velasco
*/

/* ----------------------------------- */
/* Estructura nodo                     */
/* ----------------------------------- */

//definicion de un nodo con su valor y apuntador al siguiente nodo
typedef struct _nodo
{
   //es un nodo que guarda valores de enteros
   int valor;
   struct _nodo * siguiente;
} nodo;


/* ------------------------------------ */
/* Estructura lista y metodos asociados */
/* ------------------------------------ */


// Definicion de una lista con su tamano, nodo inicial y nodo
// final 
typedef struct {
   int tamano;
   nodo * inicial;
} lista;


// Para inicializar una lista recien creada
void inicializa(lista * ls);

// regresa el numero de elementos de la lista, 0 si es vacia
int longitud(lista *lst);

// regresa 1 si la lista es vacia 0 si no
int esVacia(lista *lst);

//regresa el elemento en la posicion indice de la lista
int elemIndice(lista *lst, int indice);

//inserta un elemento en la posicion indice de la lista
void insertaEn(lista *lst, int elemento, int indice);

// agrega un elemento al final de la lista
void agregaFinal(lista *lst, int elemento);

//borra el elemento que esta en la posicion indice de la lista
void borraEn(lista *lst, int indice);
