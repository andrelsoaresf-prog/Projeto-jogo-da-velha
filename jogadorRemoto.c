#include "jogadorRemoto.h"
#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void aceitar(jogadorRemoto *remoto, int porta){
    struct sockaddr_in endereco;
    socklen_t endereco_len = sizeof(endereco);

    remoto->socketServidor = socket(AF_INET, SOCK_STREAM, 0);
    if (remoto->socketServidor < 0) {
        perror("Erro ao criar socket do servidor");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY; 
    endereco.sin_port = htons(porta);

    if (bind(remoto->socketServidor , (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("Erro no bind");
        close(remoto->socketServidor);
     exit(EXIT_FAILURE);
    }

    if (listen(remoto->socketServidor, 1) < 0) {
        perror("Erro no listen");
        close(remoto->socketServidor);
     exit(EXIT_FAILURE);
    }

    printf("Aguardando o adversario conectar na porta %d...\n", porta);

    remoto->socketComunicacao = accept(remoto->socketServidor, (struct sockaddr *)&endereco, &endereco_len);
    if (remoto->socketComunicacao < 0) {
        perror("Erro no accept");
        close(remoto->socketServidor);
        exit(EXIT_FAILURE);
    }

    printf("Adversario remoto conectado com sucesso!\n");
}