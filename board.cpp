#include "board.hpp"

// Constructor implementation
Board::Board(int width, int height) : _width(width), _height(height) {
    Clear(); // Initialize the board to empty state
}

// Clear the board
void Board::Clear() {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            _board[i][j] = ' '; // Fill the board with empty spaces
        }
    }
}

// MakeMove implementation
bool Board::MakeMove(const Point& move, char player) {
    if (move.x >= 0 && move.x < _width && move.y >= 0 && move.y < _height && _board[move.y][move.x] == ' ') {
        _board[move.y][move.x] = player; // Place the player's move on the board
        return true; // Move was successful
    }
    return false; // Move failed (invalid or occupied)
}

// CheckWin implementation
bool Board::CheckWin(char player) const {
    // Check rows
    for (int i = 0; i < _height; ++i) {
        if ((_board[i][0] == player && _board[i][1] == player && _board[i][2] == player)) {
            return true; // Player wins by row
        }
    }
    // Check columns
    for (int j = 0; j < _width; ++j) {
        if ((_board[0][j] == player && _board[1][j] == player && _board[2][j] == player)) {
            return true; // Player wins by column
        }
    }
    // Check diagonals
    return ((_board[0][0] == player && _board[1][1] == player && _board[2][2] == player) || 
            (_board[0][2] == player && _board[1][1] == player && _board[2][0] == player));
}

// IsFull implementation
bool Board::IsFull() const {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            if (_board[i][j] == ' ') return false; // Empty space found
        }
    }
    return true; // No empty spaces found
}

// GetBoardState implementation (optional, if you want to retrieve the board state)
void Board::GetBoardState(char board[3][3]) const {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            board[i][j] = _board[i][j]; // Copy the current state of the board
        }
    }
}
