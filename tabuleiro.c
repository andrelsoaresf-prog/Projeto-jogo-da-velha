#include "tabuleiro.h"
#include <stdio.h>

void desenharTabuleiro(Tabuleiro *tabela){ 
    printf("\033[2J\033[H");
    printf("\n");

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (tabela->M[i][j] == 0)
                printf(".");
            else if (tabela->M[i][j] == 1)
                printf("o");
            else if (tabela->M[i][j] == 4)
                printf("x");
            
            if (j < 2)
                printf(" | ");
        }
        printf("\n");
        if (i < 2)
            printf("----------\n");
    }
}

int temVencedor(Tabuleiro *tabela){
    int soma = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma += tabela->M[i][j];
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
            soma += tabela->M[j][i];
        }
        if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
        
    }

    for (int i = 0; i < 3; i++){
        soma += tabela->M[i][i];
    }

    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;

    for (int i = 0; i < 3; i++){
        soma += tabela->M[i][2 - i];
    }
    
    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
    
    return 0;
}

void marcarJogada(jogada posicao, int jogador, Tabuleiro *tabela){

    if (jogador == 1 && tabela->M[posicao.x][posicao.y] == 0){
        tabela->M[posicao.x][posicao.y] = 1;
    } else if (jogador == 2 && tabela->M[posicao.x][posicao.y] == 0){
        tabela->M[posicao.x][posicao.y] = 4;
    } else {
        printf("valor indefinido");
    }

    desenharTabuleiro(tabela);
}