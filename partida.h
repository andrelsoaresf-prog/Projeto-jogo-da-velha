#ifndef _partida_H_
#define _partida_H_

#include "jogadorTeclado.h"

typedef struct {
    int rodada, jogador;

} partida;

void configuraJogadores(Jogador *jogador);
void inicia();

#endif