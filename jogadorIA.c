#include <stdio.h>
#include "jogadorIA.h"
#include "tabuleiro.h"
#include <stdlib.h>
#include <time.h>

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
        tabuleiro[1][1] = 4;
        //regra 3

    } 
    else 
    if (tabuleiro[0][0] == 1 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    } else if (tabuleiro[2][2] == 1 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    } else if (tabuleiro[0][2] == 1 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
    } else if (tabuleiro[2][0] == 1 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
        //regra 4

    } 
    else 
    if (tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    } else if (tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    } else if (tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
    } else if (tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
        //regra 5

    }
    else{
        aleatorio(tabuleiro);
    }

    desenharTabuleiro(tabuleiro);
}

void aleatorio(int **tabuleiro){
    srand(time(NULL));
    int x = rand() % 3;
    int y = rand() % 3;
    if (tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 4;
    } else{
        aleatorio(tabuleiro);
        //regra 6
    }
}