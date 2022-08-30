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
#define 10

typedef struct sPilha{
    int itens[TAMMAX];
    int topo;
} PILHA;

void inicializar(PILHA *p)
{
    p->topo = -1;
}

int vazia(PILHA *p)
{
    if(topo == -1)
        return 1;
    else
        return 0;
}

void cheia(PILHA *p)
{
    if(topo == TAMMAX -1)
        return 1;
    else
        return 0;
}

void empilhar(PILHA *p, int val){

}
