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
    if(vazia(lista)==1){
        printf("A lista esta vazia\n");
    }else{
        printf("Impressao da lista:\n");
        for(i=lista.inicio; i< lista.fim; i++){
            printf("%d - Preco: %.2f - Desconto: %2.f\n", lista.itens[i].id, lista.itens[i].preco, lista.itens[i].desconto);
        }
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
//retorna -1 se não achar o item ou o índice do vetor
int busca(TipoLista lista, int id){
    int i;
    for(i=lista.inicio; i<lista.fim; i++){
        if(lista.itens[i].id==id){
            return i;
        }
    }
    return -1;
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

void altera(TipoLista *lista, int id){
    int posItem = busca(*lista, id);
    if(posItem==-1){
        printf("O id nao esta presente na lista");
    }else{
        printf("Informe o novo id: ");
        scanf("%d", &lista->itens[posItem].id);
        printf("Informe o novo preco: ");
        scanf("%f", &lista->itens[posItem].preco);
        printf("Informe o novo desconto: ");
        scanf("%f", &lista->itens[posItem].desconto);
    }
}

void imprimeItem(TipoLista lista, int id){
    int posItem = busca(lista, id);

    if(posItem==-1){
        printf("O id nao esta presente na lista");
    }else{
        printf("\nImpressao de um item da lista:\n");
        printf("%d - Preco: %.2f - Desconto: %2.f\n", lista.itens[posItem].id, lista.itens[posItem].preco, lista.itens[posItem].desconto);
        printf("\n");
    }
}

void zerarLista(TipoLista *lista){
    criaLista(lista);
}

//copia os itens da lista 2 para o final da lista 1
void unir(TipoLista *lista1, TipoLista lista2){
    int i;
    for(i=lista2.inicio; i<lista2.fim; i++){
        insere(lista1, lista2.itens[i]);
    }
}

//copia os itens da lista 1 para a lista 2
void copiar(TipoLista lista1, TipoLista *lista2){
    int i;
    for(i=lista1.inicio; i<lista1.fim; i++){
        insere(lista2, lista1.itens[i]);
    }
}


int main(){

    TipoLista lista1;
    TipoLista lista2;

    criaLista(&lista1);
    criaLista(&lista2);

    TipoItem item;

    item.id = 10;
    item.preco = 50.0;
    item.desconto = 5.0;
    insere(&lista1, item);

    item.id = 8;
    item.preco = 500.10;
    item.desconto = 10.0;
    insere(&lista1, item);

    item.id = 7;
    item.preco = 1.20;
    item.desconto = 12.0;
    insere(&lista1, item);

    item.id = 400;
    item.preco = 200.50;
    item.desconto = 0.0;
    insere(&lista1, item);

    item.id = 3;
    item.preco = 0.50;
    item.desconto = 35.0;
    insere(&lista1, item);

    imprime(lista1);

    copiar(lista1, &lista2);

    /*
    item.id = 250;
    item.preco = 50.0;
    item.desconto = 5.0;
    insere(&lista2, item);

    item.id = 251;
    item.preco = 500.0;
    item.desconto = 50.0;
    insere(&lista2, item);
    */

    imprime(lista2);

    //unir(&lista1, lista2);

    //imprime(lista1);

    //zerarLista(&lista);

    //imprime(lista);

    //altera(&lista, 3);

    //imprime(lista);

    //imprimeItem(lista, 7);

    //imprimeItem(lista, 14);

    //trocaPosicao(&lista, 1, 3);

    //imprime(lista);

    //removeItem(&lista, 3);

    //imprime(lista);

    /*
    if(busca(lista, 3)!=-1){
        printf("O item esta na lista");
    }else{
        printf("O item NAO esta na lista");
    }*/

    return 0;
}
