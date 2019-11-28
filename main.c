#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main() {

int i, j;
    Dados_Matriz *matriz;
		ponto p1, p2, p3, pcirculo;
		Pixel_cor *cor;

		p1.x = 200;
		p1.y = 200;
		p2.x = 110;
		p2.y = 110;
		p3.x = 0;
		p3.y = 300;
		pcirculo.x = 200;
		pcirculo.y = 100;

    
		
		//ler_arquivo("teste2.txt", matriz);

	
		matriz = image(600, 400);
		
		clear(matriz, 0, 0, 0);

		cor = color(255, 255, 0);

		line(p1, p2, cor, matriz);

		circle(pcirculo, 100, cor, matriz);
			
		save("temp.ppm", matriz);
		
    return 0;
}





