#include <stdio.h>

int main(void)
{
	int a, b, c;
	// Entrada do primeiro numero em decimal
	printf("Entre com o valor de a em formato decimal: ");
	scanf("%d", &a);

	//Entrada do segundo numero em octal (ex: 011 = 9)
	printf("Entre com o valor de b em formato octal: ");
	scanf("%i", &b);

	//Entrada do terceiro numero em hexadecimal (0xff = 255)
	printf("Entre com o valor de c em formato hexa: ");
	scanf("%i", &c);

	//Apresentacao dos valores
	printf("\na = %i, b = %i, c = %i", a, b, c);
	printf("\na = %o, b = %o, c = %o", a, b, c);
	printf("\na = %X, b = %x, c = %X", a, b, c);

	//Saida para o OS
	return 0;
}

