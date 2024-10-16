#include <stdio.h>
 
int main() {
 
    int X, Y, linhas, cont = 1;
    scanf("%d", &X);
    scanf("%d", &Y);
    linhas = Y / X;

    for(int i = 1; i <= linhas; i++){
        for(int j = 0; j < X; j++){
            printf("%d", cont);
            if(j != X - 1){
                printf(" ");
            }
            cont++;
        }
        printf("\n");
        
    }
 
    return 0;
}