#ifndef _jogadorRemoto_H_
#define _jogadorRemoto_H_

typedef struct {
    int tipo;
    int socketServidor;
    int socketComunicacao;
}jogadorRemoto;


void aceitar(jogadorRemoto *remoto, int porta);

#endif