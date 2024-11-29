
/**
 * @file board.hpp
 * @brief Defines the Board class used to represent the Tic-Tac-Toe game board.
 * @author Sumschi Victoria
 * @date 11/29/2024
 */

#pragma once
#include "point.hpp"
#include <iostream>
#include <vector>
#include <memory>

/**
 * @class Board
 * @brief Represents the game board for Tic-Tac-Toe.
 * 
 * The Board class manages the state of the game board, handles player moves, 
 * and provides functionality to check for wins, determine if the board is full, 
 * and reset the board for a new game.
 */

class Board {
    int _width; ///< The width of the game board.
    int _height; ///< The height of the game board.
    std::vector<std::vector<char>> _board; ///< 2D vector to store board cells.

public:
/**
     * @brief Constructs a Board with given dimensions.
     * @param width The width of the board (default is 3).
     * @param height The height of the board (default is 3).
     */

    // Constructor implicit și cu parametri
    Board(int width = 3, int height = 3);

    /**
     * @brief Constructs a Board as a copy of another Board.
     * @param other The Board to copy.
     */

    // Constructor de copiere
    Board(const Board& other);
    
    /**
     * @brief Assigns the values from another Board to this Board.
     * @param other The Board to copy from.
     * @return A reference to the current Board.
     */

    // Operator de copiere
    Board& operator=(const Board& other);

    /**
     * @brief Compares two Boards for equality.
     * @param other The Board to compare against.
     * @return True if the Boards have the same dimensions and state, false otherwise.
     */

    // Operator de comparație
    bool operator==(const Board& other) const;

    /**
     * @brief Makes a move on the board for a player.
     * @param move The Point where the move is made.
     * @param player The character representing the player ('X' or 'O').
     * @return True if the move is valid and made successfully, false otherwise.
     */

    // Metode de joc
    bool MakeMove(const Point& move, char player);
        /**
     * @brief Checks if a player has won the game.
     * @param player The character representing the player ('X' or 'O').
     * @return True if the player has a winning line, false otherwise.
     */

    bool CheckWin(char player) const;
        /**
     * @brief Checks if the board is full.
     * @return True if all cells are occupied, false otherwise.
     */

    bool IsFull() const;
        /**
     * @brief Clears the board, resetting it for a new game.
     */

    void Clear();
        /**
     * @brief Displays the board in a readable format.
     */

    void Display() const;
        /**
     * @brief Reads a Board from an input stream.
     * @param in The input stream.
     * @param board The Board object to populate.
     * @return A reference to the input stream.
     */

    // Operatorii de citire și afișare
    friend std::istream& operator>>(std::istream& in, Board& board);
        /**
     * @brief Outputs a Board to an output stream.
     * @param out The output stream.
     * @param board The Board object to output.
     * @return A reference to the output stream.
     */

    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};


