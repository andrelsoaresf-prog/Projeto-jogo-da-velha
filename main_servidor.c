#include <stdio.h>
#include "partida.h"

int main(){
    printf("INICIANDO JOGO DA VELHA\n");
    printf("MODO SERVIDOR (X)\n");
    
    inicia(1, NULL, 8080);
    return 0;
}