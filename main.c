//#include <stdio.h>
//#include <stdlib.h>
//#include "lab.h"
//#include "arquivo.h"
#include "resolveLab.h"

int main () {
    int Resultado;
    Tabuleiro* tab = (Tabuleiro*) malloc(sizeof(Tabuleiro));
    contTAM(tab);
    Caminho * caminho = criar();
    arq(tab);
    Resultado = resolverLab(tab, 0,0,caminho);
    if(Resultado==1){
        printf("Parabens, você chegou no final.\n");
    }
    else{
        printf("O labirinto não pode ser resolvido. Não foi dessa vez :(.\n");
    }
    free(caminho);
    freeTabuleiro(tab);
    return 0;
}
