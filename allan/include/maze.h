/**
 * @file maze.h
 * @author Allan de Miranda - Josué Cláudio
 * @brief Classe Maze que irá guardar o controle lógico do labirinto
 * @version 0.1
 * @date 2018-11-25
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef MAZE_H
#define MAZE_H

#include <vector> // std::vector

/**
 * @brief Class Maze do Labirinto contendo o status do labirinto
 * 
 */
class Maze
{
public:
    /**
     * @brief Estrutura lógica de uma célula do labirinto
     * 
     */
    struct celula
    {
        int tipo = 0;                   //! Tipo da célula livre = 0, entrada = 1, saída = 2, caminho = 3, caminho_descartado = 4   
        bool paredes[4] = {1,1,1,1};    //! Paredes norte, sul, leste, oeste da célula
    };

    /**
     * @brief Dados lógico do labirinto
     * 
     */
    int m_linhas;                               //! Quantidade de linhas
    int m_colunas;                              //! Quantidade de colunas        
    std::vector <std::vector <celula>> m_maze;  //! Matriz que guarda as células
    celula status_celula(int, int);             //! Status da célula

public:
    Maze(int, int);        
    bool status_celula_livre(int, int);
    bool status_celula_entrada(int, int);
    bool status_celula_saida(int, int);
    bool status_celula_caminho(int, int);
    bool status_celula_caminho_descartado(int, int);
    bool status_celula_parede_norte(int, int);
    bool status_celula_parede_sul(int, int);
    bool status_celula_parede_leste(int, int);
    bool status_celula_parede_oeste(int, int);
    void modificar_para_entrada(int, int);
    void modificar_para_saida(int, int);
    void modificar_para_caminho(int, int);
    void modificar_para_caminho_descartado(int, int);
    void derrubar_parede_norte(int, int);
    void derrubar_parede_sul(int, int);
    void derrubar_parede_leste(int, int);
    void derrubar_parede_oeste(int, int);
};

#endif