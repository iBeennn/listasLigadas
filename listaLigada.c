/*
  Implementacion de las funciones basicas para manipular listas
  ligadas de enteros. En base a los tipos de dato nodo y lista
  definidas en el archivo ".h"

  Marco Antonio Heredia Velasco
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"


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
void inicializa(lista * ls)
{
   ls-> tamano =0;
   ls-> inicial =NULL;
}

// regresa el numero de elementos de la lista
int longitud(lista *lst)
{
   return lst-> tamano;
}

// regresa 1 si la lista es vacia 0 si no
int esVacia(lista *lst)
{
   if (longitud(lst) == 0)
      return 1;
   else
      return 0;
}

//regresa el elemento en la posicion indice de la lista
int elemIndice(lista *lst, int indice)
{
   int posActual;
   nodo * actual;
      
   //si el indice no es una posicion valida
   if (indice > longitud(lst)-1 ||
       indice < 0)
   {
      printf("Error, indice fuera de rango.\n");
      return;
   } else {
      //Empezaremos a buscar la posicion desde el nodo inicial
      actual= lst->inicial;
      posActual =0;
      
      //Mientras no lleguemos a la posicion deseada
      while (posActual != indice)
      {
         //avanzamos al siguiente nodo
         actual = actual->siguiente;
         posActual++;
      }
      return actual-> valor;
   }
}


//inserta un elemento en la posicion indice de la lista
void insertaEn(lista *lst, int elemento, int indice)
{
   int posActual;
   nodo * anterior;
   nodo * nuevo;  //apuntador al nuevo nodo

   //pedimos memoria para el nuevo nodo
   nuevo = malloc(sizeof(nodo));

   // asignamos el valor del nodo nuevo
   nuevo->valor = elemento;
   
   //si el indice no es una posicion valida
   if (indice > longitud(lst) ||
       indice < 0)
   {
      printf("Error, indice fuera de rango.\n");
      return;
   } else {

      if (indice == 0)
      {
         //hacemos que el siguiente nodo despues del nuevo sea
         //el nodo al inicio de la lista 
         nuevo->siguiente = lst->inicial;

         //actualizamos el inicio de la lista
         lst->inicial = nuevo;
         
      } else {  //si indice no es 0

         //Empezaremos a buscar la posicion desde el nodo inicial
         anterior= lst->inicial;
         posActual =0;
      
         //Mientras no lleguemos un nodo antes de la posicion deseada
         while (posActual != indice-1)
         {
            //avanzamos al siguiente nodo
            anterior = anterior->siguiente;
            posActual++;
         }

         //el nodo despues del nuevo sera la que antes seguia a
         //la anterior
         nuevo->siguiente = anterior->siguiente;
         
         //y el nodo siguiente al anterior sera ahora el nuevo
         anterior->siguiente = nuevo;

      } //fin si indice no es 0

      //aumentamos el numero de elementos
      lst->tamano++;   
   } //fin else si dan indice adecuado
}

// agrega un elemento al final de la lista
void agregaFinal(lista *lst, int elemento)
{
   //Insertamos elemento en la posicion que corresponde a la
   //longitud de la lista. Recuerda que el maximo indice de la
   //lista es igual a su longitud - 1
   insertaEn(lst, elemento, longitud(lst));
}


//borra el elemento que esta en la posicion indice de la lista
void borraEn(lista *lst, int indice)
{
   int posActual;
   nodo * anterior;
   nodo * borrar; //apuntaremos al nodo que queremos borrar
         
   //si el indice no es una posicion valida
   if (indice > longitud(lst)-1 ||
       indice < 0)
   {
      printf("Error, indice fuera de rango.\n");
      return;
   } else {

      if (indice == 0)  //queremos borrar el nodo inicial
      {
         //a el nodo que queremos borrar
         borrar =lst->inicial;
         
         //ahora el inicial sera el que sigue del primero
         lst->inicial = lst->inicial->siguiente;

         //liberamos la memoria del nodo que borramos
         free(borrar);
         
      } else {
         // si no queremos borrar la primera

         //Empezaremos a buscar la posicion desde el nodo inicial
         anterior= lst->inicial;
         posActual =0;
      
         //Mientras no lleguemos un nodo antes de la posicion deseada
         while (posActual != indice-1)
         {
            //avanzamos al siguiente nodo
            anterior = anterior->siguiente;
            posActual++;
         }

         //queremos borrar el siguiente de anterior
         borrar = anterior->siguiente;
                  
         //nos saltamos el nodo que queremos borrar
         anterior->siguiente = anterior->siguiente->siguiente;
         
         //liberamos la memoria del nodo que borramos
         free(borrar);
         
      } //fin si no queremos borrar la primera
      
      //reducimos el numero de elementos
      lst->tamano--;   
   } //fin else si dan indice adecuado
}
