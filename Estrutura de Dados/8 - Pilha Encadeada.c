#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int id;
    struct item*prox;
}node;

void criaPilha(node*pilha){
    pilha->prox=NULL;
}

int vazia(node pilha){
    if(pilha->prox==NULL){
        return 1;
    } else {
        return 0;
    }
}

void push(node *pilha, int id){
    node *novo = (node*)malloc(sizeof(node));
    if(novo==NULL){
        printf("Sem memória disponível");
    } else {
        novo->id = id;
        novo->prox =NULL;
        if(vazia(*pilha)==1){
            pilha->prox = novo;
        } else {
            novo *aux = pilha-> prox;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
        }
    }
}

node* pop(node *pilha){
    if(vazia(*pilha)==1){
        printf("A pilha esta vazia!");
    } else {
        node *ultimo = pilha ->prox;
        node *penultimo =pilha;
        while (ultimo -> prox!= NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo -> prox = NULL;
        return ultimo;
    }
}

void imprimir(node pilha){
    if(vazia(pilha)==1){
        printf("A pilha está vazia");
    } else {
        node *aux = pilha.prox;
        while(aux != NULL){
            printf("%d\n", aux->id);
            aux = aux -> prox;
        }
        printf("\n");
    }
}

