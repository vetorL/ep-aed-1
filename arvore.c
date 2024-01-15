#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

Linha *cria_linha(char *texto_linha, int num_linha)
{
    Linha *line = (Linha *)malloc(sizeof(Linha));
    line->texto_linha = texto_linha;
    line->num_linha = num_linha;
    return line;
}

Elemento *cria_elemento(char *palavra, int num_ocorrencias, char *texto_linha, int num_linha)
{
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    e->palavra = palavra;
    e->num_ocorrencias = num_ocorrencias;
    e->linha = cria_linha(texto_linha, num_linha);
    return e;
}

Arvore *cria_arvore()
{

    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

bool insere_arvore(Arvore *arvore, NoAr *pai, Elemento *e, int lado)
{

    NoAr *novo = (NoAr *)malloc(sizeof(NoAr));

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

NoAr *busca_rec(NoAr *no, Elemento *e)
{

    NoAr *aux;

    if (no)
    {

        if (no->valor == e)
            return no;

        aux = busca_rec(no->esq, e);
        if (aux)
            return aux;

        return busca_rec(no->dir, e);
    }

    return NULL;
}

NoAr *busca_arvore(Arvore *arvore, Elemento *e)
{

    return busca_rec(arvore->raiz, e);
}

NoAr *encontra_pai(NoAr *raiz, NoAr *no)
{

    NoAr *aux;

    if (raiz)
    {

        if (raiz->esq == no)
            return raiz;
        if (raiz->dir == no)
            return raiz;

        aux = encontra_pai(raiz->esq, no);
        if (aux)
            return aux;

        return encontra_pai(raiz->dir, no);
    }

    return NULL;
}