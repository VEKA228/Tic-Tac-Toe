#pragma once

#include "point.hpp"

class Board {
    char _grid[3][3]; 
public:
    Board();
    void Display() const;          
    bool MakeMove(Point p, char player);  
    bool IsFull() const;          
    bool CheckWin(char player) const;
};
