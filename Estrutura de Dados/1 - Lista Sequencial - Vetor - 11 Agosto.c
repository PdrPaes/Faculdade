#include <stdio.h>
#include <stdlib.h>

#define tamanhoLista 10

typedef struct{
    int id;
    float preco;
    float desconto;
}TipoItem;

typedef struct{
    TipoItem itens[tamanhoLista];
    int inicio, fim;
}TipoLista;

void criaLista(TipoLista *lista){
    lista->inicio = 0;
    lista->fim = 0;
}

int vazia (TipoLista lista){
    if(lista.inicio==lista.fim){
        return 1;
    }else{
        return 0;
    }
}

void insere (TipoLista *lista, TipoItem item){
    if(lista->fim > tamanhoLista){
        printf("Lista Cheia");
    }else{
        lista->itens[lista->fim] = item;
        lista->fim++;
    }
}

void imprime(TipoLista lista){
    int i;
    printf("Impressao da lista:\n");
    for(i=lista.inicio; i< lista.fim; i++){
        printf("%d - Preco: %.2f - Desconto: %2.f\n", lista.itens[i].id, lista.itens[i].preco, lista.itens[i].desconto);
    }
    printf("\n");
}

void remove(TipoLista *lista, int pos){
    int i;

    //verifica se a lista está vazia
    if(vazia(*lista)==1){
        printf("A lista esta vazia");
    }else if(pos >= lista->fim){
        printf("Operacao invalida");
    }else{
        for(i=pos;i<lista->fim;i++){
            lista->itens[i] = lista->itens[i+1];
        }
        lista->fim--;
    }

}



int main(){

    TipoLista lista;

    TipoItem item;

    criaLista(&lista);

    item.id = 10;
    item.preco = 50.0;
    item.desconto = 5.0;
    insere(&lista, item);

    item.id = 8;
    item.preco = 500.10;
    item.desconto = 10.0;
    insere(&lista, item);

    item.id = 7;
    item.preco = 1.20;
    item.desconto = 12.0;
    insere(&lista, item);

    item.id = 400;
    item.preco = 200.50;
    item.desconto = 0.0;
    insere(&lista, item);

    item.id = 3;
    item.preco = 0.50;
    item.desconto = 35.0;
    insere(&lista, item);

    imprime(lista);

    remove(&lista, 3);

    imprime(lista);

    return 0;
}
