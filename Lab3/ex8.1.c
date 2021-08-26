#include <stdio.h>

int main(void)
{

	int a = 5;
	int b = 20;
	int c;

	//char a = 5 - Tabela ASCII
	//char b = 20 - Tabela ASCII

	// Condicao verdadeira, pois AND entre quaisquer numeros diferentes de 0 retorna True
	if (a & b)    // Aqui, o operador bitwise retorna 4 - (00000101 & 00010100 = 00000100)
	{
		// OP 1 - AND
		printf("OP 1 - Cond. verdadeira ; c = %i\n", c);
	}

	// O mesmo para a condicao OR
	if (a | b)    // Aqui, o operador bitwise retorna 21 - (00000101 | 00010100 = 00010101)
	{
		// OP 2 - OR
		printf("OP 2 - Cond. verdadeira\n");
	}

	/* Trocando os valores de a e b */

	a = 0;
	b = 10;
	c = a & b; // Aqui, c sera 0 de qualquer maneira,  pois todos os digitos em binario de a sao zero

	// Dessa vez a == 0, e um AND com ele retornara falso, tambem com o operador bitwise
	if (a & b)
	{
		printf("OP 3 - Cond. verdadeira ; c = %i\n", c);
	}
	else
	{
		printf("OP 3 - Cond. falsa ; c = %i\n", c);
	}
	

	// Negacao da condicao anterior, que era falsa
	if ( ~(a & b) ) // Como a & b era 00000000, sera agora 11111111, ou seja, verdadeiro
	{
		printf("OP 4 - Cond. verdadeira\n");
	}
	
	return 0;
}