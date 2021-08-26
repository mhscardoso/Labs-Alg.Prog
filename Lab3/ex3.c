#include <stdio.h>

int main(void)
{
	int numero1;
	int numero2;
	char operacao;
	char decisao;

	do
	{
		printf("Digite um numero: ");
		scanf("%d", &numero1);

		printf("Digite outro numero: ");
		scanf("%d", &numero2);

		printf("Escolha uma operacao (+, -, *, /): ");
		scanf(" %c", &operacao);

		switch (operacao)
		{
			case '+':
				printf("%d + %d = %d\n", numero1, numero2, (numero1 + numero2));
				break;
			case '-':
				printf("%d - %d = %d\n", numero1, numero2, (numero1 - numero2));
				break;
			case '*':
				printf("%d * %d = %d\n", numero1, numero2, (numero1 * numero2));
				break;
			case '/':
				printf("%d / %d = %0.2f\n", numero1, numero2, ( (float) numero1 / numero2));
				break;
			default:
				printf("Operacao invalida\n");
		}

		printf("Deseja continuar? (s/n) ");
		scanf(" %c", &decisao);

	} while ((decisao == 's') || (decisao == 'S'));

	return 0;
}


