/*
3. Codifique, compile e execute um programa que seja capaz de ler do usuário diversos
números e, para cada um destes, realizar as seguintes operações:
a. se positivo, inserir na pilha P;
b. se negativo, inserir na pilha N;
c. se zero, retirar um elemento de cada pilha.
Obs: Devem ser declaradas duas pilhas N e P que sejam capazes de armazenar
valores positivos e negativos, respectivamente.
*/

#include <stdio.h>
#define T 10

typedef struct sPilha
{
    int itens[T];
    int topo;
} PILHA;

void inicializar(PILHA *P)
{
    P->topo = -1;
}

int vazia(PILHA *P)
{
    if(P->topo == -1)
        return 1;
    else
        return 0;
}

int cheia(PILHA *P)
{
    if(P->topo == T - 1)
        return 1;
    else
        return 0;
}

int empilhar(PILHA *P, int elem)
{
    if(cheia(P))
    {
        printf("\nERRO: Pilha cheia!");
        return 1;
    }
    else
    {
        P->topo++;
        P->itens[P->topo] = elem;
    }
}

int desempilhar(PILHA *P)
{
    int aux;
    if(vazia(P))
    {
        printf("\nERRO: Pilha vazia!");
        return 1;
    }
    else
    {
        aux = P->itens[P->topo]; // guarda em aux oque esta no topo;
        P->topo--; // diminui uma posição do topo;
        return aux; // retorna aux caso precisar usar em alguma outra função (por exemplo imprimir)
    }
}

int retornaTopo(PILHA *P)
{
    if(vazia(P))
    {
        printf("\nERRO: Pilha vazia!");
        return 1;

    }
    else
    {
        return P->itens[P->topo];
    }
}

int imprimir(PILHA *P)
{
    if(vazia(P))
    {
        printf("\ERRO: Pilha vazia!, impossivel imprimir");
        return 1;
    }
    else
    {
        printf("\nExibindo pilha estatica:\n\n");
        while(!vazia(P))
        {
            printf("\n[%d]", desempilhar(P));
        }
    }
}

int verificaPositivoENegativo(PILHA *P, PILHA *N, int elem)
{
    if(elem > 0)
    {
        empilhar(P, elem);
    }
    else if(elem == 0)
    {
        desempilhar(P);
        desempilhar(N);
    }
    else
    {
        empilhar(N, elem);
    }
}

int main()
{
    PILHA P;
    PILHA N;
    inicializar(&P);
    inicializar(&N);
    int i,valor;

    for(i=0;i<T;i++)
    {
        printf("Indique o valor %d\n>>> ", i+1);
        scanf("%d", &valor);
        verificaPositivoENegativo(&P, &N, valor);
    }

    printf("\n\nPilhas após as verificacoes: \n");
    imprimir(&P);
    imprimir(&N);
}
