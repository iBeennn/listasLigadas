/*
  Programa para probar el funcionamiento de las pilas
  de enteros definidas en el archivo pila.c

*/
#include <stdio.h>
#include "pila.h"

int main() {
  int i;
  pila p;

  // inicializamos la pila l para usarla
  inicializa(&p);

  // agregamos elementos a la pila
  push(&p, 12);
  printf("sadkasjdlasjdlajsdlkas\n");
  push(&p, 4);
  push(&p, 5);
  push(&p, 3);

  // ahora la pila es 12, 4, 5, 3

  // insertamos un 90 en la pila
  push(&p, 90);

  // ahora la pila es 12, 4, 5, 3, 90

  // borramos el elemento 90
  pop(&p);

  // ahora la lista es 12, 4, 5, 3

  if (esVacia(&p))
    printf("\nLa pila es vacia.\n");
  else
    printf("\nLa pila NO es vacia.\n");

  printf("Longitud de la pila: %d\n", longitud(&p));
  printf("Los elementos dentro la pila son:\n");

  for (i = 0; i < longitud(&p); i++) {
    printf("%d\n", tope(&p));
    pop(&p);
  }
}
