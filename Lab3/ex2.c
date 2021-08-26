#include <stdio.h>

int main(void)
{
	int a1, a2;
	char operacao;

	printf("Primeiro numero: ");
	scanf("%i", &a1);

	printf("Segundo numero: ");
	scanf("%i", &a2);

	printf("Escreva uma operacao (+, -, *, /): ");
	scanf(" %c", &operacao);

	printf("Numeros: %i e %i\n", a1, a2);

	if ((operacao != '+') && (operacao != '-') && (operacao != '*') && (operacao != '/'))
	{
		printf("Operacao invalida\n");
		return 1;
	}

	if (operacao == '+')
	{
		printf("Soma: %i\n", a1 + a2);
	}
	else if (operacao == '-')
	{
		printf("Subtracao: %i\n", a1 - a2);
	}
	else if (operacao == '*')
	{
		printf("Multiplicacao: %i\n", a1 * a2);
	}
	else
	{
		printf("Divisao: %.2f\n", (double) a1 / a2);
	}

	return 0;
}