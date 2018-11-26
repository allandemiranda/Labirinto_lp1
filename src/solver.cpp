/**
 * @file solver.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções class Solver
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "../include/solver.h"

/**
 * @brief Construct a new Solver:: Solver object
 * 
 * @param num_linha Quantidade de Linhas que a matriz do labirinto terá
 * @param num_coluna Quantidade de Colunas que a martiz do labirinto terá 
 * @param maze_ O labirinto
 */
Solver::Solver(int num_linha, int num_coluna, Maze & maze_){
    /**
     * @brief configurando controles de organização
     * 
     */
    tamanho_linha = num_linha;
    tamanho_coluna = num_coluna;
    saida = (num_linha*num_coluna) - 1;
    posicao_atual = 0;

    /**
     * @brief Mapear e preencher tabela de solução
     * 
     */
    

}