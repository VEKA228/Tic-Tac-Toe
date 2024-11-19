#include "game.hpp"
#include <iostream>

int main() {
    std::cout << "Inceperea jocului Tic-Tac-Toe...\n";
    
    Game game;
    game.Play();
    
    std::cout << "Jocul s-a terminat.\n";
    return 0;
}
