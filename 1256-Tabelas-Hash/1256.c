#include <stdio.h>
#include <stdlib.h>

int M;

typedef struct Node {
    int valor;
    struct Node *prox;
} No;

int funcaoHash(int chave) {
    return chave % M;
}

void insere(No **tabelaHash, int valor);

int main() {
    int N, C, i, j, num;
    No *lista;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &M, &C);

        No *tabelaHash[M];
        for (j = 0; j < M; j++) {
            tabelaHash[j] = NULL;
        }

        for (j = 0; j < C; j++) {
            scanf("%d", &num);
            insere(tabelaHash, num);
        }

        for (j = 0; j < M; ++j) {
            printf("%d -> ", j);
            for (lista = tabelaHash[j]; lista != NULL; lista = lista->prox) {
                printf("%d -> ", lista->valor);
            }
            printf("\\\n");
        }

        if (i != N - 1) {
            printf("\n");
        }

        // Liberar memória alocada dinamicamente
        for (j = 0; j < M; j++) {
            No *atual = tabelaHash[j];
            while (atual != NULL) {
                No *temp = atual;
                atual = atual->prox;
                free(temp);
            }
        }
    }
    return 0;
}

void insere(No **tabelaHash, int valor) {
    int index = funcaoHash(valor);
    No *noNovo = (No *)malloc(sizeof(No));
    noNovo->valor = valor;
    noNovo->prox = NULL;

    if (tabelaHash[index] == NULL) {
        // Lista vazia, insere o primeiro elemento
        tabelaHash[index] = noNovo;
    } else {
        // Percorre até o final da lista e insere o novo nó
        No *aux = tabelaHash[index];
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = noNovo;
    }
}
