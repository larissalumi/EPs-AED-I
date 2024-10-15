#include <stdio.h>
 
int main() {
    double area;
    float raio, pi = 3.14159;
    scanf("%f", &raio);
    
    area = pi * raio * raio;
    
    printf("A=%.4lf\n", area);
    
    return 0;
}