#include <stdio.h>

int main(void)
{
	const int q_canetas = 30;
	const float t_pago = 100.0;
	const float troco = 67.0;

	// O preco das 30 canetas
	float preco_total = t_pago - troco;

	// O preco de cada caneta
	float preco_caneta = preco_total / q_canetas;
	
	printf("O preco de cada caneta eh: R$ %.2f\n", preco_caneta);
	return 0;
}