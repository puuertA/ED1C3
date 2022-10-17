/*
10. Usando a Linguagem C:
a. Como você definiria o tipo fila usando a representação de lista simplesmente
encadeada? Considere, para isto, uma fila de pacientes de uma clínica médica
contendo os campos nome, idade, enfermidade.
b. Desenvolva a função void fila_inicializa (CELULA** inicio, CELULA** fim)
c. Desenvolva a função void fila_insereFim (CELULA** inicio, CELULA** fim,
Paciente x)
d. Na função main() crie uma variável do tipo Fila. Em seguida chame a função
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
