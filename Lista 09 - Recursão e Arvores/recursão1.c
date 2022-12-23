/*
1. Desenvolva um programa em Linguagem C que permita fazer as seguintes operações
sobre uma lista simplesmente encadeada:
a. Calcular o comprimento da lista;
b. Somar todos os elementos da lista;
c. Multiplicar todos os elementos da lista;
d. Imprimir os elementos ímpares a partir do início da lista;
e. Imprimir os elementos pares da lista na ordem inversa.
* Para cada operação acima desenvolva uma função recursiva. Desenvolva também uma
função menu para que o usuário possa selecionar a opção desejada.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct cell
{
    int info;
    struct cell *next;
} CELULA;

CELULA *getnode()
{
    return (CELULA*)malloc(sizeof(CELULA));
}

void freenode(CELULA *lista)
{
    free(lista);
}

void inicializar(CELULA **lista)
{
    *lista = NULL;

}

int vazia(CELULA **lista)
{
    if(*lista == NULL)
        return 1;
    else
        return 0;
}

void exibeLista(CELULA *lista)
{
    CELULA *aux;

    aux = lista;

    while(aux != NULL)
    {
        printf("%d\t", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

void insereInicio(CELULA **lista, int elem)
{
    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        q->info = elem;
        q->next = *lista;
        *lista = q;
    }
    else
    {
        printf("\nERRO na alocacao do no\n");
        exit(1);
    }
}

void removeInicio(CELULA **lista)
{
    CELULA *q;

    q = *lista;
    if(!vazia(*lista))
    {
        *lista = q->next;
        freenode(q);
    }
    else
    {
        printf("\nERRO: lista vazia!");
        exit(1);
    }
}

int calcularComprimento(CELULA **lista)
{
    CELULA *aux;
    int comprimento = 0;
    aux = *lista;
    if(!vazia(*lista))
    {
        aux = aux->next;
        comprimento++;
        calcularComprimento(lista);
        printf("\nComprimento da lista: %d", comprimento);
    }
    else
    {
        printf("\nERRO: lista vazia!");
    }
}

int main()
{
    CELULA *lista;

    inicializar(&lista);

    printf("\nInserindo elementos na lista...\n");

    insereInicio(&lista, 1);
    insereInicio(&lista, 3);
    insereInicio(&lista, 5);
    insereInicio(&lista, 7);
    insereInicio(&lista, 9);

    exibeLista(lista);

    printf("\nComprimento da lista: %d", calcularComprimento(&lista));
}
