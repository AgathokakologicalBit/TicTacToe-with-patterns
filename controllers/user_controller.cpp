// Copyright 2017 Ermishin Michael

#include <iostream>
#include "../game/game.h"
#include "user_controller.h"


void UserController::init() {}

const Move UserController::do_turn(const Board& board)
{
    uint16_t x, y;
    std::cout << "Place " << Game::get().current_symbol() << " on (x y): ";
    std::cin >> x >> y;

    return Move {x, y};
}
