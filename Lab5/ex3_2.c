/*
	Nessa segunda versao, nao havera niveis,
	simplesmente, o jogador ira decidir quantos pares de numeros quer
	que apareca.
	Se for par, sera uma matriz 4xA, senao, 2xA
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
void cria_baralho(int pares, int matriz_principal[2][(pares % 2 == 0) ? 5: 3][((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1]);
void conta_tempo(char mensagem[], int tempo);
void mostra_baralho(int pares, int mat[2][(pares % 2 == 0) ? 5: 3][((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1]);
char getch(char maximo, char* mensagem);
int jogo(int pares, int matriz[2][(pares % 2 == 0) ? 5: 3][((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1]);

int main(void) {

	int pares;

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

	printf("Quantos pares quer que apareca? ");
	scanf("%d", &pares);

	if (pares < 2) {
		printf("Pequeno numero de pares\n");
		return 1;
	}

	int linhas = (pares % 2 == 0) ? 4: 2;

	int linhas_matriz = linhas + 1;
	int colunas_matriz = ((pares * 2) / linhas) + 1;

	int mat[2][linhas_matriz][colunas_matriz];
	cria_baralho(pares, mat);

	int tent = jogo(pares, mat);

	printf("Voce terminou o jogo com %d tentativas\n", tent);
	mostra_baralho(pares, mat);
	printf("Este era seu baralho\n");


	return 0;
}

void random_index(int pares, int vetor_indices[][2]) {

	/*
		Esta funcao eh responsavel por criar um vetor com todas as coordenadas em ordem
		e, depois de criada, desarranja de maneira aleatoria todos os vetores dentro do
		vetor principal.
	*/

	int linhas = (pares % 2 == 0) ? 4: 2;
	int colunas = (pares * 2) / linhas;

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


void cria_baralho(int pares, int matriz_principal[2][(pares % 2 == 0) ? 5: 3][((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1]) {

	int linhas = (pares % 2 == 0) ? 5: 3;
	int colunas = ((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1;

	int coordenadas[linhas * colunas][2];
	random_index(pares, coordenadas);

	int valor_maximo_possivel = (linhas - 1) * (colunas - 1);    		// Valor limite para o par

	// Criando um baralho mostravel para o usuario
	for (int i = 1; i <= colunas; i++) {

		matriz_principal[0][0][i] = (char) 64 + i;
		matriz_principal[1][0][i] = (char) 64 + i;
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

		matriz_principal[1][coordenadas[i][0]][coordenadas[i][1]] = (i / 2);
	}
}


void mostra_baralho(int pares, int mat[2][(pares % 2 == 0) ? 5: 3][((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1]) {

	int linhas = (pares % 2 == 0) ? 5: 3;
	int colunas = ((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1;

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			
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

int jogo(int pares, int matriz[2][(pares % 2 == 0) ? 4: 3][((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1]) {

	/*Retorna o numero de tentativas feitas pelo jogador*/

	int match = 0;
	int tentativas = 0;												// Valor que sera retornado pela funcao

	int linhas = (pares % 2 == 0) ? 5: 3;							// Total de linhas da matriz que compoe o baralho
	int colunas = ((pares * 2) / ((pares % 2 == 0) ? 4: 2)) + 1;	// Total de colunas da matriz que compoe o baralho
	int total_matches = ((linhas - 1) * (colunas - 1)) / 2; 		// Total de acertos que o usuario pode ter

	char linhas_maximo = 63 + linhas;								// Coordenada maxima das linhas
	char colunas_maximo = 63 + colunas;								// Coordenada maxima das colunas

	char coord_linha1;
	char coord_coluna1;

	char coord_linha2;
	char coord_coluna2;

	while (match < total_matches) {

		tentativas++;

		mostra_baralho(pares, matriz);

		coord_linha1 = getch(linhas_maximo, "Decida em qual linha (A, B, C, ...): ");
		coord_coluna1 =  getch(colunas_maximo, "Decida em qual coluna (A, B, C, ...): ");

		if (matriz[0][coord_linha1 - 64][coord_coluna1 - 64] >= 0 && matriz[0][coord_linha1 - 64][coord_coluna1 - 64] <= (pares - 1)) {
			matriz[0][coord_linha1 - 64][coord_coluna1 - 64] = '|';
			printf("\nVoce ja descobriu esta coordenada\n");
			conta_tempo(" ", 2);
			clear();
			continue;
		}

		clear();

		matriz[0][coord_linha1 - 64][coord_coluna1 - 64] = matriz[1][coord_linha1 - 63][coord_coluna1 - 64];

		mostra_baralho(pares, matriz);

		coord_linha2 = getch(linhas_maximo, "Decida em qual linha (A, B, C, ...): ");
		coord_coluna2 = getch(colunas_maximo, "Decida em qual coluna (A, B, C, ...): ");


		if (matriz[0][coord_linha2 - 64][coord_coluna2 - 64] >= 0 && matriz[0][coord_linha2 - 64][coord_coluna2 - 64] <= (pares - 1)) {
			matriz[0][coord_linha1 - 64][coord_coluna1 - 64] = '|';
			matriz[0][coord_linha2 - 64][coord_coluna2 - 64] = '|';
			printf("\nVoce ja descobriu esta coordenada\n");
			conta_tempo(" ", 2);
			clear();
			continue;
		}

		matriz[0][coord_linha2 - 64][coord_coluna2 - 64] = matriz[1][coord_linha2 - 63][coord_coluna2 - 64];

		clear();

		mostra_baralho(pares, matriz);

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