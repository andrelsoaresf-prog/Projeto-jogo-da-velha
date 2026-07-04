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
    

    else
    if (tabela->M[1][1] == 0){
        tabela->M[1][1] = 4;
       

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


    }
    else{
        aleatorio(tabela);
    }

    desenharTabuleiro(tabela);
}

void aleatorio(Tabuleiro *tabela){
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (tabela->M[x][y] != 0); // Sorteia até achar uma vazia
    
    tabela->M[x][y] = 4;
}