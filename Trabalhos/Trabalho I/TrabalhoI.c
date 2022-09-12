/*1. Na cidade de Presidente Epitácio o carnaval é uma festa que conta com a participação
de um grande número de foliões, incluindo moradores da cidade e visitantes de outras
localidades. A festa acontece na orla da cidade, que é ocupada por barracas para venda
de bebidas, lanches e artigos em geral. Para garantir o sucesso da festa, a prefeitura
define, todos os anos, um número máximo de barracas que poderão ser instaladas no
local da festa. Para o ano de 2019 foi prevista a instalação de 50 barracas, as quais serão
alugadas pelos comerciantes interessados. Porém, todo ano a prefeitura apresenta
dificuldades para gerenciar informações como, por exemplo: - número de barracas
ocupadas e livres; - dados do locatário (nome, CPF); - situação dos aluguéis (pagos ou
não); - produtos que serão comercializados. Para facilitar o gerenciamento dessas
informações a prefeitura contratou os serviços de uma empresa de TI para desenvolver
um programa na linguagem C que atenda as seguintes requisições, utilizando os
conceitos de lista estática:
a. Todas as barracas deverão possuir uma identificação, bem como o nome e CPF
do locatário responsável pelo aluguel, situação do aluguel (pago ou não),
identificação do produto que será comercializado (1: bebida, 2: lanches, 3:
artigos em geral);
b. O aluguel de barracas deverá acontecer por ordem de chegada, ou seja, o
comerciante que chegar primeiro ficará com a primeira barraca, o que chegar
na sequência ficará com a segunda barraca e assim por diante;
c. Ao solicitar o aluguel de uma barraca, o locatário deverá fornecer ao funcionário
da prefeitura as informações necessárias para cadastro (item (a));
d. O sistema deverá ser capaz de gerar os seguintes relatórios:
i. Relatório com os dados dos locatários inadimplentes (pessoas que não
efetuaram o pagamento da reserva) exibindo a identificação da barraca;
ii. Relatório exibindo a lista de barracas livres e ocupadas (pelo número de
identificação de cada barraca) apresentando ao final de cada listagem a
soma total.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 50

typedef struct sBarraca
{
    int idBarraca;
    char nomeLocatario[50];
    char cpfLocatario[14];
    int situacaoAluguel;
    int produtoComercializado;
} BARRACA;

typedef struct sLista
{
    BARRACA barraca[T];
    int n;
} LISTA;

void listaInicializar(LISTA *L)
{
    L->n = -1;
}

int vazia(LISTA *L)
{
    if(L->n == -1)
        return 1;
    else
        return 0;
}

int cheia(LISTA *L)
{
    if(L->n + 1 == T)
        return 1;
    else
        return 0;
}

BARRACA ler()
{

    BARRACA barracaLida;
    printf("\nInsira o nome do locatario\n>>> ");
    fflush(stdin);
    scanf("%s", &barracaLida.nomeLocatario);
    printf("\nInsira o cpf do locatario\n>>> ");
    scanf("%s", barracaLida.cpfLocatario);
    printf("\nInsira a situação da barraca (1 - pago 2 - nao pago)\n>>> ");
    fflush(stdin);
    scanf("%d", &barracaLida.situacaoAluguel);
    printf("\nInsira o tipo de produto (1: bebida, 2: lanches, 3: artigos em geral)\n>>> ");
    scanf("%d", &barracaLida.produtoComercializado);

    printf("\n");

    return barracaLida;
}

int inserirFim(LISTA *L)
{
    if(cheia(L))
    {
        printf("\nERRO: Lista cheia!");
    }
    else
    {
    L->n++;
    BARRACA b = ler();
    L->barraca[L->n]= b;
    }
}

void relatorioInadiplentes(LISTA *L)
{
    int i;
    BARRACA b;
    printf("\nBarracas inadiplentes: ");
    for(i = 0; i<=(L->n); i++)
    {
        b = L->barraca[i];
        if(b.situacaoAluguel == 2)
        {
            printf("\nBarraca: %d", i+1);
            printf("\nNome: %s", b.nomeLocatario);
            printf("\n");
        }
    }
    printf("\n");
}

void relatorioBarracas(LISTA *L)
{
    int i;
    printf("\n\nBarracas ocupadas:\n");
    for(i=1; i<=(L->n+1); i++)
    {
        printf("|%d|", i);
    }
    printf("\nTotal: %d", L->n+1);

    printf("\n\nBarracas livres:\n");
    for(i=(L->n+2); i<=T; i++)
    {
        printf("|%d|", i);
    }
    printf("\nTotal: %d", T-(L->n+1));

    printf("\n");
}

int menu()
{
    LISTA L; // declara variavel do tipo lista
    listaInicializar(&L);
    int op;

    do
    {
        printf("\n+-------------------------------------+");
        printf("\n|              MENU BARRACA           |");
        printf("\n+-------------------------------------+");
        printf("\n|1 - Cadastrar Barraca                |");
        printf("\n|2 - Exibir barracas inadinplentes    |");
        printf("\n|3 - Exibir barracas ocupadas e livres|");
        printf("\n+-------------------------------------+");

        printf("\n\nEscolha uma opcao\n>>> ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            ;
            inserirFim(&L);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 2:
            ;
            relatorioInadiplentes(&L);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 3:
            ;
            relatorioBarracas(&L);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 4:
            ;

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 5:
            ;

            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        default:
            ;
            printf("\nInsira uma opcao valida");
        }
    }
    while(op!=0);
}

int main()
{
    menu();
}
