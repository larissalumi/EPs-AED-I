#include <stdio.h>

int main() {
    int L, i, j;
    char T;
    double matriz[12][12], soma = 0.0;

    scanf("%d %c", &L, &T);

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    for (j = 0; j < 12; j++) {
        soma += matriz[L][j];
    }

    if (T == 'M') {
        soma /= 12.0;
    }

    printf("%.1lf\n", soma);

    return 0;
}
