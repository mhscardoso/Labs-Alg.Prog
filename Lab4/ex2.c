/*Escreva um programa em C para (i) ler dois vetores ordenados em
ordem crescente de n ((ii) n informado pelo usuário e valendo até
100) números reais, e (iii) gerar um vetor de 2n elementos ordenado
em ordem crescente, (iv) contendo os elementos dos dois vetores
originais.*/

#include <stdio.h>
#define MAX 100

int main(void)
{
	int n, count_a, count_b;
	int vet_a[MAX];
	int vet_b[MAX];
	int vetor[2 * MAX];
	count_a = count_b = 0;

	printf("Digite a quantidade (0 - 100): ");
	scanf("%i", &n);

	if (n < 0 || n > 100)
	{
		printf("Invalido\n");
		return 1;
	}

	// Lendo o primeiro vetor
	printf("Primeiro Vetor:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i: ", i + 1);
		scanf("%i", &vet_a[i]);
	}

	// Lendo o segundo vetor
	printf("\nSegundo Vetor:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i: ", i + 1);
		scanf("%i", &vet_b[i]);
	}

	for (int i = 0; i < 2 * n; ++i)
	{
		if (vet_a[count_a] > vet_b[count_b])
		{
			vetor[i] = vet_b[count_b];
			if (count_b < n)
			{
				++count_b;
			}			
		}
		else if (vet_a[count_a] < vet_b[count_b])
		{
			vetor[i] = vet_a[count_a];
			if (count_a < n)
			{
				++count_a;
			}
		}
		else
		{
			vetor[i] = vet_a[count_a];
			++i;
			vetor[i] = vet_b[count_b];
			count_a++;
			count_b++;
		}
	}

	for (int i = 0, q = 2 * n; i < q; ++i)
	{
		printf("%i  ", vetor[i]);
	}
	printf("\n");

	return 0;
}