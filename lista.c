#include "lista.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Entrada
{
    char *palavra;
    int num_ocorrencias = 0;
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

ListaLigada *
cria_lista()
{
    ListaLigada *lista = (ListaLigada *)malloc(sizeof(ListaLigada));
    lista->cabeca = NULL;

    return lista;
}

void insere_lista(char *palavra)
{
    return;
}

int busca_lista(char *palavra)
{
    return 0;
}