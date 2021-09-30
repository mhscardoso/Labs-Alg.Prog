#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menor(int arr[], int n);

int main(void)
{
	int arr[35];
	
	srand((unsigned) clock());

	//Preenchendo o vetor
	for (int i = 0; i < 35; i++)
	{
		// Valores de 0 a 99
		arr[i] = rand() % 100;
	}

	printf("\nO menor eh: %d\n", menor(arr, 35));

	return 0;
}

int menor(int arr[], int n)
{
	if (n == 1)
	{
		return arr[0];
	}

	if (arr[n - 1] < menor(arr, n - 1))
	{
		return arr[n - 1];
	}
	else
	{
		return menor(arr, n - 1);
	}
}