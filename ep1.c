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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define TAMANHO 1000

int main(int argc, char ** argv){

	FILE * in;
	char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;
	double tempo_carregamento;

	if(argc == 3) {

		clock_t tic = clock();

		in = fopen(argv[1], "r");

		printf(">>>>> Carregando arquivo...\n");

		contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));

		while(in && fgets(linha, TAMANHO, in)){
			
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

			printf("linha %03d: '%s'\n", contador_linha + 1, linha);

			// fazemos uma copia do endereço que corresponde ao array de chars 
			// usado para armazenar cada linha lida do arquivo pois a função 'strsep' 
			// modifica o endereço do ponteiro a cada chamada feita a esta função (e 
			// não queremos que 'linha' deixe de apontar para o inicio do array).

			copia_ponteiro_linha = linha;

			while( (palavra = strsep(&copia_ponteiro_linha, " ")) ){

				// antes de guardar a palavra em algum tipo de estrutura usada
				// para implementar o índice, será necessário fazer uma copia
				// da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
				// substring dentro da string 'linha', e a cada nova linha lida
				// o conteúdo da linha anterior é sobreescrito.

				printf("\t\t'%s'\n", palavra);
			}

			contador_linha++;
		}

		printf(">>>>> Arquivo carregado!\n");

		clock_t toc = clock();

		tempo_carregamento = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000;

		// Mensagens iniciais
		printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);
		printf("Numero de linhas no arquivo: %d\n", contador_linha);
		printf("Tempo para carregar o arquivo e construir o indice: %f ms\n", tempo_carregamento);

		// Entrada
		bool continua = true;

		while(continua)
		{
			char entrada[100];
			char *token;

			// recebe a entrada e armazena
			printf("> ");
			fgets(entrada, 100, stdin);

			token = strtok(entrada, " ");			
			
			puts(token);

			if(strcmp(token, "fim\n") == 0) 
			{
				// caso a entrada seja "fim", encerra o programa
				return 0;
			}
			else if (strcmp(token, "busca") == 0)
			{
				token = strtok(NULL, "\n");
				puts(token);
				continue;
			}
			else 
			{
				continue;
			}
		}


		return 0;
	}

	return 1;
}