/**
 * @file solver.h
 * @author Allan de Miranda - Josué Cláudio
 * @brief Class Solver que irá solucionar o labirinto
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef SOLVER_H
#define SOLVER_H

#include <vector> // std::vector
#include "../include/maze.h" // VERIFICAR SE ISSO ENTRA AQUI

/**
 * @brief Class Solver rosolvendo o labirinto
 * 
 */
class Solver
{
private:
    /**
     * @brief Controles de organização
     * 
     */
    int tamanho_linha;
    int tamanho_coluna;
    int posicao_atual;
    int entrada = 0;
    int saida;
    /**
     * @brief Controles de solução
     * 
     */
    std::vector <std::vector <int>> tabela;
    std::vector <int> lista;
public:
    Solver(int, int, Maze&);
};



#endif