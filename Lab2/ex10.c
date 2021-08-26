#include <stdio.h>

int main(void)
{
	double a1, a2, a3;

	printf("Primeiro numero: ");
	scanf("%lf", &a1);

	printf("Segundo numero: ");
	scanf("%lf", &a2);

	printf("Terceiro numero: ");
	scanf("%lf", &a3);

	if ((a1 == a2) && (a2 == a3))
	{
		printf("TODOS IGUAIS\n");
	}
	// Em a1 sendo o maior e a3 sendo o menor
	else if ((a1 > a2) && (a2 >= a3))
	{
		printf("Maior: %.2lf\n", a1);
		printf("Menor: %.2lf\n", a3);
	}
	// Em a1 sendo o maior e a2 sendo o menor
	else if ((a1 > a3) && (a3 >= a2))
	{
		printf("Maior: %.2lf\n", a1);
		printf("Menor: %.2lf\n", a2);
	}
	// Em a2 sendo o maior e a3 o menor
	else if ((a2 > a1) && (a1 >= a3))
	{
		printf("Maior: %.2lf\n", a2);
		printf("Menor: %.2lf\n", a3);
	}
	// Em a2 sendo o maior e a1 sendo o menor
	else if ((a2 > a3) && (a3 >= a1))
	{
		printf("Maior: %.2lf\n", a2);
		printf("Menor: %.2lf\n", a1);
	}
	// Em a3 sendo o maior e a1 o menor
	else if ((a3 > a2) && (a2 >= a1))
	{
		printf("Maior: %.2lf\n", a3);
		printf("Menor: %.2lf\n", a1);
	}
	// Em a3 sendo o maior e a2 sendo o menor
	else
	{
		printf("Maior: %.2lf\n", a3);
		printf("Menor: %.2lf\n", a2);
	}
}