#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned resp;

typedef struct no{
    char string[100010];
    struct no *esq;
    struct no *dir;
} noArv;

noArv * Push(noArv *arv, char *p){
    if(!arv){
        arv = (noArv *)malloc(sizeof(noArv));
        arv->esq = arv->dir = NULL;
        strcpy(arv->string, p);
        ++resp;
    }
    else if(strcmp(arv->string, p) > 0)
        arv->esq = Push(arv->esq, p);

    else if(strcmp(arv->string, p) < 0)
        arv->dir = Push(arv->dir, p);

    return arv;
}

int main(){
    char string[1000010];

    noArv *arvore = NULL;

    while(scanf("%s", string) != EOF)
        arvore = Push(arvore, string);

    printf("%d\n", resp);

    return 0;
}