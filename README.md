gcc main_servidor.c partida.c jogadorTeclado.c jogadorRemoto.c tabuleiro.c -o servidor
./servidor

gcc main_cliente.c partida.c jogadorTeclado.c jogadorRemoto.c tabuleiro.c -o cliente
./cliente