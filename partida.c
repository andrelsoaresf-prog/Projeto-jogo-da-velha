#include "partida.h"
#include <stdio.h>
#include "tabuleiro.h"
#include "jogadorIA.h"
#include "jogadorTeclado.h"


void configuraJogadores(Jogador *jogador){
    int selecao;
    printf("Qual modo de jogo deseja jogar\n");
    printf("Digite 1 - JOGADOR X JOGADOR\n");
    printf("Digite 2 - JOGADOR X IA\n");
    scanf("%d", &selecao);

    if(selecao == 1){
        printf("\nDefina quem vai jogar primeiro\n");
        printf("Digite 1 para o\n");
        printf("Digite 2 para x\n"); 
        scanf("%d", &selecao);

        if (selecao != 1 && selecao != 2){
            printf("\nNumero invalido! Digite novamente!");
            configuraJogadores(jogador);
        } else {
            jogador->tipo = selecao;
            jogador->modo = 0;
        }
    } else if(selecao == 2){
        jogador->tipo = 1;
        jogador->modo = 2;
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
        if (jogadorAtual.modo == 0){
            if (jogadorAtual.tipo == 1){
                joga(jogadorAtual.tipo, &tabela);
                rodada++;
                jogadorAtual.tipo = 2;
            } else {
                joga(jogadorAtual.tipo, &tabela);
                rodada++;
                jogadorAtual.tipo = 1;
            }
        }
        else if (jogadorAtual.modo == 2){
            if(rodada % 2 == 1){
                regras(&tabela);
                rodada++;
            }
            else{
                joga(jogadorAtual.tipo, &tabela);
                rodada++;
            }
        }
    }
    
    if(rodada == 10 && temVencedor(&tabela) == 0)
        printf("Resultado: Empate! Deu velha!!");

    if(temVencedor(&tabela) == 2 && jogadorAtual.modo == 2)
        printf("Resultado: IA venceu!");

    if(temVencedor(&tabela) == 1 && jogadorAtual.modo == 0)
        printf("Resultado: Jogador 1 venceu!");

    if (temVencedor(&tabela) == 2 && jogadorAtual.modo == 0)
        printf("Resultado: Jogador 2 venceu!");
    
}