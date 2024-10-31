#pragma once
#include "board.hpp"
#include "point.hpp"

class Game {
public:
    Game();
    void Play();

private:
    void SwitchPlayer();
    Point GetPlayerMove() const;

    Board _board;
    char _currentPlayer;
};
