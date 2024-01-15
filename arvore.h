#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1

typedef struct
{
    char *texto_linha;
    int num_linha;
} Linha;

typedef struct
{
    char *palavra;
    int num_ocorrencias;
    Linha *linha;
} Elemento;

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

bool insere_arvore(Arvore *arvore, No *pai, Elemento *e, int lado);
No *busca_arvore(Arvore *arvore, Elemento *e);
No *encontra_pai(No *raiz, No *no);
Elemento *cria_elemento(char *palavra, int num_ocorrencias, char *texto_linha, int num_linha);
Linha *cria_linha(char *texto_linha, int num_linha);
No *busca_rec(No *no, Elemento *e);