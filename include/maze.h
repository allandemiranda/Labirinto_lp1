#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <memory>  // unique_ptr<>
#include <cstring> // memset, memcpy
#include <vector>

namespace maze {
    /**
     * @brief Classe que representa o labirinto
     * 
     */
    class Maze
    {
        public:            
            /**
             * @brief Estrutura que representa uma celula do labirinto
             * 
             */
            struct celula 
            {
                enum tipo { LIVRE, ENTRADA, SAIDA, CAMINHO, CAMINHO_DESCARTADO };
                enum estados { VISITADA, NAO_VISITADA, FAZ_PARTE_DO_CAMINHO, NAO_FAZ_PARTE_DO_CAMINHO };
                bool walls[4] = {1,1,1,1}; /// paredes norte, sul, leste, oeste
            };
            //=== Alias
            using maze_matrix = std::vector<std::vector<celula> >; /// apelido para a matrix que representa o labirinto

            //=== Special members
            Maze( void )
            { //FAZER ESSA PARTE ALLAN
                for(auto i(0u); i<m_rows; ++i){
                    std::vector <celula> temp;
                    for(auto j(0u); j<m_columns; ++j){
                        //nova_celula celula;
                        //nova_celula.tipo(LIVRE)
                        //temp.push_back();                                           
                    }
                }
                //m_maze[0][0].ENTRADA;
               // m_maze[m_rows-1][m_columns-1].SAIDA;
            }

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
            void set_rows( int r ) { m_rows = r; }
            int get_rows() { return m_rows; }

            void set_columns( int c ) { m_columns = c; }
            int get_columns() { return m_columns; }

            void set_width( size_t w ) { m_width = w; }
            int get_width() { return m_width; }

            void set_height( size_t h ) { m_height = h; }
            size_t get_height() { return m_height; }

            /// para pegar o labirinto
            maze_matrix get_maze() { return m_maze; }
            
        private:
            //=== Members
            maze_matrix m_maze; /// matrix que representa o labirinto
            int m_rows; /// linhas de m_maze
            int m_columns; /// colunas de m_maze
            size_t m_width;
            size_t m_height;
    };
} // namespace

#endif // MAZE_H
