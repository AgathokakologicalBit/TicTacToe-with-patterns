#include "board_printer.h"

std::ostream& operator <<(std::ostream& out, const BoardPrinter& p)
{
    for (uint16_t y = 0; y < p.board->size; ++y)
    {
        if (y != 0) out << '\n';

        for (uint16_t x = 0; x < p.board->size; ++x)
        {
            if (x != 0) out << ' ';
            out << p.symbol_table.at(p.board->get(x, y));
        }
    }

    return out;
}
