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
    apontador ant;
}celula;

typedef struct{
    apontador primeiro, ultimo;
}TipoLista;

void criarLista(TipoLista *lista){
    lista->primeiro = (apontador) malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
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
    lista->ultimo->prox->ant = lista->ultimo;
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

void imprimirContrario(TipoLista lista){
    if(vazia(lista)){
        printf("Lista vazia!!!\n");
    }else{
        apontador aux = lista.ultimo;
        printf("=======Impressao da Lista ao contrário=======\n");
        while(aux != lista.primeiro){
            printf("%d\n", aux->item.id);
            aux = aux->ant;
        }
    }
    printf("\n");
}

void imprimirItem(TipoLista lista, int id){
    if(vazia(lista)){
        printf("Lista vazia!!!\n");
    }else{
        int achou = 0;
        apontador aux = lista.primeiro->prox;
        while(aux != NULL){
            if(aux->item.id == id){
                printf("=======Impressao de um item=======\n");
                printf("%d\n", aux->item.id);
                printf("\n");
                achou = 1;
                break;
            }
            aux = aux->prox;
        }
        if(achou==0){
            printf("Nenhum item foi localizado com o id informado\n");
        }
    }
}

void removerItem(TipoLista *lista, int id){
    int achou = 0;
    if(vazia(*lista)){
        printf("Lista vazia!!!\n");
    }else{
        if(lista->primeiro->prox->item.id == id){
            apontador aux = lista->primeiro->prox;
            lista->primeiro->prox = aux->prox;
            lista->primeiro->prox->ant = lista->primeiro;
            free(aux);
            achou = 1;
        }else if(lista->ultimo->item.id == id){
            apontador aux;
            aux = lista->ultimo;
            lista->ultimo = aux->ant;
            lista->ultimo->prox = NULL;
            free(aux); //liberar memória
            achou = 1;
        }else{
            apontador aux;
            aux = lista->primeiro->prox;
            while(aux != NULL){
                if(aux->item.id == id){
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    free(aux); //liberar memória
                    achou = 1;
                    break;
                }
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

    item.id = 2;
    inserirFinal(&lista, item);

    item.id = 100;
    inserirFinal(&lista, item);

    item.id = 1;
    inserirFinal(&lista, item);

    imprimir(lista);

    imprimirContrario(lista);

    //removerItem(&lista, 40);

    //imprimir(lista);

    //removerItem(&lista, 30);

    //removerItem(&lista, 200);

    //imprimirItem(lista, 10);

    return 0;

}
