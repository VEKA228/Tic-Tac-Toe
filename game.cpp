#include "game.hpp"

Game::Game() : _currentPlayer('X') {}

void Game::Play() {
    _board.Clear();
    while (!_board.IsFull()) {
        Point move = GetPlayerMove();
        if (_board.MakeMove(move, _currentPlayer)) {
            if (_board.CheckWin(_currentPlayer)) {
                return;
            }
            SwitchPlayer();
        }
    }
}

void Game::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == 'X') ? 'O' : 'X';
}

Point Game::GetPlayerMove() const {
    Point p;
    // Aici ar fi logica pentru obținerea unei mișcări valide
    return p;
}
