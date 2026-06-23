#include <stdio.h>

//jogador 1 = 0, jogador 2 = 1
//1 = o, 4 = x

void desenharTabuleiro(int tabuleiro[3][3]){
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
void marcarJogada(int x, int y, int jogador){
    int tabuleiro[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

    if (jogador == 0){
        tabuleiro[x][y] = 1;
    } else{
        tabuleiro[x][y] = 4;
    }

    desenharTabuleiro(tabuleiro);
}

int main(){
    int x, y, jogador;

    printf("quem vai ser o primeiro a jogar? (0 ou 1): ");
    scanf("%d", &jogador);
    printf("digite qual posição do tabuleiro pra colocar (x,y): ");
    scanf("%d, %d", &x ,&y);

    marcarJogada(x, y, jogador);
    return 0;
}