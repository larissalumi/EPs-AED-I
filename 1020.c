#include <stdio.h>
 
int main() {
    int idade_dias, ano, mes, dia;
    
    scanf("%d", &idade_dias);
    
    ano = idade_dias / 365;
    mes = (idade_dias - (ano * 365)) / 30;
    dia = (idade_dias - (ano * 365)) - (mes * 30);
    
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
 
    return 0;
}