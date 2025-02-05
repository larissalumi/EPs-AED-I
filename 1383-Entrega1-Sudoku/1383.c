#include <stdio.h>

int verificaLinha(int sudoku[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int existe[10] = {0};
            if(existe[sudoku[i][j]]){
                return 0; // não é solução
            }
            existe[sudoku[i][j]] = 1;
        }
    }
    return 1;
}

int verificaColuna(int sudoku[9][9]){
    for (int j = 0; j < 9; j++){
        int existe[10] = {0};
        for (int i = 0; i < 9; i++){
            if(existe[sudoku[i][j]]){
                return 0; // não é solução
            }
            existe[sudoku[i][j]] = 1;
        }
    }
    return 1;
}

int verificaBloco(int sudoku[9][9]){
    for (int blocoI = 0; blocoI < 9; blocoI += 3){
        for (int blocoJ = 0; blocoJ < 9; blocoJ += 3){
            int existe[10] = {0};
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if (existe[sudoku[blocoI + i][blocoJ + j]]) {
                        return 0; // não é solução
                    }
                    existe[sudoku[blocoI + i][blocoJ + j]] = 1;
                }
            }
        }
    }
    return 1;
}

int main(){
    int numMatrizes, sudoku[9][9];
    scanf("%d", &numMatrizes);
    int verifica[numMatrizes];

    // entrada e verificação
    for (int k = 0; k < numMatrizes; k++){
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++){
                    scanf("%d", &sudoku[i][j]);
            }
        }
        if (verificaLinha(sudoku) && verificaColuna(sudoku) && verificaBloco(sudoku)){
            verifica[k] = 1; // é solução
        } else {
            verifica[k] = 0; // não é solução
        }
    }
    // saída
    for (int k = 0; k < numMatrizes; k++)
    {
        printf("Instancia %d\n", k + 1);
        printf("%s\n\n", verifica[k] == 1 ? "SIM" : "NAO");
    }
}