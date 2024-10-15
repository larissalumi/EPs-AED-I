#include <stdio.h>
 
int main() {
    int N, horas, minutos, segundos;
    
    scanf("%d", &N);
    
    minutos = N / 60;
    segundos = N % 60;
    
    horas = minutos / 60;
    minutos %= 60;
    
    printf("%d:%d:%d\n", horas, minutos, segundos);
 
    return 0;
}