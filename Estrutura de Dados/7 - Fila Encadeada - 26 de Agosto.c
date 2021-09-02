#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int id;
    struct item *prox;
}node;

void criaFila(node *fila){
    fila->prox = NULL;
}

int vazia(node fila){
    if(fila.prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void inserir(node *fila, int id){
    node *novo = (node*) malloc(sizeof(node));

    if(novo == NULL){
        printf("Sem espaco na memoria");
    }else{
        novo->id = id;
        novo->prox = NULL;
        if(vazia(*fila)==1){
            fila->prox = novo;
        }else{
            node *aux = fila->prox;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
}

node* remover(node *fila){
    node *aux = fila->prox;
    fila->prox = aux->prox;
    return aux;
}

int quantidade(node fila){
    int cont = 0;
    if(vazia(fila)==1){
        return 0;
    }else{
        node *aux = fila.prox;
        while(aux != NULL){
            cont++;
            aux = aux->prox;
        }
    }
    return cont;
}

void imprimir(node fila){
    if(vazia(fila)==1){
        printf("A fila esta vazia!!!");
    }else{
        node *aux = fila.prox;
        printf("FILA ");
        while(aux != NULL){
            printf("<- [%d] ", aux->id);
            aux = aux->prox;
        }
    }
    printf("\nTotal de elementos na fila: %d\n\n", quantidade(fila));
}


int main(){

    node fila;

    criaFila(&fila);

    inserir(&fila, 10);
    inserir(&fila, 20);
    inserir(&fila, 30);
    inserir(&fila, 40);
    inserir(&fila, 2);

    imprimir(fila);

    node *removido;

    /*primeiroNormal = removerNormal(&filaNormal);
    printf("\nChamada Fila Normal: %d\n", primeiroNormal->idNormal);*/

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);

    removido = remover(&fila);
    printf("Elemento removido: %d\n", removido->id);
    imprimir(fila);



    return 0;
}
