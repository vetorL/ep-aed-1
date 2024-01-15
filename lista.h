typedef struct
{
    char *palavra;
    int num_ocorrencias;
} Entrada;

typedef struct _lin_
{
    char *texto_linha;
    int num_linha;
    struct _lin_ *proximo;
} Linha;

typedef struct _no_
{
    Entrada *entrada;
    Linha *linhas;
    struct _no_ *proximo;
} No;

typedef struct
{
    No *cabeca;
} ListaLigada;

ListaLigada *cria_lista();
No *cria_no(Entrada *entrada, char *texto_linha, int num_linha);
Entrada *cria_entrada(char *palavra);
void insere_lista(char *palavra, ListaLigada *lista, char *texto_linha, int num_linha);
int busca_lista(char *palavra, ListaLigada *lista);
void imprime_lista(ListaLigada *lista);
Linha *cria_linha(char *texto_linha, int num_linha);
void imprime_ocorrencias_lista(char *palavra, ListaLigada *lista);