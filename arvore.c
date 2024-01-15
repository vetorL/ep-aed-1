#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>

Arvore *cria_arvore()
{

    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

bool insere(Arvore *arvore, No *pai, Elemento e, int lado)
{

    No *novo = (No *)malloc(sizeof(No));

    novo->valor = e;
    novo->esq = novo->dir = NULL;

    if (!busca(arvore, e))
    {

        if (pai)
        {

            if (lado == ESQUERDO)
            {

                novo->esq = pai->esq;
                pai->esq = novo;
            }
            else
            {

                novo->esq = pai->dir;
                pai->dir = novo;
            }
        }
        else
        {
            novo->esq = arvore->raiz;
            arvore->raiz = novo;
        }

        return true;
    }

    return false;
}

void insere_arvore(char *palavra)
{
    return;
}

bool busca_arvore(char *palavra)
{
    return false;
}