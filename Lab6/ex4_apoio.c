#include <stdio.h>
#include <time.h>

// Uma função que termina quando a tecla enter é pressionada
void fun(void)
{
	printf("fun() iniciou \n");
	printf("Tecle enter para parar fun \n");

	while(1)
	{
		if (getchar())
			break;
	}

	printf("fun() terminou \n");
}

// O prog. princ. chama fun() e mede o tempo utilizado por ela
int main(void)
{ 
	// Calcula o tempo utilizado por fun()
	clock_t t;
	t = clock();

	fun();
	
	t = clock() - t;

	double time_taken = ((double)t) / CLOCKS_PER_SEC; // em segundos

	printf("fun() levou %f segundos para executar \n\n", time_taken);

	return 0;
}