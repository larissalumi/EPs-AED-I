#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diamante{
    char pedaco[2];
    struct diamante *prox;
} Pilha;

void empilha(Pilha **extracao, char pedaco[2]){
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
    Pilha *atual = *extracao;

    strncpy(nova->pedaco, pedaco, 2);
    nova->pedaco[1] = '\0';
    nova->prox = NULL;

    if (*extracao == NULL) {
        *extracao = nova;
    } else {
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = nova;
    }
}

void desempilha(Pilha **extrair){
    Pilha *atual = *extrair;

    if(*extrair == NULL)
        return;
    
    if(atual->prox == NULL){
        free(atual);

        *extrair = NULL;
        return;
    }

    *extrair = atual->prox;
    free(atual);
}

void limparPilha(Pilha **extracao) {
    Pilha *atual = *extracao;

    if (*extracao == NULL) return;

    if (atual->prox == NULL) {
        free(atual);
        *extracao = NULL;
        return;
    }

    while (atual->prox != NULL) {
        *extracao = atual->prox;
        free(atual);
        atual = *extracao;
    }

    free(atual);
    *extracao = NULL;
}

int main() {
    char caso[1000], peca[2];
    int qtdCasos, cont, diamante;

    scanf("%d", &qtdCasos);

    Pilha *extrai = NULL;

    while(qtdCasos > 0){
        diamante = 0;
        scanf(" %[^\n]", caso);

        for (cont = 0; cont < (int)strlen(caso); cont++){
            if(caso[cont] == '<'){
                peca[0] = caso[cont];
                peca[1] = '\0';
                empilha(&extrai, peca);
            }
            if (caso[cont] == '>' && extrai != NULL){
                desempilha(&extrai);
                diamante++;
            }
        }
        printf("%d\n", diamante);
        limparPilha(&extrai);
        qtdCasos--;
    }
}