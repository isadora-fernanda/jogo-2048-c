# Jogo 2048 em C

Versão para terminal do jogo **2048**, escrita em C em 2017 como trabalho em dupla da disciplina de Construção de Algoritmos, do curso de Engenharia Eletrônica da UTFPR. Foi um dos meus primeiros programas completos, com menu, regras, pontuação e ranking.

> **English:** terminal version of the 2048 puzzle game, written in C in 2017 as a pair project for the Algorithm Construction course (UTFPR, Electronics Engineering). Features a menu, instructions, score tracking and a high-score ranking.

## Como funciona

O tabuleiro tem 4 × 4 casas. A cada jogada, todos os blocos deslizam para o lado escolhido, e blocos de mesmo valor que se encontram se somam. Depois de cada movimento válido surge um novo bloco, com valor 2 ou, com menor chance, 4. Você vence ao formar um bloco de 2048 e perde quando o tabuleiro enche sem nenhum movimento possível.

```
|   4   ||       ||   8   ||   2   |

|       ||       ||       ||   4   |

|       ||  32   ||   8   ||   2   |

|  32   ||   8   ||  32   ||   4   |

                                SCORE 352
```

**Funcionalidades**
- Menu com instruções, início de partida, classificação e saída
- Movimentação pelas setas do teclado
- Pontuação acumulada a cada fusão de blocos
- Ranking dos melhores resultados da sessão, com nome e data

## Como compilar e jogar

O programa foi feito para **Windows**, porque usa `conio.h` para ler as setas do teclado.

**Pelo Code::Blocks.** Abra o arquivo `Misadora.cbp` e clique em *Build and run*.

**Pelo terminal, com MinGW (gcc).**
```bash
gcc -Wall *.c -o 2048.exe
2048.exe
```

Use as **setas** para mover os blocos.

## Organização do código

| Arquivo | O que faz |
|---|---|
| `main.c` | Ponto de entrada. Inicializa o tabuleiro e abre o menu |
| `funcoes.h` | Estruturas `Jogo2048` e `Jogador`, constantes e protótipos |
| `menu.c` | Menu principal e instruções do jogo |
| `funcoes.c` | Geração de blocos, exibição do tabuleiro, leitura das setas e ranking |
| `movimentos.c` | Lógica dos quatro movimentos (deslizar e somar blocos) |
| `ganhououperdeu.c` | Verificação de vitória e de derrota |

## O que eu faria diferente hoje

Mantive o código como foi entregue em 2017, com só dois ajustes: incluí `conio.h` para compilar em versões atuais do gcc e tirei um nome próprio que estava fixo nas mensagens. Olhando com a experiência de hoje, eu mudaria estes pontos.

- **Limites da matriz.** Algumas comparações acessam uma posição além da borda do tabuleiro (por exemplo `matriz[i][j+1]` na última coluna). Eu verificaria o índice antes de acessar.
- **Gerador aleatório.** `srand(time(NULL))` é chamado a cada novo bloco. O certo é chamar uma vez só, no início do programa.
- **Código repetido.** As quatro direções repetem a mesma lógica. Daria para escrever um único movimento e girar a matriz para as outras direções.
- **Ranking só em memória.** A classificação se perde ao fechar o programa. Eu salvaria em arquivo.
- **Portabilidade.** O uso de `conio.h`, `windows.h` e `system("cls")` prende o jogo ao Windows.

---

Trabalho desenvolvido em dupla. Repositório mantido por **Isadora Fernanda Zappe Schmidt** · [LinkedIn](https://www.linkedin.com/in/isadora-fernanda)
