#include <stdio.h>

int main() {
	unsigned valorA, valorB, carrega, vaium;

	while (1) {
        scanf("%u %u", &valorA, &valorB);
        if (valorA == 0 && valorB == 0) break;

		carrega = 0;
		vaium = 0;

		while (valorA || valorB) {
            if (((valorA % 10) + (valorB % 10) + vaium) > 9) {
                carrega++;
                vaium = 1;
            } else {
                vaium = 0;
            }

            valorA /= 10;
            valorB /= 10;
        }

        if (carrega == 0)
            printf("No carry operation.\n");
        else if (carrega == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", carrega);
    }

    return 0;
}
