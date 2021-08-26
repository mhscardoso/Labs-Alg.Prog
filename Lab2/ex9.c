#include <stdio.h>

int main(void)
{
	float a1, a2, maior;

	printf("Digite o primeiro numero: ");
	scanf("%f", &a1);

	printf("Digite o segundo numero: ");
	scanf("%f", &a2);

	if (a1 == a2)
	{
		printf("IGUAIS");
	}
	else
	{
		maior = (a1 > a2) ? a1: a2;
		printf("%.2f\n", maior);
	}

	return 0;

}