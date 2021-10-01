/*
	Nivel 1 - 4 x 3
	Nivel 2 - 5 x 4
	Nivel 3 - 6 x 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
	#include <Windows.h>
	#define clear() system("cls")
	#define sleep(x) Sleep(x)
#else
	#include <unistd.h>
	#define clear() system("clear")
#endif

void random_index(int nivel, int vetor_indices[][2]);
void cria_baralho(int nivel, int matriz_principal[2][nivel + 4][nivel + 3]);
void conta_tempo(char mensagem[], int tempo);
void mostra_baralho(int nivel, int mat[2][nivel + 4][nivel + 3]);
char getch(char maximo, char* mensagem);
int jogo(int nivel, int matriz[2][nivel + 4][nivel + 3]);

int main(void) {

	int nivel;

	printf("Seja bem vindo ao jogo da memoria\n");
	printf("Neste jogo, lhe sera apresentado um baralho deste tipo\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0 && j == 0) {
				printf("   ");
			}
			else if (i == 0) {
				printf("%c  ", (char) 64 + j);
			}
			else if (j == 0) {
				printf("%c  ", (char) 64 + i);
			}
			else {
				printf("%c  ", '|');
			}
		}
		printf("\n");
	}

	printf("E lhe serao perguntadas duas coordenadas.\n");
	printf("Primeiramente das linhas (A, B, C, ...)\n");
	printf("Depois das colunas...\n");
	printf("Depois de ser perguntado duas vezes, voce podera comparar as opcoes que escolheu.\n");
	printf("Se forem iguais, o numero permanece fixo no baralho\n");
	printf("Se nao, viram-se as cartas.\n");
	printf("Ao final, voce vera quantas tentativas precisou, e seu baralho completo.\n");

	conta_tempo("Leia: ", 20);

	clear();

	printf("Escolha um nivel (1 - Facil; 2 - Medio; 3 - Dificil): ");
	scanf("%d", &nivel);

	int mat[2][nivel + 4][nivel + 3];
	cria_baralho(nivel, mat);

	int tent = jogo(nivel, mat);

	printf("Voce terminou o jogo com %d tentativas\n", tent);
	mostra_baralho(nivel, mat);
	printf("Este era seu baralho\n");


	return 0;
}

void random_index(int nivel, int vetor_indices[][2]) {

	/*
		Esta funcao eh responsavel por criar um vetor com todas as coordenadas em ordem
		e, depois de criada, desarranja de maneira aleatoria todos os vetores dentro do
		vetor principal.
	*/

	int linhas = nivel + 3;										// linhas da matriz
	int colunas = nivel + 2;									// colunas da matriz
	int tamanho_vetor_indices = linhas * colunas;				// basicamente, a quantidade de coordenadas da matriz
	int cte = 0;												// auxiliar para gerar o vetor ordenado

	int aux;													// indice da coordenada sorteada
	int temp[2];												// temporario, para alocar uma coordenada anterior

	time_t t;													// Para a semente do gerador de numeros aleatorios

	// Alocando oa coordenadas em ordem
	for (int i = 0; i < linhas; i++) {

		for (int k = cte, n = cte + colunas; k < n; k++) {

			vetor_indices[k][0] = i + 1;
			vetor_indices[k][1] = (k % colunas) + 1;

		}
		cte += colunas;
	}

	// Desarranjo do vetor
	srand((unsigned) time(&t));

	for (int i = 0; i < tamanho_vetor_indices; i++) {

		aux = (rand() % (tamanho_vetor_indices - i)) + i;

		// Neste caso, se o valor sorteado for igual ao indice atual, 
		// o programa entende que este deve ficar ali mesmo
		if (aux == i) {
			continue;
		}

		// Fazendo a troca
		temp[0] = vetor_indices[i][0];
		temp[1] = vetor_indices[i][1];

		vetor_indices[i][0] = vetor_indices[aux][0];
		vetor_indices[i][1] = vetor_indices[aux][1];

		vetor_indices[aux][0] = temp[0];
		vetor_indices[aux][1] = temp[1];
	}
}


void cria_baralho(int nivel, int matriz_principal[2][nivel + 4][nivel + 3]) {

	int linhas = nivel + 3;
	int colunas = nivel + 2;
	
	int coordenadas[linhas * colunas][2];
	random_index(nivel, coordenadas);

	int valor_maximo_possivel = (linhas * colunas);     		// Ate onde vai esses numeros

	// Criando um baralho mostravel para o usuario
	for (int i = 1; i <= colunas; i++) {

		matriz_principal[0][0][i] =  (char) 64 + i;
		matriz_principal[1][0][i] =  (char) 64 + i;
	}

	for (int i = 1; i <= linhas; i++) {

		for (int j = 1; j <= colunas; j++) {

			matriz_principal[0][i][j] = (char) 124;
		}
	}

	// Criando a outra matriz com os numeros
	for (int i = 1; i <= linhas; i++) {

		matriz_principal[0][i][0] = (char) 64 + i;
		matriz_principal[1][i][0] = (char) 64 + i;
	}

	for (int i = 0; i < valor_maximo_possivel; i++) {

		matriz_principal[1][coordenadas[i][0]][coordenadas[i][1]] = ((i / 2));
	}
}


void mostra_baralho(int nivel, int mat[2][nivel + 4][nivel + 3]) {

	for (int i = 0; i < nivel + 4; i++) {
		for (int j = 0; j < nivel + 3; j++) {
			
			if (i == 0 && j == 0) {
				printf("%3c", (char) 32);
			}
			else if (i == 0) {
				printf("%3c", (char) mat[0][i][j]);
			}
			else if (j == 0) {
				printf("%3c", (char) mat[0][i][j]);
			}
			else {
				if (mat[0][i][j] == 124) {
					printf("%3c", (char) mat[0][i][j]);
				}
				else {
					printf("%3i", mat[0][i][j]);
				}
			}

		}
		printf("\n");
	}

	printf("\n\n");
}


void conta_tempo(char mensagem[], int tempo) {

	/*
		Esta funcao existe para criar um timer
		atrativo para a tela de um jogo
	*/

	printf("\n%s: ", mensagem);
	for (int i = tempo; i > 0; i--) {
		printf("%i", i);
		sleep(1000);

		if (i >= 10) {
			printf("\b\b");

			if (i == 10) {
				printf(" ");
			}
		}
		else {
			printf("\b");
		}
	}

	printf("\n");
}

char getch(char maximo, char* mensagem) {

	char c1;
	char vazamento;

	while (1) {

		vazamento = getchar();

		printf("\n%s", mensagem);
		c1 = getchar();

		if (c1 > 96 && c1 < 123) {

			c1 = c1 - 32;
			if (c1 > maximo) {
				printf("\nInvalido\n");
			}
			else {
				return c1;
			}
		}
		else if (c1 > 64 && c1 < 91) {

			if (c1 > maximo) {
				printf("\nInvalido\n");
			}
			else {
				return c1;
			}
		}
		else {
			printf("\nInvalido\n");
		}
	}
}

int jogo(int nivel, int matriz[2][nivel + 4][nivel + 3]) {

	/*Retorna o numero de tentativas feitas pelo jogador*/

	int match = 0;
	int tentativas = 0;											// Valor que sera retornado pela funcao

	int linhas = nivel + 4;										// Total de linhas da matriz que compoe o baralho
	int colunas = nivel + 3;									// Total de colunas da matriz que compoe o baralho
	int total_matches = ((linhas - 1) * (colunas - 1)) / 2; 	// Total de acertos que o usuario pode ter

	char linhas_maximo = 63 + linhas;							// Coordenada maxima das linhas
	char colunas_maximo = 63 + colunas;							// Coordenada maxima das colunas

	char coord_linha1;
	char coord_coluna1;

	char coord_linha2;
	char coord_coluna2;

	while (match < total_matches) {

		tentativas++;

		mostra_baralho(nivel, matriz);

		coord_linha1 = getch(linhas_maximo, "Decida em qual linha (A, B, C, ...): ");
		coord_coluna1 =  getch(colunas_maximo, "Decida em qual coluna (A, B, C, ...): ");

		if (matriz[0][coord_linha1 - 64][coord_coluna1 - 64] == matriz[1][coord_linha1 - 64][coord_coluna1 - 64]) {
			printf("\nVoce ja descobriu esta coordenada\n");
			conta_tempo(" ", 2);
			clear();
			continue;
		}

		clear();

		matriz[0][coord_linha1 - 64][coord_coluna1 - 64] = (int) matriz[1][coord_linha1 - 64][coord_coluna1 - 64];

		mostra_baralho(nivel, matriz);

		coord_linha2 = getch(linhas_maximo, "Decida em qual linha (A, B, C, ...): ");
		coord_coluna2 =  getch(colunas_maximo, "Decida em qual coluna (A, B, C, ...): ");

		if ((coord_linha1 == coord_linha2) && (coord_coluna1 == coord_coluna2)) {
			printf("Esta voce ja descobriu\n");
			matriz[0][coord_linha1 - 64][coord_coluna1 - 64] = '|';
			conta_tempo(" ", 2);
			clear();
			continue;
		}

		if (matriz[0][coord_linha2 - 64][coord_coluna2 - 64] == matriz[1][coord_linha2 - 64][coord_coluna2 - 64]) {
			matriz[0][coord_linha1 - 64][coord_coluna1 - 64] = '|';
			printf("\nVoce ja descobriu esta coordenada\n");
			conta_tempo(" ", 2);
			clear();
			continue;
		}

		matriz[0][coord_linha2 - 64][coord_coluna2 - 64] = (int) matriz[1][coord_linha2 - 64][coord_coluna2 - 64];

		clear();

		mostra_baralho(nivel, matriz);

		conta_tempo("Observe: ", 3);

		if (matriz[0][coord_linha1 - 64][coord_coluna1 - 64] == matriz[0][coord_linha2 - 64][coord_coluna2 - 64]) {
			printf("\nAcertou uma\n");
			match++;
		}
		else {
			printf("\nErrou\n");
			matriz[0][coord_linha1 - 64][coord_coluna1 - 64] = '|';
			matriz[0][coord_linha2 - 64][coord_coluna2 - 64] = '|';
		}

		conta_tempo(" ", 3);
		clear();
	}

	return tentativas;
}