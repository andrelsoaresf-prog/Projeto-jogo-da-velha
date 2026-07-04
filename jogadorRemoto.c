#include "jogadorRemoto.h"
#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void aceitarJR(jogadorRemoto *remoto, int porta){
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

void conectaJR(jogadorRemoto *remoto, char *ip, int porta){
    struct sockaddr_in servidor_addr;

    remoto->socketComunicacao = socket(AF_INET, SOCK_STREAM, 0);
    if (remoto->socketComunicacao < 0) {
        perror("Erro ao criar socket do cliente");
        exit(EXIT_FAILURE);
    }

    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_port = htons(porta);

    if (inet_pton(AF_INET, ip, &servidor_addr.sin_addr) <= 0) {
        perror("Endereco IP invalido");
        close(remoto->socketComunicacao);
        exit(EXIT_FAILURE);
    }

    printf("Tentando conectar ao jogador em %s:%d...\n", ip, porta);

    if (connect(remoto->socketComunicacao, (struct sockaddr *)&servidor_addr, sizeof(servidor_addr)) < 0) {
        perror("Erro ao conectar ao adversario");
        close(remoto->socketComunicacao);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao adversario com sucesso!\n");

    remoto->socketServidor = -1;
}

void enviarJogadaJR(jogadorRemoto *remoto, jogada msg){
    int bytes_enviados = send(remoto->socketComunicacao, &msg, sizeof(jogada), 0);
    if (bytes_enviados <= 0) {
        printf("Erro ao enviar jogada para o adversario remoto.\n");
    }
}