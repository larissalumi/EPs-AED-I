#include <stdio.h>
 
int main() {
 
    float N1, N2, N3, N4, media;
    scanf("%f", &N1);
    scanf("%f", &N2);
    scanf("%f", &N3);
    scanf("%f", &N4);
    
    media = (2 * N1 + 3 * N2 + 4 * N3 + N4) / 10;
    printf("Media: %.1f\n", media);
    
    if(media >= 7.0){
        printf("Aluno aprovado.\n");
    }
    
    else if(media < 5.0){
        printf("Aluno reprovado.\n");
    }
    else{
        printf("Aluno em exame.\n");
        float exame;
        scanf("%f", &exame);
        printf("Nota do exame: %.1f\n", exame);
        
        media = (media + exame) / 2;
        
        if(media >= 5.0){
            printf("Aluno aprovado.\n");
        }
        else{
            printf("Aluno reprovado.\n");
        }
        
        printf("Media final: %.1f\n", media);
    }
    return 0;
}