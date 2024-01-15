#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// #include <string.h>
// #include <math.h>

// bool __debug__ = false;
// void debug_on() { __debug__ = true; }
// void debug_off() { __debug__ = false; }

// #define ROWS 20
// #define COLS 80

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

// int display_rec(char **buffer, NoAr *no, int level, double h_position)
// {

//     char *ptr;
//     int i, col, a, b;
//     double offset;

//     if (no)
//     {
//         col = (int)(h_position * COLS);
//         offset = 1.0 / pow(2, level + 2);

//         ptr = buffer[1 + level * 3] + col;
//         sprintf(ptr, "%s", no->valor->palavra);
//         *(ptr + strlen(ptr)) = ' ';

//         if (no->esq || no->dir)
//             *(buffer[2 + level * 3] + col + 1) = '|';

//         if (no->esq)
//         {

//             i = (int)((h_position - offset) * COLS);
//             *(buffer[3 + level * 3] + 1 + i) = '|';
//             i++;
//             for (; i <= col; i++)
//                 *(buffer[3 + level * 3] + 1 + i) = '-';
//         }

//         if (no->dir)
//         {

//             for (i = col; i < (int)((h_position + offset) * COLS); i++)
//                 *(buffer[3 + level * 3] + 1 + i) = '-';
//             *(buffer[3 + level * 3] + 1 + i) = '|';
//         }

//         a = display_rec(buffer, no->esq, level + 1, h_position - offset);
//         b = display_rec(buffer, no->dir, level + 1, h_position + offset);

//         if (a > b)
//             return a;
//         return b;
//     }

//     return level;
// }

// void display_no(NoAr *no)
// {

//     int i, j, r;

//     char **buffer = (char **)malloc(ROWS * sizeof(char *));

//     for (i = 0; i < ROWS; i++)
//     {

//         buffer[i] = (char *)malloc((COLS + 1) * sizeof(char));

//         for (j = 0; j < COLS; j++)
//             buffer[i][j] = ' ';
//         buffer[i][j] = '\0';
//     }

//     r = display_rec(buffer, no, 0, 0.5);

//     if (__debug__)
//         getchar();

//     for (i = 0; i < 3 * r; i++)
//         printf("%s\n", buffer[i]);
//     printf("-----------------------------------------------------------------------------------------------\n");
// }

// void display(Arvore *arvore)
// {

//     display_no(arvore->raiz);
// }