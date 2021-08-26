#include <stdio.h>

int main(void)
{
	int n, iguais;
	double a1, a2, soma, produto;

	soma = 0;
	produto = 1;
	iguais = 0;

	printf("Quantos pares de numeros? ");
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
	{
		printf("Digite a1: ");
		scanf("%d", &a1);

		printf("Digite a2: ");
		scanf("%d", &a2);

		if (a1 > a2)
		{
			soma += a1;
			produto *= a2;
		}
		else if (a1 < a2)
		{
			soma += a2;
			produto *= a1;
		}
		else
		{
			++iguais;
		}
		printf("\n");
	}

	printf("A soma dos maiores numeros eh: %d\n", soma);
	printf("O produto dos menores numeros eh: %d\n", produto);
	printf("A quantidade de pares iguais eh: %i\n", iguais);

	return 0;
}