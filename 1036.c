#include <stdio.h>
#include <math.h>

int main () {
    double r1, r2, A, B, C, delta;
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    delta = (B * B) - 4.0 * A * C;

    if (delta >= 0 && A != 0) {
        r1 = (-B + sqrt(delta)) / (2.0 * A);
        r2 = (-B - sqrt(delta)) / (2.0 * A);
        
        printf("R1 = %.5lf\nR2 = %.5lf\n", r1, r2);
    }
    else {
        printf("Impossivel calcular\n");
    }
}