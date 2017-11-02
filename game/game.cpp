// Copyright 2017 Ermishin Michael

#include <iostream>

#include "game.h"
#include "board/board_printer_factory.h"
#include "../controllers/user_controller.h"

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

    _player1 = std::make_unique<UserController>();
    _player2 = std::make_unique<UserController>();
}

bool Game::update()
{
    if (_winner != eWinner::NA) return false;

    auto player = _board->get_current_player();
    auto controller = player == eCell::X ? _player1.get() : _player2.get();
    auto move = controller->do_turn(*_board);
    _board->do_turn(move.x, move.y);

    _winner = _board->calculate_winner();
    return true;
}

void Game::render()
{
    system("clear");
    std::cout << *_printer << "\n\n";
}
