#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main() {

int i, j;
Dados_Matriz *matriz;
ponto pcirculo;
Pixel_cor *cor;
int largura, altura, r, g, b, n_pontos,raio_circulo;
char nomeArquivo[20];

		FILE *arq = fopen("test.txt", "r");
    if (arq == NULL){
      printf ("Erro - arquivo não encontrado\n");
      return NULL;} 

    char teste_funcao[12];

		while(fscanf (arq , "%s" , teste_funcao) != EOF){

			if (strcmp("image", teste_funcao) == 0) {
					fscanf(arq, "%d", &largura);
					fscanf(arq, "%d", &altura);
					matriz = image(largura, altura);
					}
			else if(strcmp("clear", teste_funcao) == 0){
				fscanf(arq, "%d", &r);
				fscanf(arq, "%d", &g);
				fscanf(arq, "%d", &b);
				clear(matriz, r, g, b);
					}
			else if(strcmp("save", teste_funcao) == 0){
				fscanf(arq, "%s", nomeArquivo);
				save(nomeArquivo, matriz);			
				}
			
			else if(strcmp("polygon", teste_funcao) == 0){
								fscanf(arq, "%d", &n_pontos);
								ponto *p_1 = (ponto*) malloc(sizeof(ponto) * n_pontos);
								
								for(i = 0; i < n_pontos; i++){
									fscanf(arq, "%d", &p_1[i].x);
									fscanf(arq, "%d", &p_1[i].y);									
								}

								polygon(p_1, n_pontos, cor, matriz);
								free(p_1);
							}
			else if(strcmp("circle", teste_funcao) == 0){

								fscanf(arq, "%d", &pcirculo.x);
								fscanf(arq, "%d", &pcirculo.y);
								fscanf(arq, "%d", &raio_circulo);

			}



		}
    fclose(arq);
		
    return 0;
}





