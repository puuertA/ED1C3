/* 2. Desenvolva um programa em Linguagem C que permita
ao usuário inserir e remover elementos nos extremos de
uma sequência de itens, ou seja, no início e no final
de uma lista linear estática.*/

#include <stdio.h>
#include <stdlib.h>
#define T 10

typedef struct lista
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
    if(L->n + 1 == T)
        return 1;
    else
        return 0;
}

int inserirNoInicio(LISTA *L, int elem)
{
    if(cheia(L))
    {
        printf("\nERRO: lista cheia!");
        return 1;
    }
    else
    {
        for(int i=(L->n+1); i>=0; i--)
        {
            L->valor[i] = L->valor[i-1];
        }

        L->valor[0] = elem;
        L->n = L->n+1;
    }
}

int removerDoInicio(LISTA *L)
{
    if(vazia(L))
    {
        printf("\nERRO: lista vazia!");
        return 1;
    }
    else
    {
        for(int i=0; i<(L->n); i++)
        {
            L->valor[i] = L->valor[i+1];
        }
        printf("\nElemento removido com sucesso do inicio");
        L->n = L->n-1;
    }
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

int removerDoFim(LISTA *L)
{
    if(vazia(L))
    {
        printf("\nERRO: lista vazia!");
        return 1;
    }
    else
    {
        for(int i=(L->n); i<(L->n); i++)
        {
            L->valor[i] = L->valor[i+1];
        }
        printf("\nElemento removido com sucesso do inicio");
        L->n = L->n-1;
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

int menu()
{
    LISTA L; // declara variavel do tipo lista
    inicializar(&L);
    int op;

    do
    {
        printf("\n+----------------------------+");
        printf("\n|          MENU LISTA        |");
        printf("\n+----------------------------+");
        printf("\n|1 - Inserir no inicio       |");
        printf("\n|2 - Remover do inicio       |");
        printf("\n|3 - Inserir no fim          |");
        printf("\n|4 - Remover do fim          |");
        printf("\n|5 - Exibir os elementos     |");
        printf("\n+----------------------------+");

        printf("\n\nEscolha uma opcao\n>>> ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            ;
            int elem = 0;

            printf("\n\nIndique o elemento que sera inserido\n>>> ");
            scanf("%d", &elem);

            inserirNoInicio(&L,elem);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 2:
            ;
            printf("\nRemovendo elemento do inicio da lista");

            removerDoInicio(&L);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 3:
            ;
            int element;

            printf("\n\nIndique o elemento que sera inserido\n>>> ");
            scanf("%d", &element);

            inserirNoFim(&L,element);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 4:
            ;
            printf("\nRemovendo elemento do fim da lista");

            removerDoFim(&L);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 5:
            ;
            printf("\nExibindo os elementos da lista: \n\n");
            imprimir(&L);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        default:
            ;
            printf("\nInsira uma opcao valida");
        }
    }
    while(op!=0);
}

void main()
{
    menu();
}
