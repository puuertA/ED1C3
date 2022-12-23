#include <stdio.h>
#include <stdlib.h>
#define MAX 50;

// arvore estatica
typedef struct sNo
{
    int info;
}NO;

typedef struct sArvore
{
    NO arv[MAX];
}Arvore;

// arvore dinamica
typedef struct sNo
{
    int info;
    struct sNo* esq;
    struct sNo* dir;
}NO;

typedef struct sArvore
{
    NO* ptRaiz;
}Arvore;

// arvore estritamente binária
// ou tem dois filhos ou não tem nenhum

// arvore binaria completa
// filhos estão no ultimo ou penultimo nivel

// arvore binaria cheia
// filhos estão no ultimo nivel

//percursos básicos
// pré-ordem raiz-esquerda-direita
// em-ordem esquerda-raiz-direita
// pós-ordem esquerda-direita-raiz

/// ARVORE BINÁRIA DE PESQUISA
// esquerda < nó < direita
