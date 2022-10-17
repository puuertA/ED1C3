/*
1. Uma pilha representa uma estrutura de dados em que os elementos só podem ser
inseridos (empilhados) e removidos (desempilhados) do topo (início da lista). Codifique,
compile e execute um programa que implemente as operações empilhar e desempilhar
do TAD pilha usando os conceitos de lista linear simplesmente encadeada formada por
números reais:
a. Inserir um elemento no início da lista;
b. Remover um elemento do início da lista;
c. Exibir elementos da lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info; // representa a informação contida dentro da celula da pilha
    struct cell *next; // representa o endereço da proxima celula da pilha
} CELULA;


void freenode(CELULA *pilha)
{
    free(pilha); // função utilizada para liberar espaço do nó, geralmente para remover um elemento da pilha
}

CELULA *getnode()
{
    // função utilizada para alocar dinamicamente um espaço na pilha
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
    aux = getnode(); // alocando espaço para a variavel auxiliar

    if(!vazia(&aux)) // verifica se o ponteiro aux não esta vazio para poder empilhar na pilha
    {
        aux->info = elem; // empilha devidamente o elemento recebido no nó daquela posição
        aux->next = *pilha; // determina que a proxima posição vai receber o resto da pilha (topo)
        *pilha = aux; // coloca o número guardado (aux) no topo da pilha
    }
    else
    {
        printf("\nERRO na alocacao do no");
    }
}

int desempilhar(CELULA **pilha)
{
    CELULA *aux; // variavel auxiliar do tipo ponteiro que ira guardar a lista antes de empilhar
    int valor; // valor do mesmo tipo da informação da lista, util para exibir
    if(!vazia(pilha)) // verifica se a pilha não está vazia para poder desempilhar um elemento dela
    {
        valor = (*pilha)->info; // passa o topo da lista (elemento que será removido) para a variavel valor
        aux = *pilha; // determina que o ponteiro auxiliar recebera a pilha
        *pilha = (*pilha)->next; // determina que o nó atual será o proximo nó

        free(aux); // remove o nó atual da pilha
        return valor; // retorna o valor que esta sendo removido da pilha, util para uma função de imprimir
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
