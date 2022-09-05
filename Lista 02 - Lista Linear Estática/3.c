/*
3. Desenvolva um programa em Linguagem C
que permita fazer as seguintes
operações sobre uma lista linear
estática de números reais:
inserir um elemento mantendo a ordem crescente entre os elementos no vetor;
remover um valor indicado pelo usuário, eliminando eventuais "lacunas abertas" pela remoção.
*/

#include <stdio.h>
#include <stdlib.h>
#define T 10

typedef struct sLista
{
    int valor[T];
    int n;
} LISTA;

int inicializar(LISTA *L)
{
    L->n = -1;
}

int cheia(LISTA *L)
{
    if(L->n+1 == T)
        return 1;
    else
        return 0;
}

int vazia(LISTA *L)
{
    if(L->n == -1)
        return 1;
    else
        return 0;
}

int inserirOrdenadamente(LISTA *L, int elem)
{
    if(cheia(L))
    {
        printf("\nERRO: lista cheia");
    }
    if(vazia(L)){ // ve se ta vazia
        L->n = L->n+1; // aumenta o indice em 1 pra poder inserir
        L->valor[L->n] = elem; // insere o elemento na posição do indice (fim da lista)
        return 1; // ja sai fora se tiver vazia
    }
    int i=(L->n); // determina o i como o indice (fim da lista)
    int p=(L->n)+1; // determina o p como uma posição a frente do indice (fim da lista  + 1)
    while(elem<L->valor[i]){ // praticamente um if vendo se o o valor que quer inserir é maior que os da lista
        L->valor[i+1] = L->valor[i]; // faz o valor da frente virar o que tem atras
        i--; // diminui uma posição do i com intenção de achar a posição anterior ao valor inserido
        p--; // diminui uma do p com intenção de achar a posição que vai ser devidamente inserido
    }
    L->valor[p] = elem; // insere na posição correta
    L->n = L->n+1; // aumenta o indice em 1 para poder inserir
    return 1; // so sai fora depois que reoordenar toda a lista
}

int removerElemento(LISTA *L, int elem)
{

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
        printf("\n+-------------------------------+");
        printf("\n|          MENU LISTA           |");
        printf("\n+-------------------------------+");
        printf("\n|1 - Inserir val. ordenadamente |");
        printf("\n|2 - Remover val. especifico    |");
        printf("\n|3 - Exibir os elementos        |");
        printf("\n+-------------------------------+");

        printf("\n\nEscolha uma opcao\n>>> ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            ;
            int elem = 0;

            printf("\n\nIndique o elemento que sera inserido\n>>> ");
            scanf("%d", &elem);

            inserirOrdenadamente(&L,elem);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 2:
            ;
//            printf("\n\nIndique o elemento sera removido\n>>> ");
//            scanf("%d", &elem);
//
//            removerPosicaoEspecifica(&L, elem);
//
//            printf("\n");
//            system("pause");
//            system("clear||cls");
            break;

        case 3:
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
