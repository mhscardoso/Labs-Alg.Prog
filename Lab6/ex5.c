#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fib_iterativo(int n);
int fib_recursivo(int n);

int main(void) {

	int n;
	int aux = 0;
	clock_t t;

	printf("Quantos numeros da sequencia queres printar? ");
	scanf("%d", &n);

	printf("\n");


	t = clock();
	printf("Iterativo\n");
	fib_iterativo(n);
	t = clock() - t;
	printf("\n");
	printf("Tempo levado: %f\n", (double) t / CLOCKS_PER_SEC);

	printf("\n\n");

	t = clock();
	printf("Recursivo\n");
	while (aux < n) {
		printf("%d  ", fib_recursivo(aux));
		aux++;
	}
	printf("\n");
	t = clock() - t;
	printf("Tempo levado: %f\n", (double) t / CLOCKS_PER_SEC);

	return 0;
}

void fib_iterativo(int n) {

	int primeiro = 0;
	int segundo = 1;
	int temp;

	printf("Fibonacci Iterativo:\n");
	for (int i = 0; i < n; i++) {

		printf("%d  ", primeiro);

		temp = primeiro;
		primeiro = segundo;
		segundo = temp + primeiro;
	}
}

int fib_recursivo(int n) {

	// Retorna o n-esimo termo da sequencia de fibonacci 
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fib_recursivo(n - 1) + fib_recursivo(n - 2);		
	}
}
