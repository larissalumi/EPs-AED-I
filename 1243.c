#include <stdio.h>
#include <string.h>

int main() {
    int totalPalavras, somaTam, tamAtual, i;
    char texto[51];

    while (scanf(" %[^\n]", texto) != EOF) {
        int palavraValida = 1;
        totalPalavras = 0;
        somaTam = 0;
        tamAtual = 0;

        int comp = strlen(texto);

        for (i = 0; i < comp; i++) {
            if ((texto[i] >= '0' && texto[i] <= '9') || (texto[i] == '.' && texto[i + 1] != '\0')) {
                palavraValida = 0;
                tamAtual = 0;
            }

            if (((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z')) && palavraValida) {
                tamAtual++;
            }

            if (texto[i] == ' ' || texto[i + 1] == '\0') {
                if (tamAtual > 0) {
                    somaTam += tamAtual;
                    totalPalavras++;
                }
                tamAtual = 0;
                palavraValida = 1;
            }
        }

        int mediaTam = (totalPalavras > 0) ? somaTam / totalPalavras : 0;

        if (mediaTam <= 3) {
            printf("250\n");
        } else if (mediaTam < 6) {
            printf("500\n");
        } else {
            printf("1000\n");
        }
    }

    return 0;
}
