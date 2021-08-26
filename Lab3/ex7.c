#include <stdio.h>

int main(void)
{

	int a = 5;
	int b = 20;
	int c;

	// Condicao verdadeira, pois AND entre quaisquer numeros diferentes de 0 retorna True
	if (a && b)
	{
		// OP 1 - AND
		printf("OP 1 - Cond. verdadeira ; c = %i\n", c);
	}

	// O mesmo para a condicao OR
	if (a || b)
	{
		// OP 2 - OR
		printf("OP 2 - Cond. verdadeira\n");
	}

	/* Trocando os valores de a e b */

	a = 0;
	b = 10;
	c = a && b;

	// Dessa vez a == 0, e um AND com ele retornara falso
	if (a && b)
	{
		printf("OP 3 - Cond. verdadeira ; c = %i\n", c);
	}
	else
	{
		printf("OP 3 - Cond. falsa ; c = %i\n", c);
	}
	

	// Negacao da condicao anterior, que era falsa
	if ( !(a && b) )
	{
		printf("OP 4 - Cond. verdadeira\n");
	}
	
	return 0;
}
