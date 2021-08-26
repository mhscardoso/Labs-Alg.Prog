#include <stdio.h>

int main(void)
{
	int a, b, lim;

	printf("Digite o primeiro numero: ");
	scanf("%d", &a);

	printf("Digite o segundo numero: ");
	scanf("%d", &b);

	printf("Digite um limite: ");
	scanf("%i", &lim);

	if (a + b < lim)
	{
		printf("Soma menor que limite\n");
	}
	else if (a + b > lim)
	{
		printf("Soma maior que limite\n");
	}
	else
	{
		printf("Soma igual ao limite\n");
	}

	return 0;
}
