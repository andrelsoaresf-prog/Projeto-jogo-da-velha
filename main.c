#include <stdio.h>
#include "tabuleiro.h"
#include "partida.h"
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

    int jogador = 0;
  
    configuraJogadores(&jogador);
    desenharTabuleiro(tabuleiro);
    inicia(jogador, tabuleiro);

    for (int i = 0; i < 3; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
    tabuleiro = NULL;
    
    return 0;

}