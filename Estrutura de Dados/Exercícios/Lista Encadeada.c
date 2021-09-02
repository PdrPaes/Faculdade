#include <locale.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char nome[30];
    float preco;
    int estoque;
}TipoItem;

typedef struct celula_struct*apontador;

typedef struct celula_struct{
    TipoItem item;
    apontador prox;
} celula;

typedef struct{
    apontador primeiro, ultimo;
} TipoLista;

void criarLista(TipoLista *lista){
    lista->primeiro = (apontador)malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

int vazia(TipoLista lista){
    if (lista.primeiro == lista.ultimo){
        return 1;
    }
    else{
        return 0;
    }
}

void inserirProduto(TipoLista *lista, TipoItem item){
    lista->ultimo->prox = (apontador)malloc(sizeof(celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = item;
}

void imprimir(TipoLista lista){
    if (vazia(lista)){
        printf("\n————— Lista Vazia —————\n");
    }else{
        apontador aux = lista.primeiro->prox;
        printf("\n————— Impressao dos produtos —————\n");
        while (aux != NULL){
            printf("\n - Código: %d\n - Nome: %s - Preço de compra: R$ %.2f\n - Quantidade no estoque(Un): %d\n - Valor do estoque: R$ %.2f\n\n", aux->item.codigo, aux->item.nome, aux->item.preco, aux->item.estoque, (aux->item.preco * aux->item.estoque));
            aux = aux->prox;
        }
    }
    printf("\n");
}

int buscar(TipoLista lista, int codigo){
    apontador aux = lista.primeiro->prox;
    while (aux != NULL){
        if (aux->item.codigo == codigo){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void valorEstoque(TipoLista lista){
    float soma;
    float somaFinal;
    apontador aux = lista.primeiro->prox;
    while (aux != NULL){
        soma = (aux->item.preco * aux->item.estoque);
        aux = aux->prox;
        somaFinal += soma;
    }
    printf("\nValor Total - Estoque: R$ %.2f\n", somaFinal);
}

int main(){
    int i = 1;

    TipoLista lista;
    TipoItem item;

    criarLista(&lista);

    while(i != 0){
    printf("\n ——————————————————————————");
    printf("\n 1-> Inserir Produto");
    printf("\n 2-> Detalhes Produto");
    printf("\n 3-> Valor Total - Estoque");
    printf("\n 4-> Editar Produto");
    printf("\n 0-> Finalizar Aplicação");
    printf("\n ——————————————————————————\n—>");
    scanf("%d", &i);

    switch (i){
        case 1:
            printf("\n————— Inserir Produto ————— \n");
            printf("\nInforme o Código do Produto:");
                scanf("%d",&item.codigo);
                fflush(stdin);
            printf("\nInforme o Nome do produto:");
                fgets(item.nome, 30, stdin);
            printf("\nInforme o Preco de compra:\n");
                scanf("%f", &item.preco);
            printf("\nInforme a Quantidade de estoque:\n");
                scanf("%d",&item.estoque);
            inserirProduto(&lista, item);
            break;

        case 2:
            printf("\n————— Detalhes Produto —————\n");
            imprimir(lista);
            break;

        case 3:
            printf("\n————— Valor Total - Estoque —————\n");
            valorEstoque(lista);
            break;

        case 4:
            break;

        case 0:
            printf("\n————— Aplicação Finalizada —————\n");
            break;
    
        default:
            printf("\n————— Entrada Inválida —————\n");
    }
    }
return 0;
}
