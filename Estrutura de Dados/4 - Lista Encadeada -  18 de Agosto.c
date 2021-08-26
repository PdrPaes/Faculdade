#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    //demais campos
}TipoItem;

typedef struct celula_struct *apontador;

typedef struct celula_struct{
    TipoItem item;
    apontador prox;
}celula;

typedef struct{
    apontador primeiro, ultimo;
}TipoLista;

void criarLista(TipoLista *lista){
    lista->primeiro = (apontador) malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

int vazia(TipoLista lista){
    if(lista.primeiro == lista.ultimo){
        return 1;
    }else{
        return 0;
    }
}

void inserirFinal(TipoLista *lista, TipoItem item){
    lista->ultimo->prox = (apontador) malloc(sizeof(celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = item;
}

void imprimir(TipoLista lista){
    if(vazia(lista)){
        printf("Lista vazia!!!\n");
    }else{
        apontador aux = lista.primeiro->prox;
        printf("=======Impressao da Lista=======\n");
        while(aux != NULL){
            printf("%d\n", aux->item.id);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void removerItem(TipoLista *lista, int id){
    int achou = 0;
    if(vazia(*lista)){
        printf("Lista vazia!!!\n");
    }else{
        if(lista->primeiro->prox->item.id == id){
            apontador aux = lista->primeiro->prox;
            lista->primeiro->prox = aux->prox;
            free(aux);
            achou = 1;
        }else{
            apontador aux, anterior;
            aux = lista->primeiro->prox;
            while(aux != NULL){
                if(aux->item.id == id){
                    anterior->prox = aux->prox;
                    free(aux); //liberar memória
                    achou = 1;
                    break;
                }
                anterior = aux;
                aux = aux->prox;
            }
        }
        if(achou==0){
            printf("O ID %d nao esta presente na lista\n", id);
        }
    }
}



int main(){

    TipoLista lista;
    TipoItem item;

    criarLista(&lista);

    //printf("Vazia? %d\n", vazia(lista));

    item.id = 10;
    inserirFinal(&lista, item);

    item.id = 20;
    inserirFinal(&lista, item);

    item.id = 30;
    inserirFinal(&lista, item);

    imprimir(lista);

    removerItem(&lista, 10);

    imprimir(lista);

    removerItem(&lista, 30);

    imprimir(lista);

    removerItem(&lista, 200);

    return 0;

}
