#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main() {

	  Dados_Matriz *matriz = (Dados_Matriz*) malloc(sizeof(Dados_Matriz));

		ler_arquivo("test.txt", matriz);

	


		/* Teste sem função de leitura ok
		
		int i, j;
		ponto p1, p2, p3, pcirculo;
		Pixel_cor *cor;
		ponto *p_1 = (ponto*) malloc(sizeof(ponto) * 3);
		p_1->x = 200;
		p_1->y = 200;
		(p_1+1)->x = 400;
		(p_1+1)->y = 300;
		(p_1+2)->x = 350;
		(p_1+2)->y = 350;
		p1.x = 100;
		p1.y = 200;
		p2.x = 300;
		p2.y = 350;
		pcirculo.x = 100;
		pcirculo.y = 100; */
		/*matriz = image(600, 400);
		printf ("a1");
		clear(matriz, 0, 0, 0);
		printf ("a2");
		cor = color(255, 255, 0);
		printf ("a3");
		line(p1, p2, cor, matriz);
		printf ("a4");
		polygon(p_1, 3, cor, matriz);
		printf ("a5");
		circle(pcirculo, 100, cor, matriz);
		save("temp.ppm", matriz); */
		
    return 0;
}





