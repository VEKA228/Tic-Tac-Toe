#include "board.hpp"
#include <iostream>
#include <algorithm>

// Constructor cu parametri
Board::Board(int width, int height) : _width(width), _height(height), _board(3, std::vector<char>(3, ' ')) {}

// Constructor de copiere
Board::Board(const Board& other) : _width(other._width), _height(other._height), _board(other._board) {}

// Operator de copiere
Board& Board::operator=(const Board& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        _board = other._board;
    }
    return *this;
}

// Operator de comparație
bool Board::operator==(const Board& other) const {
    return _width == other._width && _height == other._height && _board == other._board;
}

// Curăță tabla de joc
void Board::Clear() {
    for (auto& row : _board) {
        std::fill(row.begin(), row.end(), ' ');
    }
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
        if (std::all_of(_board[i].begin(), _board[i].end(), [player](char cell) { return cell == player; }) ||
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
    return std::all_of(_board.begin(), _board.end(), [](const std::vector<char>& row) {
        return std::all_of(row.begin(), row.end(), [](char cell) { return cell != ' '; });
    });
}

// Metoda Display pentru afișarea tablei de joc
void Board::Display() const {
    std::cout << *this;
}

// Operator de citire
std::istream& operator>>(std::istream& in, Board& board) {
    for (auto& row : board._board) {
        for (auto& cell : row) {
            in >> cell;
        }
    }
    return in;
}

// Operator de afișare
std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (const auto& row : board._board) {
        for (const auto& cell : row) {
            out << (cell == ' ' ? '.' : cell) << " ";
        }
        out << std::endl;
    }
    return out;
}
