#include <stdio.h>

// Aqui a declaracao e definicao foram feitas em momentos diferentes, o que e bom para futura leitura do codigo, sendo uma boa pratica por a funcao main no topo.
int multiplica(int a, int b);

int main(void)
{
	int x, y;

	printf("Digite o primeiro numero: ");
	scanf("%d", &x);

	printf("Digite o segundo numero: ");
	scanf("%d", &y);

	printf("O produto dos numeros eh: %d\n", multiplica(x, y));
}


int multiplica(int a, int b)
{
	return a * b;
}