/*Escreva um programa em C para (i) ler os elementos de uma matriz
quadrada mxm ((ii) m informado pelo usuário e 30), (iii) calcular e
escrever sua transposta e (iv) apresentar a diferença das somas dos
elementos das suas diagonais.*/

#include <stdio.h>
#define MAX 30

int main(void)
{
	int m, diag_main, diag_sec;
	int matrix[MAX][MAX];
	int T_matrix[MAX][MAX];

	diag_main = diag_sec = 0;

	printf("Informe a ordem da matriz: ");
	scanf("%i", &m);

	if (m < 0 || m > 30)
	{
		printf("Invalido\n");
		return 1;
	}


	printf("\nEscreva sua Matriz:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("Elemento [%i][%i]: ", i, j);
			scanf("%i", &matrix[i][j]);

			if (i == j)
			{
				diag_main += matrix[i][j];
			}

			if (i + j == m - 1)
			{
				diag_sec += matrix[i][j];
			}
		}
	}

	printf("\nSua matriz eh:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%i  ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\nSua transposta eh:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			T_matrix[i][j] = matrix[j][i];

			printf("%i  ", T_matrix[i][j]);
		}
		printf("\n");
	}

	printf("\nA diferenca entre as diagonais da matriz eh: %i\n", diag_main - diag_sec);

	return 0;
}
