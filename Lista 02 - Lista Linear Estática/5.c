/*
5. Desenvolva um programa em Linguagem C que possua uma fun��o que, dada duas listas, L1 e L2,
intercale os elementos de L1 com L2 armazenando o resultado em uma terceira lista L3.
*/

#include <stdio.h>
#include <stdlib.h>
#define T 10

typedef struct sLista
{
    int valor[T];
    int n;
} LISTA;

void inicializar(LISTA *L)
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
        printf("\nERRO: Lista cheia");
        return 1;
    }
    else
    {
        L->valor[L->n+1] = elem;
        L->n = L->n+1;
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
    if((pos < 0) || (pos > L->n+1)) // verifica se a posi��o escolhida para acessar existe realmente na lista
    {
        printf("\nERRO: posicao escolhida fora dos limites");
        return 1; // retorna 1 para tratar erros no main
    }
    else
    {
        return L->valor[pos]; // retorna o valor que esta naquela posi��o especifica;
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
        for(i = 0; i<=(L->n); i++) // enquanto n�o chegar no final da lista vai imprimindo
        {
            printf("\n%d - |%d|", i, L->valor[i]);
        }
    }
}

int intercalarListas(LISTA *L1, LISTA *L2)
{
    LISTA L3;
    inicializar(&L3);
    if((L1->n) + (L2->n) == T)
    {
        printf("\nERRO: Impossivel intercalar, listas excedem o n�mero m�ximo de elementos");
        return 1;
    }
    else
    {
        //        while(i < (L1->n) + (L2->n))
//        {
//            inserirNoFim(&L3, acessar(L1, i));
//            inserirNoFim(&L3, acessar(L2, i));
//            i++;
//        }
        int i;
        for(i=0;i<=(L1->n) + (L2->n);i++)
        {
            inserirNoFim(&L3, acessar(L1, i));
            inserirNoFim(&L3, acessar(L2, i));
        }
    }
    imprimir(&L3);
}

int main()
{
    LISTA L1, L2;
    inicializar(&L1);
    inicializar(&L2);
    int i = 1, j = 1, valor;

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

    printf("\nIntercalando listas...\n");
    printf("\nListas intercaladas em L3");
    intercalarListas(&L1,&L2);
    printf("\n");
    system("pause");
}
