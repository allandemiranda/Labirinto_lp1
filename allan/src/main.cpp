/**
 * @file main.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Menu inicial do jogo
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>

#include "../include/magos.h"

int main(int argc, char const *argv[])
{
    // Verificar se existem 4 argumentos
    if(argc != 4){
        std::cout << "Erro: número incorreto de argumento" << std::endl;
        std::cout << "São 4 argumentos, ex: [ linhas, colunas, largura, altura ]" << std::endl;
        return 0;
    }
    // Verificar se existem números negartivos
    for(int i(0); i<4; ++i){
        if(atoi(argv[i]) < 0){
            std::cout << "Erro: argumento fora da faixa permitida" << std::endl;
            std::cout << "Apenas argumentos maiores que zero são válidos" << std::endl;
            return 0;
        }
    }
    // Verificar se valores mínimos de tamanho do labirinto estão adequados
    for(int i(0); i<2; ++i){
        if(atoi(argv[i]) == 1){
            std::cout << "Erro: Argumentos 1 e 2 devem ser maiores que 1" << std::endl;
            return 0;
        }
    }

    // Gaming
    Magos magos_(atoi(argv[0]), atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

    // Fim do jogo
    return 0;
}
