/*
1. Uma pilha representa uma estrutura de dados em que os elementos s� podem ser
inseridos (empilhados) e removidos (desempilhados) do topo (in�cio da lista). Codifique,
compile e execute um programa que implemente as opera��es empilhar e desempilhar
do TAD pilha usando os conceitos de lista linear simplesmente encadeada formada por
n�meros reais:
a. Inserir um elemento no in�cio da lista;
b. Remover um elemento do in�cio da lista;
c. Exibir elementos da lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info; // representa a informa��o contida dentro da celula da pilha
    struct cell *next; // representa o endere�o da proxima celula da pilha
} CELULA;


void freenode(CELULA *pilha)
{
    free(pilha); // fun��o utilizada para liberar espa�o do n�, geralmente para remover um elemento da pilha
}

CELULA *getnode()
{
    // fun��o utilizada para alocar dinamicamente um espa�o na pilha
    return (CELULA*)malloc(sizeof(CELULA));
}

void inicializar(CELULA **pilha)
{
    *pilha = NULL;
}

int vazia(CELULA **pilha)
{
    if(*pilha == NULL)
        return 1;
    else
        return 0;
}

void empilhar(CELULA **pilha, int elem)
{
    CELULA *aux; // variavel auxiliar do tipo ponteiro que ira guardar a lista antes de empilhar
    aux = getnode(); // alocando espa�o para a variavel auxiliar

    if(!vazia(&aux)) // verifica se o ponteiro aux n�o esta vazio para poder empilhar na pilha
    {
        aux->info = elem; // empilha devidamente o elemento recebido no n� daquela posi��o
        aux->next = *pilha; // determina que a proxima posi��o vai receber o resto da pilha (topo)
        *pilha = aux; // coloca o n�mero guardado (aux) no topo da pilha
    }
    else
    {
        printf("\nERRO na alocacao do no");
    }
}

int desempilhar(CELULA **pilha)
{
    CELULA *aux; // variavel auxiliar do tipo ponteiro que ira guardar a lista antes de empilhar
    int valor; // valor do mesmo tipo da informa��o da lista, util para exibir
    if(!vazia(pilha)) // verifica se a pilha n�o est� vazia para poder desempilhar um elemento dela
    {
        valor = (*pilha)->info; // passa o topo da lista (elemento que ser� removido) para a variavel valor
        aux = *pilha; // determina que o ponteiro auxiliar recebera a pilha
        *pilha = (*pilha)->next; // determina que o n� atual ser� o proximo n�

        free(aux); // remove o n� atual da pilha
        return valor; // retorna o valor que esta sendo removido da pilha, util para uma fun��o de imprimir
    }
    else
    {
        printf("\nERRO: pilha vazia!"); // se tiver vazia da erro e avisa.
    }
}

void imprimir(CELULA **pilha)
{
    if(!vazia(pilha))
    {
        printf("\nExibindo pilha:\n");
        while(!vazia(pilha))
        {
            printf("|%d|", desempilhar(pilha));
        }
    }
    else
    {
        printf("\nERRO: pilha vazia!");
    }
}

int main()
{

}
