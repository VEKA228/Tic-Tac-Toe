/**
 * @file point.hpp
 * @brief Defines the Point class.
 * @author Sumschi Victoria
 * @date 11/29/2024
 */

#pragma once
/**
 * @class Point
 * @brief Represents a point in a 2D grid.
 */
#include <iostream>
#include <memory>

struct Point {
    int x; ///< The x-coordinate of the point.
    int y; ///< The y-coordinate of the point.

    /**
     * @brief Constructs a Point with specified coordinates.
     * @param _x The x-coordinate (default is 0).
     * @param _y The y-coordinate (default is 0).
     */

    // Constructor implicit
    Point(int _x = 0, int _y = 0);

     /**
     * @brief Constructs a Point as a copy of another Point.
     * @param other The Point to copy.
     */
    
    // Constructor de copiere
    Point(const Point& other);
    
    /**
     * @brief Assigns values from another Point to this Point.
     * @param other The Point to copy values from.
     * @return A reference to the current Point.
     */

    // Operator de copiere
    Point& operator=(const Point& other);

    /**
     * @brief Compares two Points for equality.
     * @param other The Point to compare against.
     * @return True if both Points have the same x and y coordinates, false otherwise.
     */
    // Operator de comparație
    bool operator==(const Point& other) const;
};

/**
 * @brief Reads a Point from an input stream.
 * @param in The input stream.
 * @param point The Point object to store the input.
 * @return A reference to the input stream.
 */
// Operator de citire
std::istream& operator>>(std::istream& in, Point& point);

/**
 * @brief Outputs a Point to an output stream.
 * @param out The output stream.
 * @param point The Point object to output.
 * @return A reference to the output stream.
 */
// Operator de afișare
std::ostream& operator<<(std::ostream& out, const Point& point);
