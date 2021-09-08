/*(i) Construa um programa em C que leia os elementos de um vetor de
até 30 inteiros sem sinal, (ii) ordene-o e (iii) permita a consulta ao
seu conteúdo utilizando a busca linear. (iv) Pesquise como funciona a
Busca Linear.*/

#include <stdio.h>

int main(void)
{
	unsigned int vetor[30];
	int n, posicao, escolha;
	int achou = 0;

	printf("Entre quantos numeros (0 - 30): ");
	scanf("%i", &n);

	if (n < 0 || n > 30)
	{
		printf("Invalido\n");
		return 1;
	}

	printf("Entre com os numeros:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%i: ", i);
		scanf("%i", &vetor[i]);
	}

	printf("Agora, escolha um numero: ");
	scanf("%i", &escolha);

	/*Busca linear - uma busca sequencial ate encontrar o elemento*/
	for (posicao = 0; posicao < n; posicao++)
	{
		if (vetor[posicao] == escolha)
		{
			achou++;
			break;
		}

	}

	if (achou)
	{
		printf("\nO numero %d foi encontrado na posicao: %d\n", escolha, posicao);
	}
	else
	{
		printf("\nO numero %d nao foi encontrado.\n", escolha);
	}

	return 0;
}