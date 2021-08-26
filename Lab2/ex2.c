#include <stdio.h>

int main(void)
{
	float base, altura;

	printf("Digite a base: ");
	scanf("%f", &base);

	printf("Digite a altura: ");
	scanf("%f", &altura);

	printf("O perimetro e: %.2f\n", 2 * (base + altura));
	printf("A area e: %.2f\n", (base * altura));
	return 0;
}