/*
Para valores aleatorios de numeros, o programa nao funcionara corretamente, afinal, ele considera que estes estejam em ordem crescente. O programa funciona da seguinte maneira. Ele analisa se o valor do "meio" da matriz eh igual ao valor de busca, se sim, acaba, se for maior, considere valores com indices menores (fazendo perder os possiveis valores que estariam "acima" do "meio"), senao, considera valores com indices maiores (perdendo possiveis valores tambem)
*/

#include <stdio.h>

int main(void)
{
	int c, primeiro, ultimo, meio, n, consulta, vet[100];

	printf("Entre nro de elementos\n");
	scanf("%d",&n);

	printf("Entre %d inteiros\n", n);
	for (c = 0; c < n; c++)
	{
		scanf("%d", &vet[c]);
	}
	
	printf("Entre valor a procurar\n");
	scanf("%d", &consulta);
	primeiro = 0;
	ultimo = n - 1;
	meio = (primeiro + ultimo) / 2;

	// A mudanca feita na condicao while para retirar o break, foi adicionada uma nova variavel (find) que sera um se o valor for achado - true - do contrario, sera zero - false.
	int find = 0;
	while (primeiro <= ultimo && !find)
	{
		if (vet[meio] < consulta)
		{
			primeiro = meio + 1;
		}
		else if (vet[meio] == consulta)
		{
			printf("%d encontrado na posicao %d.\n", consulta, meio + 1);
			find++;
		}
		else
		{	
			ultimo = meio - 1;
		}

		meio = (primeiro + ultimo) / 2;
	}

	if (primeiro > ultimo)
	{
		printf("Nao encontrado! %d nao esta na lista.\n", consulta);
	}
	return 0;
}