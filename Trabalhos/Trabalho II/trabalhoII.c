/*1. Para organizar o chá de cozinha de Maria Eduarda, sua irmã mais nova, Gabriela, enviou um
e-mail para todas as suas amigas convidando-as para se reunirem no salão de festa de sua casa. Ela
solicitou que cada convidada levasse junto com o presente uma receita culinária de sua preferência
para enriquecer o livro de receitas virtual que será dado para Maria Eduarda antes do dia do
casamento. Para facilitar a organização das receitas, Gabriela pediu a um(a) amigo(a) do curso de
Ciência da Computação (você!!!) que fizesse um programa em que fosse possível cadastrar
(ordenando pelo título) e exibir as receitas na tela do computador a qualquer momento que ela
quisesse. Foi solicitado também que este sistema ficasse pronto até o dia da festa, para que fosse
possível cada convidada cadastrar sua receita previamente. As informações solicitadas no momento
do cadastro deverão ser: título da receita, descrição dos ingredientes, tipo (doce ou salgado) e o
nome da pessoa que presenteou Maria Eduarda com a receita. Utilize os conceitos de lista
simplesmente encadeada para implementar uma solução para o problema acima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sReceita
{
    char titulo[50];
    char descricaoIngredientes[50];
    int tipo; // 1 doce, 2 salgada
    char nomePresente[50];
} RECEITA;

typedef struct cell
{
    RECEITA receita;
    struct cell *next;
} CELULA;

void init (CELULA **lista)
{
    *lista = NULL;
}

int vazia(CELULA *lista)
{
    if(lista == NULL) // "lista" é o endereço do primeiro nó da lista
        return 1;
    else
        return 0;
}

RECEITA ler()
{
    RECEITA receitaLida;
    printf("\nInsira o titulo da receita\n>>> ");
    fflush(stdin);
    scanf("%s", &receitaLida.titulo);
    printf("\nInsira a descricao dos ingredientes da receita\n>>> ");
    fflush(stdin);
    scanf("%s", receitaLida.descricaoIngredientes);
    printf("\nInsira o tipo da receita (1 - doce 2 - salgada)\n>>> ");
    fflush(stdin);
    scanf("%d", &receitaLida.tipo);
    printf("\nInsira o nome da pessoa que presenteou a receita\n>>> ");
    fflush(stdin);
    scanf("%s", &receitaLida.nomePresente);

    printf("\n");

    return receitaLida;
}

CELULA *getnode()
{
    return (CELULA*) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    free(q);
}

CELULA* inserirOrdenadamente(CELULA *lista)
{
    CELULA *atual = lista;
    CELULA *anterior = NULL;
    CELULA *q;

    q = getnode();
    if(q != NULL)
    {
        RECEITA r = ler();
        q->receita = r;
        q->next = NULL;

//        !vazia(atual) && strcmp(q->info.titulo_receita, atual->info.titulo_receita) > 0
// função strcmp compara duas strings
// retorna 0 se forem iguais
// retorna menor que 0 se o valor ASCI da primeira for menor que o da segunda
// retorna maior que 0 se o valor ASCI da primeira for maiorq que o da segunda
        while(atual != NULL && strcmp(r.titulo, atual->receita.titulo) > 0)
        {
            anterior = atual;
            atual = atual->next;
        }
        if(atual == lista)
        {
            q->next = lista;
            lista = q;
        }
        else
        {
            anterior->next = q;
            q->next = atual;
        }
        return lista;
    }
    else
    {
        printf("\nERRO na alocacao do nó.\n");
        return NULL;
    }
}

void exibeLista(CELULA *lista)
{
    CELULA *aux;
    aux = lista;

    while(aux != NULL)
    {
        printf("%s\t", aux->receita.titulo);
        printf("\n");
        aux = aux->next;
    }
    printf("\n");
}

void exibeListaDetalhada(CELULA *lista)
{
    CELULA *aux;
    aux = lista;

    while(aux != NULL)
    {
        printf("%s\t", aux->receita.titulo);
        printf("%s\t", aux->receita.descricaoIngredientes);
        printf("%d\t", aux->receita.tipo);
        printf("%s\t", aux->receita.nomePresente);
        printf("\n");
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
    CELULA *ptrLista;
    init(&ptrLista);

    int op;

    do
    {
        printf("\n+------------------------------------------------+");
        printf("\n|                  MENU RECEITAS                 |");
        printf("\n+------------------------------------------------+");
        printf("\n|1 - Cadastrar receita                           |");
        printf("\n|2 - Exibir lista de receitas pelo titulo        |");
        printf("\n|3 - Exibir receitas detalhadamente              |");
        printf("\n+------------------------------------------------+");

        printf("\n\nEscolha uma opcao\n>>> ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            ;
            ptrLista = inserirOrdenadamente(ptrLista);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 2:
            ;
            exibeLista(ptrLista);

            printf("\n");
            system("pause");
            system("clear||cls");
            break;

        case 3:
            ;
            exibeListaDetalhada(ptrLista);

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
