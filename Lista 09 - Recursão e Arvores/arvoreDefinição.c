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

// arvore estritamente bin�ria
// ou tem dois filhos ou n�o tem nenhum

// arvore binaria completa
// filhos est�o no ultimo ou penultimo nivel

// arvore binaria cheia
// filhos est�o no ultimo nivel

//percursos b�sicos
// pr�-ordem raiz-esquerda-direita
// em-ordem esquerda-raiz-direita
// p�s-ordem esquerda-direita-raiz

/// ARVORE BIN�RIA DE PESQUISA
// esquerda < n� < direita
