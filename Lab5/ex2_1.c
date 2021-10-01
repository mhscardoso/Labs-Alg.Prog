#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
	#include <Windows.h>
	#define sleep(x) Sleep(x)
	#define clear() system("cls")
#else
	#include <unistd.h>
	#define clear() system("clear")
#endif

// 5 rodadas para todos os niveis
const int RODADAS = 5;

// Definindo os intervalo de valores para cada nivel
const int INTERVALO_FACIL   = 15;		// 0 - 14
const int INTERVALO_MEDIO   = 25;		// 0 - 24
const int INTERVALO_DIFICIL = 35;		// 0 - 34

int tamanho;							// Armazenara o necessario para o vetor

int escolher_nivel();
int faz_vetor(int vetor[], int quantidade, int intervalo);
void mostra_vetor(int vetor[], int qtd);
void conta_tempo();

int main(void){

	/*
		Este jogo possui 3 niveis de dificuldade:
			Facil
				- Numeros sorteados variam de 0 a 14
				- Quantidade maxima de numeros = 10
				- 5 rodadas: 2; 4; 6; 8; 10
			Medio
				- Numeros sorteados variam de 0 a 24
				- Quantidade maxima de numeros = 12
				- 5 rodadas: 2; 4; 6; 9; 12
			Dificil
				- Numeros sorteados variam de 0 a 34
				- Quantidade maxima de numeros = 
				- 5 rodadas: 3; 6; 9; 12; 15
	*/

	int nivel = escolher_nivel();
	int vetor[tamanho];				// Vetor com os numeroa a serem decorados
	int num;						// Armazena o numero lido
	int qtd;						// Quantidade de numeros que aparecerao em cada rodada
	int avanco;						// O quanto a quantidade acima, aumenta
	int intervalo;					// Os numeros sorteados irao variar de 0 ate este valor

	if (nivel == 1) {
		qtd = avanco = 2;
		intervalo = INTERVALO_FACIL;
	}
	else if (nivel == 2) {
		qtd = avanco = 2;
		intervalo = INTERVALO_MEDIO;
	}
	else if (nivel == 3) {
		qtd = avanco = 3;
		intervalo = INTERVALO_DIFICIL;
	}
	else {
		return 0;
	}

	for (int i = 0; i < RODADAS; i++) {

		printf("\nRodada %i\n", i + 1);

		faz_vetor(vetor, qtd, intervalo);

		mostra_vetor(vetor, qtd);

		conta_tempo((i + 1) * 4);

		clear();

		// Pergunta ao usuario os numeros
		for (int k = 0; k < qtd; k++) {
			printf("Elemento %d: ", k);
			scanf("%d", &num);

			// Se errar, o jogo acaba
			if (num != vetor[k]) {

				printf("ERROU!\n");
				printf("O vetor original eh:\n");
				mostra_vetor(vetor, qtd);
				return 0;
			}
		}

		clear();

		// Caso especifico para o nivel medio
		if (nivel == 2 && qtd == 6) {
			avanco++;
		}

		// Aumenta o nivel, conforme seguem as rodadas
		qtd += avanco;

		printf("OK\n");
	}

	printf("Parabens, voce conseguiu!\n");

	return 0;
}


int escolher_nivel() {
	/*
	Esta funcao retorna o nivel escolhido pelo usuario e
	altera a variavel global, tamanho, para que o array
	tenha o tamanho necessario.
	*/

	int n;

	do {
		printf("Decida o nivel (1 - Facil; 2 - Medio; 3 - Dificil; 0 - SAIR): ");
		scanf("%d", &n);

		switch (n) {
			case 0:
				printf("Sinto pela sua memoria!\n");
				return 0;

			case 1:
				printf("Voce escolheu o modo FACIL!\n");
				tamanho = 10;								// A qtd. maxima de valores, aqui sera de 10
				return 1;

			case 2:
				printf("Voce escolheu o modo MEDIO!\n");
				tamanho = 12;								// A qtd. maxima de valores, aqui sera de 12
				return 2;

			case 3:
				printf("Voce escolheu o modo DIFICIL!\n");
				tamanho = 15;								// A qtd. maxima de valores, aqui sera de 15
				return 3;

			default:
				printf("\nPrecisa melhorar sua memoria, isto nao representa nenhuma das opcoes!\n");
		}

	} while ((n != 0) && (n != 1) && (n != 2) && (n != 3));
}

int faz_vetor(int vetor[], int quantidade, int intervalo) {
	/*
	Funcao que fara um vetor de numeros aleatorios na quantidade
	certa de acordo com o nivel.
	*/

	srand((unsigned) clock());

	for (int i = 0; i < quantidade; i++) {

		// Aloca um nomero aleatorio na posicao i
		vetor[i] = rand() % intervalo;
	}	
}

void mostra_vetor(int vetor[], int qtd) {
	/*
	Apenas uma rapida chamada de funcao para mostrar o vetor ao jogador
	*/

	for (int i = 0; i < qtd; i++) {

		printf("%i\t", vetor[i]);
	}
	printf("\n");
}

void conta_tempo(int tempo) {
	/*
	Mostrando o tempo restante que o jogador tem para decorar os numeros
	*/

	printf("Tempo faltando: ");

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
}
