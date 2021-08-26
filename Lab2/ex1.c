#include <stdio.h>

int main(void)
{
	float saldo;

	printf("Digite o saldo: ");
	scanf("%f", &saldo);

	printf("Este saldo com reajuste vale: %.2f\n", saldo * 1.15);
	return 0;
}

