/**
 * @file builder.h
 * @author Allan de Miranda - Josué Cláudio
 * @brief Class Builder que irá criar o labirinto
 * @version 0.1
 * @date 2018-11-25
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef BUILDER_H
#define BUILDER_H

#include "../include/maze.h"

/**
 * @brief Class Builder para criação do labirinto
 * 
 */
class Builder
{
private:
    int tamanho_coluna;                     //! Quantidade de colunas
    int tamanho_linha;                      //! Quantidade de linhas
    std::vector <int> indices_restantes;    //! Indices ainda não sorteados
    std::vector <int> indices_selecionados; //! Indices já sorteados
public:
    Builder(int,int);
    bool status_builder(void);
    void derrubar_parede(Maze&);
};

#endif