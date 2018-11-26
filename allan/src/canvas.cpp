/**
 * @file canvas.cpp
 * @author Allan de Miranda - Josué Cláudio
 * @brief Funções da Class Canvas
 * @version 0.1
 * @date 2018-11-25
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <stdexcept>
#include <iostream>

#include "../include/canvas.h"

namespace canvas {

    /*!
     * Deep copy of the canvas.
     * @param clone The object we are copying from.
     */
    Canvas::Canvas( const Canvas & clone )
    {
        this->m_height = clone.m_height;
        this->m_line_thikness = clone.m_line_thikness;
        this->m_pixels = clone.m_pixels;
        this->m_width = clone.m_width;
    }

    /*!
     * @param source The object we are copying information from.
     * @return A reference to the `this` object.
     */
    Canvas& Canvas::operator=( const Canvas & source )
    {
        this->m_height = source.m_height;
        this->m_line_thikness = source.m_line_thikness;
        this->m_pixels = source.m_pixels;
        this->m_width = source.m_width;
        return *this;
    }

    void Canvas::clear( const Color& color )
    {
        for( auto i(0u); i < m_height*m_width*3; i+=3 )
        {
            m_pixels[i] = color.channels[0];
            m_pixels[i+1] = color.channels[1];
            m_pixels[i+2] = color.channels[2];
        }
    }

    /*!
     * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to know the color of.
     * @return The pixel color.
     */
    Color Canvas::pixel( coord_type x, coord_type y ) const
    {
        // TODO
        if( x < m_height or x > m_height or y < m_width or y > m_width )
        {
            std::cerr<<"argumento inválido"<< '\n';
        }

        size_t offset_pixel( (y*m_width*3) + 3*x);
        return this->m_pixels[offset_pixel];
    }

    /*!
     * @note Nothing is done if the  pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to change the color.
     * @param c The color.
     */
    void Canvas::pixel( coord_type x, coord_type y, const Color& c )
    {
        size_t offset_pixel( (y*m_width*3) + 3*x);
        if( offset_pixel+2 <= m_width*m_height )
        {
            this->m_pixels[offset_pixel] = c.channels[0]; 
            this->m_pixels[offset_pixel+1] = c.channels[1]; 
            this->m_pixels[offset_pixel+2] = c.channels[2]; 
        }
    }

    /*!
     * Draws on the canvas a horizontal line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The horizontal length of the line in pixels.
     */
    void Canvas::hline( coord_type x, coord_type y, size_t length, const Color& color )
    {
        if( length <= m_height*m_width )
        {
            for( auto k(0); k < this->thickness(); ++k ) 
            {
                for( auto i( ( (y*m_width*3) + 3*x) ); i < ( ( (y*m_width*3) + 3*x)+(length*3) ); i+=3 )
                {
                    std::memcpy( m_pixels+i, color.channels, sizeof(color.channels) );
                }
                ++y;
            } 
        }        
    }

    /*!
     * Draws on the canvas a vertical line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The vertical length of the line in pixels.
     */
    void Canvas::vline( coord_type x, coord_type y, size_t length, const Color& color )
    {
        if( length <= m_height*m_width )
        {
            for( auto k(0); k < this->thickness(); ++k ) 
            {
                for( auto i( ( (y*m_width*3) + 3*x) ); i < ( ( (y*m_width*3) + 3*x)+(length*3*m_width) ); i+=3*m_width )
                {
                    std::memcpy( m_pixels+i, color.channels, sizeof(color.channels) );
                }
                ++x;
            } 
        }  
    }

    /*!
     * Draws on the canvas a filled box. The origin of the box is the top-left corner.
     * The box is compose of horizontal lines, drawn top to bottom.
     * @param p The 2D coordinate of the initial pixel of the box (top-left corner).
     * @param width The box's width in pixels.
     * @param height The box's heigth in pixels.
     */
    void Canvas::box( coord_type x, coord_type y, size_t width, size_t height , const Color& color)
    {
        size_t offset_pixel( (y*m_width*3) + 3*x);
        if( height <= m_height*m_width )
        {
            for( auto i(offset_pixel); i < offset_pixel+height*3; i+=3, ++x )
            {
                vline(x, y, height, color);
            }
        }
    }
}

//================================[ canvas.cpp ]================================//