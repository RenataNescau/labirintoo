#include "lab.h"

int visitado(Caminho* caminho, int linha, int coluna){
    while(caminho!=NULL){
        if(caminho->linha==linha && caminho->coluna==coluna){
            return 1;
        }
        caminho=caminho->anterior;
    }
    return 0;
}

void criarTab (Tabuleiro* tab){
    int i;
    tab->matriz = (int **) malloc (sizeof(int*) * (tab->tam));
    if(tab->matriz == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    for(i = 0; i < tab->tam; i++){
        (tab->matriz)[i] = (int *) calloc(tab->tam, sizeof(int));
        if((tab->matriz)[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(2);
        }
    }
}

void imprimirTab(Tabuleiro*tab, Caminho* caminho){
    int i,j;
    system("clear");
    for(i=0;i<tab->tam;i++){
        for(j=0;j<tab->tam;j++){
            if(visitado(caminho, i, j)) { printf("X\t"); }
            else if(tab->matriz[i][j] == 1) { printf("\t"); }
            else{ printf("0\t"); }
        }
        printf("\n");
    }
    usleep(100000);
}

Caminho* criar(){
    return NULL;
}

Caminho* remover(Caminho* caminho){
    if(caminho == NULL) { return NULL; }
    Caminho* aux = caminho->anterior;
    free(caminho);
    return aux;
}

Caminho * inserir (Caminho* caminho, int linha, int coluna){
    Caminho*novo = (Caminho*)malloc(sizeof(Caminho));
    novo->anterior = caminho;
    novo->linha = linha;
    novo->coluna = coluna;
    return novo;
}

void freeTabuleiro(Tabuleiro* tab){
    int i;
    for(i = 0; i < tab->tam; i++){
        free((tab->matriz)[i]);
    }
    free(tab->matriz);
    free(tab->arquivo);
    free(tab);
}
