#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned u, v, w;
} vertice;

vertice g[200100];
int p[200100];

int pai(int i) {
    if(i != p[i])
        p[i] = pai(p[i]); 
    return p[i];
}

int kruskal(int numArestas) {
    int i, raizU, raizV;
    unsigned int pesoMST = 0;

    for (i = 0; i < numArestas; ++i) {
        raizU = pai(g[i].u);
        raizV = pai(g[i].v);

        if (raizU != raizV) {
            p[raizV] = raizU;
            pesoMST += g[i].w;
        }
    }

    return pesoMST;
}

int compara(const void *a, const void *b) {
    return ((vertice *)a)->w - ((vertice *)b)->w;
}

int main() {
    int numVertices, numArestas;

    while (scanf("%d %d", &numVertices, &numArestas), numVertices && numArestas) {
        int i;
        unsigned int pesoTotal = 0;

        for (i = 0; i < numArestas; ++i) {
            scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);
            pesoTotal += g[i].w;
        }

        qsort(g, numArestas, sizeof(vertice), compara);

        for (i = 0; i < numVertices; ++i)
            p[i] = i;

        printf("%u\n", pesoTotal - kruskal(numArestas));
    }

    return 0;
}
