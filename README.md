# Magos_LP1
	Desenvolvimento do projeto Magos da disciplina Linguagem de 	programação 1 - UFRN IMD

# Desenvolvedores
	[Allan de Miranda](https://github.com/allandemiranda)
	[Josué Cláudio](https://github.com/JO5U3)

# Descrição

	Magos é um  gerador e solucionador de labirintos perfeitos. Um labirinto perfeito é um labirinto onde cada localização no labirinto é alcançável de qualquer outro local. Isso também significa que há um caminho entre os locais de entrada e saída do labirinto.
	O projeto MAGOS funciona em duas etapas. Primeiro lê a partir da entrada o número necessário de linhas e colunas do labirinto e constrói um labirinto perfeito com base nessas informações. Na segunda etapa, o programa encontra uma solução (um caminho) conectando duas células, a entrada do labirinto e a saída.
	A saída do programa  é um conjunto de imagens representando, passo a passo, ambas etapas de contrução e resolução de processos. 

# Algoritmo usado na Construção

	Para construção do labirinto faz-se o uso inicial de dois conjuntos de índices, seus nomes respectivamente são: Selecionados e Não Selecionados. Supondo que o labirinto é formado por células e cada célula possui um índice numérico, onde o primeiro índice da matriz labirinto posição [0][0] tem número 0, também identificado como entrada do labirinto , e linearmente em ordem crescente o último índice [coluna_max-1][linha_max-1] será (linha * coluna) – 1. Dentro deste padrão, será colocado no conjunto Não Selecionados, todos os índices, com exceção ao índice 0 que é colocado no conjunto Selecionados. A partir deste momento entramos em um loop onde é sorteado um índice do conjunto Selecionados, verificado com quais índices esse índice sorteado faz Parede, adicionando eles a um novo conjunto: o conjunto dos Possíveis para a rodada. O programa verifica quais destes possíveis fazem parte do conjunto dos Selecionados, e os excluem do conjunto dos Possíveis. A partir dai é selecionando um índice do conjunto dos Possíveis, onde a Parede que faz conexão entre o índice sorteado do conjunto dos Possíveis e o índice sorteado do conjunto dos Sorteados, será derrubada pelo sistema. Com isso o programa adiciona esse índice sorteado do conjunto dos Possíveis no conjunto dos Sorteados e o exclui do conjunto dos Não Sorteados. Este ciclo se repete a cada interação solicitada. Quando não houver mais números no conjunto dos Não Sorteados, o programa termina o loop.

# Algoritmo usado na Solução

	Para resolver o labirinto foi utilizada uma pilha e uma tabela de dispersão. Semelhante ao modo de contrição do labirinto, o de solução também utiliza-se de índices para identificar as partes da matriz labirinto. A tabela de dispersão guardara os índices e a cada índice associado terá os possíveis índices que o guia de solução pode se movimentar. A pilha guardará a trajetória que está sendo percorrida, sempre excluindo dela o caminho descartado que não é solução. O programa de solução se baseia em um loop, onde é verificado o índice onde se encontra o guia, que nada mais é que a última posição da pilha. Com acesso a tabela de índices se tem a informação de para quais índices o guia pode se movimentar e dentro dos índices possíveis de movimento é verificado quais não são parte do caminho ou já foram descartados como caminho, e dentre dos restantes e sorteado um índice, que corresponde para onde o guia irá se movimentar. Ao se mover é adicionado a pilha a posição sorteada e a mesma é excluída da lista do índice que o guia estava. Caso não haja mais nenhum movimento na hora de sortear um índice, é identificado que o guia seguiu por um caminho sem saída, e é eliminado da pilha sua ultima posição, com isso o identificador. Caso o índice adicionado a pilha é o índice de saída do labirinto, o programa é terminado.  

# Instalação e execução

Para instalar e executar o programa siga as instruções: 

1. Abra o terminal do seu sistema operacional e digite ...
2. `git clone https://github.com/allandemiranda/MAGOS_LP1.git`
3. `cd Magos_LP1`
4. `g++ -Wall -std=c++11 src/*.cpp -I include -o ./bin/magos.o`
5. Exemplo de entrada`./bin/magos.o 10 10 1200 800`

As imagens geradas estão disponíveis na pasta "builder" e "solver".
