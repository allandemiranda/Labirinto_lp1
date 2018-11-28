# Magos_LP1
	Desenvolvimento do projeto Magos da disciplina Linguagem de 	programação 1 - UFRN IMD

# Desenvolvedores
	[Allan de Miranda](https://github.com/allandemiranda)
	[Josué Cláudio](https://github.com/JO5U3)

# Descrição

	Magos é um  gerador e solucionador de labirintos perfeitos. Um labirinto perfeito é um labirinto onde cada localização no labirinto é alcançável de qualquer outro local. Isso também significa que há um caminho entre os locais de entrada e saída do labirinto.
	O projeto MAGOS funciona em duas etapas. Primeiro lê a partir da entrada o número necessário de linhas e colunas do labirinto e constrói um labirinto perfeito com base nessas informações. Na segunda etapa, o programa encontra uma solução (um caminho) conectando duas células, a entrada do labirinto e a saída.
	A saída do programa  é um conjunto de imagens representando, passo a passo, ambas etapas de contrução e resolução de processos. 

#Algoritmo usado na Construção

#Algoritmo usado na Solução

# Instalação e execução

Para instalar e executar o programa siga as instruções: 

1. Abra o terminal do seu sistema operacional e digite ...
2. `git clone https://github.com/allandemiranda/MAGOS_LP1.git`
3. `cd MAGOS_LP1`
4. `g++ -Wall -std=c++11 src/*.cpp -I include -o ./bin/magos.o`
5. Exemplo de entrada`./bin/magos.o 5 5 1000 10000`
