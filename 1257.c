#include <stdio.h>

int main() {
    int numCasos, numLinhas;
    int linhaIndex, charIndex;
    unsigned int somaLetras;
    char palavra[51];

    scanf("%d", &numCasos);

    for (int caso = 0; caso < numCasos; caso++) {
        scanf("%d", &numLinhas);

        linhaIndex = 0;
        somaLetras = 0;

        for (int linha = 0; linha < numLinhas; linha++) {
            scanf("%s", palavra);

            charIndex = 0;
            int posicaoNaLinha = 0;

            while (palavra[charIndex]) {
                somaLetras += (palavra[charIndex] - 'A') + linhaIndex + posicaoNaLinha;
                charIndex++;
                posicaoNaLinha++;
            }
            linhaIndex++;
        }
        printf("%u\n", somaLetras);
    }

    return 0;
}
