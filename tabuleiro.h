#ifndef _tabuleiro_H_
#define _tabuleiro_H_

typedef struct {
    int x;
    int y;
} jogada;

typedef struct {
    int M[3][3];
} Tabuleiro;

void desenharTabuleiro(Tabuleiro *tabela);
int temVencedor(Tabuleiro *tabela);
void marcarJogada(jogada posicao, int jogador, Tabuleiro *tabela);

#endif