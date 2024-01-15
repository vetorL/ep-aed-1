#include <stdbool.h>
#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1

typedef struct
{
    char *texto_linha;
    int num_linha;
} LinhaAr;

typedef struct
{
    char *palavra;
    int num_ocorrencias;
    LinhaAr *linha;
} Elemento;

typedef struct _no_arvore_
{

    Elemento *valor;
    struct _no_arvore_ *esq;
    struct _no_arvore_ *dir;

} NoAr;

typedef struct
{

    NoAr *raiz;

} Arvore;

Arvore *cria_arvore();
bool insere_arvore(Arvore *arvore, NoAr *pai, Elemento *e, int lado);
NoAr *busca_arvore(Arvore *arvore, char *palavra);
NoAr *encontra_pai(NoAr *raiz, NoAr *no);
Elemento *cria_elemento(char *palavra, int num_ocorrencias, char *texto_linha, int num_linha);
LinhaAr *cria_linha_ar(char *texto_linha, int num_linha);
// void display(Arvore *arvore);
NoAr *busca_rec(NoAr *no, char *palavra);