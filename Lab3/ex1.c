#include <stdio.h>

int main(void)
{
	int a, b;
	printf("Primeiro numero: ");
	scanf("%i", &a);

	printf("Segundo numero: ");
	scanf("%i", &b);

	printf("A soma dos numeros eh: %i\n", a + b);
	printf("A subtracao dos numeros eh: %i\n", a - b);
	printf("O produto dos numeros eh: %i\n", a * b);
	printf("A divisao dos numeros eh: %f\n", (double) a / b);

	return 0;

}