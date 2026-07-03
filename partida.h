#ifndef _partida_H_
#define _partida_H_

typedef struct {
    int rodada, jogador;

} partida;

void configuraJogadores(int *jogador);
void inicia(int jogador, int **tabuleiro);

#endif