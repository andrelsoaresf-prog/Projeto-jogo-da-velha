#include "partida.h"
#include <stdio.h>
#include "tabuleiro.h"

void configuraJogadores(int *jogador){
    int selecao;
    printf("\nDefina quem vai jogar primeiro (1 para o, 2 para x): "); scanf("%d", &selecao);

    if (selecao != 1 && selecao != 2){
        printf("\nNumero invalido! Digite novamente!");
        configuraJogadores(jogador);
    } else {
        *jogador = selecao;
    }
}

void inicia(int jogador, int **tabuleiro){
    partida ctrlPartida;
    ctrlPartida.rodada = 1; 
    ctrlPartida.jogador = jogador;
    
    while(temVencedor(tabuleiro) == 0 && ctrlPartida.rodada < 10 && jogador == 1){
        joga(ctrlPartida.jogador, tabuleiro);
        ctrlPartida.rodada++;
        if(ctrlPartida.rodada % 2 == 0){
            ctrlPartida.jogador = 2;
        } else{
            ctrlPartida.jogador = 1;
        }
    }
    while(temVencedor(tabuleiro) == 0 && ctrlPartida.rodada < 10 && jogador == 2){
        joga(ctrlPartida.jogador, tabuleiro);
        ctrlPartida.rodada++;
        if(ctrlPartida.rodada % 2 == 0){
            ctrlPartida.jogador = 1;
        } else{
            ctrlPartida.jogador = 2;
        }
    }

    if(ctrlPartida.rodada == 10 && temVencedor(tabuleiro) == 0){
        printf("Resultado: Empate! Deu velha!!");
    }

    if(temVencedor(tabuleiro) == 1){
        printf("Resultado: Jogador 1 venceu!");
    } 
    
    if(temVencedor(tabuleiro) == 2){
        printf("Resultado: Jogador 2 venceu!");
    }
}

void joga(int jogador, int **tabuleiro){
    int x, y;

    printf("\nDefina a linha da jogada: "); scanf("%d", &x);
    printf("\nDefina a coluna da jogada: "); scanf("%d", &y);
    if (x>=0 && x<3 && y>=0 && y<3 && tabuleiro[x][y]==0){
        marcarJogada(x, y, jogador, tabuleiro);
    } else{
        printf("\nPosicao invalida! Escolha novamente!");
        joga(jogador, tabuleiro);
    }
}