#include <stdio.h>

int main(){
    int N, i;

    scanf("%d", &N);

    for (i = 2; i < 10000; i++){
        if(i % N == 2)
            printf("%d\n", i);
    }
}