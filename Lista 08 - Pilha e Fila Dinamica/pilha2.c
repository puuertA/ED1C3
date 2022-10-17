/*2. Usando a Linguagem C:
a. Como você definiria o tipo pilha usando a representação de lista simplesmente
encadeada? Considere, para isto, uma pilha de pratos contendo os campos: cor
(branco, preto, roxo, etc) e formato (redondo, quadrado, retangular, etc).
b. Desenvolva a função Pilha* pilha_inicializa (Pilha* p)
c. Desenvolva a função Pilha* pilha_insereTopo (Pilha* p, Prato x)
d. Na função main crie uma variável do tipo da estrutura Pilha. Em seguida chame
a função pilha_inicializa e pilha_insereTopo.
*/

#include <stdio.h>
#include <stdlib.h>

// a
typedef struct sPratos
{
    char cor[30];
    char formato[30];
} PRATO;

typedef struct cell
{
    PRATO prato;
    struct cell *next;
} CELULA;

// b
void inicializar(CELULA **pilha)
{
    *pilha = NULL;
}

CELULA* getnode()
{
    return(CELULA*)malloc(sizeof(CELULA));
}

void freenode(CELULA *pilha)
{
    free(pilha);
}

// c
PRATO ler()
{
    PRATO pratoLido;
    printf("\nInsira a cor do prato\n>>> ");
    fflush(stdin);
    scanf("%s", &pratoLido.cor);
    printf("\nInsira o formato do prato\n>>> ");
    fflush(stdin);
    scanf("%s", &pratoLido.formato)

    printf("\n");

    return pratoLido;
}

void insereTopo (CELULA **pilha)
{
    CELULA *aux;
    aux = getnode();

    if(!vazia(&aux))
    {
        PRATO p = ler();
        aux->prato = p;
        aux->next = *pilha;
        *pilha = aux;
    }
    else
    {
        printf("\nERRO na alocacao do no");
    }
}

int main()
{
  CELULA *pilha;

  inicializar(&pilha);

  insereTopo(&pilha);
  insereTopo(&pilha);
  insereTopo(&pilha);

}
