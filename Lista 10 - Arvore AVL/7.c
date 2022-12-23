/* Num sistema de arquivos, um catálogo de todos os arquivos é organizado como uma
árvore de busca binária. Cada nó denota um arquivo e especifica seu nome e, entre
outras coisas, a data de seu último acesso, codificada como um inteiro. Escreva um
programa que percorra a árvore e apague todos os arquivos cujos últimos acessos
tenham sido anteriores a uma certa data. As chaves do catálogo são os nomes dos
arquivos
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct arquivo
{
    char nome[50];
    int data;
} ARQUIVO;

typedef struct sNo
{
    ARQUIVO info;
    struct sNO *esq;
    struct sNO *dir;
} NO

void inicializar(NO **ptrRaiz)
{
    *ptrRaiz = NULL;
}

ARQUIVO ler()
{
    ARQUIVO arquivoLido;
    printf("\nInsira o nome do arquivo\n>>> ");
    fflush(stdin);
    scanf("%s", &arquivoLido.nome);
    printf("\nInsira a data do arquivo\n>>> ");
    fflush(stdin);
    scanf("%d", &arquivoLido.data);

    printf("\n");

    return arquivoLido;
}

void inserir(NO **ptrRaiz)
{
    if(*ptrRaiz == NULL)
    {
        *ptrRaiz = (NO*)malloc(sizeof(NO));
        (*ptrRaiz) -> esq = NULL;
        (*ptrRaiz) -> dir = NULL;
         ARQUIVO aa = ler();
        (*ptrRaiz) -> info = aa;
    }
    else
    {
        ARQUIVO ab = ler();
        if(strcmp(ab.nome, (*ptrRaiz)->info.nome) > 0)
        {
            inserir(&((*ptrRaiz)->esq), ab);
        }
        else
        {
            inserir(&((*ptrRaiz)->esq), ab);
        }
    }
}

void emOrdem(NO *ptrRaiz)
{
    if(ptrRaiz != NULL)
    {
        emOrdem(ptrRaiz->esq);
        printf("|%s|", ptrRaiz->info.nome);
        emOrdem(ptrRaiz->dir);
    }
}

void preOrdem(NO *ptrRaiz)
{
    if(ptrRaiz != NULL)
    {
        printf("|%s|", ptrRaiz->info.nome);
        emOrdem(ptrRaiz->esq);
        emOrdem(ptrRaiz->dir);
    }
}

void posOrdem(NO *ptrRaiz)
{
    if(ptrRaiz != NULL)
    {
        emOrdem(ptrRaiz->esq);
        emOrdem(ptrRaiz->dir);
        printf("|%s|", ptrRaiz->info.nome);
    }
}


void main()
{

}
