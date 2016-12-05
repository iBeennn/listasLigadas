/*
  Programa para probar el funcionamiento de las listas ligadas
  de enteros definidas en el archivo listaLigada.c
  
  Marco Antonio Heredia Velasco
*/
#include <stdio.h>
#include "listaLigada.h"

void main()
{
   int i;
   lista l;
   
   //inicializamos la lista l para usarla
   inicializa(&l);

   //agregamos elementos al la lista
   agregaFinal(&l, 12);
   agregaFinal(&l, 4);
   agregaFinal(&l, 5);
   agregaFinal(&l, 3);

   // ahora la lista es 12, 4, 5, 3

   //insertamos un 90 en el indice 2 de la lista
   insertaEn(&l, 90, 2);

   // ahora la lista es 12, 4, 90, 5, 3
   
   //borramos el elemento con indice 1
   borraEn(&l, 1);

   // ahora la lista es 12, 90, 5, 3


   if (esVacia(&l))
      printf("\nLa lista es vacia.\n");
   else
      printf("\nLa lista NO es vacia.\n");

   printf("Longitud de la lista: %d\n", longitud(&l));
   printf("Los elementos dentro la lista son:\n");

   for (i=0; i< longitud(&l); i++){
      printf("%d\n", elemIndice(&l,i));
   }
}
