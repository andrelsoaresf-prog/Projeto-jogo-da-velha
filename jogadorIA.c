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
