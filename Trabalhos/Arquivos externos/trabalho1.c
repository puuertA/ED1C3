/* 1. Considerando um programa em linguagem C que armazene em uma pilha P os seguintes
dados: nome, idade e sexo. A partir desta pilha, codifique uma função que seja capaz de
gerar duas outras pilhas: PF e PM, contendo, cada uma: nome e idade, sendo que a pilha
PF armazena dados das pessoas femininas e a pilha PM das masculinas. Após este
processo, exiba o conteúdo das duas pilhas. Crie, também, um programa que seja capaz
de simular a execução desta função. */

#include <stdio.h>
#include <string.h>
#define TAMMAX 3

typedef struct sPilha
{
    char nome[30];
    int idade;
    char sexo;
    int topo;
} PILHA;

typedef struct mPilha
{
    char nome[TAMMAX];
    int idade[TAMMAX];
    char sexo[TAMMAX];
    int topo;
} PILHAM;

typedef struct fPilha
{
    char nome[TAMMAX];
    int idade[TAMMAX];
    char sexo[TAMMAX];
    int topo;
} PILHAF;

void inicializar(PILHA *p)
{
    p->topo = -1;
}

int vazia(PILHA *p)
{
    if(p->topo == -1)
        return 1;
    return 0;
}

int cheia(PILHA *p)
{
    if(p->topo == TAMMAX - 1)
        return 1;
    return 0;
}

void empilhar(PILHA *p, char letra)
{
    if(cheia(p))
    {
        printf("Pilha cheia!!!");
        return;
    }
    p->topo++;
    p->nome[p->topo] = letra;
}

char desempilhar(PILHA *p)
{
    char temp;
    if(vazia(p))
    {
        printf("Pilha vazia!!!");
        return;
    }
    temp = p->nome[p->topo];
    p->topo--;
    return temp;
}

char ver_topo(PILHA *p)
{
    if(vazia(p))
        printf("Pilha vazia");
    else
        return p->nome[p->topo];

}

void separaPilhas(PILHA *p)
{
    PILHAM m;
    PILHAF f;

    int i;

    for(i=0; i<TAMMAX; i++)
    {
        if(p->sexo == 'M')
        {
        }
        else if(p->sexo == 'F')
        {
        }
    }

}

void main()
{
    int i;
    PILHA p[TAMMAX];
    PILHAM m[TAMMAX];
    PILHAF f[TAMMAX];
    inicializar(&p);

    for(i=0; i<TAMMAX; i++)
    {
        printf("Digite o nome: ");
        scanf("%s",&p->nome);

        fflush(stdin);
        printf("Digite a idade: ");
        scanf("%d",&p->idade);

        fflush(stdin);
        printf("Digite o sexo (M/F): ");
        scanf("%c",&p->sexo);
    }

    for(i=0; i<=TAMMAX; i++)
    {
        printf("\n%s - %d - %c", p->nome, p->idade, p->sexo);
    }


    void separaPilhas();





}
