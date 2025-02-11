#include <stdio.h>

long long int potencia(int base, int exp) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result *= base;
        }
        base *= base; 
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%lld\n", potencia(3, n));
    return 0;
}
