#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <memory>  // unique_ptr<>
#include <cstring> // memset, memcpy
#include <vector>

namespace maze {
    /**
     * @brief classe que representa o labirinto
     * 
     */
    class Maze
    {
        public:
            /// estrutura que representa uma celula do labirinto
            struct celula 
            {
                enum tipo { LIVRE, ENTRADA, SAIDA, CAMINHO, CAMINHO_DESCARTADO };
                enum estados { VISITADA, NAO_VISITADA, FAZ_PARTE_DO_CAMINHO, NAO_FAZ_PARTE_DO_CAMINHO };
                bool walls[4]; /// paredes norte, sul, leste, oeste
            };
            //=== Alias
            using maze_matrix = std::vector<std::vector<celula> >; /// apelido para a matrix que representa o labirinto
        public:

            //=== Special members
            Maze( /*algo*/ )
            { /*algo*/ }

            /// Destructor.
            virtual ~Maze( void )
            {
                // TODO 
            }

            //=== Special members
            /// Copy constructor.
            Maze( const Maze & );
            /// Assignment operator.
            Maze & operator=( const Maze & );

            //=== Members

        private:
            //=== Members
            maze_matrix m_maze; /// matrix que representa o labirinto
            int m_rows; /// linhas de m_maze
            int m_columns; /// colunas de m_maze
    };
} // namespace

#endif // MAZE_H
