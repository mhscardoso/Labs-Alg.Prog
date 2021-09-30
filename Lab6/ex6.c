#include <stdio.h>
#include <stdlib.h>

void torre_de_hanoi(int n, char origem, char destino, char auxiliar);

int main(void) {

    int qtd_discos;

    printf("Quantos discos: ");
    scanf("%d", &qtd_discos);

    printf("\n");

    torre_de_hanoi(qtd_discos, 'A', 'B', 'C');
    
    return 0;
}

void torre_de_hanoi(int n, char origem, char auxiliar, char destino) {

    static int movimentos = 0;

    if (n == 1) {

        movimentos++;
        printf("\nMova o disco 1 da torre %c para a torre %c. Movimento: %d", origem, destino, movimentos);
        return;

    }

    torre_de_hanoi(n - 1, origem, destino, auxiliar);
    movimentos++;
    printf("\nMova o disco %d da torre %c para a torre %c. Movimento: %d", n, origem, destino, movimentos);
    torre_de_hanoi(n - 1, auxiliar, origem, destino);

}


void hanoi_iterativo(int n) {

    

}






/*
          -							--					--
        -----						--					--
      ---------						--					--
    -------------					--					--
  -----------------                 --					--
---------------------               --					--

*/

