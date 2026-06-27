#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>

int main(){
    int **tabuleiro = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++){
        tabuleiro[i] = malloc(3 * sizeof(int));
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tabuleiro[i][j] = 0;
        }
    }
    int x=0, y=0, jogador=0;
  
    configuraJogadores(&jogador);
    partida ctrlPartida = {1, jogador};
    desenharTabuleiro(tabuleiro);
    inicia(ctrlPartida, jogador, x, y, tabuleiro);

    for (int i = 0; i < 3; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
    tabuleiro = NULL;
    
    return 0;

}