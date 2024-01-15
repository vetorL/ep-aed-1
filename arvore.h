#include <stdbool.h>
#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1

typedef struct _xin_
{
    char *texto_linha;
    int num_linha;
    struct _xin_ *proximo;
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
bool insere_arvore(Arvore *arvore, char *palavra, char *texto_linha, int num_linha);
void imprime_ocorrencias_arvore(Arvore *arvore, char *palavra);
NoAr *busca_arvore(Arvore *arvore, char *palavra);
Elemento *cria_elemento(char *palavra, char *texto_linha, int num_linha);
LinhaAr *cria_linha_ar(char *texto_linha, int num_linha);
// void display(Arvore *arvore);
NoAr *busca_rec(NoAr *no, char *palavra);