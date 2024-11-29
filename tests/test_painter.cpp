#include "../include/painter.hpp"
#include <cassert>

int main() {
    Painter painter;

    // Test DrawImage
    char* image[2];
    char row1[] = {'X', 'O'};
    char row2[] = {'O', 'X'};
    image[0] = row1;
    image[1] = row2;

    painter.DrawImage(Point(0, 0), Point(2, 2), image);

    // Test WriteText
    painter.WriteText(Point(1, 1), "Hello, Tic-Tac-Toe!");

    return 0;
}
