#include <stdio.h>

int main(void)
{
	int n;
	double a1, a2;

	printf("Quantos pares de numeros vc quer registrar? ");
	scanf("%i", &n);

	if (n == '\n')
	{
		printf("Invalido\n");
		return 1;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("Digite a1: ");
		scanf("%d", &a1);

		printf("Digite a2: ");
		scanf("%d", &a2);

		if (a1 > a2)
		{
			printf("O maior eh: %d\n\n", a1);
		}
		else if (a1 < a2)
		{
			printf("O maior eh: %d\n\n", a2);
		}
		else
		{
			printf("IGUAIS\n\n");
		}
	}

	return 0;
}