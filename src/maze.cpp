/**
 * @file maze.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções da class maze
 * @version 0.1
 * @date 2018-11-25
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <vector> // std::vector
#include "../include/maze.h"

/**
 * @brief Construct a new Maze::Maze object
 * 
 * @param num_linhas Quantidade de Linhas que a matriz do labirinto terá
 * @param num_colunas Quantidade de Colunas que a martiz do labirinto terá
 */
Maze::Maze(int num_linhas, int num_colunas)
{
    m_linhas = num_linhas;      //! Guardar quantidade de linahs
    m_colunas = num_colunas;    //! Guardar quantidade de colunas

    /**
     * @brief Gerar matriz inicial para labirinto
     * 
     */
    for(int i(0); i<m_linhas; ++i){
        std::vector <celula> temp;
        for(int j(0); j<m_colunas; ++j){
            celula c_temp;
            temp.push_back(c_temp); 
        }
        m_maze.push_back(temp);
    }

    /**
     * @brief Setar entrada e saída do labirinto
     * 
     */
    m_maze[0][0].tipo = 1;                      //! Entrada do labirinto
    m_maze[m_linhas-1][m_colunas-1].tipo = 2;   //! Saída do labirinto
}

/**
 * @brief Verificar o status da célula
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return maze::celula A estutura da célula
 */
Maze::celula Maze::status_celula(int cord_linha, int cord_coluna){
    return m_maze[cord_linha][cord_coluna];
}

/**
 * @brief Verificar se é uma célula Livre
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se for uma célula Livre
 * @return false Se não for uma célula Livre
 */
bool Maze::status_celula_livre(int cord_linha, int cord_coluna){
    if(status_celula(cord_linha,cord_coluna).tipo == 0){
        return true;
    }
    return false;
}

/**
 * @brief Verificar se é uma célula Entrada
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se for uma célula Entrada
 * @return false Se não for uma célula Entrada
 */
bool Maze::status_celula_entrada(int cord_linha, int cord_coluna){
    if(status_celula(cord_linha,cord_coluna).tipo == 1){
        return true;
    }
    return false;
}

/**
 * @brief Verificar se é uma célula Saída
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se for uma célula Saída
 * @return false Se não for uma célula Saída
 */
bool Maze::status_celula_saida(int cord_linha, int cord_coluna){
    if(status_celula(cord_linha,cord_coluna).tipo == 2){
        return true;
    }
    return false;
}

/**
 * @brief Verificar se é uma célula Caminho
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se for uma célula Caminho
 * @return false Se não for uma célula Caminho
 */
bool Maze::status_celula_caminho(int cord_linha, int cord_coluna){
    if(status_celula(cord_linha,cord_coluna).tipo == 3){
        return true;
    }
    return false;
}

/**
 * @brief Verificar se é uma célula Caminho Descartado
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se for uma célula Caminho Descartado
 * @return false Se não for uma célula Caminho Descartado
 */
bool Maze::status_celula_caminho_descartado(int cord_linha, int cord_coluna){
    if(status_celula(cord_linha,cord_coluna).tipo == 4){
        return true;
    }
    return false;
}

/**
 * @brief Verificar se a parede Norte está ativa
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se a parede Norte não estiver destruida
 * @return false Se a parede Norte estiver destruida
 */
bool Maze::status_celula_parede_norte(int cord_linha, int cord_coluna){
    return status_celula(cord_linha,cord_coluna).paredes[0];
}

/**
 * @brief Verificar se a parede Sul está ativa
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se a parede Sul não estiver destruida
 * @return false Se a parede Sul estiver destruida
 */
bool Maze::status_celula_parede_sul(int cord_linha, int cord_coluna){
    return status_celula(cord_linha,cord_coluna).paredes[1];
}

/**
 * @brief Verificar se a parede Leste está ativa
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se a parede Leste não estiver destruida
 * @return false Se a parede Leste estiver destruida
 */
bool Maze::status_celula_parede_leste(int cord_linha, int cord_coluna){
    return status_celula(cord_linha,cord_coluna).paredes[2];
}


/**
 * @brief Verificar se a parede Oeste está ativa
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna
 * @return true Se a parede Oeste não estiver destruida
 * @return false Se a parede Oeste estiver destruida
 */
bool Maze::status_celula_parede_oeste(int cord_linha, int cord_coluna){
    return status_celula(cord_linha,cord_coluna).paredes[3];
}

/**
 * @brief Modificar tipo da célula para Entrada
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna 
 */
void Maze::modificar_para_entrada(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].tipo = 1;
}

/**
 * @brief Modificar tipo da célula para Saída
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna 
 */
void Maze::modificar_para_saida(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].tipo = 2;
}

/**
 * @brief Modificar tipo da célula para Caminho
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna 
 */
void Maze::modificar_para_caminho(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].tipo = 3;
}

/**
 * @brief Modificar tipo da célula para Caminho Descartado
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna 
 */
void Maze::modificar_para_caminho_descartado(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].tipo = 4;
}

/**
 * @brief Derrubar parede Norte da célula
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna  
 */
void Maze::derrubar_parede_norte(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].paredes[0] = false;
}

/**
 * @brief Derrubar parede Sul da célula
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna  
 */
void Maze::derrubar_parede_sul(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].paredes[1] = false;
}

/**
 * @brief Derrubar parede Leste da célula
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna  
 */
void Maze::derrubar_parede_leste(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].paredes[2] = false;
}

/**
 * @brief Derrubar parede Oeste da célula
 * 
 * @param cord_linha Cordenada da Linha
 * @param cord_coluna Cordenada da Coluna  
 */
void Maze::derrubar_parede_oeste(int cord_linha, int cord_coluna){
    m_maze[cord_linha][cord_coluna].paredes[3] = false;
}