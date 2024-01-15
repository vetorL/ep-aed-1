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
Entrada *cria_entrada();
void insere_lista(char *palavra);
int busca_lista(char *palavra);
