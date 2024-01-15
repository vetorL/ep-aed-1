#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

LinhaAr *cria_linha_ar(char *texto_linha, int num_linha)
{
    LinhaAr *line = (LinhaAr *)malloc(sizeof(LinhaAr));
    line->texto_linha = texto_linha;
    line->num_linha = num_linha;
    return line;
}

Elemento *cria_elemento(char *palavra, char *texto_linha, int num_linha)
{
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    e->palavra = palavra;
    e->num_ocorrencias = 1;
    e->linha = cria_linha_ar(texto_linha, num_linha);
    return e;
}

Arvore *cria_arvore()
{

    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

bool insere_arvore(Arvore *arvore, char *palavra, char *texto_linha, int num_linha)
{
    Elemento *e = cria_elemento(palavra, texto_linha, num_linha);

    NoAr *pai = NULL;

    int lado = DIREITO;

    NoAr *novo = (NoAr *)malloc(sizeof(NoAr));

    novo->valor = e;
    novo->esq = novo->dir = NULL;

    if (!busca_arvore(arvore, e->palavra))
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
    else
    {
        busca_arvore(arvore, e->palavra)->valor->num_ocorrencias += 1;
    }

    return false;
}

NoAr *busca_rec(NoAr *no, char *palavra)
{

    NoAr *aux;

    if (no)
    {

        if (strcmp(no->valor->palavra, palavra) == 0)
            return no;

        aux = busca_rec(no->esq, palavra);
        if (aux)
            return aux;

        return busca_rec(no->dir, palavra);
    }

    return NULL;
}

NoAr *busca_arvore(Arvore *arvore, char *palavra)
{

    return busca_rec(arvore->raiz, palavra);
}

void imprime_ocorrencias_arvore(Arvore *arvore, char *palavra)
{
    NoAr *no = busca_arvore(arvore, palavra);
    printf("%05d: %s\n", no->valor->linha->num_linha, no->valor->linha->texto_linha);
    return;
}