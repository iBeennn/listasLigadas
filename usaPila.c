/*
  Programa para probar el funcionamiento de las listas ligadas
  de enteros definidas en el archivo listaLigada.c

  Marco Antonio Heredia Velasco
*/
#include <stdio.h>
#include "pila.h"

void main()
{
   int i;
   pila p;

   //inicializamos la lista l para usarla
   inicializa(&p);

   //agregamos elementos al la lista
   push(&p, 12);
   push(&p, 4);
   push(&p, 5);
   push(&p, 3);

   // ahora la lista es 12, 4, 5, 3

   //insertamos un 90 en el indice 2 de la lista
   push(&p, 90);

   // ahora la lista es 12, 4, 90, 5, 3

   //borramos el elemento con indice 1
   pop(&p);

   // ahora la lista es 12, 90, 5, 3


   if (esVacia(&p))
      printf("\nLa lista es vacia.\n");
   else
      printf("\nLa lista NO es vacia.\n");

   printf("Longitud de la lista: %d\n", longitud(&p));
   printf("Los elementos dentro la lista son:\n");

   for (i=0; i< longitud(&p); i++){
      printf("%d\n", tope(&p));
   }
}
