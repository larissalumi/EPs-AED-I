#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// estrutura 1 a n sorteado = aluno[k]
// estrutura ordenada a a z
void encontraVencedor (char *alunos[], int N, int K) {
    int a, b;
    char *aux;

    for (a = 0; a < N - 1; a++) {
        for (b = 0; b < N - 1 - a; b++) {
            if (strcmp(alunos[b+1], alunos[b]) < 0) {
                aux = alunos[b];
                alunos[b] = alunos[b+1];
                alunos[b+1] = aux;
            }
        }
    }
    printf("%s\n", alunos[K - 1]);
}

int main(){
    int K, N, i;
    scanf("%d %d", &N, &K);

    char *nomes[N];

    for (i = 0; i < N; i++){
        nomes[i] = malloc(21 * sizeof(char));
        scanf("%s", nomes[i]);
    }

    encontraVencedor(nomes, N, K);

    for (i = 0; i < N; i++){
        free(nomes[i]);
    }
    return 0;
}