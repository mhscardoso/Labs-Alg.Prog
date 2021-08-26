#include <stdio.h>

int main(void)
{
	int anos, meses, dias;

	printf("Quantos anos vc tem? ");
	scanf("%i", &anos);

	printf("Quantos meses a mais? ");
	scanf("%i", &meses);

	printf("E quantos dias a mais? ");
	scanf("%i", &dias);

	printf("Uau! Vc tem, ao todo %i dias de vida\n", (anos * 365) + (meses * 30) + dias);
	return 0;
}