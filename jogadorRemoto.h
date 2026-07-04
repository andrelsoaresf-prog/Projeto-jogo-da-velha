#ifndef _jogadorRemoto_H_
#define _jogadorRemoto_H_
#include "tabuleiro.h"

typedef struct {
    int tipo;
    int socketServidor;
    int socketComunicacao;
}jogadorRemoto;


void aceitarJR(jogadorRemoto *remoto, int porta);
void conectaJR(jogadorRemoto *remoto, char *ip, int porta);
void enviarJogadaJR(jogadorRemoto *remoto, jogada msg);
void jogaJR(jogadorRemoto *remoto, Tabuleiro *tabela);

#endif