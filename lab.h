#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define WAY 1
#define WALL 0

typedef struct tabuleiro{
    int** matriz;
    int tam;
    char* arquivo;
}Tabuleiro;

typedef struct celula{
    int direcoes[4];
}Celula;

typedef struct caminho{
    int linha;
    int coluna;
    struct caminho *anterior;
}Caminho;

int visitado(Caminho* caminho, int linha, int coluna);

void criarTab ();

void imprimirTab (Tabuleiro* tab, Caminho* caminho);

Caminho* criar ();

Caminho* remover (Caminho*caminho);

Caminho * inserir (Caminho* caminho, int linha, int coluna);

void freeTabuleiro (Tabuleiro* tab);
