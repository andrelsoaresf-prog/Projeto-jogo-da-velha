#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


//jogador 1 = 0, jogador 2 = 1
//1 = o, 4 = x


void marcarJogada(int x, int y, int jogador, int **tabuleiro){

    if (jogador == 1 && tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 1;
    } else if (jogador == 2 && tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 4;
    } else {
        printf("valor indefinido");
    }

    desenharTabuleiro(tabuleiro);

    if (temVencedor(tabuleiro) == 1)
        printf("jogador 1 ganhou");
    else if (temVencedor(tabuleiro) == 2)
        printf("jogador 2 ganhou");
}

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
    int x, y, jogador;
    printf("quem vai ser o primeiro a jogar? (1 ou 2): ");
    scanf("%d", &jogador);
    printf("digite qual posição do tabuleiro pra colocar (x,y): ");
    scanf("%d, %d", &x ,&y);
    
    
    marcarJogada(x, y, jogador, tabuleiro);
   

    for (int i = 0; i < 3; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
    tabuleiro = NULL;
    return 0;
}