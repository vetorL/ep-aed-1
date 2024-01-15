#include "lista.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

ListaLigada *
cria_lista()
{
    ListaLigada *lista = (ListaLigada *)malloc(sizeof(ListaLigada));
    lista->cabeca = NULL;

    return lista;
}

No *cria_no(Entrada *entrada)
{
    No *no = (No *)malloc(sizeof(No));
    no->entrada = entrada;
    no->proximo = NULL;
    return no;
}

Entrada *
cria_entrada(char *palavra)
{
    Entrada *entrada = (Entrada *)malloc(sizeof(Entrada));
    entrada->palavra = palavra;
    entrada->num_ocorrencias = 1;
    return entrada;
}

void insere_lista(char *palavra, ListaLigada *lista)
{
    // Checar se existe palavra na lista
    if (lista->cabeca == NULL)
    {
        // Lista esta vazia

        // Cria entrada
        Entrada *entrada = cria_entrada(palavra);

        // Cria no
        No *no = cria_no(entrada);

        lista->cabeca = no;
    }
    else
    {
        // Lista ja tem palavra

        // Checar se a palavra ja foi anteriormente inserida
        No *atual = lista->cabeca;
        while (true)
        {
            if (strcmp(atual->entrada->palavra, palavra) == 0)
            {
                // Caso em que a palavra ja foi inserida
                atual->entrada->num_ocorrencias++;
                return;
            }
            else if (atual->proximo == NULL)
            {
                // Palavra nao foi encontrada, criar novo No
                Entrada *entrada = cria_entrada(palavra);
                No *no = cria_no(entrada);
                atual->proximo = no;
                return;
            }
            atual = atual->proximo;
        }
    }

    return;
}

int busca_lista(char *palavra, ListaLigada *lista)
{
    if (lista->cabeca == NULL)
    {
        // Lista esta vazia, portanto nao tem palavras
        return 0;
    }
    else
    {
        No *atual = lista->cabeca;
        while (true)
        {
            if (strcmp(atual->entrada->palavra, palavra) == 0)
            {
                // Palavra achada, retorna numero de ocorrencias
                return atual->entrada->num_ocorrencias;
            }
            else if (atual->proximo == NULL)
            {
                // Palavra nao foi encontrada, retorna zero
                return 0;
            }
            atual = atual->proximo;
        }
    }

    return 0;
}