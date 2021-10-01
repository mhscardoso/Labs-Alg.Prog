#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIM 15
#define MAX 50

void random_vet(int arr[LIM], unsigned short int level);

int main(void)
{
	int arr[LIM];
	int tentativa, j, k;
	char ctrl;

	printf("Bem vindo ao jogo da memoria. Pressione ENTER para prosseguir: ");
	
	while ((ctrl = getchar()) != '\n')
	{
		continue;
	}

	system("cls");

	// Portanto, o level subira de 3 em 3, indo ate 15 = 3 x 5
	for (int i = 0, level = 3; i < 5; i++, level += 3)
	{

		// Colocando numeros aleatorios no vetor, conforme o level.
		random_vet(arr, level);

		// Escrevendo os numeros ateatorios na tela
		for (j = 0; j < level; j++)
		{
			printf("%i\t", arr[j]);
		}
		printf("\nQuando pronto, pressione ENTER ");

		ctrl = 'a';

		// Aguardando sinal do usuario
		while ((ctrl = getchar()) != '\n')
		{
			continue;
		}

		// Limpando a tela
		system("cls");

		// Pedindo quais numeros foram mostrados
		for (k = 1; k <= level; k++)
		{
			printf("Elemento %i: ", k);
			scanf("%i", &tentativa);

			if (tentativa != arr[k - 1])
			{
				printf("Errou!\nVoce foi ate o level %i de 5\n", (level / 3) - 1);
				// Escrevendo os numeros ateatorios na tela
				printf("Os numeros eram: \n");
				for (j = 0; j < level; j++)
				{
					printf("%i\t", arr[j]);
				}
				printf("\n");
				return 0;
			}
		}

		ctrl = getchar();

		printf("\nOK!\n");
	}

	// Congratulando o usuario
	printf("Parabens, vc concluiu tudo\n");

	return 0;
}

void random_vet(int arr[LIM], unsigned short int level)
{
	// Iniciando o gerador de numeros aleatorios.
	srand((unsigned) clock());

	for (int i = 0; i < level; i++)
	{
		arr[i] = (rand() % MAX);
	}

	return;
}