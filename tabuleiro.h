#ifndef _tabuleiro_H_
#define _tabuleiro_H_

typedef enum {
    VAZIO = 0,
    O = 1,
    X = 4,
    EMPATE = 2,
} valorRep;

typedef struct {
    M[3][3];
    int totalJogadas;
} Tabuleiro;

void desenharTabuleiro(int **tabuleiro);
int temVencedor(int **tabuleiro);
void marcarJogada(int x, int y, int jogador, int **tabuleiro);

#endif