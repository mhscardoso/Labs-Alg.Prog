#include <stdio.h>

void swap(int* a, int* b)
{	
	printf("---------------------------\n");
	printf("Primeiro: %i\tSegundo: %i\n", *a, *b);

	int temp = *a;
	*a = *b;
	*b = temp;

	printf("Primeiro: %i\tSegundo: %i\n", *a, *b);
	printf("---------------------------\n");
}

int main(void)
{
	int x, y;

	printf("Digite um numero: ");
	scanf("%i", &x);

	printf("Digite outro numero: ");
	scanf("%i", &y);

	swap(&x, &y);

	printf("Fora do escopo da funcao\n");
	printf("\nPrimeiro: %i\tSegundo: %i\n", x, y);

	/*Ao realizar os testes, percebi que na funcao principal, as variaveis FORAM trocadas.
	Aqui, passamos para a funcao os enderecos de memoria das variaveis que queremos alterar.
	Assim, ocorre a troca, ainda que na funcao main.
	*/

	return 0;
}