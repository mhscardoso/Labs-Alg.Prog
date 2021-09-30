#include <stdio.h>

// Aqui a declaracao e definicao foram feitas ao mesmo tempo, o que e ruim para futura leitura do codigo, sendo uma boa pratica por a funcao main no topo.
int multiplica(int a, int b)
{
	return a * b;
}

int main(void)
{
	int x, y;

	printf("Digite o primeiro numero: ");
	scanf("%d", &x);

	printf("Digite o segundo numero: ");
	scanf("%d", &y);

	printf("O produto dos numeros eh: %d\n", multiplica(x, y));
}

