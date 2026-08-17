#ifndef _jogadorIA_H_
#define _jogadorIA_H_

#include "tabuleiro.h"

void regras(Tabuleiro *tabela);
void aleatorio(Tabuleiro *tabela);
int regra1(Tabuleiro *tabela, int valor_alvo);
int contar_ameacas(Tabuleiro *tabela);
int regra2(Tabuleiro *tabela);

#endif