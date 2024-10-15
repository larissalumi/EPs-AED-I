#include <stdio.h>
 
int main() {
    int N;
    scanf("%d", &N);
    
    float valor[N][3], mediaPonderada[N];
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            scanf("%f", &valor[i][j]);
        }
        mediaPonderada[i] = (2 * valor[i][0] + 3 * valor[i][1] + 5 * valor[i][2]) / 10;
    }
    
    for(int i = 0; i < N; i++){
        printf("%.1f\n", mediaPonderada[i]);
    }
        
    return 0;
}