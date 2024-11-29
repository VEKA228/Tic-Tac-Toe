#include "../include/board.hpp"
#include "../include/point.hpp"
#include <cassert>

int main() {
    Board board;

    // Test Clear
    board.Clear();
    assert(!board.IsFull());

    // Test MakeMove
    Point p1(0, 0);
    assert(board.MakeMove(p1, 'X'));  // Mutare valid
    assert(!board.MakeMove(p1, 'O')); // Mutare invalid (ocupat)

    // Test CheckWin
    board.MakeMove(Point(1, 1), 'X');
    board.MakeMove(Point(2, 2), 'X');
    assert(board.CheckWin('X'));  // X castiga pe diagonala

    return 0;
}
