/* 4. Leia um vetor de 10 posições e em seguida um valor X qualquer. Seu programa deverá
fazer uma busca do valor de X no vetor lido. Caso encontre o valor deverá ser removido
do vetor. */

#include <stdio.h>
#define T 10
#define true 1
#define false 0

void lerVetor(int vet[])
{
    for(int i=0; i<T; i++)
    {
        printf("\nIndique o elemento %d do vetor\n>>>", i+1);
        scanf("%d", &vet[i]);
    }
}

int lerX()
{
    int x;
    printf("\nIndique o valor de x\n\n>>>");
    scanf("%d", &x);

    return x;
}

void buscaXERemove(int vet[], int x)
{
    int controle;
    for(int i=0; i<T; i++)
    {
        if(vet[i]==x)
        {
            controle == true;
            printf("\nX encontrado na posicao %d", i+1);
            printf("\nRemovendo X do vetor");
            vet[i] = 0;
        }
    }
    if(controle==false)
    {
        printf("\nX nao foi encontrado");
    }
}

void exibir(int vet[])
{
    printf("\n\nVetor com valor removido:\n");
    for(int i=0; i<T; i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n");
}

void main()
{
    int vet[T], x;


    lerVetor(vet);
    x = lerX();
    buscaXERemove(vet, x);
    exibir(vet);
}
