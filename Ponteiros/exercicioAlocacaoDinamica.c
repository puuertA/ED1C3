#include <stdioh.>
#include <stdlib.h>

typedef struct sProduto
{
    int codProduto;
    char nomeProduto[50];
    int quantDisponivel;
    float precoVenda;
} PRODUTO;

PRODUTO encontraMaiorPrecoVenda()
{

}

void main()
{
    PRODUTO *P;
    int quantArmazenada;

    printf("\nQuantos produtos deseja armazenar?\n\n>>> ");
    scanf("%d", &quantArmazenada);

    P = (PRODUTO *)malloc(quantArmazenada * sizeof(PRODUTO));

    for(i=0; i<quantArmazenada; i++)
    {
        printf("\nCodigo\n\n>>> ");
        scanf("%d", &P[i].codProduto);

        printf("\nNome\n\n>>> ");
        gets(P[i].nomeProduto);

        printf("\nQuantidade Disponivel\n\n>>> ");
        scanf("%d", &P[i].quantDisponivel);

        printf("\nPreco de Venda\n\n>>> ");
        scanf("%f", &P[i].precoVenda);
    }

}
