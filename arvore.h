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

bool insere(Arvore *arvore, No *pai, Elemento e, int lado);
void insere_arvore(char *palavra);
bool busca_arvore(char *palavra);
