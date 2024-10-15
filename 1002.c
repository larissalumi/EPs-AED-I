#include <stdio.h>
 
int main() {
    double area, pi = 3.14159;
    float raio;
    scanf("%f", &raio);
    
    area = pi * raio * raio;
    
    printf("A=%.4lf\n", area);
    
    return 0;
}