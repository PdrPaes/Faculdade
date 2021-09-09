#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
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
    int contador = 0;
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
//-------------------Função Tamanho
int tamanho(node pilha){
    int contador = 0;
    if(vazia(pilha)== 1) {
        printf("A pilha esta vazia");
    }else {
        node *aux = pilha.prox;
        while( aux != NULL) {
            contador++;
            aux = aux->prox;
        }
        return contador;
    }
}

//-------------------Função Inverter
node inverter(node *pilha){
    int i = tamanho(*pilha);

    node pilhaAuxiliar;
    criaPilhaAuxiliar(&pilhaAuxiliar);

    int j = i;
    do{
        node *retirado = pop(pilha);
        pushAuxiliar(&pilhaAuxiliar, retirado->id);
        j--;
    } while(j > 0);

    return pilhaAuxiliar;
    zerarAuxiliar(&pilhaAuxiliar);
}

//-------------------Função Main
int main(){
    char dateStr[9];
    char timeStr[9];
    int menu;
    setlocale(LC_ALL, "Portuguese");

    node pilha;
    criaPilha(&pilha);

    node pilhaAuxiliar;
    criaPilhaAuxiliar(&pilhaAuxiliar);

    while (menu != 7){
    system("COLOR 0A");
    _strdate(dateStr);
    _strtime(timeStr);
    printf("\n--------------------------------------------------------------\n");
    printf("Atividade sobre Pilha \n");
    system("date /t");
    printf("%s\n",timeStr);
    printf("[1] - Inserir item.\n");
    printf("[2] - Remover item.\n");
    printf("[3] - Imprimir Pilha.\n");
    printf("[4] - Inverter Pilha.\n");
    printf("[5] - Imprimir quantidade de itens na Pilha.\n");
    printf("[6] - Limpar Pilha.\n");
    printf("[7] - Sair.");
    printf("\n--------------------------------------------------------------\n");
    printf("Opção desejada: ");
    scanf("%d", &menu);
    printf("\n--------------------------------------------------------------\n");

        switch(menu){
            case 1: //Inserir item.
                system("cls");
                printf("\n————— Inserir item —————\n");
                printf("\n—> Informe o item a ser inserido: ");
                    int inserir = 0;
                    scanf("%d",&inserir);
                    push(&pilha, inserir);
            break;
            case 2: //Remover item.
                system("cls");
                printf("\n————— Remover item —————\n");
                node *retirado = pop(&pilha);
                printf("Elemento Removido ->%d\n", retirado->id);
                    
            break;
            case 3: //Imprimir Pilha.
                system("cls");
                printf("\n————— Imprimir Pilha —————");
                    imprimir(pilha);

            break;
            case 4: // Inverter Pilha Inversa.
                system("cls");
                printf("\n————— Inverter Pilha —————");
                    pilha = inverter(&pilha);
                    imprimir(pilha);

            break;
            case 5: //Imprimir quantidade de itens na Pilha.
                system("cls");
                printf("\n————— Imprimir quantidade de itens na Pilha —————");
                    int tamanhoPilha = tamanho(pilha);
                    printf("No momento %d itens estão na Pilha.",&tamanhoPilha);

            break;
            case 6: //Limpar Pilha
                system("cls");
                printf("\n————— Limpar Pilha —————\n");
                    zerar(&pilha);
                    printf("\nPilha Limpa.\n");

            break;
            case 7: //Sair
                system("cls");
                printf("\n————— Aplicação Finalizada —————\n");
            default:
                system("cls");
                printf("————— Opção não existente no menu! —————");
            break;
        }
    }
return 0;
}
