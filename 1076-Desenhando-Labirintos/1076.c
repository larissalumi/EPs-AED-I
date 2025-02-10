#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int grafo[50][50];
    int numTestes, vInicial, numVertices, numArestas, v1, v2;

    scanf("%d\n", &numTestes);

    for (int testeAtual = 0; testeAtual < numTestes; ++testeAtual) {
        scanf("%d\n", &vInicial);
        scanf("%d %d\n", &numVertices, &numArestas);

        memset(grafo, 0, sizeof(grafo));

        for (int arestaAtual = 0; arestaAtual < numArestas; ++arestaAtual) {
            scanf("%d %d\n", &v1, &v2);
            grafo[v1][v2] = 1;
            grafo[v2][v1] = 1;
        }

        int contadorArestas = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = i; j < numVertices; ++j) {
                if (grafo[i][j] == 1) {
                    ++contadorArestas;
                }
            }
        }
        printf("%d\n", 2 * contadorArestas);
    }
    return 0;
}