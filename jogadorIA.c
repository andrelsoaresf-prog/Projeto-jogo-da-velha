#include <stdio.h>
#include "jogadorIA.h"

void selecionarModo(int *selecionar){
    int opcao;
    printf("Digite 1 para jodar Jogador x Jogador\n");
    printf("Digite 2 para jogar contra contra IA\n");
    scanf("%d", &opcao);
    if (opcao != 1 && opcao != 2){
        printf("valor inválido");
        selecionarModo(selecionar);
    }
    else{
        *selecionar = opcao;
    }
}

void regras(int **tabuleiro){
    if (tabuleiro[1][1] == 0){
        tabuleiro[1][1] == 4;
        //regra 3
    } 

    if (tabuleiro[0][0] == 1){
        tabuleiro[2][2] = 4;

    } else if (tabuleiro[2][2] == 1){
        tabuleiro[0][0] = 4 

    } else if (tabuleiro[0][2] == 1){
        tabuleiro[2][0] = 4;

    } else if (tabuleiro[2][0] == 1){
        tabuleiro[0][2] = 4;
        //regra 4
    }
}