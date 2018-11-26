/**
 * @file solver.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções class Solver
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <vector>   // std::vector
#include <cstdlib>  // std::rand
#include "../include/solver.h"

/**
 * @brief Construct a new Solver:: Solver object
 * 
 * @param num_linha Quantidade de Linhas que a matriz do labirinto terá
 * @param num_coluna Quantidade de Colunas que a martiz do labirinto terá 
 * @param maze_ O labirinto
 */
Solver::Solver(int num_linha, int num_coluna, Maze & maze_){
    /**
     * @brief configurando controles de organização
     * 
     */
    t_linha = num_linha;
    t_coluna = num_coluna;
    saida = (num_linha*num_coluna) - 1;
    posicao_atual = 0;
    lista.push_back(0);

    /**
     * @brief Mapear e preencher tabela de solução
     * 
     */
    for(int i(0); i<(num_linha*num_coluna); ++i){
        std::vector <int> temp;
        // Calcular coordenada do índice i
        int cord_linha = (i / num_coluna);
        int cord_coluna = (i - (cord_linha * num_coluna));
        // Verificar possibilidades
        if(maze_.status_celula_parede_norte(cord_linha,cord_coluna)){
            temp.push_back(i-num_coluna);
        }
        if(maze_.status_celula_parede_sul(cord_linha,cord_coluna)){
            temp.push_back(i+num_coluna);
        }
        if(maze_.status_celula_parede_leste(cord_linha,cord_coluna)){
            temp.push_back(i+1);
        }
        if(maze_.status_celula_parede_leste(cord_linha,cord_coluna)){
            temp.push_back(i-1);
        }
        // Adicionar a tabela
        tabela.push_back(temp);
    }
}

/**
 * @brief Verifica se o labirinto já foi resolvido
 * 
 * @return true Se ainda não foi resolvido
 * @return false Se já foi resolvido
 */
bool Solver::status_resolver(void){
    if(*(lista.end()-1) == ((t_linha*t_coluna)-1)){
        return false;
    }
    return true;
}

/**
 * @brief Resolver o labirinto
 * 
 * @param maze_ Class que contem dados do labirinto
 */
void Solver::resolver(Maze & maze_){
    // Movimentação lógica
    // Verificar as possibilidades de seguir no labirinto
    std::vector <int> possibilidades;
    for(int i(0); i<tabela[posicao_atual].size(); ++i){
        possibilidades.push_back(tabela[posicao_atual][i]);
    }
    for(int i = (possibilidades.size()-1); i>=0; --i){
        for(int j(0); j<lista.size(); ++j){
            if(possibilidades[i] == lista[j]){
                possibilidades.erase(possibilidades.begin()+i);
                break;
            }
        }
    }
    if(possibilidades.size()>0){
        int indice_sorteado = std::rand()%possibilidades.size();
        // Aviciona a lista o índice
        lista.push_back(possibilidades[indice_sorteado]);
        // Exclui o índice da tabela
        for(int i(0); i<tabela[posicao_atual].size(); ++i){
            if(possibilidades[indice_sorteado] == tabela[posicao_atual][i]){
                tabela[posicao_atual].erase(tabela[posicao_atual].begin()+i);
                break;
            }
        }    
        // Atualiza posição
        posicao_atual = possibilidades[indice_sorteado];        
        // Modificar no labirinto o status das células envolvidas
        int cord_linha = (*(lista.end()-1) / t_coluna);
        int cord_coluna = (*(lista.end()-1) - (cord_linha * t_coluna));
        maze_.modificar_para_caminho(cord_linha,cord_coluna);
    } else {        
        // Modificar no labirinto o status das células envolvidas
        int cord_linha = (*(lista.end()-1) / t_coluna);
        int cord_coluna = (*(lista.end()-1) - (cord_linha * t_coluna));
        maze_.modificar_para_caminho_descartado(cord_linha,cord_coluna);
        // Terminar movimentação lógica
        lista.pop_back();
        posicao_atual = *(lista.end()-1);
    }
}