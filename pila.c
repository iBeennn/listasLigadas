/*
  Implementacion de las funciones basicas para manipular pilas de enteros. En
  base a los tipos de dato nodo y pila
  definidas en el archivo "pila.h"

*/

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*
  Definiciones de nodo y pila, ya incluidas en pila.h

typedef struct _nodo
{
   int valor;
   struct _nodo * siguiente;
} nodo;

typedef struct {
   int tamano;
   nodo * inicial;
} pila;
*/

// Para inicializar una pila recien creada
void inicializa(pila *pi) {
  pi->tamano = 0;
  pi->inicial = NULL;
}

// regresa el numero de elementos de la pila
int longitud(pila *pil) { return pil->tamano; }

// regresa 1 si la pila es vacia 0 si no
int esVacia(pila *pil) {
  if (longitud(pil) == 0)
    return 1;
  else
    return 0;
}

// regresa el elemento en el tope
int tope(pila *pil) {
  int posActual;
  nodo *actual;

  // si la pila es vacia
  if (longitud(pil) == 0) {
    printf("La pila es vacia");
    return 0;
  } else {
    // Empezaremos a buscar el tope desde el nodo inicial
    actual = pil->inicial;
    posActual = 0;

    // Mientras no lleguemos a la posicion deseada
    while (posActual != pil->tamano) {
      // avanzamos al siguiente nodo
      actual = actual->siguiente;
      posActual++;
    }
    return actual->valor;
  }
}

// inserta un elemento en la posicion despues del tope
void push(pila *pil, int elemento) {
  int posActual;
  nodo *actual;
  nodo *nuevo;  // apuntador al nuevo nodo

  // pedimos memoria para el nuevo nodo
  nuevo = malloc(sizeof(nodo));

  // asignamos el valor del nodo nuevo
  nuevo->valor = elemento;

  if (pil->tamano == 0) {
    nuevo->siguiente = pil->inicial;

    // actualizamos el inicio de la lista
    pil->inicial = nuevo;

  } else {  // si la pila no esta vacia

    actual = pil->inicial;
    posActual = 0;

    // Mientras no lleguemos a la posicion deseada
    while (posActual != pil->tamano) {
      // avanzamos al siguiente nodo
      actual = actual->siguiente;
      posActual++;
    }

    // el nodo nuevo apuntara al siguiente del actual
    nuevo->siguiente = actual->siguiente;

    // y el nodo actual apuntara al nuevo
    actual->siguiente = nuevo;
  }

  // aumentamos el numero de elementos
  pil->tamano++;
}

// borra el elemento que esta en la posicion tope
void pop(pila *pil) {
  int posActual;
  nodo *actual;
  nodo *borrar;  // apuntaremos al nodo que queremos borrar

  // si la pila esta vacia
  if (longitud(pil) == 0) {
    printf("La pila es vacia");
    return;
  } else {

    // Empezaremos a buscar la posicion desde el nodo inicial
    actual = pil->inicial;
    posActual = 0;

    // Mientras no lleguemos un nodo antes de la posicion deseada
    while (posActual != pil->tamano - 1) {
      // avanzamos al siguiente nodo
      actual = actual->siguiente;
      posActual++;
    }

    // queremos borrar el siguiente de actual
    borrar = actual->siguiente;

    // nos saltamos el nodo que queremos borrar
    actual->siguiente = actual->siguiente->siguiente;

    // liberamos la memoria del nodo que borramos
    free(borrar);
  }

  // reducimos el numero de elementos
  pil->tamano--;
}
