#include <stdio.h>
#define MAX 100

int main(void)
{
	int elementos[MAX];
	int qtd_elementos;
	int aux;

	printf("Informa a quantidade de elementos (0 - 100): ");
	scanf("%i", &qtd_elementos);

	if (qtd_elementos < 0 || qtd_elementos > 100)
	{
		printf("Quantidade Invalida\n");
		return 1;
	}

	for (int i = 0; i < qtd_elementos; ++i)
	{
		printf("%i: ", i + 1);
		scanf("%i", &elementos[i]);
	}

	for (int i = 0, n = (qtd_elementos) / 2; i < n; ++i)
	{
		aux = elementos[qtd_elementos - i - 1];
		elementos[qtd_elementos - i - 1] = elementos[i];
		elementos[i] = aux;
	}

	for (int i = 0; i < qtd_elementos; ++i)
	{
		printf("%i  ", elementos[i]);
	}

	printf("\n");

	return 0;
}