/*3. Leia um vetor de 10 posições e em seguida um valor X qualquer. Seu programa deverá
fazer uma busca do valor de X no vetor lido e informar a posição em que foi encontrado
ou se não foi encontrado.*/

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

void buscaXEApresenta(int vet[], int x)
{
    int controle;
    for(int i=0; i<T; i++)
    {
        if(vet[i]==x)
        {
            controle == true;
            printf("\nX encontrado na posicao %d", i+1);
        }
    }
    if(controle==false)
    {
        printf("\nX nao foi encontrado");
    }
}

void main()
{
    int vet[T], x;


    lerVetor(vet);
    x = lerX();
    buscaXEApresenta(vet, x);
}
