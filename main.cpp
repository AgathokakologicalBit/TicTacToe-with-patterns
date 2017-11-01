// Copyright 2017 Ermishin Michael

#include <iostream>

#include "game/game.h"


/**
 * [Entry point] Program's main method
 * @return 0
 */
int main() {
    Game::get().init();

    Game::get().render();
    while (Game::get().update())
        Game::get().render();


    if (Game::get().winner() == eWinner::T)
    {
        std::cout << "It's a tie!\n\n";
    }
    else
    {
        std::cout << "Congratulations!\n"
                  << "  Player '" << Game::get().winner_symbol()
                  << "' has won.\n\n";
    }

    return 0;
}
