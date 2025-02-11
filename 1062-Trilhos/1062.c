#include <stdlib.h>
#include <stdio.h>

typedef struct pilhaNo{
    int valor;
    struct pilhaNo* abaixo;
} No;

typedef struct pilha{
    int tam;
    struct pilhaNo* topo;
} Pilha;

void push(struct pilha* p, int valor){
    p->tam += 1;
    No* novoTopo = (No *) malloc(sizeof(No));

    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void pop(Pilha* p){
    if(p->tam > 0){
        p->tam -= 1;
        No* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    }
}

int top(Pilha* p){
    return p->topo->valor;
}

int size(Pilha* p){
    return p->tam;
}

int empty(Pilha* p){
    return p->tam == 0;
}

void inicializa(Pilha* p){
    p->tam = 0;
    p->topo = NULL;
}

void destroi(Pilha* p){
    while(!empty(p)){
        pop(p);
    }
}

int main(){
    int N, x;
    struct pilha A, estacao, B;

    while(scanf("%d", &N) != EOF){
        if(!N)  break;

        while(scanf("%d", &x)){
            if(!x){
                printf("\n");
                break;
            }

            inicializa(&A);
            inicializa(&estacao);
            inicializa(&B);

            push(&A, x);
            push(&B, 1);
            for(int i = 2; i <= N; ++i){
                scanf("%d", &x);
                push(&A, x);
                push(&B, i);
            }

            while(!empty(&A) || !empty(&estacao) || !empty(&B)){
                if(!empty(&A) && !empty(&B) && top(&A) == top(&B)){
                    pop(&A);
                    pop(&B);
                }else if(!empty(&estacao) && !empty(&B) && top(&estacao) == top(&B)){
                    pop(&estacao);
                    pop(&B);
                }else if(!empty(&A)){
                    push(&estacao, top(&A));
                    pop(&A);
                }else{
                    break;
                }
            }

            if(empty(&A) && empty(&estacao) && empty(&B)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }

            destroi(&A);
            destroi(&estacao);
            destroi(&B);
        }
    }

    return 0;
}