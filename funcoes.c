#include "funcoes.h"
#include <stdio.h>

int temVencedor(int **tabuleiro){
    int soma = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma += tabuleiro[i][j];
        }
        if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
        
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma += tabuleiro[j][i];
        }
        if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
        
    }

    for (int i = 0; i < 3; i++){
        soma += tabuleiro[i][i];
    }

    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;

    for (int i = 0; i < 3; i++){
        soma += tabuleiro[i][2 - i];
    }
    
    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
    
    return 0;
}

void desenharTabuleiro(int **tabuleiro){ 
    printf("\033[2J\033[H");
    printf("\n");

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == 0)
                printf(".");
            else if (tabuleiro[i][j] == 1)
                printf("o");
            else if (tabuleiro[i][j] == 4)
                printf("x");
            
            if (j < 2)
                printf(" | ");
        }
        printf("\n");
        if (i < 2)
            printf("----------\n");
    }
    
}

void marcarJogada(int x, int y, int jogador, int **tabuleiro){

    if (jogador == 1 && tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 1;
    } else if (jogador == 2 && tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 4;
    } else {
        printf("valor indefinido");
    }

    desenharTabuleiro(tabuleiro);
}

void joga(int x, int y, int jogador, int **tabuleiro){

    printf("\nDefina a linha da jogada: "); scanf("%d", &x);
    printf("\nDefina a coluna da jogada: "); scanf("%d", &y);
    if (x>=0 && x<3 && y>=0 && y<3 && tabuleiro[x][y]==0){
        marcarJogada(x, y, jogador, tabuleiro);
    } else{
        printf("\nPosicao invalida! Escolha novamente!");
        joga(x, y, jogador, tabuleiro);
}
}

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

void inicia(partida ctrlPartida, int jogador, int x, int y, int **tabuleiro){
    ctrlPartida.rodada = 1; 
    ctrlPartida.jogador = jogador;
    
    while(temVencedor(tabuleiro) == 0 && ctrlPartida.rodada < 10 && jogador == 1){
        joga(x, y, ctrlPartida.jogador, tabuleiro);
        ctrlPartida.rodada++;
        if(ctrlPartida.rodada % 2 == 0){
            ctrlPartida.jogador = 2;
        } else{
            ctrlPartida.jogador = 1;
        }
    }
    while(temVencedor(tabuleiro) == 0 && ctrlPartida.rodada < 10 && jogador == 2){
        joga(x, y, ctrlPartida.jogador, tabuleiro);
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