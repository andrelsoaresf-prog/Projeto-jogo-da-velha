#include "partida.h"
#include <stdio.h>
#include "tabuleiro.h"
#include "jogadorIA.h"
#include "jogadorTeclado.h"


void configuraJogadores(Jogador *jogador){
    int selecao;
    printf("\nDefina quem vai jogar primeiro\n");
    printf("Digite 1 para o\n");
    printf("Digite 2 para x\n"); 
    scanf("%d", &selecao);

    if (selecao != 1 && selecao != 2){
        printf("\nNumero invalido! Digite novamente!");
        configuraJogadores(jogador);
    } else {
        jogador->tipo = selecao;
    }
}

void inicia(int selecionar){
    Tabuleiro tabela;
    Jogador jogadorAtual;
    int rodada = 1;

    configuraJogadores(&jogadorAtual);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            tabela.M[i][j] = 0;
        }}

    desenharTabuleiro(&tabela);

    while (temVencedor(&tabela) == 0 && rodada < 10){
        joga(jogadorAtual.tipo, &tabela);
        rodada++;
        if (jogadorAtual.tipo == 1)
            jogadorAtual.tipo = 2;
        else
            jogadorAtual.tipo = 1;
        
    }
    
    if(rodada == 10 && temVencedor(&tabela) == 0){
        printf("Resultado: Empate! Deu velha!!");
    }

    if(temVencedor(&tabela) == 1){
        printf("Resultado: Jogador 1 venceu!");
    } 
    
    if(temVencedor(&tabela) == 2){
        printf("Resultado: Jogador 2 venceu!");
    }
}