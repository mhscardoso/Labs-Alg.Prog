#include <stdio.h>

int main(void)
{
	int n;
	float a;
	int q = 0;

	printf("Quantos numeros vc quer avaliar? ");
	scanf("%i", &n);
	printf("\n");

	for (int i = 0; i < n; ++i)
	{
		printf("Digito: ");
		scanf("%f", &a);

		if (a < 0)
			++q;
	}

	printf("Vc digitou %i numeros negativos.\n", q);
	return 0;
}