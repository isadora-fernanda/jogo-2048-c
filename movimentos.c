#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "funcoes.h"
#include <string.h>
#include <windows.h>
#include <stdlib.h>

void Direita (Jogo2048 *jogo)
{
    int i = 0, j = 0, k, Ax [TAMMATRIZ][TAMMATRIZ];

    Igualar(jogo, Ax);

    for (i = 0; i < LINHA; i++)
    {
        for (j = COLUNA; j >= 0; j--)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = j-1; k >= 0; k--)
                {
                    if (jogo->matriz[i][k] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[i][k];
                        jogo->matriz[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < LINHA; i++)
    {
        for (j = COLUNA; j > 0; j--)
        {
            if (jogo->matriz[i][j] == jogo->matriz[i][j-1])
            {
                jogo->matriz[i][j] += jogo->matriz[i][j-1];
                jogo->matriz[i][j-1] = 0;
                jogo->score += jogo->matriz[i][j];
            }
        }
    }

    for (i = 0; i < LINHA; i++)
    {
        for (j = COLUNA; j >= 0; j--)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = j-1; k >= 0; k--)
                {
                    if (jogo->matriz[i][k] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[i][k];
                        jogo->matriz[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    system("cls || clear");

    if (Comparar(jogo, Ax) == 0)
    {
        GerarRandonPrime(jogo);
    }

    printMatriz(jogo);
}

void Esquerda (Jogo2048 *jogo)
{
    int i = 0, j = 0, k, Ax [TAMMATRIZ][TAMMATRIZ];

    Igualar(jogo, Ax);

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j <= COLUNA; j++)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = j+1; k <= COLUNA; k++)
                {
                    if (jogo->matriz[i][k] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[i][k];
                        jogo->matriz[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j <= COLUNA; j++)
        {
            if (jogo->matriz[i][j] == jogo->matriz[i][j+1])
            {
                jogo->matriz[i][j] += jogo->matriz[i][j+1];
                jogo->matriz[i][j+1] = 0;
                jogo->score += jogo->matriz[i][j];
            }
        }
    }

    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j <= COLUNA; j++)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = j+1; k <= COLUNA; k++)
                {
                    if (jogo->matriz[i][k] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[i][k];
                        jogo->matriz[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    system("cls || clear");

    if (Comparar(jogo, Ax) == 0)
    {
        GerarRandonPrime(jogo);
    }

    printMatriz(jogo);
}

void Cima (Jogo2048 *jogo)
{
    int i = 0, j = 0, k, Ax [TAMMATRIZ][TAMMATRIZ];

    Igualar(jogo, Ax);

    for (j = 0; j <= COLUNA; j++)
    {
        for (i = 0; i < LINHA; i++)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = i+1; k < LINHA; k++)
                {
                    if (jogo->matriz[k][j] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[k][j];
                        jogo->matriz[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (j = 0; j <= COLUNA; j++)
    {
        for (i = 0; i < LINHA; i++)
        {
            if (jogo->matriz[i][j] == jogo->matriz[i+1][j])
            {
                jogo->matriz[i][j] += jogo->matriz[i+1][j];
                jogo->matriz[i+1][j] = 0;
                jogo->score += jogo->matriz[i][j];
            }
        }
    }

    for (j = 0; j <= COLUNA; j++)
    {
        for (i = 0; i < LINHA; i++)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = i+1; k < LINHA; k++)
                {
                    if (jogo->matriz[k][j] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[k][j];
                        jogo->matriz[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    system("cls || clear");

    if (Comparar(jogo, Ax) == 0)
    {
        GerarRandonPrime(jogo);
    }

    printMatriz(jogo);
}

void Baixo (Jogo2048 *jogo)
{
    int i = 0, j = 0, k, Ax [TAMMATRIZ][TAMMATRIZ];

    Igualar(jogo, Ax);

    for (j = 0; j <= COLUNA; j++)
    {
        for (i = LINHA-1; i >= 0; i--)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = i-1; k >= 0; k--)
                {
                    if (jogo->matriz[k][j] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[k][j];
                        jogo->matriz[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (j = 0; j <= COLUNA; j++)
    {
        for (i = LINHA-1; i > 0; i--)
        {
            if (jogo->matriz[i][j] == jogo->matriz[i-1][j])
            {
                jogo->matriz[i][j] += jogo->matriz[i-1][j];
                jogo->matriz[i-1][j] = 0;
                jogo->score += jogo->matriz[i][j];
            }
        }
    }

    for (j = 0; j <= COLUNA; j++)
    {
        for (i = LINHA-1; i >= 0; i--)
        {
            if (jogo->matriz[i][j] == 0)
            {
                for (k = i-1; k >= 0; k--)
                {
                    if (jogo->matriz[k][j] != 0)
                    {
                        jogo->matriz[i][j] = jogo->matriz[k][j];
                        jogo->matriz[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    system("cls || clear");

    if (Comparar(jogo, Ax) == 0)
    {
        GerarRandonPrime(jogo);
    }

    printMatriz(jogo);
}
