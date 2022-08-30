/*2. Leia um vetor de 16 posições e troque os 8 primeiros valores pelos 8 últimos e vice-eversa. Escreva ao final o vetor obtido.
*/

#include <stdio.h>
#define T 16

void lerVetor(int vet[])
{
    for(int i=0; i<T; i++)
    {
        printf("\nIndique o elemento %d do vetor\n>>>", i+1);
        scanf("%d", &vet[i]);
    }
}

void trocaPosicao(int vet[])
{
    int aux = 0;
    for(int i=0; i<(T/2); i++)
    {
        aux = vet[i];
        vet[i] = vet[i+(T/2)];
        vet[i+(T/2)] = aux;
    }
}

void exibir(int vet[])
{
    printf("\n\nVetor alterado:\n");
    for(int i=0; i<T; i++)
    {
        printf("[%d]", vet[i]);
    }
    printf("\n");
}

void main()
{
    int vet[T];


    lerVetor(vet);
    trocaPosicao(vet);
    exibir(vet);
}
