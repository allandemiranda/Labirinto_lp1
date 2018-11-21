#ifndef MAGOS_H
#define MAGOS_H

#include <iostream>
#include <memory>  // unique_ptr<>
#include <cstring> // memset, memcpy
#include <vector>
#include <list> // list
#include <set> // set
#include "../include/canvas.h"
#include "../include/maze.h"
#include "../include/render.h"

namespace magos {
    /**
     * @brief classe principal que vai chamar todas as outras.
     * 
     */
    class Magos
    {
        public:
            //=== Alias
            using set_list_path = std::list<std::set<maze::Maze::celula> >; /// apelido para a lista de dicionario de celulas do labirinto
        public:

            //=== Special members
            Magos( /*algo*/ )
            { /*algo*/ }

            /// Destructor.
            virtual ~Magos( void )
            {
                // TODO 
            }

            //=== Special members
            /// Copy constructor.
            Magos( const Magos & );
            /// Assignment operator.
            Magos & operator=( const Magos & );

            //=== Members
            bool initializer(); /// configura todos os parâmetros de objetos instanciados no construtor. Este método deve validar os argumentos de entrada.
            void update(); /// Este método deve avançar a simulação atual (construir ou resolver) uma única etapa. E nele estão os estados = start, build, solve, erro, done;
            void render(); /// este é o método que envia a imagem atual do labirinto para um arquivo de imagem de saída.
            bool done(); /// este método retorna true somente se a simulação terminar. Isso pode acontecer quando os processos de construção e resolução são concluídos ou se ocorrer um erro durante a execução.
            
            //=== Variáveis necessárias
            bool gameover; /// status que identifica se é o fim do gameloop

        private:
            //=== Members
            void builder(); /// usado na construção do labirinto
            void solver(); /// usado na solução do labirinto
            /// OBS: outros métodos auxiliares serão acrescentados

            //=== Variáveis necessárias
            /// instancias de cada um objeto das classes Canvas, Maze, Render
            canvas::Canvas m_canvas; 
            maze::Maze m_maze;
            render::Render m_render;

    };
} // namespace

#endif // MAGOS_H
