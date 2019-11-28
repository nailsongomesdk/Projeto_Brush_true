#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main() {

	  Dados_Matriz *matriz = (Dados_Matriz*) malloc(sizeof(Dados_Matriz));
	
		ler_arquivo("test.txt", matriz);

	
		/*matriz = image(600, 400);
		
		clear(matriz, 0, 0, 0);

		cor = color(255, 255, 0);

		//line(p1, p2, cor, matriz);
		polygon(p1, 3, cor, matriz);

		circle(pcirculo, 100, cor, matriz);
			
		save("temp.ppm", matriz);*/
		
    return 0;
}





