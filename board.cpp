#include "board.hpp"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _grid[i][j] = ' ';
}

void Board::Display() const {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << _grid[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -+-+-\n";
    }
}

bool Board::MakeMove(Point p, char player) {
    if (_grid[p.x][p.y] == ' ') {
        _grid[p.x][p.y] = player;
        return true;
    }
    return false;
}

bool Board::IsFull() const {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (_grid[i][j] == ' ') return false;
    return true;
}

bool Board::CheckWin(char player) const {
    for (int i = 0; i < 3; i++)
        if ((_grid[i][0] == player && _grid[i][1] == player && _grid[i][2] == player) || 
            (_grid[0][i] == player && _grid[1][i] == player && _grid[2][i] == player))
            return true;

    return (_grid[0][0] == player && _grid[1][1] == player && _grid[2][2] == player) ||
           (_grid[0][2] == player && _grid[1][1] == player && _grid[2][0] == player);
}
