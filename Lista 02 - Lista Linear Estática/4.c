/* 4. Desenvolva um programa em Linguagem C que possua uma função que, dada duas
listas, L1 e L2, concatene L1 com L2 armazenando o resultado em L1. */
#include <stdio.h>
#define T 5

typedef struct sLista
{
    int vet[T];
    int n;
} LISTA;

void inicializar(LISTA *lis)
{
    (*lis).n = -2;
    lis->n = -1; // na função utiliza-se o ponteiro como "->"
}

int cheia(LISTA lista)
{
    if((*lista).n == T - 1)
        return 1; // pode ser usado para validar como cheio
    else
        return 0; // pode ser usado para validar como vazio
}

int vazia(LISTA lista){
    if((*lista).n == -1)
        return 1;
    else
        return 0;
}

void inserirElementoFim(LISTA *lista, int valor)
{
    if(cheia(&lista))
    {
        printf("Lista cheia!!! Ferrou...");
    }
    else
    {
        lista->n++;
        lista->vetor[lista->n] = valor;
    }
}

void exibirLista(LISTA lista)
{
    int i;
    if(vazia(&lista))
    {
        printf("Lista vazia!!!");
    }
    else
    {
        for(i = 0; i <= lista.n; i++)
        {
            printf("%d ", lista.vetor[i]);
        }
    }
}

void concatenarListas(LISTA *lista1, LISTA lista2){
    int i;
    if((lista1->n + 1) + (lista2.n + 1) <= TAM)
    {
        for(i = 0; )
    }else{
        printf("Tamanho insuficiente");
    }
}

void main()
{
    LISTA lista1, lista2;
    inicializar(&lista1);
    inicializar(&lista2);
    int valor;

//    printf("%d",lista.n); // no main utiliza-se o ponteiro como "."

    do
    {
        printf("Digite o valor para a lista 1 (0 - sair):");
        scanf("%d", &valor);
        if(valor != 0)
            inserirElementoFim(&lista1 ,valor);
    }while(valor != 0);

    exibirLista(lista1);
    do{
        printf("\nDigite o valor para a lista 2 (0 - sair)");
        scanf("%d", &valor);
        if(valor != 0)
            inserirElementoFim(&lista2, valor);
    }while (valor != 0);
    exibirLista(lista2);

    concatenarListas(&lista1, &lista2);
}
