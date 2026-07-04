#ifndef _jogadorTeclado_H_
#define _jogadorTeclado_H_

#include "tabuleiro.h"

typedef struct {
    int tipo;
} Jogador;

void joga(int jogador, Tabuleiro *tabela);

#endif