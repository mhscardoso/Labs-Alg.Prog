#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int verify = 0xff00; // 0000 0000  0000 0000  1111 1111  0000 0000 = 65280
	int digit;

	printf("Digite um numero: ");
	scanf("%i", &digit);

	digit = verify & digit;
	printf("O terceiro byte eh: %X\n", digit >> 8);

	// Perceba que a principal diferenca entre os operadores logico e bitwise e que o primeiro analisa duas condicoes, enquanto o segundo analisa cada bit do valor comparado.

	return 0;
}
