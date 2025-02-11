#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned u, v, w;
} vertice;

vertice g[200100];
int p[2000100];

int pai(int i){
    if(i == p[i])
        return i;
    return pai(p[i]);
}

int kruskal(int c){
    int i, v, u;
    unsigned resp;

    for (i = 0, resp = 0; i < c; ++i){
        v = pai(g[i].v);
        u = pai(g[i].u);

        if(u != v)
            p[v] = p[u], resp += g[i].w;
    }

    return resp;
}

int compara(vertice *a, vertice *b){
    return a->w - b->w;
}

int main(){
    int e, v;

    while(scanf("%d %d", &e, &v), e && v){
        int i;
        unsigned total = 0;
        for (i = 0; i < v; ++i){
            scanf("%d %d %d", &g[i].v, &g[i].v, &g[i].u, &g[i].w), total += g[i].w;
        }

        qsort(g, v, sizeof(vertice), compara);

        for (i = 1; i <= e; ++i)
            p[i] = i;

        printf("%u\n", total - kruskal(v));

        memset(g, 0, sizeof(g));
        memset(p, 0, sizeof(p));
    }

    return 0;
}