#include <stdio.h>
#include "jogadorIA.h"
#include "tabuleiro.h"
#include <stdlib.h>
#include <time.h>

void regras(Tabuleiro *tabela){
    if(tabela->M[0][0] + tabela->M[0][1] == 8 && tabela->M[0][2] == 0){
        tabela->M[0][2] = 4;
    }
    else if (tabela->M[0][1] + tabela->M[0][2] == 8 && tabela->M[0][0] == 0){
        tabela->M[0][0] = 4;
    }
    else if (tabela->M[0][0] + tabela->M[0][2] == 8 && tabela->M[0][1] == 0){
        tabela->M[0][1] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[1][1] == 8 && tabela->M[1][2] ==0){
        tabela->M[1][2] = 4;
    }
    else if (tabela->M[1][1] + tabela->M[1][2] == 8 && tabela->M[1][0] == 0){
        tabela->M[1][0] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[1][2] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[2][0] + tabela->M[2][1] == 8 && tabela->M[2][2] == 0){
        tabela->M[2][2] = 4;
    }
    else if (tabela->M[2][1] + tabela->M[2][2] == 8 && tabela->M[2][0] == 0){
        tabela->M[2][0] = 4;
    }
    else if (tabela->M[2][0] + tabela->M[2][2] == 8 && tabela->M[2][1] == 0){
        tabela->M[2][1] = 4;
    }
    //regra 1: sequencias horizontais feitas pela maquina

    else
    if (tabela->M[0][0] + tabela->M[1][0] == 8 && tabela->M[2][0] == 0){
        tabela->M[2][0] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[2][0] == 8 && tabela->M[0][0] == 0){
        tabela->M[0][0] = 4;
    }
    else if (tabela->M[0][0] + tabela->M[2][0] == 8 && tabela->M[1][0] == 0){
        tabela->M[1][0] = 4;
    }
    else if (tabela->M[0][1] + tabela->M[1][1] == 8 && tabela->M[2][1] == 0){
        tabela->M[2][1] = 4;
    }
    else if (tabela->M[1][1] + tabela->M[2][1] == 8 && tabela->M[0][1] == 0){
        tabela->M[0][1] = 4;
    }
    else if (tabela->M[0][1] + tabela->M[2][1] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[0][2] + tabela->M[1][2] == 8 && tabela->M[2][2] == 0){
        tabela->M[2][2] = 4;
    }
    else if (tabela->M[1][2] + tabela->M[2][2] == 8 && tabela->M[0][2] == 0){
        tabela->M[0][2] = 4;
    }
    else if (tabela->M[0][2] + tabela->M[2][2] == 8 && tabela->M[1][2] == 0){
        tabela->M[1][2] = 4;
    }
    //regra 1: sequencias verticais feitas pela maquina

    else
    if (tabela->M[0][0] + tabela->M[1][1] == 8 && tabela->M[2][2] == 0){
        tabela->M[2][2] = 4;
    }
    else if (tabela->M[1][1] + tabela->M[2][2] == 8 && tabela->M[0][0] == 0){
        tabela->M[0][0] = 4;
    }
    else if (tabela->M[2][0] + tabela->M[1][1] == 8 && tabela->M[0][2] == 0){
        tabela->M[0][2] = 4;
    }
    else if (tabela->M[1][1] + tabela->M[0][2] == 8 && tabela->M[2][0] == 0){
        tabela->M[2][0] = 4;
    }
    //regra 1: sequencias diagonais feitas pela maquina
    
    else
    if(tabela->M[0][0] + tabela->M[0][1] == 2 && tabela->M[0][2] == 0){
        tabela->M[0][2] = 4;
    }
    else if (tabela->M[0][1] + tabela->M[0][2] == 2 && tabela->M[0][0] == 0){
        tabela->M[0][0] = 4;
    }
    else if (tabela->M[0][0] + tabela->M[0][2] == 2 && tabela->M[0][1] == 0){
        tabela->M[0][1] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[1][1] == 2 && tabela->M[1][2] ==0){
        tabela->M[1][2] = 4;
    }
    else if (tabela->M[1][1] + tabela->M[1][2] == 2 && tabela->M[1][0] == 0){
        tabela->M[1][0] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[1][2] == 2 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[2][0] + tabela->M[2][1] == 2 && tabela->M[2][2] == 0){
        tabela->M[2][2] = 4;
    }
    else if (tabela->M[2][1] + tabela->M[2][2] == 2 && tabela->M[2][0] == 0){
        tabela->M[2][0] = 4;
    }
    else if (tabela->M[2][0] + tabela->M[2][2] == 2 && tabela->M[2][1] == 0){
        tabela->M[2][1] = 4;
    }
    //regra 1: sequencias horizontais feitas pelo jogador

    else 
    if (tabela->M[0][0] + tabela->M[1][0] == 2 && tabela->M[2][0] == 0){
        tabela->M[2][0] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[2][0] == 2 && tabela->M[0][0] == 0){
        tabela->M[0][0] = 4;
    }
    else if (tabela->M[0][0] + tabela->M[2][0] == 2 && tabela->M[1][0] == 0){
        tabela->M[1][0] = 4;
    }
    else if (tabela->M[0][1] + tabela->M[1][1] == 2 && tabela->M[2][1] == 0){
        tabela->M[2][1] = 4;
    }
    else if (tabela->M[1][1] + tabela->M[2][1] == 2 && tabela->M[0][1] == 0){
        tabela->M[0][1] = 4;
    }
    else if (tabela->M[0][1] + tabela->M[2][1] == 2 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[0][2] + tabela->M[1][2] == 2 && tabela->M[2][2] == 0){
        tabela->M[2][2] = 4;
    }
    else if (tabela->M[1][2] + tabela->M[2][2] == 2 && tabela->M[0][2] == 0){
        tabela->M[0][2] = 4;
    }
    else if (tabela->M[0][2] + tabela->M[2][2] == 2 && tabela->M[1][2] == 0){
        tabela->M[1][2] = 4;
    }
    //regra 1: sequencias verticais feitas pelo jogador

    else
    if (tabela->M[0][0] + tabela->M[2][2] == 8 && tabela->M[1][0] + tabela->M[2][0] + tabela->M[2][1] == 0 && tabela->M[1][1] == 1){
        tabela->M[2][0] = 4;
    }
    else if (tabela->M[0][0] + tabela->M[2][2] == 8 && tabela->M[0][1] + tabela->M[0][2] + tabela->M[1][2] == 0 && tabela->M[1][1] == 1){
        tabela->M[0][2] = 4;
    }
    else if (tabela->M[2][0] + tabela->M[0][2] == 8 && tabela->M[2][1] + tabela->M[2][2] + tabela->M[1][2] == 0 && tabela->M[1][1] == 1){
        tabela->M[2][2] = 4;
    }
    else if (tabela->M[2][0] + tabela->M[0][2] == 8 && tabela->M[1][0] + tabela->M[0][0] + tabela->M[0][1] == 0 && tabela->M[1][1] == 1){
        tabela->M[0][0] = 4;
    }
    //regra 2: ataque duplo pelos cantos, quando o meio esta ocupado

    else
    if (tabela->M[0][0] + tabela->M[2][0] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[0][2] + tabela->M[2][2] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[0][1] + tabela->M[1][2] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[2][1] + tabela->M[1][2] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[2][1] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    else if (tabela->M[1][0] + tabela->M[0][1] == 8 && tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
    }
    //regra 2: ataque duplo pelo meio

    else
    if (tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
        //regra 3

    } 
    else 
    if (tabela->M[0][0] == 1 && tabela->M[2][2] == 0){
        tabela->M[2][2] = 4;
    } else if (tabela->M[2][2] == 1 && tabela->M[0][0] == 0){
        tabela->M[0][0] = 4;
    } else if (tabela->M[0][2] == 1 && tabela->M[2][0] == 0){
        tabela->M[2][0] = 4;
    } else if (tabela->M[2][0] == 1 && tabela->M[0][2] == 0){
        tabela->M[0][2] = 4;
        //regra 4

    } 
    else 
    if (tabela->M[0][0] == 0){
        tabela->M[0][0] = 4;
    } else if (tabela->M[2][2] == 0){
        tabela->M[2][2] = 4;
    } else if (tabela->M[0][2] == 0){
        tabela->M[0][2] = 4;
    } else if (tabela->M[2][0] == 0){
        tabela->M[2][0] = 4;
        //regra 5

    }
    else{
        aleatorio(tabela->M);
    }

    desenharTabuleiro(tabela->M);
}

void aleatorio(Tabuleiro *tabela){
    int x = rand() % 3;
    int y = rand() % 3;
    if (tabela->M[x][y] == 0){
        tabela->M[x][y] = 4;
    } else{
        aleatorio(tabela->M);
        //regra 6
    }
}