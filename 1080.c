#include <stdio.h>
 
int main() {
    int valores[100], maior = 0, posicao;
    
    for(int i = 0; i < 100; i++){
        scanf("%d", &valores[i]);
        
        if(valores[i] > maior){
            maior = valores[i];
            posicao = i;
        }
    }
    printf("%d\n%d\n", maior, posicao + 1);
 
    return 0;
}