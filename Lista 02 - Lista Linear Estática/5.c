/*
5. Desenvolva um programa em Linguagem C que possua uma função que, dada duas listas, L1 e L2,
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
        int i;

        for(i=(L->n+1); i>L->n+1; i--)
        {
            L->valor[i] = L->valor[i-1];
        }

        L->n = L->n+1;
        L->valor[L->n] = elem;
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
    if((pos < 0) || (pos > L->n+1)) // verifica se a posição escolhida para acessar existe realmente na lista
    {
        printf("\nERRO: posicao escolhida fora dos limites");
        return 1; // retorna 1 para tratar erros no main
    }
    else
    {
        return L->valor[pos]; // retorna o valor que esta naquela posição especifica;
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
        for(i = 0; i<=(L->n); i++) // enquanto não chegar no final da lista vai imprimindo
        {
            printf("\n%d - |%d|", i, L->valor[i]);
        }
    }
}

//intercalar da natalia
void intercalarListas(LISTA *L1, LISTA *L2, LISTA *L3)
{
    int i;
    if((L1->n+1)+(L2->n+1)>T) // se as duas listas juntas excedem T
    {
        printf("\nERRO: Impossivel intercalar, listas excedem o número máximo de elementos");
        return;
    }
    if((L1->n)==(L2->n)) // se elas tem o mesmo tamanho pode intercalar sem problemas
    {
        for(i=0; i<=L1->n; i++) // for intercalando as duas
        {
            inserirNoFim(L3, L1->valor[i]);
            inserirNoFim(L3, L2->valor[i]);
        }
    }
    else if((L1->n)>(L2->n)) // se L1 for maior que L2
    {
        for(i=0; i<=L1->n; i++)
        {
            inserirNoFim(L3, L1->valor[i]); // insere em L3 primeiro de L1
            if(i<=L2->n) // verifica se o indice do for é menor ou igual que o indice de L2
            {
                inserirNoFim(L3, L2->valor[i]); // se for insere em L3 de L2
            }
        }
    }
    else // se L2 for maior que L1, faz o processo contrario a anterior
    {
        for(i=0; i<=L2->n; i++)
        {
            if(i<=L1->n) // verifica se o indice do for é menor que o indice de L1
            {
                inserirNoFim(L3, L1->valor[i]); // se for insere
            }
            inserirNoFim(L3, L2->valor[i]); // depois insere L2 normalmente

        }
    }

    imprimir(L3);
}

//int intercalarListas(LISTA *L1, LISTA *L2, LISTA *L3)
//{
//    //LISTA L3;
//    //inicializar(&L3);
//    if((L1->n) + (L2->n) == T)
//    {
//        printf("\nERRO: Impossivel intercalar, listas excedem o número máximo de elementos");
//        return 1;
//    }
//    else
//    {
//        int i = 0;
//        while(i <= L1->n+1 && i <= L2->n)
//        {
//            //if((L1->n) + (L2->n) <= T)
//            //{
//            inserirNoFim(L3, acessar(L1, i));
//            inserirNoFim(L3, acessar(L2, i));
//            //}
//            i++;
//        }
//    }
//    imprimir(L3);
//}

int main()
{
    LISTA L1, L2, L3;
    inicializar(&L1);
    inicializar(&L2);
    inicializar(&L3);
    int i = 0, j = 0, valor;

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
    intercalarListas(&L1,&L2,&L3);
    printf("\n");
    system("pause");
}
