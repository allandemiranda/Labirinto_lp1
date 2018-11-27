/**
 * @file render.h
 * @author Allan de Miranda - Josué Cláudio
 * @brief 
 * @version 0.1
 * @date 2018-11-25
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef RENDER_H
#define RENDER_H

#include "../include/maze.h"
#include "../include/canvas.h"

/**
 * @brief Class Render
 * 
 */
class Render
{
private:    
    int n_colunas;      //! Número de colunas no labirinto
    int n_linhas;       //! Número de linhas no labirinto
    int p_width;        //! Width da imagem
    int p_height;       //! Height da iamgem
    int status;         //! Status de impressão building = 0, solveing = 1
    int numero = 0;     //! Guarda informações da sequência numérica
public:
    Render(int, int, int, int, int);
    void print(Maze maze_);
};

#endif
