/*
9. Uma fila representa uma estrutura de dados em que o processo de inserção só acontece
no final da fila e a remoção somente no início. Codifique, compile e execute um
programa que permita fazer as operações de inserção e remoção sobre o TAD fila
usando os conceitos de lista linear simplesmente encadeada formada por números
inteiros:
a. Inserir um elemento no final da lista;
b. Remover um elemento do início da lista;
c. Exibir elementos da lista.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
} CELULA;

CELULA* inicializar(CELULA **fila)
{
    *fila = NULL;
    return *fila;
}

int vazia(CELULA **fila)
{
    if(*fila == NULL)
        return 1;
    else
        return 0;
}

CELULA* getnode()
{
    return (CELULA*)malloc(sizeof(CELULA));
}

void freenode(CELULA **fila)
{
    free(*fila);
}

CELULA* enfileirar(CELULA **fila, int elem) // insereFim
{
    CELULA *q;
    CELULA *aux;

    q = getnode();
    if(q != NULL )
    {
        q->info = elem;
        q->next = NULL;

        if(vazia(fila))
            *fila = q;
        else
        {
            aux = *fila;
            while (aux->next != NULL)
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

CELULA* desenfileirar(CELULA **fila) // removeInicio
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

void main()
{
    CELULA *fila;
    inicializar(&fila);
    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);
    enfileirar(&fila, 4);
    exibeFila(&fila);
    desenfileirar(&fila);
    exibeFila(&fila);
    enfileirar(&fila, 5);
    exibeFila(&fila);
}
