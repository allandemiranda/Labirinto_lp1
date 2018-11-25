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

class builder
{
private:
    int tamanho_linha;
    int tamanho_coluna;
    std::vector <int> indices_restantes;
    std::vector <int> indices_selecionados;
public:
    builder(int,int);
    bool status_builder(void);
    void derrubar_parede(maze&);
};

#endif