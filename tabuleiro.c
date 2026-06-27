#include "tabuleiro.h"
#include <stdio.h>

void desenharTabuleiro(int **tabuleiro){ 
    printf("\033[2J\033[H");
    printf("\n");

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == 0)
                printf(".");
            else if (tabuleiro[i][j] == 1)
                printf("o");
            else if (tabuleiro[i][j] == 4)
                printf("x");
            
            if (j < 2)
                printf(" | ");
        }
        printf("\n");
        if (i < 2)
            printf("----------\n");
    }
}

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

void marcarJogada(int x, int y, int jogador, int **tabuleiro){

    if (jogador == 1 && tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 1;
    } else if (jogador == 2 && tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 4;
    } else {
        printf("valor indefinido");
    }

    desenharTabuleiro(tabuleiro);
}