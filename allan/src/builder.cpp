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
#include "../include/builder.h"

/**
 * @brief Construct a new Builder::Builder object
 * 
 * @param num_linhas Quantidade de Linhas que a matriz do labirinto tem
 * @param num_colunas Quantidade de Colunas que a martiz do labirinto tem
 */
Builder::Builder(int num_linhas, int num_colunas){
    int contador = 0;
    for(int i(0); i<num_linhas; ++i){
        for(int j(0); j<num_colunas; ++j){
            indices_restantes.push_back(contador);
            ++contador;
        }
    }
    int sorteio = std::rand()%indices_restantes.size();
    indices_selecionados.push_back(indices_restantes[sorteio]);
    indices_restantes.erase(indices_restantes.begin()+sorteio);
    tamanho_linha = num_linhas;
    tamanho_coluna = num_colunas;
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
    while(status_builder()){    
        // Selecionar um índice do conjunto do caminho    
        int sorteio = std::rand()%indices_selecionados.size();
        // Mostrar possibilidades para criar novo caminho
        std::vector <int> possiveis;
        if((indices_selecionados[sorteio]+1) < (tamanho_linha*tamanho_coluna)){
            possiveis.push_back(indices_selecionados[sorteio]+1);
        }
        if((indices_selecionados[sorteio]-1) >= 0){
            possiveis.push_back(indices_selecionados[sorteio]-1);
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
        // Se o indice não tiver possivilidade, sortear um novo
        if(possiveis.size()==0){
            continue;
        }
        // Sortear possibilidade
        int sorteio_possivel = std::rand()%possiveis.size();
        // Verificar coordenada que os une (em relação ao índice sorteio)
        int cord_linha = indices_selecionados[sorteio]/tamanho_coluna;
        int cord_coluna = indices_selecionados[sorteio] - (cord_linha*tamanho_coluna);
        // Derruba a parede correta
        // Norte
        if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]-tamanho_coluna)){
            maze_.derrubar_parede_norte(cord_linha, cord_coluna);
        } else {
            // Sul
            if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]+tamanho_coluna)){
                maze_.derrubar_parede_sul(cord_linha, cord_coluna);
            } else {
                // Leste
                if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]+1)){
                    maze_.derrubar_parede_leste(cord_linha, cord_coluna);
                } else {
                    // Oeste
                    if(possiveis[sorteio_possivel] == (indices_selecionados[sorteio]-1)){
                        maze_.derrubar_parede_oeste(cord_linha, cord_coluna);
                    } else {
                        // RETORNAR ERRO AO DERRUBAR PAREDE (DEBUG)
                    }
                }
            }
        }
        // Migrar o índice para um já selecionado
        for(int i(0); i<indices_restantes.size(); ++i){
            if(possiveis[sorteio_possivel] == indices_restantes[i]){
                indices_restantes.erase(indices_restantes.begin()+i);
                indices_selecionados.push_back(possiveis[sorteio_possivel]);
                std::sort(indices_selecionados.begin(), indices_selecionados.end());
                break;
            }
        }
        break;
    }
}