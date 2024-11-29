/**
 * @file abstract_painter.hpp
 * @brief Defines the abstract base class for rendering graphics in the Tic-Tac-Toe game.
 * @author Sumschi Victoria
 * @date 11/29/2024
 */

#pragma once
#include "point.hpp"

/**
 * @class AbstractPainter
 * @brief Abstract base class for rendering operations in the Tic-Tac-Toe game.
 * 
 * This class provides a blueprint for rendering operations such as drawing images
 * and writing text on a 2D grid. It must be inherited and its methods must be
 * implemented by derived classes.
 */
struct AbstractPainter {
        /**
     * @brief Draws an image within the specified rectangular area.
     * 
     * @param topLeft The top-left corner of the rectangle where the image will be drawn.
     * @param bottomRight The bottom-right corner of the rectangle.
     * @param image A 2D character array representing the image to be drawn.
     * 
     * This method must be implemented by derived classes to define the way images are drawn.
     */
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) = 0;
    
        /**
     * @brief Writes text at the specified position on the grid.
     * 
     * @param position The position on the grid where the text will be written.
     * @param text A constant character pointer to the text to be written.
     * 
     * This method must be implemented by derived classes to define how text is written.
     */
    virtual void WriteText(Point position, const char* text) = 0;
};
