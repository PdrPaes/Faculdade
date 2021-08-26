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

int vazia(TipoLista lista){
    if(lista.inicio==lista.fim){
        return 1;
    }else{
        return 0;
    }
}

void insere(TipoLista *lista, TipoItem item){
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

void removeItem(TipoLista *lista, int pos){
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

//verificar se um determinado item está na lista
//parâmetro para isso será o ID
int busca(TipoLista lista, int id){
    int i;
    for(i=lista.inicio; i<lista.fim; i++){
        if(lista.itens[i].id==id){
            return 1;
        }
    }
    return 0;
}

//trocar a posição de dois itens da lista
//função vai receber a posição(índice) dos dois itens
void trocaPosicao(TipoLista *lista, int posItem1, int posItem2){
    TipoItem aux;
    if((posItem1<0) || (posItem1>=lista->fim)){
        printf("Posicao do item 1 invalida");
    }else if((posItem2<0) || (posItem2>=lista->fim)){
        printf("Posicao do item 2 invalida");
    }else{
        aux = lista->itens[posItem1];
        lista->itens[posItem1] = lista->itens[posItem2];
        lista->itens[posItem2] = aux;
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

    trocaPosicao(&lista, 1, 3);

    imprime(lista);

    //removeItem(&lista, 3);

    //imprime(lista);

    /*
    if(busca(lista, 500)==1){
        printf("O item esta na lista");
    }else{
        printf("O item NAO esta na lista");
    }*/

    return 0;
}
