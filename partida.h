#ifndef _partida_H_
#define _partida_H_

#include "jogadorTeclado.h"

void configuraJogadores(Jogador *jogador, int tipo_selecionado);
void inicia(int servidor, char *ip, int porta);

#endif