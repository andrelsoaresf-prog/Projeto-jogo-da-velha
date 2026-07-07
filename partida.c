#include "partida.h"
#include <stdio.h>
#include "tabuleiro.h"
#include "jogadorTeclado.h"
#include "jogadorRemoto.h"

void configuraJogadores(Jogador *jogador, int tipo_selecionado){
        jogador->tipo = tipo_selecionado;
}


void inicia(int servidor, char *ip, int porta){
    Tabuleiro tabela;
    Jogador jogadorAtual;
    jogadorRemoto adversarioRemoto;
    int rodada = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabela.M[i][j] = 0;
        }
    }

    if (servidor){
        configuraJogadores(&jogadorAtual, 2);
        adversarioRemoto.tipo = 1;
        aceitarJR(&adversarioRemoto, porta);
    } else {
        configuraJogadores(&jogadorAtual, 1);
        adversarioRemoto.tipo = 2;
        conectaJR(&adversarioRemoto, ip, porta);
    }

    desenharTabuleiro(&tabela);

    while (temVencedor(&tabela) == 0 && rodada < 10){
        if (servidor) {
            Jogada minha_jogada = joga(jogadorAtual.tipo, &tabela);
            enviarJogadaJR(&adversarioRemoto, minha_jogada);
            rodada++;

            if (temVencedor(&tabela) != 0 || rodada >= 9)
                break;
            
            jogaJR(&adversarioRemoto, &tabela);
            rodada++;

        }else {
            jogaJR(&adversarioRemoto, &tabela);
            rodada++;

            if (temVencedor(&tabela) != 0 || rodada >= 9)
                break;

            Jogada minha_jogada = joga(jogadorAtual.tipo, &tabela);
            enviarJogadaJR(&adversarioRemoto, minha_jogada);
            rodada++;
        }
    }
    
    if(rodada == 10 && temVencedor(&tabela) == 0){
        printf("Resultado: Empate! Deu velha!!");
    }

    if(temVencedor(&tabela) == 1){
        printf("Resultado: Jogador cliente venceu!");
    } 
    
    if(temVencedor(&tabela) == 2){
        printf("Resultado: Jogador servidor venceu!");
    }
}