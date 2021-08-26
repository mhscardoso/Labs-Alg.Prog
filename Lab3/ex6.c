#include <stdio.h>

int main(void)
{
	char ch1, ch2, ch3, ch4;
	unsigned int num;

	// Aqui, foi colocado a representacao de B de diferentes modos de acordo com a tabela ASCII.
	ch1 = 'B';			//Caractere em formato tradicional
	ch2 = 66;			//Caractere B, de acordo com a tabela ASCII
	ch3 = '\102';	    //B em octal
	ch4 = '\x42';		//B em hexadecimal

	// melhore a saida
	printf("ch1 = %c (Variavel posta em formato tradicional)\nch2 = %c (Variavel posta no formato decimal da tabela ASCII)\nch3 = %c (Variavel posta em formato decimal, de acordo com a tabela ASCII)\nch4 = %c(Variavel posta com valor em hexadecimal)\n", ch1, ch2, ch3, ch4);

	// Aqui ocorreu um caso de casting, pois ch1 eh um caractere - B - e ch1 + 2 eh D, o (int) antes de ch1 + 2 eh necessario para que a saida seja o numero correspondente ao D na tabela ASCII
	printf("ch1 + 2 = %c, ch1 + 2 = %i\n ", ch1+2, (int) ch1+2);

	// Aqui, o programa apenas pede que o usuario insira um numero
	printf("\nEntre valor inteiro entre 0 e 255 : ");
	scanf("%i", &num);
	
	// Novamente ha o caso de casting, no qual sera apresentado para o usuario a letra de acordo com o numero na tabela ASCII
	printf("\nO valor lido corresponde ao caractere = %c", (char) num);
	
	//resposta ao sistema operacional
	return 0;
}
