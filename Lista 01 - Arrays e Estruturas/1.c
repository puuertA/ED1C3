/*1. Faça um programa para ler um vetor de 12 posições e em seguida ler também dois
valores X e Y quaisquer correspondentes a duas posições no vetor. Ao final seu programa
deverá escrever a soma dos valores encontrados nas respectivas posições X e Y.*/

#include <stdio.h>
#define T 12

int lerVetor(int vet[])
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

int lerY()
{
    int y;
    printf("\nIndique o valor de y\n\n>>>");
    scanf("%d", &y);

    return y;
}

int comparaESoma(int vet[], int x, int y)
{
    int soma = 0;
    for(int i=0; i<T; i++)
    {
        soma = vet[x-1] + vet[y-1];
    }

    return soma;
}

void exibir(int soma)
{
    printf("\nA soma dos valores x e y e de:\n%d", soma);
}

void main()
{
    int vet[T], x, y, soma;


    lerVetor(vet);
    x = lerX();
    y = lerY();
    soma = comparaESoma(vet, x, y);
    exibir(soma);
}

