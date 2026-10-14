#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "funcoes.h"
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void limpaBufferTeclado ( )
{
    int ch;

    do
        ch = fgetc(stdin);

    while (ch != EOF && ch != '\n' );
}

void GerarRandonPrime (Jogo2048 *jogo)
{
    int d = 0, i = 0, j = 0, a, b, c;

    for (i = 0; i < LINHA; i++)
        for (j = 0; j <= COLUNA; j++)
            if (jogo->matriz[i][j] == 0)
                d = 1;

    srand(time(NULL));

    if (d == 1)
    {
        while (1)
        {
            a = rand( )%4;
            b = rand( )%4;
            c = rand( )%5;

            if (jogo->matriz[a][b] == 0)
            {
                if (c == 3)
                {
                    jogo->matriz[a][b] = 4;
                }
                else
                {
                    jogo->matriz[a][b] = 2;
                }
                break;
            }
        }
    }
}

void printMatriz (Jogo2048 *jogo)
{
    int i = 0, j = 0;
    system("cls||clear");
    for (i = 0; i < LINHA; i++)
    {
        printf("\n\n\n\n");
        printf("\t\t");

        for (j = 0; j < COLUNA+1; j++)
            printf("|\t%1.d\t|", jogo->matriz[i][j]);

        printf("\n");
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tSCORE %i", jogo->score);
}

void inicializaMatriz (Jogo2048 *jogo)
{
    int i = 0, j = 0;
    jogo->score = 0;

    jogo->movimento2 = 1;

    for (i = 0; i < LINHA; i++)
        for (j = 0; j < COLUNA+1; j++)
            jogo->matriz[i][j] = 0;

    GerarRandonPrime(jogo);
}

void movimenta (Jogo2048 *jogo)
{
    int i, k;

    while (jogo->movimento2 != 0)
    {

        if (verificar2048(jogo) == 1)
        {
            printMatriz(jogo);

            printf("\nPARABÉNS, VOCÊ VENCEU!\n");
            system("pause");
            return;
        }
        if (verificarperda(jogo) == 1)
        {
            printMatriz(jogo);

            printf("\nQUE PENA, VOCÊ PERDEU!\n");
            system("pause");
            return;
        }

        printMatriz(jogo);
        jogo->movimento1 = getch( );
        jogo->movimento2 = getch( );
        i = jogo->movimento1;
        k = jogo->movimento2;

        if (i == -32)
        {
            switch (k)
            {
            case 75:
                Esquerda(jogo);
                break;

            case 80:
                Baixo(jogo);
                break;

            case 77:
                Direita(jogo);
                break;

            case 72:
                Cima(jogo);
                break;
            }
        }
    }
}

void Igualar (Jogo2048 *jogo, int Ax[][TAMMATRIZ])
{
    int i, j;

    for (j = 0; j < LINHA; j++)
    {
        for (i = 0; i < COLUNA+1; i++)
        {
            Ax[i][j] = jogo->matriz[i][j];
        }
    }
}

int Comparar (Jogo2048 *jogo, int Ax[][TAMMATRIZ])
{
    int i, j;

    for (j = 0; j < LINHA; j++)
    {
        for (i = 0; i < COLUNA+1; i++)
        {
            if (Ax[i][j] != jogo->matriz[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void lerinformacoes (Jogador *jogadores)
{

    printf("\nInforme seu nome: ");
    setbuf(stdin,NULL);
    fgets(jogadores->nome, TAMCHAR, stdin);

    printf("\nInforme a data de nascimento: ");
    setbuf(stdin,NULL);
    fgets(jogadores->nascimento, TAMCHAR, stdin);

    printf("\nInforme sua nacionalidade: ");
    setbuf(stdin,NULL);
    fgets(jogadores->nacionalidade, TAMCHAR, stdin);

    printf("\nInforme seu endereço (cidade, estado, país): ");
    setbuf(stdin,NULL);
    fgets(jogadores->endereco, TAMCHAR, stdin);

    printf("\nInforme seu email: ");
    setbuf(stdin,NULL);
    fgets(jogadores->email, TAMCHAR, stdin);

    printf("\nInforme a data de hoje: ");
    setbuf(stdin,NULL);
    fgets(jogadores->diajogo, TAMCHAR, stdin);
}

void zerarpontuacao (Jogador *jogadores)
{

    int i = 0;

    for (i = 0; i < TOP; i++)
    {
        jogadores[i].score = 0;
        jogadores[i].nome[0] = '\0';
        jogadores[i].diajogo[0] = '\0';
    }
}

void posicao (Jogador *jogadores, Jogador *lugar)
{

    int i = 0, numeroax = 0;
    char vetorax[TAMCHAR];


    if (lugar[COLOCACAO].score < jogadores->score)
    {
        lugar[COLOCACAO].score = jogadores->score;
        strcpy(lugar[COLOCACAO].nome, jogadores->nome);
        strcpy(lugar[COLOCACAO].diajogo, jogadores->diajogo);
    }

    for (i = COLOCACAO; i > 0; i--)
    {
        if (lugar[i].score >lugar[i-1].score)
        {
            numeroax = lugar[i-1].score;
            lugar[i-1].score = lugar[i].score;
            lugar[i].score = numeroax;

            strcpy(vetorax, lugar[i-1].nome);
            strcpy(lugar[i-1].nome, lugar[i].nome);
            strcpy(lugar[i].nome, vetorax);

            strcpy(vetorax, lugar[i-1].diajogo);
            strcpy(lugar[i-1].diajogo, lugar[i].diajogo);
            strcpy(lugar[i].diajogo, vetorax);
        }
    }
}

void imprimirclassificacao (Jogador *jogadores)
{

    int i = 0;

    system("cls||clear");

    printf("\n\t\tNOME\t\t\t\t\t\t\tPONTUAÇÃO\t\t\t\t\t\t\tDATA\n");
    for (i = 0; i < COLOCACAO; i++)
    {
        printf("\n\t\t%s\t\t\t\t\t\t\t\t\t\t%d\t\t\t\t\t\t\t%s\n", jogadores[i].nome, jogadores[i].score, jogadores[i].diajogo);
    }
    system("pause");
}
