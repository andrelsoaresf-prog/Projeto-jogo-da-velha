#include <stdio.h>
#include <time.h>
#include "tabuleiro.h"
#include "partida.h"
#include "jogadorIA.h"
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int **tabuleiro = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++){
        tabuleiro[i] = malloc(3 * sizeof(int));
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tabuleiro[i][j] = 0;
        }
    }

    int jogador = 1, selecionar = 0;

    selecionarModo(&selecionar);
  
    if (selecionar == 1){
        configuraJogadores(&jogador);
        desenharTabuleiro(tabuleiro);
        inicia(jogador, tabuleiro, selecionar);
    } 
    else if (selecionar == 2){
        inicia(jogador, tabuleiro, selecionar);
    }

    for (int i = 0; i < 3; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
    tabuleiro = NULL;
    
    return 0;

}