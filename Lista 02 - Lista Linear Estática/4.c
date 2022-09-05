/*
4. Desenvolva um programa em Linguagem C que possua uma função que,
dada duas listas, L1 e L2, concatene L1 com L2 armazenando o resultado em L1.
*/

#include <stdio.h>
#include <stdlib.h>
#define T 10

typedef struct sLista
{
    int valor[T];
    int n;
} LISTA;

int inicializar (LISTA *L)
{
    L->n = -1;
}

int vazia(LISTA *L)
{
    if(L->n == -1)
        return 1;
    else
        return 0;
}

int cheia(LISTA *L)
{
    if(L->n+1 == T)
        return 1;
    else
        return 0;
}

int inserirNoFim(LISTA *L, int elem)
{
    if(cheia(L)) // verifica se tem espaço na lista para inserir
    {
        printf("\nERRO: lista cheia!");
        return 1; // retorna 1 para tratar erros no main
    }
    else
    {
        L->valor[L->n+1] = elem; // como o indice "n" é iniciado na posição "-1" para se inserir passasse para o valor a posição n+1, que no caso vai ser a primeira posição na frente do indice;
        L-> n = L-> n+1; // atualiza a posição do indice, pois inseriu-se um elemento na posição em que "n" estava
        return 0; // retorna 0 para tratar erros no main
    }
}

int imprimir(LISTA *L)
{
    int i;

    if(vazia(L)) // verifica se tem alguma coisa pra imprimir
    {
        printf("\nERRO: lista vazia!");
        return 1; // retorna 1 para tratar erros no main
    }
    else
    {
        for(i = 0; i<(L->n+1); i++) // enquanto não chegar no final da lista vai imprimindo
        {
            printf("\n%d - |%d|", i, L->valor[i]);
        }
    }
}

int concatenarListas(LISTA *L1, LISTA *L2)
{
    if((L1->n) + (L2->n) <= T)
    {
        for(int i=0; i<L2->n; i++)
        {
            inserirNoFim(L1, L2->valor[i]);
        }
    }
    else
    {
        printf("\nERRO: Tamanho insuficiente");
    }
}


void main()
{
    LISTA L1, L2;
    inicializar(&L1);
    inicializar(&L2);
    int valor;
    int i = 1;
    int j = 1;
    do
    {
        printf("\nIndique o elemento %d a ser inserido em L1 (0 para sair)\n>>> ", i);
        scanf("%d", &valor);
        if(valor != 0)
            inserirNoFim(&L1,valor);
        i++;
    }
    while(valor != 0);
    imprimir(&L1);

    do
    {
        printf("\nIndique o elemento %d a ser inserido em L2 (0 para sair)\n>>> ", j);
        scanf("%d", &valor);
        if(valor != 0)
            inserirNoFim(&L2,valor);
        j++;
    }
    while(valor != 0);
    imprimir(&L2);

    printf("\nConcatenando listas...\n");
    concatenarListas(&L1, &L2);
    system("pause");

    printf("\nListas concatenadas em L1");
    imprimir(&L1);
}

