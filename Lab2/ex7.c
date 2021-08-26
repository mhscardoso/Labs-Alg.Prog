#include <stdio.h>

int main(void)
{
	float massa, volume;

	printf("Diga a massa do material (Kg): ");
	scanf("%f", &massa);

	printf("Diga o volume do material (m^3): ");
	scanf("%f", &volume);

	printf("A densidade absoluta do material eh: %.3f Kg/m3 \n", massa / volume);
	return 0;
}