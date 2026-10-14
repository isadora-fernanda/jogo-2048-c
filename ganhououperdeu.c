#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "funcoes.h"
#include <string.h>
#include <windows.h>
#include <stdlib.h>

int verificar2048 (Jogo2048 *jogo)
{

    int i = 0, j = 0;

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA+1; j++)
        {
            if (jogo->matriz[i][j] == 2048)
            {
                return 1; /* achou */
            }
        }
    }
    return 0;
}

int verificarperda (Jogo2048 *jogo)
{

    int i = 0, j = 0;

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA+1; j++)
        {
            if (jogo->matriz[i][j] == 0)
            {
                return 0; /* continua jogo */
            }
            else
            {
                if (jogo->matriz[i][j] == jogo->matriz[i+1][j] && i < LINHA-1)
                {
                    return 0; /* continua jogo */
                }
                if (jogo->matriz[i][j] == jogo->matriz[i][j+1] && j < COLUNA)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
