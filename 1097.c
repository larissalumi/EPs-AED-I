#include <stdio.h>
 
int main() {
 
    int cont1, cont2, i = 1, j = 7;
    for(cont1 = 0; cont1 < 5; cont1++){
        for(cont2 = 0; cont2 < 3; cont2++){
            printf("I=%d J=%d\n", i, j);
            j--;
        }
        i += 2;
        j += 5;
    }
 
    return 0;
}