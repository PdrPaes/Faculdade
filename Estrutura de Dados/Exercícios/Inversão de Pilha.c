#include <stdio.h>
#include <stdlib.h>

//-------------------Pilha Original
typedef struct item{
    int id;
    struct item *prox;
}node;

void criaPilha(node *pilha){
    pilha->prox = NULL;
}

int vazia(node pilha){
    if(pilha.prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(node *pilha, int id){
    node *novo = (node*) malloc(sizeof(node));

    if(novo==NULL){
        printf("Sem memória disponível");
    }else{
        novo->id = id;
        novo->prox = NULL;
        if(vazia(*pilha)==1){
            pilha->prox = novo;
        }else{
            node *aux = pilha->prox;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
}

node* pop(node *pilha){
    if(vazia(*pilha)==1){
        printf("A pilha esta vazia!");
    }else{
        node *ultimo = pilha->prox;
        node *penultimo = pilha;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;
        return ultimo;
    }
}

void imprimir(node pilha){
    if(vazia(pilha)==1){
        printf("A pilha esta vazia");
    }else{
        node *aux = pilha.prox;
        printf("Elementos da Pilha:\n");
        while(aux != NULL){
            printf("%d\n", aux->id);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void zerar(node *pilha){
    if(vazia(*pilha)==0){
        node *prox, *atual;
        atual = pilha->prox;

        while(atual != NULL){
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
        criaPilha(pilha);
    }
}

//-------------------Pilha Auxiliar
typedef struct itemAuxiliar{
    int idAuxiliar;
    struct item *proxAuxiliar;
}nodeAuxiliar;

void criaPilhaAuxiliar(nodeAuxiliar *pilhaAuxiliar){
    pilhaAuxiliar->proxAuxiliar = NULL;
}

int vaziaAuxiliar(nodeAuxiliar pilhaAuxiliar){
    if(pilhaAuxiliar.proxAuxiliar == NULL){
        return 1;
    }else{
        return 0;
    }
}

void pushAuxiliar(nodeAuxiliar *pilhaAuxiliar, int idAuxiliar){
    nodeAuxiliar *novoAuxiliar = (nodeAuxiliar*) malloc(sizeof(nodeAuxiliar));

    if(novoAuxiliar==NULL){
        printf("Sem memória disponível");
    }else{
        novoAuxiliar->idAuxiliar = idAuxiliar;
        novoAuxiliar->proxAuxiliar = NULL;
        if(vaziaAuxiliar(*pilhaAuxiliar)==1){
            pilhaAuxiliar->proxAuxiliar = novoAuxiliar;
        }else{
            nodeAuxiliar *auxAuxiliar = pilhaAuxiliar->proxAuxiliar;
            while(auxAuxiliar->proxAuxiliar != NULL){
                auxAuxiliar = auxAuxiliar->proxAuxiliar;
            }
            auxAuxiliar->proxAuxiliar = novoAuxiliar;
        }
    }
}

nodeAuxiliar* pop(nodeAuxiliar *pilhaAuxiliar){
    if(vaziaAuxiliar(*pilhaAuxiliar)==1){
        printf("A pilha esta vazia!");
    }else{
        nodeAuxiliar *ultimoAuxiliar = pilhaAuxiliar->proxAuxiliar;
        nodeAuxiliar *penultimoAuxiliar = pilhaAuxiliar;
        while(ultimoAuxiliar->proxAuxiliar != NULL){
            penultimoAuxiliar = ultimoAuxiliar;
            ultimoAuxiliar = ultimoAuxiliar->proxAuxiliar;
        }
        penultimoAuxiliar->proxAuxiliar = NULL;
        return ultimoAuxiliar;
    }
}

void imprimirAuxiliar(nodeAuxiliar pilhaAuxiliar){
    if(vaziaAuxiliar(pilhaAuxiliar)==1){
        printf("A pilha esta vazia");
    }else{
        nodeAuxiliar *auxAuxiliar = pilhaAuxiliar.proxAuxiliar;
        printf("Elementos da Pilha:\n");
        while(auxAuxiliar != NULL){
            printf("%d\n", auxAuxiliar->idAuxiliar);
            auxAuxiliar = auxAuxiliar->proxAuxiliar;
        }
        printf("\n");
    }
}

void zerarAuxiliar(nodeAuxiliar *pilhaAuxiliar){
    if(vaziaAuxiliar(*pilhaAuxiliar)==0){
        nodeAuxiliar *proxAuxiliar, *atualAuxiliar;
        atualAuxiliar = pilhaAuxiliar->proxAuxiliar;

        while(atualAuxiliar != NULL){
            proxAuxiliar = atualAuxiliar->proxAuxiliar;
            free(atualAuxiliar);
            atualAuxiliar = proxAuxiliar;
        }
        criaPilhaAuxiliar(pilhaAuxiliar);
    }
}
//-------------------Função Inverter
void inverterPilhas(){
    for (i = 0; i < tamanho; i++){
        pushAuxiliar(&pilhaAuxiliar, pop(&pilha));
    }
}

int main()
{
    node pilha;

    criaPilha(&pilha);

    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);

    imprimir(pilha);

    node *retirado = pop(&pilha);

    printf("Elemento retirado: %d\n\n", retirado->id);

    zerar(&pilha);

    imprimir(pilha);

    return 0;
}
