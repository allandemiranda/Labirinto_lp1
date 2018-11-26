/**
 * @file render.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções da Class Render
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "../include/render.h"

/**
 * @brief Construct a new Render:: Render object
 * 
 * @param n_l Número de linhas no labirinto
 * @param n_c Número de colunas no labirinto
 * @param p_w Width da imagem
 * @param p_h Height da iamgem
 * @param stt Status de impressão building = 0, solveing = 1
 */
Render::Render(int n_l, int n_c, int p_w, int p_h, int stt){
    n_linhas = n_l;       //! Número de linhas no labirinto
    n_colunas = n_c;      //! Número de colunas no labirinto
    p_width = p_w;        //! Width da imagem
    p_height = p_h;       //! Height da iamgem
    status = stt;         //! Status de impressão building = 0, solveing = 1

    /// Se necessário der continuidade a mais coisas ...
}

/**
 * @brief Função para desenhar o labirinto e salvar no local determinado
 * 
 * @param maze_ Class contendo toda a informação lógica do labirinto
 */
void Render::print(Maze maze_){
    Canvas canvas_; /// Suposta declaraçaõ do canvas

    /// recebe o Maze (contem toda parte lógica do labirinto) 
    /// -> verifica o status de cada índice (célula) -> 
    /// Desenha -> Salva no canto correto de acordo com o status

}