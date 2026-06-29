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
    if(tabuleiro[0][0] + tabuleiro[0][1] == 2 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
    }
    else if (tabuleiro[0][1] + tabuleiro[0][2] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    }
    else if (tabuleiro[0][0] + tabuleiro[0][2] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[0][1] = 4;
    }
    else if (tabuleiro[1][0] + tabuleiro[1][1] == 2 && tabuleiro[1][2] ==0){
        tabuleiro[1][2] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[1][2] == 2 && tabuleiro[1][0] == 0){
        tabuleiro[1][0] = 4;
    }
    else if (tabuleiro[1][0] + tabuleiro[1][2] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[1][1] = 4;
    }
    else if (tabuleiro[2][0] + tabuleiro[2][1] == 2 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    }
    else if (tabuleiro[2][1] + tabuleiro[2][2] == 2 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
    }
    else if (tabuleiro[2][0] + tabuleiro[2][2] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[2][1] = 4;
    }
    //regra 1: sequencias horizontais feitas pelo jogador
    else if (tabuleiro[0][0] + tabuleiro[1][0] == 2 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
    }
    else if (tabuleiro[1][0] + tabuleiro[2][0] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    }
    else if (tabuleiro[0][0] + tabuleiro[2][0] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[1][0] = 4;
    }
    else if (tabuleiro[0][1] + tabuleiro[1][1] == 2 && tabuleiro[2][1] == 0){
        tabuleiro[2][1] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[2][1] == 2 && tabuleiro[0][1] == 0){
        tabuleiro[0][1] = 4;
    }
    else if (tabuleiro[0][1] + tabuleiro[2][1] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[1][1] = 4;
    }
    else if (tabuleiro[0][2] + tabuleiro[1][2] == 2 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    }
    else if (tabuleiro[1][2] + tabuleiro[2][2] == 2 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
    }
    else if (tabuleiro[0][2] + tabuleiro[2][2] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[1][2] = 4;
    }
    //regra 1: sequencias verticais feitas pelo jogador
    else
    if(tabuleiro[0][0] + tabuleiro[0][1] == 8 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
    }
    else if (tabuleiro[0][1] + tabuleiro[0][2] == 8 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    }
    else if (tabuleiro[1][0] + tabuleiro[1][1] == 8 && tabuleiro[1][2] ==0){
        tabuleiro[1][2] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[1][2] == 8 && tabuleiro[1][0] == 0){
        tabuleiro[1][0] = 4;
    }
    else if (tabuleiro[2][0] + tabuleiro[2][1] == 8 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    }
    else if (tabuleiro[2][1] + tabuleiro[2][2] == 8 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
    
    }
    //regra 1: sequencias horizontais feitas pela maquina
    else
    if (tabuleiro[0][0] + tabuleiro[1][0] == 8 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
    }
    else if (tabuleiro[1][0] + tabuleiro[2][0] == 8 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    }
    else if (tabuleiro[0][1] + tabuleiro[1][1] == 8 && tabuleiro[2][1] == 0){
        tabuleiro[2][1] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[2][1] == 8 && tabuleiro[0][1] == 0){
        tabuleiro[0][1] = 4;
    }
    else if (tabuleiro[0][2] + tabuleiro[1][2] == 8 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    }
    else if (tabuleiro[1][2] + tabuleiro[2][2] == 8 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
    }
    //regra 1: sequencias verticais feitas pela maquina
    else if (tabuleiro[0][0] + tabuleiro[1][1] == 2 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[2][2] == 2 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    }
    else if (tabuleiro[2][0] + tabuleiro[1][1] == 2 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[0][2] == 2 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
    }

    //regra 1: sequencias diagonais feitas pelo jogador
    else
    if (tabuleiro[0][0] + tabuleiro[1][1] == 8 && tabuleiro[2][2] == 0){
        tabuleiro[2][2] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[2][2] == 8 && tabuleiro[0][0] == 0){
        tabuleiro[0][0] = 4;
    }
    else if (tabuleiro[2][0] + tabuleiro[1][1] == 8 && tabuleiro[0][2] == 0){
        tabuleiro[0][2] = 4;
    }
    else if (tabuleiro[1][1] + tabuleiro[0][2] == 8 && tabuleiro[2][0] == 0){
        tabuleiro[2][0] = 4;
    }
    //regra 1: sequencias diagonais feitas pela maquina
    else
    if (tabuleiro[0][0] + tabuleiro[2][2] == 8 && tabuleiro[1][0] + tabuleiro[2][0] + tabuleiro[2][1] == 0 && tabuleiro[1][1] == 1){
        tabuleiro[2][0] = 4;
    }
    else if (tabuleiro[0][0] + tabuleiro[2][2] == 8 && tabuleiro[0][1] + tabuleiro[0][2] + tabuleiro[1][2] == 0 && tabuleiro[1][1] == 1){
        tabuleiro[0][2] = 4;
    }
    else if (tabuleiro[2][0] + tabuleiro[0][2] == 8 && tabuleiro[2][1] + tabuleiro[2][2] + tabuleiro[1][2] == 0 && tabuleiro[1][1] == 1){
        tabuleiro[2][2] = 4;
    }
    else if (tabuleiro[2][0] + tabuleiro[0][2] == 8 && tabuleiro[1][0] + tabuleiro[0][0] + tabuleiro[0][1] == 0 && tabuleiro[1][1] == 1){
        tabuleiro[0][0] = 4;
    }

    //regra 2: ataque duplo pelos cantos, quando o meio esta ocupado
    else
    if (tabuleiro[0][0] + tabuleiro[2][0] == 8 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 4;
    }
    else if (tabuleiro[0][2] + tabuleiro[2][2] == 8 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 4;
    }
    else if (tabuleiro[0][1] + tabuleiro[1][2] == 8 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 4;
    }
    else if (tabuleiro[2][1] + tabuleiro[1][2] == 8 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 4;
    }
    else if (tabuleiro[1][0] + tabuleiro[2][1] == 8 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 4;
    }
    else if (tabuleiro[1][0] + tabuleiro[0][1] == 8 && tabuleiro[1][1] == 0){
        tabuleiro[1][1] = 4;
    }
    //regra 2: ataque duplo pelo meio

    else
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
    int x = rand() % 3;
    int y = rand() % 3;
    if (tabuleiro[x][y] == 0){
        tabuleiro[x][y] = 4;
    } else{
        aleatorio(tabuleiro);
        //regra 6
    }
}