// Membros do grupo:
// ==========
// Nome: Karen Miyuki Massuda
// Número USP: 14585868
// Turma: 04
// ==========
// Nome: Vivian Ayumi Miamura
// Número USP: 14835140
// Turma: 94
// ==========
// Nome: Vítor Benvenisti Laguna Navarenho
// Número USP: 14749425
// Turma: 94
// ==========

#include "filtra.h"
#include "lista.h"
#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define TAMANHO 1000

bool busca(char *palavra, char *indice);
void insere(char *palavra, char *indice, char *texto_linha, int num_linha);

ListaLigada *lista;
Arvore *arvore;

int main(int argc, char **argv)
{

	FILE *in;
	char *linha;
	char *copia_ponteiro_linha;
	char *quebra_de_linha;
	char *palavra;
	int contador_linha;
	double tempo_carregamento;

	if (argc == 3)
	{

		// Inicia a contagem do tempo de execução
		clock_t tic = clock();

		in = fopen(argv[1], "r");

		// Identifica a estrutura a ser utilizada
		if (strcmp(argv[2], "arvore") == 0)
		{
			// Cria arvore
			arvore = cria_arvore();
		}
		else if (strcmp(argv[2], "lista") == 0)
		{
			// Cria lista
			lista = cria_lista();
		}
		else
		{
			printf("'%s' não é uma opção válida!\n", argv[2]);
			return 1;
		}

		// Mensagens iniciais sobre os argumentos utilizados
		printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);

		contador_linha = 0;
		linha = (char *)malloc((TAMANHO + 1) * sizeof(char));

		while (in && fgets(linha, TAMANHO, in))
		{

			if ((quebra_de_linha = strrchr(linha, '\n')))
				*quebra_de_linha = 0;

			char *linha_copia = strdup(linha);

			// fazemos uma copia do endereço que corresponde ao array de chars
			// usado para armazenar cada linha lida do arquivo pois a função 'strsep'
			// modifica o endereço do ponteiro a cada chamada feita a esta função (e
			// não queremos que 'linha' deixe de apontar para o inicio do array).

			copia_ponteiro_linha = linha;

			while ((palavra = strsep(&copia_ponteiro_linha, " .,-/")))
			{

				// antes de guardar a palavra em algum tipo de estrutura usada
				// para implementar o índice, será necessário fazer uma copia
				// da mesma, uma vez que o ponteiro 'palavra' aponta para uma
				// substring dentro da string 'linha', e a cada nova linha lida
				// o conteúdo da linha anterior é sobreescrito.

				// Filtra palavra
				bool palavra_vazia = filtra(palavra);

				if (palavra_vazia)
				{
					continue;
				}

				char *copia_ponteiro_palavra = strdup(palavra);

				// insere a palavra na estrutura
				insere(copia_ponteiro_palavra, argv[2], linha_copia, contador_linha + 1);
			}

			contador_linha++;
		}

		// Termina a contagem do tempo de execução
		clock_t toc = clock();

		tempo_carregamento = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000;

		// Mensagens iniciais sobre o arquivo e a execucao do codigo
		printf("Numero de linhas no arquivo: %d\n", contador_linha);
		printf("Tempo para carregar o arquivo e construir o indice: %f ms\n", tempo_carregamento);

		// Entrada
		bool continua = true;

		while (continua)
		{
			char entrada[100];
			char *comando;

			// recebe a entrada e armazena
			printf("> ");
			fgets(entrada, 100, stdin);

			// pega primeira palavra da string (primeiro token)
			comando = strtok(entrada, " ");

			if (strcmp(comando, "fim\n") == 0)
			{
				// caso a entrada seja "fim", encerra o programa
				return 0;
			}
			else if (strcmp(comando, "busca") == 0)
			{
				// caso o comando seja "busca", obter segundo token
				// (segunda palavra da string)

				// obtem palavra a ser buscada
				char *palavra;
				palavra = strtok(NULL, "\n");

				// busca pela palavra
				busca(palavra, argv[2]);

				continue;
			}
			else
			{
				printf("Opcao invalida!\n");
				continue;
			}
		}

		return 0;
	}

	return 1;
}

bool busca(char *palavra, char *indice)
{
	int ocorrencias = 0;

	// Inicia a contagem do tempo de busca
	clock_t tic = clock();

	if (strcmp(indice, "lista") == 0)
	{
		ocorrencias = busca_lista(palavra, lista);

		// Imprime no terminal de acordo com o resultado
		if (ocorrencias)
		{
			printf("Existem %d ocorrências da palavra '%s' na(s) seguinte(s) linha(s):\n", ocorrencias, palavra);
			imprime_ocorrencias_lista(palavra, lista);
		}
		else
		{
			printf("Palavra '%s' nao encontrada.\n", palavra);
		}
	}
	else if (strcmp(indice, "arvore") == 0)
	{
		NoAr *no = busca_arvore(arvore, palavra);
		if (no)
		{
			if (strcmp(no->valor->palavra, palavra) == 0)
			{
				ocorrencias = no->valor->num_ocorrencias;
			}
			// Imprime no terminal de acordo com o resultado
			if (ocorrencias)
			{
				printf("Existem %d ocorrências da palavra '%s' na(s) seguinte(s) linha(s):\n", ocorrencias, palavra);
				imprime_ocorrencias_arvore(arvore, palavra);
			}
			else
			{
				printf("Palavra '%s' nao encontrada.\n", palavra);
			}
		}
	}

	// Termina a contagem do tempo de busca
	clock_t toc = clock();

	// calcula o tempo de busca
	double tempo_busca;
	tempo_busca = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000;

	printf("Tempo de busca: %f ms\n", tempo_busca);

	if (ocorrencias)
	{
		return true;
	}

	return false;
}

void insere(char *palavra, char *indice, char *texto_linha, int num_linha)
{
	if (strcmp(indice, "lista") == 0)
	{
		insere_lista(palavra, lista, texto_linha, num_linha);
	}
	else if (strcmp(indice, "arvore") == 0)
	{
		insere_arvore(arvore, palavra, texto_linha, num_linha);
	}

	return;
}