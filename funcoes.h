#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define TAMMATRIZ 4
#define LINHA 4
#define COLUNA 3
#define TAMCHAR 30
#define COLOCACAO 9
#define TOP 10

typedef struct
{

    int matriz[TAMMATRIZ][TAMMATRIZ];
    int score;
    char movimento1;
    char movimento2;

} Jogo2048;

typedef struct
{

    char nome[TAMCHAR];
    char nascimento[TAMCHAR];
    char nacionalidade[TAMCHAR];
    char endereco[TAMCHAR];
    char email[TAMCHAR];
    char diajogo[TAMCHAR];
    int score;

} Jogador;

void limpaBufferTeclado ( );
void GerarRandonPrime (Jogo2048 *jogo);
void printMatriz (Jogo2048 *jogo);
void inicializaMatriz (Jogo2048 *jogo);
void movimenta (Jogo2048 *jogo);
int verificar2048 (Jogo2048 *jogo);
int verificarperda (Jogo2048 *jogo);
void Igualar (Jogo2048 *jogo, int Ax[][TAMMATRIZ]);
int Comparar (Jogo2048 *jogo, int Ax[][TAMMATRIZ]);
void Direita (Jogo2048 *jogo);
void Esquerda (Jogo2048 *jogo);
void Cima (Jogo2048 *jogo);
void Baixo (Jogo2048 *jogo);
void imprimirmenu ( );
void switchcasemenu (Jogo2048 *jogo, Jogador *jogadores);
void lerinformacoes (Jogador *jogadores);
void zerarpontuacao (Jogador *jogadores);
void posicao (Jogador *jogadores, Jogador *lugar);
void imprimirclassificacao (Jogador *jogadores);

#endif /* FUNCOES_H_INCLUDED */
