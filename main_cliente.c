#include <stdio.h>
#include "partida.h"

int main(){
    printf("INICIANDO JOGO DA VELHA\n");
    printf("MODO CLIENTE (O)\n");
    
    inicia(0, "127.0.0.1", 8080);
    return 0;
}