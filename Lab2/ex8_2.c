#include <stdio.h>

int main(void)
{
	float numeros[20];
	float soma;

	for (int i = 0; i < 20; ++i)
	{
		printf("%i*: ", i + 1);
		scanf("%f", &numeros[i]);
		soma += numeros[i];
	}

	printf("A media eh: %f\n", soma / 20);
	return 0;

}