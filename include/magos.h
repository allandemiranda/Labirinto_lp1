/**
 * @file magos.h
 * @author Allan de Miranda - Josué Cláudio
 * @brief Class principal do jogo
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef MAGOS_H
#define MAGOS_H

#include "../include/maze.h"
#include "../include/render.h"

/**
 * @brief Class Magos
 * 
 */
class Magos
{
private:    
    int n_colunas;      //! Número de colunas no labirinto
    int n_linhas;       //! Número de linhas no labirinto
    int p_width;        //! Width da imagem
    int p_height;       //! Height da iamgem
    Maze maze_;         //! Class com informações das células do labirinto
public:
    /**
     * @brief Construct a new Magos object
     * 
     * @param linha Número de linhas no labirinto
     * @param coluna Número de colunas no labirinto
     * @param p_w Width da imagem
     * @param p_h Height da iamgem
     */
    Magos(int coluna, int linha, int p_w, int p_h) : 
        maze_(coluna, linha){                   
            n_colunas = coluna;
            n_linhas = linha;
            p_width = p_w;
            p_height = p_h;
        };    
    
    void building(void);    
    void solveing(void);    
};

#endif
