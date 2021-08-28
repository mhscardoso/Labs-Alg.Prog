// a)

#include <stdio.h>

int main(void)
{
	int vet[100], n, c, d, posicao, aux;

	printf("Entre nro de elementos:\n");
	scanf("%d", &n);

	printf("Entre %d inteiros\n", n);

	for (c = 0; c < n; c++)
	{
		scanf("%d", &vet[c]);
	}

	//Neste for, o programa encontra, sempre o "proximo menor numero" e o aloca na posicao correta a cada vez que encontra
	for (c = 0; c < (n - 1); c++)
	{
		posicao = c;

		for (d = c + 1; d < n; d++)
		{
			// A unica alteracao para tornar a ordem decrescente e a condicao deste if
			if (vet[posicao] < vet[d]) // vet[posicao] > vet[d] (anterior)
			{
				posicao = d;
			}
		}
		if (posicao != c)
		{
			aux = vet[c];
			vet[c] = vet[posicao];
			vet[posicao] = aux;
		}
	}

	printf("Lista ordenada em ordem decrescente:\n");
	for (c = 0; c < n; c++)
	{
		printf("%d ", vet[c]);
	}

	return 0;
}

