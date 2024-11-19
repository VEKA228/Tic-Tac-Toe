#pragma once
#include "board.hpp"
#include "point.hpp"
#include <memory>

class Game {
public:
    Game();
    void Play();

private:
    void SwitchPlayer();
    Point GetPlayerMove() const;

    char _currentPlayer; 
    std::unique_ptr<Board> _board;  // smart pointer
};

