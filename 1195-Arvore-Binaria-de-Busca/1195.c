#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore{
    int num;
    struct noArvore *esq;
    struct noArvore *dir;
} no;

no* Insere(no *arv, int num){
    if(!arv){
        arv = (no *)malloc(sizeof(no));
        arv->num = num;
        arv->esq = arv->dir = NULL;
    }
    else if (arv->num > num) arv->esq = Insere(arv->esq, num);
    else arv->dir = Insere(arv->dir, num);
    return arv;
}

void Pre(no *arv){
    if(arv){
        printf(" %d", arv->num);
        Pre(arv->esq);
        Pre(arv->dir);
    }
}

void In(no *arv){
    if(arv){
        In(arv->esq);
        printf(" %d", arv->num);
        In(arv->dir);
    }
}

void Post(no *arv){
    if(arv){
        Post(arv->esq);
        Post(arv->dir);
        printf(" %d", arv->num);
    }
}

void Liberar(no *arv){
    if(arv){
        Liberar(arv->esq);
        Liberar(arv->dir);
        free(arv);
        arv = NULL;
    }
}

int main(){
    int num, cont, qtdNos, qtdCasos, caso;

    scanf("%d", &qtdCasos);

    for (caso = 1; caso <= qtdCasos; caso++){
        no *arv = NULL;
        scanf("%d", &qtdNos);

        for (cont = 0; cont < qtdNos; cont++){
            scanf("%d", &num);
            arv = Insere(arv, num);
        }

        printf("Case %d:", caso);
        printf("\nPre.:");
        Pre(arv);
        printf("\nIn..:");
        In(arv);
        printf("\nPost:");
        Post(arv);
        printf("\n\n");
        Liberar(arv);
    }
}
