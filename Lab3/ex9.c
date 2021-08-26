#include <stdio.h>

int main(void)
{
	// a) devido ao casting, a saida sera em ponto flutuante
	int soma1 = 22, cont1 = 5;
	double media1 = (double) soma1 / cont1;

	// b) o mesmo que a letra a
	int soma2 = 22, cont2 = 5;
	double media2 = soma2 / (double) cont2;

	// c) Sera a divisao de dois numeros inteiros, e, apesar do tipo de madia (double), a media3 sera inteira
	int soma3 = 22, cont3 = 5;
	double media3 = soma3 / cont3;

	// d) Sim, ocorreu o casting, mas pela ordem de precedencia, primeiro sera feita a divisao, portanto ele modelara a divisao dos inteiros - cuja saida e inteira. Sera a parte inteira de 22 / 4 com zeros depois do ponto (ponto flutuante)
	int soma4 = 22, cont4 = 5;
	double media4 = (double) (soma4 / cont4);

	printf("%.2f\n", media1);
	printf("%.2f\n", media2);
	printf("%.2f\n", media3);
	printf("%.2f\n", media4);

	return 0;

}