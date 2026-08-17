# ❌⭕ Jogo da Velha em C (com IA Especialista e Sockets)

Um projeto completo de Jogo da Velha desenvolvido em **Linguagem C** como parte da disciplina de **Programação Estruturada** na UFPB.

**Dupla:** Andre Luis Soares Ferreira e Icaro Eduardo de Souza Lucena

O sistema traz três modos de jogo distintos: partida local entre dois humanos, partida contra um sistema especialista (IA baseada em regras) e partida em rede via comunicação de *sockets* (arquitetura Cliente-Servidor).

---

## 📌 Funcionalidades

- **🎮 Modo Humano vs. Humano:** Dois jogadores se enfrentam localmente no mesmo terminal.
- **🤖 Modo Humano vs. IA Especialista:** Desafie um bot com tomada de decisão hierárquica dividida em 6 regras de prioridade (Ataque, Defesa, Dupla Ameaça, Controle do Centro, Cantos Estratégicos e Jogada Aleatória).
- **🌐 Modo Remoto (Sockets TCP/IP):** Jogabilidade em rede utilizando o modelo Cliente-Servidor (`sys/socket.h`), permitindo conexões em rede local ou na mesma máquina.
- **🎨 Interface de Terminal:** Exibição dinâmica do tabuleiro a cada jogada com limpeza de tela e formato padronizado.

---

## 🌳 Organização do Projeto (Branches)

Cada modo de jogo foi desenvolvido em uma branch separada. **A branch `main` não deve ser usada** — a integração dos três módulos ainda está incompleta/misturada. Para compilar qualquer modo, use a branch correspondente:

| Branch | Modo | Arquivos principais |
| --- | --- | --- |
| `Normal` | Humano vs. Humano | `main.c`, `partida.c`, `jogadorTeclado.c`, `tabuleiro.c` |
| `JogadorIA` | Humano vs. IA | `main.c`, `partida.c`, `jogadorTeclado.c`, `jogadorIA.c`, `tabuleiro.c` |
| `JogadorRemoto` | Cliente-Servidor (rede) | `main_servidor.c`, `main_cliente.c`, `partida.c`, `jogadorTeclado.c`, `jogadorRemoto.c`, `tabuleiro.c` |

---

## 🛠️ Regras de Decisão da IA

Disponível na branch `JogadorIA`, o bot toma decisões avaliando sequencialmente as seguintes regras:

1. **Vitória / Bloqueio (R1):** Completa 3 em linha se possível ou bloqueia o oponente caso ele esteja prestes a vencer.
2. **Dupla Ameaça / Fork (R2):** Identifica e executa jogadas que criam duas possibilidades simultâneas de vitória.
3. **Centro (R3):** Ocupa a posição central se estiver livre.
4. **Canto Oposto (R4):** Se o oponente ocupar um canto, joga no canto diametralmente oposto.
5. **Canto Livre (R5):** Marca um dos cantos disponíveis.
6. **Jogada Aleatória (R6):** Escolhe arbitrariamente uma posição válida restante.

> A IA sempre joga primeiro nesse modo — essa ordem é o que garante que ela nunca perde uma partida, apenas vença ou empate.

---

## 📐 Representação Lógica do Tabuleiro

O estado da partida é armazenado em uma matriz 3×3 com os seguintes valores:

| Valor | Representação no Tabuleiro |
| :---: | :---: |
| `0` | Casa Vazia |
| `1` | Marcador `'O'` |
| `4` | Marcador `'X'` |

---

## 🚀 Como Executar

### Pré-requisitos
- Compilador C instalado (`gcc` recomendado).
- Sistema operacional Linux/Unix ou ambiente com suporte à API POSIX Sockets (necessário só para o modo remoto).

### 🎮 Modo Humano vs. Humano (branch `Normal`)
```bash
git checkout Normal
gcc -o jogo_velha main.c tabuleiro.c partida.c jogadorTeclado.c
./jogo_velha
```

### 🤖 Modo Humano vs. IA (branch `JogadorIA`)
```bash
git checkout JogadorIA
gcc -o jogo_velha main.c tabuleiro.c partida.c jogadorTeclado.c jogadorIA.c
./jogo_velha
```

### 🌐 Modo Remoto (branch `JogadorRemoto`)
Precisa de dois terminais — um para o servidor (jogador X, começa a partida) e um para o cliente (jogador O), podendo estar na mesma máquina ou em máquinas diferentes na mesma rede.

```bash
git checkout JogadorRemoto

# Terminal 1 — servidor
gcc -o servidor main_servidor.c partida.c jogadorTeclado.c jogadorRemoto.c tabuleiro.c
./servidor

# Terminal 2 — cliente
gcc -o cliente main_cliente.c partida.c jogadorTeclado.c jogadorRemoto.c tabuleiro.c
./cliente
```

Por padrão o cliente conecta em `127.0.0.1:8080`. Para jogar em máquinas diferentes, ajuste o IP em `main_cliente.c` para o IP da máquina que está rodando o servidor.

---

## 👥 Autores

- Andre Luis Soares Ferreira
- Icaro Eduardo de Souza Lucena

Projeto desenvolvido para a disciplina de Programação Estruturada — UFPB.
