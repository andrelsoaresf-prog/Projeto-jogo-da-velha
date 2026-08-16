#include <stdio.h>
#include "jogadorIA.h"
#include "tabuleiro.h"
#include <stdlib.h>
#include <time.h>

int regra1(Tabuleiro *tabela, int valor_alvo) {

    for (int i = 0; i < 3; i++) {
        if (tabela->M[i][0] + tabela->M[i][1] + tabela->M[i][2] == valor_alvo) {
            if (tabela->M[i][0] == 0) { tabela->M[i][0] = 4; return 1; }
            if (tabela->M[i][1] == 0) { tabela->M[i][1] = 4; return 1; }
            if (tabela->M[i][2] == 0) { tabela->M[i][2] = 4; return 1; }
        }
    }

    for (int j = 0; j < 3; j++) {
        if (tabela->M[0][j] + tabela->M[1][j] + tabela->M[2][j] == valor_alvo) {
            if (tabela->M[0][j] == 0) { tabela->M[0][j] = 4; return 1; }
            if (tabela->M[1][j] == 0) { tabela->M[1][j] = 4; return 1; }
            if (tabela->M[2][j] == 0) { tabela->M[2][j] = 4; return 1; }
        }
    }

    if (tabela->M[0][0] + tabela->M[1][1] + tabela->M[2][2] == valor_alvo) {
        if (tabela->M[0][0] == 0) { tabela->M[0][0] = 4; return 1; }
        if (tabela->M[1][1] == 0) { tabela->M[1][1] = 4; return 1; }
        if (tabela->M[2][2] == 0) { tabela->M[2][2] = 4; return 1; }
    }

    if (tabela->M[0][2] + tabela->M[1][1] + tabela->M[2][0] == valor_alvo) {
        if (tabela->M[0][2] == 0) { tabela->M[0][2] = 4; return 1; }
        if (tabela->M[1][1] == 0) { tabela->M[1][1] = 4; return 1; }
        if (tabela->M[2][0] == 0) { tabela->M[2][0] = 4; return 1; }
    }

    return 0; 
}

void regras(Tabuleiro *tabela){
    
    if(regra1(tabela, 8)){
        desenharTabuleiro(tabela);
        return;
    }

    if (tabela->M[1][1] == 0)
        tabela->M[1][1] = 4;
     
    else 
    if (tabela->M[0][0] == 1 && tabela->M[2][2] == 0)
        tabela->M[2][2] = 4;
     else if (tabela->M[2][2] == 1 && tabela->M[0][0] == 0)
        tabela->M[0][0] = 4;
     else if (tabela->M[0][2] == 1 && tabela->M[2][0] == 0)
        tabela->M[2][0] = 4;
     else if (tabela->M[2][0] == 1 && tabela->M[0][2] == 0)
        tabela->M[0][2] = 4;
  

     
    else 
    if (tabela->M[0][0] == 0)
        tabela->M[0][0] = 4;
     else if (tabela->M[2][2] == 0)
        tabela->M[2][2] = 4;
     else if (tabela->M[0][2] == 0)
        tabela->M[0][2] = 4;
     else if (tabela->M[2][0] == 0)
        tabela->M[2][0] = 4;


    
    else
        aleatorio(tabela);
    

    desenharTabuleiro(tabela);
}

void aleatorio(Tabuleiro *tabela){
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    }while (tabela->M[x][y] != 0); 
    
    tabela->M[x][y] = 4;
}