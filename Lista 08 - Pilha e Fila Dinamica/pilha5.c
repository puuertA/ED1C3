/*
5. Dada uma pilha P, codifique uma função que inverta a ordem dos elementos dessa pilha
utilizando apenas uma estrutura auxiliar. Obs: - Defina adequadamente a estrutura
auxiliar; - atente sobre a possibilidade da pilha estar vazia.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
} CELULA;

void inicializar(CELULA **pilha)
{
    *pilha = NULL;
}

CELULA* getnode()
{
     return (CELULA*)malloc(sizeof(CELULA));
}

void freenode(CELULA *pilha)
{
    free(pilha);
}

int vazia(CELULA **pilha)
{
    if(*pilha == NULL)
        return 1;
    else
        return 0;
}

int empilhar(CELULA **pilha, int elem)
{
    CELULA *aux;

    aux = getnode();

    if(!vazia(&aux))
    {
        aux->info = elem;
        aux->next = *pilha;
        *pilha = aux;
    }
    else
    {
        printf("\nERRO na alocacao do no");
    }
}

int desempilhar(CELULA **pilha)
{
    CELULA *aux;
    int valor;
    if(!vazia(pilha))
    {
        valor = (*pilha)->info;
        aux = *pilha;
        *pilha = (*pilha)->next;

        free(aux);
        return valor;
    }
    else
    {
        printf("\nERRO: pilha vazia!");
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

//int invertePilha(CELULA **pilha)
//{
//    CELULA *pilhaAuxiliar;
//
//    inicializar(&pilhaAuxiliar);
//
//
//}

int main()
{
    CELULA *pilha;
    CELULA *pilhaAuxiliar;

    inicializar(&pilha);
    inicializar(&pilhaAuxiliar);

    empilhar(&pilha, 7);
    empilhar(&pilha, 14);
    empilhar(&pilha, 24);
    empilhar(&pilha, 43);
    if(!vazia(&pilha))
    {
        while(!vazia(&pilha))
        {
            empilhar(&pilhaAuxiliar, desempilhar(&pilha));
        }
        while(!vazia(&pilhaAuxiliar))
        {
            empilhar(&pilha, desempilhar(&pilhaAuxiliar));
        }
    }
    else
    {
        printf("\nERRO: pilha vazia!");
    }
    imprimir(&pilha);

}
