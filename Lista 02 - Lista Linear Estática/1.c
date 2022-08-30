/* 1. Desenvolva um programa em Linguagem C que permita fazer as seguintes operações
sobre uma lista linear estática de números inteiros positivos:
a. Inserir um elemento em uma posição específica;
b. Remover um elemento de uma posição específica;
c. Acessar um elemento de uma posição específica;
d. Procurar um determinado elemento;
e. Exibir os elementos do vetor.
 Quantos bytes seu programa principal ocupa para armazenar dados?
 OBS: Defina funções para cada operação.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define T 5

typedef struct lista
{
    int valor[T];
    int n; // n é o indice da lista estatica
} LISTA;

void listaInicializar(LISTA *L)
{
    L->n = -1; // define n como "-1" para indicar que a lista esta vazia
}

int cheia(LISTA *L)
{
    if (L->n+1 == T) // verifica se uma posição a frente do indice da lista ela atinge o tamanho maximo
        return 1; // retorna 1 para tratamento de erros
    else
        return 0;
}

int vazia(LISTA *L)
{
    if (L->n == -1) // verifica se o indice esta na posição inicial definida
        return 1; // retorna 1 para tratamento de erros
    else
        return 0;
}

/*
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
} */

int inserirPosicaoEspecifica(LISTA *L, int pos, int elem)
{
    if(cheia(L)) // verifica se tem espaço na lista para inserir
    {
        printf("\nERRO: lista cheia!");
        return 1; // retorna 1 para tratar erros no main
    }

    if(pos < 0 || pos > L->n+1) // verifica se a posição escolhida para inserção existe realmente na lista
    {
        printf("\nERRO: posição escolhida fora dos limites");
        return 1; // retorna 1 para tratar erros no main
    }
    else
    {
        int i;

        for(i=(L->n+1); i>pos; i--) // percorre a lista de forma inversa até encontrar a posição escolhida
        {
            L->valor[i] = L->valor[i-1]; // como o indice "i" vai estar uma posição a frente da posição escolhida, passa-se para o valor a posição "i-1", que no caso é valor da posição anterior
        }

        L->valor[pos] = elem; // insere-se o valor desejado na posição escolhida
        L->n = L->n+1; // atualiza a posição do indice, pois inseriu-se um elemento na posição em que "n" estava
        printf("\nElemento inserido na posicao escolhida!");
        return 0; // retorna 0 para tratar erros no main
    }

}

int removerPosicaoEspecifica(LISTA *L, int pos)
{
    int i;

    if(vazia(L)) // verifica se tem alguma coisa pra remover
    {
        printf("\nERRO: lista vazia!");
        return 1; // retorna 1 para tratar erros no main
    }
    if(pos < 0 || pos > L->n+1) // verifica se a posição escolhida para remoção existe realmente na lista
    {
        printf("\nERRO: posição escolhida fora dos limites");
        return 1; // retorna 1 para tratar erros no main
    }
    else
    {
        for(i=pos; i<(L->n); i++) // percorre a lista da posição escolhida, até o indice da mesma
        {
            L->valor[i] = L->valor[i+1]; // faz com que o valor de uma posição assuma o valor da proxima posição;
        }

        printf("\nElemento removida da posicao escolhida!");
        L->n = L->n-1; // remove uma posição da lista fazendo o "indice - 1"
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

int buscar(LISTA *L, int val)
{
    int elem = -1;
    int i = 0;

    while(i <= (L->n)) // aqui ta passando de posição em posição da lista até chegar no final dela
    {
        if(val == L->valor[i]) // verifica se o valor buscar é igual ao valor da posição atual
        {
            elem = i; // se for guarda a posição atual na variavel elem;

            break; // faz sair do if forçadamente
        }
        i++; // passa o indice pra proxima posição
    }
    return elem; //retorna a posição em que o valor buscado está
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
    listaInicializar(&L);
    int op;

    do
    {
        printf("\n+----------------------------+");
        printf("\n|          MENU LISTA        |");
        printf("\n+----------------------------+");
        printf("\n|1 - Inserir pos. especifica |");
        printf("\n|2 - Remover pos. especifica |");
        printf("\n|3 - Acessar pos. especifica |");
        printf("\n|4 - Procurar det. elemento  |");
        printf("\n|5 - Exibir os elementos     |");
        printf("\n+----------------------------+");

        printf("\n\nEscolha uma opcao\n>>> ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            ;
            int pos = 0, elem = 0;

            printf("\n\nIndique a posicao que o elemento sera inserido\n>>> ");
            scanf("%d", &pos);


            printf("\n\nIndique o elemento que sera inserido\n>>> ");
            scanf("%d", &elem);

            inserirPosicaoEspecifica(&L,pos,elem);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 2:
            ;
            printf("\n\nIndique a posicao que o elemento sera inserido\n>>> ");
            scanf("%d", &pos);

            removerPosicaoEspecifica(&L, pos);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 3:
            ;
            printf("\n\nIndique a posicao que o elemento sera acessado\n>>> ");
            scanf("%d", &pos);

            printf("Elemento da posicao %d: %d", pos, acessar(&L, pos));

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 4:
            ;
            int val = 0;

            printf("\n\nIndique o elemento a ser buscado\n>>> ");
            scanf("%d", &val);

            printf("Posicao do elemento %d: %d", val, buscar(&L, val));

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

int main()
{
    menu();
}
