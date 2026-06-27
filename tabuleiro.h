#ifndef _tabuleiro_H_
#define _tabuleiro_H_

void desenharTabuleiro(int **tabuleiro);
int temVencedor(int **tabuleiro);
void marcarJogada(int x, int y, int jogador, int **tabuleiro);

#endif