#include <stdio.h>

int main(){
    int T, degustador[5], i, certo = 0;

    scanf("%d", &T);

    for(i = 0; i < 5; i++){
        scanf("%d", &degustador[i]);
        if (degustador[i] == t)
        certo++;
    }

    printf("%d\n", certo);

    return 0;
}