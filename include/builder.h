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

#include <vector> // std::vector	
#include "../include/maze.h" // VERIFICAR SE ISSO ENTRA AQUI

/**
 * @brief Class builder para criação do labirinto
 * 
 */
class builder
{
private:
    int tamanho_linha;                      //! Quantidade de linhas
    int tamanho_coluna;                     //! Quantidade de colunas
    std::vector <int> indices_restantes;    //! Indices ainda não sorteados
    std::vector <int> indices_selecionados; //! Indices já sorteados
public:
    builder(int,int);
    bool status_builder(void);
    void derrubar_parede(Maze&);
};

#endif