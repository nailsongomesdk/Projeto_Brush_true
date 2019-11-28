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
	
		
		



		/*for(i = 0; i < matriz->linhas;i++){
			for(j = 0; j < matriz->colunas; j++){
				matriz->matriz[i][j].r = i;
				matriz->matriz[i][j].g = j;

				printf("%d %d\n", matriz->matriz[i][j].r, matriz->matriz[i][j].g);
			}
		}



		


		
		  matriz_imagem = ler_arquivo_txt("teste2.txt", &largura , &altura , rgb_color , rgb_clear);
    if (teste2 == NULL) {
        printf("Arquivo nao eh PPM P3 ou nao existe");
        return 1;
    }
    salvar_imagem_ppm("imagemsaida.ppm", matriz_imagem);*/
    return 0;
}



