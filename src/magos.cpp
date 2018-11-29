/**
 * @file magos.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções da Class Magos
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "../include/maze.h"
#include "../include/magos.h"
#include "../include/builder.h"
#include "../include/solver.h"
#include "../include/render.h"

/**
 * @brief Função para gerar labirinto
 * 
 */
void Magos::building(void){
    Builder builder_(n_colunas, n_linhas);
    Render render_(n_colunas, n_linhas, p_width, p_height, 0);
    render_.print(maze_);
    /// Game Loop Builder
    while(builder_.status_builder()){
        /// Derrubar parede        
        builder_.derrubar_parede(maze_);
        /// Renderizar imagem do labirinto
        render_.print(maze_);
    }
}

/**
 * @brief Função apra resolver labirinto
 * 
 */
void Magos::solving(void){
    Solver solver_(n_colunas, n_linhas, maze_);
    Render render_(n_colunas, n_linhas, p_width, p_height, 1);
    render_.print(maze_);
    /// Game Loop Solver
    while(solver_.status_resolver()){
        /// Se mover no labirinto
        solver_.resolver(maze_);
        /// Renderizar imagem do labirinto
        render_.print(maze_);
    }
}
