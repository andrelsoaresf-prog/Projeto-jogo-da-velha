#ifndef _tabuleiro_H_
#define _tabuleiro_H_

typedef struct {
    int x;
    int y;
} Jogada;

typedef struct {
    int M[3][3];
} Tabuleiro;

void desenharTabuleiro(Tabuleiro *tabela);
int temVencedor(Tabuleiro *tabela);
void marcarJogada(Jogada posicao, int jogador, Tabuleiro *tabela);

#endif