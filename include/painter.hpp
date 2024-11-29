/**
 * @file painter.hpp
 * @brief Defines the Painter class for rendering text and images in the Tic-Tac-Toe game.
 * @author Sumschi Victoria
 * @date 11/29/2024
 */

#pragma once
#include "abstract_painter.hpp"
#include "point.hpp"

/**
 * @class Painter
 * @brief Implements graphical operations for rendering the game using text-based graphics.
 * 
 * The Painter class provides methods to draw images and write text at specific
 * positions on a 2D grid. It inherits from AbstractPainter and overrides its methods.
 */

class Painter : public AbstractPainter {
public:
    /**
     * @brief Draws an image within the specified rectangular area.
     * 
     * @param topLeft The top-left corner of the rectangle.
     * @param bottomRight The bottom-right corner of the rectangle.
     * @param image A 2D character array representing the image.
     */
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) override;

        /**
     * @brief Writes text at the specified position on the board.
     * 
     * @param position The position where the text should be written.
     * @param text A constant character pointer to the text to be written.
     */
    virtual void WriteText(Point position, const char* text) override; 
};


