#include <stdio.h>
 
int main() {
    int X;
    do{
        scanf("%d", &X);
        for(int i = 1; i <= X; i++){
            printf("%d", i);
            if(i != X){
                printf(" ");
            } else {
                printf("\n");
            }
        }

    } while (X != 0);

    return 0;
}