#include <stdio.h>

/* void inserirNumeros(char sudoku[9][9][1], int posicaoI, int posicaoJ){
    
}  */

void imprimirNumeros(char sudoku[9][9][1]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%c ", sudoku[i][j][0]);
            if(j == 2 || j == 5){
                printf("| ");
            }
        }
        printf("\n");
        if(i == 2 || i == 5){
            printf("---------------------\n");
        }
    }
}

int main(){
    char sudoku[9][9][1];
    int posicaoI, posicaoJ;

    //padrão
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            sudoku[i][j][0] = '*';
        }
    }

    //inserir números
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            scanf("%d", &posicaoI);
            scanf("%d", &posicaoJ);
            scanf("%c", &sudoku[posicaoI][]);
        }
    }

    imprimirNumeros(sudoku);
}