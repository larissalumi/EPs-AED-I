#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alocarMemoria(int totalListas, char **listas, char ***listasOrdenadas) {
    int i, j;

    for (i = 0; i < totalListas; i++) {
        listas[i] = (char *)malloc(21000 * sizeof(char));
        listasOrdenadas[i] = (char **)malloc(1000 * sizeof(char *));

        for (j = 0; j < 1000; j++) {
            listasOrdenadas[i][j] = (char *)malloc(21 * sizeof(char));
        }
    }
}

void liberarMemoria(int totalListas, char **listas, char ***listasOrdenadas) {
    int i, j;

    for (i = 0; i < totalListas; i++) {
        for (j = 0; j < 1000; j++) {
            free(listasOrdenadas[i][j]);
        }

        free(listas[i]);
        free(listasOrdenadas[i]);
    }

    free(listas);
    free(listasOrdenadas);
}

int checarPalavraUnica(int numPalavras, char palavra[21], char **listasOrdenadas) {
    int k;

    for (k = 0; k < numPalavras; k++) {
        if (!strcmp(palavra, listasOrdenadas[k])) {
            return 0;
        }
    }

    return 1;
}

void limparString(int tamanho, char palavra[21]) {
    int i;

    for (i = 0; i < tamanho; i++) {
        palavra[i] = '\0';
    }
}

int compararStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void lerEntradas(int totalListas, char **listas) {
    int i;

    for (i = 0; i < totalListas; i++) {
        scanf(" %[^\n]", listas[i]);
        strcat(listas[i], " ");
    }
}

void exibirListas(int numPalavras, char **listasOrdenadas) {
    int i;

    for (i = 0; i < numPalavras; i++) {
        printf("%s", listasOrdenadas[i]);
        if (i != numPalavras - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    int totalListas, i, j, k, numPalavras, palavraUnica;
    char **listas, palavra[21], ***listasOrdenadas;

    scanf("%d", &totalListas);
    listas = (char **)malloc((size_t)totalListas * sizeof(char *));
    listasOrdenadas = (char ***)malloc((size_t)totalListas * sizeof(char **));

    alocarMemoria(totalListas, listas, listasOrdenadas);

    lerEntradas(totalListas, listas);

    for (i = 0; i < totalListas; i++) {
        numPalavras = 0;
        j = 0;
        palavraUnica = 1;

        for (k = 0; k < (int)strlen(listas[i]); k++) {
            palavra[j] = listas[i][k];

            if (listas[i][k] == ' ') {
                palavra[j] = '\0';

                palavraUnica = checarPalavraUnica(numPalavras, palavra, listasOrdenadas[i]);

                if (palavraUnica) {
                    strcpy(listasOrdenadas[i][numPalavras], palavra);
                    numPalavras++;
                }

                limparString(j, palavra);
                j = -1;
            }

            j++;
        }

        qsort(listasOrdenadas[i], (size_t)numPalavras, sizeof(char *), compararStrings);

        exibirListas(numPalavras, listasOrdenadas[i]);
    }

    liberarMemoria(totalListas, listas, listasOrdenadas);
}
