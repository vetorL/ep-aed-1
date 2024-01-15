typedef struct
{
    char *palavra;
    int num_ocorrencias;
} Entrada;

typedef struct _no_
{
    Entrada *entrada;
    struct _no_ *proximo;
} No;

typedef struct
{
    No *cabeca;
} ListaLigada;

ListaLigada *cria_lista();
No *cria_no(Entrada *entrada);
Entrada *cria_entrada(char *palavra);
void insere_lista(char *palavra, ListaLigada *lista);
int busca_lista(char *palavra, ListaLigada *lista);
void imprime_lista(ListaLigada *lista);
