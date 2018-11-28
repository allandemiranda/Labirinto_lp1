/**
 * @file builder.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções class Builder
 * @version 0.1
 * @date 2018-11-25
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <cstdlib>      // std::rand
#include <vector>       // std::vector
#include <algorithm>    // std::binary_search , std::sort
#include <ctime>
#include "../include/builder.h"
#include "../include/maze.h"

// #include <iostream> // Para o DEBUG

/**
 * @brief Construct a new Builder::Builder object
 * 
 * @param num_linhas Quantidade de Linhas que a matriz do labirinto tem
 * @param num_colunas Quantidade de Colunas que a martiz do labirinto tem
 */
Builder::Builder(int num_colunas, int num_linhas){
    int contador = 0;
    for(int i(0); i<num_colunas; ++i){
        for(int j(0); j<num_linhas; ++j){
            indices_restantes.push_back(contador);            
            ++contador;
        }
    }
    indices_selecionados.push_back(0);
    indices_restantes.erase(indices_restantes.begin());    
    tamanho_coluna = num_colunas;
    tamanho_linha = num_linhas;
}

/**
 * @brief Verificar se já foram derrubadas as paredes suficientes
 * 
 * @return true Se ainda estiver derrubando
 * @return false Se ja parou de derrubar
 */
bool Builder::status_builder(void){
    if(indices_restantes.size()!=0){
        return true;
    }
    return false;
}

/**
 * @brief Função para verificar labirinto e derrubar a parede escolhida
 * 
 * @param maze_ Class do labirinto
 */
void Builder::derrubar_parede(Maze &maze_){
    std::srand(std::time(0)); //use current time as seed for random generator
    while(status_builder()){    
        /// Selecionar um índice do conjunto do caminho    
        int sorteio = std::rand()%indices_selecionados.size();        
        /// Mostrar possibilidades para criar novo caminho
        std::vector <int> possiveis;
        if((indices_selecionados[sorteio]+1) < (tamanho_linha*tamanho_coluna)){
            int linha_sorteado = indices_selecionados[sorteio]/tamanho_coluna;
            int linha_sorteado_um = (indices_selecionados[sorteio]+1)/tamanho_coluna;
            if(linha_sorteado == linha_sorteado_um){
                possiveis.push_back(indices_selecionados[sorteio]+1);
            }
        }
        if((indices_selecionados[sorteio]-1) >= 0){
            int linha_sorteado = indices_selecionados[sorteio]/tamanho_coluna;
            int linha_sorteado_um = (indices_selecionados[sorteio]-1)/tamanho_coluna;
            if(linha_sorteado == linha_sorteado_um){
                possiveis.push_back(indices_selecionados[sorteio]-1);
            }            
        }
        if((indices_selecionados[sorteio]+tamanho_coluna) < (tamanho_linha*tamanho_coluna)){
            possiveis.push_back(indices_selecionados[sorteio]+tamanho_coluna);
        }
        if((indices_selecionados[sorteio]-tamanho_coluna) >= 0){
            possiveis.push_back(indices_selecionados[sorteio]-tamanho_coluna);
        }
        for(int i=(possiveis.size()-1); i>=0; --i){
            if(std::binary_search(indices_selecionados.begin(),indices_selecionados.end(),possiveis[i])){
                possiveis.erase(possiveis.begin()+i);
            }
        }
        /// Se o indice não tiver possibilidade, sortear um novo
        if(possiveis.size()==0){
            continue;
        }     
        /// Sortear possibilidade
        int sorteio_possivel = std::rand()%possiveis.size();
        bool flag = false;
        for(int i : possiveis){
            if(i == possiveis[sorteio_possivel]){
                flag = true;
                break;
            }
        }
        if(!flag){
            continue;
        }
        /// Verificar coordenada que os une (em relação ao índice sorteio)
        int cord_linha = indices_selecionados[sorteio]/tamanho_coluna;
        int cord_coluna = indices_selecionados[sorteio] - (cord_linha*tamanho_coluna);
        /// Derruba a parede correta
        /// Norte
        if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]-tamanho_coluna)){
            maze_.derrubar_parede_norte(cord_coluna, cord_linha);
            maze_.derrubar_parede_sul(cord_coluna, cord_linha-1);
            //std::cout << "NORTE" << std::endl; // DEBUG
        } else {
            /// Sul
            if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]+tamanho_coluna)){
                maze_.derrubar_parede_sul(cord_coluna, cord_linha);
                maze_.derrubar_parede_norte(cord_coluna, cord_linha+1);
                // std::cout << "SUL" << std::endl; // DEBUG
            } else {
                /// Leste
                if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]+1)){
                    maze_.derrubar_parede_leste(cord_coluna, cord_linha);
                    maze_.derrubar_parede_oeste(cord_coluna+1, cord_linha);
                    // std::cout << "LESTE" << std::endl; // DEBUG
                } else {
                    /// Oeste
                    if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]-1)){
                        maze_.derrubar_parede_oeste(cord_coluna, cord_linha);
                        maze_.derrubar_parede_leste(cord_coluna-1, cord_linha);
                        // std::cout << "OESTE" << std::endl;
                    } else {
                        // std::cout << "ERRO FATAL" << std::endl; // DEBUG
                    }
                }
            }
        }
        /// Migrar o índice para um já selecionado
        for(auto i(0u); i<indices_restantes.size(); ++i){
            if(possiveis[sorteio_possivel] == indices_restantes[i]){
                indices_restantes.erase(indices_restantes.begin()+i);
                indices_selecionados.push_back(possiveis[sorteio_possivel]);
                std::sort(indices_selecionados.begin(), indices_selecionados.end());
                break;
            }
        }

        /** // DEBUG ÁREA
        std::cout << "Sorteou: " << indices_selecionados[sorteio] << "->" << sorteio << std::endl;
        std::cout << "Possiveis com ele: ";
        for(int i : possiveis){
            std::cout << i << " ";
        }std::cout << std::endl;
        std::cout << "Escolheu: " << possiveis[sorteio_possivel] << std::endl;
        std::cout << "Derrubar parede entre " << indices_selecionados[sorteio] << " | "
        << possiveis[sorteio_possivel] << std::endl;
        std::cout << "Paredes " << indices_selecionados[sorteio] << " : ";
        for(int i : maze_.m_maze[cord_coluna][cord_linha].paredes){
            std::cout << i << " ";
        }std::cout << std::endl;  
        for(int i : indices_restantes){
            std::cout << i << " ";
        }std::cout << std::endl;
        for(int i : indices_selecionados){
            std::cout << i << " ";
        }std::cout << std::endl;std::cout << std::endl;
        */

        break;
    }
}