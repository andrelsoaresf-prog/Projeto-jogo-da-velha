#ifndef _funcoes_H_
#define _funcoes_H_

int temVencedor(int **tabuleiro);
void desenharTabuleiro(int **tabuleiro);
void marcarJogada(int x, int y, int jogador, int **tabuleiro);
void configuraJogadores(int jogador);
void joga(int x, int y, int jogador, int **tabuleiro);

typedef struct {
    int rodada, jogador;

} partida;
void inicia(partida ctrlPartida, int jogador, int x, int y, int **tabuleiro);


#endif