#include "../include/magos.h"

bool magos::Magos::initializer( int argc, char **argv )
{
    int argv2[argc];
    for( unsigned short i(0); i < argc; ++i )
    {
        argv2[i] = std::atoi(argv[i]);
    }
    if( argc < 5 or argc > 5 )
    {
        std::cerr<< "Erro: número incorreto de argumento \n" << "São 4 argumentos, ex: [ linhas, colunas, largura, altura ]" << '\n';
        return false; 
    }
    else if( argv2[1] < 1 or argv2[2] < 1 or argv2[3] < 1 or argv2[4] < 1 )
    {
        std::cerr<< "Erro: argumento fora da faixa permitida \n" << "Apenas argumentos maiores que zero são válidos"<< '\n';
        return false; 
    }
    else if( argv2[1] == 1 and argv2[2] == 1 )
    {
        std::cerr<< "Erro: Argumentos 1 e 2 não podem ter 1 como mesmo valor\n";
        return false;
    }
    else
    {
        // this->m_maze.set_rows(argv2[1]);
        // this->m_maze.set_columns(argv2[2]);
        // this->m_maze.set_width(argv2[3]);
        // this->m_maze.set_height(argv2[4]);
        return true;
    }
}

void magos::Magos::render(){
    
}
