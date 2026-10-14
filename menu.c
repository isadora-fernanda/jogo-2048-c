#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "funcoes.h"
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void imprimirmenu ( )
{

    system("cls||clean");
    printf("\n\n");
    printf("\t\t\t\t            222222222222222         000000000             444444444        888888888     \n");
    printf("\t\t\t\t           222222222222222222     00:::::::::00          4444444444      88:::::::::88   \n");
    printf("\t\t\t\t           2222222222222222222  00:::::::::::::00       44444444444    88:::::::::::::88 \n");
    printf("\t\t\t\t           2222222     2222222 0:::::::000:::::::0     444444444444   8::::::88888::::::8\n");
    printf("\t\t\t\t                       2222222 0::::::0   0::::::0    444444 444444   8:::::8     8:::::8\n");
    printf("\t\t\t\t                       2222222 0:::::0     0:::::0   444444  444444   8:::::8     8:::::8\n");
    printf("\t\t\t\t                    222222222  0:::::0     0:::::0  444444   444444    8:::::88888:::::8 \n");
    printf("\t\t\t\t               2222222222222   0:::::0 000 0:::::0 444444444444444444   8:::::::::::::8  \n");
    printf("\t\t\t\t             2222222222222     0:::::0 000 0:::::0 444444444444444444  8:::::88888:::::8 \n");
    printf("\t\t\t\t            22222222222        0:::::0     0:::::0 444444444444444444 8:::::8     8:::::8\n");
    printf("\t\t\t\t           2222222             0:::::0     0:::::0           444444   8:::::8     8:::::8\n");
    printf("\t\t\t\t           2222222             0::::::0   0::::::0           444444   8:::::8     8:::::8\n");
    printf("\t\t\t\t           2222222       22222 0:::::::000:::::::0           444444   8::::::88888::::::8\n");
    printf("\t\t\t\t           2222222222222222222  00:::::::::::::00          4444444444  88:::::::::::::88 \n");
    printf("\t\t\t\t           2222222222222222222    00:::::::::00            4444444444    88:::::::::88   \n");
    printf("\t\t\t\t           2222222222222222222      000000000              4444444444      888888888     \n");

    printf("\nBem-vindo(a) ao 2048!\n");

    printf("\t(1) Instruções\n");
    printf("\t(2) Iniciar o jogo\n");
    printf("\t(3) Ver classificação\n");
    printf("\t(4) Sair\n");
    printf("\nInforme a opção desejada: ");

}

void switchcasemenu (Jogo2048 *jogo, Jogador *jogadores)
{

    int opcaodejogo = 0;
    Jogador Pontuacao[10];
    zerarpontuacao(Pontuacao);
    do
    {
        imprimirmenu( );
        scanf("%d", &opcaodejogo);

        switch (opcaodejogo)
        {
        case 1:
            printf("\n\n\t\tO jogo 2048 tem como objetivo juntar os blocos com movimentos direcionados ");
            printf("para formar um bloco com o valor de 2048.");
            printf(" Entretanto, \n\tfazer isso não é tão fácil.");
            printf(" É necessário usar o raciocínio para movimentar os blocos da melhor maneira possível e ");
            printf("atingir o objetivo \n\tantes que todos os espaços do tabuleiro sejam preenchidos e não haja");
            printf(" mais movimentos. Quando isso acontecer, o jogo acabará e o \n\tjogador perde.");
            printf(" A outra maneira de acabar o jogo é com o sucesso, pois o jogador obteve, em um bloco, o ");
            printf("valor de 2048.\n\n");
            printf("\t- Use as setas do teclado para movimentar os blocos;\n");
            printf("\t- Quando dois blocos de números iguais se chocam, eles viram um só com valor igual a soma dos dois;\n");
            printf("\t- A cada movimento é acrescentado um bloco com valor 2 ou com valor 4 (menor probabilidade);\n");
            printf("\t- Você ganha quando conseguir um bloco no valor de 2048;\n");
            printf("\t- A pontuação do jogador é calculada pelo acúmulo dos blocos que se chocaram.\n\n");
            printf("\nPressione qualquer tecla para continuar. . .\n");
            getch( );
            break;
        case 2:
            lerinformacoes(jogadores);
            movimenta(jogo);
            jogadores->score = jogo->score;
            posicao(jogadores,Pontuacao);
            inicializaMatriz(jogo);
            break;

        case 3:
            imprimirclassificacao(Pontuacao);
            break;

        case 4:
            printf("\nObrigada por jogar!\n");
            exit(9);
            break;

        default:
            printf("\nOpção não encontrada\n");
            printf("\nPressione qualquer tecla para continuar. . .\n");
            break;

        }
    }

    while (opcaodejogo != 9);

}
