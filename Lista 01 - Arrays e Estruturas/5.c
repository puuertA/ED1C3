/*
5. Considere um cadastro de produtos de um estoque, com as seguintes informações para
cada produto:
- Código de identificação do produto: representado por um valor inteiro;
- Nome do produto: com até 50 caracteres;
- Quantidade disponível no estoque: representado por um número inteiro;
- Preço de venda: representado por um valor real.
a. Defina uma estrutura em C, denominada produto, que tenha os campos
apropriados para guardar as informações de um produto;
b. Crie um conjunto de 10 produtos e peça ao usuário para entrar com as
informações de cada produto;
c. Encontre o produto com o maior preço de venda;
d. Encontre o produto com a maior quantidade disponível no estoque.
Nota: Faça um menu para acesso à cada função. */

#include <stdio.h>
#define T 10

typedef struct sProduto
{
    int codigo;
    char nome[50];
    int qtd;
    float preco;
} Produto;

int menu()
{
    int op;
    printf("\n+---------------------------------------------------------+");
    printf("\n|                 SISTEMA DE GERENCIAMENTO                |\n|                         DE ESTOQUE                      |");
    printf("\n+---------------------------------------------------------+");
    printf("\n|                                                         |");
    printf("\n|         Gerenciamento de produtos                       |");
    printf("\n|                                                         |");
    printf("\n|[1] - Realizar o cadastro de 10 produtos                 |");
    printf("\n|[2] - Encontrar o produto com maior preco de venda       |");
    printf("\n|[3] - Encontrar o produto com maior quantidade disponivel|");
    printf("\n|[4] - Mostrar todos os produtos cadastrados              |");
    printf("\n|[0] - Sair                                               |");
    printf("\n+---------------------------------------------------------+");

    printf("\n\nDigite a opcao\n>>> ");
    fflush(stdin);
    scanf("%d", &op);
    return op;
}

void cadastrarProdutos(Produto prod[])
{
    for(int i=0; i < T; i++ )
    {
        printf("\nPRODUTO [%d]", i+1);
        printf("\nInsira o codigo do produto\n>>> ");
        scanf("%d", &prod[i].codigo);
        printf("Insira o nome do produto\n>>> ");
        fflush(stdin);
        scanf("%s", &prod[i].nome);
        fflush(stdin);
        printf("Insira o preco do produto\n>>> ");
        fflush(stdin);
        scanf("%f", &prod[i].preco);
        printf("Insira a quantidade do produto\n>>> ");
        fflush(stdin);
        scanf("%d", &prod[i].qtd);

        system("cls");
    }
}

void buscaMaiorPreco(Produto prod[])
{
    float maior;
    int pos;
    for(int i=0; i < T; i++)
    {
        if(i == 0)
        {
            maior = prod[0].preco;
            pos = 0;
        }
        else
        {
            if(maior < prod[i].preco)
            {
                maior = prod[i].preco;
                pos = i;
            }
        }
    }
    apresentar(prod, pos);
}

void buscaMaiorQtd(Produto prod[])
{
    int pos, maior;
    for(int i=0; i < T; i++)
    {
        if(i == 0)
        {
            maior = prod[0].qtd;
            pos = 0;
        }
        else
        {
            if(maior < prod[i].qtd)
            {
                maior = prod[i].qtd;
                pos = i;
            }
        }
    }
    apresentar(prod, pos);
}

void apresentar(Produto prod[], int pos)
{
    printf("\nCodigo: \nProduto: \nNome:%s \nRS: %.2f\nQuantidade: %d", prod[pos].codigo, prod[pos].nome, prod[pos].preco, prod[pos].qtd);
}

void apresentarTodos(Produto prod[])
{
    int i;
    for(i=0; i<T; i++)
    {
        printf("\nCodigo: \nProduto: \nNome:%s \nRS: %.2f\nQuantidade: %d", prod[i].codigo, prod[i].nome, prod[i].preco, prod[i].qtd);
    }
}

void main()
{
    Produto prod[T];
    int posicaoMenorPreco, posicaoMaiorQtd, op = 0;
    do
    {
        switch (op)
        {
        case 1:
            system("cls");
            cadastrarProdutos(prod);
            break;
        case 2:
            system("cls");
            buscaMaiorPreco(prod);
            break;
        case 3:
            system("cls");
            buscaMaiorQtd(prod);
            break;
        case 4:
            system("cls");
            apresentarTodos(prod);
            break;
        default:
            printf("\nOpcao Invalida");
            break;
        }
        op = menu();
    }
    while(op!=0);
}
