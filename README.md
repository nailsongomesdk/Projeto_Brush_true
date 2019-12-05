# Projeto_Brush_true

PROJETO ITP 2019.2

ALUNOS: 
ANDRÉ LUIS GURGEL DE FARIA JUNIOR
NAILSON GOMES DE ARAÚJO

O QUE FOI FEITO?
			Foram feitas as funções solicitadas (com a exceção de duas), todas utilizando ponteiros de forma a poupar memória e recurso do computador. Foram implementadas as funções: IMAGE, CLEAR, SAVE, LINE, CIRCLE, POLYGON, RECT e COLOR.
			Todas as funções funcionam lendo um arquivo txt(denominado test.txt dentro do código) que contém o nome de cada função (que o usuário quer utilizar), seguidas dos dados com os quais essa função ira utilizar (separados ou por espaços ou por linha).

			IMAGE: recebe a altura e largura do documento txt e criar uma imagem (matriz).
			CLEAR: recebe 3 valores para o r,g e b(variáveis usadas para definir cor do pixel) nessa ordem e utiliza esses valores para limpar todas a imagem e a deixando apenas na cor lida.
			COLOR: Recebe 3 valores para o r,g e b(variáveis usadas para definir cor do pixel) nessa ordem e utiliza esses valores para definir a cor a ser utilizada nas funções seguintes.
			LINE: Recebe 4 valores - os dois primeiros definindo respectivamente a posições x e y do primeiro ponto e os 2 últimos as posições x e y do segundo ponto. Após isso ela traça uma linha de pixels de um ponto ao outro usando a cor da função color ou a cor branca como padrão caso color ainda não tenha sido chamada.
			CIRCLE: Recebe 3 valores - os dois primeiros definindo respectivamente a posições x e y do centro do círculo e o terceiro o valor do raio. Após isso ela coloca pixels com a cor determinada para forma o círculo. 
			POLYGON: Recebe primeiro um valor determinando a quantidade de pontos, após isso ela recebe as coordenadas x e y respectivamente de cada ponto em sequência e usa a função line para traçar uma linha de um ponto para o outro em sequência, terminando traçando uma linha do último ponto para o primeiro.
			RECT: Recebe 4 valores - os dois primeiros definindo respectivamente a posições x e y do primeiro ponto do retângulo e os dois últimos definindo a largura e altura do retângulo respectivamente. Após isso ela criar mais 3 pontos de acordo com a largura e altura do retângulo e dos limites da matriz e usa a função line para criar linhas entre os 4 pontos.
			SAVE: Salva a matriz criar e modificada nas funções anteriores de acordo com o nome presente logo após (Lembrando que esse nome deve terminar com: .ppm para que ela seja salva de forma correta).

			Extras: Publicação feita no GitHub e implementação de teste na validação dos pontos utilizados no arquivo TXT de leitura.
		
O QUE NAO FOI FEITO?

			O que faltou para finalizar o projeto por completo foi finalizar duas funções, a função de preenchimento (FILL) e a função de abrir uma imagem para alteração (OPEN), pois o tempo para implementar as duas últimas não foi suficiente.
No caso da função FILL ela foi implementada parcialmente, já que ela estava funcionando apenas quando o ponto especifico caia dentro de uma linha já desenhada. Nesse caso a função corretamente pintava a linha da cor determinada. 

O QUE SERIA FEITO DIFERENTE?

			Acreditamos que para ser feito diferente, seria ter analisado o projeto por completo antes de iniciar, pois nossa maior dificuldade foi no início na criação da matriz e as funções de limpar a imagem. Demoramos muito para poder alinhar o código para ambos entenderem por completo.		

COMO COMPILAR O PROJETO, DEIXANDO EXPLICITO SE FOI UTILIZADA ALGUMA BIBLIOTECA EXTERNA QUE PRECISE SER INSTALADA, QUE VERSAO E QUAIS PARAMETROS EXTRAS SÃO NECESSARIOS PARA O COMPILADOR?

			Projeto feito através do site Repl.it, utilizando compilador Ubuntu 18.04.01.
			Não foram utilizadas nenhumas bibliotecas externa. Todos os arquivos precisão estar contidos no mesmo local.

CONTRIBUIÇAO DE CADA INTEGRANTE NO DESENVOLVIMENTO DO PROJETO:

			Projeto feito em conjunto através do site Repl.it - modificações feitas em tempo real por ambos os componentes.
			Também houveram diferentes commits feitos no GitHub pelos dois componentes.
			Link do Projeto no GitHub: https://github.com/nailsongomesdk/Projeto_Brush_true
