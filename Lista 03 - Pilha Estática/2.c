/* 2. Codifique, compile e execute um programa que seja capaz de ler 15 números informados pelo usuário e proceda, para cada um deles, como segue:
a. se o número for par, insira-o na pilha;
b. se o número lido for ímpar, retire um número da pilha;
c. Ao final, esvazie a pilha imprimindo os elementos. */

#include <stdio.h>
#define TAMMAX 15

typedef struct sPilha
{
    int itens[TAMMAX];
    int topo;
} PILHA;

void inicializar(PILHA *p)
{
    p->topo = -1;
}

int vazia(PILHA *p)
{
    if(p->topo== -1)
        return 1;
    else
        return 0;
}

int cheia (PILHA *p)
{
    if (p->topo == TAMMAX-1)
        return 1;
    else
        return 0;
}

void empilhar (PILHA *p, int val)
{
    if(cheia(p))
    {
        printf("ERRO: pilha cheia.\n");
        return;
    }
    else
    {
        ++p->topo;
        p->itens[p->topo] = val;
    }
}

int desempilha (PILHA *p)
{
    int aux;
    if(vazia(p))
    {
        printf("ERRO: pilha vazia\n");
        return -1;
    }
    else
    {
        aux = p->itens[p->topo];
        p->topo--;
        return aux;
    }
}

int retornaTopo (PILHA *p)
{
    if(vazia(p))
    {
        printf("ERRO: pilha vazia.\n");
        return -1;
    }
    else
    {
        return p->itens[p->topo];
    }
}

// exibindo na gambiarra
/*void exibeGambiarra(PILHA *p){
    int i;
    if(vazia(p))
    {
        printf("ERRO: pilha vazia.\n");

    }
    else
    {
        for(i=(p->topo); i>=0; i--)
        {
            printf("\n|%d|", p->itens[i]);
        }
    }
}
*/

void exibe(PILHA *p)
{
    if(vazia(p))
    {
        printf("ERRO: pilha vazia.\n");
        return;
    }
    else
    {
        while(!vazia(p))
        {
            printf("[%d]", desempilha(p));
        }
    }
}

int verificarPar(PILHA *p, int valor){
        if(valor % 2 == 0)
        {
            empilhar(p, valor);
        }
        else
        {
            desempilha(p);
        }
}

int main()
{
    PILHA p;
    inicializar(&p);
    int valor, i;

    for(i=0;i<TAMMAX;i++)
    {
        printf("Indique o valor %d\n>>> ", i+1);
        scanf("%d", &valor);
        verificarPar(&p, valor);
    }
    exibe(&p);
}
