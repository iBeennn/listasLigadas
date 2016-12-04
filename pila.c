/*
  Implementacion de las funciones basicas para manipular listas
  ligadas de enteros. En base a los tipos de dato nodo y lista
  definidas en el archivo ".h"

  Marco Antonio Heredia Velasco
*/

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/*
  Definiciones de nodo y lista, ya incluidas en listaLigada.h

typedef struct _nodo
{
   int valor;
   struct _nodo * siguiente;
} nodo;

typedef struct {
   int tamano;
   nodo * inicial;
} lista;
*/


// Para inicializar una lista recien creada
void inicializa(pila * pil)
{
   pil-> tamano =0;
   pil-> inicial =NULL;
}

// regresa el numero de elementos de la lista
int longitud(pila *pil)
{
   return pil-> tamano;
}

// regresa 1 si la lista es vacia 0 si no
int esVacia(pila *pil)
{
   if (longitud(pil) == 0)
      return 1;
   else
      return 0;
}

//regresa el elemento en el tope
int tope(pila *pil)
{
   int posActual;
   nodo * actual;

   //si la pila es vacia
   if (longitud(pil) == 0)
   {
      printf("La pila es vacia");
      return;
   } else {
      //Empezaremos a buscar el tope desde el nodo inicial
      actual= pil->inicial;
      posActual =0;

      //Mientras no lleguemos a la posicion deseada
      while (posActual != pil-> tamano)
      {
         //avanzamos al siguiente nodo
         actual = actual->siguiente;
         posActual++;
      }
      return actual-> valor;
   }
}


//inserta un elemento en la posicion despues del tope
void push(pila *pil, int elemento)
{
   int posActual;
   nodo * actual;
   nodo * nuevo;  //apuntador al nuevo nodo

   //pedimos memoria para el nuevo nodo
   nuevo = malloc(sizeof(nodo));

   // asignamos el valor del nodo nuevo
   nuevo->valor = elemento;

   //si el indice no es una posicion valida

      if (pil->tamano == 0)
      {
         //hacemos que el siguiente nodo despues del nuevo sea
         //el nodo al inicio de la lista
         nuevo->siguiente = pil->inicial;

         //actualizamos el inicio de la lista
         pil->inicial = nuevo;

      } else {  //si indice no es 0

         //Empezaremos a buscar la posicion desde el nodo inicial
         actual= pil->inicial;
         posActual =0;

         //Mientras no lleguemos un nodo antes de la posicion deseada
         while (posActual != pil-> tamano)
      {
         //avanzamos al siguiente nodo
         actual = actual->siguiente;
         posActual++;
      }

         //el nodo despues del nuevo sera la que antes seguia a
         //la anterior
         nuevo->siguiente = actual->siguiente;

         //y el nodo siguiente al anterior sera ahora el nuevo
         actual->siguiente = nuevo;

      } //fin si indice no es 0

      //aumentamos el numero de elementos
      pil->tamano++;
   } //fin else si dan indice adecuado
}


//borra el elemento que esta en la posicion tope
void pop(pila *pil)
{
   int posActual;
   nodo * actual;
   nodo * borrar; //apuntaremos al nodo que queremos borrar

   //si el indice no es una posicion valida
   if (longitud(pil) == 0)
   {
      printf("La pila es vacia");
      return;
   } else {

         //Empezaremos a buscar la posicion desde el nodo inicial
         actual= pil->inicial;
         posActual =0;

         //Mientras no lleguemos un nodo antes de la posicion deseada
         while (posActual != pil-> tamano-1)
      {
         //avanzamos al siguiente nodo
         actual = actual->siguiente;
         posActual++;
      }

         //queremos borrar el siguiente de anterior
         borrar = actual->siguiente;

         //nos saltamos el nodo que queremos borrar
         actual->siguiente = actual->siguiente->siguiente;

         //liberamos la memoria del nodo que borramos
         free(borrar);

      } //fin si no queremos borrar la primera

      //reducimos el numero de elementos
      pil->tamano--;
   } //fin else si dan indice adecuado
}
