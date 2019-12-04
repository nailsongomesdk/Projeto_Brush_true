#include "estruturas.h"
#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

/**********************************************************************************************

**********************************************************************************************/
Dados_Matriz *image(int largura, int altura);

void clear(Dados_Matriz *matriz, int r, int g, int b);

void save(const char *nome_arquivo, Dados_Matriz *matriz);

void *ler_arquivo(const char *nome_arquivo, Dados_Matriz *matriz);

void line(ponto p1, ponto p2, Pixel_cor *cor , Dados_Matriz *matriz);

void putPixel(ponto p, Pixel_cor *rgb, Dados_Matriz *matriz);

Pixel_cor *color(int r, int g, int b);

void polygon(ponto *p1, int n_pontos, Pixel_cor *cor, Dados_Matriz *matriz);

void Desenhar_Circle(int x1, int y1, int x, int y, Pixel_cor *cor, Dados_Matriz *matriz);

void circle(ponto p, int r, Pixel_cor *cor, Dados_Matriz *matriz);

void rect(ponto rect_p1, int rect_largura,int rect_altura, Pixel_cor *cor, Dados_Matriz *matriz);


#endif