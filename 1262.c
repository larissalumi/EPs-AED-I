#include <stdio.h>
#include <string.h>

int main() {
    int limiteProcessos, indice, totalCiclos, processosAtuais;
    char execucao[51];

    while (scanf(" %s", execucao) != EOF) {
        scanf(" %d", &limiteProcessos);

        totalCiclos = 0;
        processosAtuais = 0;
        int tamanho = (int)strlen(execucao);

        for (indice = 0; indice < tamanho; indice++) {
            switch (execucao[indice]) {
                case 'R':
                    processosAtuais++;
                    if (processosAtuais == limiteProcessos) {
                        processosAtuais = 0;
                        totalCiclos++;
                    }
                    break;

                case 'W':
                    totalCiclos++;
                    if (processosAtuais > 0) totalCiclos++;
                    processosAtuais = 0;
                    break;
            }
        }

        if (processosAtuais > 0) totalCiclos++;

        printf("%d\n", totalCiclos);
    }

    return 0;
}
