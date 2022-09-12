#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50

typedef struct Barraca
{
    char nome_locatario[45];
    char cpf_locatario[14];
    char situacao;
    int produto;
} BARRACA;

typedef struct sLista
{
    BARRACA barraca[tam];
    int n;
} LISTA;

void incializar(LISTA *L)
{
    L->n= -1;
}

int cheia(LISTA *L)
{
    if (L->n+1==tam)
        return 1;
    return 0;
}

int vazia(LISTA *L)
{
    if (L->n==-1)
        return 1;
    return 0;
}

BARRACA ler()
{

    BARRACA b;
    printf("\nInsira o nome do locatario: ");
    fflush(stdin);
    scanf("%s", &b.nome_locatario);
    printf("\nInsira o cpf do locatario: ");
    scanf("%s", b.cpf_locatario);
    printf("\nInsira a situação da barraca (P-pago N-nao pago): ");
    fflush(stdin);
    scanf(" %c", &b.situacao);
    b.situacao=toupper(b.situacao);
    printf("\nInsira o tipo de produto (1: bebida, 2: lanches, 3: artigos em geral) ");
    scanf("%d", &b.produto);

    printf("\n");

    return b;
}

void inserir(LISTA *L)
{
    if(cheia(L))
    {
        printf("\nERRO: Lista cheia");
        return;
    }
    L->n++;
    BARRACA b = ler();
    L->barraca[L->n]= b;
}

void relatorioInadiplentes(LISTA L)
{
    int i;
    BARRACA b;
    printf("\nBarracas inadiplentes: ");
    for(i = 0; i<=L.n; i++)
    {
        b = L.barraca[i];
        if(b.situacao== 'N')
        {
            printf("\nBarraca: %d", i+1);
            printf("\nNome: %s", b.nome_locatario);
            printf("\n");
        }
    }
    printf("\n");
}

void relatorioBarrcas(LISTA L)
{
    int i;
    printf("\n\nBarracas ocupadas: ");
    for(i=1; i<=L.n+1; i++)
    {
        printf("|%d|", i);
    }
    printf("\nTotal: %d", L.n+1);

    printf("\n\nBarracas livres: ");
    for(i=L.n+2; i<=tam; i++)
    {
        printf("|%d|", i);
    }
    printf("\nTotal: %d", tam-(L.n+1));

    printf("\n");
}

void main()
{
    LISTA lista;
    int op=1;
    incializar(&lista);
    while(op!=0)
    {
        printf("\nInserir barraca.............1");
        printf("\nBarracas inadiplentes.......2");
        printf("\nBarracas ocupadas e livres..3");
        printf("\nSair........................0\n");
        scanf("%d", & op);

        switch(op){
            case 0:
            break;

            case 1:
                inserir(&lista);
            break;

            case 2:
                relatorioInadiplentes(lista);
            break;

            case 3:
                relatorioBarrcas(lista);
            break;

        }
    }

}




