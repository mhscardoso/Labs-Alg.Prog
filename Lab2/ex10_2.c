#include <stdio.h>
#define MAX 3

int main(void)
{
	double atual, maior, menor;
	int n = 0;

	do
	{
		printf("Digite um numero: ");
		scanf("%lf", &atual);

		if (n == 0)
		{
			maior = menor = atual;
		}
		else if (atual > maior)
		{
			maior = atual;
		}
		else if (atual < menor)
		{
			menor = atual;
		}

		n++;

	} while (n < MAX);

	printf("Maior: %.1lf\n", maior);
	printf("Menor: %.1lf\n", menor);
	return 0;
}