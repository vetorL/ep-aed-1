#include "lista.h"
#include <stdio.h>
#include <stdbool.h>

struct Entrada
{
    char *palavra;
    int num_ocorrencias;
}

struct No
{
    Entrada *e;
    No *proximo;
}

struct ListaLigada
{
    No *cabeca;
}

void
insere_lista(char *palavra)
{
    return;
}

bool busca_lista(char *palavra)
{
    return false;
}