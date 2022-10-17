/*
10. Usando a Linguagem C:
a. Como voc� definiria o tipo fila usando a representa��o de lista simplesmente
encadeada? Considere, para isto, uma fila de pacientes de uma cl�nica m�dica
contendo os campos nome, idade, enfermidade.
b. Desenvolva a fun��o void fila_inicializa (CELULA** inicio, CELULA** fim)
c. Desenvolva a fun��o void fila_insereFim (CELULA** inicio, CELULA** fim,
Paciente x)
d. Na fun��o main() crie uma vari�vel do tipo Fila. Em seguida chame a fun��o
fila_inicializa e fila_insereFim.*/

#include <stdio.h>
#include<stdlib.h>

typedef struct sPaciente
{
    char nome[50];
    int idade;
    char enfermidade[50];
} PACIENTE;

typedef struct cell
{
    PACIENTE paciente;
    struct cell *next;
}
