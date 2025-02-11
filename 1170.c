#include <stdio.h>

int main(){
    int dias, N, caso;
    float C;

    scanf("%d", &N);

    for (caso = 0; caso < N; caso++){
        scanf("%f", &C);

        for (dias = 0; C > 1; dias++)
            C /= 2;

        printf("%d dias\n", dias);
        dias = 0;
    }

    return 0;
}