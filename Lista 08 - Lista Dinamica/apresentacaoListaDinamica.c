#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info; // informação a ser guardada na lista dinamcia (pode ser int, float, char, struct)
    struct cell *next;
} CELULA;

CELULAR* getnode()
{
    return (CELULA *) malloc (sizeof (CELULA)); // reservando espaço de memoria pra poder alocar informações
}

void freenode(CELULA *q)
{
    free(q);
}

CELULA* inicializar(CELULA *lista)
{
    lista = NULL;
    return lista;
}

int vazia(CELULA *lista)
{
    if(lista = NULL)
        return 1;
    return 0;
}

void exibeLista(CELULA *lista)
{
    CELULA *aux;

    aux = lista;
    while(aux !=NULL)
    {
        printf("%d\t", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

CELULA* insereInicio(CELULA *lista, int x)
{
    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        q->info = x;
        q->next = lista;
        lista = q;
        return lista;
    }
    else
    {
        printf("\nERRO na alocacao do no.\n");
        return NULL;
    }
}

CELULA* insereFim(CELULA *lista, int x)
{
    CELULA *q; // usa-se esse ponteiro para apontar pro novo nó que será inserido
    CELULA *aux; // usa-se esse ponteiro para percorrer a lista
    q = getnode();
    if(q != NULL)
    {
        q->info = x;
        q->next = NULL;

        if(vazia(lista))
            lista = q;
        else
        {
            aux = lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }

            aux->next = q;
        }
        return lista;
    }
    else
    {
        printf("\nERRO na alocacao do no.\n");
        return NULL;
    }
}

CELULA* removeInicio(CELULA *lista)
{
    CELULA *q;

    q = lista;
    if(!vazia(lista))
    {
        lista = q->next;
        freenode(q);
    }
}
