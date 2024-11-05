#include "board.hpp"
#include <iostream>

// Constructor cu parametri
Board::Board(int width, int height) : _width(width), _height(height) {
    Clear(); 
}

// Constructor de copiere
Board::Board(const Board& other) : _width(other._width), _height(other._height) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _board[i][j] = other._board[i][j];
}

// Operator de copiere
Board& Board::operator=(const Board& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                _board[i][j] = other._board[i][j];
    }
    return *this;
}

// Operator de comparație
bool Board::operator==(const Board& other) const {
    if (_width != other._width || _height != other._height) return false;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (_board[i][j] != other._board[i][j]) return false;
    return true;
}

// Curăță tabla de joc
void Board::Clear() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _board[i][j] = ' ';
}

// Adaugă o mutare pentru jucătorul specificat
bool Board::MakeMove(const Point& move, char player) {
    if (move.x >= 0 && move.x < 3 && move.y >= 0 && move.y < 3 && _board[move.x][move.y] == ' ') {
        _board[move.x][move.y] = player;
        return true;
    }
    return false; 
}

// Verifică dacă jucătorul specificat a câștigat
bool Board::CheckWin(char player) const {
    for (int i = 0; i < 3; ++i) {
        if ((_board[i][0] == player && _board[i][1] == player && _board[i][2] == player) ||
            (_board[0][i] == player && _board[1][i] == player && _board[2][i] == player)) {
            return true;
        }
    }
    if ((_board[0][0] == player && _board[1][1] == player && _board[2][2] == player) ||
        (_board[0][2] == player && _board[1][1] == player && _board[2][0] == player)) {
        return true;
    }
    return false;
}

// Verifică dacă tabla este plină
bool Board::IsFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (_board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Metoda Display pentru afișarea tablei de joc
void Board::Display() const {
    std::cout << *this;
}

// Operator de citire
std::istream& operator>>(std::istream& in, Board& board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            in >> board._board[i][j];
    return in;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << (board._board[i][j] == ' ' ? '.' : board._board[i][j]) << " ";
        }
        out << std::endl;
    }
    return out;
}
