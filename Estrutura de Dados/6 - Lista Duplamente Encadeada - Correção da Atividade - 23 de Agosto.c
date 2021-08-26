#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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

int buscar(TipoLista lista, int id){
    if(vazia(lista)==1){
        printf("Lista vazia\n");
    }else{
        apontador aux = lista.primeiro->prox;
        while(aux != NULL){
            if(aux->item.id == id){
                return 1;
            }
            aux = aux->prox;
        }
    }
    return 0;
}

void inserirFinal(TipoLista *lista, TipoItem item){
    if(buscar(*lista, item.id)==1){
        printf("ERRO: O id %d ja esta presente na lista\n", item.id);
    }else{
        lista->ultimo->prox = (apontador) malloc(sizeof(celula));
        lista->ultimo->prox->ant = lista->ultimo;
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->prox = NULL;
        lista->ultimo->item = item;
    }
}

void inserir(TipoLista *lista, TipoItem item, int antecessor){
    if(buscar(*lista, antecessor)==0){
        printf("ERRO: O antecessor %d NAO esta presente na lista\n", antecessor);
    }else if(buscar(*lista, item.id)==1){
        printf("ERRO: O id %d ja esta presente na lista\n", item.id);
    }else if(lista->ultimo->item.id == antecessor){
        inserirFinal(lista, item);
    }else{
        apontador aux = lista->primeiro->prox;
        while(aux != NULL){
            if(aux->item.id == antecessor){
                apontador novo = (apontador) malloc(sizeof(celula));
                novo->prox = aux->prox;
                novo->prox->ant = novo;
                novo->ant = aux;
                aux->prox = novo;
                novo->item = item;
                break;
            }
            aux = aux->prox;
        }
    }
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

void trocar(TipoLista *lista, int item1, int item2){
    if(buscar(*lista, item1)==0){
        printf("O id do primeiro item nao esta na lista");
    }else if(buscar(*lista, item2)==0){
        printf("O id do segundo item nao esta na lista");
    }else{
        apontador auxItem1, auxItem2, aux;
        aux = lista->primeiro->prox;
        while(aux != NULL){
            if(aux->item.id == item1){
                auxItem1 = aux;
            }else if(aux->item.id == item2){
                auxItem2 = aux;
            }
            aux = aux->prox;
        }
        apontador antItem1, antItem2, proxItem1, proxItem2;

        antItem1 = auxItem1->ant;
        proxItem1 = auxItem1->prox;

        antItem2 = auxItem2->ant;
        proxItem2 = auxItem2->prox;

        antItem1->prox = auxItem2;
        antItem2->prox = auxItem1;

        proxItem1->ant = auxItem2;
        proxItem2->ant = auxItem1;

        auxItem1->ant = antItem2;
        auxItem1->prox = proxItem2;

        auxItem2->ant = antItem1;
        auxItem2->prox = proxItem1;
    }
}

void zerar(TipoLista *lista){
    apontador aux = lista->primeiro->prox;
    apontador anterior;
    while(aux != NULL){
        anterior = aux;
        aux = aux->prox;
        free(anterior);
    }
    criarLista(lista);
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

    item.id = 1000;
    inserirFinal(&lista, item);

    imprimir(lista);

    item.id = 11;
    inserir(&lista, item, 10);

    imprimir(lista);

    trocar(&lista, 30, 1);

    imprimir(lista);

    imprimirContrario(lista);

    zerar(&lista);

    imprimir(lista);

    item.id = 1;
    inserirFinal(&lista, item);

    item.id = 2;
    inserirFinal(&lista, item);

    imprimir(lista);

    //removerItem(&lista, 2);

    //imprimir(lista);

    //removerItem(&lista, 30);

    //removerItem(&lista, 200);

    //imprimirItem(lista, 10);

    return 0;

}
