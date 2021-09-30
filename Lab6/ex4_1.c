#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iterativa(int n, int vetor[]);
int recursiva(int vetor[], int n);

int main(void)
{
	int arr[30];
	int menor1, menor2;
	clock_t start, end;

	srand((unsigned) clock());

	//Preenchendo o vetor
	for (int i = 0; i < 30; i++)
	{
		// Valores de 0 a 99
		arr[i] = rand() % 100;
	}

	// Primeiro, testa a funcao iterativa
	start = clock();
	menor1 = iterativa(30, arr);
	printf("Menor 1: %d\n", menor1);
	end = clock();
	printf("Tempo levado: %f\n", ((double) end - start) / CLOCKS_PER_SEC);

	// Agora, testa a funcao recursiva
	start = clock();
	menor2 = recursiva(arr, 30);
	printf("\nMenor 2: %d\n", menor2);
	end = clock();
	printf("Tempo levado: %f\n", ((double) end - start) / CLOCKS_PER_SEC);

	// Percebo que a funcao recursiva gasta mais tempo para encontrar o menor valor
	// Isso se deve, provavelmente, porque a funcao recursiva envolve diveras chamadas
	// de funcao.

	return 0;
}


int iterativa(int n, int vetor[])
{
	int menor;
	menor = vetor[0];

	for (int i = 1; i < n; i++)
	{
		if (vetor[i] < menor)
		{
			menor = vetor[i];
		}
	}

	return menor;
}


int recursiva(int vetor[], int n)
{
	if (n == 1)
	{
		return vetor[0];
	}
	
	if (vetor[n - 1] < recursiva(vetor, n - 1))
	{
		return vetor[n - 1];
	}
	else
	{
		return recursiva(vetor, n - 1);
	}
}