#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//-----------------Fila Normal-----------------
typedef struct itemNormal{
    int idNormal;
    struct itemNormal *proximoNormal;
}normal;
void criaFilaNormal(normal *filaNormal){
    filaNormal->proximoNormal = NULL;
}
int vaziaNormal(normal filaNormal){
    if(filaNormal.proximoNormal == NULL){
        return 1;
    }else{
        return 0;
    }
}
void inserirNormal(normal *filaNormal, int idNormal){
    normal *novoNormal = (normal*) malloc(sizeof(normal));

    if(novoNormal == NULL){
        printf("\nMemória Insuficiente!");
    }else{
        novoNormal->idNormal = idNormal;
        novoNormal->proximoNormal = NULL;
        if(vaziaNormal(*filaNormal)==1){
            filaNormal->proximoNormal = novoNormal;
        }else{
            normal *auxNormal = filaNormal->proximoNormal;
            while(auxNormal->proximoNormal != NULL){
                auxNormal = auxNormal->proximoNormal;
            }
            auxNormal->proximoNormal = novoNormal;
        }
    }
}
normal* removerNormal(normal *filaNormal){
    normal *auxNormal = filaNormal->proximoNormal;
    filaNormal->proximoNormal = auxNormal->proximoNormal;
    return auxNormal;
}
int quantidadeNormal(normal filaNormal){
    int contNormal = 0;
    if(vaziaNormal(filaNormal)==1){
        return 0;
    }else{
        normal *auxNormal = filaNormal.proximoNormal;
        while(auxNormal != NULL){
            contNormal++;
            auxNormal = auxNormal->proximoNormal;
        }
    }
    return contNormal;
}
void imprimirNormal(normal filaNormal){
    if(vaziaNormal(filaNormal)==1){
        printf("A Fila Normal esta vazia!!!");
    }else{
        normal *auxNormal = filaNormal.proximoNormal;
        printf("Fila Normal - ");
        while(auxNormal != NULL){
            printf("<- [%d] ", auxNormal->idNormal);
            auxNormal = auxNormal->proximoNormal;
        }
    }
    printf("\nTotal de elementos na Fila Normal: %d\n\n", quantidadeNormal(filaNormal));
}
//-----------------Fila Prioritária-----------------
typedef struct itemPrioridade{
    int idPrioridade;
    struct itemPrioridade *proximoPrioridade;
}prioridade;
void criaFilaPrioridade(prioridade *filaPrioritaria){
    filaPrioritaria->proximoPrioridade = NULL;
}
int vaziaPrioridade(prioridade filaPrioritaria){
    if(filaPrioritaria.proximoPrioridade == NULL){
        return 1;
    }else{
        return 0;
    }
}
void inserirPrioridade(prioridade *filaPrioritaria, int idPrioridade){
    prioridade *novoPrioridade = (prioridade*) malloc(sizeof(prioridade));

    if(novoPrioridade == NULL){
        printf("\nMemória Insuficiente!");
    }else{
        novoPrioridade->idPrioridade = idPrioridade;
        novoPrioridade->proximoPrioridade = NULL;
        if(vaziaPrioridade(*filaPrioritaria)==1){
            filaPrioritaria->proximoPrioridade = novoPrioridade;
        }else{
            prioridade *auxPrioridade = filaPrioritaria->proximoPrioridade;
            while(auxPrioridade->proximoPrioridade != NULL){
                auxPrioridade = auxPrioridade->proximoPrioridade;
            }
            auxPrioridade->proximoPrioridade = novoPrioridade;
        }
    }
}
prioridade* removerPrioridade(prioridade *filaPrioritaria){
    prioridade *auxPrioridade = filaPrioritaria->proximoPrioridade;
    filaPrioritaria->proximoPrioridade = auxPrioridade->proximoPrioridade;
    return auxPrioridade;
}
int quantidadePrioridade(prioridade filaPrioritaria){
    int contPrioridade = 0;
    if(vaziaPrioridade(filaPrioritaria)==1){
        return 0;
    }else{
        prioridade *auxPrioridade = filaPrioritaria.proximoPrioridade;
        while(auxPrioridade != NULL){
            contPrioridade++;
            auxPrioridade = auxPrioridade->proximoPrioridade;
        }
    }
    return contPrioridade;
}
void imprimirPrioridade(prioridade filaPrioritaria){
    if(vaziaPrioridade(filaPrioritaria)==1){
        printf("A Fila Prioritária está vazia!!!");
    }else{
        prioridade *auxPrioridade = filaPrioritaria.proximoPrioridade;
        printf("Fila Prioridade - ");
        while(auxPrioridade != NULL){
            printf("<- [%d] ", auxPrioridade->idPrioridade);
            auxPrioridade = auxPrioridade->proximoPrioridade;
        }
    }
    printf("\nTotal de elementos na Fila Prioritária: %d\n\n", quantidadePrioridade(filaPrioritaria));
}

void desenfileirar(normal filaNormal, prioridade filaPrioritaria){
    normal*primeiroNormal;
    prioridade*primeiroPrioridade;
    int total = quantidadePrioridade(filaPrioritaria) + quantidadeNormal(filaNormal);
        for( int i = 1; i <= total; i++){
            if(quantidadePrioridade(filaPrioritaria)!=0){
                if (i%3==0){
                    if(quantidadeNormal(filaNormal)!=NULL){
                        primeiroNormal = removerNormal(&filaNormal);
                        printf("\nChamada Fila Normal: %d\n", primeiroNormal->idNormal);
                    } else {
                        primeiroPrioridade = removerPrioridade(&filaPrioritaria);
                        printf("\nChamada Fila Prioritária: %d\n", primeiroPrioridade->idPrioridade);
                    }
                } else {
                    primeiroPrioridade = removerPrioridade(&filaPrioritaria);
                    printf("\nChamada Fila Prioritária: %d\n", primeiroPrioridade->idPrioridade);
                }
            } else {
                primeiroNormal = removerNormal(&filaNormal);
                    printf("\nChamada Fila Normal: %d\n", primeiroNormal->idNormal);
            }
        }
}
int main(){
    normal filaNormal;
    prioridade filaPrioritaria;
    normal*primeiroNormal;
    setlocale(LC_ALL, "Portuguese");

    char dateStr[9];
    char timeStr[9];
    int menu;
    int i=1;
    int idNormal,idPrioritaria;

    criaFilaNormal(&filaNormal);
    criaFilaPrioridade(&filaPrioritaria);

    while (menu != 5){
    system("COLOR 0A");
    _strdate(dateStr);
    _strtime(timeStr);
    printf("\n--------------------------------------------------------------\n");
    printf("Atividade sobre Fila de Prioridade \n");
    system("date /t");
    printf("%s\n",timeStr);
    printf("[1] - Enfileirar na fila normal.                        \n");
    printf("[2] - Enfileirar na fila prioritária.                   \n");
    printf("[3] - Desenfileirar.                                    \n");
    printf("[4] - Imprimir as filas.                                \n");
    printf("[5] - Sair.                                             ");
    printf("\n--------------------------------------------------------------\n");
    printf("Opção desejada: ");
    scanf("%d", &menu);
    printf("\n--------------------------------------------------------------\n");

        switch(menu){
            case 1: //Enfileirar na Fila Normal
                system("cls");
                printf("\n————— Enfileirar na fila normal —————\n");
                printf("\n—> Informe o valor a ser inserido: ");
                scanf("%d",&idNormal);

                inserirNormal(&filaNormal, idNormal);
            break;
            case 2: //Enfileirar na Fila Prioritária
                system("cls");
                printf("\n————— Enfileirar na Fila Prioritária —————\n");
                printf("\n—> Informe o valor a ser inserido: ");
                scanf("%d",&idPrioritaria);

                inserirPrioridade(&filaPrioritaria, idPrioritaria);
            break;
            case 3: //Desenfileirar
                system("cls");
                printf("\n————— Desenfileirar —————");
                desenfileirar(filaNormal,filaPrioritaria);

            break;
            case 4: // Imprimir as Filas
                system("cls");
                printf("\n————— Imprimir as Filas —————");
                printf("\n 1 - Fila Normal: ");
                imprimirNormal(filaNormal);

                printf("\n 2 - Fila Prioritária: ");
                imprimirPrioridade(filaPrioritaria);
            break;
            case 5: //Sair
                system("cls");
                printf("\n————— Aplicação Finalizada —————\n");
            break;
            default:
                system("cls");
                printf("————— Opção não existente no menu! —————");
            break;
        }
    }
return 0;
}
/*
DecolagemPrioritaria *auxDecolagemPrioritaria = filaDecolagemPrioritaria.proximoDecolagemPrioritaria;
    auxDecolagemPrioritaria = auxDecolagemPrioritaria->proximoDecolagemPrioritaria;
    int primeiroDecolagemPrioritaria = auxDecolagemPrioritaria->idDecolagemPrioritaria;

    Decolagem *auxDecolagem = filaDecolagem.proximoDecolagem;
    auxDecolagem = auxDecolagem->proximoDecolagem;
    int primeiroDecolagem = auxDecolagem->idDecolagem;

    AterrissagemPrioritaria *auxAterrissagemPrioritaria = filaAterrissagemPrioritaria.proximoAterrissagemPrioritaria;
    auxAterrissagemPrioritaria = auxAterrissagemPrioritaria->proximoAterrissagemPrioritaria;
    int primeiroAterrissagemPrioritaria = auxAterrissagemPrioritaria->idAterrissagemPrioritaria;

    Aterrissagem *auxAterrissagem = filaAterrissagem.proximoAterrissagem;
    auxAterrissagem = auxAterrissagem->proximoAterrissagem;
    int primeiroAterrissagem = auxAterrissagem->idAterrissagem;*/

    printf("Fila de Decolagem: 6 – 16 – 56 – 88 – 44 – 46 - 28 - 32");
    printf("\nFila de Aterrissagem: 23 – 55 – 27 - 89 - 77 - 15 - 5");
    printf("\nPista 1 - *32(Decolando)");
    printf("\nPista 2 - *5(Aterrissando)");
    printf("\nPista 3 - 13(Aterrissando)");
    printf("\nTotal de aviões atendidos: 22");
    printf("\nTotal de emergências: 2");