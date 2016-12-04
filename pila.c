#include <stdio.h>

typedef struct{
    struct elemento* siguiente;
    char* nombre;
}elemento;

elemento* tope=NULL;

void push(elemento* _elemento){
    _elemento -> siguiente = NULL;
    if (tope==NULL){
            tope=_elemento;
    }else{
        _elemento -> siguiente = tope;
        tope = _elemento;
    }
}

elemento* pop(){
    if(tope == NULL){
        return NULL;
    }
    elemento* elemento_retorno = tope;
    tope = elemento_retorno -> siguiente;
    return elemento_retorno;
}

int main(){
    elemento* uno = malloc(sizeof(elemento));
    elemento* dos = malloc(sizeof(elemento));
    elemento* tres = malloc(sizeof(elemento));
    elemento* cuatro = malloc(sizeof(elemento));
    elemento* cinco = malloc(sizeof(elemento));

    uno->nombre="A Game of Thrones";
    dos->nombre="A Storm of Swords";
    tres->nombre="A Feast of Crows";
    cuatro->nombre="A Dance with Dragons";
    cinco->nombre="Winds of Winter";


    push(dos);
    push(tres);
    push(cuatro);
    push(cinco);
    pop();
    push(uno);

    elemento* i = pop();

    while(i!=NULL){
        printf("%s\n", i->nombre);
        i = pop();
    }

    return 0;
}
