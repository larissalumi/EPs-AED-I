#include <stdio.h>
 
int main() {
 
    int numFuncionario, numHoras;
    float recebePorHora, salario;
    
    scanf("%d", &numFuncionario);
    scanf("%d" , &numHoras);
    scanf("%f", &recebePorHora);
    
    salario = numHoras * recebePorHora;
    
    printf("NUMBER = %d\nSALARY = U$ %.2f\n", numFuncionario, salario);
 
    return 0;
}