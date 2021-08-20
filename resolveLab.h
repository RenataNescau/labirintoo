#include <stdlib.h>
#include <stdio.h>
#include "arquivo.h"

int visitado(Caminho* caminho, int linha, int coluna);

Celula verificarCaminhos(int linha, int coluna, Tabuleiro* tab);

int resolverLab (Tabuleiro* tab, int linha, int coluna, Caminho* caminho);
