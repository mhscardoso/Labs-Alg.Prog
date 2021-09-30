#include <stdio.h>

void swap(int a, int b)
{	
	printf("---------------------------\n");
	printf("Primeiro: %i\tSegundo: %i\n", a, b);

	int temp = a;
	a = b;
	b = temp;

	printf("Primeiro: %i\tSegundo: %i\n", a, b);
	printf("---------------------------\n");
}

int main(void)
{
	int x, y;

	printf("Digite um numero: ");
	scanf("%i", &x);

	printf("Digite outro numero: ");
	scanf("%i", &y);

	swap(x, y);

	printf("Fora do escopo da funcao\n");
	printf("\nPrimeiro: %i\tSegundo: %i\n", x, y);

	/*Ao realizar os testes, percebi que na funcao principal, as variaveis nao foram trocadas.
	O que acontece eh: quando uma nova funcao eh chamada, apesar de darmos a ela parametros,
	a funcao cria variaveis locais, e, qualquer procedimento deotro do escopo da funcao, altera
	apenas as variaveis licais da funcao
	*/

	return 0;
}