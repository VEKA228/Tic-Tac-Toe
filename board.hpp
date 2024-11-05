#pragma once
#include "point.hpp"
#include <iostream>
#include <vector>
#include <memory>

class Board {
    int _width;
    int _height;
    std::vector<std::vector<char>> _board; // STL cont

public:
    // Constructor implicit și cu parametri
    Board(int width = 3, int height = 3);

    // Constructor de copiere
    Board(const Board& other);
    
    // Operator de copiere
    Board& operator=(const Board& other);

    // Operator de comparație
    bool operator==(const Board& other) const;

    // Metode de joc
    bool MakeMove(const Point& move, char player);
    bool CheckWin(char player) const;
    bool IsFull() const;
    void Clear();
    void Display() const;

    // Operatorii de citire și afișare
    friend std::istream& operator>>(std::istream& in, Board& board);
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};


