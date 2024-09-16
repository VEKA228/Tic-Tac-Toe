#pragma once

#include "board.hpp"

class Game {
    Board _board;
    char _currentPlayer;
public:
    Game();
    void Play(); 
private:
    void SwitchPlayer();           
    Point GetPlayerMove() const; 
};
