// b)

#include <stdio.h>

int main(void)
{
	int n, vet[1000], c, d, t;

	printf("Entre nro de elementos\n");
	scanf("%d", &n);

	printf("Entre %d inteiros\n", n);

	for (c = 0; c < n; c++)
	{
		scanf("%d", &vet[c]);
	}

	// Aqui foi aplicado o algoritmo: insertion sort
	// Para todo o elemento do array
	for (c = 1; c <= n - 1; c++)
	{
		d = c;

		// Enquanto o numero anterior for maior que o atual (vet[d]), troque os numeros
		// Para os elementos maiores que a parte da lista que ja foi ordenada
		// Para que o algoritmo os ponha em ordem decrescente, basta trocar o sinal da segunda condicao
		while (d > 0 && vet[d - 1] > vet[d])	//vet[d - 1] < vet[d]
		{
			// Enquanto nao chegar no ultimo elemento ou o elemento anterior nao for maior que o analisado
			t = vet[d];
			vet[d] = vet[d - 1];
			vet[d - 1] = t;
			d--;
		}
	}

	printf("Lista ordenada em ordem crescente:\n");

	for (c = 0; c <= n - 1; c++)
	{
		printf("%d  ", vet[c]);
	}


	return 0;

}

