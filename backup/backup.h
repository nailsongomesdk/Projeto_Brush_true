#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void funcoes(){}

void polygon(ponto *p1, int n_pontos, Pixel_cor *cor, Dados_Matriz *matriz){
		int i;

		for(i = 0; i < n_pontos-1; i++){
			//line(p1[i], p1[i+1], cor, matriz);
		}
		
		//line(p1[0], p1[n_pontos], cor, matriz);

	}

  Imagem_dados *image(int largura, int altura){
    int i,j;

		//criando imagem em matriz;
    Imagem_dados *imagem = (Imagem_dados *) malloc(sizeof(Imagem_dados));
    imagem->largura = largura;
    imagem->altura = altura;

		//criando arquivo temporario
		FILE *arq = fopen("temp.txt", "w");
		fprintf(arq, "P3\n%d %d\n255", imagem->largura, imagem->altura);

		for(i = 0; i < imagem->largura; i++){
			for(j = 0; j < imagem->altura; j++){
				fprintf(arq, "\n0 0 0");
			}
		}
		fclose(arq);
    return imagem;
  }

  /*void clear(int r, int g, int b){
    FILE *arq = fopen(nome_arquivo, "r");
    int x, y;
    for (y = 0; y < imagem.altura; y++) {
        for (x = 0; x < imagem->largura; x++) {
            Pixel_cor *pont_pixel = pixel_da_imagem(imagem, x, y);
            fprintf(arq, "\n%d %d %d", pont_pixel->vermelho, pont_pixel->verde, pont_pixel->azul);
        }
    }
  }*/

  
/**********************************************************************************************

**********************************************************************************************/

Imagem_dados *criar_imagem(int largura, int altura, int cor_maxima){
    Imagem_dados *imagem = (Imagem_dados *) malloc(sizeof(Imagem_dados));
    imagem->pixels = (Pixel_cor *) malloc(largura * altura * sizeof(Pixel_cor));
    imagem->largura = largura;
    imagem->altura = altura;
    imagem->cor_maxima = cor_maxima;
    return imagem;
}

/**********************************************************************************************
Esta fórmula y * imagem->largura + x é porque cada linha corresponde a um bloco de largura pixels, sendo todas as linhas armazenadas contiguamente na memória em um único bloco maior. Assim sendo, cada posição que variar no y ocasiona uma variação de largura posições dentro do bloco maior. Isso serve para não precisar alocar cada linha uma por um, otimizando a memória ao fazer todos os pixels serem alocados na mesma região de memória.
**********************************************************************************************/
Pixel_cor *pixel_da_imagem(Imagem_dados *imagem, int x, int y) {
    return &(imagem->pixels[y * imagem->largura + x]);
}

/**********************************************************************************************

**********************************************************************************************/
Imagem_dados *ler_arquivo_txt(const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL){
      printf ("Erro - arquivo não encontrado\n");
      return NULL;} 

    int largura, altura, cor_maxima, x, y;
    Imagem_dados *imagem = NULL;
    char teste_formato[6];
    fgets(teste_formato, 6, arq);
    if (strcmp("P3\n", teste_formato) == 0) {
        fscanf(arq, "%d", &largura);
        fscanf(arq, "%d", &altura);
        fscanf(arq, "%d", &cor_maxima);
        imagem = criar_imagem(largura, altura, cor_maxima);
        for (y = 0; y < altura; y++) {
            for (x = 0; x < largura; x++) {
                Pixel_cor *pont_pixel = pixel_da_imagem(imagem, x, y);
                fscanf(arq, "%d", &(pont_pixel->vermelho));
                fscanf(arq, "%d", &(pont_pixel->verde));
                fscanf(arq, "%d", &(pont_pixel->azul));
            }
        }
    }
    fclose(arq);
    return imagem;
}

/**********************************************************************************************

**********************************************************************************************/
void salvar_imagem_ppm(const char *nome_arquivo, Imagem_dados *imagem){
    FILE *arq = fopen(nome_arquivo, "w");
    int x, y;
    fprintf(arq, "P3\n%d %d\n%d", imagem->largura, imagem->altura, imagem->cor_maxima);
    for (y = 0; y < imagem->altura; y++) {
        for (x = 0; x < imagem->largura; x++) {
            Pixel_cor *pont_pixel = pixel_da_imagem(imagem, x, y);
            fprintf(arq, "\n%d %d %d", pont_pixel->vermelho, pont_pixel->verde, pont_pixel->azul);
        }
    }
    fclose(arq);
}

/**********************************************************************************************
Função para limpar a imagem caso necessario 
**********************************************************************************************/
void clear_imagem(Imagem_dados *imagem) {
    free(imagem->pixels);
    free(imagem);
}

Matriz *ler_arquivo_txt(const char *nome_arquivo , int *largura , int *altura , Pixel_1 *rgb_color , Pixel_1 *rgb_clear) {

      int n_pontos =0 ;
      int j;
      ponto p1 , p2 , paux;

    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL){
      printf ("Erro - arquivo não encontrado\n");
      return NULL;} 

    Pixel_1 **matriz_imagem = NULL;
    char teste_funcao[9];

		while(fscanf (arq , "%s" , teste_funcao)){
    if (strcmp("image", teste_funcao) == 0) {
        fscanf(arq, "%d", largura);
        fscanf(arq, "%d", altura);
        matriz_imagem = image(*largura, *altura);
         }
				 
		else if(strcmp("clear", teste_funcao) == 0){
			fscanf(arq, "%d", &rgb_clear->r);
      fscanf(arq, "%d", &rgb_clear->g);
			fscanf(arq, "%d", &rgb_clear->b);
			matriz_imagem = clear(*(rgb_clear), *largura, *altura);
				 }
    else if(strcmp("color", teste_funcao) == 0){
			fscanf(arq, "%d", &rgb_color->r);
      fscanf(arq, "%d", &rgb_color->g);
			fscanf(arq, "%d", &rgb_color->b);
				 }

    else if(strcmp("line", teste_funcao) == 0){

			fscanf(arq, "%d", &p1.x);
      fscanf(arq, "%d", &p1.y);
      fscanf(arq, "%d", &p2.x);
      fscanf(arq, "%d", &p2.y);
			matriz_imagem = line(p1, p2, rgb_color);
				 }

		else if(strcmp("polygon", teste_funcao) == 0){

			fscanf(arq, "%d", &n_pontos);
      fscanf(arq, "%d", &p1.x);
      fscanf(arq, "%d", &p1.y);
      fscanf(arq, "%d", &p2.x);
      fscanf(arq, "%d", &p2.y);
			matriz_imagem = line(p1, p2, rgb_color);
      for(j = 0;j <= n_pontos-2;j++){
        paux.x = p2.x;
        paux.y = p2.y;
        fscanf(arq, "%d", &p2.x);
        fscanf(arq, "%d", &p2.y);
        matriz_imagem = line(paux, p2, rgb_color);
              }
        matriz_imagem = line(p2, p1, rgb_color);      
			 }



		}
    fclose(arq);
    return matriz_imagem;
}
