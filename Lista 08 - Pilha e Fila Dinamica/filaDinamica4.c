/*
12. Escreva um programa em Linguagem C que forneça o maior, o menor e a média
aritmética dos elementos de uma fila.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
} CELULA;

void inicializar(CELULA **fila)
{
    *fila = NULL;
    return *fila;
}

CELULA* getnode()
{
    return (CELULA*)malloc(sizeof(CELULA));
}

void freenode(CELULA **fila)
{
    free(*fila);
}

int vazia(CELULA **fila)
{
    if(*fila == NULL)
        return 1;
    else
        return 0;
}

CELULA* enfileirar(CELULA **fila, int elem)
{
    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q != NULL)
    {
        q->info = elem;
        q->next = NULL;

        if(vazia(fila))
            *fila = q;
        else
        {
            aux = *fila;
            while(aux->next != NULL)
                aux = aux->next;

            aux->next = q;
        }
        return *fila;
    }
    else
    {
        printf("\nERRO na alocacao do no");
        return NULL;
    }
}

CELULA* desenfileirar(CELULA **fila)
{
    CELULA *q;

    q = *fila;
    if(!vazia(fila))
    {
        *fila = q->next;
        freenode(&q);
        return *fila;
    }
    else
    {
        printf("\nERRO: fila vazia!");
        return NULL;
    }
}

void exibeFila(CELULA **fila)
{
    CELULA *aux;
    aux = *fila;

    while(aux != NULL)
    {
        printf("%d\t", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

CELULA* achaMaior(CELULA **fila)
{
    CELULA *aux;
    aux = *fila;
    int maior = 0;
    maior = aux->info;
    while(aux != NULL)
    {
        if(aux->info > maior)
        {
            maior = aux->info;
        }
        aux = aux->next;
    }
    return maior;
}

CELULA* achaMenor(CELULA **fila)
{
    CELULA *aux;
    aux = *fila;
    int menor = 0;
    menor = (*fila)->info;
    while(aux != NULL)
    {
        if(aux->info < menor)
        {
            menor = aux->info;
        }
        aux = aux->next;
    }
    return menor;
}

float calculaMedia(CELULA **fila)
{
    CELULA *aux;
    aux = *fila;
    float media = 0;
    int count = 0;
    while(aux != NULL)
    {
        media += aux->info;
        count++;
        aux = aux->next;
    }
    return media / count;
}

void main()
{
    CELULA *fila;
    inicializar(&fila);
    enfileirar(&fila, 2);
    enfileirar(&fila, 1);
    enfileirar(&fila, 3);
    enfileirar(&fila, 6);
    enfileirar(&fila, 5);
    exibeFila(&fila);
    printf("\nMaior elemento da fila: %d", achaMaior(&fila));
    printf("\nMenor elemento da fila: %d", achaMenor(&fila));
    printf("\nMedia aritmetica dos elementos da fila: %.2f", calculaMedia(&fila));

}
