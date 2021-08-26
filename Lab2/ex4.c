#include <stdio.h>

int main(void)
{
	float vendas;

	printf("Quanto este funcionario gerou em vendas? ");
	scanf("%f", &vendas);

	printf("Tendo como salario base, o valor de R$ 1200.00, o funcionario deve receber: %.2f\n", 1200.0 + vendas * 0.17);
	return 0;
}
