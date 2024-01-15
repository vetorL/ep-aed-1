typedef struct
{
    char *palavra;
    int num_ocorrencias;
} Entrada;

typedef struct
{
    Entrada *entrada;
    No *proximo;
} No;

typedef struct
{
    No *cabeca;
} ListaLigada;

Entrada *cria_lista();
No *cria_no(Entrada *entrada);
Entrada *cria_entrada(char *palavra);
void insere_lista(char *palavra, ListaLigada *lista);
int busca_lista(char *palavra);
