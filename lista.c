#include "lista.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

ListaLigada *
cria_lista()
{
    ListaLigada *lista = (ListaLigada *)malloc(sizeof(ListaLigada));
    lista->cabeca = NULL;

    return lista;
}

Entrada *
cria_entrada(char *palavra)
{
    Entrada *entrada = (Entrada *)malloc(sizeof(Entrada));
    entrada->palavra = palavra;
    entrada->num_ocorrencias = 0;
    return entrada;
}

void insere_lista(char *palavra)
{
    return;
}

int busca_lista(char *palavra)
{
    return 0;
}