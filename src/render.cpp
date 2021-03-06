/**
 * @file render.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções da Class Render
 * @version 0.1
 * @date 2018-11-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

//#include <omp.h> // -fopenmp
#include <string> // std::to_string
#include "../include/render.h"

using namespace canvas;

/**
 * @brief Construct a new Render:: Render object
 * 
 * @param n_l Número de linhas no labirinto
 * @param n_c Número de colunas no labirinto
 * @param p_w Width da imagem
 * @param p_h Height da iamgem
 * @param stt Status de impressão building = 0, solveing = 1
 */
Render::Render(int n_c, int n_l, int p_w, int p_h, int stt){       
    n_colunas = n_c;      //! Número de colunas no labirinto
    n_linhas = n_l;       //! Número de linhas no labirinto
    p_width = p_w;        //! Width da imagem
    p_height = p_h;       //! Height da iamgem
    status = stt;         //! Status de impressão building = 0, solveing = 1
}

/**
 * @brief Função para desenhar o labirinto e salvar no local determinado
 * 
 * @param maze_ Class contendo toda a informação lógica do labirinto
 */
void Render::print(Maze maze_){
    Canvas canvas_(p_width, p_height);
    /// Pintar o fundo de branco
    canvas_.clear( WHITE );
    /// Determinar tamanho espacial da célula     
    int largura_p = ((p_width)/(n_colunas+2));    
    int altura_p = ((p_height)/(n_linhas+2));
    /// Verificar cada célula e desenhar    
    for(auto i(0); i<n_linhas; ++i){        
        for(auto j(0); j<n_colunas; ++j){
            /// Verificar posição inicial do desenho
            coord_type orig_x{ (size_t)( (j*largura_p)+largura_p ) }, orig_y{ (size_t) ( (i*altura_p)+altura_p ) };
            canvas_.thickness( 3 );
            /// Verificando paredes e desenhando se possivel            
            if(maze_.status_celula_parede_norte(j,i)){
                canvas_.hline(orig_x, orig_y, largura_p, BLACK);
            }
            if(maze_.status_celula_parede_sul(j,i)){
                canvas_.hline(orig_x, orig_y+altura_p, largura_p, BLACK);
            }
            if(maze_.status_celula_parede_leste(j,i)){
                canvas_.vline(orig_x+largura_p, orig_y, altura_p, BLACK);
            }
            if(maze_.status_celula_parede_oeste(j,i)){
                canvas_.vline(orig_x, orig_y, altura_p, BLACK);
            }
            /// Verificando status da célula e desenhando se não for livre            
            if(maze_.status_celula_entrada(j,i)){
                if(!maze_.status_celula_parede_sul(j,i)){
                    if(maze_.status_celula_caminho(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, RED);
                    }
                    if(maze_.status_celula_caminho_descartado(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                }
                if(!maze_.status_celula_parede_leste(j,i)){
                    if(maze_.status_celula_caminho(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, RED);
                    }
                    if(maze_.status_celula_caminho_descartado(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                }
                canvas_.box( orig_x+4+(largura_p/3), orig_y+4+(altura_p/3), largura_p/3, altura_p/3, DEEP_SKY_BLUE );
            }
            if(maze_.status_celula_saida(j,i)){
                canvas_.box( orig_x+4+(largura_p/3), orig_y+4+(altura_p/3), largura_p/3, altura_p/3, GREEN );
            }
            if(maze_.status_celula_caminho(j,i)){
                if(!maze_.status_celula_parede_norte(j,i)){
                    if(maze_.status_celula_caminho(j,i-1)){
                        canvas_.box(orig_x+4+(largura_p/3),orig_y, largura_p/3, altura_p/3 + 4, RED);
                    }
                    if(maze_.status_celula_caminho_descartado(j,i-1)){
                        canvas_.box(orig_x+4+(largura_p/3),orig_y, largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j,i-1)){
                        canvas_.box(orig_x+4+(largura_p/3),orig_y, largura_p/3, altura_p/3 + 4, RED);
                    }
                }
                if(!maze_.status_celula_parede_sul(j,i)){
                    if(maze_.status_celula_caminho(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, RED);
                    }
                    if(maze_.status_celula_caminho_descartado(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, RED);
                    }
                }
                if(!maze_.status_celula_parede_leste(j,i)){
                    if(maze_.status_celula_caminho(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, RED);
                    }
                    if(maze_.status_celula_caminho_descartado(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, RED);
                    }
                }
                if(!maze_.status_celula_parede_oeste(j,i)){
                    if(maze_.status_celula_caminho(j-1,i)){
                        canvas_.box(orig_x+4,orig_y+4+(altura_p/3), largura_p/3, altura_p/3, RED);
                    }
                    if(maze_.status_celula_caminho_descartado(j-1,i)){
                        canvas_.box(orig_x+4,orig_y+4+(altura_p/3), largura_p/3, altura_p/3, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j-1,i)){
                        canvas_.box(orig_x+4,orig_y+4+(altura_p/3), largura_p/3, altura_p/3, RED);
                    }
                }
                canvas_.box( orig_x+4+(largura_p/3), orig_y+4+(altura_p/3), largura_p/3, altura_p/3, RED );
            }
            if(maze_.status_celula_caminho_descartado(j,i)){                
                if(!maze_.status_celula_parede_norte(j,i)){
                    if(maze_.status_celula_caminho(j,i-1)){
                        canvas_.box(orig_x+4+(largura_p/3),orig_y, largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                    if(maze_.status_celula_caminho_descartado(j,i-1)){
                        canvas_.box(orig_x+4+(largura_p/3),orig_y, largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j,i-1)){
                        canvas_.box(orig_x+4+(largura_p/3),orig_y, largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                }
                if(!maze_.status_celula_parede_sul(j,i)){
                    if(maze_.status_celula_caminho(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                    if(maze_.status_celula_caminho_descartado(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j,i+1)){
                        canvas_.box(orig_x+(largura_p/3)+4,orig_y+4+((altura_p/3)*2), largura_p/3, altura_p/3 + 4, YELLOW);
                    }
                }
                if(!maze_.status_celula_parede_leste(j,i)){
                    if(maze_.status_celula_caminho(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                    if(maze_.status_celula_caminho_descartado(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j+1,i)){
                        canvas_.box(orig_x+4+((largura_p/3)*2),orig_y+4+((altura_p/3)), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                }
                if(!maze_.status_celula_parede_oeste(j,i)){
                    if(maze_.status_celula_caminho(j-1,i)){
                        canvas_.box(orig_x+4,orig_y+4+(altura_p/3), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                    if(maze_.status_celula_caminho_descartado(j-1,i)){
                        canvas_.box(orig_x+4,orig_y+4+(altura_p/3), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                    if(maze_.status_celula_entrada(j-1,i)){
                        canvas_.box(orig_x+4,orig_y+4+(altura_p/3), largura_p/3 + 4, altura_p/3, YELLOW);
                    }
                }
                canvas_.box( orig_x+4+(largura_p/3), orig_y+4+(altura_p/3), largura_p/3, altura_p/3, YELLOW );
            }
        }
    }
    /// Verificar onde salvar
    auto width = canvas_.width();
    auto height = canvas_.height();
    auto pixels = canvas_.buffer();
    stbi_write_png_compression_level = 0;
    if(status == 0){
        std::string temp_name = "builder/building_"+std::to_string(numero)+".png";
        char *c_temp_name = new char[temp_name.length() + 1];
        std::strcpy(c_temp_name, temp_name.c_str());
        stbi_write_png( c_temp_name,      /// file name
                    width, height,        /// image dimensions
                    3,                    /// # of channels per pixel
                    pixels,               /// the pixels
                    width*3)  ;           /// length of a row (in bytes), see above.
        delete[] c_temp_name;
        numero++;
    } else {
        std::string temp_name = "solver/solving_"+std::to_string(numero)+".png";
        char *c_temp_name = new char[temp_name.length() + 1];
        std::strcpy(c_temp_name, temp_name.c_str());
        stbi_write_png( c_temp_name,      /// file name
                    width, height,        /// image dimensions
                    3,                    /// # of channels per pixel
                    pixels,               /// the pixels
                    width*3)  ;           /// length of a row (in bytes), see above.
        delete[] c_temp_name;
        numero++;
    }  
}