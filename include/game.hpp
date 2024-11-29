/**
 * @file game.hpp
 * @brief Defines the Game class, the core logic for the Tic-Tac-Toe gameplay.
 * @author Sumschi Victoria
 * @date 11/29/2024
 */

#pragma once
#include "board.hpp"
#include "point.hpp"
#include <memory>

/**
 * @class Game
 * @brief Manages the main gameplay logic for Tic-Tac-Toe.
 * 
 * The Game class coordinates the interaction between players and the game board,
 * handling turns, player moves, and determining game progression.
 */
class Game {
public:
    /**
     * @brief Constructs a Game object and initializes the board and the current player.
     */
    Game();

        /**
     * @brief Starts and manages the main game loop.
     * 
     * This function handles turn-taking, user input for moves, and checks for
     * game-winning conditions or draws.
     */
    void Play();

private:
    /**
     * @brief Switches the active player after a turn is completed.
     */
    void SwitchPlayer();

        /**
     * @brief Retrieves the move from the active player.
     * @return A Point object representing the player's chosen move.
     */
    Point GetPlayerMove() const;

    char _currentPlayer; ///< The current player's symbol ('X' or 'O').
    std::unique_ptr<Board> _board; ///< Pointer to the game board (dynamically allocated).
};

