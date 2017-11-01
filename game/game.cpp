// Copyright 2017 Ermishin Michael

#include <iostream>

#include "game.h"
#include "board/board_printer_factory.h"

void Game::init()
{
    uint16_t size, target_score;
    std::cout << "Tic tac tie YxY. Score Z to win!" << std::endl;

    std::cout << "Please specify Y: ";
    std::cin >> size;

    std::cout << "Please specify Z: ";
    std::cin >> target_score;

    _board = std::make_unique<Board>(size, target_score);
    auto builder = std::make_unique<BoardPrinterFactory>(*_board);
    _printer.reset((*builder)
            .set_symbol(eCell::X, '0')
            .set_symbol(eCell::O, '1')
            .set_symbol(eCell::Empty, '.')
            .build());
}

bool Game::update()
{
    if (_winner != eWinner::NA) return false;

    uint16_t x, y;
    std::cout << "Place " << _printer->get_symbol(_board->get_current_player()) << " on (x y): ";
    std::cin >> x >> y;
    _board->do_turn(x, y);

    _winner = _board->calculate_winner();
    return true;
}

void Game::render()
{
    system("clear");
    std::cout << *_printer << "\n\n";
}