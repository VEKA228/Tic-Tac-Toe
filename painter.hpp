#pragma once
#include "point.hpp"

class Painter {
public:
    Painter();
    void DrawBoard(const char board[3][3]);
    void DisplayMessage(const char* message);
};
