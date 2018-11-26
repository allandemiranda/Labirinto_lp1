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

/**
 * @brief Class solver rosolvendo o labirinto
 * 
 */
class solver
{
private:
    int tamanho_linha;
    int tamanho_coluna;
    int posicao_atual[2] = {0,0};
    int entrada[2] = {0,0};
    int saida[2];
public:
    solver(/* args */);
    ~solver();
};

solver::solver(/* args */)
{
}

solver::~solver()
{
}


#endif