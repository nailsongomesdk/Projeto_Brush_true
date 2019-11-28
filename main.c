#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main() {

		int i, j;
    Dados_Matriz *matriz;
		ponto p2, p3, pcirculo;
		Pixel_cor *cor;
		ponto *p1 = (ponto*) malloc(sizeof(ponto) * 3) ;

		p1[0].x = 0;
		p1[0].y = 100;
		p1[1].x = 200;
		p1[1].y = 300;
		p1[2].x = 100;
		p1[2].y = 300;
	
		pcirculo.x = 200;
		pcirculo.y = 300;

    
		
		//ler_arquivo("teste2.txt", matriz);

	
		matriz = image(600, 400);
		
		clear(matriz, 0, 0, 0);

		cor = color(255, 255, 0);

		//line(p1, p2, cor, matriz);
		polygon(p1, 3, cor, matriz);

		circle(pcirculo, 100, cor, matriz);
			
		save("temp.ppm", matriz);
		
    return 0;
}





