#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
} NO;

void inicializar(NO **ptrRaiz)
{
    *ptrRaiz = NULL;
}

void inserir(NO **ptrRaiz, int elem)
{
    if(*ptrRaiz == NULL)
    {
        *ptrRaiz = (NO*)malloc(sizeof(NO));
        (*ptrRaiz)->esq = NULL;
        (*ptrRaiz)->dir = NULL;
        (*ptrRaiz)->info = elem;
    }
    else
    {
        if(elem < ((*ptrRaiz)->info))
        {
            inserir(&((*ptrRaiz)->esq), elem);
        }
        else
        {
            inserir(&((*ptrRaiz)->dir), elem);
        }
    }
}

void emOrdem(NO *ptrRaiz)
{
    if(ptrRaiz != NULL)
    {
        emOrdem(ptrRaiz->esq);
        printf("|%d|", ptrRaiz->info);
        emOrdem(ptrRaiz->dir);
    }
}

void preOrdem(NO *ptrRaiz)
{
    if(ptrRaiz != NULL)
    {
        printf("|%d|", ptrRaiz->info);
        preOrdem(ptrRaiz->esq);
        preOrdem(ptrRaiz->dir);
    }
}

void posOrdem(NO *ptrRaiz)
{
    if(ptrRaiz != NULL)
    {
        posOrdem(ptrRaiz->esq);
        posOrdem(ptrRaiz->dir);
        printf("|%d|", ptrRaiz->info);
    }
}

int contarNos(NO *ptrRaiz)
{
    if(ptrRaiz == NULL)
        return 0;
    else
        return 1 + contarNos(ptrRaiz->esq) + contarNos(ptrRaiz->dir);
}

int contarFolhas(NO *ptrRaiz)
{
    if(ptrRaiz == NULL)
        return 0;
    if(ptrRaiz->esq == NULL && ptrRaiz->dir == NULL)
        return 1;
    return contarFolhas(ptrRaiz->esq) + contarFolhas(ptrRaiz->dir);
}

// função auxiliar para calcular a calcularAltura da arvore
int maior(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int calcularAltura(NO *ptrRaiz)
{
    if((ptrRaiz == NULL) || (ptrRaiz->esq == NULL && ptrRaiz->dir == NULL))
        return 0;
    else
        return 1 + maior(calcularAltura(ptrRaiz->esq), calcularAltura(ptrRaiz->dir));
}

NO* remover(NO *raiz, int elem)
{
    if(raiz == NULL)
        return NULL;
    else if(raiz->info > elem)
        raiz->esq = remover(raiz->esq, elem);
    else if(raiz->info < elem)
        raiz->dir = remover(raiz->dir, elem);
    else
    {
        if(raiz->esq == NULL && raiz->dir == NULL) /* não tem filhos (é folha) */
        {
            free(raiz);
            raiz = NULL;
        }
        else if(raiz->esq == NULL) /* tem filho na direita */
        {
            NO* temp = raiz;
            raiz = raiz->dir;
            free(raiz);
        }
        else if(raiz->dir == NULL)
        {
            NO* temp = raiz;
            raiz = raiz->esq;
            free(raiz);
        }
        else /* tem filho na direita e na esquerda */
        {
            NO* Pai = raiz;
            NO* Filho = raiz->esq;
            while(Filho->dir != NULL)
            {
                Pai = Filho;
                Filho = Filho->dir;
            }
            raiz->info = Filho->info; /* troca as informações do filho para a raiz */
            Filho->info = elem;
            raiz->esq = remover(raiz->esq, elem);
        }
    }
    return raiz;
}



void main()
{

    setlocale(LC_ALL,"");

    NO* n;
    inicializar(&n);

    int op,num, retorno;

    do
    {
        printf("\n+----------------------------+");
        printf("\n|            *Menu*          |");
        printf("\n+----------------------------+");
        printf("\n|1 - Inserir um elemento     |");
        printf("\n|2 - Apresentar em Pós-Ordem |");
        printf("\n|3 - Apresentar em Ordem     |");
        printf("\n|4 - Apresentar em Pré-Ordem |");
        printf("\n|5 - Contar Folhas           |");
        printf("\n|6 - Contar Nós              |");
        printf("\n|7 - Calcular Altura         |");
        printf("\n|8 - Remover um número       |");
        printf("\n|0 - Encerrar Programa       |");
        printf("\n+----------------------------+");
        printf("\nSelecione uma das opções>>> ");
        scanf("%d",&op);

        switch(op)
        {

        case 1:
            printf("\nInsira o número que deseja:");
            scanf("%d",&num);
            inserir(&n,num);
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 2:
            posOrdem(n);
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 3:
            emOrdem(n);
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 4:
            preOrdem(n);
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 5:
            printf("\nQuantidade de folhas: %d\n", contarFolhas(n));
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 6:
            printf("\nQuantidade de Nós: %d\n", contarNos(n));
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 7:
            printf("\nAltura da arvore: %d\n", calcularAltura(n));
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 8:
            printf("\nInsira o número que deseja remover:");
            scanf("%d",&num);
            remover(n,num);
            printf("\n");
            system("pause");
            system("clear||cls");
            break;
        case 0:
            printf("\nFim do Programa.\n");
            break;
        default:
            printf("\nComando Inválido.\n");
            break;
        }
    }
    while(op!=0);

}
