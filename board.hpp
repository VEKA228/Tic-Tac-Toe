#pragma once
#include "point.hpp"

class Board {
public:
    Board(int width = 3, int height = 3);
    bool MakeMove(const Point& move, char player);
    bool CheckWin(char player) const;
    bool IsFull() const;
    void Clear();
    void GetBoardState(char board[3][3]) const;

private:
    char _board[3][3];
    int _width;
    int _height;
};
