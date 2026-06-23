#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//jogador 1 = 0, jogador 2 = 1
//1 = o, 4 = x

int temVencedor(int **tabuleiro){
    int soma = 0;

    int tabuleiro[3][3] = {{1,1,1},{0,0,0},{0,0,0}};

    //soma linhas
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
    //soma colunas
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

    //soma diagonal principal
    for (int i = 0; i < 3; i++){
        for (int j; j < 3; j++){
            if (i == j)
                soma += tabuleiro[i][j];
        }
    }
    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;

    //soma diagonal secundaria
    for (int i = 0; i < 3; i++){
        for (int j = 2; j >= 0; j--){
            if (i + j == 2)
                soma += tabuleiro[i][j];
        }
    }
    if (soma == 3)
            return 1;
        else if (soma == 12)
            return 2;
        else
            soma = 0;
    
    if (soma = 0)
        return 0;
}


void desenharTabuleiro(int **tabuleiro){
    printf("\033[2J\033[H");

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d ", tabuleiro[i][j]);
            if (j < 2)
                printf(" | ");
        }
        printf("\n");
        if (i < 2)
            printf("---------------\n");
    }
}

void marcarJogada(int x, int y, int jogador, int **tabuleiro){

    if (jogador == 0){
        tabuleiro[x][y] = 1;
    } else{
        tabuleiro[x][y] = 4;
    }

    desenharTabuleiro(tabuleiro);
    temVencedor(tabuleiro);
}

int main(){
    int **tabuleiro = malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++){
        tabuleiro[i] = malloc(3 * sizeof(int));
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tabuleiro[i][j] = 0;
        }
    }

    int x, y, jogador;

    printf("quem vai ser o primeiro a jogar? (0 ou 1): ");
    scanf("%d", &jogador);
    printf("digite qual posição do tabuleiro pra colocar (x,y): ");
    scanf("%d, %d", &x ,&y);

    marcarJogada(x, y, jogador, tabuleiro);



    free(tabuleiro);
    **tabuleiro = NULL;
    return 0;
}