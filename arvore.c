#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>

Arvore *cria_arvore()
{

    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

bool insere_arvore(Arvore *arvore, No *pai, Elemento e, int lado)
{

    No *novo = (No *)malloc(sizeof(No));

    novo->valor = e;
    novo->esq = novo->dir = NULL;

    if (!busca_arvore(arvore, e))
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

No *busca_rec(No *no, Elemento e)
{

    No *aux;

    if (no)
    {

        if (__debug__)
            display_no(no);

        if (no->valor == e)
            return no;

        aux = busca_rec(no->esq, e);
        if (aux)
            return aux;

        return busca_rec(no->dir, e);
    }

    return NULL;
}

No *busca_arvore(Arvore *arvore, Elemento e)
{

    return busca_rec(arvore->raiz, e);
}