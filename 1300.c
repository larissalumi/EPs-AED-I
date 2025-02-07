#include <stdio.h>

int main () {
	int num;
	while (scanf("%d", &num) != EOF)
		printf("%c\n", !(num % 6) ? 'Y' : 'N');

	return 0;
}