#include <stdio.h>

int main(void)
{
	int vetor[30];
	int n, m, aux, escolha;
	int meio, ultimo, primeiro, find;

	printf("Entre quantos numeros (0 - 30): ");
	scanf("%i", &n);

	if (n < 0 || n > 30)
	{
		printf("Invalido\n");
		return 1;
	}

	printf("Entre com os numeros:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%i: ", i);
		scanf("%i", &vetor[i]);
	}

	for (int i = 1; i < n; i++)
	{
		m = i;

		while (m > 0 && vetor[m] < vetor[m - 1])
		{
			aux = vetor[m];
			vetor[m] = vetor[m - 1];
			vetor[m - 1] = aux;
			m--;
		}
	}

	printf("De forma ordenada: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", vetor[i]);
	}
	printf("\n");

	printf("Agora, escolha um numero: ");
	scanf("%i", &escolha);

	meio = n / 2;
	primeiro = 0;
	ultimo = n;

	while (ultimo - primeiro > 1)
	{
		if (escolha == vetor[meio])
		{
			find = meio;
			break;
		}
		else if (escolha > vetor[meio])
		{
			primeiro = meio;
			meio += ((ultimo - primeiro) / 2);
		}
		else
		{
			ultimo = meio;
			meio -= ((ultimo - primeiro) / 2);
		}
	}

	printf("%d\n", find);

	return 0;
}