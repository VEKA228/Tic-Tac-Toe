#include "game.hpp"
#include <iostream>

Game::Game() : _currentPlayer('X'), _board(std::make_unique<Board>()) {}

void Game::Play() {
    std::cout << "Reguli:\n";
    std::cout << "1. Jocul se joaca pe o tabla de 3x3\n";
    std::cout << "2. Jucatorii alterneaza sa puna X sau O in celulele libere\n";
    std::cout << "3. Primul jucator care reuseste sa alinieze 3 simboluri pe orizontala, verticala sau diagonala castiga\n";
    std::cout << "4. Daca tabla este plina si nu exista un castigator, jocul se termina egal\n";
    std::cout << "5. Pentru a face o miscare, introduceti coordonatele (x y), unde x si y sunt indexii celulei dorite, incepand de la 0 pana la 2\n";
    std::cout << "Exemplu: pentru a pune un simbol in coltul stanga-sus, introduceti '0 0'\n";
    std::cout << "Sa incepem!\n\n";

    while (true) { 
        _board->Clear(); 
        bool gameWon = false; 

        while (!_board->IsFull()) {
            std::cout << "Jucatorul " << _currentPlayer << " sa faca o miscare.\n";
            Point move = GetPlayerMove();
            if (_board->MakeMove(move, _currentPlayer)) {
                _board->Display(); 

                if (_board->CheckWin(_currentPlayer)) {
                    std::cout << "Jucatorul " << _currentPlayer << " a castigat!\n";
                    gameWon = true; 
                    break; 
                }
                SwitchPlayer();
            } else {
                std::cout << "Miscare invalidă. Incearcă din nou.\n";
            }
        }

        if (!gameWon) {
            std::cout << "Tabla este plina. Niciun jucator nu a castigat.\n";
        }

        char playAgain;
        std::cout << "Vrei să joci din nou? (y/n): ";
        std::cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break; 
        }

        _board = std::make_unique<Board>();
    }
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