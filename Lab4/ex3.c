#include <stdio.h>
#define MAX 100

int main(void)
{
	int n, duplicados;
	int vetor[MAX];

	printf("Informe quantos elementos no vetor de entrada N = ");
	scanf("%i", &n);

	if (n < 0 || n > 100)
	{
		printf("Valor invalido\n");
		return 1;
	}

	printf("Informe os elementos do vetor:\n");

	for (int i = 0; i < n; ++i)
	{
		printf("elemento - %i = ", i);
		scanf("%i", &vetor[i]);

		for (int a = 0; a < i; ++a)
		{
			if (vetor[a] == vetor[i])
			{
				duplicados++;
			}
		}
	}

	printf("\nTotal de elementos duplicados = %i\n", duplicados);

	return 0;
}