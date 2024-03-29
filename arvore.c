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
    line->proximo = NULL;
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
        NoAr *no_1 = busca_arvore(arvore, e->palavra);
        no_1->valor->num_ocorrencias += 1;
        LinhaAr *linha_atual = no_1->valor->linha;
        while (true)
        {
            if (linha_atual->num_linha == num_linha)
            {
                // linha ja esta presente
                return false;
            }
            if (linha_atual->proximo == NULL)
            {
                linha_atual->proximo = cria_linha_ar(texto_linha, num_linha);
                return false;
            }
            linha_atual = linha_atual->proximo;
        }
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
    LinhaAr *linha_atual = busca_arvore(arvore, palavra)->valor->linha;
    while (true)
    {
        if (linha_atual->proximo == NULL)
        {
            printf("%05d: %s\n", linha_atual->num_linha, linha_atual->texto_linha);
            return;
        }
        printf("%05d: %s\n", linha_atual->num_linha, linha_atual->texto_linha);
        linha_atual = linha_atual->proximo;
    }
    return;
}