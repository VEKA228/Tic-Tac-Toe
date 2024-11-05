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

    std::unique_ptr<Board> _board;  // smart pointer
    char _currentPlayer;
};
