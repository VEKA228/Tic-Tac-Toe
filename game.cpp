#include "game.hpp"
#include <iostream>

Game::Game() : _currentPlayer('X') {}

void Game::Play() {
    _board.Clear();
    while (!_board.IsFull()) {
        std::cout << "Jucătorul " << _currentPlayer << " să facă o mișcare.\n";
        Point move = GetPlayerMove();
        if (_board.MakeMove(move, _currentPlayer)) {
            _board.Display(); // opțional: să afișeze tabla după fiecare mutare

            if (_board.CheckWin(_currentPlayer)) {
                std::cout << "Jucătorul " << _currentPlayer << " a câștigat!\n";
                return;
            }
            SwitchPlayer();
        } else {
            std::cout << "Mișcare invalidă. Încearcă din nou.\n";
        }
    }
    std::cout << "Remiză! Tabla este plină.\n";
}

void Game::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == 'X') ? 'O' : 'X';
}

Point Game::GetPlayerMove() const {
    Point p;
    std::cout << "Introdu coordonatele (x y): ";
    std::cin >> p.x >> p.y;
    return p;
}

