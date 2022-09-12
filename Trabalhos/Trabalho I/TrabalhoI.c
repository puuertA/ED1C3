/*1. Na cidade de Presidente Epit�cio o carnaval � uma festa que conta com a participa��o
de um grande n�mero de foli�es, incluindo moradores da cidade e visitantes de outras
localidades. A festa acontece na orla da cidade, que � ocupada por barracas para venda
de bebidas, lanches e artigos em geral. Para garantir o sucesso da festa, a prefeitura
define, todos os anos, um n�mero m�ximo de barracas que poder�o ser instaladas no
local da festa. Para o ano de 2019 foi prevista a instala��o de 50 barracas, as quais ser�o
alugadas pelos comerciantes interessados. Por�m, todo ano a prefeitura apresenta
dificuldades para gerenciar informa��es como, por exemplo: - n�mero de barracas
ocupadas e livres; - dados do locat�rio (nome, CPF); - situa��o dos alugu�is (pagos ou
n�o); - produtos que ser�o comercializados. Para facilitar o gerenciamento dessas
informa��es a prefeitura contratou os servi�os de uma empresa de TI para desenvolver
um programa na linguagem C que atenda as seguintes requisi��es, utilizando os
conceitos de lista est�tica:
a. Todas as barracas dever�o possuir uma identifica��o, bem como o nome e CPF
do locat�rio respons�vel pelo aluguel, situa��o do aluguel (pago ou n�o),
identifica��o do produto que ser� comercializado (1: bebida, 2: lanches, 3:
artigos em geral);
b. O aluguel de barracas dever� acontecer por ordem de chegada, ou seja, o
comerciante que chegar primeiro ficar� com a primeira barraca, o que chegar
na sequ�ncia ficar� com a segunda barraca e assim por diante;
c. Ao solicitar o aluguel de uma barraca, o locat�rio dever� fornecer ao funcion�rio
da prefeitura as informa��es necess�rias para cadastro (item (a));
d. O sistema dever� ser capaz de gerar os seguintes relat�rios:
i. Relat�rio com os dados dos locat�rios inadimplentes (pessoas que n�o
efetuaram o pagamento da reserva) exibindo a identifica��o da barraca;
ii. Relat�rio exibindo a lista de barracas livres e ocupadas (pelo n�mero de
identifica��o de cada barraca) apresentando ao final de cada listagem a
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
    printf("\nInsira a situa��o da barraca (1 - pago 2 - nao pago)\n>>> ");
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
