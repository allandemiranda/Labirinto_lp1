#ifndef RENDER_H
#define RENDER_H

#define STB_IMAGE_WRITE_IMPLEMENTATION /// define da biblioteca de png 
#include "../include/stb_image_write.h" /// biblioteca de png 

#include <iostream>
#include <memory>  // unique_ptr<>
#include <cstring> // memset, memcpy
#include <vector>

#include "../include/canvas.h"

namespace render {
    /**
     * @brief classe que renderiza as imagem do labirinto e manda para a imagem de saida específica
     * 
     */
    class Render
    {
        public:
            //=== Alias
            
        public:

            //=== Special members
            Render( /*algo*/ )
            { /*algo*/ }

            /// Destructor.
            virtual ~Render( void )
            {
                // TODO 
            }

            //=== Special members
            /// Copy constructor.
            Render( const Render & );
            /// Assignment operator.
            Render & operator=( const Render & );

            //=== Members

        private:
        
    };
} // namespace

#endif // RENDER_H
