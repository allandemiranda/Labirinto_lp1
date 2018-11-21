#include <iostream>
#include <cstring>

#define STB_IMAGE_WRITE_IMPLEMENTATION /// define da biblioteca de png
#include "../include/stb_image_write.h" /// biblioteca de png

#include "../include/magos.h"

int main( int argc, char **argv )
{
    /// talvez precise acrescentar mais coisas, mas acho que não vai precisar
    magos::Magos labirinto;

    while( not labirinto.gameover )
	{
        labirinto.initializer();
        labirinto.update();
        labirinto.render();
	} 
}
