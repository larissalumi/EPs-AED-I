#include <stdio.h>

int main () {
    int N, i, n1=1, n2=1, sum;
    scanf("%d", &N);
    
    if(N == 1){
        printf("0\n");
    }
    else if(N == 2){
        printf("0 1\n");
    }
    else if(N < 46){
        printf("0 1 1 ");
        for (i=4; i<=N; i++) {
            sum=n1+n2;
            n1 = n2;
            n2 = sum;
            printf("%d ", n2);
        }
        printf("\n");
    }

    return 0;
}