/*Escreva um programa em C para (i) ler um vetor de n ((ii) n
informado pelo usuário e valendo até 100) números inteiros e (iii)
exibir e (iv) contar o número de elementos duplicados nele. (v) A
saída deve ter a seguinte aparência:
Informe quantos elementos no vetor de entrada N = 3
Informe os elementos do vetor :
elemento - 0 = 5
elemento - 1 = 3
elemento - 2 = 3
Total de elementos duplicados = 1*/

#include <stdio.h>
#define MAX 100

int main(void)
{
	int n, duplicados;
	int vetor[MAX];

	printf("Informe quantos elementos no vetor de entrada N = ");
	scanf("%i", &n);

	if (n < 0 || n > 100)
	{
		printf("Valor invalido\n");
		return 1;
	}

	printf("Informe os elementos do vetor:\n");

	for (int i = 0; i < n; ++i)
	{
		printf("elemento - %i = ", i);
		scanf("%i", &vetor[i]);

		for (int a = 0; a < i; ++a)
		{
			if (vetor[a] == vetor[i])
			{
				duplicados++;
			}
		}
	}

	printf("\nTotal de elementos duplicados = %i\n", duplicados);

	return 0;
}