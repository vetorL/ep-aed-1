#include "arvore.c"

typedef struct _no_arvore_
{

    Elemento valor;
    struct _no_arvore_ *esq;
    struct _no_arvore_ *dir;

} No;

typedef struct
{

    No *raiz;

} Arvore;

void insere_arvore(char *palavra);
bool busca_arvore(char *palavra);
