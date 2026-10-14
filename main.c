#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "funcoes.h"
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int main ( )
{
    setlocale(LC_ALL,"Portuguese");

    Jogo2048 jogo;
    Jogador jogadores;

    inicializaMatriz (&jogo);

    switchcasemenu (&jogo, &jogadores);

    movimenta (&jogo);

    return 0;
}
