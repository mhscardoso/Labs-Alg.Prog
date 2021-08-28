/*Construa um programa em C para (i) ler uma matriz de mais de 2
dimensões, (ii) verifique limites de tamanho em nro de elementos
inteiros e (iii) em dimensões.*/

#include <stdio.h>
const int MAX = 80;

int main(void)
{
	int cube[MAX][MAX][MAX];
	int cube2[MAX][MAX][MAX];
	// Com duas matrizes multidimensionais, o programa sequer executa

	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			for (int k = 0; k < MAX; ++k)
			{
				printf("elemento[%i][%i][%i]: ", i, j, k);
				scanf("%i", &cube[i][j][k]);
			}
		}
	}

	for (int i = 0; i < MAX; ++i)
	{
		printf("Face %i:\n", i);
		for (int j = 0; j < MAX; ++j)
		{
			for (int k = 0; k < MAX; ++k)
			{
				printf("%i  ", cube[i][j][k]);
			}
			printf("\n");
		}

		printf("\n");
	}

	return 0;
}