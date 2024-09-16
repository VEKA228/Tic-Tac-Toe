#include "game.hpp"
#include <iostream>

Game::Game() : _currentPlayer('X') {}

void Game::Play() {
    while (!_board.IsFull()) {
        _board.Display();
        Point move = GetPlayerMove();
        if (_board.MakeMove(move, _currentPlayer)) {
            if (_board.CheckWin(_currentPlayer)) {
                _board.Display();
                std::cout << "Jucătorul " << _currentPlayer << " a câștigat!\n";
                return;
            }
            SwitchPlayer();
        } else {
            std::cout << "Mutare invalidă! Încercați din nou.\n";
        }
    }
    std::cout << "Egalitate!\n";
}

void Game::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == 'X') ? 'O' : 'X';
}

Point Game::GetPlayerMove() const {
    Point p;
    std::cout << "Jucătorul " << _currentPlayer << ", introduceți mișcarea (rând și coloană): ";
    std::cin >> p.x >> p.y;
    return p;
}
