#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main() {

	  Dados_Matriz *matriz = (Dados_Matriz*) malloc(sizeof(Dados_Matriz));

		ler_arquivo("test.txt", matriz);
		
    return 0;
}




