#include "jogadorTeclado.h"
#include <stdio.h>
#include "partida.h"
#include "tabuleiro.h"


Jogada joga(int jogador, Tabuleiro *tabela){
    Jogada posicao;

    printf("\nDefina a linha da jogada(1 a 3): "); 
    scanf("%d", &posicao.x);
    printf("\nDefina a coluna da jogada(1 a 3): "); 
    scanf("%d", &posicao.y);
    posicao.x--;
    posicao.y--;
    if (posicao.x>=0 && posicao.x<3 && posicao.y>=0 && posicao.y<3 && tabela->M[posicao.x][posicao.y]==0){
        marcarJogada(posicao, jogador, tabela);
        return posicao;
    } else{
        printf("\nPosicao invalida! Escolha novamente!");
        return joga(jogador, tabela);
    }
}