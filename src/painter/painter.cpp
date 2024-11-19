#include "painter.hpp"
#include <iostream>

// desenarea bordului de joc
void Painter::DrawImage(Point topLeft, Point bottomRight, char** image) {
    for (int i = 0; i < bottomRight.x - topLeft.x; ++i) {
        for (int j = 0; j < bottomRight.y - topLeft.y; ++j) {
            std::cout << image[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// afișarea textului
void Painter::WriteText(Point position, const char* text) {
    std::cout << "Text at (" << position.x << ", " << position.y << "): " << text << std::endl;
}



