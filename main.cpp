// Copyright 2017 Ermishin Michael

#include <iostream>

#include "board.h"
#include "board_printer_factory.h"

int main() {
    uint16_t size, target_score;
    std::cout << "Tic tac tie YxY. Score Z to win!" << std::endl;

    std::cout << "Please specify Y: ";
    std::cin >> size;

    std::cout << "Please specify Z: ";
    std::cin >> target_score;

    Board board(size, target_score);
    auto printer = BoardPrinterFactory(board)
        .set_symbol(eCell::X, '0')
        .set_symbol(eCell::O, '1')
        .set_symbol(eCell::Empty, '.')
        .build();

    char symbol = '?';
    eWinner winner;
    while ((winner = board.get_winner()) == eWinner::NA)
    {
        system("clear");
        std::cout << printer << "\n\n";

        uint16_t x, y;
        symbol = printer.get_symbol(board.get_current_player());
        std::cout << "Place " << symbol << " on (x y): ";
        std::cin >> x >> y;
        board.do_turn(x, y);
    }

    system("clear");
    std::cout << printer << "\n\n";

    if (winner == eWinner::T)
        std::cout << "It's a tie!\n\n";
    else
        std::cout << "Congratulations!\n" << "  Player '" << symbol << "' has won.\n\n";

    return 0;
}
