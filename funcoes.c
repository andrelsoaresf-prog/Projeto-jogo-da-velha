#include "funcoes.h"
#include <stdio.h>

int temVencedor(int **tabuleiro){
    int soma = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma += tabuleiro[i][j];
        }
        if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
        
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma += tabuleiro[j][i];
        }
        if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
        
    }

    for (int i = 0; i < 3; i++){
        soma += tabuleiro[i][i];
    }
    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;

    for (int i = 0; i < 3; i++){
        soma += tabuleiro[i][2 - i];
    }
    
    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
    
    return 0;
}

void desenharTabuleiro(int **tabuleiro){

    printf("\033[2J\033[H");

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d ", tabuleiro[i][j]);
            if (j < 2)
                printf(" | ");
        }
        printf("\n");
        if (i < 2)
            printf("---------------\n");
    }
}