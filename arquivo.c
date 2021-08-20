#include "arquivo.h"

int* criarVet(int tam){
    int* V = (int *) malloc (sizeof(int)*tam);
    return V;
}

char* criarVetChar(int tam){
    char* V = (char *) malloc (sizeof(char)*tam);
    return V;
}

void contTAM(Tabuleiro*tab){
    FILE*a;
    char *inic = (char*) malloc(sizeof(char) * 256);
    char *str = (char*) malloc(sizeof(char) * 256);

    printf("Digite o nome do arquivo com extensao .csv: ");
    fscanf(stdin,"%s",inic);

    tab->tam = 0;

    a = fopen(inic, "r");
    while (!feof(a)){
        if (fgets(str, 1024, a))
        {
            (tab->tam)++;
        }
    }
    fclose(a);
    free(str);
    tab->arquivo = inic;
}

void arq(Tabuleiro* tab){
    FILE *a;
    int *num,j, firstElem=0, *vet, posArqLinha, *indiceC, count=0, aux=1;
    char *token;
    char *str;
    criarTab(tab);

    int tam = tab->tam;
    str = criarVetChar((tam*tam)+tam);
    num = criarVet((tam*tam)+tam); vet = criarVet(tam); indiceC = criarVet(tam);

    a = fopen(tab->arquivo, "r");
    int i;
    int posArq = 0;
    while (!feof(a))
    {
        posArqLinha=0;
        //Vetor com a posição dos primeiros elementos no arquivo.
        vet[firstElem] = posArq;
        firstElem++;
        if (fgets(str, 1024, a))
        {
            token = strtok(str, ",");
            while (token != NULL)
            {
                //Conversão de string para inteiro.
                num[posArq] = atoi(token);
                posArq++;
                //Posição de cada elemento em cada linha.
                posArqLinha++;
                token = strtok(NULL, ",");
            }
        }
        //quantos lugares terão um novo caminho.
        indiceC[count] = posArqLinha-1;
        count++;
    }
    fclose(a);


    for(i=0;i<firstElem;i++)
    {
        for(j=0;j<indiceC[i];j++)
        {
            //inserção do caminho no labirinto.
            tab->matriz[i][num[aux]]=WAY;
            aux++;
        }
        aux++;
    }
    free(num); free(token);
}
