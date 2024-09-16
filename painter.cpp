#include "painter.hpp"
#include <iostream>

void Painter::DrawText(Point position, const char* text) {
    // Deocamdată, afișăm doar textul la poziția dată
    std::cout << "Textul: " << text << " la poziția (" << position.x << ", " << position.y << ")\n";
}
