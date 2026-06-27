#ifndef _partida_H_
#define _partida_H_

typedef struct {
    int rodada, jogador;

} partida;

void configuraJogadores(int *jogador);
void inicia(partida ctrlPartida, int jogador, int x, int y, int **tabuleiro);
void joga(int x, int y, int jogador, int **tabuleiro);

#endif