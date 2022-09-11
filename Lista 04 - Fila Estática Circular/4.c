/*
4. Escreva um programa em Linguagem C que seja capaz de inverter a ordem dos
elementos de uma fila utilizando uma pilha como estrutura auxiliar
*/

#include <stdio.h>
#include <stdlib.h>
#define T 10

typedef struct sFila
{
    int itens[T];
    int inicio, fim;
} FILA;

typedef struct sPilha
{
    int itens[T];
    int topo;
} PILHA;

void inicializarFila(FILA *F)
{
    F->inicio = T-1;
    F->fim = T-1;
}

void inicializarPilha(PILHA *p)
{
    p->topo = -1;
}

int vaziaFila(FILA *F)
{
    if(F->fim == F->inicio)
        return 1;
    else
        return 0;
}

int cheiaFila(FILA *F)
{
    if(F->fim == F->inicio)
        return 1;
    else
        return 0;
}

int vaziaPilha(PILHA *p)
{
    if(p->topo== -1)
        return 1;
    else
        return 0;
}

int cheiaPilha(PILHA *p)
{
    if (p->topo == T-1)
        return 1;
    else
        return 0;
}

void enfileirar(FILA *F, int elem)
{
    if(F->fim == (T-1)) // se tiver vazia
    {
        F->fim = 0; // define fim como 0
    }
    else // se não
    {
        F->fim++; // aumenta uma posição do fim
    }
    if(cheiaFila(F))
    {
        printf("\nERRO: Fila cheia!");
        F->fim--; // diminui uma posição do fim
        if(F->fim == -1) // se tiver vazia
            F->fim = T-1; // define o fim como o tamanho -1;
        return; // sai do if
    }
    F->itens[F->fim] = elem; // enfileira o elemento devidamente
}

int desenfileirar (FILA *F)
{
    int aux = 0; // cria um aux para retornar no final da função

    if(!vaziaFila(F)) // ve se não ta vazia pra poder tirar as coisa né
    {
        if(F->inicio == T-1) //se o inicio tiver em -1
        {
            F->inicio = 0; // passa ele pra 0 pra poder lidar
        }
        else // se não
        {
            F->inicio++; // aumentar uma posição do inicio
        }
        aux = F->itens[F->inicio]; //passa o valor que tiver no inicio pro auxiliar
    }
    else
    {
        printf("\nERRO: Fila vazia!");
    }
    return aux; // volta o valor que ta em aux, caso precise dele pra alguma outra coisa
}

void empilhar (PILHA *p, int val)
{
    if(cheiaPilha(p))
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

int desempilhar(PILHA *p)
{
    int aux;
    if(vaziaPilha(p))
    {
        printf("ERRO: pilha vazia\n");
        return -1;
    }
    else
    {
        aux = p->itens[p->topo];
        p->topo--;
    }

    return aux;
}

void imprimirNaoClassica (FILA *F)
{
    int i = (F->inicio+1) % T;
    if(!vaziaFila(F))
    {
        printf("Fila utilizando impressao nao classica");
        printf("\nFila: ");
        while(i!=((F->fim+1)% T))
        {
            printf("|%d|",F->itens[i]);
            i = (i+1) % T;
        }
    }
    else
        printf("\nERRO: Fila vazia!");
}

void exibe(PILHA *p)
{
    if(vaziaPilha(p))
    {
        printf("ERRO: pilha vazia.\n");
        return;
    }
    else
    {
        while(!vaziaPilha(p))
        {
            printf("[%d]", desempilhar(p));
        }
    }
}

int inverterFila(FILA *F, PILHA *P)
{
    if(vaziaFila(F))
    {
        printf("\nERRO: Fila vazia!");
    }
    else
    {
        while(!vaziaFila(F) && !cheiaPilha(P))
        {
            empilhar(P, desenfileirar(F));
        }

        printf("\n\nPilha preenchida com os elementos da fila!\n");
        system("pause");
        printf("Passando os elementos da pilha de volta para a fila");

        while(!vaziaPilha(P))
        {
            enfileirar(F, desempilhar(P));
        }
        imprimirNaoClassica(F);
    }
}

int main()
{
    FILA F;
    PILHA P;
    inicializarFila(&F);
    inicializarPilha(&P);

    enfileirar(&F, 1);
    enfileirar(&F, 2);
    enfileirar(&F, 3);
    enfileirar(&F, 4);
    enfileirar(&F, 5);

    imprimirNaoClassica(&F);

    inverterFila(&F, &P);
}
