#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char listaAtual[1000], novaLista[1000], amigoIndicado[21];
    char *amigos[100];
    int totalAmigos = 0;

    fgets(listaAtual, sizeof(listaAtual), stdin);
    fgets(novaLista, sizeof(novaLista), stdin);
    fgets(amigoIndicado, sizeof(amigoIndicado), stdin);

    listaAtual[strcspn(listaAtual, "\n")] = '\0';
    novaLista[strcspn(novaLista, "\n")] = '\0';
    amigoIndicado[strcspn(amigoIndicado, "\n")] = '\0';

    char *nomeAmigo = strtok(listaAtual, " ");
    while (nomeAmigo != NULL) {
        amigos[totalAmigos] = malloc((strlen(nomeAmigo) + 1) * sizeof(char));
        strcpy(amigos[totalAmigos], nomeAmigo);
        totalAmigos++;
        nomeAmigo = strtok(NULL, " ");
    }

    int posicaoInsercao = totalAmigos;
    if (strcmp(amigoIndicado, "nao") != 0) {
        for (int i = 0; i < totalAmigos; i++) {
            if (strcmp(amigos[i], amigoIndicado) == 0) {
                posicaoInsercao = i;
                break;
            }
        }
    }

    nomeAmigo = strtok(novaLista, " ");
    while (nomeAmigo != NULL) {
        for (int i = totalAmigos; i > posicaoInsercao; i--) {
            amigos[i] = amigos[i - 1];
        }

        amigos[posicaoInsercao] = malloc((strlen(nomeAmigo) + 1) * sizeof(char));
        strcpy(amigos[posicaoInsercao], nomeAmigo);
        posicaoInsercao++;
        totalAmigos++;

        nomeAmigo = strtok(NULL, " ");
    }

    for (int i = 0; i < totalAmigos; i++) {
        printf("%s", amigos[i]);
        if (i != totalAmigos - 1) printf(" ");
        free(amigos[i]);
    }
    printf("\n");
    return 0;
}