#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

void funcoes(){}

  Dados_Matriz *image(int largura, int altura){
    int i;
		
    Pixel_cor **matriz_imagem = (Pixel_cor **) malloc(sizeof(Pixel_cor*) * largura);
    
		for(i = 0; i < largura; i++){
			*(matriz_imagem+i) = (Pixel_cor*) malloc(sizeof(Pixel_cor) * altura);
		}

		Dados_Matriz *matriz = (Dados_Matriz*) malloc(sizeof(Dados_Matriz));
		matriz->linhas = altura;
		matriz->colunas = largura;
		matriz->str_matriz = matriz_imagem;
		
    return matriz;
  }

	void clear(Dados_Matriz *matriz, int r, int g, int b){
		int x, y;

    for (y = 0; y < matriz->linhas; y++) {
        for (x = 0; x < matriz->colunas; x++) {
           matriz->str_matriz[x][y].r = r;
					 matriz->str_matriz[x][y].g = g;
					 matriz->str_matriz[x][y].b = b;
        }
    }
  }

 	void save(const char *nome_arquivo, Dados_Matriz *matriz){
    FILE *arq = fopen(nome_arquivo, "w");
    int x, y;

		fprintf(arq, "P3\n");
		fprintf(arq, "%d %d\n255", matriz->colunas, matriz->linhas);

    for (y = 0; y < matriz->linhas; y++) {
        for (x = 0; x < matriz->colunas; x++) {
           fprintf(arq, "\n%d %d %d", matriz->str_matriz[x][y].r, matriz->str_matriz[x][y].g, matriz->str_matriz[x][y].b);
        }
    }
    fclose(arq);
	}

	void line(ponto p1, ponto p2, Pixel_cor *cor , Dados_Matriz *matriz){
		int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int inclinacao=0;    
    
		if(dx<0){
        line(p2, p1, cor, matriz);
        return;
    }

    if(dy<0){
        inclinacao = -1;
    }else{
        inclinacao = 1;
		}
    int incE, incNE, d;

    ponto pixel = p1;

    putPixel(pixel, cor, matriz);
    if(dx >= inclinacao*dy){    
        if(dy<0){
            d = 2*dy+dx;
            while(pixel.x<p2.x){
                if(d<0){
                    d += 2*(dy+dx);
                    pixel.x++;
                    pixel.y--;
                }else{ 
                    d+=2*dy;
                    pixel.x++; 
                }
								
                putPixel(pixel, cor, matriz);
            }
        }else{ 
            d=2*dy-dx;
            while(pixel.x<p2.x){
                if(d<0){ 
                    d+=2*dy;
                    pixel.x++; 
                }
                else{ 
                    d+=2*(dy-dx);
                    pixel.x++;
                    pixel.y++;
                }
								putPixel(pixel, cor, matriz);
            }
        }
    }else{ 
        if(dy<0){ 
            d=dy+2*dx;
            while(pixel.y > p2.y){
                if(d<0){
                    d += 2*dx;
                    pixel.y--; 
                }else{
                    d+=2*(dy+dx);
                    pixel.x++;
                    pixel.y--;
                }
								putPixel(pixel, cor, matriz);
            }
        }else{ 
            d=dy-2*dx;
            while(pixel.y<p2.y){
                if(d<0){
                    d+=2*(dy-dx);
                    pixel.x++;
                    pixel.y++;
                }else{
                    d+=-2*dx;
                    pixel.y++;
                }
                putPixel(pixel, cor, matriz);
            }
        }
    }
    	putPixel(pixel, cor, matriz);
	}

	void putPixel(ponto p, Pixel_cor *rgb, Dados_Matriz *matriz){
		matriz->str_matriz[p.x][p.y].r = rgb->r;
		matriz->str_matriz[p.x][p.y].g = rgb->g;
		matriz->str_matriz[p.x][p.y].b = rgb->b;
	}

	Pixel_cor *color(int r, int g, int b){
		Pixel_cor* cor = (Pixel_cor*) malloc(sizeof(Pixel_cor));

		cor->r = r;
		cor->g = g;
		cor->b = b;
		return cor;
	}

	void polygon(ponto *p1, int n_pontos, Pixel_cor *cor, Dados_Matriz *matriz){
		int i;

			for(i = 0; i < n_pontos-1;i++){
				line(p1[i], p1[i+1], cor, matriz);
			}

			line(p1[n_pontos-1], p1[0], cor, matriz);

	}

	void Desenhar_Circle(int x1, int y1, int x, int y, Pixel_cor *cor, Dados_Matriz *matriz){
		ponto p1;
		p1.x = x1 + x;
		p1.y = y1 + y; 
    putPixel(p1,cor,matriz);
		p1.x = x1 - x;
		p1.y = y1 + y; 
    putPixel(p1,cor,matriz);
		p1.x = x1 + x;
		p1.y = y1 - y; 
    putPixel(p1,cor,matriz);
		p1.x = x1 - x;
		p1.y = y1 - y; 
    putPixel(p1,cor,matriz);
		p1.x = x1 + y;
		p1.y = y1 + x; 
    putPixel(p1,cor,matriz);
		p1.x = x1 - y;
		p1.y = y1 + x; 
    putPixel(p1,cor,matriz);
		p1.x = x1 + y;
		p1.y = y1 - x; 
    putPixel(p1,cor,matriz);
		p1.x = x1 - y;
		p1.y = y1 - x; 
    putPixel(p1,cor,matriz); 
}

	void circle(ponto p, int r, Pixel_cor *cor, Dados_Matriz *matriz) { 

			int x = 0, y = r; 
			int d = 3 - 2 * r; 
			Desenhar_Circle(p.x, p.y, x, y, cor, matriz); 
			while (y >= x) { 
					
					x++; 
		

					if (d > 0) { 
							y--;  
							d = d + 4 * (x - y) + 10; 
											} 
					else    d = d + 4 * x + 6; 

					Desenhar_Circle(p.x, p.y, x, y, cor, matriz); 

									
			} 
	}

	void rect(ponto rect_p1, int rect_largura,int rect_altura, Pixel_cor *cor, Dados_Matriz *matriz){
		ponto rect_p2, rect_p3, rect_p4;
		rect_p2.y = rect_p1.y;
		rect_p3.x = rect_p1.x;
		if(rect_p1.x+rect_largura<matriz->colunas){
			rect_p2.x = rect_p1.x+rect_largura;
			rect_p4.x = rect_p1.x+rect_largura;
		}
		else {
			rect_p2.x = rect_p1.x-rect_largura;
			rect_p4.x = rect_p1.x-rect_largura;
		}
		if(rect_p1.y+rect_altura<matriz->linhas){
			rect_p3.y = rect_p1.y+rect_altura;
			rect_p4.y = rect_p1.y+rect_altura;
		}
		else {
			rect_p3.y = rect_p1.y-rect_altura;
			rect_p4.y = rect_p1.y-rect_altura;
		}

		line(rect_p1, rect_p2, cor, matriz);
		line(rect_p2, rect_p4, cor, matriz);
		line(rect_p4, rect_p3, cor, matriz);
		line(rect_p3, rect_p1, cor, matriz);

	}

	void fill(int x, int y , Pixel_cor *cor, Dados_Matriz *matriz){

    Pixel_cor cor_anterior;
		ponto p1;
		p1.x = x;
		p1.y = y;

		cor_anterior.r = matriz->str_matriz[x][y].r;
		cor_anterior.g = matriz->str_matriz[x][y].g;
		cor_anterior.b = matriz->str_matriz[x][y].b;
		
			if(cor_anterior.r != cor->r && cor_anterior.g != cor->g && cor_anterior.b != cor->b)
    {
        putPixel(p1, cor, matriz);
        fill(x + 1, y, cor, matriz);
        fill(x, y + 1, cor, matriz);
        fill(x - 1, y, cor, matriz);
        fill(x, y - 1, cor, matriz);
    }
}
	

	void *ler_arquivo(const char *nome_arquivo, Dados_Matriz *matriz) {
		
		int largura, altura, r, g, b, i, n_pontos,raio_circulo,rect_largura,rect_altura;
		ponto pcirculo;
		Pixel_cor *cor = (Pixel_cor*) malloc(sizeof(Pixel_cor));
		
		char nomeArquivo[20];
		
    
		FILE *arq = fopen(nome_arquivo, "r");
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
								if((r > 255 || r < 0) || (g > 255 || g < 0 ) || (b > 255 || b < 0)){
											printf("valores rgb são invalidos");
											break;
								}
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

									if(p_1[i].x > matriz->colunas){
										printf("valores de x invalidos");
										break;
										}

									if(p_1[i].y > matriz->linhas){
										printf("valores de y invalidos");
										break;
									}
					
								}

								polygon(p_1, n_pontos, cor, matriz);
								free(p_1);
								
			}
			else if(strcmp("circle", teste_funcao) == 0){

								fscanf(arq, "%d", &pcirculo.x);
								fscanf(arq, "%d", &pcirculo.y);
								fscanf(arq, "%d", &raio_circulo);

								if(pcirculo.x > matriz->colunas){
										printf("valores de x invalidos");
										break;
										}

									if(pcirculo.y > matriz->linhas){
										printf("valores de y invalidos");
										break;
									}

								circle(pcirculo, raio_circulo, cor, matriz);
								
			}
			else if(strcmp("color", teste_funcao) == 0){
								fscanf(arq, "%d", &r);
								fscanf(arq, "%d", &g);
								fscanf(arq, "%d", &b);
								if((r > 255 || r < 0) || (g > 255 || g < 0 ) || (b > 255 || b < 0)){
								printf("valores rgb são invalidos");
								break;
								}
								cor = color(r, g, b);
								
			}
			else if(strcmp("line", teste_funcao) == 0){

								ponto *p1 = (ponto*) malloc(sizeof(ponto) * 2);
																
								fscanf(arq, "%d", &p1[0].x);
								fscanf(arq, "%d", &p1[0].y);
								fscanf(arq, "%d", &p1[1].x);
								fscanf(arq, "%d", &p1[1].y);

								if(p1[0].x > matriz->colunas || p1[1].x > matriz->colunas){
										printf("valores de x invalidos");
										break;
										}

									if(p1[0].y > matriz->linhas || p1[1].y > matriz->linhas){
										printf("valores de y invalidos");
										break;
									}									

								line(p1[0], p1[1], cor, matriz);
								free(p1);
								
			}
			else if(strcmp("rect", teste_funcao) == 0){

								ponto rect_p1;

								fscanf(arq, "%d", &rect_p1.x);
								fscanf(arq, "%d", &rect_p1.y);
								fscanf(arq, "%d", &rect_largura);
								fscanf(arq, "%d", &rect_altura);
								
								if(rect_p1.x > matriz->colunas){
										printf("valores de x invalidos");
										break;
										}

									if(rect_p1.y > matriz->linhas){
										printf("valores de y invalidos");
										break;
									}

								rect(rect_p1, rect_largura,rect_altura, cor, matriz);
																
			}
			else if(strcmp("fill", teste_funcao) == 0){

								int x, y;

								fscanf(arq, "%d", &x);
								fscanf(arq, "%d", &y);

								fill(x, y, cor, matriz);
			}



		}
    fclose(arq);
		return 0;
}

	