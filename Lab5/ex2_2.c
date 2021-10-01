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

const int intervalo = 25;		// Intervalo de sorteio de valores

void faz_vetor(int vetor[], int quantidade);
void mostra_vetor(int vetor[], int quantidade);
void conta_tempo(char mensagem[], int tempo);
int jogo(char jogador[]);

int main(void) {

	// Erro que sera retornado pela funcao jogo.
	int erro1;
	int erro2;

	// Obtendo o nome dos jogadores
	char jogador1[20];
	char jogador2[20];

	// Apresentando o jogo para o usuario --------------------------------------------------------------------
	printf("SEJAM BEM VINDOS AO JOGO DA MEMORIA\n");
	printf("Para iniciar, insiram seus nomes...\n");
	
	printf("Jogador 1: ");
	scanf("%s", jogador1);

	printf("Jogador 2: ");
	scanf("%s", jogador2);

	printf("Ola, %s e %s\n", jogador1, jogador2);
	printf("\n---------------REGRAS--------------\n");
	printf("Neste jogo existem 4 rodadas, nas\nquais os jogadores devem decorar\numa determinada sequencia de\nnumeros, e, depois, informa-los.\n");
	printf("Cada jogador, jogara as rodadas de\numa vez, iniciando por %s\ne depois, sendo jogada por %s.\n", jogador1, jogador2);
	printf("-----------------------------------\n");

	printf("\nBOA SORTE A QUEM JOGAR!\n");

	conta_tempo("----------------------- ", 20);
	// -------------------------------------------------------------------------------------------------------

	clear();

	// Preparando o jogador 1
	printf("%s, seu jogo comeca em ", jogador1);
	conta_tempo("\t\t\t\t", 5);

	clear();

	erro1 = jogo(jogador1);

	clear();

	// Preparando o jogador 2
	printf("%s, seu jogo comeca em: ", jogador2);
	conta_tempo("\t\t\t\t", 5);

	clear();

	erro2 = jogo(jogador2);

	// Mostrando os resultados.
	conta_tempo("Verificando resultados ", 5);

	printf("\nAcertos de %s: %d / 21\n", jogador1, (21 - erro1));
	printf("\nAcertos de %s: %d / 21\n", jogador2, (21 - erro2));

	// Criterios - quem acertou mais, ganha. Se acertarem
	// a mesma quantidade de numeros ha empate.
	if (erro1 < erro2) {
		printf("\n%s Venceu\n", jogador1);
	}
	else if (erro1 > erro2) {
		printf("\n%s Venceu\n", jogador2);
	}
	else {
		printf("Empate entre %s e %s\n", jogador1, jogador2);
	}

}

void faz_vetor(int vetor[], int quantidade) {

	/*
		Produz um vetor com numeros aleatorios
		que variam de 0 a 24
	*/

	srand((unsigned) clock());

	for (int i = 0; i < quantidade; i++) {
		vetor[i] = rand() % intervalo;
	}

}

void mostra_vetor(int vetor[], int quantidade) {
	/*
		Mostra o vetor quando precisar
	*/

	for (int i = 0; i < quantidade; i++) {
		printf("%d\t", vetor[i]);
	}
	printf("\n");
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
}

int jogo(char jogador[]) {

	/*
		Eferivamente a funcao que realoza o jogo.
		Seu retorno e o numero de erros do usuario
		que variam de 0 a 21 (numero maximo de erros)

		:jogador: nome de quem joga

		:quantidade: quantidade de numeros mostrada na rodada.
			Inicia com 2 e vai crescendo conforme o jogo avanca
			da deguinte forma - 2 -> 4 -> 6 -> 9

		:aux: auxiliar para pegar os dados do usuario.

		:erro: valor retornado. A cada erro cometido, o valor
			eh acrescido de um.
	*/

	int quantidade;
	int aux;
	int erro = 0;

	int vetor[9];

	for (quantidade = 2; quantidade < 10; quantidade+= 2) {

		printf("Rodada %d / 4 de %s\n", (quantidade / 2), jogador);

		faz_vetor(vetor, quantidade);

		mostra_vetor(vetor, quantidade);

		conta_tempo("Faltam: ", (quantidade / 2) * 4);		// 4 8 12 16

		clear();

		printf("Rodada %d / 4 de %s\n", (quantidade / 2), jogador);

		printf("Agora, %s, tente adivinhar os numeros\n", jogador);

		for (int k = 0; k < quantidade; k++) {

			printf("Elemento %i: ", k);
			scanf("%i", &aux);

			if (aux != vetor[k]) {
				erro++;
			}
		}

		printf("Vetor original: \n");
		mostra_vetor(vetor, quantidade);
		conta_tempo("Proxima rodada em: ", 5);

		clear();

		if (quantidade == 6) {
			quantidade++;
		}
	}
	return erro;
}

