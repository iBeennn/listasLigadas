#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
   int valor;
   struct _nodo * siguiente;
} nodo;

typedef struct {
   int tamano;
   nodo * inicial;
} pila;


void inicializa(pila * pi);

int longitud(pila *pil);

int esVacia(pila *pil);

int tope(pila *pil);

void push(pila *pil, int elemento);

void pop(pila *pil);


void inicializa(pila * pi)
{
   pi-> tamano =0;
   pi-> inicial =NULL;
}

int longitud(pila *pil)
{
   return pil-> tamano;
}

int esVacia(pila *pil)
{
   if (longitud(pil) == 0)
      return 1;
   else
      return 0;
}


int tope(pila *pil)
{
   int posActual=0;
   nodo * actual;


   if (longitud(pil) == 0)
   {
      printf("La pila es vacia");
      return;
   } else {

      actual= pil->inicial;
      posActual =0;


      while (posActual != pil-> tamano)
      {

         actual = actual->siguiente;
         posActual++;
      }
      return actual-> valor;
   }
}



void push(pila *pil, int elemento)
{
   int posActual=0;
   nodo * actual;
   nodo * nuevo;

   nuevo = malloc(sizeof(nodo));


   nuevo->valor = elemento;

  if (pil->tamano == 0)
      {
         nuevo->siguiente = pil->inicial;


         pil->inicial = nuevo;

      } else {

         actual= pil->inicial;
         posActual =0;

         while (posActual != pil-> tamano)
      {

         actual = actual->siguiente;
         posActual++;
      }

         nuevo->siguiente = actual->siguiente;
         actual->siguiente = nuevo;

      }

      pil->tamano++;
   }

void pop(pila *pil)
{
   int posActual=0;
   nodo * actual;
   nodo * borrar;


   if (longitud(pil) == 0)
   {
      printf("La pila es vacia");
      return;
   } else {

         actual= pil->inicial;
         posActual =0;

         while (posActual != pil-> tamano-1)
      {

         actual = actual->siguiente;
         posActual++;
      }


         borrar = actual->siguiente;


         actual->siguiente = actual->siguiente->siguiente;


         free(borrar);

      }

      pil->tamano--;
}


void main()
{
   int i=0;
   pila p;

   inicializa(&p);

   push(&p, 12);
   push(&p, 4);
   push(&p, 5);
   push(&p, 3);

   push(&p, 90);

   pop(&p);

   if (esVacia(&p))
      printf("\nLa pila es vacia.\n");
   else
      printf("\nLa pila NO es vacia.\n");

   printf("Longitud de la pila: %d\n", longitud(&p));
   printf("Los elementos dentro la pila son:\n");

   for (i=0; i< longitud(&p); i++){
      printf("%d\n", tope(&p));
      pop(&p);
   }
}

