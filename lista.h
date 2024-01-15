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

void insere_lista(char *palavra);
int busca_lista(char *palavra);
