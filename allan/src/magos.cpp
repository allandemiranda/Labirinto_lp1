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

#include "../include/magos.h"
#include "../include/builder.h"
#include "../include/solver.h"

/**
 * @brief Função para gerar labirinto
 * 
 */
void Magos::building(void){
    Builder builder_(n_linhas, n_colunas);
    Render render_(n_linhas, n_colunas, p_width, p_height, 0);
    // Game Loop Builder
    while(builder_.status_builder()){
        // Derrubar parede        
        builder_.derrubar_parede(maze_);
        // Renderizar imagem do labirinto
        render_.print(maze_);
    }
}

/**
 * @brief Função apra resolver labirinto
 * 
 */
void Magos::solveing(void){
    Solver solver_(n_linhas, n_colunas, maze_);
    Render render_(n_linhas, n_colunas, p_width, p_height, 1);
    // Game Loop Builder
    while(solver_.status_resolver()){
        // Se mover no labirinto
        solver_.resolver(maze_);
        // Renderizar imagem do labirinto
        render_.print(maze_);
    }

}
