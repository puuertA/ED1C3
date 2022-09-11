/*
3. Escreva uma função que devolva o comprimento (ou seja, o número de elementos) de
uma determinada fila estática circular.
*/

#include <stdio.h>
#include <stdlib.h>
#define T 10

typedef struct sFila
{
    int itens[T];
    int inicio, fim;
} FILA;

void inicializar(FILA *F)
{
    F->inicio = T-1;
    F->fim = T-1;
}

int vazia(FILA *F)
{
    if(F->fim == F->inicio)
        return 1;
    else
        return 0;
}

int cheia(FILA *F)
{
    if(F->fim == F->inicio)
        return 1;
    else
        return 0;
}

void enfileirar(FILA *F, int elem)
{
    if(F->fim == (T-1)) // se tiver vazia
    {
        F->fim = 0; // define fim como 0
    }
    else // se não
    {
        F->fim++; // aumenta uma posição do fim
    }
    if(cheia(F))
    {
        printf("\nERRO: Fila cheia!");
        F->fim--; // diminui uma posição do fim
        if(F->fim == -1) // se tiver vazia
            F->fim = T-1; // define o fim como o tamanho -1;
        return; // sai do if
    }
    F->itens[F->fim] = elem; // enfileira o elemento devidamente
}

int desenfileirar (FILA *F)
{
    int aux = 0; // cria um aux para retornar no final da função

    if(!vazia(F)) // ve se não ta vazia pra poder tirar as coisa né
    {
        if(F->inicio == T-1) //se o inicio tiver em -1
        {
            F->inicio = 0; // passa ele pra 0 pra poder lidar
        }
        else // se não
        {
            F->inicio++; // aumentar uma posição do inicio
        }
        aux = F->itens[F->inicio]; //passa o valor que tiver no inicio pro auxiliar
    }
    else
    {
        printf("\nERRO: Fila vazia!");
    }
    return aux; // volta o valor que ta em aux, caso precise dele pra alguma outra coisa
}

// impressão não classica dos elementos de uma fila
void imprimirNaoClassica (FILA *F)
{
    int i = (F->inicio+1) % T;
    if(!vazia(F))
    {
        printf("Fila utilizando impressao nao classica (utilizando indice i e aumentando ele)");
        printf("\nFila: ");
        while(i!=((F->fim+1)% T))
        {
            printf("|%d|",F->itens[i]);
            i = (i+1) % T;
        }
    }
    else
        printf("\nERRO: Fila vazia!");
}

// impressão classica dos elementos de uma fila
void imprimirClassica(FILA *F)
{
    if(vazia(F))
    {
        printf("ERRO: Fila vazia.\n");
        return;
    }
    else
    {
        printf("Fila utilizando impressao classica (desenfileirando)");
        printf("\nFila: ");
        while(!vazia(F))
        {
            printf("[%d]", desenfileirar(F));
        }
    }
}

// calculando o elemento de uma fila usando resto da divisão e o tamanho fisico
int calcularComprimento (FILA *F)
{
    int i = (F->inicio+1) %T;
    int comp = 0;
    if(!vazia(F))
    {
        while(i!=((F->fim+1)%T))
        {
            comp++;
            i = (i+1)%T;
        }
    }
    else
        printf("\nFila vazia.");

    return comp;
}

int main()
{
    FILA F;
    inicializar(&F);
    enfileirar(&F, 1);
    enfileirar(&F, 2);
    enfileirar(&F, 3);
    enfileirar(&F, 4);
    enfileirar(&F, 5);
    enfileirar(&F, 6);

    //calcularComprimento(&F);
    imprimirNaoClassica(&F);
    printf("\n");
    printf("\nComprimento da Fila: %d", calcularComprimento(&F));
    printf("\n");
    imprimirClassica(&F);
    printf("\n");
    printf("\nComprimento da Fila: %d", calcularComprimento(&F));
    printf("\n");
}
