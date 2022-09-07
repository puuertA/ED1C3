/*
6. Desenvolva um programa em Linguagem C que dada uma
lista L1 seu inverso seja armazenado em uma lista L2.
*/

#include <stdio.h>
#include <stdlib.h>
#define T 5

typedef struct sLista
{
    int valor[T];
    int n;
} LISTA;

int inicializar(LISTA *L)
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
    if(cheia(L))
    {
        printf("\nERRO: lista cheia!");
        return 1;
    }
    else
    {
        L->valor[L->n+1] = elem;
        L->n = L->n + 1;
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
        return 0;
    }
}

int acessar(LISTA *L, int pos)
{
    if(vazia(L)) // verifica se tem alguma coisa pra acessar
    {
        printf("\nERRO: lista vazia!");
        return 1; // retorna 1 para tratar erros no main
    }
    if(pos < 0 || pos > L->n+1) // verifica se a posição escolhida para acessar existe realmente na lista
    {
        printf("\nERRO: posição escolhida fora dos limites");
        return 1; // retorna 1 para tratar erros no main
    }
    else
    {
        return L->valor[pos]; // retorna o valor que esta naquela posição especifica;
    }
}

int inverterListas(LISTA *L1)
{
    LISTA L2;
    inicializar(&L2);

    for(int i=(L1->n); i>=0; i--)
    {
        inserirNoFim(&L2, acessar(L1, i));
    }

    printf("\n\nLista L1 invertida em L2\n");
    imprimir(&L2);
}

int main()
{
    LISTA L1;
    inicializar(&L1);

    int i, valor;

    while(L1.n + 1 < T)
    {
        printf("\nIndique o valor %d\n>>> ", i);
        scanf("%d", &valor);

        inserirNoFim(&L1, valor);

        i++;
    }

    imprimir(&L1);
    inverterListas(&L1);
}

