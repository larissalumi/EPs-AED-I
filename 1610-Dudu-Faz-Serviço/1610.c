#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int valor;
    struct node *prox;
} no;

typedef struct graph{
    no **adj;
} Grafo;

char vis[30100];

_Bool flag;

Grafo *inicializaGrafo(int tam){
    int i;
    Grafo *grafo = (Grafo *) malloc(sizeof(Grafo));
    grafo->adj = (no **)malloc(tam * sizeof(no *));

    for (i = 0; i < tam; ++i)
        grafo->adj[i] = NULL;

    return grafo;
}

no *criaNo(int valor){
    no *novoNo = (no *)malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    return novoNo;
}

void push(Grafo *grafo, int valor, int val){
    no *aux;
    no *novoNo = criaNo(val);

    if (grafo->adj[valor] == NULL){
        novoNo->prox = grafo->adj[valor];
        grafo->adj[valor] = novoNo;
    } else{
        aux = grafo->adj[valor];
        novoNo->prox = aux;
        grafo->adj[valor] = novoNo;
    }
}

int main(){
    int n, m, i, k, u, v, cont;
    scanf("%d", &k);

    for (cont = 0; cont < k; cont++){
        Grafo *grafo = inicializaGrafo(10100);
        scanf("%d %d", &n, &m);

        for (i = 0; i < m; ++i){
            scanf("%d %d", &u, &v), push(grafo, u, v);
        }
            flag = 0;
        for (i = 0; i < n; ++i){
            if(!vis[i])
                dfs(grafo, i);

            if(flag)
                break;
        }
        printf("%s\n", flag ? "SIM" : "NAO");
        memset(vis, 0, sizeof(vis));
    }

    return 0;
}

void dfs(Grafo *grafo, int valor){
    no *aux;
    vis[valor] = 1;

    if(flag)
        return;

    for (aux = grafo->adj[valor]; aux != NULL; aux = aux->prox){
        int val = aux->valor;
        if(vis[val] == 1){
            flag = 1;
            break;
        }
        else if(vis[val] == 0)
            dfs(grafo, val);
    }

    vis[valor] = 2;
}