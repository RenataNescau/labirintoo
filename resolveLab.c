#include "resolveLab.h"

Celula verificarCaminhos(int linha, int coluna, Tabuleiro* tab){
    Celula org;
    int i;

    for(i = 0; i < 4; i++){
        org.direcoes[i] = WALL;
    }

    if(linha - 1 >= 0) { org.direcoes[0] = tab->matriz[linha - 1][coluna]; }

    if(coluna + 1 < tab->tam) { org.direcoes[1] = tab->matriz[linha][coluna + 1]; }

    if(linha + 1 < tab->tam) { org.direcoes[2] = tab->matriz[linha + 1][coluna]; }

    if(coluna - 1 >= 0) { org.direcoes[3] = tab->matriz[linha][coluna - 1]; }

    return org;
}

int resolverLab (Tabuleiro* tab, int linha, int coluna, Caminho* caminho){
    imprimirTab(tab, caminho);
    int direcoes[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int i, j = 0, x, y;

    if(tab->matriz[linha][coluna]==WALL){ return 0; }
    caminho=inserir(caminho,linha,coluna);

    Celula org;
    if(linha==tab->tam-1 && coluna==tab->tam-1){
        imprimirTab(tab, caminho);
        free(caminho);
        return 1;
    }

    org = verificarCaminhos(linha, coluna, tab);

    for(i = 0; i < 4; i++){
        x = direcoes[i][0];
        y = direcoes[i][1];
        if(org.direcoes[i] == WAY && !visitado(caminho, linha + x, coluna + y)) {
            j = resolverLab(tab, linha + x, coluna + y, caminho);
        }
        if (j == 1) { free(caminho); return 1; }
    }

    caminho=remover(caminho);
    return 0;
}
