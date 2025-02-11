#include <stdio.h>

int main(){
    int X, Y, troca, soma = 0, i;

    scanf("%d", &X);
    scanf("%d", &Y);

    if(Y < X){
        troca = X;
        X = Y;
        Y = troca;
    }

    for (i = X + 1; i < Y; i++){
        if(i % 2 != 0){
            if(i > 0){
                soma += i;
            } else{
                soma -= i * (-1);
            }
        }
    }
    printf("%d\n", soma);

    return 0;
}