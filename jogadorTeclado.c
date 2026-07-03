#include "jogadorTeclado.h"
#include <stdio.h>
#include "partida.h"


void joga(int jogador, int **tabuleiro){
    int x, y;

    printf("\nDefina a linha da jogada: "); scanf("%d", &x);
    printf("\nDefina a coluna da jogada: "); scanf("%d", &y);
    if (x>=0 && x<3 && y>=0 && y<3 && tabuleiro[x][y]==0){
        marcarJogada(x, y, jogador, tabuleiro);
    } else{
        printf("\nPosicao invalida! Escolha novamente!");
        joga(jogador, tabuleiro);
    }
}