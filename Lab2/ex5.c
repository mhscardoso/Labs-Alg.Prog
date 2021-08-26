#include <stdio.h>

int main(void)
{
	int a, b, c, d, e;

	printf("Primeiro numero: ");
	scanf("%i", &a);

	printf("Segundo numero: ");
	scanf("%i", &b);

	printf("Terceiro numero: ");
	scanf("%i", &c);

	printf("Quarto numero: ");
	scanf("%i", &d);

	printf("Quinto numero: ");
	scanf("%i", &e);

	printf("A soma dos numeros eh: %i\n", a + b + c + d + e);
	printf("O produto dos numeros eh: %i\n", a * b * c * d * e);
	printf("A media so numeros eh: %.2f\n", (a + b + c + d + e) / 5.0);
	return 0;
}