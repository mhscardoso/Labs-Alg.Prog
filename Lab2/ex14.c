#include <stdio.h>

int main(void)
{
	int n;
	float a;
	float soma = 0;

	printf("Quantos numeros vc quer avaliar? ");
	scanf("%i", &n);
	printf("\n");

	for (int i = 0; i < n; ++i)
	{
		printf("Digito: ");
		scanf("%f", &a);

		if (a < 0)
			soma += a;
	}

	printf("A soma dos que sao negativos eh: %.2f\n", soma);
	return 0;
}